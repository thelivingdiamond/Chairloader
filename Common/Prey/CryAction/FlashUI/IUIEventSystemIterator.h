// Header file automatically created from a PDB.
#pragma once

struct IUIEventSystem;

// IUIEventSystemIterator
// Header:  _unknown/IUIEventSystemIterator.h
// Include: Prey/CrySystem/Scaleform/IFlashUI.h
struct IUIEventSystemIterator
{ // Size=8 (0x8)
	virtual ~IUIEventSystemIterator();
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual IUIEventSystem* Next(string& sName) = 0;
};

