// Header file automatically created from a PDB.

#pragma once

struct IFlashPlayer;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Override
// Prey/GameDll/ark/ui/IUIElementEventListener.h
struct IUIElementEventListener // Id=80022C0 Size=8
{
	virtual void OnUIEvent(IUIElement *pSender, SUIEventDesc const &event, SUIArguments const &args);
	virtual void OnUIEventEx(IUIElement *pSender, const char *fscommand, SUIArguments const &args, void *pUserData);
	virtual void OnInit(IUIElement *pSender, IFlashPlayer *pFlashPlayer);
	virtual void OnUnload(IUIElement *pSender);
	virtual void OnSetVisible(IUIElement *pSender, bool bVisible);
	virtual void OnInstanceCreated(IUIElement *pSender, IUIElement *pNewInstance);
	virtual void OnInstanceDestroyed(IUIElement *pSender, IUIElement *pDeletedInstance);
	virtual ~IUIElementEventListener();
	
	static inline auto FOnUIEvent = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender, SUIEventDesc const &event, SUIArguments const &args)>(0xA13080);
	static inline auto FOnUIEventEx = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender, const char *fscommand, SUIArguments const &args, void *pUserData)>(0xA13080);
	static inline auto FOnInit = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender, IFlashPlayer *pFlashPlayer)>(0xA13080);
	static inline auto FOnUnload = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender)>(0xA13080);
	static inline auto FOnSetVisible = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender, bool bVisible)>(0xA13080);
	static inline auto FOnInstanceCreated = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender, IUIElement *pNewInstance)>(0xA13080);
	static inline auto FOnInstanceDestroyed = PreyFunction<void(IUIElementEventListener *const _this, IUIElement *pSender, IUIElement *pDeletedInstance)>(0xA13080);
};

