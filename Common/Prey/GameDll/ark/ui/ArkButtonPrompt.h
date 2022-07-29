// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

struct IUIElement;
struct SUIArguments;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkButtonPrompt.h
class ArkButtonPrompt // Id=801703C Size=56
{
public:
	CCryName m_actionId;
	string m_actionMap;
	ArkSimpleTimer m_holdTimer;
	float m_baseHoldDuration;
	bool m_bUseHoldTriggerDelay;
	wstring m_inputPromptString;
	wstring m_promptText;
	bool m_bEnabled;
	bool m_bDirty;
	
	ArkButtonPrompt();
	void Clear() { FClear(this); }
	void ClearPromptText() { FClearPromptText(this); }
	void SetValues(CCryName _actionId, string const &_actionMap, string const &_promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration) { FSetValuesOv2(this,_actionId,_actionMap,_promptText,_bEnabled,_bUseHoldTriggerDelay,_holdDuration); }
	void SetValues(CCryName _actionId, string const &_actionMap, wstring const &_promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration) { FSetValuesOv1(this,_actionId,_actionMap,_promptText,_bEnabled,_bUseHoldTriggerDelay,_holdDuration); }
	void SetValues(wstring const &_promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration) { FSetValuesOv0(this,_promptText,_bEnabled,_bUseHoldTriggerDelay,_holdDuration); }
	void SetInput(CCryName _actionId, string const &_actionMap) { FSetInput(this,_actionId,_actionMap); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void CallActionscript(IUIElement *_pUIElement, int _index, string const &_setFunction) { FCallActionscript(this,_pUIElement,_index,_setFunction); }
	void PopulateArguments(SUIArguments &_args) { FPopulateArguments(this,_args); }
	bool IsVisible() const { return FIsVisible(this); }
	void OnInputDeviceChanged(EActionInputDevice _inputDevice) { FOnInputDeviceChanged(this,_inputDevice); }
	void OnOptionMenuClosed() { FOnOptionMenuClosed(this); }
	bool operator==(ArkButtonPrompt const &_rhs) const { return FoperatorEqEq(this,_rhs); }
	
#if 0
	void UpdateHoldDuration(EActionInputDevice arg0);
	string const &GetActionMap() const;
	CCryName GetActionId() const;
	bool IsEnabled() const;
	bool IsHold() const;
	wstring const &GetPromptText() const;
	void UpdateInputPromptString(EActionInputDevice arg0);
#endif
	
	static inline auto FClear = PreyFunction<void(ArkButtonPrompt *const _this)>(0x1350F70);
	static inline auto FClearPromptText = PreyFunction<void(ArkButtonPrompt *const _this)>(0x1351160);
	static inline auto FSetValuesOv2 = PreyFunction<void(ArkButtonPrompt *const _this, CCryName _actionId, string const &_actionMap, string const &_promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration)>(0x1351520);
	static inline auto FSetValuesOv1 = PreyFunction<void(ArkButtonPrompt *const _this, CCryName _actionId, string const &_actionMap, wstring const &_promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration)>(0x1351620);
	static inline auto FSetValuesOv0 = PreyFunction<void(ArkButtonPrompt *const _this, wstring const &_promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration)>(0x13514D0);
	static inline auto FSetInput = PreyFunction<void(ArkButtonPrompt *const _this, CCryName _actionId, string const &_actionMap)>(0x1351450);
	static inline auto FProcessInput = PreyFunction<void(ArkButtonPrompt *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x13513D0);
	static inline auto FUpdate = PreyFunction<bool(ArkButtonPrompt *const _this, float _frameTime)>(0x1351800);
	static inline auto FCallActionscript = PreyFunction<void(ArkButtonPrompt *const _this, IUIElement *_pUIElement, int _index, string const &_setFunction)>(0x1350E80);
	static inline auto FPopulateArguments = PreyFunction<void(ArkButtonPrompt *const _this, SUIArguments &_args)>(0x1351340);
	static inline auto FIsVisible = PreyFunction<bool(ArkButtonPrompt const *const _this)>(0x13511C0);
	static inline auto FOnInputDeviceChanged = PreyFunction<void(ArkButtonPrompt *const _this, EActionInputDevice _inputDevice)>(0x13511D0);
	static inline auto FOnOptionMenuClosed = PreyFunction<void(ArkButtonPrompt *const _this)>(0x1351280);
	static inline auto FoperatorEqEq = PreyFunction<bool(ArkButtonPrompt const *const _this, ArkButtonPrompt const &_rhs)>(0x1350E00);
};

