// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/GameDll/ark/ScriptHandle.h>

struct IFunctionHandler;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_arkkiosk.h
class CScriptBind_ArkKiosk : public CScriptableBase // Id=8016641 Size=96
{
public:
	CScriptBind_ArkKiosk();
	int SetKioskPowered(IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered) { return FSetKioskPowered(this,_pH,_entityId,_bPowered); }
	int SetKioskButtonHeader(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_header) { return FSetKioskButtonHeader(this,_pH,_entityId,_button,_header); }
	int SetKioskButtonBody(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_body) { return FSetKioskButtonBody(this,_pH,_entityId,_button,_body); }
	int SetKioskButtonState(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, int _state) { return FSetKioskButtonState(this,_pH,_entityId,_button,_state); }
	int SetKioskButtonVisible(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, bool _bVisible) { return FSetKioskButtonVisible(this,_pH,_entityId,_button,_bVisible); }
	int SetKioskHeader(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_header) { return FSetKioskHeader(this,_pH,_entityId,_header); }
	int SetKioskBody(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_body) { return FSetKioskBody(this,_pH,_entityId,_body); }
	int SetMultipleChoiceQuestion(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_question) { return FSetMultipleChoiceQuestion(this,_pH,_entityId,_question); }
	int SetMultipleChoiceAnswer(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_id, const char *_answer) { return FSetMultipleChoiceAnswer(this,_pH,_entityId,_id,_answer); }
	int DisplayMultipleChoiceRorschach(IFunctionHandler *_pH, ScriptHandle _entityId) { return FDisplayMultipleChoiceRorschach(this,_pH,_entityId); }
	int DisplayMultipleChoiceQuestion(IFunctionHandler *_pH, ScriptHandle _entityId) { return FDisplayMultipleChoiceQuestion(this,_pH,_entityId); }
	int DisplayMultipleChoiceLogo(IFunctionHandler *_pH, ScriptHandle _entityId) { return FDisplayMultipleChoiceLogo(this,_pH,_entityId); }
	int DisplayMultipleChoiceStart(IFunctionHandler *_pH, ScriptHandle _entityId) { return FDisplayMultipleChoiceStart(this,_pH,_entityId); }
	int SetElevatorCurrentFloor(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text) { return FSetElevatorCurrentFloor(this,_pH,_entityId,_text); }
	int SetElevatorDefaultText(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text) { return FSetElevatorDefaultText(this,_pH,_entityId,_text); }
	int SetElevatorFailText(IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text) { return FSetElevatorFailText(this,_pH,_entityId,_text); }
	int SetElevatorButtonFloor(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_text) { return FSetElevatorButtonFloor(this,_pH,_entityId,_button,_text); }
	int SetElevatorButtonSecondary(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_text) { return FSetElevatorButtonSecondary(this,_pH,_entityId,_button,_text); }
	int SetElevatorButtonVisible(IFunctionHandler *_pH, ScriptHandle _entityId, int _button, bool _bVisible) { return FSetElevatorButtonVisible(this,_pH,_entityId,_button,_bVisible); }
	int SetElevatorStateDefault(IFunctionHandler *_pH, ScriptHandle _entityId) { return FSetElevatorStateDefault(this,_pH,_entityId); }
	int SetElevatorStateProcessing(IFunctionHandler *_pH, ScriptHandle _entityId) { return FSetElevatorStateProcessing(this,_pH,_entityId); }
	int SetElevatorStateFail(IFunctionHandler *_pH, ScriptHandle _entityId) { return FSetElevatorStateFail(this,_pH,_entityId); }
	
	static inline auto FSetKioskPowered = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, bool _bPowered)>(0x1335CF0);
	static inline auto FSetKioskButtonHeader = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_header)>(0x1335A80);
	static inline auto FSetKioskButtonBody = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_body)>(0x1335990);
	static inline auto FSetKioskButtonState = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, int _state)>(0x1335B70);
	static inline auto FSetKioskButtonVisible = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, bool _bVisible)>(0x1335BC0);
	static inline auto FSetKioskHeader = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_header)>(0x1335C10);
	static inline auto FSetKioskBody = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_body)>(0x13358B0);
	static inline auto FSetMultipleChoiceQuestion = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_question)>(0x1335EC0);
	static inline auto FSetMultipleChoiceAnswer = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_id, const char *_answer)>(0x1335E70);
	static inline auto FDisplayMultipleChoiceRorschach = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1334FB0);
	static inline auto FDisplayMultipleChoiceQuestion = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1334F80);
	static inline auto FDisplayMultipleChoiceLogo = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1334F50);
	static inline auto FDisplayMultipleChoiceStart = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1334FE0);
	static inline auto FSetElevatorCurrentFloor = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text)>(0x1335560);
	static inline auto FSetElevatorDefaultText = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text)>(0x1335640);
	static inline auto FSetElevatorFailText = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, const char *_text)>(0x1335720);
	static inline auto FSetElevatorButtonFloor = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_text)>(0x1335330);
	static inline auto FSetElevatorButtonSecondary = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, const char *_text)>(0x1335420);
	static inline auto FSetElevatorButtonVisible = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId, int _button, bool _bVisible)>(0x1335510);
	static inline auto FSetElevatorStateDefault = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1335800);
	static inline auto FSetElevatorStateProcessing = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1335870);
	static inline auto FSetElevatorStateFail = PreyFunction<int(CScriptBind_ArkKiosk *const _this, IFunctionHandler *_pH, ScriptHandle _entityId)>(0x1335830);
};

