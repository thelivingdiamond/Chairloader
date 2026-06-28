// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryPhysics/primitives.h>
#include <Prey/Ark/ArkAudioUtil.h>
//#include <Prey/CryAISystem/INavigationSystem.h>
//#include <Prey/CryAISystem/MovementRequest.h>
//#include <Prey/CryAISystem/MovementStyle.h>
#include <Prey/CryAction/IGameObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/ArkCommon/ArkDelegate.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
//#include <Prey/GameDll/ark/ai/ArkOffMeshLinkHelper.h>
#include <Prey/GameDll/ark/ArkDoor.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/iface/IArkDoor.h>
//#include <Prey/GameDll/ark/npc/desires/ArkNpcDesireTarget.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionInfo;
struct ArkInteractionTestResult;
class IArkRoomPortal;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class SmartScriptTable;

#if 0
// Header: Exact
// Prey/GameDll/ark/arkdoor.h
class ArkNpcMovementDesire : public ArkNpcDesireBase<ArkNpcMovementDesireManager,ArkNpcMovementDesire,enum EArkNpcMovementDesirePriority> // Id=8014110 Size=240
{
public:
	using Callback = ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)>;
	
	class DestinationParam // Id=8014115 Size=8
	{
	public:
		ArkNpcDesireTarget const &m_destination;
		
		DestinationParam(ArkNpcDesireTarget const &_destination);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::DestinationParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526DC0);
	};

	class EnableNavMeshQueryParam // Id=8014116 Size=12
	{
	public:
		float m_navQueryHorizontalRadius;
		float m_navQueryBelowThreshold;
		float m_navQueryAboveThreshold;
		
		EnableNavMeshQueryParam();
		EnableNavMeshQueryParam(float _navQueryHorizontalRadius, float _navQueryBelowThreshold, float _navQueryAboveThreshold);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::EnableNavMeshQueryParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526ED0);
	};

	class DisableNavMeshQueryParam // Id=8014117 Size=1
	{
	public:
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::DisableNavMeshQueryParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526EB0);
	};

	class ForcePathParam // Id=8014118 Size=1
	{
	public:
		bool m_bForce;
		
		ForcePathParam(bool _bForce);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
#if 0
		void __dflt_ctor_closure();
#endif
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::ForcePathParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526F40);
	};

	class ForceGoToNavMeshParam // Id=8014119 Size=1
	{
	public:
#if 0
		bool Set(ArkNpcMovementDesire &arg0) const;
#endif
	};

	class StanceParam // Id=801411A Size=4
	{
	public:
		MovementStyle::Stance m_stance;
		
		StanceParam(MovementStyle::Stance _stance);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::StanceParam const *const _this, ArkNpcMovementDesire &_desire)>(0x15270F0);
	};

	class SpeedLiteralParam // Id=801411B Size=4
	{
	public:
		float m_overrideSpeedLiteral;
		
		SpeedLiteralParam(float _overrideSpeedLiteral);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::SpeedLiteralParam const *const _this, ArkNpcMovementDesire &_desire)>(0x15270D0);
	};

	class AccelLiteralParam // Id=801411C Size=4
	{
	public:
		float m_overrideAccelLiteral;
		
		AccelLiteralParam(float _overrideAccelLiteral);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::AccelLiteralParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526D80);
	};

	class DecelLiteralParam // Id=801411D Size=4
	{
	public:
		float m_overrideDecelLiteral;
		
#if 0
		bool Set(ArkNpcMovementDesire &arg0) const;
#endif
	};

	class StopDistanceParam // Id=801411E Size=4
	{
	public:
		float m_stopDistance;
		
		StopDistanceParam(float _stopDistance);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::StopDistanceParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1527100);
	};

	class UseExactPositionParam // Id=801411F Size=20
	{
	public:
		bool m_bEnable;
		float m_rotationStartDist;
		Vec3 m_dirAtTarget;
		
		UseExactPositionParam(bool _bEnable, Vec3 const &_dirAtTarget, float _rotationStartDist);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::UseExactPositionParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1527120);
	};

	class ShiftParam // Id=8014120 Size=24
	{
	public:
		bool m_bShift;
		float m_beforeShiftDist;
		float m_afterShiftDist;
		MovementStyle::ShiftAnimation m_shiftAnims;
		float m_telegraphTime;
		MovementStyle::ShiftType m_shiftType;
		
		ShiftParam(bool _bShift, float _beforeShiftDist, float _afterShiftDist, MovementStyle::ShiftAnimation _shiftAnims, float _telegraphTime, MovementStyle::ShiftType _shiftType);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::ShiftParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1527030);
	};

	class JumpParam // Id=8014121 Size=16
	{
	public:
		MovementStyle::JumpStyle m_jumpStyle;
		MovementStyle::JumpGoal m_jumpGoal;
		float m_jumpDist;
		float m_goalPathDist;
		
		JumpParam(MovementStyle::JumpStyle _jumpStyle, MovementStyle::JumpGoal _jumpGoal, float _jumpDist, float _goalPathDist);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::JumpParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526F80);
	};

	class HoverParam // Id=8014122 Size=4
	{
	public:
		MovementStyle::HoverStyle m_style;
		
		HoverParam(MovementStyle::HoverStyle _style);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::HoverParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526F60);
	};

	class ContinueMovingParam // Id=8014123 Size=1
	{
	public:
		bool m_bEnable;
		
		ContinueMovingParam(bool _bEnable);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
#if 0
		void __dflt_ctor_closure();
#endif
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::ContinueMovingParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526DA0);
	};

	class ScriptMoveParam // Id=8014124 Size=1
	{
	public:
		bool m_bScriptMove;
		
		ScriptMoveParam(bool _bEnable);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::ScriptMoveParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1527010);
	};

	class ObstacleAvoidanceParam // Id=8014125 Size=4
	{
	public:
		EArkObstacleAvoidanceUrgency m_urgency;
		
		ObstacleAvoidanceParam(EArkObstacleAvoidanceUrgency _urgency);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::ObstacleAvoidanceParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526FF0);
	};

	class ErrorParam // Id=8014126 Size=1
	{
	public:
		bool m_bAllowTeleportToNavMesh;
		
		ErrorParam(bool _bAllowTeleportToNavMesh);
		bool Set(ArkNpcMovementDesire &_desire) const { return FSet(this,_desire); }
		
		static inline auto FSet = PreyFunction<bool(ArkNpcMovementDesire::ErrorParam const *const _this, ArkNpcMovementDesire &_desire)>(0x1526F20);
	};

	ArkNpcDesireTarget m_destination;
	bool m_bQueryNavSystem;
	float m_navQueryHorizontalRadius;
	float m_navQueryBelowThreshold;
	float m_navQueryAboveThreshold;
	bool m_bForcePath;
	bool m_bForceGoToNavMesh;
	int m_stance;
	float m_speedLiteral;
	float m_accelLiteral;
	float m_decelLiteral;
	float m_stopDistance;
	float m_resumeDistance;
	bool m_bUseExactPosition;
	float m_exactRotationStartDist;
	Vec3 m_exactDirection;
	bool m_bShift;
	float m_shiftDistBefore;
	float m_shiftDistAfter;
	float m_shiftTelegraphTime;
	MovementStyle::ShiftAnimation m_shiftAnims;
	MovementStyle::ShiftType m_shiftType;
	MovementStyle::JumpStyle m_jumpStyle;
	MovementStyle::JumpGoal m_jumpGoal;
	float m_jumpDist;
	float m_jumpGoalPathDist;
	MovementStyle::HoverStyle m_hoverStyle;
	EArkObstacleAvoidanceUrgency m_obstacleAvoidUrgency;
	bool m_bContinueMoving;
	bool m_bScriptMove;
	bool m_bAllowTeleportToNavMesh;
	MovementRequestResult::FailureReason m_lastFailure;
	ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)> m_callback;
	
	ArkNpcMovementDesire(EArkNpcMovementDesirePriority _priority, const char *_dbgSource);
	void SetCallback(ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)> _callback) { FSetCallback(this,_callback); }
	void ClearCallback() { FClearCallback(this); }
	void SetResumeDistance(float _resumeDistance) { FSetResumeDistance(this,_resumeDistance); }
	bool GetCanShift() const { return FGetCanShift(this); }
	
#if 0
	MovementRequestResult::FailureReason GetLastFailureReason() const;
	ArkNpcDesireTarget const &GetDesireTarget();
#endif
	
	static inline auto FSetCallback = PreyFunction<void(ArkNpcMovementDesire *const _this, ArkDelegate<void __cdecl(enum EArkNpcMovementDesireCallbackEvent)> _callback)>(0x1527190);
	static inline auto FClearCallback = PreyFunction<void(ArkNpcMovementDesire *const _this)>(0x1526D60);
	static inline auto FSetResumeDistance = PreyFunction<void(ArkNpcMovementDesire *const _this, float _resumeDistance)>(0x15271B0);
	static inline auto FGetCanShift = PreyFunction<bool(ArkNpcMovementDesire const *const _this)>(0x1426BA0);
};
#endif

// Header: Exact
// Prey/GameDll/ark/ArkDoor.h
class ArkDoor : public CGameObjectExtensionHelper<ArkDoor,IGameObjectExtension>, public IArkDisruptableListener, public IArkDoor, public IArkPlayerInteractionListener // Id=8019108 Size=688
{
public:
	std::vector<unsigned int> m_entitiesInArea;
	unsigned m_lastCollidedEntityId;
	ArkSimpleTimer m_openTimer;
	Vec3 m_linkPosOffset;
	ArkOffMeshLinkHelper m_navLinksForward;
	ArkOffMeshLinkHelper m_navLinksReverse;
	unsigned m_portalId;
	bool m_bOpened;
	bool m_bLocked;
	bool m_bPowered;
	bool m_bRebuildLinks;
	bool m_bMarkedForUpdate;
	float m_updateEditorPosTimer;
	ArkDisruptable m_disruptable;
	ArkDisruptableSignalReceiver m_disruptableSignalReceiver;
	bool m_isVisPortalActive;
	bool m_bBroadcastDoorState;
	bool m_bForceClosed;
	
	enum class EArkPryState
	{
		none = 0,
		lerp = 1,
		in = 2,
		loop = 3,
		out = 4,
	};

	ArkDoor::EArkPryState m_pryState;
	_smart_ptr<TAction<SAnimationContext> > m_pPryAction;
	std::vector<unsigned int> m_usingNpcEntityIds;
	bool m_bDisruptable;
	bool m_bOnlyBackSideUsable;
	bool m_bStartsOpen;
	bool m_bPryable;
	int m_openAnimId;
	int m_closeAnimId;
	int m_pryInAnimId;
	int m_pryLoopAnimId;
	int m_pryOpenAnimId;
	int m_pryCancelAnimId;
	float m_pryPlayerLerpSpeed;
	float m_pryPlayerAngularLerp;
	uint64_t m_pryOpenAbilityRequirement;
	ArkSimpleTimer m_pryTimer;
	string m_pryInteractionText;
	string m_manualOpenInteractionText;
	string m_manualCloseInteractionText;
	string m_displayNameLockedAndUnpowered;
	string m_displayNameUnlockedAndUnpowered;
	string m_displayNameLockedAndManual;
	string m_displayNameUnlockedAndManual;
	Vec3 m_triggerDimensions;
	QuatT m_pryFrontAttachment;
	QuatT m_pryBackAttachment;
	string m_pryPlayerFragmentIn;
	string m_pryPlayerFragmentOut;
	string m_pryPlayerFragmentCancel;
	ArkAudioTrigger m_triggerOpen;
	ArkAudioTrigger m_triggerClose;
	ArkAudioTrigger m_triggerLocked;
	
	ArkDoor();
	virtual ~ArkDoor();
	virtual bool Init(IGameObject *_pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual void PostReloadExtension(IGameObject *_pGameObject, SEntitySpawnParams const &_params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer *_pS) const;
	virtual bool IsOpening() const;
	virtual bool IsOpen() const;
	virtual void Open();
	virtual void OpenResetTimer();
	virtual bool WaitToUse(unsigned _id) const;
	virtual void SetUsing(unsigned _id, bool _bUsing);
	virtual bool IsDoorGlooed() const;
	void BreakAllGloo() const { FBreakAllGloo(this); }
	void OnLock(bool _bLock) { FOnLock(this,_bLock); }
	void OnOpen() { FOnOpen(this); }
	bool OnClose() { return FOnClose(this); }
	void OnPower(bool _bOn) { FOnPower(this,_bOn); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity);
	virtual bool OnHoldToUseStopped(IEntity *const _pEntity);
	virtual bool TestInteraction(IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result) const;
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo) const;
	std::vector<geom_contact> GetContactsTouchingSensor() const { return FGetContactsTouchingSensor(this); }
	void ClearLinks() { FClearLinks(this); }
	void RebuildLinks() { FRebuildLinks(this); }
	void OnNavMeshChange() { FOnNavMeshChange(this); }
	bool IsPlayingAnimation() const { return FIsPlayingAnimation(this); }
	void OnObstructed(IEntity const &_entity) { FOnObstructed(this,_entity); }
	bool CalculateLinkPositions(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentID, Vec3 &_start, Vec3 &_end) const { return FCalculateLinkPositions(this,_navAgentID,_start,_end); }
	bool TestValidLinkPositions(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentID, Vec3 &_start, Vec3 &_end, float _radius, bool _bGloo) const { return FTestValidLinkPositions(this,_navAgentID,_start,_end,_radius,_bGloo); }
	void UpdateNavigation() { FUpdateNavigation(this); }
	void MarkForUpdate() { FMarkForUpdate(this); }
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual bool AffectedByDisruption() const;
	bool IsAreaTriggered() const { return FIsAreaTriggered(this); }
	void LoadProperties() { FLoadProperties(this); }
	void LoadCharacterData() { FLoadCharacterData(this); }
	void RefreshAttachmentPoints() { FRefreshAttachmentPoints(this); }
	bool TestInteractionHeading() const { return FTestInteractionHeading(this); }
	bool DoPlayAnimation(int _animId, float _forceTime) { return FDoPlayAnimation(this,_animId,_forceTime); }
	bool DoPlayPryAnimation(int _animId, bool _bLooping) { return FDoPlayPryAnimation(this,_animId,_bLooping); }
	void DoPlayPlayerPryAnimation(string const &_animName) { FDoPlayPlayerPryAnimation(this,_animName); }
	void UpdateDisplayName() { FUpdateDisplayName(this); }
	QuatT const &GetPlayerPryLerpTarget() const { return FGetPlayerPryLerpTarget(this); }
	void StartPry() { FStartPry(this); }
	void CleanupPry() { FCleanupPry(this); }
	bool UpdateLerpParameters(float _frameTime, Vec3 &_position, Quat &_rotation, Vec3 const &_targetPos, Quat const &_targetRot) const { return FUpdateLerpParameters(this,_frameTime,_position,_rotation,_targetPos,_targetRot); }
	
#if 0
	bool IsLocked() const;
	void SetAudioPortal(unsigned arg0);
	SmartScriptTable GetPropertiesTable() const;
	IArkRoomPortal *GetLinkedAudioPortal() const;
	void ActivateVisPortal(bool arg0);
	bool IsPowered() const;
	bool IsWaitingForNpcToCompleteAnim() const;
	bool UpdatePlayerPryLerp(float arg0);
	void UpdatePryLerpTargetWithOffset(Vec3 &arg0, Quat const &arg1) const;
	void StopPry(bool arg0);
#endif
	
	static inline auto FBitNotArkDoor = PreyFunction<void(ArkDoor *const _this)>(0x1422B80);
	static inline auto FInit = PreyFunction<bool(ArkDoor *const _this, IGameObject *_pGameObject)>(0x1426890);
	static inline auto FInitClient = PreyFunction<void(ArkDoor *const _this, int _channelId)>(0xA13080);
	static inline auto FPostInit = PreyFunction<void(ArkDoor *const _this, IGameObject *_pGameObject)>(0x1428970);
	static inline auto FPostInitClient = PreyFunction<void(ArkDoor *const _this, int _channelId)>(0xA13080);
	static inline auto FReloadExtension = PreyFunction<bool(ArkDoor *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xDD23F0);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkDoor *const _this, IGameObject *_pGameObject, SEntitySpawnParams const &_params)>(0xA13080);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkDoor *const _this, TSerialize _signature)>(0xDD23F0);
	static inline auto FRelease = PreyFunction<void(ArkDoor *const _this)>(0x1429860);
	static inline auto FFullSerialize = PreyFunction<void(ArkDoor *const _this, TSerialize _ser)>(0x1425330);
	static inline auto FNetSerialize = PreyFunction<bool(ArkDoor *const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1B933B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkDoor *const _this)>(0x1428B40);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkDoor *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>(ArkDoor *const _this)>(0x13883F0);
	static inline auto FUpdate = PreyFunction<void(ArkDoor *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x142A3A0);
	static inline auto FPostUpdate = PreyFunction<void(ArkDoor *const _this, float _frameTime)>(0xA13080);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkDoor *const _this)>(0xA13080);
	static inline auto FHandleEvent = PreyFunction<void(ArkDoor *const _this, SGameObjectEvent const &_event)>(0xA13080);
	static inline auto FProcessEvent = PreyFunction<void(ArkDoor *const _this, SEntityEvent &_event)>(0x1428B90);
	static inline auto FSetChannelId = PreyFunction<void(ArkDoor *const _this, uint16_t _id)>(0xA13080);
	static inline auto FSetAuthority = PreyFunction<void(ArkDoor *const _this, bool _bAuth)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkDoor const *const _this, ICrySizer *_pS)>(0x13A4DC0);
	static inline auto FIsOpening = PreyFunction<bool(ArkDoor const *const _this)>(0x1426BB0);
	static inline auto FIsOpen = PreyFunction<bool(ArkDoor const *const _this)>(0x1426BA0);
	static inline auto FOpen = PreyFunction<void(ArkDoor *const _this)>(0x1428670);
	static inline auto FOpenResetTimer = PreyFunction<void(ArkDoor *const _this)>(0x1428790);
	static inline auto FWaitToUse = PreyFunction<bool(ArkDoor const *const _this, unsigned _id)>(0x142BA40);
	static inline auto FSetUsing = PreyFunction<void(ArkDoor *const _this, unsigned _id, bool _bUsing)>(0x1429A50);
	static inline auto FIsDoorGlooed = PreyFunction<bool(ArkDoor const *const _this)>(0x1426910);
	static inline auto FBreakAllGloo = PreyFunction<void(ArkDoor const *const _this)>(0x14242A0);
	static inline auto FOnLock = PreyFunction<void(ArkDoor *const _this, bool _bLock)>(0x1428280);
	static inline auto FOnOpen = PreyFunction<void(ArkDoor *const _this)>(0x1428550);
	static inline auto FOnClose = PreyFunction<bool(ArkDoor *const _this)>(0x1427F80);
	static inline auto FOnPower = PreyFunction<void(ArkDoor *const _this, bool _bOn)>(0x14285A0);
	static inline auto FOnInteraction = PreyFunction<bool(ArkDoor *const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity *const _pEntity)>(0x14281E0);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(ArkDoor *const _this, IEntity *const _pEntity)>(0x1428120);
	static inline auto FTestInteraction = PreyFunction<bool(ArkDoor const *const _this, IEntity const *const _pEntity, ArkInteractionInfo const &_interactionInfo, EArkInteractionMode _mode, ArkInteractionTestResult &_result)>(0x1429CD0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkDoor const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x14287B0);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(ArkDoor const *const _this, IEntity const *const _pEntity, ArkInteractionInfo &_interactionInfo)>(0x14288E0);
	static inline auto FGetContactsTouchingSensor = PreyFunction<std::vector<geom_contact>(ArkDoor const *const _this)>(0x1425670);
	static inline auto FClearLinks = PreyFunction<void(ArkDoor *const _this)>(0x1424FA0);
	static inline auto FRebuildLinks = PreyFunction<void(ArkDoor *const _this)>(0x1428F90);
	static inline auto FOnNavMeshChange = PreyFunction<void(ArkDoor *const _this)>(0x1428300);
	static inline auto FIsPlayingAnimation = PreyFunction<bool(ArkDoor const *const _this)>(0x1426C20);
	static inline auto FOnObstructed = PreyFunction<void(ArkDoor *const _this, IEntity const &_entity)>(0x1428340);
	static inline auto FCalculateLinkPositions = PreyFunction<bool(ArkDoor const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentID, Vec3 &_start, Vec3 &_end)>(0x14242C0);
	static inline auto FTestValidLinkPositions = PreyFunction<bool(ArkDoor const *const _this, TNavigationID<ENavigationIDTag::AgentTypeIDTag> _navAgentID, Vec3 &_start, Vec3 &_end, float _radius, bool _bGloo)>(0x1429FB0);
	static inline auto FUpdateNavigation = PreyFunction<void(ArkDoor *const _this)>(0x142B9D0);
	static inline auto FMarkForUpdate = PreyFunction<void(ArkDoor *const _this)>(0x1427F40);
	static inline auto FOnDisruptedChanged = PreyFunction<void(ArkDoor *const _this, bool _bDisrupted, bool _bWasForced)>(0x1428080);
	static inline auto FGetSparkLoc = PreyFunction<QuatT(ArkDoor const *const _this)>(0x14260D0);
	static inline auto FAffectedByDisruption = PreyFunction<bool(ArkDoor const *const _this)>(0xAB1310);
	static inline auto FIsAreaTriggered = PreyFunction<bool(ArkDoor const *const _this)>(0x14268E0);
	static inline auto FLoadProperties = PreyFunction<void(ArkDoor *const _this)>(0x1427150);
	static inline auto FLoadCharacterData = PreyFunction<void(ArkDoor *const _this)>(0x1426C90);
	static inline auto FRefreshAttachmentPoints = PreyFunction<void(ArkDoor *const _this)>(0x14296A0);
	static inline auto FTestInteractionHeading = PreyFunction<bool(ArkDoor const *const _this)>(0x1429ED0);
	static inline auto FDoPlayAnimation = PreyFunction<bool(ArkDoor *const _this, int _animId, float _forceTime)>(0x1425020);
	static inline auto FDoPlayPryAnimation = PreyFunction<bool(ArkDoor *const _this, int _animId, bool _bLooping)>(0x1425230);
	static inline auto FDoPlayPlayerPryAnimation = PreyFunction<void(ArkDoor *const _this, string const &_animName)>(0x1425180);
	static inline auto FUpdateDisplayName = PreyFunction<void(ArkDoor *const _this)>(0x142B390);
	static inline auto FGetPlayerPryLerpTarget = PreyFunction<QuatT const &(ArkDoor const *const _this)>(0x1425FF0);
	static inline auto FStartPry = PreyFunction<void(ArkDoor *const _this)>(0x1429AD0);
	static inline auto FCleanupPry = PreyFunction<void(ArkDoor *const _this)>(0x1424C30);
	static inline auto FUpdateLerpParameters = PreyFunction<bool(ArkDoor const *const _this, float _frameTime, Vec3 &_position, Quat &_rotation, Vec3 const &_targetPos, Quat const &_targetRot)>(0x142B440);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <CryEngine/cryaction/igameobject.h>
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryPhysics/primitives.h>
#include <Prey/GameDll/ark/ArkDisruptable.h>
#include <Prey/GameDll/ark/ArkDisruptableSignalReceiver.h>
#include <Prey/GameDll/ark/ArkDoorRNG.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/ArkRepairable.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkNavLinkOwner.h>
#include <Prey/GameDll/ark/iface/IArkDisruptableListener.h>
#include <Prey/GameDll/ark/iface/IArkDoor.h>
#include <Prey/GameDll/ark/iface/IArkRepairableListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerInteractionListener.h>

struct ArkInteractionTestResult;
enum class EArkInteractionMode;
enum class EArkInteractionType;
enum EEntityAspects;
class IArkRoomPortal;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct ISerializableInfo;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SEntityUpdateContext;
struct SGameObjectEvent;
class SmartScriptTable;

// ArkDoor
// Header:  Prey/GameDll/ark/ArkDoor.h
class ArkDoor
	: public CGameObjectExtensionHelper<ArkDoor, IGameObjectExtension>
	, public IArkDisruptableListener
	, public IArkDoor
	, public IArkPlayerInteractionListener
	, public ArkNavLinkOwner
	, public IArkRepairableListener
	, public IEntityEventListener
{ // Size=1008 (0x3F0)
public:
	enum class EArkPryState
	{
		none = 0,
		lerp = 1,
		in = 2,
		loop = 3,
		out = 4,
	};

	ArkDoorRNG m_rng;
	std::vector<unsigned int> m_entitiesInArea;
	std::vector<unsigned int> m_registeredControllers;
	unsigned m_lastCollidedEntityId;
	ArkSimpleTimer m_openTimer;
	unsigned m_portalId;
	bool m_bOpened;
	bool m_bLocked;
	bool m_bPowered;
	bool m_bMarkedForUpdate;
	ArkDisruptable m_disruptable;
	ArkDisruptableSignalReceiver m_disruptableSignalReceiver;
	ArkRepairable m_repairable;
	ArkRandomizedAutoResetTimer m_brokenVFXTimer;
	ArkFireAndForgetEffect m_brokenVFX;
	bool m_isVisPortalActive;
	bool m_bBroadcastDoorState;
	bool m_bForceClosed;
	ArkDoor::EArkPryState m_pryState;
	_smart_ptr<TAction<SAnimationContext>> m_pPryAction;
	std::vector<unsigned int> m_usingNpcEntityIds;
	bool m_bDisruptable;
	bool m_bOnlyBackSideUsable;
	bool m_bStartsOpen;
	bool m_bPryable;
	int m_openAnimId;
	int m_closeAnimId;
	int m_pryInAnimId;
	int m_pryLoopAnimId;
	int m_pryOpenAnimId;
	int m_pryCancelAnimId;
	float m_pryPlayerLerpSpeed;
	float m_pryPlayerAngularLerp;
	float m_animPlayingTime;
	uint64_t m_pryOpenAbilityRequirement;
	ArkSimpleTimer m_pryTimer;
	string m_pryInteractionText;
	string m_manualOpenInteractionText;
	string m_manualCloseInteractionText;
	string m_displayNameLockedAndUnpowered;
	string m_displayNameUnlockedAndUnpowered;
	string m_displayNameLockedAndManual;
	string m_displayNameUnlockedAndManual;
	Vec3 m_triggerDimensions;
	QuatT m_pryFrontAttachment;
	QuatT m_pryBackAttachment;
	string m_pryPlayerFragmentIn;
	string m_pryPlayerFragmentOut;
	string m_pryPlayerFragmentCancel;
	ArkAudioTrigger m_triggerOpen;
	ArkAudioTrigger m_triggerClose;
	ArkAudioTrigger m_triggerLocked;

	ArkDoor();
	virtual ~ArkDoor();
	virtual bool Init(IGameObject* _pGameObject);
	virtual void InitClient(int _channelId);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void PostInitClient(int _channelId);
	virtual bool ReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual void PostReloadExtension(IGameObject* _pGameObject, const SEntitySpawnParams& _params);
	virtual bool GetEntityPoolSignature(TSerialize _signature);
	virtual void Release();
	virtual void FullSerialize(TSerialize _ser);
	virtual bool NetSerialize(TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags);
	virtual void PostSerialize();
	virtual void SerializeSpawnInfo(TSerialize _ser);
	virtual _smart_ptr<ISerializableInfo> GetSpawnInfo();
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void PostUpdate(float _frameTime);
	virtual void PostRemoteSpawn();
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void SetChannelId(uint16_t _id);
	virtual void SetAuthority(bool _bAuth);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual bool IsOpening() const;
	virtual bool IsOpen() const;
	virtual void Open();
	virtual void OpenResetTimer();
	virtual bool WaitToUse(unsigned _id) const;
	virtual void SetUsing(unsigned _id, bool _bUsing);
	virtual bool IsDoorGlooed() const;
	void BreakAllGloo() const { FBreakAllGloo(this); }
	void OnLock(bool _bLock) { FOnLock(this, _bLock); }
	void OnOpen() { FOnOpen(this); }
	bool OnClose() { return FOnClose(this); }
	void OnPower(bool _bOn) { FOnPower(this, _bOn); }
	virtual bool OnInteraction(EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity);
	virtual bool OnHoldToUseStopped(IEntity* const _pEntity);
	virtual bool TestInteraction(const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, const EArkInteractionMode _mode, ArkInteractionTestResult& _result) const;
	virtual bool PopulateInteractionInfo(const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray) const;
	virtual bool PopulateRemoteManipulationInteraction(const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo) const;
	void RegisterController(unsigned _entityId) { FRegisterController(this, _entityId); }
	void UnregisterController(unsigned _entityId) { FUnregisterController(this, _entityId); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	std::vector<geom_contact> GetContactsTouchingSensor() const { alignas(std::vector<geom_contact>) std::byte _return_buf_[sizeof(std::vector<geom_contact>)]; return *FGetContactsTouchingSensor(this, reinterpret_cast<std::vector<geom_contact>*>(_return_buf_)); }
	bool IsPlayingAnimation() const { return FIsPlayingAnimation(this); }
	void OnObstructed(const IEntity& _entity) { FOnObstructed(this, _entity); }
	void UpdateNavigation() { FUpdateNavigation(this); }
	void MarkForUpdate() { FMarkForUpdate(this); }
	virtual void OnDisruptedChanged(bool _bDisrupted, bool _bWasForced);
	virtual QuatT GetSparkLoc() const;
	virtual bool AffectedByDisruption() const;
	bool IsAreaTriggered() const { return FIsAreaTriggered(this); }
	void LoadProperties() { FLoadProperties(this); }
	void LoadCharacterData() { FLoadCharacterData(this); }
	void RefreshAttachmentPoints() { FRefreshAttachmentPoints(this); }
	bool TestInteractionHeading() const { return FTestInteractionHeading(this); }
	bool DoPlayAnimation(int _animId, float _forceTime) { return FDoPlayAnimation(this, _animId, _forceTime); }
	bool DoPlayPryAnimation(int _animId, bool _bLooping) { return FDoPlayPryAnimation(this, _animId, _bLooping); }
	void DoPlayPlayerPryAnimation(const string& _animName) { FDoPlayPlayerPryAnimation(this, _animName); }
	void UpdateDisplayName() { FUpdateDisplayName(this); }
	const QuatT& GetPlayerPryLerpTarget() const { return FGetPlayerPryLerpTarget(this); }
	void StartPry() { FStartPry(this); }
	void CleanupPry() { FCleanupPry(this); }
	virtual void ClearLinks();
	virtual void OnBrokenChanged(bool _bBroken, bool _bWasForced);
	bool UpdateLerpParameters(float _frameTime, Vec3& _position, Quat& _rotation, const Vec3& _targetPos, const Quat& _targetRot) const { return FUpdateLerpParameters(this, _frameTime, _position, _rotation, _targetPos, _targetRot); }

#if 0
	bool IsLocked() const;
	void SetAudioPortal(unsigned _arg0_);
	ArkRepairable& GetRepairable();
	SmartScriptTable GetPropertiesTable() const;
	IArkRoomPortal* GetLinkedAudioPortal() const;
	void ActivateVisPortal(bool _arg0_);
	bool IsPowered() const;
	bool IsWaitingForNpcToCompleteAnim() const;
	bool UpdatePlayerPryLerp(float _arg0_);
	void UpdatePryLerpTargetWithOffset(Vec3& _arg0_, const Quat& _arg1_) const;
	void StopPry(bool _arg0_);
	void UpdateControllerBrokenState();
#endif

	static inline auto FArkDoorOv1 = PreyFunction<void(ArkDoor* const _this)>(0x15387D0);
	static inline auto FBitNotArkDoor = PreyFunction<void(ArkDoor* const _this)>(0x1538AA0);
	static inline auto FInit = PreyFunction<bool(ArkDoor* const _this, IGameObject* _pGameObject)>(0x153C0C0);
	static inline auto FInitClient = PreyFunction<void(ArkDoor* const _this, int _channelId)>(0x1333E90);
	static inline auto FPostInit = PreyFunction<void(ArkDoor* const _this, IGameObject* _pGameObject)>(0x153EBF0);
	static inline auto FPostInitClient = PreyFunction<void(ArkDoor* const _this, int _channelId)>(0x1333E90);
	static inline auto FReloadExtension = PreyFunction<bool(ArkDoor* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x13B0900);
	static inline auto FPostReloadExtension = PreyFunction<void(ArkDoor* const _this, IGameObject* _pGameObject, const SEntitySpawnParams& _params)>(0x1333E90);
	static inline auto FGetEntityPoolSignature = PreyFunction<bool(ArkDoor* const _this, TSerialize _signature)>(0x13B0900);
	static inline auto FRelease = PreyFunction<void(ArkDoor* const _this)>(0x153F3E0);
	static inline auto FFullSerialize = PreyFunction<void(ArkDoor* const _this, TSerialize _ser)>(0x153AAF0);
	static inline auto FNetSerialize = PreyFunction<bool(ArkDoor* const _this, TSerialize _ser, EEntityAspects _aspect, uint8_t _profile, int _flags)>(0x1A302A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkDoor* const _this)>(0x153ECD0);
	static inline auto FSerializeSpawnInfo = PreyFunction<void(ArkDoor* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FGetSpawnInfo = PreyFunction<_smart_ptr<ISerializableInfo>*(ArkDoor* const _this, _smart_ptr<ISerializableInfo>* _return_value_)>(0x361570);
	static inline auto FUpdate = PreyFunction<void(ArkDoor* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x153FA20);
	static inline auto FPostUpdate = PreyFunction<void(ArkDoor* const _this, float _frameTime)>(0x1333E90);
	static inline auto FPostRemoteSpawn = PreyFunction<void(ArkDoor* const _this)>(0x1333E90);
	static inline auto FHandleEvent = PreyFunction<void(ArkDoor* const _this, const SGameObjectEvent& _event)>(0x1333E90);
	static inline auto FProcessEvent = PreyFunction<void(ArkDoor* const _this, SEntityEvent& _event)>(0x153ED60);
	static inline auto FSetChannelId = PreyFunction<void(ArkDoor* const _this, uint16_t _id)>(0x1333E90);
	static inline auto FSetAuthority = PreyFunction<void(ArkDoor* const _this, bool _bAuth)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkDoor* const _this, ICrySizer* _pS)>(0x153B800);
	static inline auto FIsOpening = PreyFunction<bool(const IArkDoor* const _this)>(0x153C3F0);
	static inline auto FIsOpen = PreyFunction<bool(const IArkDoor* const _this)>(0x153C3E0);
	static inline auto FOpen = PreyFunction<void(IArkDoor* const _this)>(0x153E8E0);
	static inline auto FOpenResetTimer = PreyFunction<void(IArkDoor* const _this)>(0x153EA00);
	static inline auto FWaitToUse = PreyFunction<bool(const IArkDoor* const _this, unsigned _id)>(0x15413A0);
	static inline auto FSetUsing = PreyFunction<void(IArkDoor* const _this, unsigned _id, bool _bUsing)>(0x153F410);
	static inline auto FIsDoorGlooed = PreyFunction<bool(const IArkDoor* const _this)>(0x153C150);
	static inline auto FBreakAllGloo = PreyFunction<void(const ArkDoor* const _this)>(0x153A410);
	static inline auto FOnLock = PreyFunction<void(ArkDoor* const _this, bool _bLock)>(0x153E530);
	static inline auto FOnOpen = PreyFunction<void(ArkDoor* const _this)>(0x153E7C0);
	static inline auto FOnClose = PreyFunction<bool(ArkDoor* const _this)>(0x153DE60);
	static inline auto FOnPower = PreyFunction<void(ArkDoor* const _this, bool _bOn)>(0x153E810);
	static inline auto FOnInteraction = PreyFunction<bool(IArkPlayerInteractionListener* const _this, EArkInteractionType _interaction, EArkInteractionMode _mode, IEntity* const _pEntity)>(0x153E480);
	static inline auto FOnHoldToUseStopped = PreyFunction<bool(IArkPlayerInteractionListener* const _this, IEntity* const _pEntity)>(0x153E3C0);
	static inline auto FTestInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, const ArkInteractionInfo& _interactionInfo, const EArkInteractionMode _mode, ArkInteractionTestResult& _result)>(0x153F6A0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, std::array<ArkInteractionInfo, 4>& _interactionArray)>(0x153EA20);
	static inline auto FPopulateRemoteManipulationInteraction = PreyFunction<bool(const IArkPlayerInteractionListener* const _this, const IEntity* const _pEntity, ArkInteractionInfo& _interactionInfo)>(0x153EB60);
	static inline auto FRegisterController = PreyFunction<void(ArkDoor* const _this, unsigned _entityId)>(0x153F360);
	static inline auto FUnregisterController = PreyFunction<void(ArkDoor* const _this, unsigned _entityId)>(0x153F9A0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x153E2D0);
	static inline auto FGetContactsTouchingSensor = PreyFunction<std::vector<geom_contact>*(const ArkDoor* const _this, std::vector<geom_contact>* _return_value_)>(0x153AE80);
	static inline auto FIsPlayingAnimation = PreyFunction<bool(const ArkDoor* const _this)>(0x153C460);
	static inline auto FOnObstructed = PreyFunction<void(ArkDoor* const _this, const IEntity& _entity)>(0x153E5B0);
	static inline auto FUpdateNavigation = PreyFunction<void(ArkDoor* const _this)>(0x1541330);
	static inline auto FMarkForUpdate = PreyFunction<void(ArkDoor* const _this)>(0x153D8C0);
	static inline auto FOnDisruptedChanged = PreyFunction<void(IArkDisruptableListener* const _this, bool _bDisrupted, bool _bWasForced)>(0x153E230);
	static inline auto FGetSparkLoc = PreyFunction<QuatT*(const IArkDisruptableListener* const _this, QuatT* _return_value_)>(0x153B900);
	static inline auto FAffectedByDisruption = PreyFunction<bool(const IArkDisruptableListener* const _this)>(0x153A400);
	static inline auto FIsAreaTriggered = PreyFunction<bool(const ArkDoor* const _this)>(0x153C120);
	static inline auto FLoadProperties = PreyFunction<void(ArkDoor* const _this)>(0x153C990);
	static inline auto FLoadCharacterData = PreyFunction<void(ArkDoor* const _this)>(0x153C4D0);
	static inline auto FRefreshAttachmentPoints = PreyFunction<void(ArkDoor* const _this)>(0x153F1A0);
	static inline auto FTestInteractionHeading = PreyFunction<bool(const ArkDoor* const _this)>(0x153F8C0);
	static inline auto FDoPlayAnimation = PreyFunction<bool(ArkDoor* const _this, int _animId, float _forceTime)>(0x153A7E0);
	static inline auto FDoPlayPryAnimation = PreyFunction<bool(ArkDoor* const _this, int _animId, bool _bLooping)>(0x153A9F0);
	static inline auto FDoPlayPlayerPryAnimation = PreyFunction<void(ArkDoor* const _this, const string& _animName)>(0x153A940);
	static inline auto FUpdateDisplayName = PreyFunction<void(ArkDoor* const _this)>(0x1540CF0);
	static inline auto FGetPlayerPryLerpTarget = PreyFunction<const QuatT& (const ArkDoor* const _this)>(0x153B820);
	static inline auto FStartPry = PreyFunction<void(ArkDoor* const _this)>(0x153F490);
	static inline auto FCleanupPry = PreyFunction<void(ArkDoor* const _this)>(0x153A430);
	static inline auto FClearLinks = PreyFunction<void(ArkNavLinkOwner* const _this)>(0x153A7B0);
	static inline auto FOnBrokenChanged = PreyFunction<void(IArkRepairableListener* const _this, bool _bBroken, bool _bWasForced)>(0x153D900);
	static inline auto FUpdateLerpParameters = PreyFunction<bool(const ArkDoor* const _this, float _frameTime, Vec3& _position, Quat& _rotation, const Vec3& _targetPos, const Quat& _targetRot)>(0x1540DA0);
};
#endif // !MOONCRASH
