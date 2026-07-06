// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryAction/SharedParams/ISharedParams.h>
#include <Prey/CryAction/SharedParams/SharedParamsTypeInfo.h>
#include <_unknown/VectorSet.h>
#include <_unknown/pe_action_arkimpulse.h>

class CCryActor;
struct IItemParamsNode;
struct SHitImpulse;

// CActorImpulseHandler
// Header:  Prey/GameDll/ActorImpulseHandler.h
class CActorImpulseHandler
{ // Size=880 (0x370)
public:
	enum class EImpulseState
	{
		Imp_None = 0,
		Imp_Impulse = 1,
		Imp_Recovery = 2,
	};

	// CActorImpulseHandler::SImpulseSet
	// Header:  Prey/GameDll/ActorImpulseHandler.h
	struct SImpulseSet
	{ // Size=104 (0x68)
		// CActorImpulseHandler::SImpulseSet::SImpulse
		// Header:  Prey/GameDll/ActorImpulseHandler.h
		struct SImpulse
		{ // Size=24 (0x18)
			int iPartID;
			Vec3 vDirection;
			float fStrength;
			bool bUseDirection;
			bool bUseStrength;

		#if 0
			SImpulse();
		#endif
		};

		using ImpulseContainer = std::vector<CActorImpulseHandler::SImpulseSet::SImpulse>;
		using IDContainer = VectorSet<int,std::less<int>,std::allocator<int> >;

		VectorSet<int,std::less<int>,std::allocator<int> > allowedHitTypes;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedBulletTypes;
		VectorSet<int,std::less<int>,std::allocator<int> > allowedPartIDs;
		float fAngularImpulseScale;
		std::vector<CActorImpulseHandler::SImpulseSet::SImpulse> impulses;

		bool MatchesHitInfo(const HitInfo& hitInfo) const { return FMatchesHitInfo(this, hitInfo); }

	#if 0
		SImpulseSet();
	#endif

		static inline auto FMatchesHitInfo = PreyFunction<bool(const CActorImpulseHandler::SImpulseSet* const _this, const HitInfo& hitInfo)>(0x10BE2C0);
	};

	// CActorImpulseHandler::SSharedImpulseHandlerParams
	// Header:  Prey/GameDll/ActorImpulseHandler.h
	struct SSharedImpulseHandlerParams : public ISharedParams
	{ // Size=40 (0x28)
		static inline auto s_typeInfo = PreyGlobal<const CSharedParamsTypeInfo>(0x23DF320);
		float fMaxRagdollImpulse;
		float fMass;
		std::vector<CActorImpulseHandler::SImpulseSet> impulseSets;

		virtual ISharedParams* Clone() const;
		virtual const CSharedParamsTypeInfo& GetTypeInfo() const;

	#if 0
		SSharedImpulseHandlerParams();
	#endif

		static inline auto FClone = PreyFunction<ISharedParams* (const CActorImpulseHandler::SSharedImpulseHandlerParams* const _this)>(0x10BCBF0);
		static inline auto FGetTypeInfo = PreyFunction<const CSharedParamsTypeInfo& (const CActorImpulseHandler::SSharedImpulseHandlerParams* const _this)>(0x10BCC50);
	};

	// CActorImpulseHandler::QueuedDeathImpulse
	// Header:  Prey/GameDll/ActorImpulseHandler.h
	struct QueuedDeathImpulse
	{ // Size=112 (0x70)
		HitInfo hitInfo;
		float timeOut;
	};

	// CActorImpulseHandler::SFindMatchingSet
	// Header:  Prey/GameDll/ActorImpulseHandler.h
	struct SFindMatchingSet : public std::unary_function<bool,CActorImpulseHandler::SImpulseSet const &>
	{ // Size=8 (0x8)
		const HitInfo& hitInfo;

	#if 0
		SFindMatchingSet(const HitInfo& _arg0_);
		bool operator()(const CActorImpulseHandler::SImpulseSet& _arg0_) const;
	#endif
	};

	using ImpulseSetsContainer = std::vector<CActorImpulseHandler::SImpulseSet>;
	using SSharedImpulseHandlerParamsPtr = std::shared_ptr<CActorImpulseHandler::SSharedImpulseHandlerParams>;
	using SSharedImpulseHandlerParamsConstPtr = std::shared_ptr<const CActorImpulseHandler::SSharedImpulseHandlerParams>;
	using SSharedImpulseHandlerParamsWeakPtr = std::weak_ptr<CActorImpulseHandler::SSharedImpulseHandlerParams>;
	using SSharedImpulseHandlerParamsConstWeakPtr = std::weak_ptr<CActorImpulseHandler::SSharedImpulseHandlerParams const >;

	static constexpr const int NUM_JOINTS = 3;
	CCryActor& m_actor;
	std::shared_ptr<const CActorImpulseHandler::SSharedImpulseHandlerParams> m_pParams;
	std::shared_ptr<IAnimationOperatorQueue> m_poseModifier;
	CActorImpulseHandler::QueuedDeathImpulse m_queuedDeathImpulse;
	static constexpr const int s_kImpulseFrameHistorySize = 10;
	std::array<pe_action_arkimpulse, 10> m_postRagdollImpulses;
	int m_ragdollImpulseFrameIndex;
	bool m_delayedDeathImpulse;
	int m_jointIdx[3];
	Quat m_targetOffsets[3];
	Quat m_initialOffsets[3];
	float m_impulseTime;
	float m_impulseDuration;
	CActorImpulseHandler::EImpulseState m_impulseState;

	CActorImpulseHandler(CCryActor& actor);
	void ReadXmlData(const IItemParamsNode* pRootNode) { FReadXmlData(this, pRootNode); }
	void AddLocalHitImpulse(const SHitImpulse& hitImpulse) { FAddLocalHitImpulse(this, hitImpulse); }
	void ApplyDeathImpulse(const HitInfo& lastHit) { FApplyDeathImpulse(this, lastHit); }
	void QueueDeathImpulse(const HitInfo& hitInfo, const float delay) { FQueueDeathImpulse(this, hitInfo, delay); }
	void SetOnRagdollPhysicalizedImpulse(const pe_action_arkimpulse& impulse) { FSetOnRagdollPhysicalizedImpulse(this, impulse); }
	void Update(float frameTime) { FUpdate(this, frameTime); }
	void UpdateDeath(float frameTime) { FUpdateDeath(this, frameTime); }
	void OnRagdollPhysicalized() { FOnRagdollPhysicalized(this); }
	void ApplyDeathAngularImpulse(float fAngularImpulseScale, const Vec3& hitpos, const Vec3& playerPos, const HitInfo& lastHit) { FApplyDeathAngularImpulse(this, fAngularImpulseScale, hitpos, playerPos, lastHit); }
	void LoadDeathImpulses(const IItemParamsNode* pDeathImpulses, std::vector<CActorImpulseHandler::SImpulseSet>& impulseSets) { FLoadDeathImpulses(this, pDeathImpulses, impulseSets); }
	void ClearOnRagdollPhysicalizedImpulse() { FClearOnRagdollPhysicalizedImpulse(this); }

#if 0
	void AddOnRagdollPhysicalizedImpulse(const pe_action_arkimpulse& _arg0_);
#endif

	static inline auto FCActorImpulseHandlerOv2 = PreyFunction<void(CActorImpulseHandler* const _this, CCryActor& actor)>(0x10BB320);
	static inline auto FReadXmlData = PreyFunction<void(CActorImpulseHandler* const _this, const IItemParamsNode* pRootNode)>(0x10BE620);
	static inline auto FAddLocalHitImpulse = PreyFunction<void(CActorImpulseHandler* const _this, const SHitImpulse& hitImpulse)>(0x10BB440);
	static inline auto FApplyDeathImpulse = PreyFunction<void(CActorImpulseHandler* const _this, const HitInfo& lastHit)>(0x10BC6C0);
	static inline auto FQueueDeathImpulse = PreyFunction<void(CActorImpulseHandler* const _this, const HitInfo& hitInfo, const float delay)>(0x10BE5C0);
	static inline auto FSetOnRagdollPhysicalizedImpulse = PreyFunction<void(CActorImpulseHandler* const _this, const pe_action_arkimpulse& impulse)>(0x10BF090);
	static inline auto FUpdate = PreyFunction<void(CActorImpulseHandler* const _this, float frameTime)>(0x10BF1C0);
	static inline auto FUpdateDeath = PreyFunction<void(CActorImpulseHandler* const _this, float frameTime)>(0x10BF830);
	static inline auto FOnRagdollPhysicalized = PreyFunction<void(CActorImpulseHandler* const _this)>(0x10BE410);
	static inline auto FApplyDeathAngularImpulse = PreyFunction<void(CActorImpulseHandler* const _this, float fAngularImpulseScale, const Vec3& hitpos, const Vec3& playerPos, const HitInfo& lastHit)>(0x10BC130);
	static inline auto FLoadDeathImpulses = PreyFunction<void(CActorImpulseHandler* const _this, const IItemParamsNode* pDeathImpulses, std::vector<CActorImpulseHandler::SImpulseSet>& impulseSets)>(0x10BCC60);
	static inline auto FClearOnRagdollPhysicalizedImpulse = PreyFunction<void(CActorImpulseHandler* const _this)>(0x10BCB30);
};
#endif // MOONCRASH
