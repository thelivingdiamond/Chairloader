#include "Drawing.h"
#include "ModLoader.h"


LPCSTR Drawing::lpWindowName = "Chairloader Mod Manager";
ImVec2 Drawing::vWindowSize = { 800, 500 };
ImGuiWindowFlags Drawing::WindowFlags =
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar;

bool Drawing::bDraw = true;

void Drawing::Active() {
	bDraw = true;
}

bool Drawing::isActive() {
	return bDraw;
}


static ModLoader modLoader;


void Drawing::Draw()
{
	if (isActive())
	{
//		ImGui::ShowDemoWindow(&bDraw);

		ImGui::SetNextWindowSize(vWindowSize);
		ImGui::SetNextWindowBgAlpha(1.0f);
//        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
//        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5, 5));
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
            modLoader.Draw();
		}
		ImGui::End();
//        ImGui::PopStyleVar(1);
        modLoader.Update();
	}
	#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
	#endif
}

void Drawing::Setup() {
    ImGui::StyleColorsDark();
//    ImGui::GetStyle().WindowBorderSize = 0.0f;
    ImGui::GetStyle().FramePadding = {8, 5};
    ImGui::GetStyle().FrameRounding = 2;
    ImGui::GetStyle().ChildRounding = 2;
    ImGui::GetStyle().WindowRounding = 2;
    ImGui::GetStyle().PopupRounding = 2;
}


