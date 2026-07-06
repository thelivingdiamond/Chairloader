// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/arkdeferredaction.h>
#include <Prey/CrySystem/TimeValue.h>
#include <_unknown/ArkDeferredActionImpl_RayCast.h>
#include <_unknown/RayCastQueue.h>

struct AABB;
struct IEntity;
struct RayCastRequest;
struct RayCastResult;

// ArkNpcThrowPropManager
// Header:  Prey/GameDll/ark/npc/ArkNpcThrowPropManager.h
class ArkNpcThrowPropManager
{ // Size=112 (0x70)
public:
	// ArkNpcThrowPropManager::QueryParams
	// Header:  Prey/GameDll/ark/npc/ArkNpcThrowPropManager.h
	struct QueryParams
	{ // Size=36 (0x24)
		float m_maxDistanceFromTarget;
		float m_minDistanceFromTarget;
		float m_minHeight;
		float m_maxHeight;
		float m_minMass;
		float m_maxMass;
		float m_clusterMaxDistance;
		float m_clusterMaxMass;
		float m_clusterMaxMassDifference;

	#if 0
		QueryParams();
	#endif
	};

	// ArkNpcThrowPropManager::DeferredRayCastImpl
	// Header:  Prey/GameDll/ark/npc/ArkNpcThrowPropManager.h
	class DeferredRayCastImpl : public ArkDeferredActionImpl_RayCast<RayCastQueue<41> >
	{ // Size=8 (0x8)
	public:
		unsigned m_propId;
		bool m_bHasPriority;

	#if 0
		DeferredRayCastImpl();
		DeferredRayCastImpl(unsigned _arg0_);
		RayCastQueue<41>& GetQueue() const;
		bool GetRequest(RayCastRequest& _arg0_) const;
		void OnAborted();
		void OnResult(const RayCastResult& _arg0_);
	#endif
	};

	// ArkNpcThrowPropManager::PropData
	// Header:  Prey/GameDll/ark/npc/ArkNpcThrowPropManager.h
	struct PropData
	{ // Size=392 (0x188)
		CTimeValue m_lastFailTime;
		Vec3 m_pos;
		Vec3 m_lastTestPos;
		float m_lastTestTimer;
		float m_distToTarget;
		float m_mass;
		bool m_bHasLos;
		ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl> m_los;

		PropData(const ArkNpcThrowPropManager::PropData& _other);

	#if 0
		PropData();
	#endif

		static inline auto FPropDataOv0 = PreyFunction<void(ArkNpcThrowPropManager::PropData* const _this, const ArkNpcThrowPropManager::PropData& _other)>(0x129A020);
	};

	using DeferredRayCast = ArkDeferredAction<ArkNpcThrowPropManager::DeferredRayCastImpl>;
	using PropDataMap = std::map<unsigned int, ArkNpcThrowPropManager::PropData>;
	using PropDataMapPair = std::pair<unsigned int, ArkNpcThrowPropManager::PropData>;

	static inline auto s_kMassMin = PreyGlobal<const float>(0x1F47738);
	static inline auto s_kMassMax = PreyGlobal<const float>(0x1F4773C);
	static inline auto s_kDistMin = PreyGlobal<const float>(0x1F47740);
	static inline auto s_kDistMax = PreyGlobal<const float>(0x1F47744);
	static inline auto s_kVelMaxSqr = PreyGlobal<const float>(0x1F47748);
	static inline auto s_kAABBTestTime = PreyGlobal<const float>(0x1F4774C);
	static inline auto s_kMinLOSTestTime = PreyGlobal<const float>(0x1F47750);
	static inline auto s_kMaxLOSTestTime = PreyGlobal<const float>(0x1F47754);
	static inline auto s_kMaxLOSTestDist = PreyGlobal<const float>(0x1F47758);
	static inline auto s_kPropRetestDist = PreyGlobal<const float>(0x1F4775C);
	static inline auto s_kPropTestAboveDist = PreyGlobal<const float>(0x1F47760);
	static inline auto s_kPlayerRetestDist = PreyGlobal<const float>(0x1F47764);
	bool m_bHasUseParams;
	float m_aabbTestTimer;
	Vec3 m_lastTargetTestPos;
	Vec3 m_targetPos;
	ArkNpcThrowPropManager::QueryParams m_useParams;
	int m_detectCounter;
	std::map<unsigned int, ArkNpcThrowPropManager::PropData> m_props;
	std::vector<unsigned int> m_prioritizedProps;

	ArkNpcThrowPropManager();
	void Initialize() { FInitialize(this); }
	void Reset(bool _bStart) { FReset(this, _bStart); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void StartDetection() { FStartDetection(this); }
	void StopDetection() { FStopDetection(this); }
	void GetBestThrowableEntityIds(const Vec3& _sourcePos, const ArkNpcThrowPropManager::QueryParams& _params, std::vector<unsigned int>& _propIds) const { FGetBestThrowableEntityIds(this, _sourcePos, _params, _propIds); }
	bool HasLOS(unsigned _propId) const { return FHasLOS(this, _propId); }
	void AddPrioritizedProps(std::vector<unsigned int>& _propIds) { FAddPrioritizedProps(this, _propIds); }
	void RemovePrioritizedProps(std::vector<unsigned int>& _propIds) { FRemovePrioritizedProps(this, _propIds); }
	bool IsPrioritized(unsigned _propId) const { return FIsPrioritized(this, _propId); }
	void SetThrowFailed(const std::vector<unsigned int>& _propIds) { FSetThrowFailed(this, _propIds); }
	void FindProps(const AABB& _aabb) { FFindProps(this, _aabb); }
	float GetScore(IEntity* pPropEntity, const ArkNpcThrowPropManager::PropData& _data, const Vec3& _sourcePos, const ArkNpcThrowPropManager::QueryParams& _params, bool& _bInCluster) const { return FGetScore(this, pPropEntity, _data, _sourcePos, _params, _bInCluster); }

#if 0
	ArkNpcThrowPropManager(const ArkNpcThrowPropManager& _arg0_);
	bool GetUseQueryParams(ArkNpcThrowPropManager::QueryParams& _arg0_) const;
	void SetUseQueryParams(const ArkNpcThrowPropManager::QueryParams& _arg0_);
	void AddPrioritizedProp(unsigned _arg0_);
	void RemovePrioritizedProp(unsigned _arg0_);
	ArkNpcThrowPropManager& operator=(const ArkNpcThrowPropManager& _arg0_);
	const ArkNpcThrowPropManager::PropData& GetPropData(unsigned _arg0_);
	AABB GetSearchAABB(const Vec3& _arg0_) const;
	bool InCluster(IEntity* _arg0_, const ArkNpcThrowPropManager::PropData& _arg1_, const ArkNpcThrowPropManager::QueryParams& _arg2_) const;
	void GetCluster(IEntity* _arg0_, const ArkNpcThrowPropManager::PropData& _arg1_, const ArkNpcThrowPropManager::QueryParams& _arg2_, std::vector<unsigned int>& _arg3_) const;
	float GetMass(IEntity* _arg0_) const;
#endif

	static inline auto FArkNpcThrowPropManagerOv1 = PreyFunction<void(ArkNpcThrowPropManager* const _this)>(0x1299FB0);
	static inline auto FInitialize = PreyFunction<void(ArkNpcThrowPropManager* const _this)>(0x1333E90);
	static inline auto FReset = PreyFunction<void(ArkNpcThrowPropManager* const _this, bool _bStart)>(0x129B790);
	static inline auto FUpdate = PreyFunction<void(ArkNpcThrowPropManager* const _this, float _elapsedTime)>(0x129B9C0);
	static inline auto FStartDetection = PreyFunction<void(ArkNpcThrowPropManager* const _this)>(0x129B950);
	static inline auto FStopDetection = PreyFunction<void(ArkNpcThrowPropManager* const _this)>(0x129B960);
	static inline auto FGetBestThrowableEntityIds = PreyFunction<void(const ArkNpcThrowPropManager* const _this, const Vec3& _sourcePos, const ArkNpcThrowPropManager::QueryParams& _params, std::vector<unsigned int>& _propIds)>(0x129AC90);
	static inline auto FHasLOS = PreyFunction<bool(const ArkNpcThrowPropManager* const _this, unsigned _propId)>(0x129B390);
	static inline auto FAddPrioritizedProps = PreyFunction<void(ArkNpcThrowPropManager* const _this, std::vector<unsigned int>& _propIds)>(0x129A0B0);
	static inline auto FRemovePrioritizedProps = PreyFunction<void(ArkNpcThrowPropManager* const _this, std::vector<unsigned int>& _propIds)>(0x129B720);
	static inline auto FIsPrioritized = PreyFunction<bool(const ArkNpcThrowPropManager* const _this, unsigned _propId)>(0x129B3E0);
	static inline auto FSetThrowFailed = PreyFunction<void(ArkNpcThrowPropManager* const _this, const std::vector<unsigned int>& _propIds)>(0x129B8C0);
	static inline auto FFindProps = PreyFunction<void(ArkNpcThrowPropManager* const _this, const AABB& _aabb)>(0x129A430);
	static inline auto FGetScore = PreyFunction<float(const ArkNpcThrowPropManager* const _this, IEntity* pPropEntity, const ArkNpcThrowPropManager::PropData& _data, const Vec3& _sourcePos, const ArkNpcThrowPropManager::QueryParams& _params, bool& _bInCluster)>(0x129B000);
};
#endif // MOONCRASH
