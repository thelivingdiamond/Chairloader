// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/IUIModule.h>
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/IUIGameEventSystem.h>
#include <Prey/ArkStubs.h>
#include <Prey/ArkStubs.h>

struct IUIEventSystem;

// CUIMenuEvents
// Header:  Prey/GameDll/ui/UIMenuEvents.h
class CUIMenuEvents : public IUIGameEventSystem, public IUIModule
{ // Size=104 (0x68)
public:
	enum EUIEvent
	{
		eUIE_StartIngameMenu = 0,
		eUIE_StopIngameMenu = 1,
	};

	SUIEventReceiverDispatcher<CUIMenuEvents> m_eventDispatcher;
	SUIEventSenderDispatcher<enum CUIMenuEvents::EUIEvent> m_eventSender;
	IUIEventSystem* m_pUIEvents;
	IUIEventSystem* m_pUIFunctions;
	bool m_bIsIngameMenuStarted;

	virtual const char* GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void Reset();
	void DisplayIngameMenu(bool bDisplay, bool bForce) { FDisplayIngameMenu(this, bDisplay, bForce); }

#if 0
	CUIMenuEvents();
	static const char* GetTypeNameS();
	bool IsIngameMenuStarted() const;
	void StartIngameMenu();
	void StopIngameMenu();
#endif

#ifndef MOONCRASH
	static inline auto FGetTypeName = PreyFunction<const char* (const CUIMenuEvents* const _this)>(0x18006E0);
	static inline auto FInitEventSystem = PreyFunction<void(CUIMenuEvents* const _this)>(0x18006F0);
	static inline auto FUnloadEventSystem = PreyFunction<void(CUIMenuEvents* const _this)>(0x1800CC0);
	static inline auto FReset = PreyFunction<void(IUIModule* const _this)>(0x1800CB0);
	static inline auto FDisplayIngameMenu = PreyFunction<void(CUIMenuEvents* const _this, bool bDisplay, bool bForce)>(0x18003D0);
#else
	static inline auto FGetTypeName = PreyFunction<const char* (const CUIMenuEvents* const _this)>(0x1928290);
	static inline auto FInitEventSystem = PreyFunction<void(CUIMenuEvents* const _this)>(0x19282A0);
	static inline auto FUnloadEventSystem = PreyFunction<void(CUIMenuEvents* const _this)>(0x19287E0);
	static inline auto FReset = PreyFunction<void(IUIModule* const _this)>(0x19287D0);
	static inline auto FDisplayIngameMenu = PreyFunction<void(CUIMenuEvents* const _this, bool bDisplay, bool bForce)>(0x1927E40);
#endif
};

