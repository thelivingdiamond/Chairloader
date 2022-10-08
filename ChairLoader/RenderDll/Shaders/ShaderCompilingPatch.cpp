#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/XRenderD3D9/D3DHWShader.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Prey/RenderDll/Common/ResFile.h>
#include <Prey/RenderDll/Common/Shaders/CShaderBin.h>
#include <mem.h>
#include "ShaderPaths.h"
#include "ShaderCompilingPatch.h"

CD3D9Renderer* gcpRendD3D = nullptr;

//-----------------------------------------------------------------------------------

void CShaderMan::mfInitLookups()
{
	m_ResLookupDataMan[CACHE_READONLY].Clear();
	string dirdatafilename(m_ShadersCache);
	dirdatafilename += "lookupdata.bin";
	m_ResLookupDataMan[CACHE_READONLY].LoadData(dirdatafilename.c_str(), true);

	m_ResLookupDataMan[CACHE_USER].Clear();
	dirdatafilename = m_szUserPath + m_ShadersCache;
	dirdatafilename += "lookupdata.bin";
	m_ResLookupDataMan[CACHE_USER].LoadData(dirdatafilename.c_str(), false);
}

//-----------------------------------------------------------------------------------

namespace RenderDll::Shaders
{

// This hepler class allows you to hook a PreyFunction to call a method of a class.
// Doesn't work with virtual functions.
// @tparam	pPreyFunc			Pointer to PreyFunction<>.
// @tparam	pOverrideMethod		Pointer to a method to call.
template<auto pPreyFunc, auto pOverrideMethod>
class PreyFuncOverride
{
public:
	//! PreyFunction<>
	using PreyFuncType = std::remove_pointer_t<decltype(pPreyFunc)>;

	//! Initializes the hook.
	static void Init()
	{
		m_Hook.SetHookFunc(&Wrapper);
	}

private:
	static inline auto m_Hook = pPreyFunc->MakeHook();

	//! Wrapper function that calls the method. It's required because member function pointers
	//! can't be cast to an address.
	template <typename... Args>
	static typename PreyFuncType::FuncReturnType Wrapper(Args... args)
	{
		return std::invoke(pOverrideMethod, args...);
	}
};

//-----------------------------------------------------------------------------------

#ifdef SHADER_ASYNC_COMPILATION
std::vector<CAsyncShaderTask*> g_AsyncShaderTasks;
#endif

//-----------------------------------------------------------------------------------

auto g_CHWShader_D3D_mfActivate_Hook = CHWShader_D3D::FmfActivate.MakeHook();
auto g_CShaderMan_mfInit_Hook = CShaderMan::FmfInit.MakeHook();
auto g_CShaderMan_mfReleaseSystemShaders_Hook = CShaderMan::FmfReleaseSystemShaders.MakeHook();
auto g_CShaderMan_mfReloadAllShaders_Hook = CShaderMan::FmfReloadAllShaders.MakeHook();
auto g_CD3D9Renderer_SF_CreateResources_Hook = CD3D9Renderer::FSF_CreateResources.MakeHook();

bool CHWShader_D3D_mfActivate_Hook(CHWShader_D3D* _this, CShader* pSH, uint32 nFlags, FXShaderToken* Table, TArray<uint32>* pSHData, bool bCompressedOnly)
{
	// Overload, can't use PreyFuncOverride here
	return _this->mfActivate(pSH, nFlags, Table, pSHData);
}

void CShaderMan_mfInit_Hook(CShaderMan* _this)
{
	if (!_this->m_bInitialized)
	{
		*CRenderer::CV_r_shadersediting = 1;
		*CRenderer::CV_r_shadersAllowCompilation = 1;
		*CRenderer::CV_r_shadersasyncactivation = 1;
		*CRenderer::CV_r_shadersasynccompiling = 1;

		const ICmdLineArg* shadersdebug = gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "shadersdebug");
		if (shadersdebug)
			*CRenderer::CV_r_shadersdebug = shadersdebug->GetIValue();
		else
			*CRenderer::CV_r_shadersdebug = 0;
	}

	g_CShaderMan_mfInit_Hook.InvokeOrig(_this);
}

void CShaderMan_mfReleaseSystemShaders_Hook(CShaderMan* _this)
{
	static bool onlyRunOnceInmfInit = false;

	if (!onlyRunOnceInmfInit)
	{
		onlyRunOnceInmfInit = true;

		if (*CRenderer::CV_r_shadersAllowCompilation)
		{
			_this->mfInitShadersCache(false, NULL, NULL, 0);
		}
		else
		{
			// make sure we can write to the shader cache
			if (!_this->CheckAllFilesAreWritable((string(_this->m_ShadersCache) + "cgpshaders").c_str())
				|| !_this->CheckAllFilesAreWritable((string(_this->m_ShadersCache) + "cgvshaders").c_str()))
			{
				// message box causes problems in fullscreen
				//			MessageBox(0,"WARNING: Shader cache cannot be updated\n\n"
				//				"files are write protected / media is read only / windows user setting don't allow file changes","CryEngine",MB_ICONEXCLAMATION|MB_OK);
				gEnv->pLog->LogError("ERROR: Shader cache cannot be updated (files are write protected / media is read only / windows user setting don't allow file changes)");
			}
		}
	}

	g_CShaderMan_mfReleaseSystemShaders_Hook.InvokeOrig(_this);
}

bool CShaderMan_mfReloadAllShaders_Hook(CShaderMan* const _this, int nFlags, unsigned nFlagsHW)
{
	// Refresh file list on shader reload
	ShaderPaths::Get().RefreshFileList();
	return g_CShaderMan_mfReloadAllShaders_Hook.InvokeOrig(_this, nFlags, nFlagsHW);
}

#ifdef SHADER_ASYNC_COMPILATION
void CD3D9Renderer_SF_CreateResources_Hook(CD3D9Renderer* const _this)
{
	// Init async compile threads
	constexpr uint32 MAX_THREADS = 4; // CV_r_shadersasyncmaxthreads; //clamp_tpl(CV_r_shadersasyncmaxthreads, 1, 4);
	uint32 nThreads = MAX_THREADS;

	uint32 nOldThreads = g_AsyncShaderTasks.size();
	for (uint32 a = nThreads; a < nOldThreads; a++)
		delete g_AsyncShaderTasks[a];

	g_AsyncShaderTasks.resize(nThreads);

	for (uint32 a = nOldThreads; a < nThreads; a++)
		g_AsyncShaderTasks[a] = new CAsyncShaderTask();

	for (int32 i = 0; i < g_AsyncShaderTasks.size(); i++)
	{
		g_AsyncShaderTasks[i]->SetThread(i);
	}

	g_CD3D9Renderer_SF_CreateResources_Hook.InvokeOrig(_this);
}
#endif

//-----------------------------------------------------------------------------------

bool GetShaderModsRegistered()
{
	return ShaderPaths::Get().HasAnyFiles();
}

void InitHooks()
{
	g_CHWShader_D3D_mfActivate_Hook.SetHookFunc(&CHWShader_D3D_mfActivate_Hook);
	g_CShaderMan_mfInit_Hook.SetHookFunc(&CShaderMan_mfInit_Hook);
	g_CShaderMan_mfReleaseSystemShaders_Hook.SetHookFunc(&CShaderMan_mfReleaseSystemShaders_Hook);
	g_CShaderMan_mfReloadAllShaders_Hook.SetHookFunc(&CShaderMan_mfReloadAllShaders_Hook);

#ifdef SHADER_ASYNC_COMPILATION
	g_CD3D9Renderer_SF_CreateResources_Hook.SetHookFunc(&CD3D9Renderer_SF_CreateResources_Hook);
#endif

#define INIT_OVERRIDE(className, funcName) PreyFuncOverride<&className::F##funcName, &className::funcName>::Init()

	INIT_OVERRIDE(CHWShader_D3D, mfGetDstFileName);
	//INIT_OVERRIDE(CHWShader_D3D, mfAddFXParameter); // Overload!
	INIT_OVERRIDE(CHWShader_D3D, mfCreateBinds);
	INIT_OVERRIDE(CHWShader_D3D, mfUpdateFXVertexFormat);
	//INIT_OVERRIDE(CHWShader_D3D, mfVertexFormat); // Overload!
	//INIT_OVERRIDE(CHWShader_D3D, mfSetDefaultRT); // Overload!
	INIT_OVERRIDE(CHWShader_D3D, mfStoreCacheTokenMap);
	INIT_OVERRIDE(CHWShader_D3D, mfGetTokenMap);
	INIT_OVERRIDE(CHWShader_D3D, mfGetCacheTokenMap);
	INIT_OVERRIDE(CHWShader_D3D, mfGetCacheItem);
	INIT_OVERRIDE(CHWShader_D3D, mfActivateCacheItem);
	INIT_OVERRIDE(CHWShader_D3D, mfOutputCompilerError);
	INIT_OVERRIDE(CHWShader_D3D, mfAsyncCompileReady);
	INIT_OVERRIDE(CHWShader_D3D, mfPrepareShaderDebugInfo);
	INIT_OVERRIDE(CHWShader_D3D, mfPrintCompileInfo);
	INIT_OVERRIDE(CHWShader_D3D, _OpenCacheFile);
	INIT_OVERRIDE(CHWShader_D3D, mfOpenCacheFile);
	INIT_OVERRIDE(CHWShader_D3D, mfInitCache);

	INIT_OVERRIDE(CShaderMan, mfForName);
	INIT_OVERRIDE(CShaderMan, mfCreateShaderGenInfo);
	INIT_OVERRIDE(CShaderMan, RT_ParseShader);
	INIT_OVERRIDE(CShaderMan, mfInitLookups);

	INIT_OVERRIDE(CResFile, mfGetEntry);
	INIT_OVERRIDE(CShaderManBin, GetBinShader);

#undef INIT_OVERRIDE

	ShaderPaths::Get().Init();
}

void ShutdownRenderer()
{
#ifdef SHADER_ASYNC_COMPILATION
	for (int32 a = 0; a < g_AsyncShaderTasks.size(); a++)
		delete g_AsyncShaderTasks[a];
#endif
}

}
