#include <Prey/CrySystem/System.h>
#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Preditor/IGameViewport.h>
#include "GameViewportPatch.h"

class CFlashUIElement;

namespace
{

auto CFlashUIElement_Render = PreyFunction<void(CFlashUIElement* const _this)>(0x2FF300);

IGameViewport* g_pVP = nullptr;
auto g_CSystem_Render_Hook = CSystem::FRender.MakeHook();
auto g_CFlashUIElement_Render_Hook = CFlashUIElement_Render.MakeHook();

void CSystem_Render_Hook(CSystem* const _this)
{
	if (!g_pVP || !g_pVP->NeedCustomRender())
	{
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
		g_pVP->CustomRender();
	}

	gEnv->p3DEngine->WorldStreamUpdate();
	gEnv->pRenderer->SwitchToNativeResolutionBackbuffer();
}

void CFlashUIElement_Render_Hook(CFlashUIElement* const _this)
{
	// Only render if viewport doesn't
	if (!g_pVP || !g_pVP->NeedCustomRender())
	{
		g_CFlashUIElement_Render_Hook.InvokeOrig(_this);
	}
}

} // namespace

void GameViewportPatch::InitHooks()
{
	g_CSystem_Render_Hook.SetHookFunc(&CSystem_Render_Hook);
	g_CFlashUIElement_Render_Hook.SetHookFunc(&CFlashUIElement_Render_Hook);
}

void GameViewportPatch::SetGameViewport(IGameViewport* pVP)
{
	g_pVP = pVP;
}
