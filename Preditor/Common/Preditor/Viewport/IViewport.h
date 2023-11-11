#pragma once

enum class EViewportInputMode
{
	//! No input events are handled by the game.
	None,

	//! Only Chairloader's ImGui will process the input.
	ImGui,

	//! The input will be passed to the game.
	Game,
};

struct IViewport
{
	virtual ~IViewport() {}

	//! @returns whether CustomRender needs to be called this frame.
	virtual bool NeedCustomRender() = 0;

	//! Called in place of default p3DEngine->RenderWorld.
	virtual void CustomRender() = 0;

	//! Checks whether hardware mouse events should be passed to listeners (e.g. FlashUI).
	//! @returns true if need to, false otherwise.
	virtual EViewportInputMode GetInputMode() = 0;
};
