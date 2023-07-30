#ifdef RENDERDLL_SHADER_COMPILER
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/RenderDll/Common/CommonRender.h>
#include <Prey/RenderDll/XRenderD3D9/D3DHWShader.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Prey/RenderDll/Common/ResFile.h>
#include <Prey/RenderDll/Common/Shaders/CShaderBin.h>
#include <mem.h>
#include "ShaderCompilingPatch.h"

namespace RenderDll::Shaders
{

//-----------------------------------------------------------------------------------

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

bool g_bEnableShaderMods = false;
auto g_CShaderMan_mfInit_Hook = CShaderMan::FmfInit.MakeHook();
auto g_CShaderMan_mfInitLookups_Hook = CShaderMan::FmfInitLookups.MakeHook();

//-----------------------------------------------------------------------------------

void CShaderMan_mfInit_Hook(CShaderMan* _this)
{
	if (!_this->m_bInitialized)
	{
		*CRenderer::CV_r_shadersAllowCompilation = 1;
		*CRenderer::CV_r_shadersasyncactivation = 1;
		*CRenderer::CV_r_shadersasynccompiling = 0;

		if (const ICmdLineArg* shadersediting = gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "shadersediting"))
			*CRenderer::CV_r_shadersediting = shadersediting->GetIValue();
		else
			*CRenderer::CV_r_shadersediting = 0;

		if (const ICmdLineArg* shadersdebug = gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "shadersdebug"))
			*CRenderer::CV_r_shadersdebug = shadersdebug->GetIValue();
		else
			*CRenderer::CV_r_shadersdebug = 0;
	}

	g_CShaderMan_mfInit_Hook.InvokeOrig(_this);
}

void CShaderMan_mfInitLookups_Hook(CShaderMan* _this)
{
	_this->m_ResLookupDataMan[CACHE_READONLY].Clear();
	string dirdatafilename(_this->m_ShadersCache);
	dirdatafilename += "lookupdata.bin";
	_this->m_ResLookupDataMan[CACHE_READONLY].LoadData(dirdatafilename.c_str(), true);

	// CACHE_USER is missing in Prey's function
	_this->m_ResLookupDataMan[CACHE_USER].Clear();
	dirdatafilename = _this->m_szUserPath + _this->m_ShadersCache;
	dirdatafilename += "lookupdata.bin";
	_this->m_ResLookupDataMan[CACHE_USER].LoadData(dirdatafilename.c_str(), false);
}

//-----------------------------------------------------------------------------------

void AddShadersMod(const std::string& name)
{
	g_bEnableShaderMods = true;
}

bool GetShaderModsRegistered()
{
	if (g_bEnableShaderMods)
		return true;

	if (gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "shadercompiler"))
	{
		g_bEnableShaderMods = true;
		return true;
	}

	return false;
}

//-----------------------------------------------------------------------------------

void InitHooks()
{
	CryWarning("Enabling expreimental shader compiler!");

	g_CShaderMan_mfInit_Hook.SetHookFunc(&CShaderMan_mfInit_Hook);
	g_CShaderMan_mfInitLookups_Hook.SetHookFunc(&CShaderMan_mfInitLookups_Hook);

#define INIT_OVERRIDE(className, funcName) PreyFuncOverride<&className::F##funcName, &className::chair_##funcName>::Init()
	INIT_OVERRIDE(CHWShader_D3D, mfActivate);
	INIT_OVERRIDE(CShaderManBin, GetBinShader);
#undef INIT_OVERRIDE
}

void ShutdownRenderer()
{
#ifdef SHADER_ASYNC_COMPILATION
#endif
}

}
#else

namespace RenderDll::Shaders
{
void AddShadersMod(const std::string& name) {}
bool GetShaderModsRegistered() { return false; }
void InitHooks() {}
void ShutdownRenderer() {}
}

#endif
