// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryName.h>

struct IUIElement;
struct SActionInput;

// Header: Exact
// Prey/GameDll/ark/ui/arkuiutil.h
class UIUtil // Id=80175FB Size=1
{
public:
	static void CallUIFunction0P0R(IUIElement *const _pElement, const char *const _pFunctionName) { FCallUIFunction0P0R(_pElement,_pFunctionName); }
	static void StringTokenReplace(wstring &_input, wstring const &_key, wstring const &_replaceValue) { FStringTokenReplace(_input,_key,_replaceValue); }
	static wstring FormatLocStringWithString(const char *const _locKey, const char *const _subString) { return FFormatLocStringWithString(_locKey,_subString); }
	static wstring FormatLocStringWithStrings(const char *const _locKey, const char *const _subString1, const char *const _subString2) { return FFormatLocStringWithStrings(_locKey,_subString1,_subString2); }
	static wstring FormatLabelWithDistance(const char *const _label, const float _distance) { return FFormatLabelWithDistanceOv1(_label,_distance); }
	static wstring FormatLabelWithDistance(const wchar_t *const _label, const float _distance) { return FFormatLabelWithDistanceOv0(_label,_distance); }
	static const char *GetKeyNameForAction(CCryName _actionId, const char *_actionMap, EActionInputDevice _inputDevice) { return FGetKeyNameForAction(_actionId,_actionMap,_inputDevice); }
	static SActionInput const *GetActionInput(CCryName _actionId, const char *_actionMap, EActionInputDevice _inputDevice) { return FGetActionInput(_actionId,_actionMap,_inputDevice); }
	static EActionInputDevice GetInputDeviceFromControlScheme(EControlScheme _controlScheme) { return FGetInputDeviceFromControlScheme(_controlScheme); }
	static wstring FormatStringWithActionImages(string const &_label, CCryName _contextualAction, string const &_contextualActionMap) { return FFormatStringWithActionImages(_label,_contextualAction,_contextualActionMap); }
	static void MakeStringNarrow(wstring const &_wide, string &_narrow) { FMakeStringNarrow(_wide,_narrow); }
	static void MakeStringWide(string const &_narrow, wstring &_wide) { FMakeStringWide(_narrow,_wide); }
	static wstring ConvertActionNameToDisplayString(CCryName const &_action, const char *const _actionMap) { return FConvertActionNameToDisplayString(_action,_actionMap); }
	static wstring GetStringForInputPrompt(CCryName const &_action, const char *const _actionMap, EActionInputDevice _inputDevice) { return FGetStringForInputPrompt(_action,_actionMap,_inputDevice); }
	static string GetInputImagePath(const char *const _keyname, EActionInputDevice _inputDevice) { return FGetInputImagePathOv1(_keyname,_inputDevice); }
	static string GetInputImagePath(CCryName _actionId, const char *_actionMap, EActionInputDevice _inputDevice) { return FGetInputImagePathOv0(_actionId,_actionMap,_inputDevice); }
	static wstring GetIconHTMLForKeyname(const char *const _keyname, const int _vspace) { return FGetIconHTMLForKeyname(_keyname,_vspace); }
	static wstring GetLocalizedStringForKeyname(const char *const _keyname) { return FGetLocalizedStringForKeyname(_keyname); }
	static void FormatStringWithGameTokens(wstring &_input) { FFormatStringWithGameTokens(_input); }
	
	static inline auto FCallUIFunction0P0R = PreyFunction<void(IUIElement *const _pElement, const char *const _pFunctionName)>(0x1162B70);
	static inline auto FStringTokenReplace = PreyFunction<void(wstring &_input, wstring const &_key, wstring const &_replaceValue)>(0x10B6D00);
	static inline auto FFormatLocStringWithString = PreyFunction<wstring(const char *const _locKey, const char *const _subString)>(0x11A62E0);
	static inline auto FFormatLocStringWithStrings = PreyFunction<wstring(const char *const _locKey, const char *const _subString1, const char *const _subString2)>(0x163DE60);
	static inline auto FFormatLabelWithDistanceOv1 = PreyFunction<wstring(const char *const _label, const float _distance)>(0x1640280);
	static inline auto FFormatLabelWithDistanceOv0 = PreyFunction<wstring(const wchar_t *const _label, const float _distance)>(0x1640360);
	static inline auto FGetKeyNameForAction = PreyFunction<const char *(CCryName _actionId, const char *_actionMap, EActionInputDevice _inputDevice)>(0x1641490);
	static inline auto FGetActionInput = PreyFunction<SActionInput const *(CCryName _actionId, const char *_actionMap, EActionInputDevice _inputDevice)>(0x1640F80);
	static inline auto FGetInputDeviceFromControlScheme = PreyFunction<EActionInputDevice(EControlScheme _controlScheme)>(0x1641270);
	static inline auto FFormatStringWithActionImages = PreyFunction<wstring(string const &_label, CCryName _contextualAction, string const &_contextualActionMap)>(0x16403E0);
	static inline auto FMakeStringNarrow = PreyFunction<void(wstring const &_wide, string &_narrow)>(0x1641AA0);
	static inline auto FMakeStringWide = PreyFunction<void(string const &_narrow, wstring &_wide)>(0x1641AF0);
	static inline auto FConvertActionNameToDisplayString = PreyFunction<wstring(CCryName const &_action, const char *const _actionMap)>(0x16400A0);
	static inline auto FGetStringForInputPrompt = PreyFunction<wstring(CCryName const &_action, const char *const _actionMap, EActionInputDevice _inputDevice)>(0x16417B0);
	static inline auto FGetInputImagePathOv1 = PreyFunction<string(const char *const _keyname, EActionInputDevice _inputDevice)>(0x16412B0);
	static inline auto FGetInputImagePathOv0 = PreyFunction<string(CCryName _actionId, const char *_actionMap, EActionInputDevice _inputDevice)>(0x16413D0);
	static inline auto FGetIconHTMLForKeyname = PreyFunction<wstring(const char *const _keyname, const int _vspace)>(0x16410B0);
	static inline auto FGetLocalizedStringForKeyname = PreyFunction<wstring(const char *const _keyname)>(0x1641600);
	static inline auto FFormatStringWithGameTokens = PreyFunction<void(wstring &_input)>(0x1640BB0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>

class CCryName;
enum EActionInputDevice;
enum EControlScheme;
struct IUIElement;
struct SActionInput;

// UIUtil
// Header:  Prey/GameDll/ark/ui/arkuiutil.h
class UIUtil
{ // Size=1 (0x1)
public:
	static void CallUIFunction0P0R(IUIElement* const _pElement, const char* const _pFunctionName) { FCallUIFunction0P0R(_pElement, _pFunctionName); }
	static void StringTokenReplace(wstring& _input, const wstring& _key, const wstring& _replaceValue) { FStringTokenReplace(_input, _key, _replaceValue); }
	static wstring FormatLocStringWithString(const char* const _locKey, const char* const _subString) { return FFormatLocStringWithString(_locKey, _subString); }
	static wstring FormatLocStringWithStrings(const char* const _locKey, const char* const _subString1, const char* const _subString2) { return FFormatLocStringWithStrings(_locKey, _subString1, _subString2); }
	static wstring FormatLabelWithDistance(const char* const _label, const float _distance) { return FFormatLabelWithDistanceOv1(_label, _distance); }
	static wstring FormatLabelWithDistance(const wchar_t* const _label, const float _distance) { return FFormatLabelWithDistanceOv0(_label, _distance); }
	static const char* GetKeyNameForAction(const CCryName _actionId, const char* _actionMap, EActionInputDevice _inputDevice) { return FGetKeyNameForAction(_actionId, _actionMap, _inputDevice); }
	static const SActionInput* GetActionInput(const CCryName _actionId, const char* _actionMap, EActionInputDevice _inputDevice) { return FGetActionInput(_actionId, _actionMap, _inputDevice); }
	static EActionInputDevice GetInputDeviceFromControlScheme(const EControlScheme _controlScheme) { return FGetInputDeviceFromControlScheme(_controlScheme); }
	static wstring FormatStringWithActionImages(const string& _label, CCryName _contextualAction, const string& _contextualActionMap) { return FFormatStringWithActionImagesOv1(_label, _contextualAction, _contextualActionMap); }
	static wstring FormatStringWithActionImages(const char* _label, CCryName _contextualAction, const string& _contextualActionMap) { return FFormatStringWithActionImagesOv0(_label, _contextualAction, _contextualActionMap); }
	static void MakeStringNarrow(const wstring& _wide, string& _narrow) { FMakeStringNarrow(_wide, _narrow); }
	static void MakeStringWide(const string& _narrow, wstring& _wide) { FMakeStringWide(_narrow, _wide); }
	static wstring ConvertActionNameToDisplayString(const CCryName& _action, const char* const _actionMap) { return FConvertActionNameToDisplayString(_action, _actionMap); }
	static wstring GetStringForInputPrompt(const CCryName& _action, const char* const _actionMap, EActionInputDevice _inputDevice) { return FGetStringForInputPrompt(_action, _actionMap, _inputDevice); }
	static string GetInputImagePath(const char* const _keyname, EActionInputDevice _inputDevice) { return FGetInputImagePathOv1(_keyname, _inputDevice); }
	static string GetInputImagePath(const CCryName _actionId, const char* _actionMap, EActionInputDevice _inputDevice) { return FGetInputImagePathOv0(_actionId, _actionMap, _inputDevice); }
	static wstring GetIconHTMLForKeyname(const char* const _keyname, const int _vspace) { return FGetIconHTMLForKeyname(_keyname, _vspace); }
	static wstring GetLocalizedStringForKeyname(const char* const _keyname) { return FGetLocalizedStringForKeyname(_keyname); }
	static void FormatStringWithGameTokens(wstring& _input) { FFormatStringWithGameTokens(_input); }

	static inline auto FCallUIFunction0P0R = PreyFunction<void(IUIElement* const _pElement, const char* const _pFunctionName)>(0x11B05B0);
	static inline auto FStringTokenReplace = PreyFunction<void(wstring& _input, const wstring& _key, const wstring& _replaceValue)>(0x10E5B60);
	static inline auto FFormatLocStringWithString = PreyFunction<wstring(const char* const _locKey, const char* const _subString)>(0x11EB7F0);
	static inline auto FFormatLocStringWithStrings = PreyFunction<wstring(const char* const _locKey, const char* const _subString1, const char* const _subString2)>(0x17617B0);
	static inline auto FFormatLabelWithDistanceOv1 = PreyFunction<wstring(const char* const _label, const float _distance)>(0x1763D10);
	static inline auto FFormatLabelWithDistanceOv0 = PreyFunction<wstring(const wchar_t* const _label, const float _distance)>(0x1763DF0);
	static inline auto FGetKeyNameForAction = PreyFunction<const char* (const CCryName _actionId, const char* _actionMap, EActionInputDevice _inputDevice)>(0x1764F80);
	static inline auto FGetActionInput = PreyFunction<const SActionInput* (const CCryName _actionId, const char* _actionMap, EActionInputDevice _inputDevice)>(0x1764A70);
	static inline auto FGetInputDeviceFromControlScheme = PreyFunction<EActionInputDevice(const EControlScheme _controlScheme)>(0x1764D60);
	static inline auto FFormatStringWithActionImagesOv1 = PreyFunction<wstring(const string& _label, CCryName _contextualAction, const string& _contextualActionMap)>(0x1763E70);
	static inline auto FFormatStringWithActionImagesOv0 = PreyFunction<wstring(const char* _label, CCryName _contextualAction, const string& _contextualActionMap)>(0x1763ED0);
	static inline auto FMakeStringNarrow = PreyFunction<void(const wstring& _wide, string& _narrow)>(0x1765590);
	static inline auto FMakeStringWide = PreyFunction<void(const string& _narrow, wstring& _wide)>(0x17655E0);
	static inline auto FConvertActionNameToDisplayString = PreyFunction<wstring(const CCryName& _action, const char* const _actionMap)>(0x1763B30);
	static inline auto FGetStringForInputPrompt = PreyFunction<wstring(const CCryName& _action, const char* const _actionMap, EActionInputDevice _inputDevice)>(0x17652A0);
	static inline auto FGetInputImagePathOv1 = PreyFunction<string(const char* const _keyname, EActionInputDevice _inputDevice)>(0x1764DA0);
	static inline auto FGetInputImagePathOv0 = PreyFunction<string(const CCryName _actionId, const char* _actionMap, EActionInputDevice _inputDevice)>(0x1764EC0);
	static inline auto FGetIconHTMLForKeyname = PreyFunction<wstring(const char* const _keyname, const int _vspace)>(0x1764BA0);
	static inline auto FGetLocalizedStringForKeyname = PreyFunction<wstring(const char* const _keyname)>(0x17650F0);
	static inline auto FFormatStringWithGameTokens = PreyFunction<void(wstring& _input)>(0x17646A0);
};
#endif // !MOONCRASH
