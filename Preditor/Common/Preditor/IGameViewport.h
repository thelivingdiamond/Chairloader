#pragma once

class CSystem;

struct IGameViewport
{
	virtual ~IGameViewport() {}

	//! @returns whether CustomRender needs to be called this frame.
	virtual bool NeedCustomRender() = 0;

	//! Called in place of default p3DEngine->RenderWorld.
	virtual void CustomRender() = 0;

	//! Processes an input event after ChairImGui but before the engine.
	//! @param	event	The input event.
	//! @returns true if the event was processed and doesn't need to be passed to the engine.
	virtual bool HandleInputEventPreGame(const SInputEvent& event) = 0;

	//! Checks whether hardware mouse events should be passed to listeners (e.g. FlashUI).
	//! @returns true if need to, false otherwise.
	virtual bool EnableMouseEvents() = 0;
};
