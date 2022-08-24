// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/CryAISystem/AgentParams.h>
#include <Prey/CryAISystem/IAIMannequin.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include "AgentMovementAbility.h"
#include <Prey/CryAISystem/AISignal.h>

struct IAIObject;
class ICrySizer;
struct IPipeUser;


// FIXME - move these to correct header files
struct SFireCommandProjectileInfo // Id=8000FA8 Size=8
{
    unsigned trackingId;
    float fSpeedScale;

#if 0
    void Reset();
#endif
};

struct SAIPredictedCharacterState // Id=8000FAA Size=28
{
    Vec3 position;
    Vec3 velocity;
    float predictionTime;

#if 0
    void Set(Vec3 const &arg0, Vec3 const &arg1, float arg2);
	void Serialize(TSerialize arg0);
#endif
};



struct SAIPredictedCharacterStates // Id=8000FA9 Size=900
{
    enum
    {
        maxStates = 32,
    };

    SAIPredictedCharacterState states[32];
    int nStates;

#if 0
    void Serialize(TSerialize arg0);
#endif
};





// Header: Exact
// CryEngine/crycommon/iagent.h
struct SAIActorTargetRequest // Id=8000FAB Size=120
{
	int id;
	Vec3 approachLocation;
	Vec3 approachDirection;
	Vec3 animLocation;
	Vec3 animDirection;
	float speed;
	float directionTolerance;
	float startArcAngle;
	float startWidth;
	float loopDuration;
	float directionStartDistance;
	float forceInterpolationTime;
	bool signalAnimation;
	bool projectEndPoint;
	bool lowerPrecision;
	bool useAssetAlignment;
	string animation;
	EStance stance;
	unsigned *pQueryStart;
	unsigned *pQueryEnd;
	
	void Reset() { FReset(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
	static inline auto FReset = PreyFunction<void(SAIActorTargetRequest *const _this)>(0x5E85F0);
	static inline auto FSerialize = PreyFunction<void(SAIActorTargetRequest *const _this, TSerialize ser)>(0x705970);
};

// Header: Exact
// CryEngine/crycommon/iagent.h
struct SOBJECTSTATE // Id=8000FA7 Size=1416
{
	enum EFireControllerIndex
	{
		eFireControllerIndex_None = 0,
		eFireControllerIndex_First = 1,
		eFireControllerIndex_Second = 2,
		eFireControllerIndex_Third = 3,
		eFireControllerIndex_Fourth = 4,
		eFireControllerIndex_All = 17185,
	};

	bool jump;
	bool aimObstructed;
	bool aimTargetIsValid;
	bool forceWeaponAlertness;
	EAIFireState fire;
	EAIFireState fireSecondary;
	EAIFireState fireMelee;
	ERequestedGrenadeType requestedGrenadeType;
	int weaponAccessories;
	int bodystate;
	float lean;
	float peekOver;
	Vec3 vShootTargetPos;
	Vec3 vAimTargetPos;
	Vec3 vLookTargetPos;
	Vec3 vLobLaunchPosition;
	Vec3 vLobLaunchVelocity;
	SFireCommandProjectileInfo projectileInfo;
	ELookStyle eLookStyle;
	bool bAllowLowerBodyToTurn;
	Vec3 vMoveDir;
	Vec3 vForcedNavigation;
	Vec3 vBodyTargetDir;
	Vec3 vDesiredBodyDirectionAtTarget;
	Vec3 vBodyPathForceDir;
	Vec3 vBodyAlignDir;
	float fForcedNavigationSpeed;
	unsigned movementContext;
	SAIPredictedCharacterStates predictedCharacterStates;
	Vec3 vMoveTarget;
	Vec3 vInflectionPoint;
	float fMovementUrgency;
	float fDesiredSpeed;
	float fTargetSpeed;
	bool allowStrafing;
	bool allowEntityClampingByAnimation;
	float fDistanceToPathEnd;
	Vec3 vDirOffPath;
	EActorTargetPhase curActorTargetPhase;
	Vec3 curActorTargetFinishPos;
	SAIActorTargetRequest actorTargetReq;
	bool bCloseContact;
	bool bReevaluate;
	bool bTargetEnabled;
	bool bTargetIsGroupTarget;
	bool continuousMotion;
	EAITargetType eTargetType;
	EAITargetContextType eTargetContextType;
	EAITargetThreat eTargetThreat;
	unsigned eTargetID;
	EAITargetType ePeakTargetType;
	EAITargetThreat ePeakTargetThreat;
	unsigned ePeakTargetID;
	EAITargetType ePreviousPeakTargetType;
	EAITargetThreat ePreviousPeakTargetThreat;
	unsigned ePreviousPeakTargetID;
	Vec3 vTargetPos;
	float fDistanceFromTarget;
	EAITargetStuntReaction eTargetStuntReaction;
	int nTargetType;
	DynArray<AISIGNAL,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > vSignals;
	int secondaryIndex;
	CAIMannequinCommandList<32> mannequinRequest;
	EBodyOrientationMode bodyOrientationMode;
	
	void Reset(bool clearMoveDir) { FReset(this,clearMoveDir); }
	void FullReset(bool clearMoveDir) { FFullReset(this,clearMoveDir); }
	void ClearSignals() { FClearSignals(this); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
#if 0
	bool operator==(SOBJECTSTATE &arg0);
#endif
	
	static inline auto FReset = PreyFunction<void(SOBJECTSTATE *const _this, bool clearMoveDir)>(0x5E8680);
	static inline auto FFullReset = PreyFunction<void(SOBJECTSTATE *const _this, bool clearMoveDir)>(0x5E5960);
	static inline auto FClearSignals = PreyFunction<void(SOBJECTSTATE *const _this)>(0x5E50B0);
	static inline auto FSerialize = PreyFunction<void(SOBJECTSTATE *const _this, TSerialize ser)>(0x705BA0);
};

// Header: Exact
// CryEngine/crycommon/iagent.h
struct SAIBodyInfo // Id=8000FBF Size=188
{
	Vec3 vEyePos;
	Vec3 vEyeDir;
	Vec3 vEyeDirAnim;
	Vec3 vEntityDir;
	Vec3 vAnimBodyDir;
	Vec3 vMoveDir;
	Vec3 vUpDir;
	Vec3 vFireDir;
	Vec3 vFirePos;
	float maxSpeed;
	float normalSpeed;
	float minSpeed;
	EStance stance;
	AABB stanceSize;
	AABB colliderSize;
	bool isAiming;
	bool isFiring;
	bool isMoving;
	float lean;
	float peekOver;
	float slopeAngle;
	
	Vec3 const &GetEyeDir() const { return FGetEyeDir(this); }
	Vec3 const &GetBodyDir() const { return FGetBodyDir(this); }
	SAIBodyInfo();
	
	static inline auto FGetEyeDir = PreyFunction<Vec3 const &(SAIBodyInfo const *const _this)>(0x700F00);
	static inline auto FGetBodyDir = PreyFunction<Vec3 const &(SAIBodyInfo const *const _this)>(0x700E80);
};

// Header: Exact
// CryEngine/crycommon/iagent.h
struct AIWeaponDescriptor // Id=8000FCF Size=120
{
	string firecmdHandler;
	float fSpeed;
	float fDamageRadius;
	float fChargeTime;
	float fRangeMax;
	float fRangeMin;
	bool bSignalOnShoot;
	int burstBulletCountMin;
	int burstBulletCountMax;
	float burstPauseTimeMin;
	float burstPauseTimeMax;
	float singleFireTriggerTime;
	float spreadRadius;
	float coverFireTime;
	float drawTime;
	float sweepWidth;
	float sweepFrequency;
	float pressureMultiplier;
	float lobCriticalDistance;
	float preferredHeight;
	float closeDistance;
	float preferredHeightForCloseDistance;
	float maxAcceptableDistanceFromTarget;
	float minimumDistanceFromFriends;
	Vec3 projectileGravity;
	string smartObjectClass;
	
	AIWeaponDescriptor(string const &fcHandler, float chargeTime, float speed, float damageRadius);
	
#if 0
	void GetMemoryUsage(ICrySizer *arg0) const;
	void __dflt_ctor_closure();
#endif
};

// Header: Exact
// CryEngine/crycommon/iagent.h
struct AIObjectParams // Id=800103E Size=1552
{
	AgentParameters m_sParamStruct;
	AgentMovementAbility m_moveAbility;
	uint16_t type;
	IAIObject *association;
	const char *name;
	unsigned entityID;
	float m_fCloseThresholdAutoDisable;
	
	AIObjectParams(uint16_t _type, IAIObject *_association, unsigned _entityID, float _fCloseThresholdAutoDisable);
};

#if 0
// Header: Exact
// CryEngine/crycommon/iagent.h
struct IGoalPipeListener // Id=800111E Size=16
{
	using VectorRegisteredPipes = DynArray<std::pair<IPipeUser *,int>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > >;
	
	DynArray<std::pair<IPipeUser *,int>,int,NArray::SmallDynStorage<NAlloc::AllocCompatible<NAlloc::ModuleAlloc> > > _vector_registered_pipes;
	
	virtual void OnGoalPipeEvent(IPipeUser *arg0, EGoalPipeEvent arg1, int arg2, bool &arg3) = 0;
	virtual ~IGoalPipeListener();
	
	static inline auto FBitNotIGoalPipeListener = PreyFunction<void(IGoalPipeListener *const _this)>(0x4827A0);
};
#endif
