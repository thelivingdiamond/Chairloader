// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractiveMachine.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ArkDoor.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <Prey/GameDll/ark/ArkPasswordProtected.h>

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
	OBB m_obstructionTestFine;
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkInteractiveMachine.h>
#include <Prey/GameDll/ark/ArkMaterialAnimationManager.h>
#include <Prey/GameDll/ark/ArkPasswordProtected.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/IArkDoomClockListener.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum class EArkInteractiveScreenType;
enum class EArkNpcMovementDesireCallbackEvent;
class ICrySizer;
struct IEntity;
struct IEntityArchetype;
struct IGameObject;
struct IUIElement;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// ArkOperatorDispenser
// Header:  Prey/GameDll/ark/ArkOperatorDispenser.h
class ArkOperatorDispenser
	: public ArkInteractiveMachine
	, public ArkUIMenuBase<ArkOperatorDispenser>
	, public IArkConversationListener
	, public IArkDoomClockListener
{ // Size=2488 (0x9B8)
public:
	// ArkOperatorDispenser::SpawnedOperator
	// Header:  Prey/GameDll/ark/ArkOperatorDispenser.h
	class SpawnedOperator
	{ // Size=8 (0x8)
	public:
		unsigned m_operatorId;
		bool m_bDispensed;
		bool m_bMoving;
		bool m_bExited;

	#if 0
		SpawnedOperator();
		void Serialize(TSerialize _arg0_);
		bool operator==(const unsigned _arg0_) const;
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
	OBB m_obstructionTestFine;
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
	int m_dahlHackingLevel;

	ArkOperatorDispenser();
	virtual ~ArkOperatorDispenser();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, const EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual void OnStartLookingAt(unsigned _targetId);
	virtual void OnWorldUIInstanceGranted(IUIElement* _pUIInstance);
	virtual void OnWorldUIInstanceRevoked(IUIElement* _pUIInstance);
	virtual EArkInteractiveScreenType GetInteractiveScreenType() const;
	virtual void OnDoomClockEnabled(bool _bEnabled);
	virtual void OnDoomClockPreIncrement(int _level);
	virtual void OnDoomClockIncrement(int _level);
	void OnButtonPress(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnButtonPress(this, _pSender, _event, _args); }
	void OnPasswordSuccess(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPasswordSuccess(this, _pSender, _event, _args); }
	void ForceSpawn() { FForceSpawn(this); }
	void SetLocked(bool _bLocked, bool _bForce) { FSetLocked(this, _bLocked, _bForce); }
	void OverrideValues(const string& _archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration) { FOverrideValues(this, _archetypeName, _maxConcurrent, _maxLifetime, _autospawnDuration); }
	void ClearOverrides() { FClearOverrides(this); }
	int AssignOperator(const unsigned _operatorId, bool _bDispensed) { return FAssignOperator(this, _operatorId, _bDispensed); }
	void MovementDesireCallback(const EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }
	void OnHackingFinished(bool _bSuccess) { FOnHackingFinished(this, _bSuccess); }
	virtual void OnConversationComplete(const bool _bComplete);
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual void InitCachedPositionData();
	virtual bool IsProcessing() const;
	virtual bool IsInteractive() const;
	bool SetState(EArkDispenserState _state, bool _bForce) { return FSetState(this, _state, _bForce); }
	void UpdateErrorState() { FUpdateErrorState(this); }
	void SetError(EArkDispenserError _error) { FSetError(this, _error); }
	void RefreshUI(bool _bReinit) { FRefreshUI(this, _bReinit); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	bool TriggerSpawn() { return FTriggerSpawn(this); }
	void SpawnFakeOperator() { FSpawnFakeOperator(this); }
	void ClearFakeOperator() { FClearFakeOperator(this); }
	void MoveOperator() { FMoveOperator(this); }
	void InvalidateAnimDelay() { FInvalidateAnimDelay(this); }
	void PlayAnimation(const int _animId, bool _bHoldLastFrame, const float _startTime) { FPlayAnimation(this, _animId, _bHoldLastFrame, _startTime); }
	void AddSpawnModifiers(unsigned _id) { FAddSpawnModifiers(this, _id); }
	void DestroyGloo() { FDestroyGloo(this); }
	const char* GetErrorString() const { return FGetErrorString(this); }
	void SetOperatorArchetype(uint64_t _archetype) { FSetOperatorArchetype(this, _archetype); }
	virtual void OnEnabledChanged(bool _bForce);
	boost::optional<CryStringT<char> const &> GetOperatorDisplayName() const { alignas(boost::optional<CryStringT<char> const &>) std::byte _return_buf_[sizeof(boost::optional<CryStringT<char> const &>)]; return *FGetOperatorDisplayName(this, reinterpret_cast<boost::optional<CryStringT<char> const &>*>(_return_buf_)); }

#if 0
	void ClearSpawnedOperators();
	IEntityArchetype* GetOperatorArchetype() const;
	bool SpawnOperator();
	bool TestForObstruction() const;
	void RemoveSpawnModifiers(unsigned _arg0_);
	bool Speak(const char* _arg0_, const IEntityArchetype* const _arg1_);
#endif

	static inline auto FArkOperatorDispenser = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x12208E0);
	static inline auto FBitNotArkOperatorDispenser = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1220C20);
	static inline auto FPostInit = PreyFunction<void(ArkOperatorDispenser* const _this, IGameObject* _pGameObject)>(0x1224C90);
	static inline auto FFullSerialize = PreyFunction<void(ArkOperatorDispenser* const _this, TSerialize _ser)>(0x1221AE0);
	static inline auto FPostSerialize = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1224DA0);
	static inline auto FUpdate = PreyFunction<void(ArkOperatorDispenser* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1225FB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkOperatorDispenser* const _this, SEntityEvent& _event)>(0x1225090);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkOperatorDispenser* const _this, ICrySizer* _s)>(0x1221E70);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x1224500);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, const EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x1225D90);
	static inline auto FOnStartLookingAt = PreyFunction<void(IArkPlayerInteractionListener* const _this, unsigned _targetId)>(0x12247E0);
	static inline auto FOnWorldUIInstanceGranted = PreyFunction<void(ArkOperatorDispenser* const _this, IUIElement* _pUIInstance)>(0x1224890);
	static inline auto FOnWorldUIInstanceRevoked = PreyFunction<void(ArkOperatorDispenser* const _this, IUIElement* _pUIInstance)>(0x1224910);
	static inline auto FGetInteractiveScreenType = PreyFunction<EArkInteractiveScreenType(const ArkOperatorDispenser* const _this)>(0x1A2FA50);
	static inline auto FOnDoomClockEnabled = PreyFunction<void(IArkDoomClockListener* const _this, bool _bEnabled)>(0x1333E90);
	static inline auto FOnDoomClockPreIncrement = PreyFunction<void(IArkDoomClockListener* const _this, int _level)>(0x1333E90);
	static inline auto FOnDoomClockIncrement = PreyFunction<void(IArkDoomClockListener* const _this, int _level)>(0x12242A0);
	static inline auto FOnButtonPress = PreyFunction<void(ArkOperatorDispenser* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1223A80);
	static inline auto FOnPasswordSuccess = PreyFunction<void(ArkOperatorDispenser* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1224580);
	static inline auto FForceSpawn = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1221AA0);
	static inline auto FSetLocked = PreyFunction<void(ArkOperatorDispenser* const _this, bool _bLocked, bool _bForce)>(0x1225900);
	static inline auto FOverrideValues = PreyFunction<void(ArkOperatorDispenser* const _this, const string& _archetypeName, int _maxConcurrent, int _maxLifetime, float _autospawnDuration)>(0x1224960);
	static inline auto FClearOverrides = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x12216C0);
	static inline auto FAssignOperator = PreyFunction<int(ArkOperatorDispenser* const _this, const unsigned _operatorId, bool _bDispensed)>(0x1221480);
	static inline auto FMovementDesireCallback = PreyFunction<void(ArkOperatorDispenser* const _this, const EArkNpcMovementDesireCallbackEvent _event)>(0x1223800);
	static inline auto FOnHackingFinished = PreyFunction<void(ArkOperatorDispenser* const _this, bool _bSuccess)>(0x1224460);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x1224230);
	static inline auto FOnReset = PreyFunction<void(ArkOperatorDispenser* const _this, bool _bEnteringGameMode)>(0x1224620);
	static inline auto FLoadProperties = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1222960);
	static inline auto FInitCachedPositionData = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x12220C0);
	static inline auto FIsProcessing = PreyFunction<bool(const ArkOperatorDispenser* const _this)>(0x1222950);
	static inline auto FIsInteractive = PreyFunction<bool(const ArkOperatorDispenser* const _this)>(0x13B0900);
	static inline auto FSetState = PreyFunction<bool(ArkOperatorDispenser* const _this, EArkDispenserState _state, bool _bForce)>(0x1225B00);
	static inline auto FUpdateErrorState = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x12262E0);
	static inline auto FSetError = PreyFunction<void(ArkOperatorDispenser* const _this, EArkDispenserError _error)>(0x1225800);
	static inline auto FRefreshUI = PreyFunction<void(ArkOperatorDispenser* const _this, bool _bReinit)>(0x1225240);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x12243D0);
	static inline auto FTriggerSpawn = PreyFunction<bool(ArkOperatorDispenser* const _this)>(0x1225E80);
	static inline auto FSpawnFakeOperator = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1225B90);
	static inline auto FClearFakeOperator = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1221640);
	static inline auto FMoveOperator = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1223460);
	static inline auto FInvalidateAnimDelay = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x12228D0);
	static inline auto FPlayAnimation = PreyFunction<void(ArkOperatorDispenser* const _this, const int _animId, bool _bHoldLastFrame, const float _startTime)>(0x1224A80);
	static inline auto FAddSpawnModifiers = PreyFunction<void(ArkOperatorDispenser* const _this, unsigned _id)>(0x1221310);
	static inline auto FDestroyGloo = PreyFunction<void(ArkOperatorDispenser* const _this)>(0x1221980);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkOperatorDispenser* const _this)>(0x1221E40);
	static inline auto FSetOperatorArchetype = PreyFunction<void(ArkOperatorDispenser* const _this, uint64_t _archetype)>(0x1225970);
	static inline auto FOnEnabledChanged = PreyFunction<void(ArkOperatorDispenser* const _this, bool _bForce)>(0x1224310);
	static inline auto FGetOperatorDisplayName = PreyFunction<boost::optional<CryStringT<char> const &>*(const ArkOperatorDispenser* const _this, boost::optional<CryStringT<char> const &>* _return_value_)>(0x1221EE0);
};
#endif // !MOONCRASH
