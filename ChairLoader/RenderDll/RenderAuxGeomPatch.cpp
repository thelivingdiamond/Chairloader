#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/RenderDll/XRenderD3D9/DriverD3D.h>
#include <detours/detours.h>
#include "D3DRenderAuxGeom.h"
#include "../ChairLoader.h"

static_assert(offsetof(CD3D9Renderer, m_bStopRendererAtFrameEnd) == 96);
static_assert(offsetof(CD3D9Renderer, m_pRT) == 3472);

void SRenderThread_InstallCommandHandler();
void SRenderThread_RemoveCommandHandler();
void SRenderThread_PostHook();

namespace
{
int CV_r_enableauxgeom;

CRenderAuxGeomD3D* s_pRenderAuxGeomD3D = nullptr;

auto CD3D9Renderer_FX_PipelineShutdown_Hook = CD3D9Renderer::FFX_PipelineShutdown.MakeHook();
auto CD3D9Renderer_RT_ShutDown_Hook = CD3D9Renderer::FRT_ShutDown.MakeHook();
auto CD3D9Renderer_OnD3D11PostCreateDevice_Hook = CD3D9Renderer::FOnD3D11PostCreateDevice.MakeHook();
auto CD3D9Renderer_InitRenderer_Hook = CD3D9Renderer::FInitRenderer.MakeHook();
auto CD3D9Renderer_EF_RemoveParticlesFromScene_Hook = CD3D9Renderer::FEF_RemoveParticlesFromScene.MakeHook();
auto CD3D9Renderer_Set2DMode_Hook = CD3D9Renderer::FSet2DMode.MakeHook();
auto CD3D9Renderer_GetIRenderAuxGeom_Hook = CD3D9Renderer::FGetIRenderAuxGeom.MakeHook();
auto CD3D9Renderer_PostLevelUnload_Hook = CD3D9Renderer::FPostLevelUnload.MakeHook();

void CD3D9Renderer_FX_PipelineShutdown(CD3D9Renderer* _this, bool bFastShutdown)
{
	if (s_pRenderAuxGeomD3D)
		s_pRenderAuxGeomD3D->ReleaseShader();

	CD3D9Renderer_FX_PipelineShutdown_Hook.InvokeOrig(_this, bFastShutdown);
}

void CD3D9Renderer_RT_ShutDown(CD3D9Renderer* _this, uint32 nFlags)
{
	SAFE_DELETE(s_pRenderAuxGeomD3D);
	CD3D9Renderer_RT_ShutDown_Hook.InvokeOrig(_this, nFlags);
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

void CD3D9Renderer_InitRenderer(CD3D9Renderer* _this)
{
	if (!gRenDev)
		gRenDev = _this;

	CD3D9Renderer_InitRenderer_Hook.InvokeOrig(_this);

	if (CV_r_enableauxgeom)
	{
		s_pRenderAuxGeomD3D = CRenderAuxGeomD3D::Create(*_this);
		gCL->GetChairloaderEnvironment()->pAuxGeomEx = s_pRenderAuxGeomD3D->GetRenderAuxGeom();
	}
}

void CD3D9Renderer_EF_RemoveParticlesFromScene(CRenderer* _this)
{
	// Called only from RT_EndFrame

	if (s_pRenderAuxGeomD3D)
	{
		assert(1 == static_cast<CD3D9Renderer*>(_this)->m_SceneRecurseCount);
		// in case of MT rendering flush render thread CB is flashed (main thread CB gets flushed in SRenderThread::FlushFrame()),
		// otherwise unified "main-render" tread CB is flashed

		if (CAuxGeomCB* pAuxGeomCB = s_pRenderAuxGeomD3D->GetRenderAuxGeom())
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

}

void InitRenderAuxGeomPatchHooks()
{
	CD3D9Renderer_FX_PipelineShutdown_Hook.SetHookFunc(&CD3D9Renderer_FX_PipelineShutdown);
	CD3D9Renderer_RT_ShutDown_Hook.SetHookFunc(&CD3D9Renderer_RT_ShutDown);
	CD3D9Renderer_OnD3D11PostCreateDevice_Hook.SetHookFunc(&CD3D9Renderer_OnD3D11PostCreateDevice);
	CD3D9Renderer_InitRenderer_Hook.SetHookFunc(&CD3D9Renderer_InitRenderer);
	CD3D9Renderer_EF_RemoveParticlesFromScene_Hook.SetHookFunc(&CD3D9Renderer_EF_RemoveParticlesFromScene);
	CD3D9Renderer_Set2DMode_Hook.SetHookFunc(&CD3D9Renderer_Set2DMode);
	CD3D9Renderer_GetIRenderAuxGeom_Hook.SetHookFunc(&CD3D9Renderer_GetIRenderAuxGeom);
	CD3D9Renderer_PostLevelUnload_Hook.SetHookFunc(&CD3D9Renderer_PostLevelUnload);
	SRenderThread_InstallCommandHandler();
}

void InitRenderAuxGeomPatch()
{
	if (gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "auxgeom"))
	{
		SRenderThread_PostHook();
		REGISTER_CVAR2("r_enableAuxGeom", &CV_r_enableauxgeom, 1, VF_REQUIRE_APP_RESTART, "Enables aux geometry rendering.");
	}
	else
	{
		// Remove all hooks
		DetourTransactionBegin();
		CD3D9Renderer_FX_PipelineShutdown_Hook.RemoveHook();
		CD3D9Renderer_RT_ShutDown_Hook.RemoveHook();
		CD3D9Renderer_OnD3D11PostCreateDevice_Hook.RemoveHook();
		CD3D9Renderer_InitRenderer_Hook.RemoveHook();
		CD3D9Renderer_EF_RemoveParticlesFromScene_Hook.RemoveHook();
		CD3D9Renderer_Set2DMode_Hook.RemoveHook();
		CD3D9Renderer_GetIRenderAuxGeom_Hook.RemoveHook();
		CD3D9Renderer_PostLevelUnload_Hook.RemoveHook();
		SRenderThread_RemoveCommandHandler();
		DetourTransactionCommit();
	}
}