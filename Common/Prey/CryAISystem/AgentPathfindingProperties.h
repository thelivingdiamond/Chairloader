// Header file automatically created from a PDB.

#pragma once
//#include <Prey/CryAISystem/IAISystem.h>
#include <Prey/CryAISystem/IAgent.h>

//TODO: move this to correct header file
//namespace IAISystem{
    struct NavCapMask{
        uint32_t m_navCaps;
    };
//}


// Header: MadeUp
// _unknown/AgentPathfindingProperties.h
struct AgentPathfindingProperties // Id=8000FD6 Size=80
{
//	IAISystem::NavCapMask navCapMask;
    NavCapMask navCapMask;
	float triangularResistanceFactor;
	float waypointResistanceFactor;
	float flightResistanceFactor;
	float volumeResistanceFactor;
	float roadResistanceFactor;
	float waterResistanceFactor;
	float maxWaterDepth;
	float minWaterDepth;
	float exposureFactor;
	float dangerCost;
	float zScale;
	unsigned customNavCapsMask;
	float radius;
	float height;
	float maxSlope;
	int id;
	bool avoidObstacles;
	float endAccuracy;
	float safeLineDistance;
	
#if 0
	void SetToDefaults();
#endif
};

