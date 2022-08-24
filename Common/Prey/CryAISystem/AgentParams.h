// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <ChairLoader/PreyFunction.h>
#include <Prey/CryAISystem/AgentParams.h>
#include <Prey/CryNetwork/ISerialize.h>

//TODO: move to correct header file
// Header: FromCpp
// CryEngine/cryaisystem/aiobject.h
struct AgentPerceptionParameters // Id=800103C Size=100
{
    float sightRange;
    float sightNearRange;
    float sightDelay;
    float FOVPrimary;
    float FOVSecondary;
    float stanceScale;
    float audioScale;
    float targetPersistence;
    float reactionTime;
    float collisionReactionScale;
    float stuntReactionTimeOut;
    float forgetfulness;
    float forgetfulnessTarget;
    float forgetfulnessSeek;
    float forgetfulnessMemory;
    bool isAffectedByLight;
    float minAlarmLevel;
    float bulletHitRadius;
    float minDistanceToSpotDeadBodies;
    float cloakMaxDistStill;
    float cloakMaxDistMoving;
    float cloakMaxDistCrouchedAndStill;
    float cloakMaxDistCrouchedAndMoving;

    struct SPerceptionScale // Id=800103D Size=8
    {
        float visual;
        float audio;
    };

    AgentPerceptionParameters::SPerceptionScale perceptionScale;

    void Serialize(TSerialize ser) { FSerialize(this,ser); }

    static inline auto FSerialize = PreyFunction<void(AgentPerceptionParameters *const _this, TSerialize ser)>(0x7053D0);
};

// Header: Exact
// CryEngine/crycommon/agentparams.h
struct AgentParameters // Id=800103B Size=240
{
	AgentPerceptionParameters m_PerceptionParams;
	int m_CombatClass;
	float m_fAccuracy;
	float m_fPassRadius;
	float m_fSeparationRadius;
	float m_fStrafingPitch;
	float m_fAttackRange;
	float m_fCommRange;
	float m_fAttackZoneHeight;
	float m_fProjectileLaunchDistScale;
	int m_weaponAccessories;
	float m_fMeleeRange;
	float m_fMeleeRangeShort;
	float m_fMeleeHitRange;
	float m_fMeleeAngleCosineThreshold;
	float m_fMeleeDamage;
	float m_fMeleeKnowckdownChance;
	float m_fMeleeImpulse;
	int m_nGroup;
	bool m_bAiIgnoreFgNode;
	bool m_bPerceivePlayer;
	bool m_bInvisible;
	bool m_bCloaked;
	float m_fCloakScale;
	float m_fCloakScaleTarget;
	float m_fLastCloakEventTime;
	float m_lookIdleTurnSpeed;
	float m_lookCombatTurnSpeed;
	float m_aimTurnSpeed;
	float m_fireTurnSpeed;
	float distanceToCover;
	float effectiveCoverHeight;
	float effectiveHighCoverHeight;
	float inCoverRadius;
	string m_sTerritoryName;
	string m_sWaveName;
	
	AgentParameters();
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	
#if 0
	void Reset();
#endif
	
	static inline auto FSerialize = PreyFunction<void(AgentParameters *const _this, TSerialize ser)>(0x7050E0);
};

