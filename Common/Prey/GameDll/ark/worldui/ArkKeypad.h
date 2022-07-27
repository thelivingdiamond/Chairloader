// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkKeyWorldUI.h>

class ICrySizer;
struct IEntity;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkKeypad.h
class ArkKeypad : public ArkKeyWorldUI // Id=801BC93 Size=600
{
public:
	enum class EArkKeypadState
	{
		Invalid = 0,
		Processing = 1,
		Failure = 2,
		Locked = 3,
		Unlocked = 4,
	};

	ArkKeypad::EArkKeypadState m_state;
	ArkKeypad::EArkKeypadState m_pendingState;
	ArkTimeRemaining m_timer;
	string m_currentCode;
	float m_validationDelay;
	float m_failDelay;
	float m_successDelay;
	int m_codeLength;
	int m_hackingLevel;
	uint64_t m_hackingRequirement;
	uint64_t m_keycode;
	
	ArkKeypad();
	virtual ~ArkKeypad();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnStopLookingAt(unsigned _targetId);
	void OnHackingFinished(bool _bSuccess) { FOnHackingFinished(this,_bSuccess); }
	bool ButtonPressed(string const &_buttonName) { return FButtonPressed(this,_buttonName); }
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual bool SetLocked(bool _bLocked, bool _bForce);
	void ReinitializeUI() { FReinitializeUI(this); }
	virtual void LoadProperties();
	virtual void LoadInstanceProperties();
	virtual const char *GetInteractFunctionName() const;
	virtual bool OnWorldUIBack();
	virtual bool IsProcessing() const;
	void SetState(ArkKeypad::EArkKeypadState _state, bool _bForce) { FSetState(this,_state,_bForce); }
	
#if 0
	int GetHackingLevel() const;
	bool Backspace();
#endif
	
	static inline auto FUpdate = PreyFunction<void(ArkKeypad *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x139C6B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkKeypad const *const _this, ICrySizer *_s)>(0x139B3E0);
	static inline auto FFullSerialize = PreyFunction<void(ArkKeypad *const _this, TSerialize _ser)>(0x139B170);
	static inline auto FPostSerialize = PreyFunction<void(ArkKeypad *const _this)>(0x139BED0);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkKeypad *const _this, unsigned _targetId)>(0x139BAA0);
	static inline auto FOnStopLookingAt = PreyFunction<void(ArkKeypad *const _this, unsigned _targetId)>(0x139BD70);
	static inline auto FOnHackingFinished = PreyFunction<void(ArkKeypad *const _this, bool _bSuccess)>(0x139B960);
	static inline auto FButtonPressed = PreyFunction<bool(ArkKeypad *const _this, string const &_buttonName)>(0x139B120);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkKeypad const *const _this)>(0x1A42CE0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkKeypad *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x139B9F0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkKeypad *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x139B8A0);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkKeypad *const _this, IUIElement *_pUIInstance)>(0x139BEB0);
	static inline auto FSetLocked = PreyFunction<bool(ArkKeypad *const _this, bool _bLocked, bool _bForce)>(0x139C3A0);
	static inline auto FReinitializeUI = PreyFunction<void(ArkKeypad *const _this)>(0x139BF10);
	static inline auto FLoadProperties = PreyFunction<void(ArkKeypad *const _this)>(0x139B570);
	static inline auto FLoadInstanceProperties = PreyFunction<void(ArkKeypad *const _this)>(0x139B410);
	static inline auto FGetInteractFunctionName = PreyFunction<const char *(ArkKeypad const *const _this)>(0x139B3D0);
	static inline auto FOnWorldUIBack = PreyFunction<bool(ArkKeypad *const _this)>(0x139BDC0);
	static inline auto FIsProcessing = PreyFunction<bool(ArkKeypad const *const _this)>(0x139B400);
	static inline auto FSetState = PreyFunction<void(ArkKeypad *const _this, ArkKeypad::EArkKeypadState _state, bool _bForce)>(0x139C400);
};

