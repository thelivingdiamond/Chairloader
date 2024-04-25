#include <Prey/CrySystem/ITimer.h>
#include "PerfOverlay.h"
#include "ChairToolsUtils.h"

PerfOverlay::PerfOverlay() {
	REGISTER_CVAR2("ch_perf_overlay", &m_Enabled, 0, VF_DUMPTOCHAIR, "Show FPS counter");
	REGISTER_CVAR2("ch_perf_overlay_frametime", &m_ShowFrameTime, 0, VF_DUMPTOCHAIR, "Show frame time with FPS counter");
}

PerfOverlay::~PerfOverlay()
{
	gEnv->pConsole->UnregisterVariable("ch_perf_overlay");
	gEnv->pConsole->UnregisterVariable("ch_perf_overlay_frametime");
}

void PerfOverlay::Update() {
	if (!m_Enabled) {
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

		if (m_ShowFrameTime) {
			ImGui::Text("Frametime: %6.3f ms", m_LastFrameTime * 1000.0);
		}
	}

	ImGui::End();
}

void PerfOverlay::ShowMenu() {
	ChairToolsUtils::MenuItemCVar("Enable overlay", nullptr, &m_Enabled);
	ImGui::BeginDisabled(!m_Enabled);
	ChairToolsUtils::MenuItemCVar("Show frame time", nullptr, &m_ShowFrameTime);
	ImGui::EndDisabled();
}

void PerfOverlay::SetEnabled(bool state) {
	m_Enabled = state;
}

void PerfOverlay::SetFrameTimeVisible(bool state) {
	m_ShowFrameTime = state;
}
