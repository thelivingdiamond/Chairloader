// Header file automatically created from a PDB.

#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/IUIGameEventSystem.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class CCryName;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/GameDll/ark/ui/ArkNoteUI.h
class ArkNoteUI : public IUIControlSchemeListener, public ArkUIMenuBase<ArkNoteUI>, public IUIModule, public IUIGameEventSystem // Id=801910F Size=656
{
public:
	enum class EArkNoteUIState
	{
		closed = 0,
		open = 1,
		closing = 2,
		unload = 3,
	};

	ArkNoteUI::EArkNoteUIState m_uiState;
	int m_inputHandle;
	int m_timeScaleHandle;
	Vec2 m_screenRotate;
	ArkButtonPromptCollection m_inputPrompts;
	
	ArkNoteUI();
	virtual ~ArkNoteUI();
	virtual const char *GetTypeName() const;
	virtual void InitEventSystem();
	virtual void UnloadEventSystem();
	virtual void OnUpdate(float _fDelta);
	void Open(int64_t _noteId) { FOpen(this,_noteId); }
	virtual void Close(bool _bImmediate);
	bool IsOpen() const { return FIsOpen(this); }
	virtual void Reset();
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _fValue) { FProcessInput(this,_actionId,_activationMode,_fValue); }
	virtual void UpdateModule(float _frameDelta);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	void OnRequestClose(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnRequestClose(this,_pSender,_event,_args); }
	void OnCloseCompleted(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnCloseCompleted(this,_pSender,_event,_args); }
	static bool IsNoteUIOpen() { return FIsNoteUIOpen(); }
	void Enable(bool _bEnable) { FEnable(this,_bEnable); }
	virtual void CleanupClose();
	virtual IUIElement *GetUIElement() const;
	
#if 0
	static const char *GetTypeNameS();
#endif
	
	static inline auto FBitNotArkNoteUI = PreyFunction<void(ArkNoteUI *const _this)>(0x1605EE0);
	static inline auto FGetTypeName = PreyFunction<const char *(ArkNoteUI const *const _this)>(0x16068A0);
	static inline auto FInitEventSystem = PreyFunction<void(ArkNoteUI *const _this)>(0x16068D0);
	static inline auto FUnloadEventSystem = PreyFunction<void(ArkNoteUI *const _this)>(0x16070A0);
	static inline auto FOnUpdate = PreyFunction<void(ArkNoteUI *const _this, float _fDelta)>(0x1606AF0);
	static inline auto FOpen = PreyFunction<void(ArkNoteUI *const _this, int64_t _noteId)>(0x1606B40);
	static inline auto FClose = PreyFunction<void(ArkNoteUI *const _this, bool _bImmediate)>(0x1606370);
	static inline auto FIsOpen = PreyFunction<bool(ArkNoteUI const *const _this)>(0x1606980);
	static inline auto FReset = PreyFunction<void(ArkNoteUI *const _this)>(0x1607090);
	static inline auto FProcessInput = PreyFunction<void(ArkNoteUI *const _this, CCryName const &_actionId, const int _activationMode, const float _fValue)>(0x1606DC0);
	static inline auto FUpdateModule = PreyFunction<void(ArkNoteUI *const _this, float _frameDelta)>(0x16070D0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkNoteUI *const _this, EControlScheme _controlScheme)>(0x1606990);
	static inline auto FOnRequestClose = PreyFunction<void(ArkNoteUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x19C2A60);
	static inline auto FOnCloseCompleted = PreyFunction<void(ArkNoteUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x12941A0);
	static inline auto FIsNoteUIOpen = PreyFunction<bool()>(0x1606900);
	static inline auto FEnable = PreyFunction<void(ArkNoteUI *const _this, bool _bEnable)>(0x1606510);
	static inline auto FCleanupClose = PreyFunction<void(ArkNoteUI *const _this)>(0x1606220);
	static inline auto FGetUIElement = PreyFunction<IUIElement *(ArkNoteUI const *const _this)>(0x16068B0);
};

