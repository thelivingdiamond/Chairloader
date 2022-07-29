// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAction/IActionMapManager.h>
#include <Prey/CryNetwork/ISerialize.h>

class ArkPlayer;
class CCryName;
struct IGameObject;
struct SActionMapEvent;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/player/ArkPlayerInput.h
class ArkPlayerInput : public IActionListener, public IActionMapEventListener // Id=8017412 Size=208
{
public:
	enum class Mode
	{
		player = 0,
		world_ui_examination = 1,
		examination = 2,
		menu = 3,
		flycam = 4,
		focusmode = 5,
		ether_duplicate = 6,
		hacking = 7,
		psi_scanning_fanfare = 8,
		mimic_grab = 9,
		_count = 10,
	};

	enum class CinematicMode
	{
		off = 0,
		allowLook = 1,
		complete = 2,
	};

	static int s_handleGenerator;
	
	struct ModeAndHandle // Id=8017413 Size=8
	{
		ArkPlayerInput::Mode m_mode;
		int m_handle;
		
#if 0
		bool operator==(ArkPlayerInput::ModeAndHandle const &arg0);
#endif
	};

	std::vector<ArkPlayerInput::ModeAndHandle> m_modeStack;
	TActionHandler<ArkPlayerInput> m_actionHandler;
	Ang3 m_deltaRotation;
	Ang3 m_gamePadRotation;
	Ang3 m_adjustedGamePadRotation;
	Vec2 m_movement;
	Vec2 m_reticleMovement;
	
	struct MovementButtonPressInfo // Id=8017449 Size=4
	{
		bool bForward;
		bool bBack;
		bool bLeft;
		bool bRight;
	};

	ArkPlayerInput::MovementButtonPressInfo m_movementButtonPressInfo;
	ArkPlayer &m_player;
	float m_debugTimeScale;
	float m_lean;
	float m_rawLean;
	float m_lastRegisteredInputTime;
	float m_currentGamePadRotationSpeed;
	int m_mashesRemaining;
	int m_mimicGrabMashesRequired;
	ArkPlayerInput::CinematicMode m_cinematicMode;
	float m_sprintCameraRotationRateScale;
	float m_zoomCameraRotationRateScale;
	float m_sprintCancelForwardThreshold;
	float m_sprintCancelBackwardThreshold;
	float m_sprintCancelStrafeThreshold;
	bool m_bSprint;
	bool m_bUseHeld;
	bool m_bTriggeredUse;
	bool m_bTriggeredHoldUse;
	bool m_bTriggeredSpecialUse;
	bool m_bZeroGBraking;
	bool m_bSprintInhibited;
	bool m_bJumpInhibited;
	bool m_bRotationInhibited;
	bool m_bLeftLean;
	bool m_bRightLean;
	float m_deadzone;
	float m_curvePercentTurnSpeed;
	float m_accelerationThreshold;
	float m_accelerationRate;
	float m_accelerationMaxTurnSpeed;
	ArkPlayerInput::Mode m_disabledMode;
	
	ArkPlayerInput(ArkPlayer &_player);
	virtual ~ArkPlayerInput();
	bool OnActionMoveForward(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionMoveForward(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionMoveBack(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionMoveBack(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionMoveLeft(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionMoveLeft(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionMoveRight(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionMoveRight(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionRotateYaw(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionRotateYaw(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionRotatePitch(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionRotatePitch(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionJump(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionJump(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionSneak(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionSneak(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionSprint(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionSprint(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadMoveX(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadMoveX(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadMoveY(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadMoveY(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadMoveReticleX(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadMoveReticleX(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadMoveReticleY(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadMoveReticleY(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadRotateYaw(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadRotateYaw(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadRotatePitch(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadRotatePitch(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionUse(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionLoot(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionLoot(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionSpecialUse(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionSpecialUse(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionViewTutorial(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionViewTutorial(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionLeanLeft(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionLeanLeft(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionLeanRight(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionLeanRight(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleScope(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleScope(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleInventory(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleInventory(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleObjectives(unsigned _entityId, CCryName const &_rActionId, int _activationMode, float _fValue) { return FOnActionToggleObjectives(this,_entityId,_rActionId,_activationMode,_fValue); }
	bool OnActionToggleAbilities(unsigned _entityId, CCryName const &_rActionId, int _activationMode, float _fValue) { return FOnActionToggleAbilities(this,_entityId,_rActionId,_activationMode,_fValue); }
	bool OnActionTogglePDA(unsigned _entityId, CCryName const &_rActionId, int _activationMode, float _fValue) { return FOnActionTogglePDA(this,_entityId,_rActionId,_activationMode,_fValue); }
	bool OnActionToggleMap(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleMap(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleData(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleData(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleStatus(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleStatus(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionAttackPrimary(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionAttackPrimary(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionReload(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionReload(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionFlyMode(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionFlyMode(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionWorldUIExamine(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionWorldUIExamine(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleArkProfile(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleArkProfile(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionTogglePDrawHelpers(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionTogglePDrawHelpers(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionIncreaseTimeDilation(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionIncreaseTimeDilation(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionDecreaseTimeDilation(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionDecreaseTimeDilation(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionNormalTimeDilation(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionNormalTimeDilation(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionGamePadRecenterWorldUI(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionGamePadRecenterWorldUI(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionExaminationBack(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionExaminationBack(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionToggleFlashlight(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionToggleFlashlight(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionInstakill(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionInstakill(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionThirdPerson(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionThirdPerson(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionQuickSave(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionQuickSave(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionLoadLastSave(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionLoadLastSave(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionPlayAudioLog(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionPlayAudioLog(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionKeypad(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionKeypad(this,_entityId,_actionId,_activationMode,_value); }
	bool OnActionEquipLastWeapon(unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value) { return FOnActionEquipLastWeapon(this,_entityId,_actionId,_activationMode,_value); }
	Vec2 GetMovement() const { return FGetMovement(this); }
	void ClearMovement() { FClearMovement(this); }
	Ang3 GetRotation(const float _frameTime) const { return FGetRotation(this,_frameTime); }
	void HandleGamepadCameraAcceleration(float _frameTime) { FHandleGamepadCameraAcceleration(this,_frameTime); }
	bool IsRotating() const { return FIsRotating(this); }
	void Init(IGameObject &_gameObject) { FInit(this,_gameObject); }
	void LoadConfig(XmlNodeRef const &_node) { FLoadConfig(this,_node); }
	void ProcessSprintInput(const bool _bSprint) { FProcessSprintInput(this,_bSprint); }
	void Reset() { FReset(this); }
	int EnableInputMode(ArkPlayerInput::Mode _mode) { return FEnableInputMode(this,_mode); }
	void DisableInputMode(const int _handle) { FDisableInputMode(this,_handle); }
	void EnablePlayerInputMode(bool _bEnable) { FEnablePlayerInputMode(this,_bEnable); }
	bool DoesCurrentInputModeSupportWeapon() const { return FDoesCurrentInputModeSupportWeapon(this); }
	void SetCinematicMode(ArkPlayerInput::CinematicMode _cinematicMode) { FSetCinematicMode(this,_cinematicMode); }
	void EnableActionMapForMode(ArkPlayerInput::Mode _mode, const bool _bEnable) { FEnableActionMapForMode(this,_mode,_bEnable); }
	virtual void OnActionMapEvent(SActionMapEvent const &_event);
	void SetTimeScale(const float _value) { FSetTimeScale(this,_value); }
	virtual void OnAction(CCryName const &_action, int _activationMode, float _value);
	void ProcessLeanInput() { FProcessLeanInput(this); }
	
#if 0
	float GetLastRegisteredInputTime() const;
	void ClearLean();
	float GetLean() const;
	float GetRawLean() const;
	bool GetSprint() const;
	bool GetSprintWithoutInhibit();
	bool GetZeroGBoost() const;
	Ang3 GetRawMouseRotation() const;
	Vec2 GetRawGamePadRotation() const;
	void ResetDeltaRotation();
	void ClearGamePadRotation();
	bool IsHoldingUse() const;
	bool IsHoldingSpecialUse() const;
	bool IsZeroGBraking() const;
	Vec2 GetReticleMovement() const;
	void EnterMimicGrabSequence();
	bool IsMashesThresholdReached() const;
	void ExitMimicGrabSequence();
	void InhibitSprint(const bool arg0);
	void InhibitJump(const bool arg0);
	void InhibitRotation(const bool arg0);
	ArkPlayerInput::CinematicMode GetCinematicMode() const;
	bool IsMovementWithinSprintCancelThreshold() const;
	void Serialize(TSerialize &arg0);
	bool IsHoldingLeanLeft() const;
	bool IsHoldingLeanRight() const;
	void UpdateReticleUI() const;
	void SetMovementGamePad(float arg0, float &arg1);
	bool FilterLook() const;
	void SetMovementKeyboard(const float arg0, float &arg1, bool &arg2, bool arg3);
#endif
	
	static inline auto FBitNotArkPlayerInput = PreyFunction<void(ArkPlayerInput *const _this)>(0x15615E0);
	static inline auto FOnActionMoveForward = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15636E0);
	static inline auto FOnActionMoveBack = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563680);
	static inline auto FOnActionMoveLeft = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563740);
	static inline auto FOnActionMoveRight = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15637A0);
	static inline auto FOnActionRotateYaw = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563A30);
	static inline auto FOnActionRotatePitch = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15639E0);
	static inline auto FOnActionJump = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563030);
	static inline auto FOnActionSneak = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563A60);
	static inline auto FOnActionSprint = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563B40);
	static inline auto FOnActionGamePadMoveX = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562EB0);
	static inline auto FOnActionGamePadMoveY = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562F10);
	static inline auto FOnActionGamePadMoveReticleX = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562E80);
	static inline auto FOnActionGamePadMoveReticleY = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562E90);
	static inline auto FOnActionGamePadRotateYaw = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562FE0);
	static inline auto FOnActionGamePadRotatePitch = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562FA0);
	static inline auto FOnActionUse = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563F60);
	static inline auto FOnActionLoot = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15634F0);
	static inline auto FOnActionSpecialUse = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563AE0);
	static inline auto FOnActionViewTutorial = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1564160);
	static inline auto FOnActionLeanLeft = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15633E0);
	static inline auto FOnActionLeanRight = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563420);
	static inline auto FOnActionToggleScope = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563E50);
	static inline auto FOnActionToggleInventory = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563D50);
	static inline auto FOnActionToggleObjectives = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_rActionId, int _activationMode, float _fValue)>(0x1563DD0);
	static inline auto FOnActionToggleAbilities = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_rActionId, int _activationMode, float _fValue)>(0x1563C60);
	static inline auto FOnActionTogglePDA = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_rActionId, int _activationMode, float _fValue)>(0x1563E10);
	static inline auto FOnActionToggleMap = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563D90);
	static inline auto FOnActionToggleData = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563CD0);
	static inline auto FOnActionToggleStatus = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563F20);
	static inline auto FOnActionAttackPrimary = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562C00);
	static inline auto FOnActionReload = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15638F0);
	static inline auto FOnActionFlyMode = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562E60);
	static inline auto FOnActionWorldUIExamine = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1564190);
	static inline auto FOnActionToggleArkProfile = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563CA0);
	static inline auto FOnActionTogglePDrawHelpers = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0xDD23F0);
	static inline auto FOnActionIncreaseTimeDilation = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563010);
	static inline auto FOnActionDecreaseTimeDilation = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562D70);
	static inline auto FOnActionNormalTimeDilation = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563800);
	static inline auto FOnActionGamePadRecenterWorldUI = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562F70);
	static inline auto FOnActionExaminationBack = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562DF0);
	static inline auto FOnActionToggleFlashlight = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563D10);
	static inline auto FOnActionInstakill = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0xDD23F0);
	static inline auto FOnActionThirdPerson = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563BC0);
	static inline auto FOnActionQuickSave = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15638A0);
	static inline auto FOnActionLoadLastSave = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563460);
	static inline auto FOnActionPlayAudioLog = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1563870);
	static inline auto FOnActionKeypad = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x15630B0);
	static inline auto FOnActionEquipLastWeapon = PreyFunction<bool(ArkPlayerInput *const _this, unsigned _entityId, CCryName const &_actionId, int _activationMode, float _value)>(0x1562D90);
	static inline auto FGetMovement = PreyFunction<Vec2(ArkPlayerInput const *const _this)>(0x1562500);
	static inline auto FClearMovement = PreyFunction<void(ArkPlayerInput *const _this)>(0x1561F70);
	static inline auto FGetRotation = PreyFunction<Ang3(ArkPlayerInput const *const _this, const float _frameTime)>(0x1562600);
	static inline auto FHandleGamepadCameraAcceleration = PreyFunction<void(ArkPlayerInput *const _this, float _frameTime)>(0x1562740);
	static inline auto FIsRotating = PreyFunction<bool(ArkPlayerInput const *const _this)>(0x15628B0);
	static inline auto FInit = PreyFunction<void(ArkPlayerInput *const _this, IGameObject &_gameObject)>(0x1562890);
	static inline auto FLoadConfig = PreyFunction<void(ArkPlayerInput *const _this, XmlNodeRef const &_node)>(0x1562920);
	static inline auto FProcessSprintInput = PreyFunction<void(ArkPlayerInput *const _this, const bool _bSprint)>(0x15642B0);
	static inline auto FReset = PreyFunction<void(ArkPlayerInput *const _this)>(0x1564300);
	static inline auto FEnableInputMode = PreyFunction<int(ArkPlayerInput *const _this, ArkPlayerInput::Mode _mode)>(0x1562260);
	static inline auto FDisableInputMode = PreyFunction<void(ArkPlayerInput *const _this, const int _handle)>(0x1561F80);
	static inline auto FEnablePlayerInputMode = PreyFunction<void(ArkPlayerInput *const _this, bool _bEnable)>(0x15622E0);
	static inline auto FDoesCurrentInputModeSupportWeapon = PreyFunction<bool(ArkPlayerInput const *const _this)>(0x1562040);
	static inline auto FSetCinematicMode = PreyFunction<void(ArkPlayerInput *const _this, ArkPlayerInput::CinematicMode _cinematicMode)>(0x1564410);
	static inline auto FEnableActionMapForMode = PreyFunction<void(ArkPlayerInput *const _this, ArkPlayerInput::Mode _mode, const bool _bEnable)>(0x1562050);
	static inline auto FOnActionMapEvent = PreyFunction<void(ArkPlayerInput *const _this, SActionMapEvent const &_event)>(0x1563520);
	static inline auto FSetTimeScale = PreyFunction<void(ArkPlayerInput *const _this, const float _value)>(0x15644D0);
	static inline auto FOnAction = PreyFunction<void(ArkPlayerInput *const _this, CCryName const &_action, int _activationMode, float _value)>(0x1562AA0);
	static inline auto FProcessLeanInput = PreyFunction<void(ArkPlayerInput *const _this)>(0x1564240);
};

