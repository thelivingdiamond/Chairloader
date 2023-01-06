#include <Prey/CryInput/IHardwareMouse.h>
#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryRenderer/IRenderer.h>
#include "SceneViewport.h"

SceneViewport::SceneViewport()
{
	UpdateCamera();
}

void SceneViewport::Update(bool isVisible)
{
}

void SceneViewport::OnActivate()
{
	assert(!m_bActive);
	m_bActive = true;
	gEnv->pHardwareMouse->IncrementCounter();
}

void SceneViewport::OnDeactivate()
{
	assert(m_bActive);
	m_bActive = false;
	SetMouseGrabbed(false);
	gEnv->pHardwareMouse->DecrementCounter();
}

void SceneViewport::ShowTopControls()
{
	ImGui::SameLine();
	ImGui::InputInt("lol", &lol);
}

void SceneViewport::Render()
{
	UpdateCamera();
	SRenderingPassInfo renderPassInfo = SRenderingPassInfo::CreateGeneralPassRenderingInfo(m_Cam);
	int renderFlags = SHDF_ALLOW_WATER | SHDF_ALLOWPOSTPROCESS | SHDF_ALLOWHDR | SHDF_ZPASS;
	gEnv->p3DEngine->ResetPostEffects(); // Reset menu blur effect
	gEnv->p3DEngine->RenderWorld(renderFlags, renderPassInfo, __FUNCTION__);
}

void SceneViewport::SetMouseGrabbed(bool state)
{
	if (m_bGrabMouse == state)
		return;

	if (state)
	{
		gEnv->pHardwareMouse->DecrementCounter();
	}
	else
	{
		gEnv->pHardwareMouse->IncrementCounter();
	}

	m_bGrabMouse = state;
}

void SceneViewport::UpdateCamera()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	m_Cam.SetMatrixNoUpdate(viewCam.GetMatrix());
	m_Cam.SetFrustum(viewCam.GetViewSurfaceX(), viewCam.GetViewSurfaceZ(), DEG2RAD(90.0f));
}
