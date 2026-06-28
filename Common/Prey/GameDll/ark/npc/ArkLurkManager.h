// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct AABB;
class ArkNpc;
class CArkLurkPoint;

// ArkLurkManager
// Header:  Prey/GameDll/ark/npc/ArkLurkManager.h
class ArkLurkManager
{ // Size=24 (0x18)
public:
	// ArkLurkManager::LurkPointInfo
	// Header:  Prey/GameDll/ark/npc/ArkLurkManager.h
	struct LurkPointInfo
	{ // Size=16 (0x10)
		const CArkLurkPoint* m_pLurkPoint;
		bool m_bReserved;

	#if 0
		LurkPointInfo();
		LurkPointInfo(const CArkLurkPoint& _arg0_);
	#endif
	};

	// ArkLurkManager::LurkPointInfoContainsLurkPoint
	// Header:  Prey/GameDll/ark/npc/ArkLurkManager.h
	struct LurkPointInfoContainsLurkPoint
	{ // Size=4 (0x4)
		unsigned m_entityId;

	#if 0
		LurkPointInfoContainsLurkPoint(const CArkLurkPoint& _arg0_);
		LurkPointInfoContainsLurkPoint(const unsigned _arg0_);
		bool operator()(const ArkLurkManager::LurkPointInfo& _arg0_) const;
	#endif
	};

	std::vector<ArkLurkManager::LurkPointInfo> m_lurkPoints;

	ArkLurkManager();
	void AddLurkPoint(const CArkLurkPoint& _lurkPoint) { FAddLurkPoint(this, _lurkPoint); }
	void RemoveLurkPoint(const CArkLurkPoint& _lurkPoint) { FRemoveLurkPoint(this, _lurkPoint); }
	void Refresh() { FRefresh(this); }
	bool ReserveSpecificLurkPoint(unsigned _lurkPointEntityId) { return FReserveSpecificLurkPoint(this, _lurkPointEntityId); }
	unsigned ReserveLurkPoint(ArkNpc& _lurkingNpc, const float _minSearchDistance, const AABB& _searchBounds, const AABB& _exclusionBounds) { return FReserveLurkPoint(this, _lurkingNpc, _minSearchDistance, _searchBounds, _exclusionBounds); }
	void ReleaseLurkPoint(unsigned _lurkPointEntityId) { FReleaseLurkPoint(this, _lurkPointEntityId); }

#if 0
	ArkLurkManager(const ArkLurkManager& _arg0_);
	bool HasLurkPoint(const CArkLurkPoint& _arg0_) const;
	ArkLurkManager& operator=(const ArkLurkManager& _arg0_);
	static std::vector<ArkLurkManager::LurkPointInfo*>& GetUnreservedEntitiesInRange(std::vector<ArkLurkManager::LurkPointInfo>& _arg0_, const AABB& _arg1_);
	static std::vector<ArkLurkManager::LurkPointInfo*>& GetUnreservedEntities(std::vector<ArkLurkManager::LurkPointInfo>& _arg0_);
#endif

	static inline auto FArkLurkManagerOv1 = PreyFunction<void(ArkLurkManager* const _this)>(0x1F4DF0);
	static inline auto FAddLurkPoint = PreyFunction<void(ArkLurkManager* const _this, const CArkLurkPoint& _lurkPoint)>(0x1280A90);
	static inline auto FRemoveLurkPoint = PreyFunction<void(ArkLurkManager* const _this, const CArkLurkPoint& _lurkPoint)>(0x1280B10);
	static inline auto FRefresh = PreyFunction<void(ArkLurkManager* const _this)>(0x1333E90);
	static inline auto FReserveSpecificLurkPoint = PreyFunction<bool(ArkLurkManager* const _this, unsigned _lurkPointEntityId)>(0x1281000);
	static inline auto FReserveLurkPoint = PreyFunction<unsigned(ArkLurkManager* const _this, ArkNpc& _lurkingNpc, const float _minSearchDistance, const AABB& _searchBounds, const AABB& _exclusionBounds)>(0x1280B90);
	static inline auto FReleaseLurkPoint = PreyFunction<void(ArkLurkManager* const _this, unsigned _lurkPointEntityId)>(0x1280AA0);
};
#endif // MOONCRASH
