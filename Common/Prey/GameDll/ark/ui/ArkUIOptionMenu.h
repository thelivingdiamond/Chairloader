// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ui/ArkUIOptionMenuBase.h>

class IArkOptionMenuListener;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/ArkUIOptionMenu.h
class ArkUIOptionMenu : public ArkUIOptionMenuBase // Id=80191AB Size=128
{
public:
	IArkOptionMenuListener *m_pOptionMenuListener;
	
	virtual const char *GetTypeName() const;
	virtual void Reload();
	void Show(IArkOptionMenuListener *_pCloseListener) { FShow(this,_pCloseListener); }
	virtual void Hide();
	void LoadPlayerProfile() { FLoadPlayerProfile(this); }
	virtual void QueueHide();
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnMenuClose(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual void OnClickAttribute(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual void OnPressButton(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual bool IsActive();
	virtual ~ArkUIOptionMenu();
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FGetTypeName = PreyFunction<const char *(ArkUIOptionMenu const *const _this)>(0x163D0F0);
	static inline auto FReload = PreyFunction<void(ArkUIOptionMenu *const _this)>(0x163D3B0);
	static inline auto FShow = PreyFunction<void(ArkUIOptionMenu *const _this, IArkOptionMenuListener *_pCloseListener)>(0x163D4B0);
	static inline auto FHide = PreyFunction<void(ArkUIOptionMenu *const _this)>(0x163D100);
	static inline auto FLoadPlayerProfile = PreyFunction<void(ArkUIOptionMenu *const _this)>(0x163D140);
	static inline auto FQueueHide = PreyFunction<void(ArkUIOptionMenu *const _this)>(0x163D380);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkUIOptionMenu *const _this, EControlScheme _controlScheme)>(0x163D1D0);
	static inline auto FOnMenuClose = PreyFunction<void(ArkUIOptionMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163D2B0);
	static inline auto FOnClickAttribute = PreyFunction<void(ArkUIOptionMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163D150);
	static inline auto FOnPressButton = PreyFunction<void(ArkUIOptionMenu *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x163D2E0);
	static inline auto FIsActive = PreyFunction<bool(ArkUIOptionMenu *const _this)>(0x163D130);
};

