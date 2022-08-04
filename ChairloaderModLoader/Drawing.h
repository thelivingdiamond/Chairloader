#ifndef DRAWING_H
#define DRAWING_H

#include <Windows.h>

#include "ImGui/imgui.h"
#include "ImGui/imgui_stdlib.h"
#include <map>
#include <string>
#include <vector>
#include <time.h>

#include <pugixml.hpp>



class Drawing
{
private:
	static LPCSTR lpWindowName;
	static ImVec2 vWindowSize;
	static ImGuiWindowFlags WindowFlags;
	static bool bDraw;
public:
	static void Active();
	static bool isActive();
	static void Draw();
	static void Setup();
};

#endif
