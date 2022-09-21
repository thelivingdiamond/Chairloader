#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/XRenderD3D9/D3DHWShader.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Prey/RenderDll/Common/ResFile.h>
#include <mem.h>

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

auto g_CHWShader_D3D_mfActivate_Hook = CHWShader_D3D::FmfActivate.MakeHook();
auto g_CShaderMan_mfInit_Hook = CShaderMan::FmfInit.MakeHook();
auto g_CShaderMan_mfReleaseSystemShaders_Hook = CShaderMan::FmfReleaseSystemShaders.MakeHook();

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

		//if (*CRenderer::CV_r_shadersAllowCompilation)
		{
			*CRenderer::CV_r_shadersasyncactivation = 0;
			*CRenderer::CV_r_shadersasynccompiling = 0;
			*CRenderer::CV_r_shadersdebug = 4;
		}
	}

	g_CShaderMan_mfInit_Hook.InvokeOrig(_this);
}

void CShaderMan_mfReleaseSystemShaders_Hook(CShaderMan* _this)
{
	if (!_this->m_bInitialized)
	{
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

//-----------------------------------------------------------------------------------

void InitHooks()
{
	g_CHWShader_D3D_mfActivate_Hook.SetHookFunc(&CHWShader_D3D_mfActivate_Hook);
	g_CShaderMan_mfInit_Hook.SetHookFunc(&CShaderMan_mfInit_Hook);
	g_CShaderMan_mfReleaseSystemShaders_Hook.SetHookFunc(&CShaderMan_mfReleaseSystemShaders_Hook);

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

#undef INIT_OVERRIDE
}

}
