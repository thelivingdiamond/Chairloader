#pragma once
#include <imgui.h>

struct IChairloaderImGui
{
	~IChairloaderImGui() {}

	//! Checks that mod's ImGui is compatible with Chairloader's.
	//! @returns true if compatible
	virtual bool CheckVersionAndDataLayout(const char* version_str, size_t sz_io, size_t sz_style,
		size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx) = 0;

	//! Gets allocator functions used by ImGui.
	virtual void GetAllocatorFuncs(ImGuiMemAllocFunc* p_alloc_func, ImGuiMemFreeFunc* p_free_func, void** p_user_data) = 0;

	//! @returns the main ImGui context used by Chairloader.
	virtual ImGuiContext* GetContext() = 0;
};
