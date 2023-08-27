#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Prey/CryRenderer/IRenderAuxGeom.h>
#include <Prey/CryGame/Game.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/GameDll/ark/player/ArkPlayer.h>
#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/EditTools/IEditToolManager.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include <Preditor/SceneEditor/IViewportHandler.h>
#include <Preditor/Input/IPreditorInput.h>
#include <Preditor/Input/IMouseInputSystem.h>
#include "SceneViewport.h"

float CV_ed_ViewMinSpeed;
float CV_ed_ViewMaxSpeed;
float CV_ed_ViewAccel;
float CV_ed_ViewDecel;
float CV_ed_ViewSens;
float CV_ed_ViewBoostScale;

Viewport::SceneViewport::SceneViewport()
{
	gEnv->pSystem->GetISystemEventDispatcher()->RegisterListener(this);

	REGISTER_CVAR2("ed_ViewMinSpeed", &CV_ed_ViewMinSpeed, 3, VF_NULL, "Editor: View minimum speed");
	REGISTER_CVAR2("ed_ViewMaxSpeed", &CV_ed_ViewMaxSpeed, 20, VF_NULL, "Editor: View maximum speed");
	REGISTER_CVAR2("ed_ViewAccel", &CV_ed_ViewAccel, 10, VF_NULL, "Editor: View acceleration");
	REGISTER_CVAR2("ed_ViewDecel", &CV_ed_ViewDecel, 3, VF_NULL, "Editor: View deceleration");
	REGISTER_CVAR2("ed_ViewSens", &CV_ed_ViewSens, 13, VF_NULL, "Editor: Mouse sensitivity");
	REGISTER_CVAR2("ed_ViewBoostScale", &CV_ed_ViewBoostScale, 5, VF_NULL, "Editor: Speed boost on SHIFT");

	IKeyboardInputSystem* pKbd = gPreditor->pInput->GetKeyboard();
	m_pCameraActionSet = pKbd->FindActionSet("viewport_camera");
	m_pFwd = m_pCameraActionSet->FindAction("forward");
	m_pBkwd = m_pCameraActionSet->FindAction("backward");
	m_pLeft = m_pCameraActionSet->FindAction("left");
	m_pRight = m_pCameraActionSet->FindAction("right");
	m_pUp = m_pCameraActionSet->FindAction("up");
	m_pDown = m_pCameraActionSet->FindAction("down");
	m_pSpeedUp = m_pCameraActionSet->FindAction("speed_up");
}

Viewport::SceneViewport::~SceneViewport()
{
	gEnv->pSystem->GetISystemEventDispatcher()->RemoveListener(this);
}

ViewportRaycastInfo Viewport::SceneViewport::GetRayForMouse(Vec2 mousePos, Vec2 vpSize)
{
	Vec2 normCoords = 2.0f * mousePos / vpSize - Vec2(1, 1); // [-1; 1)
	Vec3 scale(-normCoords.x, 1, -normCoords.y);
	Vec3 nearPoint = m_Cam.GetEdgeN().CompMul(scale);
	Vec3 farPoint = m_Cam.GetEdgeF().CompMul(scale);

	Vec3 start = m_Cam.GetMatrix() * nearPoint;
	Vec3 end = m_Cam.GetMatrix() * farPoint;

	ViewportRaycastInfo rc;
	rc.ray = Ray(start, end - start);
	rc.viwportSize = vpSize;
	rc.viewportClickPos = mousePos;

	const CameraInfo& info = m_CamInfo;

	if (info.bDrawRealWorld)
	{
		// Only select real world when it's visible (ignore LG)
		rc.sceneMask |= SCENE_MASK_REAL;
	}
	else if (info.bDrawLookingGlass)
	{
		rc.sceneMask |= SCENE_MASK_LG;
	}
	else
	{
		// When both checkboxes are clear, the game kinda breaks so allow selection from both
		rc.sceneMask |= SCENE_MASK_REAL;
		rc.sceneMask |= SCENE_MASK_LG;
	}

	return rc;
}

Matrix34 Viewport::SceneViewport::GetCameraTransform()
{
	if (!m_CamInfo.transformValid)
		return Matrix34(IDENTITY);

	Matrix34 m(Quat(m_CamInfo.rot));
	m.SetTranslation(m_CamInfo.pos);
	return m;
}

void Viewport::SceneViewport::CustomRender()
{
	DrawAuxGeom();

	// Can't render during FMV.
	if (gEnv->IsFMVPlaying())
		return;

	// Draw player in the world since camera can now move
	// TODO 2023-06-17: Gun, held object need to be changed too
	uint32 oldPlayerFlags = 0;
	if (ArkPlayer::GetInstancePtr())
	{
		IEntity* pEnt = ArkPlayer::GetInstancePtr()->GetEntity();
		oldPlayerFlags = pEnt->GetSlotFlags(0);
		pEnt->SetSlotFlags(0, oldPlayerFlags & (~ENTITY_SLOT_RENDER_NEAREST));
	}

	CCamera oldCam = gEnv->pSystem->GetViewCamera();
	UpdateCamera();
	gEnv->pSystem->SetViewCamera(m_Cam);

	gEnv->p3DEngine->PrepareOcclusion(m_Cam);
	SRenderingPassInfo renderPassInfo = SRenderingPassInfo::CreateGeneralPassRenderingInfo(m_Cam);
	int renderFlags = SHDF_ALLOW_WATER | SHDF_ALLOWPOSTPROCESS | SHDF_ALLOWHDR | SHDF_ZPASS;
	gEnv->p3DEngine->ResetPostEffects(); // Reset menu blur effect
	gEnv->p3DEngine->RenderWorld(renderFlags, renderPassInfo, __FUNCTION__);

	gEnv->pSystem->SetViewCamera(oldCam);

	// Restore slot flags
	if (ArkPlayer::GetInstancePtr())
		ArkPlayer::GetInstancePtr()->GetEntity()->SetSlotFlags(0, oldPlayerFlags);
}

bool Viewport::SceneViewport::CanActivate()
{
	// Scene viewport only works when there is a loaded level.
	return g_pGame->GetIGameFramework()->IsGameStarted();
}

void Viewport::SceneViewport::OnEnabled()
{
    // Scene doesn't use engine mouse input
    m_InputEnabled.SetIncremented(true);
}

void Viewport::SceneViewport::OnDisabled()
{
    // Restore counter
    m_InputEnabled.SetIncremented(false);
	m_InputMode = EViewportInputMode::None;
	gPreditor->pEngine->UpdateInputState();
}

void Viewport::SceneViewport::Update(bool isVisible)
{
	if (isVisible)
	{
		bool bEnableInput = ImGui::IsWindowHovered(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem);
		m_InputMode = bEnableInput ? EViewportInputMode::ImGui : EViewportInputMode::None;
	}
	else
	{
		m_InputMode = EViewportInputMode::None;
	}

	gPreditor->pEngine->UpdateInputState();
}

void Viewport::SceneViewport::ShowUI()
{
	ImGui::SameLine();
	ShowCameraMenu();

	ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();
	if (pEditor)
		pEditor->GetViewport()->ShowViewportControls();

	ImVec4 imageBounds = ShowViewportImage();

	SetCameraMode(ImGui::IsItemHovered() && ImGui::IsMouseDown(ImGuiMouseButton_Right));

	if (!m_IsInCameraMode && ImGui::IsItemClicked(ImGuiMouseButton_Left))
	{
		ImVec2 windowPos = ImGui::GetWindowPos();
		ImVec2 mousePosScreen = ImGui::GetMousePos();
		Vec2 vpSize(imageBounds.z - imageBounds.x, imageBounds.w - imageBounds.y);
		Vec2 mousePos(mousePosScreen.x - imageBounds.x - windowPos.x, mousePosScreen.y - imageBounds.y - windowPos.y);
		OnViewportClick(mousePos, vpSize);
	}

	if (m_IsInCameraMode)
	{
		Vec2 delta = gPreditor->pInput->GetMouse()->GetMouseDelta();
		Ang3 rot = m_CamInfo.rot;
		rot.z -= delta.x;
		rot.x -= delta.y;
		m_CamInfo.rot = Ang3(Quat(rot)); // Quick and dirty 360 deg wrapping

		ImGui::SetWindowFocus();
	}

	if (pEditor)
	{
		pEditor->GetToolManager()->DrawViewport(
			Vec4(imageBounds.x, imageBounds.y, imageBounds.z, imageBounds.w),
			m_Cam);
	}
}

void Viewport::SceneViewport::OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam)
{
	if (event == ESYSTEM_EVENT_LEVEL_UNLOAD)
	{
		m_CamInfo.transformValid = false;
	}
}

void Viewport::SceneViewport::SetCameraMode(bool state)
{
	if (m_IsInCameraMode == state)
		return;

	// CryLog("[SceneViewport] Camera Mode: {}", state);
	m_IsInCameraMode = state;
	m_pCameraActionSet->SetActive(state);
	gPreditor->pInput->GetMouse()->SetExclusiveInputActive(state);
}

void Viewport::SceneViewport::OnViewportClick(Vec2 mousePos, Vec2 vpSize)
{
	ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();

	if (!pEditor)
		return;

	EEditToolResult result = pEditor->GetViewport()->OnLeftMouseClick(mousePos, vpSize);

	if (result == EEditToolResult::Passthrough)
		result = pEditor->GetToolManager()->OnLeftMouseClick(mousePos, vpSize);
}

void Viewport::SceneViewport::ShowCameraMenu()
{
	if (ImGui::Button("Camera"))
		ImGui::OpenPopup("CameraMenu");

	if (ImGui::BeginPopupContextItem("CameraMenu"))
	{
		constexpr float MIN_PLANE = 0.001f;
		constexpr float MAX_PLANE = 4096;
		constexpr float DELTA_PLANE = 16;
		constexpr char FORMAT[] = "%0.3f";
		constexpr ImGuiSliderFlags FLAGS = ImGuiSliderFlags_Logarithmic;

		CameraInfo& info = m_CamInfo;

		if (ImGui::Button("TP to Player View"))
			CopyViewCameraTransform();

		ImGui::SliderFloat("FOV", &info.fov, 10, 150);
		ImGui::DragFloat3("Position", &info.pos.x);

		Ang3 rot = RAD2DEG(info.rot);
		if (ImGui::DragFloat3("Rotation", &rot.x))
			info.rot = DEG2RAD(rot);

		if (ImGui::DragFloat("Near Plane", &info.nearPlane, 0.25f, MIN_PLANE, info.farPlane, FORMAT, FLAGS))
		{
			if (info.farPlane - info.nearPlane < DELTA_PLANE)
				info.nearPlane = info.farPlane - DELTA_PLANE;
		}

		if (ImGui::DragFloat("Far Plane", &info.farPlane, 0.25f, info.nearPlane, MAX_PLANE, FORMAT, FLAGS))
		{
			if (info.farPlane - info.nearPlane < DELTA_PLANE)
				info.farPlane = info.nearPlane + DELTA_PLANE;
		}

		if (ImGui::Button("Reset Planes"))
		{
			info.nearPlane = DEFAULT_NEAR;
			info.farPlane = DEFAULT_FAR;
		}

		bool updateLookingGlass = false;
		ImGui::Text("Looking Glass");
		updateLookingGlass |= ImGui::Checkbox("Real", &info.bDrawRealWorld);
		ImGui::SameLine();
		updateLookingGlass |= ImGui::Checkbox("LG", &info.bDrawLookingGlass);

		if (updateLookingGlass)
		{
			ICVar* pCvar = gEnv->pConsole->GetCVar("e_ArkLookingGlass");
			if (info.bDrawRealWorld && info.bDrawLookingGlass)
				pCvar->Set(1);
			else if (info.bDrawRealWorld)
				pCvar->Set(2);
			else if (info.bDrawLookingGlass)
				pCvar->Set(3);
			else
				pCvar->Set(0);
		}

		ImGui::EndPopup();
	}
}

void Viewport::SceneViewport::UpdateCamera()
{
	CameraInfo& info = m_CamInfo;

	if (!info.transformValid)
	{
		info.transformValid = true;
		CopyViewCameraTransform();
	}

	Quat rotQuat = Quat(info.rot);

	// Positional input
	{
		float timeDelta = gEnv->pTimer->GetRealFrameTime();

		Vec3 dir = Vec3(ZERO);
		const Vec3 fwd = Vec3(0, 1, 0);
		const Vec3 right = Vec3(1, 0, 0);
		const Vec3 up = Vec3(0, 0, 1);

		if (m_pFwd->IsHeldDown())
			dir += fwd;
		if (m_pBkwd->IsHeldDown())
			dir -= fwd;

		if (m_pRight->IsHeldDown())
			dir += right;
		if (m_pLeft->IsHeldDown())
			dir -= right;

		if (m_pUp->IsHeldDown())
			dir += up;
		if (m_pDown->IsHeldDown())
			dir -= up;

		dir.NormalizeSafe();

		Vec2 speedLimit = Vec2(CV_ed_ViewMinSpeed, CV_ed_ViewMaxSpeed);
		float accel = CV_ed_ViewAccel;

		if (m_pSpeedUp->IsHeldDown())
		{
			speedLimit *= CV_ed_ViewBoostScale;
			accel *= CV_ed_ViewBoostScale;
		}

		if (dir != Vec3(ZERO))
		{
			m_MoveSpeed += accel * timeDelta;
			m_MoveSpeed = std::clamp(m_MoveSpeed, speedLimit.x, speedLimit.y);
		}
		else
		{
			m_MoveSpeed -= accel * timeDelta;
			m_MoveSpeed = std::max(0.0f, m_MoveSpeed);
		}

		info.pos += (rotQuat * dir) * (m_MoveSpeed * timeDelta);
	}

	Matrix34 camMat;
	camMat.SetRotation33(Matrix33(rotQuat));
	camMat.SetTranslation(info.pos);
	m_Cam.SetMatrixNoUpdate(camMat);

	// Use overlay size here instead the original camera size
	// Mods may change the original camera, which would break the viewport
	m_Cam.SetFrustum(
		gEnv->pRenderer->GetOverlayWidth(),
		gEnv->pRenderer->GetOverlayHeight(),
		DEG2RAD(info.fov),
		info.nearPlane,
		info.farPlane,
		1.0f);
}

void Viewport::SceneViewport::CopyViewCameraTransform()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	m_CamInfo.pos = viewCam.GetMatrix().GetTranslation();
	m_CamInfo.rot = Ang3(viewCam.GetMatrix());
	m_CamInfo.rot.y = 0; // Reset roll
}

void Viewport::SceneViewport::DrawAuxGeom()
{
	DrawViewCameraFrustum();

	ISceneEditor* pEditor = gPreditor->pSceneEditorManager->GetEditor();

	if (pEditor)
		pEditor->GetViewport()->DrawAuxGeom();
}

void Viewport::SceneViewport::DrawViewCameraFrustum()
{
	const CCamera& viewCam = gEnv->pSystem->GetViewCamera();
	gEnv->pAuxGeomRenderer->DrawSphere(viewCam.GetPosition(), 0.05f, ColorB(255, 0, 0));
	gEnv->pAuxGeomRenderer->DrawSphere(viewCam.GetOccPos(), 0.03f, ColorB(0, 255, 0));

	// Near plane camera-space pos
	Vec3 planePos[8];
	std::fill(planePos, planePos + 4, viewCam.GetEdgeN());
	planePos[1].x *= -1; // right top
	planePos[2].x *= -1; // right bottom
	planePos[2].z *= -1;
	planePos[3].z *= -1; // left bottom

	// Near plane world pos
	Matrix34 camMat = viewCam.GetMatrix();
	for (int i = 0; i < 4; i++)
		planePos[i] = camMat * planePos[i];

	// 1 meter plane
	for (int i = 0; i < 4; i++)
	{
		Vec3 nearLocal = planePos[i] - viewCam.GetPosition();
		nearLocal.NormalizeSafe();
		planePos[i + 4] = viewCam.GetPosition() + nearLocal;
	}

	// Assemble indices
	vtx_idx indices[] = {
		// Near plane
		0, 1, 1, 2, 2, 3, 3, 0,
		// 1m plane
		4, 5, 5, 6, 6, 7, 7, 4,
		// Edges
		0, 4, 1, 5, 2, 6, 3, 7,
	};

	gEnv->pAuxGeomRenderer->DrawLines(planePos, std::size(planePos), indices, std::size(indices), ColorB(0, 255, 255));
}
