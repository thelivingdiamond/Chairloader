// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/TNavigationID.h>
#include <_unknown/UnreachableTargetingClaimRequester.h>

struct IEntity;
struct IntersectionTestRequest;
struct IntersectionTestResult;

// UnreachableTargetingSearchArea
// Header:  Prey/GameDll/ark/npc/ArkNpcUnreachableTargetingManager.h
class UnreachableTargetingSearchArea
{ // Size=200 (0xC8)
public:
	int m_numPointsAdded;
	int m_index;
	int m_searchId;
	TNavigationID<1> m_navAgentType;
	unsigned m_targetEntityId;
	unsigned m_searchingEntityId;
	Vec3 m_searchOriginPoint;
	Vec3 m_targetLocation;
	bool m_bHasNoValidPoint;
	bool m_bNeedsToExpandSearchRange;
	Vec3 m_closestValidPoint;
	Vec3 m_overrideSearchStartPoint;
	Vec3 m_overrideTraceEndTarget;
	float m_currentSearchRange;
	bool m_bSearchStartedFar;
	float m_traceCheckRadius;
	float m_minSearchRadius;
	float m_npcStandingHeight;
	float m_npcHeightDifferenceFromAttach;
	float m_horizontalOffsetStanding;
	float m_horizontalOffsetCrouching;
	float m_maxAllowedAngleNpcToTar;
	float m_maxSearchRadius;
	bool m_bBecomeStaleOnTargetMovement;
	static inline auto s_bLoadedConfig = PreyGlobal<bool>(0x2D4F431);
	static inline auto s_searchRadiusStep = PreyGlobal<float>(0x23E3618);
	static inline auto s_minSearchRadius = PreyGlobal<float>(0x2D4F434);
	static inline auto s_maxSearchRadius = PreyGlobal<float>(0x23E361C);
	static inline auto s_maxTracePointsPerArea = PreyGlobal<int>(0x23E3620);
	static inline auto s_maxAllowedAngleFromNpcToTarget = PreyGlobal<float>(0x23E3624);
	static inline auto s_traceRadius = PreyGlobal<float>(0x23E3628);
	static inline auto s_searchHeight = PreyGlobal<float>(0x23E362C);
	static inline auto s_maxTargetTravelDistanceBeforeUpdateNeededSq = PreyGlobal<float>(0x23E3630);
	std::unordered_map<unsigned int, Vec3> m_pendingTestIdToPoints;

	~UnreachableTargetingSearchArea();
	void InitializeSearch(int _newSearchId, const unsigned _searchingEntityId, const unsigned _targetEntityId, bool _bUseDefaultSearchParams, Vec3 _overrideSearchStartPoint, Vec3 _overrideTraceEndTarget) { FInitializeSearch(this, _newSearchId, _searchingEntityId, _targetEntityId, _bUseDefaultSearchParams, _overrideSearchStartPoint, _overrideTraceEndTarget); }
	bool AddSearchPointsInCurrentRange() { return FAddSearchPointsInCurrentRange(this); }
	void AddPointToCheck(const Vec3& _navPointToCheck, const IEntity& _searchingEntity, const IEntity& _targetEntity, const Vec3& _traceTargetPos, const Vec3& _traceStart, float _traceRadius) { FAddPointToCheck(this, _navPointToCheck, _searchingEntity, _targetEntity, _traceTargetPos, _traceStart, _traceRadius); }
	void CancelAllTraces() { FCancelAllTraces(this); }
	bool IntersectionTestSubmitCallback(const unsigned& _intID, IntersectionTestRequest& _result) { return FIntersectionTestSubmitCallback(this, _intID, _result); }
	void IntersectionTestCompleteCallback(const unsigned& _intID, const IntersectionTestResult& _result) { FIntersectionTestCompleteCallback(this, _intID, _result); }
	void LoadConfig() { FLoadConfig(this); }

#if 0
	UnreachableTargetingSearchArea();
	bool TryAddSearchPointRange();
	void IncrementSearchRange();
	bool IsOutOfSearchRange() const;
	Vec3 GetSuccessfulCandidatePoint() const;
	bool HasNoReachablePoint() const;
	void Update();
	bool IsNoLongerRelevant(const IEntity& _arg0_, const IEntity& _arg1_, const Vec3 _arg2_) const;
	void ForceToUnused(bool _arg0_);
	void DebugDraw() const;
	unsigned GetTargetEntityId() const;
	int GetSearchId() const;
	int GetIndex() const;
	Vec3 GetSearchOriginPoint() const;
	Vec3 GetTargetLocation() const;
	TNavigationID<1> GetNavAgentType() const;
	int GetNumPointsAdded() const;
	bool GetHasNoValidPoint() const;
	int GetNumPendingTraces() const;
	void SetBecomeStaleOnTargetMovement(bool _arg0_);
	void SetIndex(const int _arg0_);
#endif

	static inline auto FBitNotUnreachableTargetingSearchArea = PreyFunction<void(UnreachableTargetingSearchArea* const _this)>(0x13354D0);
	static inline auto FInitializeSearch = PreyFunction<void(UnreachableTargetingSearchArea* const _this, int _newSearchId, const unsigned _searchingEntityId, const unsigned _targetEntityId, bool _bUseDefaultSearchParams, Vec3 _overrideSearchStartPoint, Vec3 _overrideTraceEndTarget)>(0x1336670);
	static inline auto FAddSearchPointsInCurrentRange = PreyFunction<bool(UnreachableTargetingSearchArea* const _this)>(0x1335BB0);
	static inline auto FAddPointToCheck = PreyFunction<void(UnreachableTargetingSearchArea* const _this, const Vec3& _navPointToCheck, const IEntity& _searchingEntity, const IEntity& _targetEntity, const Vec3& _traceTargetPos, const Vec3& _traceStart, float _traceRadius)>(0x1335640);
	static inline auto FCancelAllTraces = PreyFunction<void(UnreachableTargetingSearchArea* const _this)>(0x1336390);
	static inline auto FIntersectionTestSubmitCallback = PreyFunction<bool(UnreachableTargetingSearchArea* const _this, const unsigned& _intID, IntersectionTestRequest& _result)>(0x1A302A0);
	static inline auto FIntersectionTestCompleteCallback = PreyFunction<void(UnreachableTargetingSearchArea* const _this, const unsigned& _intID, const IntersectionTestResult& _result)>(0x1336FF0);
	static inline auto FLoadConfig = PreyFunction<void(UnreachableTargetingSearchArea* const _this)>(0x1337240);
};

// ArkNpcUnreachableTargetingManager
// Header:  Prey/GameDll/ark/npc/ArkNpcUnreachableTargetingManager.h
class ArkNpcUnreachableTargetingManager
{ // Size=1672 (0x688)
public:
	float m_claimRadiusSquared;
	std::unordered_map<unsigned int, UnreachableTargetingClaimRequester> m_requesterToClaimInfo;
	std::array<UnreachableTargetingSearchArea, 8> m_searchAreas;
	static inline auto s_currentAreaSearchId = PreyGlobal<int>(0x2D4F438);

	ArkNpcUnreachableTargetingManager();
	void Update(float _dt) { FUpdate(this, _dt); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void OnLevelUnload() { FOnLevelUnload(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	float GetTraceRadius() const { return FGetTraceRadius(this); }
	bool HasRequest(unsigned _checkEntityId) const { return FHasRequest(this, _checkEntityId); }
	void RemoveRequest(unsigned _entityIdToRemove) { FRemoveRequest(this, _entityIdToRemove); }
	std::tuple<bool,Vec3_tpl<float> > RequestPoint(IEntity& _searchingEntity, IEntity& _targetEntity, bool _bUseDefaultSearchParams, float _avoidPointRadius, Vec3 _avoidPoint, Vec3 _overrideSearchStartPoint, Vec3 _overrideTraceEndTarget, bool _bIgnoreTargetMovementUpdating) { alignas(std::tuple<bool,Vec3_tpl<float> >) std::byte _return_buf_[sizeof(std::tuple<bool,Vec3_tpl<float> >)]; return *FRequestPoint(this, reinterpret_cast<std::tuple<bool,Vec3_tpl<float> >*>(_return_buf_), _searchingEntity, _targetEntity, _bUseDefaultSearchParams, _avoidPointRadius, _avoidPoint, _overrideSearchStartPoint, _overrideTraceEndTarget, _bIgnoreTargetMovementUpdating); }
	bool TryClaimCurrentPosition(IEntity& _searchingEntity) { return FTryClaimCurrentPosition(this, _searchingEntity); }
	bool IsPointClaimed(const Vec3& _pointToCheck, unsigned _entityIdToIgnore) const { return FIsPointClaimed(this, _pointToCheck, _entityIdToIgnore); }
	UnreachableTargetingClaimRequester* InitializeSearchArea(IEntity& _searchingEntity, IEntity& _targetEntity, bool _bUseDefaultSearchParams, Vec3 _overrideSearchStartPoint, Vec3 _overrideTraceEndTarget, bool _bIgnoreTargetMovementUpdating) { return FInitializeSearchArea(this, _searchingEntity, _targetEntity, _bUseDefaultSearchParams, _overrideSearchStartPoint, _overrideTraceEndTarget, _bIgnoreTargetMovementUpdating); }

#if 0
	ArkNpcUnreachableTargetingManager(const ArkNpcUnreachableTargetingManager& _arg0_);
	void OnLevelLoadStart();
	bool HasSuccessfullyClaimedPoint(unsigned _arg0_) const;
	ArkNpcUnreachableTargetingManager& operator=(const ArkNpcUnreachableTargetingManager& _arg0_);
	UnreachableTargetingClaimRequester& AddRequester(const unsigned _arg0_, const int _arg1_, const int _arg2_);
	UnreachableTargetingSearchArea* FindAreaBySearchId(const uint64_t _arg0_);
	Vec3 FindTraceTargetPosition(const IEntity& _arg0_, IEntity& _arg1_, const bool _arg2_) const;
	int FindUnusedAreaIndex() const;
	bool IsAreaBeingRequested(const UnreachableTargetingSearchArea& _arg0_) const;
	void ClearSearchArea(UnreachableTargetingSearchArea& _arg0_);
	void ClearAllRequestersUsingSearch(const int _arg0_);
	void ClearAreaIfUnused(const int _arg0_);
	void DebugDraw();
	void LoadConfig();
	int GetTotalNumPendingTraces() const;
#endif

	static inline auto FArkNpcUnreachableTargetingManagerOv1 = PreyFunction<void(ArkNpcUnreachableTargetingManager* const _this)>(0x1335260);
	static inline auto FUpdate = PreyFunction<void(ArkNpcUnreachableTargetingManager* const _this, float _dt)>(0x1337BB0);
	static inline auto FReset = PreyFunction<void(ArkNpcUnreachableTargetingManager* const _this, bool _bEnteringGameMode)>(0x13379A0);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkNpcUnreachableTargetingManager* const _this)>(0x1337460);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkNpcUnreachableTargetingManager* const _this)>(0x1333E90);
	static inline auto FGetTraceRadius = PreyFunction<float(const ArkNpcUnreachableTargetingManager* const _this)>(0x13365B0);
	static inline auto FHasRequest = PreyFunction<bool(const ArkNpcUnreachableTargetingManager* const _this, unsigned _checkEntityId)>(0x13365C0);
	static inline auto FRemoveRequest = PreyFunction<void(ArkNpcUnreachableTargetingManager* const _this, unsigned _entityIdToRemove)>(0x1337470);
	static inline auto FRequestPoint = PreyFunction<std::tuple<bool,Vec3_tpl<float> >*(ArkNpcUnreachableTargetingManager* const _this, std::tuple<bool,Vec3_tpl<float> >* _return_value_, IEntity& _searchingEntity, IEntity& _targetEntity, bool _bUseDefaultSearchParams, float _avoidPointRadius, Vec3 _avoidPoint, Vec3 _overrideSearchStartPoint, Vec3 _overrideTraceEndTarget, bool _bIgnoreTargetMovementUpdating)>(0x13376A0);
	static inline auto FTryClaimCurrentPosition = PreyFunction<bool(ArkNpcUnreachableTargetingManager* const _this, IEntity& _searchingEntity)>(0x1337A90);
	static inline auto FIsPointClaimed = PreyFunction<bool(const ArkNpcUnreachableTargetingManager* const _this, const Vec3& _pointToCheck, unsigned _entityIdToIgnore)>(0x1337130);
	static inline auto FInitializeSearchArea = PreyFunction<UnreachableTargetingClaimRequester* (ArkNpcUnreachableTargetingManager* const _this, IEntity& _searchingEntity, IEntity& _targetEntity, bool _bUseDefaultSearchParams, Vec3 _overrideSearchStartPoint, Vec3 _overrideTraceEndTarget, bool _bIgnoreTargetMovementUpdating)>(0x1336DE0);
};
#endif // MOONCRASH
