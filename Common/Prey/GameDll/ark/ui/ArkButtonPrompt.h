// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

enum EActionInputDevice;
struct IUIElement;
struct SUIArguments;

// ArkButtonPrompt
// Header:  Prey/GameDll/ark/ui/ArkButtonPrompt.h
class ArkButtonPrompt
{ // Size=88 (0x58)
public:
	using TPromptCallback = Functor0;

	CCryName m_actionId;
	string m_actionMap;
	ArkSimpleTimer m_holdTimer;
	float m_baseHoldDuration;
	bool m_bUseHoldTriggerDelay;
	wstring m_inputPromptString;
	wstring m_promptText;
	bool m_bEnabled;
	bool m_bDirty;
	Functor0 m_callback;

	ArkButtonPrompt();
	void Clear() { FClear(this); }
	void ClearPromptText() { FClearPromptText(this); }
	void SetValues(CCryName _actionId, const string& _actionMap, const string& _promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration, Functor0 _callback) { FSetValuesOv2(this, _actionId, _actionMap, _promptText, _bEnabled, _bUseHoldTriggerDelay, _holdDuration, _callback); }
	void SetValues(CCryName _actionId, const string& _actionMap, const wstring& _promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration, Functor0 _callback) { FSetValuesOv1(this, _actionId, _actionMap, _promptText, _bEnabled, _bUseHoldTriggerDelay, _holdDuration, _callback); }
	void SetValues(const wstring& _promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration, Functor0 _callback) { FSetValuesOv0(this, _promptText, _bEnabled, _bUseHoldTriggerDelay, _holdDuration, _callback); }
	void SetInput(CCryName _actionId, const string& _actionMap) { FSetInput(this, _actionId, _actionMap); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void CallActionscript(IUIElement* _pUIElement, int _index, const string& _setFunction) { FCallActionscript(this, _pUIElement, _index, _setFunction); }
	void CallNonHoldActionscript(IUIElement* _pUIElement, int _index, const string& _setFunction) { FCallNonHoldActionscript(this, _pUIElement, _index, _setFunction); }
	void PopulateArguments(SUIArguments& _args) { FPopulateArguments(this, _args); }
	bool IsVisible() const { return FIsVisible(this); }
	void OnInputDeviceChanged(EActionInputDevice _inputDevice) { FOnInputDeviceChanged(this, _inputDevice); }
	void OnOptionMenuClosed() { FOnOptionMenuClosed(this); }
	bool operator==(const ArkButtonPrompt& _rhs) const { return FoperatorEqEq(this, _rhs); }

#if 0
	void ClearDirty();
	void UpdateHoldDuration(EActionInputDevice _arg0_);
	const string& GetActionMap() const;
	CCryName GetActionId() const;
	bool IsEnabled() const;
	bool IsHold() const;
	const wstring& GetPromptText() const;
	const Functor0& GetCallback() const;
	void UpdateInputPromptString(EActionInputDevice _arg0_);
#endif

	static inline auto FArkButtonPromptOv2 = PreyFunction<void(ArkButtonPrompt* const _this)>(0x14336A0);
	static inline auto FClear = PreyFunction<void(ArkButtonPrompt* const _this)>(0x1433910);
	static inline auto FClearPromptText = PreyFunction<void(ArkButtonPrompt* const _this)>(0x1433B00);
	static inline auto FSetValuesOv2 = PreyFunction<void(ArkButtonPrompt* const _this, CCryName _actionId, const string& _actionMap, const string& _promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration, Functor0 _callback)>(0x1433F20);
	static inline auto FSetValuesOv1 = PreyFunction<void(ArkButtonPrompt* const _this, CCryName _actionId, const string& _actionMap, const wstring& _promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration, Functor0 _callback)>(0x1434040);
	static inline auto FSetValuesOv0 = PreyFunction<void(ArkButtonPrompt* const _this, const wstring& _promptText, bool _bEnabled, bool _bUseHoldTriggerDelay, float _holdDuration, Functor0 _callback)>(0x1433EA0);
	static inline auto FSetInput = PreyFunction<void(ArkButtonPrompt* const _this, CCryName _actionId, const string& _actionMap)>(0x1433DF0);
	static inline auto FProcessInput = PreyFunction<void(ArkButtonPrompt* const _this, const CCryName& _actionId, const int _activationMode, const float _value)>(0x1433D70);
	static inline auto FUpdate = PreyFunction<bool(ArkButtonPrompt* const _this, float _frameTime)>(0x1434260);
	static inline auto FCallActionscript = PreyFunction<void(ArkButtonPrompt* const _this, IUIElement* _pUIElement, int _index, const string& _setFunction)>(0x1433790);
	static inline auto FCallNonHoldActionscript = PreyFunction<void(ArkButtonPrompt* const _this, IUIElement* _pUIElement, int _index, const string& _setFunction)>(0x1433880);
	static inline auto FPopulateArguments = PreyFunction<void(ArkButtonPrompt* const _this, SUIArguments& _args)>(0x1433CE0);
	static inline auto FIsVisible = PreyFunction<bool(const ArkButtonPrompt* const _this)>(0x1433B60);
	static inline auto FOnInputDeviceChanged = PreyFunction<void(ArkButtonPrompt* const _this, EActionInputDevice _inputDevice)>(0x1433B70);
	static inline auto FOnOptionMenuClosed = PreyFunction<void(ArkButtonPrompt* const _this)>(0x1433C20);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkButtonPrompt* const _this, const ArkButtonPrompt& _rhs)>(0x1433710);
};
#endif // !MOONCRASH
