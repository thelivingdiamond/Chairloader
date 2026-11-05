// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryCore/Containers/CryArray.h>
#include <Prey/CryAISystem/IAISystem.h>
#include <Prey/CryAISystem/NavSpace.h>
#include <Prey/ArkStubs.h>

struct AgentMovementAbility;
class CArkHeightPathFollower;
class CArkHoverPathFollower;
class CArkLargePathFollower;
class CArkSmallPathFollower;
class CPathFollower;
class CSmartPathFollower;
class CTargetPointRequest;
struct IEntity;
class INavPath;
struct NavigationBlocker;
struct PathFollowResult;
struct PathFollowerParams;
struct PathfindRequest;

//! Passing through navigational SO methods (from CryEngine 5.2).
enum ENavSOMethod
{
	nSOmNone,               //!< Not passing or not passable.
	nSOmAction,             //!< Execute an AI action.
	nSOmPriorityAction,     //!< Execute a higher priority AI action.
	nSOmStraight,           //!< Just pass straight.
	nSOmSignalAnimation,    //!< Play signal animation.
	nSOmActionAnimation,    //!< Play action animation.
	nSOmLast
};

// IPathFollower
// Header:  CryEngine/crycommon/ipathfinder.h
// Include: Prey/CryAISystem/IPathfinder.h
class IPathFollower
{ // Size=16 (0x10)
public:
	// IPathFollower::PathFollowerFastCast
	// Header:  CryEngine/crycommon/ipathfinder.h
	struct PathFollowerFastCast
	{ // Size=1 (0x1)
		bool bPathFollower : 1;
		bool bSmartPathFollower : 1;
		bool bArkHoverPathFollower : 1;
		bool bArkHeightPathFollower : 1;
		bool bArkLargePathFollower : 1;
		bool bArkSmallPathFollower : 1;

	#if 0
		PathFollowerFastCast();
	#endif
	};

	IPathFollower::PathFollowerFastCast _fastcast;

	virtual ~IPathFollower();
	virtual void Release() = 0;
	virtual void Reset() = 0;
	virtual void AttachToPath(INavPath* pNavPath) = 0;
	virtual void SetParams(const PathFollowerParams& params) = 0;
	virtual const PathFollowerParams& GetParams() const = 0;
	virtual PathFollowerParams& GetParams() = 0;
	virtual bool Update(PathFollowResult& result, const Vec3& curPos, const Vec3& curVel, float dt) = 0;
	virtual void Advance(float distance) = 0;
	virtual float GetDistToEnd(const Vec3* pCurPos) const = 0;
	virtual float GetDistToSmartObject() const = 0;
	virtual float GetDistToNavType(IAISystem::ENavigationType navType) const = 0;
	virtual Vec3 GetPathPointAhead(float dist, float& actualDist) const = 0;
	virtual void Draw(const Vec3& drawOffset) const = 0;
	virtual void Serialize(TSerialize ser) = 0;
	virtual bool CheckWalkability(const Vec2* path, const uint64_t length) const = 0;
	virtual bool GetAllowCuttingCorners() const = 0;
	virtual void SetAllowCuttingCorners(const bool allowCuttingCorners) = 0;
	virtual bool HasTargetPOI();
	virtual Vec3 GetTargetPOI();
	virtual void SetTargetPOI(const Vec3& _targetPOI, unsigned _targetId);
	virtual float GetDistToPathPoint(const Vec3& pos) const;
	virtual Vec3 GetPathEndPoint() const;
	virtual bool IsPathEmpty() const;
	virtual float GetDistToOffMeshLink(const Vec3& pos) const;
	virtual bool GetShiftPointAhead(const Vec3& _curPos, float _startDist, float _lookAheadDist, float& _actualDist, Vec3& _shiftPos) const;
	virtual bool GetCrouchHeight(float& _height);
	virtual bool GetStandingHeight(float& _height);
	virtual void SetCrouchHeightOverride(float _height);
	virtual void ClearCrouchHeightOverride();
	virtual void SetInMovementTransition(bool _bInTransition);
	virtual bool GetInMovementTransition();

#if 0
	CPathFollower* CastToCPathFollower();
	CSmartPathFollower* CastToCSmartPathFollower();
	CArkHoverPathFollower* CastToCArkHoverPathFollower();
	CArkHeightPathFollower* CastToCArkHeightPathFollower();
	CArkLargePathFollower* CastToCArkLargePathFollower();
	CArkSmallPathFollower* CastToCArkSmallPathFollower();
#endif

#ifndef MOONCRASH
	static inline auto FHasTargetPOI = PreyFunction<bool(IPathFollower* const _this)>(0xDD23F0);
	static inline auto FGetTargetPOI = PreyFunction<Vec3*(IPathFollower* const _this, Vec3* _return_value_)>(0x6F9180);
	static inline auto FSetTargetPOI = PreyFunction<void(IPathFollower* const _this, const Vec3& _targetPOI, unsigned _targetId)>(0xA13080);
	static inline auto FGetDistToPathPoint = PreyFunction<float(const IPathFollower* const _this, const Vec3& pos)>(0xB5F050);
	static inline auto FGetPathEndPoint = PreyFunction<Vec3*(const IPathFollower* const _this, Vec3* _return_value_)>(0x6F9180);
	static inline auto FIsPathEmpty = PreyFunction<bool(const IPathFollower* const _this)>(0xDD23F0);
	static inline auto FGetDistToOffMeshLink = PreyFunction<float(const IPathFollower* const _this, const Vec3& pos)>(0xB5F050);
	static inline auto FGetShiftPointAhead = PreyFunction<bool(const IPathFollower* const _this, const Vec3& _curPos, float _startDist, float _lookAheadDist, float& _actualDist, Vec3& _shiftPos)>(0xDD23F0);
	static inline auto FGetCrouchHeight = PreyFunction<bool(IPathFollower* const _this, float& _height)>(0xDD23F0);
	static inline auto FGetStandingHeight = PreyFunction<bool(IPathFollower* const _this, float& _height)>(0xDD23F0);
	static inline auto FSetCrouchHeightOverride = PreyFunction<void(IPathFollower* const _this, float _height)>(0xA13080);
	static inline auto FClearCrouchHeightOverride = PreyFunction<void(IPathFollower* const _this)>(0xA13080);
	static inline auto FSetInMovementTransition = PreyFunction<void(IPathFollower* const _this, bool _bInTransition)>(0xA13080);
	static inline auto FGetInMovementTransition = PreyFunction<bool(IPathFollower* const _this)>(0xDD23F0);
#else
	static inline auto FHasTargetPOI = PreyFunction<bool(IPathFollower* const _this)>(0x13B0900);
	static inline auto FGetTargetPOI = PreyFunction<Vec3*(IPathFollower* const _this, Vec3* _return_value_)>(0x7153B0);
	static inline auto FSetTargetPOI = PreyFunction<void(IPathFollower* const _this, const Vec3& _targetPOI, unsigned _targetId)>(0x1333E90);
	static inline auto FGetDistToPathPoint = PreyFunction<float(const IPathFollower* const _this, const Vec3& pos)>(0x714650);
	static inline auto FGetPathEndPoint = PreyFunction<Vec3*(const IPathFollower* const _this, Vec3* _return_value_)>(0x7153B0);
	static inline auto FIsPathEmpty = PreyFunction<bool(const IPathFollower* const _this)>(0x13B0900);
	static inline auto FGetDistToOffMeshLink = PreyFunction<float(const IPathFollower* const _this, const Vec3& pos)>(0x714650);
	static inline auto FGetShiftPointAhead = PreyFunction<bool(const IPathFollower* const _this, const Vec3& _curPos, float _startDist, float _lookAheadDist, float& _actualDist, Vec3& _shiftPos)>(0x13B0900);
	static inline auto FGetCrouchHeight = PreyFunction<bool(IPathFollower* const _this, float& _height)>(0x13B0900);
	static inline auto FGetStandingHeight = PreyFunction<bool(IPathFollower* const _this, float& _height)>(0x13B0900);
	static inline auto FSetCrouchHeightOverride = PreyFunction<void(IPathFollower* const _this, float _height)>(0x1333E90);
	static inline auto FClearCrouchHeightOverride = PreyFunction<void(IPathFollower* const _this)>(0x1333E90);
	static inline auto FSetInMovementTransition = PreyFunction<void(IPathFollower* const _this, bool _bInTransition)>(0x1333E90);
	static inline auto FGetInMovementTransition = PreyFunction<bool(IPathFollower* const _this)>(0x13B0900);
#endif
};

// IAIPathAgent
// Header:  _unknown/IAIPathAgent.h
// Include: Prey/CryAISystem/IPathfinder.h
struct IAIPathAgent
{ // Size=8 (0x8)
	virtual ~IAIPathAgent();
	virtual IEntity* GetPathAgentEntity() const = 0;
	virtual const char* GetPathAgentName() const = 0;
	virtual uint16_t GetPathAgentType() const = 0;
	virtual float GetPathAgentPassRadius() const = 0;
	virtual Vec3 GetPathAgentPos() const = 0;
	virtual Vec3 GetPathAgentVelocity() const = 0;
	virtual const AgentMovementAbility& GetPathAgentMovementAbility() const = 0;
	virtual void GetPathAgentNavigationBlockers(DynArray<NavigationBlocker,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >& navigationBlockers, const PathfindRequest* pRequest) = 0;
	virtual unsigned GetPathAgentLastNavNode() const = 0;
	virtual void SetPathAgentLastNavNode(unsigned lastNavNode) = 0;
	virtual void SetPathToFollow(const char* pathName) = 0;
	virtual void SetPathAttributeToFollow(bool bSpline) = 0;
	virtual void SetPFBlockerRadius(int blockerType, float radius) = 0;
	virtual ETriState CanTargetPointBeReached(CTargetPointRequest& request) = 0;
	virtual bool UseTargetPointRequest(const CTargetPointRequest& request) = 0;
	virtual bool GetValidPositionNearby(const Vec3& proposedPosition, Vec3& adjustedPosition) const = 0;
	virtual bool GetTeleportPosition(Vec3& teleportPos) const = 0;
	virtual IPathFollower* GetPathFollower() const = 0;
	virtual bool IsPointValidForAgent(const Vec3& pos, unsigned flags) const = 0;
	virtual INavPath* GetINavPath();

#ifndef MOONCRASH
	static inline auto FGetINavPath = PreyFunction<INavPath* (IAIPathAgent* const _this)>(0x158AEF0);
#else
	static inline auto FGetINavPath = PreyFunction<INavPath* (IAIPathAgent* const _this)>(0x1CBB0B0);
#endif
};

// PathPointDescriptor
// Header:  CryEngine/crycommon/ipathfinder.h
// Include: Prey/CryAISystem/IPathfinder.h
struct PathPointDescriptor
{ // Size=56 (0x38)
	// PathPointDescriptor::SmartObjectNavData
	// Header:  CryEngine/crycommon/ipathfinder.h
	struct SmartObjectNavData : public _i_reference_target<int>
	{ // Size=24 (0x18)
		unsigned fromIndex;
		unsigned toIndex;

	#if 0
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// PathPointDescriptor::OffMeshLinkData
	// Header:  CryEngine/crycommon/ipathfinder.h
	struct OffMeshLinkData
	{ // Size=16 (0x10)
		NavSpace space;
		unsigned offMeshLinkID;
		EArkOffMeshLinkType arkLinkType;

	#if 0
		OffMeshLinkData();
	#endif
	};

	using SmartObjectNavDataPtr = _smart_ptr<PathPointDescriptor::SmartObjectNavData>;

	Vec3 vPos;
	IAISystem::ENavigationType navType;
	uint16_t navTypeCustomId;
	unsigned iTriId;
	PathPointDescriptor::OffMeshLinkData offMeshLinkData;
	_smart_ptr<PathPointDescriptor::SmartObjectNavData> pSONavData;
	ENavSOMethod navSOMethod;

	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	static bool ArePointsEquivalent(const PathPointDescriptor& point1, const PathPointDescriptor& point2) { return FArePointsEquivalent(point1, point2); }

#if 0
	PathPointDescriptor(IAISystem::ENavigationType _arg0_, const Vec3& _arg1_);
	PathPointDescriptor(const Vec3& _arg0_);
	bool IsEquivalent(const PathPointDescriptor& _arg0_) const;
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(PathPointDescriptor* const _this, TSerialize ser)>(0x6F5440);
	static inline auto FArePointsEquivalent = PreyFunction<bool(const PathPointDescriptor& point1, const PathPointDescriptor& point2)>(0x6045C0);
#else
	static inline auto FSerialize = PreyFunction<void(PathPointDescriptor* const _this, TSerialize ser)>(0x711060);
	static inline auto FArePointsEquivalent = PreyFunction<bool(const PathPointDescriptor& point1, const PathPointDescriptor& point2)>(0x61EF50);
#endif
};

// SNavPathParams
// Header:  CryEngine/crycommon/ipathfinder.h
// Include: Prey/CryAISystem/IPathfinder.h
struct SNavPathParams
{ // Size=68 (0x44)
	Vec3 start;
	Vec3 end;
	Vec3 startDir;
	Vec3 endDir;
	int nForceBuildingID;
	bool allowDangerousDestination;
	bool precalculatedPath;
	bool inhibitPathRegeneration;
	bool continueMovingAtEnd;
	bool isDirectional;
	float endDistance;
	TNavigationID<ENavigationIDTag::MeshIDTag> meshID;

	void Serialize(TSerialize ser) { FSerialize(this, ser); }

#if 0
	SNavPathParams(const Vec3& _arg0_, const Vec3& _arg1_, const Vec3& _arg2_, const Vec3& _arg3_, int _arg4_, bool _arg5_, float _arg6_, bool _arg7_, bool _arg8_);
	void Clear();
#endif

#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SNavPathParams* const _this, TSerialize ser)>(0x6F55E0);
#else
	static inline auto FSerialize = PreyFunction<void(SNavPathParams* const _this, TSerialize ser)>(0x711200);
#endif
};

