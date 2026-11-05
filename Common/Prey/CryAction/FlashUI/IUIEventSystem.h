// Header file automatically created from a PDB.
#pragma once

class ICrySizer;
struct IUIEventListener;
struct SUIArguments;
struct SUIEvent;
struct SUIEventDesc;

// IUIEventSystem
// Header:  _unknown/IUIEventSystem.h
// Include: Prey/CrySystem/Scaleform/IFlashUI.h
struct IUIEventSystem
{ // Size=8 (0x8)
	enum EEventSystemType
	{
		eEST_UI_TO_SYSTEM = 0,
		eEST_SYSTEM_TO_UI = 1,
	};

	virtual ~IUIEventSystem();
	virtual const char* GetName() const = 0;
	virtual IUIEventSystem::EEventSystemType GetType() const = 0;
	virtual unsigned RegisterEvent(const SUIEventDesc& sEventDesc) = 0;
	virtual void RegisterListener(IUIEventListener* pListener, const char* name) = 0;
	virtual void UnregisterListener(IUIEventListener* pListener) = 0;
	virtual SUIArguments SendEvent(const SUIEvent& event) = 0;
	virtual const SUIEventDesc* GetEventDesc(int index) const = 0;
	virtual const SUIEventDesc* GetEventDesc(const char* sEventName) const = 0;
	virtual int GetEventCount() const = 0;
	virtual unsigned GetEventId(const char* sEventName) = 0;
	virtual void GetMemoryUsage(ICrySizer* s) const = 0;
};

