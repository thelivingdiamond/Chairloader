// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <_unknown/TNavigationID.h>

class ArkNpc;
class CArkAreaContainer;
enum EEntityEvent;
struct IArea;
struct IEntity;
struct IEntityAreaProxy;

// ArkNpcAreaManager
// Header:  Prey/GameDll/ark/npc/ArkNpcAreaManager.h
class ArkNpcAreaManager : public IAreaManagerEventListener
{ // Size=184 (0xB8)
public:
	// ArkNpcAreaManager::AreaInfo
	// Header:  Prey/GameDll/ark/npc/ArkNpcAreaManager.h
	struct AreaInfo
	{ // Size=64 (0x40)
		int m_areaNavPointsIndex;
		float m_cachedArea;
		AABB m_cachedAreaAABB;
		std::vector<unsigned int> m_npcsInArea;
		int m_numCystoidsInArea;

	#if 0
		AreaInfo();
	#endif
	};

	using AreaIdToAreaInfoMap = std::unordered_map<unsigned int, ArkNpcAreaManager::AreaInfo>;
	using NavigationPoints = std::vector<Vec3>;
	using NavigationIndexSizePair = std::pair<int, int>;
	using NavigationPointIndices = std::vector<std::pair<int, int>>;

	std::unordered_map<unsigned int, ArkNpcAreaManager::AreaInfo> m_areaEntityIdToAreaInfoMap;
	std::vector<std::vector<std::pair<int, int>>> m_navAgentPointIndicesBuffer;
	std::vector<std::vector<Vec3>> m_navAgentPointsBuffer;
	std::vector<std::vector<std::pair<int, int>>> m_navAgentPointIndicesBufferNonBoundary;
	std::vector<std::vector<Vec3>> m_navAgentPointsBufferNonBoundary;
	float m_navMeshBoundaryUpTolerance;
	float m_navMeshBoundaryDownTolerance;
	float m_navMeshBoundaryHorizTolerance;

	ArkNpcAreaManager();
	virtual ~ArkNpcAreaManager();
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void Update(float _dt) { FUpdate(this, _dt); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void CacheAreasInContainer(CArkAreaContainer& _areaContainer) { FCacheAreasInContainer(this, _areaContainer); }
	bool IsInArea(const ArkNpc& _npc, unsigned _areaEntityId) const { return FIsInArea(this, _npc, _areaEntityId); }
	unsigned GetFirstAreaIn(const ArkNpc& _npc) const { return FGetFirstAreaIn(this, _npc); }
	unsigned GetAreasInRadius(const Vec3& _pos, float _radius, unsigned* _pOutAreas, unsigned _maxAreasCount) const { return FGetAreasInRadius(this, _pos, _radius, _pOutAreas, _maxAreasCount); }
	float GetArea2DArea(unsigned _areaEntityId) const { return FGetArea2DArea(this, _areaEntityId); }
	unsigned GetAreaNavPoints(unsigned _areaEntityId, TNavigationID<1> _navAgentId, bool _excludeBoundaryPoints, const Vec3* & _pOutPoints) const { return FGetAreaNavPoints(this, _areaEntityId, _navAgentId, _excludeBoundaryPoints, _pOutPoints); }
	void OnNpcDone(ArkNpc& _npc) { FOnNpcDone(this, _npc); }
	int GetNumCystoidsInArea(unsigned _areaEntityId) const { return FGetNumCystoidsInArea(this, _areaEntityId); }
	void PrecacheAllRoomVolumes() { FPrecacheAllRoomVolumes(this); }
	void PrecacheArea(IEntity& _areaEntity, IEntityAreaProxy& _area) { FPrecacheArea(this, _areaEntity, _area); }
	virtual void OnAreaManagerEvent(EEntityEvent _event, unsigned _triggerEntityID, IArea* _pArea);
	const ArkNpcAreaManager::AreaInfo* GetAreaInfo(const unsigned _areaEntityId) const { return FGetAreaInfo(this, _areaEntityId); }
	void CalculateAreaNavPoints(unsigned _areaEntityId, TNavigationID<1> _navAgentId, ArkNpcAreaManager::AreaInfo& _areaInfo) { FCalculateAreaNavPoints(this, _areaEntityId, _navAgentId, _areaInfo); }
	int GetNavigationAgentTypeIdIndex(TNavigationID<1> _navAgentId) const { return FGetNavigationAgentTypeIdIndex(this, _navAgentId); }

#if 0
	ArkNpcAreaManager(const ArkNpcAreaManager& _arg0_);
	unsigned GetAreasInAABB(const AABB& _arg0_, unsigned* _arg1_, unsigned _arg2_) const;
	const AABB* GetAreaAABB(unsigned _arg0_) const;
	const std::vector<unsigned int>* GetNpcsInArea(unsigned _arg0_) const;
	unsigned GetAllNavPoints(TNavigationID<1> _arg0_, const Vec3* & _arg1_) const;
	ArkNpcAreaManager& operator=(const ArkNpcAreaManager& _arg0_);
#endif

	static inline auto FArkNpcAreaManagerOv1 = PreyFunction<void(ArkNpcAreaManager* const _this)>(0x15614F0);
	static inline auto FReset = PreyFunction<void(ArkNpcAreaManager* const _this, bool _bEnteringGameMode)>(0x1563770);
	static inline auto FUpdate = PreyFunction<void(ArkNpcAreaManager* const _this, float _dt)>(0x1333E90);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkNpcAreaManager* const _this)>(0x1563190);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcAreaManager* const _this)>(0x15631D0);
	static inline auto FCacheAreasInContainer = PreyFunction<void(ArkNpcAreaManager* const _this, CArkAreaContainer& _areaContainer)>(0x1561820);
	static inline auto FIsInArea = PreyFunction<bool(const ArkNpcAreaManager* const _this, const ArkNpc& _npc, unsigned _areaEntityId)>(0x1562D80);
	static inline auto FGetFirstAreaIn = PreyFunction<unsigned(const ArkNpcAreaManager* const _this, const ArkNpc& _npc)>(0x1562BC0);
	static inline auto FGetAreasInRadius = PreyFunction<unsigned(const ArkNpcAreaManager* const _this, const Vec3& _pos, float _radius, unsigned* _pOutAreas, unsigned _maxAreasCount)>(0x1562AB0);
	static inline auto FGetArea2DArea = PreyFunction<float(const ArkNpcAreaManager* const _this, unsigned _areaEntityId)>(0x1562870);
	static inline auto FGetAreaNavPoints = PreyFunction<unsigned(const ArkNpcAreaManager* const _this, unsigned _areaEntityId, TNavigationID<1> _navAgentId, bool _excludeBoundaryPoints, const Vec3* & _pOutPoints)>(0x1562960);
	static inline auto FOnNpcDone = PreyFunction<void(ArkNpcAreaManager* const _this, ArkNpc& _npc)>(0x1563200);
	static inline auto FGetNumCystoidsInArea = PreyFunction<int(const ArkNpcAreaManager* const _this, unsigned _areaEntityId)>(0x1562D60);
	static inline auto FPrecacheAllRoomVolumes = PreyFunction<void(ArkNpcAreaManager* const _this)>(0x15632D0);
	static inline auto FPrecacheArea = PreyFunction<void(ArkNpcAreaManager* const _this, IEntity& _areaEntity, IEntityAreaProxy& _area)>(0x1563530);
	static inline auto FOnAreaManagerEvent = PreyFunction<void(ArkNpcAreaManager* const _this, EEntityEvent _event, unsigned _triggerEntityID, IArea* _pArea)>(0x1562E70);
	static inline auto FGetAreaInfo = PreyFunction<const ArkNpcAreaManager::AreaInfo* (const ArkNpcAreaManager* const _this, const unsigned _areaEntityId)>(0x15628A0);
	static inline auto FCalculateAreaNavPoints = PreyFunction<void(ArkNpcAreaManager* const _this, unsigned _areaEntityId, TNavigationID<1> _navAgentId, ArkNpcAreaManager::AreaInfo& _areaInfo)>(0x1562300);
	static inline auto FGetNavigationAgentTypeIdIndex = PreyFunction<int(const ArkNpcAreaManager* const _this, TNavigationID<1> _navAgentId)>(0x1562CE0);
};
#endif // MOONCRASH
