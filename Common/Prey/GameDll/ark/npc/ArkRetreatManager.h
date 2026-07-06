// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct AABB;
class ArkNpc;
struct ArkSearchBounds;
class CArkRetreatPoint;
struct IEntity;

// ArkRetreatManager
// Header:  Prey/GameDll/ark/npc/ArkRetreatManager.h
class ArkRetreatManager
{ // Size=64 (0x40)
public:
	// ArkRetreatManager::RetreatEntityInfo
	// Header:  Prey/GameDll/ark/npc/ArkRetreatManager.h
	struct RetreatEntityInfo
	{ // Size=16 (0x10)
		const IEntity* m_pEntity;
		bool m_bReserved;

	#if 0
		RetreatEntityInfo();
		RetreatEntityInfo(const IEntity& _arg0_);
	#endif
	};

	// ArkRetreatManager::RetreatEntityInfoContainsEntity
	// Header:  Prey/GameDll/ark/npc/ArkRetreatManager.h
	struct RetreatEntityInfoContainsEntity
	{ // Size=4 (0x4)
		unsigned m_entityId;

	#if 0
		RetreatEntityInfoContainsEntity(const IEntity& _arg0_);
		RetreatEntityInfoContainsEntity(const unsigned _arg0_);
		bool operator()(const ArkRetreatManager::RetreatEntityInfo& _arg0_) const;
	#endif
	};

	using ReserveDistractionResult = std::tuple<unsigned int,Vec3_tpl<float> >;
	using RetreatEntityInfoVector = std::vector<ArkRetreatManager::RetreatEntityInfo>;
	using RetreatEntityInfoPtrVector = std::vector<ArkRetreatManager::RetreatEntityInfo*>;

	std::vector<ArkRetreatManager::RetreatEntityInfo> m_retreatPoints;
	std::vector<ArkRetreatManager::RetreatEntityInfo> m_distractions;
	static constexpr const int s_numStaleEntities = 3;
	std::array<unsigned int, 3> m_lastReservedRetreatEntityIds;
	int m_lastReservedRetreatEntityIndex;

	ArkRetreatManager();
	void AddRetreatPoint(const CArkRetreatPoint& _retreatPoint) { FAddRetreatPoint(this, _retreatPoint); }
	void RemoveRetreatPoint(const CArkRetreatPoint& _retreatPoint) { FRemoveRetreatPoint(this, _retreatPoint); }
	void SafeAddDistraction(const IEntity& _distractionEntity) { FSafeAddDistraction(this, _distractionEntity); }
	void SafeRemoveDistraction(const IEntity& _distractionEntity) { FSafeRemoveDistraction(this, _distractionEntity); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void RemoveAllDistractions() { FRemoveAllDistractions(this); }
	unsigned ReserveRetreatPointInRanges(ArkNpc& _retreatingNpc, float _minimumDistanceFromRetreatingNpc, const AABB& _outerSearchBounds, const AABB& _exclusionSearchBounds) { return FReserveRetreatPointInRanges(this, _retreatingNpc, _minimumDistanceFromRetreatingNpc, _outerSearchBounds, _exclusionSearchBounds); }
	void ReleaseRetreatPoint(unsigned _retreatPointEntityId) { FReleaseRetreatPoint(this, _retreatPointEntityId); }
	std::tuple<unsigned int,Vec3_tpl<float> > ReserveDistractionInRange(ArkNpc& _retreatingNpc, const AABB& _searchBounds, const ArkSearchBounds& _navPointSearchBounds) { alignas(std::tuple<unsigned int,Vec3_tpl<float> >) std::byte _return_buf_[sizeof(std::tuple<unsigned int,Vec3_tpl<float> >)]; return *FReserveDistractionInRange(this, reinterpret_cast<std::tuple<unsigned int,Vec3_tpl<float> >*>(_return_buf_), _retreatingNpc, _searchBounds, _navPointSearchBounds); }
	void ReleaseDistraction(unsigned _distractionEntityId) { FReleaseDistraction(this, _distractionEntityId); }
	static void RemoveEntity(std::vector<ArkRetreatManager::RetreatEntityInfo>& _entityInfos, const IEntity& _entity) { FRemoveEntity(_entityInfos, _entity); }
	static std::vector<ArkRetreatManager::RetreatEntityInfo*>& GetUnreservedEntitiesInRange(std::vector<ArkRetreatManager::RetreatEntityInfo>& _entityInfos, const AABB& _searchBounds) { return FGetUnreservedEntitiesInRange(_entityInfos, _searchBounds); }

#if 0
	ArkRetreatManager(const ArkRetreatManager& _arg0_);
	bool HasRetreatPoint(const CArkRetreatPoint& _arg0_) const;
	void AddDistraction(const IEntity& _arg0_);
	void RemoveDistraction(const IEntity& _arg0_);
	bool HasDistraction(const IEntity& _arg0_) const;
	unsigned ReserveAnyRetreatPoint(ArkNpc& _arg0_);
	unsigned FindNearestRetreatPoint(ArkNpc& _arg0_);
	std::tuple<unsigned int,Vec3_tpl<float> > ReserveAnyDistraction(ArkNpc& _arg0_, const ArkSearchBounds& _arg1_);
	bool HasEntityBeenRecentlyReserved(const unsigned _arg0_) const;
	void AddRecentlyReservedEntity(const unsigned _arg0_);
	void ResetRecentlyReservedRetreatEntityIds();
	static void AddEntity(std::vector<ArkRetreatManager::RetreatEntityInfo>& _arg0_, const IEntity& _arg1_);
	static void SafeAddEntity(std::vector<ArkRetreatManager::RetreatEntityInfo>& _arg0_, const IEntity& _arg1_);
	static void SafeRemoveEntity(std::vector<ArkRetreatManager::RetreatEntityInfo>& _arg0_, const IEntity& _arg1_);
	static bool HasEntity(const std::vector<ArkRetreatManager::RetreatEntityInfo>& _arg0_, const IEntity& _arg1_);
	static std::vector<ArkRetreatManager::RetreatEntityInfo*>& GetUnreservedEntities(std::vector<ArkRetreatManager::RetreatEntityInfo>& _arg0_);
	static void ReleaseEntity(std::vector<ArkRetreatManager::RetreatEntityInfo>& _arg0_, unsigned _arg1_);
	ArkRetreatManager& operator=(const ArkRetreatManager& _arg0_);
#endif

	static inline auto FArkRetreatManagerOv1 = PreyFunction<void(ArkRetreatManager* const _this)>(0x129D010);
	static inline auto FAddRetreatPoint = PreyFunction<void(ArkRetreatManager* const _this, const CArkRetreatPoint& _retreatPoint)>(0x129D040);
	static inline auto FRemoveRetreatPoint = PreyFunction<void(ArkRetreatManager* const _this, const CArkRetreatPoint& _retreatPoint)>(0x129D300);
	static inline auto FSafeAddDistraction = PreyFunction<void(ArkRetreatManager* const _this, const IEntity& _distractionEntity)>(0x129D700);
	static inline auto FSafeRemoveDistraction = PreyFunction<void(ArkRetreatManager* const _this, const IEntity& _distractionEntity)>(0x129D790);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkRetreatManager* const _this)>(0x129D1A0);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkRetreatManager* const _this)>(0x129D1A0);
	static inline auto FRemoveAllDistractions = PreyFunction<void(ArkRetreatManager* const _this)>(0x129D270);
	static inline auto FReserveRetreatPointInRanges = PreyFunction<unsigned(ArkRetreatManager* const _this, ArkNpc& _retreatingNpc, float _minimumDistanceFromRetreatingNpc, const AABB& _outerSearchBounds, const AABB& _exclusionSearchBounds)>(0x129D540);
	static inline auto FReleaseRetreatPoint = PreyFunction<void(ArkRetreatManager* const _this, unsigned _retreatPointEntityId)>(0x129D210);
	static inline auto FReserveDistractionInRange = PreyFunction<std::tuple<unsigned int,Vec3_tpl<float> >*(ArkRetreatManager* const _this, std::tuple<unsigned int,Vec3_tpl<float> >* _return_value_, ArkNpc& _retreatingNpc, const AABB& _searchBounds, const ArkSearchBounds& _navPointSearchBounds)>(0x129D310);
	static inline auto FReleaseDistraction = PreyFunction<void(ArkRetreatManager* const _this, unsigned _distractionEntityId)>(0x129D1B0);
	static inline auto FRemoveEntity = PreyFunction<void(std::vector<ArkRetreatManager::RetreatEntityInfo>& _entityInfos, const IEntity& _entity)>(0x129D280);
	static inline auto FGetUnreservedEntitiesInRange = PreyFunction<std::vector<ArkRetreatManager::RetreatEntityInfo*>& (std::vector<ArkRetreatManager::RetreatEntityInfo>& _entityInfos, const AABB& _searchBounds)>(0x129D050);
};
#endif // MOONCRASH
