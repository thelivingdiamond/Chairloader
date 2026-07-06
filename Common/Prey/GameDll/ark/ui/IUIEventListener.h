// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IUIEventSystem;
struct SUIArguments;
struct SUIEvent;

// IUIEventListener
// Header:  Prey/GameDll/ark/ui/IUIEventListener.h
// Include: Prey/CrySystem/Scaleform/IFlashUI.h
struct IUIEventListener
{ // Size=8 (0x8)
	virtual SUIArguments OnEvent(const SUIEvent& event) = 0;
	virtual void OnEventSystemDestroyed(IUIEventSystem* pEventSystem) = 0;
	virtual ~IUIEventListener();
};
#endif // !MOONCRASH
