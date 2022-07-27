// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/worldui/ArkKioskBase.h>

struct IEntity;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkGenericElevatorKiosk.h
class ArkGenericElevatorKiosk : public ArkKioskBase // Id=801B8C1 Size=600
{
public:
	class ArkElevatorKioskButton // Id=801B8C2 Size=24
	{
	public:
		string m_secondaryText;
		string m_floorText;
		bool m_bVisible;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	EArkElevatorKioskState m_state;
	std::array<ArkGenericElevatorKiosk::ArkElevatorKioskButton,3> m_buttons;
	string m_currentFloorText;
	string m_defaultStateText;
	string m_failStateText;
	bool m_bStateChangeRefresh;
	
	ArkGenericElevatorKiosk();
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	void SetButtonSecondaryText(int _button, string const &_secondary) { FSetButtonSecondaryText(this,_button,_secondary); }
	void SetButtonFloorText(int _button, string const &_floor) { FSetButtonFloorText(this,_button,_floor); }
	void SetButtonVisible(int _button, bool _bVisible) { FSetButtonVisible(this,_button,_bVisible); }
	void SetCurrentFloorText(string const &_text) { FSetCurrentFloorText(this,_text); }
	void SetDefaultStateText(string const &_text) { FSetDefaultStateText(this,_text); }
	void SetFailStateText(string const &_text) { FSetFailStateText(this,_text); }
	void SetState(EArkElevatorKioskState _state) { FSetState(this,_state); }
	virtual void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void RefreshUI(bool _bReinit);
	virtual void HandleInteraction(IUIElement *_pUIInstance);
	virtual bool IsProcessing() const;
	
	static inline auto FFullSerialize = PreyFunction<void(ArkGenericElevatorKiosk *const _this, TSerialize _ser)>(0x1397110);
	static inline auto FPostSerialize = PreyFunction<void(ArkGenericElevatorKiosk *const _this)>(0x13974B0);
	static inline auto FSetButtonSecondaryText = PreyFunction<void(ArkGenericElevatorKiosk *const _this, int _button, string const &_secondary)>(0x13977B0);
	static inline auto FSetButtonFloorText = PreyFunction<void(ArkGenericElevatorKiosk *const _this, int _button, string const &_floor)>(0x1397730);
	static inline auto FSetButtonVisible = PreyFunction<void(ArkGenericElevatorKiosk *const _this, int _button, bool _bVisible)>(0x1397830);
	static inline auto FSetCurrentFloorText = PreyFunction<void(ArkGenericElevatorKiosk *const _this, string const &_text)>(0x1397850);
	static inline auto FSetDefaultStateText = PreyFunction<void(ArkGenericElevatorKiosk *const _this, string const &_text)>(0x1397880);
	static inline auto FSetFailStateText = PreyFunction<void(ArkGenericElevatorKiosk *const _this, string const &_text)>(0x13978C0);
	static inline auto FSetState = PreyFunction<void(ArkGenericElevatorKiosk *const _this, EArkElevatorKioskState _state)>(0x1397900);
	static inline auto FOnButtonPress = PreyFunction<void(ArkGenericElevatorKiosk *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1397300);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkGenericElevatorKiosk const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1397400);
	static inline auto FRefreshUI = PreyFunction<void(ArkGenericElevatorKiosk *const _this, bool _bReinit)>(0x1397510);
	static inline auto FHandleInteraction = PreyFunction<void(ArkGenericElevatorKiosk *const _this, IUIElement *_pUIInstance)>(0x13972E0);
	static inline auto FIsProcessing = PreyFunction<bool(ArkGenericElevatorKiosk const *const _this)>(0x13972F0);
};

