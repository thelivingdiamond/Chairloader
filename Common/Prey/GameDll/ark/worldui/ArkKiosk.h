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
// Prey/GameDll/ark/worldui/ArkKiosk.h
class ArkKiosk : public ArkKioskBase // Id=801B8C9 Size=600
{
public:
	class ArkKioskButton // Id=801B8CA Size=24
	{
	public:
		string m_header;
		string m_body;
		EArkKioskButtonState m_state;
		bool m_bVisible;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::array<ArkKiosk::ArkKioskButton,3> m_buttons;
	string m_header;
	string m_body;
	bool m_bElevatorError;
	bool m_bIsTimerKiosk;
	bool m_bSurvivalModeOnly;
	_smart_ptr<IMaterial> m_pScreensaverMaterial;
	_smart_ptr<IMaterial> m_pPowerOffMaterial;
	
	virtual void FullSerialize(TSerialize _ser);
	void SetButtonHeader(int _button, string const &_header) { FSetButtonHeader(this,_button,_header); }
	void SetButtonBody(int _button, string const &_body) { FSetButtonBody(this,_button,_body); }
	void SetButtonVisible(int _button, bool _bVisible) { FSetButtonVisible(this,_button,_bVisible); }
	void SetButtonState(int _button, EArkKioskButtonState _state) { FSetButtonState(this,_button,_state); }
	void SetKioskHeader(string const &_header) { FSetKioskHeader(this,_header); }
	void SetKioskBody(string const &_body) { FSetKioskBody(this,_body); }
	void SetElevatorError(bool _bError) { FSetElevatorError(this,_bError); }
	virtual void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void RefreshUI(bool _bReinit);
	virtual void HandleInteraction(IUIElement *_pUIInstance);
	virtual bool IsProcessing() const;
	virtual void SetupStaticMaterial();
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual bool GrantInstances() const;
	virtual bool IsEnabled() const;
	virtual void OnEnabledChanged(bool _bForce);
	virtual void LoadProperties();
	virtual bool HasClock() const;
	
	static inline auto FFullSerialize = PreyFunction<void(ArkKiosk *const _this, TSerialize _ser)>(0x139E410);
	static inline auto FSetButtonHeader = PreyFunction<void(ArkKiosk *const _this, int _button, string const &_header)>(0x139F190);
	static inline auto FSetButtonBody = PreyFunction<void(ArkKiosk *const _this, int _button, string const &_body)>(0x139F160);
	static inline auto FSetButtonVisible = PreyFunction<void(ArkKiosk *const _this, int _button, bool _bVisible)>(0x139F1E0);
	static inline auto FSetButtonState = PreyFunction<void(ArkKiosk *const _this, int _button, EArkKioskButtonState _state)>(0x139F1C0);
	static inline auto FSetKioskHeader = PreyFunction<void(ArkKiosk *const _this, string const &_header)>(0x139F260);
	static inline auto FSetKioskBody = PreyFunction<void(ArkKiosk *const _this, string const &_body)>(0x139F210);
	static inline auto FSetElevatorError = PreyFunction<void(ArkKiosk *const _this, bool _bError)>(0x139F200);
	static inline auto FOnButtonPress = PreyFunction<void(ArkKiosk *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139EB70);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkKiosk const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x1397400);
	static inline auto FOnReset = PreyFunction<void(ArkKiosk *const _this, bool _bEnteringGameMode)>(0x139ED60);
	static inline auto FRefreshUI = PreyFunction<void(ArkKiosk *const _this, bool _bReinit)>(0x139EDC0);
	static inline auto FHandleInteraction = PreyFunction<void(ArkKiosk *const _this, IUIElement *_pUIInstance)>(0x139E6A0);
	static inline auto FIsProcessing = PreyFunction<bool(ArkKiosk const *const _this)>(0x139E790);
	static inline auto FSetupStaticMaterial = PreyFunction<void(ArkKiosk *const _this)>(0x139F290);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkKiosk *const _this, IUIElement *_pUIInstance)>(0x139ED80);
	static inline auto FGrantInstances = PreyFunction<bool(ArkKiosk const *const _this)>(0x139E670);
	static inline auto FIsEnabled = PreyFunction<bool(ArkKiosk const *const _this)>(0x139E750);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkKiosk *const _this, bool _bForce)>(0x139ED30);
	static inline auto FLoadProperties = PreyFunction<void(ArkKiosk *const _this)>(0x139E7D0);
	static inline auto FHasClock = PreyFunction<bool(ArkKiosk const *const _this)>(0x1B933B0);
};

