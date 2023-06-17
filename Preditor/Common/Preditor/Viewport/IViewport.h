#pragma once

struct IViewport
{
	virtual ~IViewport() {}

	//! @returns whether CustomRender needs to be called this frame.
	virtual bool NeedCustomRender() = 0;

	//! Called in place of default p3DEngine->RenderWorld.
	virtual void CustomRender() = 0;

	//! Checks whether hardware mouse events should be passed to listeners (e.g. FlashUI).
	//! @returns true if need to, false otherwise.
	virtual bool EnableMouseEvents() = 0;
};
