// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/cryaction/icrymannequin.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryScriptSystem/ScriptHelpers.h>
#include <Prey/GameDll/CryActor.h>
#include <Prey/GameDll/hitdeathreactionsdefs.h>
#include <_unknown/STagState.h>

struct AnimEventInstance;
namespace ArkSignalSystem
{
class Package;
} // namespace ArkSignalSystem
class CCryActor;
class CHitDeathReactions;
class CMTRand_int32;
enum ECardinalDirection;
struct IAISignalExtraData;
class IAction;
class IActionController;
struct IAnimationSet;
struct ICharacterInstance;
class ICrySizer;
struct IPipeUser;
struct IScriptSystem;
struct IntersectionTestResult;
struct SGameObjectEvent;
struct SReactionParams;
namespace primitives
{
struct primitive;
} // namespace primitives

// CAnimActionRagdoll
// Header:  Prey/GameDll/HitDeathReactions.h
class CAnimActionRagdoll : public TAction<SAnimationContext>
{ // Size=144 (0x90)
public:
	using TBaseAction = TAction<SAnimationContext>;

	float m_timeInRagdoll;
	float m_timeToEndRagdoll;
	bool m_isForced;

	virtual const char* GetName() const;
	virtual void DoDelete();
	virtual IAction::EStatus Update(float timePassed);
	virtual IAction::EStatus UpdatePending(float timePassed);

#if 0
	CAnimActionRagdoll(bool _arg0_, int _arg1_, const STagState<12> _arg2_);
	void InitEndRagdollTime(float _arg0_);
#endif

	static inline auto FGetName = PreyFunction<const char* (const CAnimActionRagdoll* const _this)>(0x1865690);
	static inline auto FDoDelete = PreyFunction<void(CAnimActionRagdoll* const _this)>(0x3E3960);
	static inline auto FUpdate = PreyFunction<IAction::EStatus(CAnimActionRagdoll* const _this, float timePassed)>(0x1868920);
	static inline auto FUpdatePending = PreyFunction<IAction::EStatus(CAnimActionRagdoll* const _this, float timePassed)>(0x1868CA0);
};

// CHitDeathReactionsPhysics
// Header:  Prey/GameDll/HitDeathReactions.h
class CHitDeathReactionsPhysics
{ // Size=48 (0x30)
public:
	enum class #unnamed_enum_kMaxQueuedPrimitives
	{
		kMaxQueuedPrimitives = 4,
	};

	// CHitDeathReactionsPhysics::SPrimitiveRequest
	// Header:  Prey/GameDll/HitDeathReactions.h
	struct SPrimitiveRequest
	{ // Size=8 (0x8)
		unsigned queuedId;
		unsigned counter;

	#if 0
		SPrimitiveRequest();
		void Reset();
	#endif
	};

	CHitDeathReactionsPhysics::SPrimitiveRequest m_queuedPrimitives[4];
	unsigned m_requestCounter;
	CHitDeathReactions* m_pOwnerHitReactions;

	~CHitDeathReactionsPhysics();
	void Queue(int primitiveType, primitives::primitive& primitive, const Vec3& sweepDir, int objTypes, int geomFlags) { FQueue(this, primitiveType, primitive, sweepDir, objTypes, geomFlags); }
	void IntersectionTestComplete(const unsigned& intID, const IntersectionTestResult& result) { FIntersectionTestComplete(this, intID, result); }

#if 0
	CHitDeathReactionsPhysics();
	void InitWithOwner(CHitDeathReactions* _arg0_);
	int GetPrimitiveRequestSlot();
	int GetSlotFromPrimitiveId(const unsigned& _arg0_);
#endif

	static inline auto FBitNotCHitDeathReactionsPhysics = PreyFunction<void(CHitDeathReactionsPhysics* const _this)>(0x1863FF0);
	static inline auto FQueue = PreyFunction<void(CHitDeathReactionsPhysics* const _this, int primitiveType, primitives::primitive& primitive, const Vec3& sweepDir, int objTypes, int geomFlags)>(0x1867600);
	static inline auto FIntersectionTestComplete = PreyFunction<void(CHitDeathReactionsPhysics* const _this, const unsigned& intID, const IntersectionTestResult& result)>(0x1865980);
};

// CHitDeathReactions
// Header:  Prey/GameDll/HitDeathReactions.h
class CHitDeathReactions
{ // Size=360 (0x168)
public:
	enum EExecutionType
	{
		eET_None = -1,
		eET_ReactionAnim = 0,
		eET_AnimationGraphAnim = 1,
		eET_Mannequin = 2,
		eET_Custom = 3,
	};

	enum EAIPausedState
	{
		eAIP_NotPaused = 0,
		eAIP_ExecutingCustomSignal = 1,
		eAIP_PipeUserPaused = 2,
	};

	enum EReactionType
	{
		eRT_None = -1,
		eRT_Hit = 0,
		eRT_Death = 1,
		eRT_Action = 2,
		eRT_Collision = 3,
	};

	// CHitDeathReactions::SCustomAnim
	// Header:  Prey/GameDll/HitDeathReactions.h
	struct SCustomAnim
	{ // Size=16 (0x10)
		int iLayer;
		float fOverrideTransTimeToAG;
		string sAnimName;

	#if 0
		SCustomAnim();
		void Invalidate();
		bool IsValid() const;
		void SetAnimName(int _arg0_, IAnimationSet* _arg1_);
		const string& GetAnimName() const;
	#endif
	};

	// CHitDeathReactions::SPredFindValidReaction
	// Header:  Prey/GameDll/HitDeathReactions.h
	struct SPredFindValidReaction : public std::unary_function<bool,SReactionParams const &>
	{ // Size=32 (0x20)
		const CHitDeathReactions& m_owner;
		const HitInfo& m_hitInfo;
		const ArkSignalSystem::Package* m_pPackage;
		const EReactionHitType m_hitReactionType;
		ArkNpcCustomHitReaction::Type m_customType;

		bool operator()(const SReactionParams& reactionParams) const { return FoperatorRBLRBR(this, reactionParams); }

	#if 0
		SPredFindValidReaction(const CHitDeathReactions& _arg0_, const HitInfo& _arg1_, const ArkSignalSystem::Package* _arg2_, EReactionHitType _arg3_, ArkNpcCustomHitReaction::Type _arg4_);
		bool EvaluateValidationParams(const SReactionParams::SValidationParams& _arg0_, const SReactionParams& _arg1_) const;
	#endif

		static inline auto FoperatorRBLRBR = PreyFunction<bool(const CHitDeathReactions::SPredFindValidReaction* const _this, const SReactionParams& reactionParams)>(0x1864050);
	};

	IScriptSystem* m_pScriptSystem;
	std::shared_ptr<const std::vector<SReactionParams>> m_pDeathReactions;
	std::shared_ptr<const std::vector<SReactionParams>> m_pHitReactions;
	std::shared_ptr<const std::vector<SReactionParams>> m_pCollisionReactions;
	std::shared_ptr<const SHitDeathReactionsConfig> m_pHitDeathReactionsConfig;
	unsigned m_profileId;
	SmartScriptTable m_pSelfTable;
	CCryActor& m_actor;
	CMTRand_int32& m_pseudoRandom;
	float m_fReactionCounter;
	float m_fReactionEndTime;
	int m_iGoalPipeId;
	CHitDeathReactions::EAIPausedState m_AIPausedState;
	CHitDeathReactions::EExecutionType m_currentExecutionType;
	CHitDeathReactions::SCustomAnim m_currentCustomAnim;
	CHitDeathReactions::EReactionType m_currentReaction;
	EReactionHitType m_currentHitType;
	const HitInfo* m_pHitInfo;
	HitInfo m_lastHitInfo;
	CHitDeathReactionsPhysics m_primitiveIntersectionQueue;
	unsigned m_effectorChannel;
	STagState<12> m_postDeathTagRagdoll;
	const SReactionParams* m_pCurrentReactionParams;
	_smart_ptr<IAction> m_pAction;
	bool m_bInSmartObject;
	bool m_bHandledReactionThisFrame;
	uint8_t m_reactionOnCollision;
	uint8_t m_reactionFlags;

	CHitDeathReactions(CCryActor& actor);
	void Update(float fFrameTime) { FUpdate(this, fFrameTime); }
	bool OnKill(const CCryActor::KillParams& killParams, const ArkSignalSystem::Package* _pPackage, ArkNpcCustomHitReaction::Type _customType) { return FOnKillOv1(this, killParams, _pPackage, _customType); }
	bool OnKill(const HitInfo& hitInfo, const ArkSignalSystem::Package* _pPackage, ArkNpcCustomHitReaction::Type _customType) { return FOnKillOv0(this, hitInfo, _pPackage, _customType); }
	bool OnAnimationEvent(const AnimEventInstance& event) { return FOnAnimationEvent(this, event); }
	bool HandleEvent(const SGameObjectEvent& event) { return FHandleEvent(this, event); }
	void OnRevive() { FOnRevive(this); }
	void OnActorReused() { FOnActorReused(this); }
	void OnActorReturned() { FOnActorReturned(this); }
	void FullSerialize(TSerialize ser) { FFullSerialize(this, ser); }
	void PostSerialize() { FPostSerialize(this); }
	void RequestReactionAnims(unsigned requestFlags) { FRequestReactionAnims(this, requestFlags); }
	void ReleaseReactionAnims(unsigned requestFlags) { FReleaseReactionAnims(this, requestFlags); }
	void Reload() { FReload(this); }
	bool StartReaction(CHitDeathReactions::EReactionType reactionType, const HitInfo& hitInfo, const SReactionParams& reactionParams) { return FStartReaction(this, reactionType, hitInfo, reactionParams); }
	void StartCollisionReaction(const Vec3& vNormal, const Vec3& vPoint) { FStartCollisionReactionOv0(this, vNormal, vPoint); }
	bool ExecuteHitReaction(const SmartScriptTable pScriptTable) { return FExecuteHitReactionOv0(this, pScriptTable); }
	bool ExecuteDeathReaction(const SReactionParams& reactionParams) { return FExecuteDeathReactionOv1(this, reactionParams); }
	bool ExecuteDeathReaction(const SmartScriptTable pScriptTable) { return FExecuteDeathReactionOv0(this, pScriptTable); }
	bool EndCurrentReaction() { return FEndCurrentReaction(this); }
	void OnRagdollize(bool forceFallback) { FOnRagdollize(this, forceFallback); }
	bool StartReactionAnim(const string& sAnimName, bool bLoop, float fBlendTime, int iSlot, int iLayer, unsigned animFlags, float fAdditiveWeight, float fAniSpeed, bool bNoAnimCamera) { return FStartReactionAnim(this, sAnimName, bLoop, fBlendTime, iSlot, iLayer, animFlags, fAdditiveWeight, fAniSpeed, bNoAnimCamera); }
	bool StartReactionAnimByID(int animID, bool bLoop, float fBlendTime, int iSlot, int iLayer, unsigned animFlags, float fAdditiveWeight, float fAniSpeed, bool bNoAnimCamera) { return FStartReactionAnimByID(this, animID, bLoop, fBlendTime, iSlot, iLayer, animFlags, fAdditiveWeight, fAniSpeed, bNoAnimCamera); }
	void EndReactionAnim() { FEndReactionAnim(this); }
	bool IsPlayingReactionAnim() const { return FIsPlayingReactionAnim(this); }
	static int GetHitDeathFragmentID(const IActionController* piActionController) { return FGetHitDeathFragmentID(piActionController); }
	void GetMemoryUsage(ICrySizer* pSizer) const { FGetMemoryUsage(this, pSizer); }
	static bool CheckCardinalDirection2D(ECardinalDirection direction, const Vec2& vDir1, const Vec2& vDir2) { return FCheckCardinalDirection2D(direction, vDir1, vDir2); }
	void SetHitReactionAction(IAction* _pAction) { FSetHitReactionAction(this, _pAction); }
	void ClearState() { FClearState(this); }
	bool CanPlayDeathReaction() const { return FCanPlayDeathReaction(this); }
	bool EndCurrentReactionInternal(bool bForceRagdollOnHit, bool bFinished, bool bForceFinishMannequinAction) { return FEndCurrentReactionInternal(this, bForceRagdollOnHit, bFinished, bForceFinishMannequinAction); }
	bool ExecuteReactionCommon(const SReactionParams& reactionParams) { return FExecuteReactionCommon(this, reactionParams); }
	void PausePipeUser(bool bPause) { FPausePipeUser(this, bPause); }
	void LoadData(SmartScriptTable pSelfTable, bool bForceReload) { FLoadData(this, pSelfTable, bForceReload); }
	void OnCustomAnimFinished(bool bInterrupted) { FOnCustomAnimFinished(this, bInterrupted); }
	unsigned GetSynchedSeed(bool bKillReaction) const { return FGetSynchedSeed(this, bKillReaction); }
	float GetRandomProbability() const { return FGetRandomProbability(this); }
	bool SendAISignal(const char* szSignal, IAISignalExtraData* pData, bool bWaitOpOnly) const { return FSendAISignal(this, szSignal, pData, bWaitOpOnly); }
	bool IsValidReactionId(int reactionId) const { return FIsValidReactionId(this, reactionId); }
	const SReactionParams& GetReactionParamsById(int reactionId) const { return FGetReactionParamsById(this, reactionId); }
	bool StartFacialAnimation(ICharacterInstance* pCharacter, const char* szEffectorName, float fWeight, float fFadeTime) { return FStartFacialAnimation(this, pCharacter, szEffectorName, fWeight, fFadeTime); }

#if 0
	bool OnHit(const HitInfo& _arg0_, const ArkSignalSystem::Package* _arg1_, EReactionHitType _arg2_, ArkNpcCustomHitReaction::Type _arg3_);
	bool OnReaction(const HitInfo& _arg0_, int* _arg1_);
	void LogUsedAnimations(bool _arg0_);
	bool StartHitReaction(const HitInfo& _arg0_, const SReactionParams& _arg1_);
	bool StartDeathReaction(const HitInfo& _arg0_, const SReactionParams& _arg1_);
	bool StartCollisionReaction(const HitInfo& _arg0_, const SReactionParams& _arg1_);
	bool IsValidReaction(const HitInfo& _arg0_, const SReactionParams::SValidationParams& _arg1_, const ArkSignalSystem::Package* _arg2_, EReactionHitType _arg3_, ArkNpcCustomHitReaction::Type _arg4_) const;
	bool IsValidReaction(const HitInfo& _arg0_, const SmartScriptTable _arg1_, const ArkSignalSystem::Package* _arg2_, EReactionHitType _arg3_, ArkNpcCustomHitReaction::Type _arg4_) const;
	bool ExecuteHitReaction(const SReactionParams& _arg0_);
	bool IsInDeathReaction() const;
	bool IsInAction() const;
	bool IsInHitReaction() const;
	bool IsInReaction() const;
	bool AreReactionsForbidden() const;
	unsigned GetProfileId() const;
	bool CanActorMove() const;
	bool IsPlayingMannequinReactionAnim() const;
	static ECardinalDirection GetRelativeCardinalDirection2D(const Vec2& _arg0_, const Vec2& _arg1_);
	bool CanPlayHitReaction() const;
	bool DeathReactionEndsInRagdoll() const;
	void SetInReaction(CHitDeathReactions::EReactionType _arg0_);
	void SetExecutionType(CHitDeathReactions::EExecutionType _arg0_);
	bool IsExecutionType(CHitDeathReactions::EExecutionType _arg0_) const;
	void SetVariations(const std::vector<SReactionParams::SAnimGraphReaction::SVariationData>& _arg0_) const;
	bool ExecuteKnockdown();
	void EnableFirstPersonAnimation(bool _arg0_);
	void DoCollisionCheck();
	bool CustomAnimHasFinished() const;
	void StopHigherLayers(int _arg0_, int _arg1_, float _arg2_);
	bool IsAI() const;
	IPipeUser* GetAIPipeUser() const;
	void HandleAIStartReaction(const HitInfo& _arg0_, const SReactionParams& _arg1_);
	void HandleAIEndReaction();
	void HandleAIReactionInterrupted();
	string GetCurrentAGReactionAnimName() const;
	void StopFacialAnimation(ICharacterInstance* _arg0_, float _arg1_);
	bool DoesAnimEventWantToSleepRagdoll(const AnimEventInstance& _arg0_) const;
	void SleepRagdoll();
	STagState<12> MergeCurrentFragTagState(const IActionController* _arg0_, const int _arg1_, const STagState<12> _arg2_) const;
	unsigned GetRootScopeID(const IActionController* _arg0_, const int _arg1_, const STagState<12> _arg2_) const;
	void GeneratePostDeathTags();
#endif

	static inline auto FCHitDeathReactionsOv2 = PreyFunction<void(CHitDeathReactions* const _this, CCryActor& actor)>(0x1863DF0);
	static inline auto FUpdate = PreyFunction<void(CHitDeathReactions* const _this, float fFrameTime)>(0x1868AA0);
	static inline auto FOnKillOv1 = PreyFunction<bool(CHitDeathReactions* const _this, const CCryActor::KillParams& killParams, const ArkSignalSystem::Package* _pPackage, ArkNpcCustomHitReaction::Type _customType)>(0x1867030);
	static inline auto FOnKillOv0 = PreyFunction<bool(CHitDeathReactions* const _this, const HitInfo& hitInfo, const ArkSignalSystem::Package* _pPackage, ArkNpcCustomHitReaction::Type _customType)>(0x1866EA0);
	static inline auto FOnAnimationEvent = PreyFunction<bool(CHitDeathReactions* const _this, const AnimEventInstance& event)>(0x1866910);
	static inline auto FHandleEvent = PreyFunction<bool(CHitDeathReactions* const _this, const SGameObjectEvent& event)>(0x1865940);
	static inline auto FOnRevive = PreyFunction<void(CHitDeathReactions* const _this)>(0x18674A0);
	static inline auto FOnActorReused = PreyFunction<void(CHitDeathReactions* const _this)>(0x1866710);
	static inline auto FOnActorReturned = PreyFunction<void(CHitDeathReactions* const _this)>(0x18666D0);
	static inline auto FFullSerialize = PreyFunction<void(CHitDeathReactions* const _this, TSerialize ser)>(0x18654D0);
	static inline auto FPostSerialize = PreyFunction<void(CHitDeathReactions* const _this)>(0x18675D0);
	static inline auto FRequestReactionAnims = PreyFunction<void(CHitDeathReactions* const _this, unsigned requestFlags)>(0x1867920);
	static inline auto FReleaseReactionAnims = PreyFunction<void(CHitDeathReactions* const _this, unsigned requestFlags)>(0x1867860);
	static inline auto FReload = PreyFunction<void(CHitDeathReactions* const _this)>(0x18678B0);
	static inline auto FStartReaction = PreyFunction<bool(CHitDeathReactions* const _this, CHitDeathReactions::EReactionType reactionType, const HitInfo& hitInfo, const SReactionParams& reactionParams)>(0x1867EF0);
	static inline auto FStartCollisionReactionOv0 = PreyFunction<void(CHitDeathReactions* const _this, const Vec3& vNormal, const Vec3& vPoint)>(0x1867AC0);
	static inline auto FExecuteHitReactionOv0 = PreyFunction<bool(CHitDeathReactions* const _this, const SmartScriptTable pScriptTable)>(0x18650E0);
	static inline auto FExecuteDeathReactionOv1 = PreyFunction<bool(CHitDeathReactions* const _this, const SReactionParams& reactionParams)>(0x1864FC0);
	static inline auto FExecuteDeathReactionOv0 = PreyFunction<bool(CHitDeathReactions* const _this, const SmartScriptTable pScriptTable)>(0x1864FF0);
	static inline auto FEndCurrentReaction = PreyFunction<bool(CHitDeathReactions* const _this)>(0x1864890);
	static inline auto FOnRagdollize = PreyFunction<void(CHitDeathReactions* const _this, bool forceFallback)>(0x1867280);
	static inline auto FStartReactionAnim = PreyFunction<bool(CHitDeathReactions* const _this, const string& sAnimName, bool bLoop, float fBlendTime, int iSlot, int iLayer, unsigned animFlags, float fAdditiveWeight, float fAniSpeed, bool bNoAnimCamera)>(0x1868300);
	static inline auto FStartReactionAnimByID = PreyFunction<bool(CHitDeathReactions* const _this, int animID, bool bLoop, float fBlendTime, int iSlot, int iLayer, unsigned animFlags, float fAdditiveWeight, float fAniSpeed, bool bNoAnimCamera)>(0x1868500);
	static inline auto FEndReactionAnim = PreyFunction<void(CHitDeathReactions* const _this)>(0x1864F90);
	static inline auto FIsPlayingReactionAnim = PreyFunction<bool(const CHitDeathReactions* const _this)>(0x1865BB0);
	static inline auto FGetHitDeathFragmentID = PreyFunction<int(const IActionController* piActionController)>(0x1865590);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CHitDeathReactions* const _this, ICrySizer* pSizer)>(0x1865600);
	static inline auto FCheckCardinalDirection2D = PreyFunction<bool(ECardinalDirection direction, const Vec2& vDir1, const Vec2& vDir2)>(0x18646B0);
	static inline auto FSetHitReactionAction = PreyFunction<void(CHitDeathReactions* const _this, IAction* _pAction)>(0x1867A60);
	static inline auto FClearState = PreyFunction<void(CHitDeathReactions* const _this)>(0x18647C0);
	static inline auto FCanPlayDeathReaction = PreyFunction<bool(const CHitDeathReactions* const _this)>(0x1864400);
	static inline auto FEndCurrentReactionInternal = PreyFunction<bool(CHitDeathReactions* const _this, bool bForceRagdollOnHit, bool bFinished, bool bForceFinishMannequinAction)>(0x18648A0);
	static inline auto FExecuteReactionCommon = PreyFunction<bool(CHitDeathReactions* const _this, const SReactionParams& reactionParams)>(0x18651D0);
	static inline auto FPausePipeUser = PreyFunction<void(CHitDeathReactions* const _this, bool bPause)>(0x1867500);
	static inline auto FLoadData = PreyFunction<void(CHitDeathReactions* const _this, SmartScriptTable pSelfTable, bool bForceReload)>(0x1866390);
	static inline auto FOnCustomAnimFinished = PreyFunction<void(CHitDeathReactions* const _this, bool bInterrupted)>(0x1866AA0);
	static inline auto FGetSynchedSeed = PreyFunction<unsigned(const CHitDeathReactions* const _this, bool bKillReaction)>(0x1865860);
	static inline auto FGetRandomProbability = PreyFunction<float(const CHitDeathReactions* const _this)>(0x18656A0);
	static inline auto FSendAISignal = PreyFunction<bool(const CHitDeathReactions* const _this, const char* szSignal, IAISignalExtraData* pData, bool bWaitOpOnly)>(0x1867970);
	static inline auto FIsValidReactionId = PreyFunction<bool(const CHitDeathReactions* const _this, int reactionId)>(0x1866280);
	static inline auto FGetReactionParamsById = PreyFunction<const SReactionParams& (const CHitDeathReactions* const _this, int reactionId)>(0x1865750);
	static inline auto FStartFacialAnimation = PreyFunction<bool(CHitDeathReactions* const _this, ICharacterInstance* pCharacter, const char* szEffectorName, float fWeight, float fFadeTime)>(0x1867E10);
};
#endif // MOONCRASH
