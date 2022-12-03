#pragma once
#include <imgui.h>

struct IChairloaderImGui
{
	enum class EFont
	{
		Default,	//!< The font used for UI
		Monospace,	//!< The monospace font for the console
		FontCount
	};

	~IChairloaderImGui() {}

	//! Checks that mod's ImGui is compatible with Chairloader's.
	//! @returns true if compatible
	virtual bool CheckVersionAndDataLayout(const char* version_str, size_t sz_io, size_t sz_style,
		size_t sz_vec2, size_t sz_vec4, size_t sz_drawvert, size_t sz_drawidx) = 0;

	//! Gets allocator functions used by ImGui.
	virtual void GetAllocatorFuncs(ImGuiMemAllocFunc* p_alloc_func, ImGuiMemFreeFunc* p_free_func, void** p_user_data) = 0;

	//! @returns the main ImGui context used by Chairloader.
	virtual ImGuiContext* GetContext() = 0;

	//! @returns the font. If the font failed to load, returns the default one. Never returns nullptr.
	virtual ImFont* GetFont(EFont font) = 0;
};
