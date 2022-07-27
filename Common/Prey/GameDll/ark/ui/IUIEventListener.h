// Header file automatically created from a PDB.

#pragma once

struct IUIEventSystem;
struct SUIArguments;
struct SUIEvent;

// Header: Override
// Prey/GameDll/ark/ui/IUIEventListener.h
struct IUIEventListener // Id=8002306 Size=8
{
	virtual SUIArguments OnEvent(SUIEvent const &arg0) = 0;
	virtual void OnEventSystemDestroyed(IUIEventSystem *arg0) = 0;
	virtual ~IUIEventListener();
};

