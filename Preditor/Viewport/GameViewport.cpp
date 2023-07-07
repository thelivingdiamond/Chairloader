#include <Preditor/Engine/IPreditorEngine.h>
#include <Preditor/Input/IPreditorInput.h>
#include "GameViewport.h"

Viewport::GameViewport::GameViewport()
{
	m_InputEnabled.SetIncremented(true);
	m_InputLocked.SetIncremented(true);

	gPreditor->pInput->FindAction("viewport.unlock_mouse")->AddListener(
		[this](const KeyActionEventArgs& ev)
		{
			if (ev.isPressed && IsActive())
				m_InputLocked.SetIncremented(true);
		});
}

void Viewport::GameViewport::OnDisabled()
{
	BaseViewport::OnDisabled();

	// Restore mouse counter
	SetInputEnabled(true);
	m_InputLocked.SetIncremented(false);
}

void Viewport::GameViewport::Update(bool isVisible)
{
	if (isVisible)
	{
		bool bFocused = false;
		if (ImGui::IsWindowFocused())
		{
			// Check if focused in Windows
			ImGuiViewport* vp = ImGui::GetWindowViewport();
			bFocused = vp->PlatformUserData && ImGui::GetPlatformIO().Platform_GetWindowFocus(vp);
		}

		SetInputEnabled(bFocused && ImGui::IsWindowHovered());

		// Unlock the mouse on focus loss
		if (!bFocused)
			m_InputLocked.SetIncremented(true);
	}
	else
	{
		SetInputEnabled(false);
		m_InputLocked.SetIncremented(true);
	}
}

void Viewport::GameViewport::ShowUI()
{
	ImGui::SameLine();
	bool bLockMouse = !m_InputLocked.IsIncremented();
	if (ImGui::Checkbox("Lock Mouse", &bLockMouse))
		m_InputLocked.SetIncremented(!bLockMouse);

#ifdef DEBUG_BUILD
	ImGui::SameLine();
	ImGui::Text("Input: %d", m_InputActive);
#endif

    ShowViewportImage();

	if (ImGui::IsItemClicked(ImGuiMouseButton_Left))
		m_InputLocked.SetIncremented(false);
}

void Viewport::GameViewport::SetInputEnabled(bool state)
{
	m_InputActive = state;
	gPreditor->pEngine->SetGameInputEnabled(state);
	m_InputEnabled.SetIncremented(!state);
}
