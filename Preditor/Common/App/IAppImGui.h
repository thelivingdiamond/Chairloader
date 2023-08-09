#pragma once

struct IAppImGui
{
	virtual ~IAppImGui() {}
	virtual void BeginFrame() = 0;
	virtual void EndFrame() = 0;
};
