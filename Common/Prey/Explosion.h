#pragma once
#include "Prey/CryCore/StdAfx.h"

class ExplosionInfo
{
	unsigned int shooterId;
	unsigned int weaponId;
	unsigned int projectileId;
	unsigned __int16 projectileClassId;
	float damage;
	Vec3_tpl<float> pos;
	Vec3_tpl<float> dir;
	float minRadius;
	float radius;
	float soundRadius;
	float minPhysRadius;
	float physRadius;
	float angle;
	float pressure;
	float hole_size;
	IParticleEffect* pParticleEffect;
	CryStringT<char> effect_name;
	CryStringT<char> effect_class;
	float effect_scale;
	int type;
	bool impact;
	bool propogate;
	bool explosionViaProxy;
	Vec3_tpl<float> impact_normal;
	Vec3_tpl<float> impact_velocity;
	unsigned int impact_targetId;
	float maxblurdistance;
	int friendlyfire;
	float blindAmount;
	float flashbangScale;
	int firstPassPhysicsEntities;
};
enum class EDeferredMfxExplosionState : __int32
{
	eDeferredMfxExplosionState_None = 0x0,
	eDeferredMfxExplosionState_Dispatched = 0x1,
	eDeferredMfxExplosionState_ProcessingComplete = 0x2,
	eDeferredMfxExplosionState_ResultImpact = 0x3,
	eDeferredMfxExplosionState_ResultNoImpact = 0x4,
};
class SDeferredMfxExplosion
{
	unsigned int m_rayId;
	int m_mfxTargetSurfaceId;
	_smart_ptr<IPhysicalEntity> m_pMfxTargetPhysEnt;
	EDeferredMfxExplosionState m_state;
};
class SExplosionContainer
{
	ExplosionInfo m_explosionInfo;
	SDeferredMfxExplosion m_mfxInfo;
};