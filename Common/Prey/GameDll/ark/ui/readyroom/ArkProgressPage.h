// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkUIMenuBase.h>
#include <_unknown/IArkReadyRoomMetaUI.h>

class ArkReadyRoomManager;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkProgressPage
// Header:  Prey/GameDll/ark/ui/readyroom/ArkProgressPage.h
class ArkProgressPage : public ArkUIMenuBase<ArkProgressPage>, public IArkReadyRoomMetaUI
{ // Size=40 (0x28)
public:
	ArkReadyRoomManager& m_readyRoomManager;

	ArkProgressPage(ArkReadyRoomManager& _readyRoomManager);
	virtual ~ArkProgressPage();
	virtual void Open();
	virtual void Close();
	void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(this, _pSender, _event, _args); }

	static inline auto FArkProgressPageOv1 = PreyFunction<void(ArkProgressPage* const _this, ArkReadyRoomManager& _readyRoomManager)>(0x1471B10);
	static inline auto FOpen = PreyFunction<void(IArkReadyRoomMetaUI* const _this)>(0x1471E90);
	static inline auto FClose = PreyFunction<void(IArkReadyRoomMetaUI* const _this)>(0x1471E40);
	static inline auto FOnButtonPress = PreyFunction<void(ArkProgressPage* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1471E80);
};
#endif // MOONCRASH
