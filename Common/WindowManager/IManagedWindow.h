#pragma once

struct IManagedWindow
{
	virtual ~IManagedWindow() {}

	//! Updates and shows the window.
	//! @returns whether the window still exists. If false, will be removed from the manager.
	virtual bool UpdateWindow() = 0;
};
