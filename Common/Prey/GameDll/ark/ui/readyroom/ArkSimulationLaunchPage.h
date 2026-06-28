// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/IArkReadyRoomUI.h>

class ArkReadyRoomManager;
enum class EArkReadyRoomPage;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// ArkSimulationLaunchPage
// Header:  Prey/GameDll/ark/ui/readyroom/ArkSimulationLaunchPage.h
class ArkSimulationLaunchPage : public ArkUIMenuBase<ArkSimulationLaunchPage>, public IArkReadyRoomUI
{ // Size=40 (0x28)
public:
	ArkReadyRoomManager& m_readyRoomManager;

	ArkSimulationLaunchPage(ArkReadyRoomManager& _readyRoomManager);
	virtual ~ArkSimulationLaunchPage();
	virtual void Open();
	virtual void Close(bool _bImmediate, bool _bExitReadyRoom);
	virtual const char* GetLabel() const;
	void ConfirmLaunch() { FConfirmLaunch(this); }
	void OnButtonPressed(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPressed(this, _pSender, _event, _args); }

#if 0
	static EArkReadyRoomPage GetID();
#endif

	static inline auto FArkSimulationLaunchPageOv1 = PreyFunction<void(ArkSimulationLaunchPage* const _this, ArkReadyRoomManager& _readyRoomManager)>(0x147A7A0);
	static inline auto FOpen = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x147ADD0);
	static inline auto FClose = PreyFunction<void(IArkReadyRoomUI* const _this, bool _bImmediate, bool _bExitReadyRoom)>(0x147AA60);
	static inline auto FGetLabel = PreyFunction<const char* (const IArkReadyRoomUI* const _this)>(0x147ABE0);
	static inline auto FConfirmLaunch = PreyFunction<void(ArkSimulationLaunchPage* const _this)>(0x147AAC0);
	static inline auto FOnButtonPressed = PreyFunction<void(ArkSimulationLaunchPage* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x147ABF0);
};
#endif // MOONCRASH
