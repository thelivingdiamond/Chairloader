// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractiveMachine.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkdoor.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ArkOperatorDispenser.h
class ArkOperatorDispenser : public ArkInteractiveMachine, public ArkUIMenuBase<ArkOperatorDispenser>, public IArkConversationListener // Id=8019402 Size=2456
{
public:
	class SpawnedOperator // Id=8019423 Size=8
	{
	public:
		unsigned m_operatorId;
		bool m_bDispensed;
		bool m_bMoving;
		bool m_bExited;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const unsigned arg0) const;
#endif
	};

	ArkMaterialAnimationManager m_materialAnimationManager;
	ArkSpeaker<ArkDialogPlayer> m_speaker;
	EArkDispenserState m_state;
	EArkDispenserError m_error;
	ArkPasswordProtected m_passwordProtected;
	std::vector<ArkOperatorDispenser::SpawnedOperator> m_spawnedOperators;
	float m_materialAnimTime;
	int m_spawningIndex;
	int m_remainingLifetimeOperators;
	int m_overriddenRemainingLifetimeOperators;
	ArkNpcMovementDesire m_movementDesire;
	ArkSimpleTimer m_animDelay;
	unsigned m_fakeOperator;
	int m_currentAnimId;
	ArkAutoResetTimer m_autospawnTimer;
	bool m_bOpening;
	bool m_bLocked;
	bool m_bOverridden;
	QuatT m_spawnLoc;
	AABB m_obstructionTestCoarse;
	OOB m_obstructionTestFine;
	int m_animOpenId;
	int m_animCloseId;
	int m_operatorTypeId;
	string m_fakeOperatorModel;
	uint64_t m_fakeOperatorMaterialAnim;
	int m_fakeOperatorCountdown;
	Vec3 m_operatorTargetOffset;
	Vec3 m_obstructionTestCenter;
	Vec3 m_obstructionTestSize;
	uint64_t m_operatorArchetype;
	string m_animOpenName;
	string m_animCloseName;
	string m_spawnAttachmentName;
	bool m_bStartsUnlocked;
	int m_hackingLevel;
	uint64_t m_dahlHackingRequirement;
	int m_dahlHackingLevel;
	
	ArkOperatorDispenser();
	virtual ~ArkOperatorDispenser();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnWorldUIInstanceGranted(IUIElement *_pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement *_pUIInstance);
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnButtonPress(this,_pSender,_event,_args); }
	void OnPasswordSuccess(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPasswordSuccess(this,_pSender,_event,_args); }
	void ForceSpawn() { FForceSpawn(this); }
	void SetLocked(bool _bLocked, bool _bForce) { FSetLocked(this,_bLocked,_bForce); }
	void OverrideValues(string const &_archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration) { FOverrideValues(this,_archetypeName,_maxConcurrent,_maxLifetime,_autospawnDuration); }
	void ClearOverrides() { FClearOverrides(this); }
	int AssignOperator(const unsigned _operatorId, bool _bDispensed) { return FAssignOperator(this,_operatorId,_bDispensed); }
	void MovementDesireCallback(EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this,_event); }
	void OnHackingFinished(bool _bSuccess) { FOnHackingFinished(this,_bSuccess); }
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void InitCachedPositionData();
	virtual bool IsProcessing() const;
	virtual bool IsInteractive() const;
	void SetState(EArkDispenserState _state, bool _bForce) { FSetState(this,_state,_bForce); }
	void UpdateErrorState() { FUpdateErrorState(this); }
	void SetError(EArkDispenserError _error) { FSetError(this,_error); }
	void RefreshUI(bool _bReinit) { FRefreshUI(this,_bReinit); }
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	bool TriggerSpawn() { return FTriggerSpawn(this); }
	void SpawnFakeOperator() { FSpawnFakeOperator(this); }
	void ClearFakeOperator() { FClearFakeOperator(this); }
	void MoveOperator() { FMoveOperator(this); }
	bool TestForObstruction() const { return FTestForObstruction(this); }
	void PlayAnimation(const int _animId, bool _bHoldLastFrame, const float _startTime) { FPlayAnimation(this,_animId,_bHoldLastFrame,_startTime); }
	void AddSpawnModifiers(unsigned _id) { FAddSpawnModifiers(this,_id); }
	void DestroyGloo() { FDestroyGloo(this); }
	const char *GetErrorString() const { return FGetErrorString(this); }
	void SetOperatorArchetype(uint64_t _archetype) { FSetOperatorArchetype(this,_archetype); }
	virtual void OnEnabledChanged(bool _bForce);
	boost::optional<CryStringT<char> const &> GetOperatorDisplayName() const { return FGetOperatorDisplayName(this); }
	
#if 0
	void ClearSpawnedOperators();
	IEntityArchetype *GetOperatorArchetype() const;
	bool SpawnOperator();
	void InvalidateAnimDelay();
	void RemoveSpawnModifiers(unsigned arg0);
	bool Speak(const char *arg0, IEntityArchetype const *const arg1);
#endif
	
	static inline auto FBitNotArkOperatorDispenser = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A51F0);
	static inline auto FPostInit = PreyFunction<void(ArkOperatorDispenser *const _this, IGameObject *_pGameObject)>(0x11A95C0);
	static inline auto FFullSerialize = PreyFunction<void(ArkOperatorDispenser *const _this, TSerialize _ser)>(0x11A6470);
	static inline auto FPostSerialize = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A96B0);
	static inline auto FUpdate = PreyFunction<void(ArkOperatorDispenser *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x11AAD80);
	static inline auto FProcessEvent = PreyFunction<void(ArkOperatorDispenser *const _this, SEntityEvent &_event)>(0x11A99A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkOperatorDispenser const *const _this, ICrySizer *_s)>(0x11A67E0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkOperatorDispenser *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x11A8D40);
	static inline auto FTestInteraction = PreyFunction<bool(ArkOperatorDispenser const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x11AAB30);
	static inline auto FOnStartLookingAt = PreyFunction<void(ArkOperatorDispenser *const _this, unsigned _targetId)>(0x11A8FC0);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkOperatorDispenser *const _this, IUIElement *_pUIInstance)>(0x11A9170);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkOperatorDispenser *const _this, IUIElement *_pUIInstance)>(0x11A91F0);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(ArkOperatorDispenser const *const _this)>(0x13F8580);
	static inline auto FOnButtonPress = PreyFunction<void(ArkOperatorDispenser *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x11A8360);
	static inline auto FOnPasswordSuccess = PreyFunction<void(ArkOperatorDispenser *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x11A8DC0);
	static inline auto FForceSpawn = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A62A0);
	static inline auto FSetLocked = PreyFunction<void(ArkOperatorDispenser *const _this, bool _bLocked, bool _bForce)>(0x11AA280);
	static inline auto FOverrideValues = PreyFunction<void(ArkOperatorDispenser *const _this, string const &_archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration)>(0x11A9240);
	static inline auto FClearOverrides = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A5CB0);
	static inline auto FAssignOperator = PreyFunction<int(ArkOperatorDispenser *const _this, const unsigned _operatorId, bool _bDispensed)>(0x11A5A70);
	static inline auto FMovementDesireCallback = PreyFunction<void(ArkOperatorDispenser *const _this, EArkNpcMovementDesireCallbackEvent _event)>(0x11A80E0);
	static inline auto FOnHackingFinished = PreyFunction<void(ArkOperatorDispenser *const _this, bool _bSuccess)>(0x11A8CE0);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkOperatorDispenser *const _this, const bool _bComplete)>(0x11A8B20);
	static inline auto FOnReset = PreyFunction<void(ArkOperatorDispenser *const _this, bool _bEnteringGameMode)>(0x11A8E20);
	static inline auto FLoadProperties = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A7250);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A6A30);
	static inline auto FIsProcessing = PreyFunction<bool(ArkOperatorDispenser const *const _this)>(0x11A7240);
	static inline auto FIsInteractive = PreyFunction<bool(ArkOperatorDispenser const *const _this)>(0xDD23F0);
	static inline auto FSetState = PreyFunction<void(ArkOperatorDispenser *const _this, EArkDispenserState _state, bool _bForce)>(0x11AA460);
	static inline auto FUpdateErrorState = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11AB140);
	static inline auto FSetError = PreyFunction<void(ArkOperatorDispenser *const _this, EArkDispenserError _error)>(0x11AA130);
	static inline auto FRefreshUI = PreyFunction<void(ArkOperatorDispenser *const _this, bool _bReinit)>(0x11A9B40);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkOperatorDispenser *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x11A8C50);
	static inline auto FTriggerSpawn = PreyFunction<bool(ArkOperatorDispenser *const _this)>(0x11AAC20);
	static inline auto FSpawnFakeOperator = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11AA650);
	static inline auto FClearFakeOperator = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A5C30);
	static inline auto FMoveOperator = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A7D40);
	static inline auto FTestForObstruction = PreyFunction<bool(ArkOperatorDispenser const *const _this)>(0x11AA850);
	static inline auto FPlayAnimation = PreyFunction<void(ArkOperatorDispenser *const _this, const int _animId, bool _bHoldLastFrame, const float _startTime)>(0x11A9360);
	static inline auto FAddSpawnModifiers = PreyFunction<void(ArkOperatorDispenser *const _this, unsigned _id)>(0x11A5900);
	static inline auto FDestroyGloo = PreyFunction<void(ArkOperatorDispenser *const _this)>(0x11A5F70);
	static inline auto FGetErrorString = PreyFunction<const char *(ArkOperatorDispenser const *const _this)>(0x11A67B0);
	static inline auto FSetOperatorArchetype = PreyFunction<void(ArkOperatorDispenser *const _this, uint64_t _archetype)>(0x11AA2D0);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkOperatorDispenser *const _this, bool _bForce)>(0x11A8B90);
	static inline auto FGetOperatorDisplayName = PreyFunction<boost::optional<CryStringT<char> const &>(ArkOperatorDispenser const *const _this)>(0x11A6850);
};

