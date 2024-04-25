#include <Prey/CrySystem/System.h>
#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Preditor/Viewport/IViewportWindow.h>
#include <Preditor/Viewport/IViewport.h>
#include "GameViewportPatch.h"

class CFlashUIElement;

namespace
{

auto CFlashUIElement_Render = PreyFunction<void(CFlashUIElement* const _this)>(0x2FF300);

auto g_CSystem_Render_Hook = CSystem::FRender.MakeHook();
auto g_CFlashUIElement_Render_Hook = CFlashUIElement_Render.MakeHook();

IViewport* GetCurrentViewport()
{
	IViewportWindow* pVPWin = gPreditor->pViewportWindow;
	return pVPWin ? pVPWin->GetCurrentViewport() : nullptr;
}

void CSystem_Render_Hook(CSystem* const _this)
{
	IViewport* pVP = GetCurrentViewport();

	if (!pVP || !pVP->NeedCustomRender())
	{
		// PrepareOcclusion is usually called in CCryAction::PostUpdate
		// but viewport changes the camera after that.
		gEnv->p3DEngine->PrepareOcclusion(_this->GetViewCamera());
		g_CSystem_Render_Hook.InvokeOrig(_this);
		return;
	}

	if (_this->m_bIgnoreUpdates)
		return;

	if (!_this->m_pProcess)
		return;

	gEnv->p3DEngine->PreWorldStreamUpdate(_this->m_ViewCamera);

	if (_this->m_pProcess->GetFlags() & PROC_3DENGINE)
	{
		pVP->CustomRender();
	}

	gEnv->p3DEngine->WorldStreamUpdate();
	gEnv->pRenderer->SwitchToNativeResolutionBackbuffer();
}

void CFlashUIElement_Render_Hook(CFlashUIElement* const _this)
{
	IViewport* pVP = GetCurrentViewport();

	// Only render if viewport doesn't
	if (!pVP || !pVP->NeedCustomRender())
	{
		g_CFlashUIElement_Render_Hook.InvokeOrig(_this);
	}
}

} // namespace

void Engine::GameViewportPatch::InitHooks()
{
	g_CSystem_Render_Hook.SetHookFunc(&CSystem_Render_Hook);
	g_CFlashUIElement_Render_Hook.SetHookFunc(&CFlashUIElement_Render_Hook);
}
