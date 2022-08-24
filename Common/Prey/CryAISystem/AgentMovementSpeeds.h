// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/IAgent.h>

// Header: MadeUp
// _unknown/AgentMovementSpeeds.h
struct AgentMovementSpeeds // Id=8000FD4 Size=1040
{
	enum class EAgentMovementUrgency
	{
		AMU_SLOW = 0,
		AMU_WALK = 1,
		AMU_RUN = 2,
		AMU_SPRINT = 3,
		AMU_NUM_VALUES = 4,
	};

	enum class EAgentMovementStance
	{
		AMS_RELAXED = 0,
		AMS_COMBAT = 1,
		AMS_STEALTH = 2,
		AMS_ALERTED = 3,
		AMS_LOW_COVER = 4,
		AMS_HIGH_COVER = 5,
		AMS_CROUCH = 6,
		AMS_PRONE = 7,
		AMS_SWIM = 8,
		AMS_HOVER = 9,
		AMS_CORRUPTED = 10,
		AMS_GUNUP = 11,
		AMS_CHARGE = 12,
		AMS_NUM_VALUES = 13,
	};

	struct SSpeedRange // Id=8000FD5 Size=20
	{
		float def;
		float min;
		float max;
		float accel;
		float decel;
	};

	AgentMovementSpeeds::SSpeedRange speedRanges[13][4];
	
#if 0
	void SetBasicSpeeds(float arg0, float arg1, float arg2, float arg3, float arg4, float arg5, float arg6);
	void SetRanges(int arg0, int arg1, float arg2, float arg3, float arg4);
	void SetRanges(int arg0, int arg1, float arg2, float arg3, float arg4, float arg5, float arg6);
	void CopyRanges(int arg0, int arg1, int arg2);
	AgentMovementSpeeds::SSpeedRange const &GetRange(int arg0, int arg1) const;
	AgentMovementSpeeds::SSpeedRange &GetRange(int arg0, int arg1);
#endif
};

