#pragma once
#include <Chairloader/IChairloaderImGui.h>

namespace Internal
{
struct IChairloaderDll;
}

struct IChairToPreditor;

class ChairToolsUtils
{
public:
	static Internal::IChairloaderDll* GetDll();
	static ImFont* GetFont(IChairloaderImGui::EFont font);

	//! ImGui::MenuItem but with int* instead of bool*.
	static bool MenuItemCVar(const char* label, const char* shortcut, int* p_selected, bool enabled = true);

#ifdef PREDITOR
	static void SetIChairToPreditor(IChairToPreditor* pChair);
#endif
};
