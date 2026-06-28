// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/IUIElementEventListener.h>

class CCryName;
struct IEntity;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Override
// Prey/GameDll/ark/ui/ArkUIMenuBase.h
template <typename T>
class ArkUIMenuBase : public IUIElementEventListener // Id=8016710 Size=24
{
public:
	using TUIEventHandler = void (T::*)(IUIElement *const , SUIEventDesc const &, SUIArguments const &);
	using TUIEventHandlers = std::map<CCryName, TUIEventHandler>;
	
	TUIEventHandlers m_handlers;
	
#if 0
	virtual void OnUIEvent(IUIElement *_pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	void AddHandler(CCryName arg0, void (*const arg1)(IUIElement *const , SUIEventDesc const &, SUIArguments const &));
	void AddHandler(const char *const arg0, void (*const arg1)(IUIElement *const , SUIEventDesc const &, SUIArguments const &));
	static void PlayAudioTrigger(IEntity *const arg0, SUIArguments const &arg1);
	void OnForceFeedback(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual ~ArkUIMenuBase();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>

class CCryName;
struct IEntity;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkUIMenuBase<ArkBrightnessMenu>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkBrightnessMenu> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkBrightnessMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkBrightnessMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkBrightnessMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkBrightnessMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkBrightnessMenu>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkBrightnessMenu>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkBrightnessMenu>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1420DB0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkBrightnessMenu>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkCharacterSelect>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkCharacterSelect> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkCharacterSelect::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkCharacterSelect::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkCharacterSelect::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkCharacterSelect::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkCharacterSelect>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkCharacterSelect>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkCharacterSelect>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14619A0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkCharacterSelect>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkChipsetStore>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkChipsetStore> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkChipsetStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkChipsetStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkChipsetStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkChipsetStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkChipsetStore>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkChipsetStore>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkChipsetStore>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1466820);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkChipsetStore>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkDockingStation>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkDockingStation> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkDockingStation::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkDockingStation::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkDockingStation::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkDockingStation::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkDockingStation>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkDockingStation>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14AF880);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkDockingStation>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x149E500);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkDockingStation>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkFabricator>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkFabricator> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkFabricator::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkFabricator::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkFabricator::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkFabricator::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkFabricator>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkFabricator>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x11B2F30);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkFabricator>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x11B03F0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkFabricator>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkFocusModeUIComponent>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkFocusModeUIComponent> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkFocusModeUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkFocusModeUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkFocusModeUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkFocusModeUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkFocusModeUIComponent>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkFocusModeUIComponent>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkFocusModeUIComponent>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1436E20);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkFocusModeUIComponent>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkGenderSelectMenu>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkGenderSelectMenu> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkGenderSelectMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkGenderSelectMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkGenderSelectMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkGenderSelectMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkGenderSelectMenu>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkGenderSelectMenu>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkGenderSelectMenu>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1423B80);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkGenderSelectMenu>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkInventoryStore>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkInventoryStore> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkInventoryStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkInventoryStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkInventoryStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkInventoryStore::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkInventoryStore>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkInventoryStore>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkInventoryStore>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x146E590);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkInventoryStore>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkKeyWorldUI>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkKeyWorldUI> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkKeyWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkKeyWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkKeyWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkKeyWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkKeyWorldUI>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkKeyWorldUI>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14AF880);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkKeyWorldUI>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14A73B0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkKeyWorldUI>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkKioskBase>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkKioskBase> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkKioskBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkKioskBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkKioskBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkKioskBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkKioskBase>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkKioskBase>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14AF880);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkKioskBase>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14AA270);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkKioskBase>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkLauncherMenu>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkLauncherMenu> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkLauncherMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkLauncherMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkLauncherMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkLauncherMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkLauncherMenu>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkLauncherMenu>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkLauncherMenu>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x143FEF0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkLauncherMenu>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkLeaderboardUI>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkLeaderboardUI> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkLeaderboardUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkLeaderboardUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkLeaderboardUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkLeaderboardUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkLeaderboardUI>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkLeaderboardUI>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkLeaderboardUI>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14270F0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkLeaderboardUI>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkModalDialogBase>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkModalDialogBase> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkModalDialogBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkModalDialogBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkModalDialogBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkModalDialogBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkModalDialogBase>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkModalDialogBase>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkModalDialogBase>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1724F90);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkModalDialogBase>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkNoteUI>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkNoteUI> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkNoteUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkNoteUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkNoteUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkNoteUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkNoteUI>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkNoteUI>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1727A10);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkNoteUI>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1727250);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkNoteUI>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkOperatorDispenser>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkOperatorDispenser> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkOperatorDispenser::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkOperatorDispenser::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkOperatorDispenser::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkOperatorDispenser::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkOperatorDispenser>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkOperatorDispenser>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x11B2F30);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkOperatorDispenser>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x12211F0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkOperatorDispenser>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkPDAComponent>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkPDAComponent> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkPDAComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkPDAComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkPDAComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkPDAComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkPDAComponent>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkPDAComponent>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkPDAComponent>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x172B070);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkPDAComponent>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkPauseMenu>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkPauseMenu> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkPauseMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkPauseMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkPauseMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkPauseMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkPauseMenu>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkPauseMenu>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkPauseMenu>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1451E60);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkPauseMenu>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkPlayerUIComponent>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkPlayerUIComponent> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkPlayerUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkPlayerUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkPlayerUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkPlayerUIComponent::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkPlayerUIComponent>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkPlayerUIComponent>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x16A10D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkPlayerUIComponent>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x16A0980);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkPlayerUIComponent>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkReadyRoomManager>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkReadyRoomManager> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkReadyRoomManager::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkReadyRoomManager::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkReadyRoomManager::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkReadyRoomManager::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkReadyRoomManager>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkReadyRoomManager>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1727A10);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkReadyRoomManager>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14738C0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkReadyRoomManager>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkRecycler>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkRecycler> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkRecycler::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkRecycler::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkRecycler::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkRecycler::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkRecycler>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkRecycler>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x12F7670);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkRecycler>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x12F6160);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkRecycler>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkSaveLoadMenu>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkSaveLoadMenu> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkSaveLoadMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkSaveLoadMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkSaveLoadMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkSaveLoadMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkSaveLoadMenu>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkSaveLoadMenu>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkSaveLoadMenu>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x145BE90);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkSaveLoadMenu>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkScorecard>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkScorecard> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkScorecard::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkScorecard::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkScorecard::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkScorecard::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkScorecard>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkScorecard>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkScorecard>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1479050);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkScorecard>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkSimulationLaunchPage>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkSimulationLaunchPage> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkSimulationLaunchPage::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkSimulationLaunchPage::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkSimulationLaunchPage::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkSimulationLaunchPage::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkSimulationLaunchPage>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkSimulationLaunchPage>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkSimulationLaunchPage>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x147A940);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkSimulationLaunchPage>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkStationWorldUI>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkStationWorldUI> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkStationWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkStationWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkStationWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkStationWorldUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkStationWorldUI>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkStationWorldUI>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x14AF880);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkStationWorldUI>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14B1290);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkStationWorldUI>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkStoreUI>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkStoreUI> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkStoreUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkStoreUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkStoreUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkStoreUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkStoreUI>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkStoreUI>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkStoreUI>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x142FDF0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkStoreUI>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkTutorialMenu>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkTutorialMenu> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkTutorialMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkTutorialMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkTutorialMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkTutorialMenu::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkTutorialMenu>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkTutorialMenu>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkTutorialMenu>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1432210);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkTutorialMenu>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<ArkUIOptionMenuBase>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<ArkUIOptionMenuBase> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl ArkUIOptionMenuBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkUIOptionMenuBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl ArkUIOptionMenuBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl ArkUIOptionMenuBase::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const CCryName _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv1(this, _eventName, _handler); }
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<ArkUIOptionMenuBase>();
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<ArkUIOptionMenuBase>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv1 = PreyFunction<void(ArkUIMenuBase<ArkUIOptionMenuBase>* const _this, const CCryName _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x17616E0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<ArkUIOptionMenuBase>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x17615C0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<ArkUIOptionMenuBase>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkInventoryUI>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkInventoryUI> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkInventoryUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkInventoryUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkInventoryUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkInventoryUI::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkInventoryUI>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkInventoryUI>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x16A10D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkInventoryUI>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x171E970);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkInventoryUI>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAFabricationPlans>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAFabricationPlans> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAFabricationPlans::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAFabricationPlans::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAFabricationPlans::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAFabricationPlans::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAFabricationPlans>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAFabricationPlans>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAFabricationPlans>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x173C470);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAFabricationPlans>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageAbilities>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageAbilities> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageAbilities::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageAbilities::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageAbilities::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageAbilities::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageAbilities>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageAbilities>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageAbilities>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x17350F0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageAbilities>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageAudioLogs>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageAudioLogs> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageAudioLogs::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageAudioLogs::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageAudioLogs::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageAudioLogs::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageAudioLogs>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageAudioLogs>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageAudioLogs>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1739C60);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageAudioLogs>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageChipsets>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageChipsets> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageChipsets::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageChipsets::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageChipsets::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageChipsets::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageChipsets>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageChipsets>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageChipsets>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x14548F0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageChipsets>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageEmails>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageEmails> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageEmails::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageEmails::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageEmails::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageEmails::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageEmails>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageEmails>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageEmails>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1765F00);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageEmails>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageInventory>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageInventory> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageInventory::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageInventory::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageInventory::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageInventory::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageInventory>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageInventory>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageInventory>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x173DD60);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageInventory>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageLevelMap>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageLevelMap> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageLevelMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageLevelMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageLevelMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageLevelMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageLevelMap>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageLevelMap>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageLevelMap>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x17467D0);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageLevelMap>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageObjectives>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageObjectives> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageObjectives::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageObjectives::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageObjectives::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageObjectives::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageObjectives>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageObjectives>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageObjectives>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x174C670);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageObjectives>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkPDAPageStationMap>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkPDAPageStationMap> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkPDAPageStationMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageStationMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkPDAPageStationMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkPDAPageStationMap::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkPDAPageStationMap>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkPDAPageStationMap>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x172E9D0);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkPDAPageStationMap>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x142BC30);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkPDAPageStationMap>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};

// ArkUIMenuBase<CArkUIHUD>
// Header:  Prey/GameDll/ark/ui/arkuimenubase.h
class ArkUIMenuBase<CArkUIHUD> : public IUIElementEventListener
{ // Size=24 (0x18)
public:
	using TUIEventHandler = void (*)(IUIElement* const, const SUIEventDesc&, const SUIArguments&);
	using TUIEventHandlers = std::map<CCryName,void (__cdecl CArkUIHUD::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkUIHUD::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > >;

	std::map<CCryName,void (__cdecl CArkUIHUD::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &),std::less<CCryName>,std::allocator<std::pair<CCryName const ,void (__cdecl CArkUIHUD::*)(IUIElement *,SUIEventDesc const &,SUIArguments const &)> > > m_handlers;

	virtual void OnUIEvent(IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args);
	void AddHandler(const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&)) { FAddHandlerOv0(this, _eventName, _handler); }
	void OnForceFeedback(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnForceFeedback(this, _pSender, _event, _args); }

#if 0
	ArkUIMenuBase<CArkUIHUD>();
	void AddHandler(const CCryName _arg0_, void (* const_arg1_)(IUIElement* const, const SUIEventDesc&, const SUIArguments&));
	static void PlayAudioTrigger(IEntity* const _arg0_, const SUIArguments& _arg1_);
#endif

	static inline auto FOnUIEvent = PreyFunction<void(ArkUIMenuBase<CArkUIHUD>* const _this, IUIElement* _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1740210);
	static inline auto FAddHandlerOv0 = PreyFunction<void(ArkUIMenuBase<CArkUIHUD>* const _this, const char* const _eventName, void (* const_handler)(IUIElement* const, const SUIEventDesc&, const SUIArguments&))>(0x1759A40);
	static inline auto FOnForceFeedback = PreyFunction<void(ArkUIMenuBase<CArkUIHUD>* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x173F710);
};
#endif // !MOONCRASH
