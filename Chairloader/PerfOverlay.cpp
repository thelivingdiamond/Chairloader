#include <Prey/CrySystem/ITimer.h>
#include "PerfOverlay.h"
#include "ChairLoader.h"

PerfOverlay::PerfOverlay() {
#ifdef DEBUG_BUILD
	m_bEnabled = true;
	m_bFrameTime = true;
#endif
}

void PerfOverlay::Update() {
	if (!m_bEnabled) {
		return;
	}

	ImGuiWindowFlags window_flags =
		ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize |
		ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing |
		ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoBackground;
	ImGui::SetNextWindowPos(ImVec2(10, 20), ImGuiCond_Always, ImVec2(0, 0));

	if (ImGui::Begin("PerfOverlay", nullptr, window_flags)) {
		// A bit of filtering so it doesn't jump around
		float frametime = gEnv->pTimer->GetRealFrameTime();
		m_LastFrameTime = FILTER_K * frametime + (1 - FILTER_K) * m_LastFrameTime;

		ImGui::Text("FPS: %5.1f", 1.0f / m_LastFrameTime);

		if (m_bFrameTime) {
			ImGui::Text("Frametime: %6.3f ms", m_LastFrameTime * 1000.0);
		}
	}

	ImGui::End();
}

void PerfOverlay::ShowMenu() {
	// TODO: Should save these somewhere
	ImGui::MenuItem("Enable overlay", nullptr, &m_bEnabled);
	ImGui::BeginDisabled(!m_bEnabled);
	ImGui::MenuItem("Show frame time", nullptr, &m_bFrameTime);
	ImGui::EndDisabled();
}

void PerfOverlay::SetEnabled(bool state) {
	m_bEnabled = state;
}

void PerfOverlay::SetFrameTimeVisible(bool state) {
	m_bFrameTime = state;
}
