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

