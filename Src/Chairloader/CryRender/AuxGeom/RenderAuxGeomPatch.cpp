#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <Chairloader/IRenderAuxGeomImplD3D.h>
#include <detours/detours.h>
#include "D3DRenderAuxGeom.h"
#include "Shaders/ShaderCompilingPatch.h"
#include "RenderAuxGeomPatch.h"

static_assert(offsetof(CD3D9Renderer, m_bStopRendererAtFrameEnd) == 96);
static_assert(offsetof(CD3D9Renderer, m_pRT) == 3472);

namespace RenderDll::AuxGeom
{
bool g_bAuxGeomEnabled = false;

int CV_r_enableauxgeom;

IChairRender::AuxGeomFactory s_fnAuxGeomFactory;
IRenderAuxGeomImplD3D* s_pRenderAuxGeomD3D = nullptr;

auto CD3D9Renderer_FX_PipelineShutdown_Hook = CD3D9Renderer::FFX_PipelineShutdown.MakeHook();
auto CD3D9Renderer_OnD3D11PostCreateDevice_Hook = CD3D9Renderer::FOnD3D11PostCreateDevice.MakeHook();
auto CD3D9Renderer_EF_RemoveParticlesFromScene_Hook = CD3D9Renderer::FEF_RemoveParticlesFromScene.MakeHook();
auto CD3D9Renderer_Set2DMode_Hook = CD3D9Renderer::FSet2DMode.MakeHook();
auto CD3D9Renderer_GetIRenderAuxGeom_Hook = CD3D9Renderer::FGetIRenderAuxGeom.MakeHook();
auto CD3D9Renderer_PostLevelUnload_Hook = CD3D9Renderer::FPostLevelUnload.MakeHook();

IRenderAuxGeomImplD3D* DefaultAuxGeomFactory()
{
	return CRenderAuxGeomD3D::Create(*gcpRendD3D);
}

void CD3D9Renderer_FX_PipelineShutdown(CD3D9Renderer* _this, bool bFastShutdown)
{
	if (s_pRenderAuxGeomD3D)
		s_pRenderAuxGeomD3D->ReleaseShader();

	CD3D9Renderer_FX_PipelineShutdown_Hook.InvokeOrig(_this, bFastShutdown);
}

HRESULT CD3D9Renderer_OnD3D11PostCreateDevice(D3DDevice* pd3dDevice)
{
	HRESULT hr;

	if (FAILED(hr = CD3D9Renderer_OnD3D11PostCreateDevice_Hook.InvokeOrig(pd3dDevice)))
		return hr;

	if (s_pRenderAuxGeomD3D && FAILED(hr = s_pRenderAuxGeomD3D->RestoreDeviceObjects()))
		return hr;

	return S_OK;
}

void CD3D9Renderer_EF_RemoveParticlesFromScene(CRenderer* _this)
{
	// Called only from RT_EndFrame

	if (s_pRenderAuxGeomD3D)
	{
		assert(1 == static_cast<CD3D9Renderer*>(_this)->m_SceneRecurseCount);
		// in case of MT rendering flush render thread CB is flashed (main thread CB gets flushed in SRenderThread::FlushFrame()),
		// otherwise unified "main-render" tread CB is flashed

		if (IRenderAuxGeom* pAuxGeomCB = s_pRenderAuxGeomD3D->GetRenderAuxGeom())
		{
			pAuxGeomCB->Commit();
		}

		s_pRenderAuxGeomD3D->Process();
	}

	CD3D9Renderer_EF_RemoveParticlesFromScene_Hook.InvokeOrig(_this);
}

void CD3D9Renderer_Set2DMode(CD3D9Renderer* _this, bool enable, int ortox, int ortoy, float znear, float zfar)
{
	CD3D9Renderer_Set2DMode_Hook.InvokeOrig(_this, enable, ortox, ortoy, znear, zfar);

	if (s_pRenderAuxGeomD3D)
	{
		if (enable)
		{
			int nThreadID = _this->m_pRT->GetThreadList();
			Matrix44A* m = _this->m_RP.m_TI[nThreadID].m_matProj->GetTop();
			s_pRenderAuxGeomD3D->SetOrthoMode(true, m);
		}
		else
		{
			s_pRenderAuxGeomD3D->SetOrthoMode(false);
		}
	}
}

IRenderAuxGeom* CD3D9Renderer_GetIRenderAuxGeom(CD3D9Renderer* _this, void* jobID)
{
	if (s_pRenderAuxGeomD3D)
		return s_pRenderAuxGeomD3D->GetRenderAuxGeom(jobID);

	return &_this->m_renderAuxGeomNull;
}

void CD3D9Renderer_PostLevelUnload(CD3D9Renderer* _this)
{
	CD3D9Renderer_PostLevelUnload_Hook.InvokeOrig(_this);

	if (s_pRenderAuxGeomD3D)
		s_pRenderAuxGeomD3D->FreeMemory();
}

void InitAuxGeom()
{
	g_bAuxGeomEnabled = true;
	CD3D9Renderer_FX_PipelineShutdown_Hook.SetHookFunc(&CD3D9Renderer_FX_PipelineShutdown);
	CD3D9Renderer_OnD3D11PostCreateDevice_Hook.SetHookFunc(&CD3D9Renderer_OnD3D11PostCreateDevice);
	CD3D9Renderer_EF_RemoveParticlesFromScene_Hook.SetHookFunc(&CD3D9Renderer_EF_RemoveParticlesFromScene);
	CD3D9Renderer_Set2DMode_Hook.SetHookFunc(&CD3D9Renderer_Set2DMode);
	CD3D9Renderer_GetIRenderAuxGeom_Hook.SetHookFunc(&CD3D9Renderer_GetIRenderAuxGeom);
	CD3D9Renderer_PostLevelUnload_Hook.SetHookFunc(&CD3D9Renderer_PostLevelUnload);

	REGISTER_CVAR2("r_enableAuxGeom", &CV_r_enableauxgeom, 1, VF_REQUIRE_APP_RESTART, "Enables aux geometry rendering.");

	CRenderAuxGeomD3D::InitCustomCommand();
}

void SetAuxGeomFactory(const IChairRender::AuxGeomFactory& factory)
{
	if (s_pRenderAuxGeomD3D)
		CryFatalError("IChairRender::SetAuxGeomFactory called after aux geom renderer has been initialized");

	s_fnAuxGeomFactory = factory;
}

void InitRenderer()
{
	if (CV_r_enableauxgeom)
	{
		if (!s_fnAuxGeomFactory)
			s_fnAuxGeomFactory = &DefaultAuxGeomFactory;

		s_pRenderAuxGeomD3D = s_fnAuxGeomFactory();

		constexpr int requiredVersion = IRenderAuxGeomImplD3D::INTERFACE_VERSION;
		int actualVersion = s_pRenderAuxGeomD3D->GetIRenderAuxGeomImplD3DVersion();
		if (requiredVersion != actualVersion)
			CryFatalError("IRenderAuxGeomImplD3D version mismatch.\nRequired: {}\nActual: {}", requiredVersion, actualVersion);

		gCL->pAuxGeomEx = s_pRenderAuxGeomD3D->GetRenderAuxGeomEx();
	}
}

void RT_Shutdown()
{
	SAFE_DELETE(s_pRenderAuxGeomD3D);
}

void ShutdownSystem()
{
	CRenderAuxGeomD3D::ShutdownCustomCommand();
}

} // namespace RenderDll::AuxGeom
