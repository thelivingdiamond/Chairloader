// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/IAgent.h>
#include "AgentMovementSpeeds.h"
#include "AgentPathfindingProperties.h"

// Header: MadeUp
// _unknown/AgentMovementAbility.h
struct AgentMovementAbility // Id=8000FD3 Size=1284
{
	bool b3DMove;
	bool bUsePathfinder;
	bool usePredictiveFollowing;
	bool allowEntityClampingByAnimation;
	float maxAccel;
	float maxDecel;
	float minTurnRadius;
	float maxTurnRadius;
	float avoidanceRadius;
	float pathLookAhead;
	float pathRadius;
	float pathSpeedLookAheadPerSpeed;
	float cornerSlowDown;
	float slopeSlowDown;
	float optimalFlightHeight;
	float minFlightHeight;
	float maxFlightHeight;
	float maneuverTrh;
	float velDecay;
	float pathFindPrediction;
	float pathRegenIntervalDuringTrace;
	bool teleportEnabled;
	bool lightAffectsSpeed;
	bool resolveStickingInTrace;
	float directionalScaleRefSpeedMin;
	float directionalScaleRefSpeedMax;
	float directionalScaleTurn;
	float directionalScaleStrafe;
	float directionalScaleSlope;
	float harshStopSpeed;
	float harshStopMinAngle;
	float harshStopMaxAngle;
	float harshStopBelowDist;
	unsigned avoidanceAbilities;
	bool pushableObstacleWeakAvoidance;
	float obstacleAvoidanceMaxPathDeviation;
	bool ignoreMinimumMassObstaclesAtLowUrgency;
	bool ignoreMinimumMassObstaclesAtHighUrgency;
	float pushableObstacleAvoidanceRadiusMin;
	float pushableObstacleAvoidanceRadiusMax;
	float pushableObstacleMassMin;
	float pushableObstacleMassMax;
	float pushableObstacleHeightMin;
	float pushableObstacleHeightMax;
	bool collisionAvoidanceParticipation;
	EAgentForceAvoidanceType collisionAvoidanceForceType;
	float collisionAvoidanceRadiusIncrement;
	AgentMovementSpeeds movementSpeeds;
	AgentPathfindingProperties pathfindingProperties;
};

