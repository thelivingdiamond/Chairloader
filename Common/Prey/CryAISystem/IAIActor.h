// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/IPathfinder.h>
#include <Prey/CryCore/Containers/CryFixedArray.h>
#include <Prey/ArkStubs.h>

struct AIObjectParams;
struct AgentMovementAbility;
struct AgentParameters;
class CAIObject;
enum class ELookStyle;
struct IAIActorProxy;
struct IAIObject;
struct IAISignalExtraData;
struct IEntity;
struct PathFollowerParams;
struct SAIBodyInfo;
struct SOBJECTSTATE;

// IAIActor
// Header:  _unknown/IAIActor.h
// Include: Prey/CryAISystem/IAIActor.h
struct IAIActor : public IAIPathAgent
{ // Size=8 (0x8)
	// IAIActor::CloakObservability
	// Header:  _unknown/IAIActor.h
	struct CloakObservability
	{ // Size=16 (0x10)
		float cloakMaxDistStill;
		float cloakMaxDistMoving;
		float cloakMaxDistCrouchedAndStill;
		float cloakMaxDistCrouchedAndMoving;

	#if 0
		CloakObservability();
	#endif
	};

	virtual ~IAIActor();
	virtual SOBJECTSTATE& GetState() = 0;
	virtual const SOBJECTSTATE& GetState() const = 0;
	virtual IAIActorProxy* GetProxy() const = 0;
	virtual void SetSignal(int nSignalID, const char* szText, IEntity* pSender, IAISignalExtraData* pData, unsigned crcCode) = 0;
	virtual void OnAIHandlerSentSignal(const char* szText, unsigned crcCode) = 0;
	virtual const AgentParameters& GetParameters() const = 0;
	virtual void SetParameters(const AgentParameters& sParams) = 0;
	virtual const AgentMovementAbility& GetMovementAbility() const = 0;
	virtual void SetMovementAbility(AgentMovementAbility& params) = 0;
	virtual bool CanAcquireTarget(IAIObject* pOther) const = 0;
	virtual bool IsActive() const = 0;
	virtual bool CanDamageTarget(IAIObject* target) const = 0;
	virtual bool CanDamageTargetWithMelee() const = 0;
	virtual IAIObject* GetAttentionTarget() const = 0;
	virtual Vec3 GetFloorPosition(const Vec3& pos) = 0;
	virtual bool IsDevalued(IAIObject* pAIObject) = 0;
	virtual void ResetLookAt() = 0;
	virtual bool SetLookAtPointPos(const Vec3& point, bool priority) = 0;
	virtual bool SetLookAtDir(const Vec3& dir, bool priority) = 0;
	virtual void ResetBodyTargetDir() = 0;
	virtual void SetBodyTargetDir(const Vec3& dir) = 0;
	virtual const Vec3& GetBodyTargetDir() const = 0;
	virtual void SetMoveTarget(const Vec3& vMoveTarget) = 0;
	virtual void GoTo(const Vec3& vTargetPos) = 0;
	virtual void SetSpeed(float fSpeed) = 0;
	virtual void SetTerritoryShapeName(const char* szName) = 0;
	virtual const char* GetTerritoryShapeName() const = 0;
	virtual const char* GetWaveName() const = 0;
	virtual bool IsPointInsideTerritoryShape(const Vec3& vPos, bool bCheckHeight) const = 0;
	virtual bool ConstrainInsideTerritoryShape(Vec3& vPos, bool bCheckHeight) const = 0;
	virtual void GetPhysicalSkipEntities(CryFixedArray<IPhysicalEntity *,32>& _arg0_) const;
	virtual TNavigationID<ENavigationIDTag::AgentTypeIDTag> GetNavigationTypeID() const = 0;
	virtual void SetNavigationTypeID(TNavigationID<ENavigationIDTag::AgentTypeIDTag> _id) = 0;
	virtual bool IsInvisibleFrom(const Vec3& pos, bool bCheckCloak, bool bCheckCloakDistance, const IAIActor::CloakObservability& cloakObservability) const = 0;
	virtual bool IsLowHealthPauseActive() const = 0;
	virtual void SetPathToFollow(const char* pathName) = 0;
	virtual const IAIPathAgent* CastToIAIPathAgent() const;
	virtual IAIPathAgent* CastToIAIPathAgent();
	virtual float GetCollisionAvoidanceRadiusIncrement() const = 0;
	virtual void SetCollisionAvoidanceRadiusIncrement(float _inc) = 0;
	virtual void GetMovementSpeedRange(float fUrgency, bool bSlowForStrafe, float& normalSpeed, float& minSpeed, float& maxSpeed, float& maxAccel, float& maxDecel) const = 0;
	virtual void SetAllowedStrafeDistances(float start, float end, bool whileMoving);
	virtual void ParseParameters(const AIObjectParams& params, bool bParseMovementParams) = 0;
	virtual void CheckCloseContact(IAIObject* pTarget, float distSq) = 0;
	virtual bool CloseContactEnabled() = 0;
	virtual void SetCloseContact(bool bCloseContact) = 0;
	virtual const std::vector<CAIObject*>* GetProbableTargets() = 0;
	virtual void AddProbableTarget(CAIObject* pTarget) = 0;
	virtual void ClearProbableTargets() = 0;
	virtual bool ShouldConsiderActorsAsPathObstacles() const;
	virtual const SAIBodyInfo& GetBodyInfo() const = 0;
	virtual std::shared_ptr<Vec3> CreateLookTarget();
	virtual void SetLookStyle(ELookStyle eLookStyle);
	virtual void GetPathFollowerParams(PathFollowerParams& outParams) const;
	virtual unsigned GetPendingSmartObjectID() const;
	virtual void ResetDesiredBodyDirectionAtTarget();
	virtual void CancelRequestedPath(bool _arg0_);
	virtual void PathIsInvalid();

#ifndef MOONCRASH
	static inline auto FCastToIAIPathAgentOv1 = PreyFunction<const IAIPathAgent* (const IAIActor* const _this)>(0xC71190);
	static inline auto FCastToIAIPathAgentOv0 = PreyFunction<IAIPathAgent* (IAIActor* const _this)>(0xC71190);
	static inline auto FSetAllowedStrafeDistances = PreyFunction<void(IAIActor* const _this, float start, float end, bool whileMoving)>(0xA13080);
	static inline auto FShouldConsiderActorsAsPathObstacles = PreyFunction<bool(const IAIActor* const _this)>(0xDD23F0);
	static inline auto FCreateLookTarget = PreyFunction<std::shared_ptr<Vec3>*(IAIActor* const _this, std::shared_ptr<Vec3>* _return_value_)>(0xE62940);
	static inline auto FSetLookStyle = PreyFunction<void(IAIActor* const _this, ELookStyle eLookStyle)>(0xA13080);
	static inline auto FGetPathFollowerParams = PreyFunction<void(const IAIActor* const _this, PathFollowerParams& outParams)>(0xA13080);
	static inline auto FGetPendingSmartObjectID = PreyFunction<unsigned(const IAIActor* const _this)>(0x158AEF0);
	static inline auto FResetDesiredBodyDirectionAtTarget = PreyFunction<void(IAIActor* const _this)>(0xA13080);
	static inline auto FPathIsInvalid = PreyFunction<void(IAIActor* const _this)>(0xA13080);
#else
	static inline auto FCastToIAIPathAgentOv1 = PreyFunction<const IAIPathAgent* (const IAIActor* const _this)>(0x3DAC90);
	static inline auto FCastToIAIPathAgentOv0 = PreyFunction<IAIPathAgent* (IAIActor* const _this)>(0x3DAC90);
	static inline auto FSetAllowedStrafeDistances = PreyFunction<void(IAIActor* const _this, float start, float end, bool whileMoving)>(0x1333E90);
	static inline auto FShouldConsiderActorsAsPathObstacles = PreyFunction<bool(const IAIActor* const _this)>(0x13B0900);
	static inline auto FCreateLookTarget = PreyFunction<std::shared_ptr<Vec3>*(IAIActor* const _this, std::shared_ptr<Vec3>* _return_value_)>(0xE7F6A0);
	static inline auto FSetLookStyle = PreyFunction<void(IAIActor* const _this, ELookStyle eLookStyle)>(0x1333E90);
	static inline auto FGetPathFollowerParams = PreyFunction<void(const IAIActor* const _this, PathFollowerParams& outParams)>(0x1333E90);
	static inline auto FGetPendingSmartObjectID = PreyFunction<unsigned(const IAIActor* const _this)>(0x1CBB0B0);
	static inline auto FResetDesiredBodyDirectionAtTarget = PreyFunction<void(IAIActor* const _this)>(0x1333E90);
	static inline auto FPathIsInvalid = PreyFunction<void(IAIActor* const _this)>(0x1333E90);
#endif
};

