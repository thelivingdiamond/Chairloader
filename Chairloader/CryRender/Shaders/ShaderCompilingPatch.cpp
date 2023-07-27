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

bool g_bEnableShaderMods = false;

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
