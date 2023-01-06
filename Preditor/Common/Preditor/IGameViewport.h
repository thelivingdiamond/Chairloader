#pragma once

class CSystem;

struct IGameViewport
{
	virtual ~IGameViewport() {}

	//! @returns whether CustomRender needs to be called this frame.
	virtual bool NeedCustomRender() = 0;

	//! Called in place of default p3DEngine->RenderWorld.
	virtual void CustomRender() = 0;
};
