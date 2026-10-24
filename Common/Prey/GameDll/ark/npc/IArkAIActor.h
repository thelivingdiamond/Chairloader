#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/IAIActor.h>

struct IEntity;

// IArkAIActor
// Header:  _unknown/IArkAIActor.h
class IArkAIActor : public IAIActor
{ // Size=8 (0x8)
public:
	// IArkAIActor::PushObstacleParams
	// Header:  _unknown/IArkAIActor.h
	struct PushObstacleParams
	{ // Size=28 (0x1C)
		float m_impulseMin;
		float m_impulseMax;
		float m_adjustMassMin;
		float m_adjustMassMax;
		float m_radius;
		float m_falloff;
		bool m_bMassScale;

	#if 0
		PushObstacleParams();
		bool IsValid() const;
	#endif
	};

	virtual void LoadPushObstacleParams(const char* _szTableName, const char* _szPrefix, IArkAIActor::PushObstacleParams& _params) = 0;
	virtual void PushObstacles(const char* _szBoneName, const IArkAIActor::PushObstacleParams& _params) = 0;
	virtual void PushObstacles(const Vec3& _pos, const IArkAIActor::PushObstacleParams& _params) = 0;
	virtual void SetAttentionTarget(IEntity* _pAttnTargetEntity) = 0;
	virtual bool IsFacingRestricted() const = 0;
};

#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryAISystem/IAIActor.h>

struct IEntity;

// IArkAIActor
// Header:  _unknown/IArkAIActor.h
class IArkAIActor : public IAIActor
{ // Size=8 (0x8)
public:
	// IArkAIActor::PushObstacleParams
	// Header:  _unknown/IArkAIActor.h
	struct PushObstacleParams
	{ // Size=28 (0x1C)
		float m_impulseMin;
		float m_impulseMax;
		float m_adjustMassMin;
		float m_adjustMassMax;
		float m_radius;
		float m_falloff;
		bool m_bMassScale;

	#if 0
		PushObstacleParams();
		bool IsValid() const;
	#endif
	};

	virtual void LoadPushObstacleParams(const char* _szTableName, const char* _szPrefix, IArkAIActor::PushObstacleParams& _params) = 0;
	virtual void PushObstacles(const char* _szBoneName, const IArkAIActor::PushObstacleParams& _params) = 0;
	virtual void PushObstacles(const Vec3& _pos, const IArkAIActor::PushObstacleParams& _params) = 0;
	virtual void SetAttentionTarget(IEntity* _pAttnTargetEntity) = 0;
	virtual bool IsFacingRestricted() const = 0;
	virtual void IgnoreAllDangerAreaTypes() = 0;
};

#endif // !MOONCRASH
