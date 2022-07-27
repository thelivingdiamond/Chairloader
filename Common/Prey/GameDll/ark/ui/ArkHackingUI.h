// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/functor.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryString/CryName.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/ArkExaminationMode.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <_unknown/ArkUIMenuBase_ArkHackingUI_.h>

struct IConsoleCmdArgs;
struct IEntity;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkHackingUI.h
class ArkHackingUI : public ArkUIMenuBase<ArkHackingUI>, public ISystemEventListener, public IUIControlSchemeListener // Id=801670F Size=536
{
public:
	using HackingCallback = Functor1<bool>;
	
	struct SKeyInputPressed // Id=8016730 Size=4
	{
		bool left;
		bool right;
		bool up;
		bool down;
		
#if 0
		void Reset();
#endif
	};

	Functor1<bool> m_callback;
	Vec2 m_gamepadMovementInput;
	Vec2 m_keyboardMovementInput;
	ArkHackingUI::SKeyInputPressed m_keyboardInputPressed;
	bool m_bInCircle;
	bool m_bFailed;
	bool m_bQueueHide;
	CCryName m_requiredButton;
	Vec2 m_promptPos;
	Vec2 m_promptVel;
	ArkTimeRemaining m_timeRemaining;
	ArkTimeRemaining m_puzzleTimeRemaining;
	int m_currentNode;
	unsigned m_entityToHack;
	unsigned m_currentDifficulty;
	int m_numCirclesDrawn;
	float m_aspectRatio;
	int m_inputHandle;
	int m_timeScaleHandle;
	std::array<CCryName,4> m_finalButtons;
	unsigned m_examinedWorldUI;
	ArkExaminationMode::ExamineMode m_examineMode;
	int m_nCollisions;
	ArkSimpleTimer m_stunTimer;
	
	enum class HackingCircleState
	{
		Off = 0,
		Inactive = 1,
		Upcoming = 2,
		Active = 3,
		Completed = 4,
	};

	class HackingCircle // Id=8016736 Size=8
	{
	public:
		float m_radius;
		ArkHackingUI::HackingCircleState m_state;
	};

	std::vector<ArkHackingUI::HackingCircle> m_circles;
	
	struct ObstacleSpawnDesc // Id=8016749 Size=20
	{
		unsigned minWidth;
		unsigned maxWidth;
		unsigned minHeight;
		unsigned maxHeight;
		unsigned count;
	};

	struct Obstacle // Id=801674A Size=20
	{
		Vec2 min;
		Vec2 max;
		bool bSuperStun;
		
#if 0
		void Randomize(Vec2 arg0, ArkHackingUI::ObstacleSpawnDesc const &arg1, float arg2, float arg3);
		void Randomize(ArkHackingUI::ObstacleSpawnDesc const &arg0, float arg1, float arg2);
		Lineseg_tpl<float> GetSide(unsigned arg0, float arg1, float arg2) const;
		Vec2 GetNormal(unsigned arg0) const;
		static Vec2i GetRandomSize(ArkHackingUI::ObstacleSpawnDesc const &arg0);
		void Serialize(TSerialize arg0);
#endif
	};

	enum class HackingState
	{
		inactive = 0,
		bootup = 1,
		initializing = 2,
		phaseIn = 3,
		presentCursor = 4,
		hacking = 5,
		result = 6,
		closing = 7,
		failSignal = 8,
	};

	ArkHackingUI::HackingState m_state;
	
	struct HackingDifficultyLevel // Id=801674B Size=24
	{
		float m_minTravelDistance;
		float m_maxTravelDistance;
		float m_timePerPuzzle;
		int m_chainLength;
		uint8_t m_minObstacles;
		uint8_t m_maxObstacles;
		uint8_t m_pathObstacles;
		uint8_t m_pathStunObstacles;
		uint8_t m_otherStunObstacles;
	};

	class ArkHackingPuzzle // Id=801674C Size=56
	{
	public:
		Vec2 m_startPos;
		std::vector<Vec2> m_targets;
		std::vector<ArkHackingUI::Obstacle> m_obstacles;
		
		void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
		
#if 0
		std::vector<ArkHackingUI::Obstacle> const &GetObstacles() const;
		std::vector<ArkHackingUI::Obstacle> &GetObstacles();
		std::vector<Vec2> const &GetTargets() const;
		std::vector<Vec2> &GetTargets();
		Vec2 const &GetStartPos() const;
		void Reset();
		unsigned GetChainLength() const;
#endif
		
		static inline auto FSerialize = PreyFunction<void(ArkHackingUI::ArkHackingPuzzle *const _this, TSerialize _ser)>(0x15FA540);
	};

	std::vector<unsigned __int64> m_hackingAbilities;
	std::vector<ArkHackingUI::HackingDifficultyLevel> m_difficultyLevels;
	std::vector<ArkHackingUI::ObstacleSpawnDesc> m_obstacleSpawners;
	std::vector<std::vector<ArkHackingUI::ArkHackingPuzzle>> m_puzzles;
	ArkHackingUI::ArkHackingPuzzle m_generatedPuzzle;
	ArkHackingUI::ArkHackingPuzzle const *m_pCurrentPuzzle;
	float m_timeForInitialization;
	float m_timeForPhaseIn;
	float m_timeForResult;
	float m_cursorPhaseIn;
	float m_failSignalDelay;
	float m_maxVelocity;
	float m_keyboardAcceleration;
	float m_gamepadAcceleration;
	float m_inactiveRadius;
	float m_activeRadius;
	float m_gridStepWidth;
	float m_gridStepHeight;
	float m_cursorFriction;
	float m_targetFriction;
	float m_cursorElasticity;
	float m_stunElasticity;
	float m_obstacleBufferDistance;
	float m_pathObstacleVariance;
	float m_pathObstacleNormalVariance;
	float m_obstacleGridSize;
	float m_stunTime;
	float m_superStunTime;
	float m_collideForce;
	float m_stunForce;
	float m_invalidInputStunForce;
	float m_invalidInputStunTime;
	bool m_bDrawGrid;
	int m_nFailCollisions;
	uint64_t m_failureSignalPackageId;
	uint64_t m_collisionSignalPackageId;
	
	ArkHackingUI();
	virtual ~ArkHackingUI();
	void Init() { FInit(this); }
	void OpenTranscribe(const unsigned _entityToHack, Functor1<bool> _callback) { FOpenTranscribe(this,_entityToHack,_callback); }
	bool AttemptToHack(unsigned _entityToHack, Functor1<bool> _callback, uint64_t _hackingRequirement) { return FAttemptToHack(this,_entityToHack,_callback,_hackingRequirement); }
	void Close(bool _bImmediate) { FClose(this,_bImmediate); }
	bool IsOpen() const { return FIsOpen(this); }
	void PostSerialize() { FPostSerialize(this); }
	void Reset() { FReset(this); }
	void Update() { FUpdate(this); }
	int GetDifficultyLevel(IEntity const *const _pEntity) const { return FGetDifficultyLevelOv1(this,_pEntity); }
	int GetDifficultyLevel(const uint64_t _abilityId) const { return FGetDifficultyLevelOv0(this,_abilityId); }
	int GetPlayerAbilityLevel() const { return FGetPlayerAbilityLevel(this); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _fValue) { FProcessInput(this,_actionId,_activationMode,_fValue); }
	void OnSetAspectRatio(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSetAspectRatio(this,_pSender,_event,_args); }
	void OnBootupComplete(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnBootupComplete(this,_pSender,_event,_args); }
	void OnCloseComplete(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnCloseComplete(this,_pSender,_event,_args); }
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	void TutorialCallbackTriggered() { FTutorialCallbackTriggered(this); }
	void Open(const unsigned _entityToHack, Functor1<bool> _callback) { FOpen(this,_entityToHack,_callback); }
	void ResetLayout() { FResetLayout(this); }
	void GenerateRandomPuzzle() { FGenerateRandomPuzzle(this); }
	void PhaseInStarted(bool _bShowCursor) { FPhaseInStarted(this,_bShowCursor); }
	void PhaseInComplete() { FPhaseInComplete(this); }
	void Success() { FSuccess(this); }
	void Failure(bool _bExpired) { FFailure(this,_bExpired); }
	void SendPlayerSignalPackage(IEntity *_pSourceEntity, uint64_t _packageId) { FSendPlayerSignalPackage(this,_pSourceEntity,_packageId); }
	void LoadConfigFile() { FLoadConfigFile(this); }
	void UpdateUIForCircle(int _circleIndex) { FUpdateUIForCircle(this,_circleIndex); }
	void Close_Internal() { FClose_Internal(this); }
	void SendFailSignal() { FSendFailSignal(this); }
	void UpdatePrompt(bool _bUpdateLabel, bool _bShowCursor) const { FUpdatePrompt(this,_bUpdateLabel,_bShowCursor); }
	static void ReloadXmlCmd(IConsoleCmdArgs *_pArgs) { FReloadXmlCmd(_pArgs); }
	
#if 0
	void TriggerNextNode();
	void CursorPresentation();
	void Enable(bool arg0);
	string GetDefaultPromptString() const;
	static IUIElement *GetUIElement();
#endif
	
	static inline auto FBitNotArkHackingUI = PreyFunction<void(ArkHackingUI *const _this)>(0x15F5680);
	static inline auto FInit = PreyFunction<void(ArkHackingUI *const _this)>(0x15F7C30);
	static inline auto FOpenTranscribe = PreyFunction<void(ArkHackingUI *const _this, const unsigned _entityToHack, Functor1<bool> _callback)>(0x15F92B0);
	static inline auto FAttemptToHack = PreyFunction<bool(ArkHackingUI *const _this, unsigned _entityToHack, Functor1<bool> _callback, uint64_t _hackingRequirement)>(0x15F5C50);
	static inline auto FClose = PreyFunction<void(ArkHackingUI *const _this, bool _bImmediate)>(0x15F6190);
	static inline auto FIsOpen = PreyFunction<bool(ArkHackingUI const *const _this)>(0x15F7E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkHackingUI *const _this)>(0x15F97F0);
	static inline auto FReset = PreyFunction<void(ArkHackingUI *const _this)>(0x15F9DB0);
	static inline auto FUpdate = PreyFunction<void(ArkHackingUI *const _this)>(0x15FA9C0);
	static inline auto FGetDifficultyLevelOv1 = PreyFunction<int(ArkHackingUI const *const _this, IEntity const *const _pEntity)>(0x15F7B20);
	static inline auto FGetDifficultyLevelOv0 = PreyFunction<int(ArkHackingUI const *const _this, const uint64_t _abilityId)>(0x15F7B70);
	static inline auto FGetPlayerAbilityLevel = PreyFunction<int(ArkHackingUI const *const _this)>(0x15F7BB0);
	static inline auto FProcessInput = PreyFunction<void(ArkHackingUI *const _this, CCryName const &_actionId, const int _activationMode, const float _fValue)>(0x15F9820);
	static inline auto FOnSetAspectRatio = PreyFunction<void(ArkHackingUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15F8E30);
	static inline auto FOnBootupComplete = PreyFunction<void(ArkHackingUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15F8DC0);
	static inline auto FOnCloseComplete = PreyFunction<void(ArkHackingUI *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x15F8DD0);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkHackingUI *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0x15F8E50);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkHackingUI *const _this, EControlScheme _controlScheme)>(0x15F8DE0);
	static inline auto FTutorialCallbackTriggered = PreyFunction<void(ArkHackingUI *const _this)>(0x15FA9A0);
	static inline auto FOpen = PreyFunction<void(ArkHackingUI *const _this, const unsigned _entityToHack, Functor1<bool> _callback)>(0x15F8EC0);
	static inline auto FResetLayout = PreyFunction<void(ArkHackingUI *const _this)>(0x15F9DC0);
	static inline auto FGenerateRandomPuzzle = PreyFunction<void(ArkHackingUI *const _this)>(0x15F6860);
	static inline auto FPhaseInStarted = PreyFunction<void(ArkHackingUI *const _this, bool _bShowCursor)>(0x15F94F0);
	static inline auto FPhaseInComplete = PreyFunction<void(ArkHackingUI *const _this)>(0x15F94B0);
	static inline auto FSuccess = PreyFunction<void(ArkHackingUI *const _this)>(0x15FA720);
	static inline auto FFailure = PreyFunction<void(ArkHackingUI *const _this, bool _bExpired)>(0x15F6790);
	static inline auto FSendPlayerSignalPackage = PreyFunction<void(ArkHackingUI *const _this, IEntity *_pSourceEntity, uint64_t _packageId)>(0x15FA330);
	static inline auto FLoadConfigFile = PreyFunction<void(ArkHackingUI *const _this)>(0x15F7EA0);
	static inline auto FUpdateUIForCircle = PreyFunction<void(ArkHackingUI *const _this, int _circleIndex)>(0x15FBCF0);
	static inline auto FClose_Internal = PreyFunction<void(ArkHackingUI *const _this)>(0x15F6370);
	static inline auto FSendFailSignal = PreyFunction<void(ArkHackingUI *const _this)>(0x15FA2E0);
	static inline auto FUpdatePrompt = PreyFunction<void(ArkHackingUI const *const _this, bool _bUpdateLabel, bool _bShowCursor)>(0x15FB870);
	static inline auto FReloadXmlCmd = PreyFunction<void(IConsoleCmdArgs *_pArgs)>(0x15F9D90);
};

