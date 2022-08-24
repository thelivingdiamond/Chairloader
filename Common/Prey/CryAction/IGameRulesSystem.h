// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <ChairLoader/PreyFunction.h>
#include <Prey/CryAction/IGameRulesSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct IParticleEffect;

// Header: Exact
// CryEngine/cryaction/igamerulessystem.h
struct HitInfo // Id=8001F5A Size=112
{
	unsigned shooterId;
	unsigned targetId;
	unsigned weaponId;
	unsigned projectileId;
	unsigned uniqueId;
	unsigned groupId;
	float damage;
	float impulseScale;
	float radius;
	float angle;
	int material;
	int type;
	int bulletType;
	float damageMin;
	int partId;
	Vec3 pos;
	Vec3 dir;
	Vec3 normal;
	uint16_t projectileClassId;
	uint16_t weaponClassId;
	bool remote;
	bool aimed;
	bool knocksDown;
	bool knocksDownLeg;
	bool hitViaProxy;
	bool explosion;
	bool forceLocalKill;
	bool critical;
	int penetrationCount;
	
	void SerializeWith(TSerialize ser) { FSerializeWith(this,ser); }
	
#if 0
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	
	static inline auto FSerializeWith = PreyFunction<void(HitInfo *const _this, TSerialize ser)>(0x172CE50);
};

// Header: Exact
// CryEngine/cryaction/igamerulessystem.h
struct ExplosionInfo // Id=8001FA5 Size=168
{
	unsigned shooterId;
	unsigned weaponId;
	unsigned projectileId;
	uint16_t projectileClassId;
	float damage;
	Vec3 pos;
	Vec3 dir;
	float minRadius;
	float radius;
	float soundRadius;
	float minPhysRadius;
	float physRadius;
	float angle;
	float pressure;
	float hole_size;
	IParticleEffect *pParticleEffect;
	string effect_name;
	string effect_class;
	float effect_scale;
	int type;
	bool impact;
	bool propogate;
	bool explosionViaProxy;
	Vec3 impact_normal;
	Vec3 impact_velocity;
	unsigned impact_targetId;
	float maxblurdistance;
	int friendlyfire;
	float blindAmount;
	float flashbangScale;
	int firstPassPhysicsEntities;
	
	void SerializeWith(TSerialize ser) { FSerializeWith(this,ser); }
	
#if 0
	void SetImpact(Vec3 const &arg0, Vec3 const &arg1, unsigned arg2);
	void SetEffect(const char *arg0, float arg1, float arg2, float arg3, float arg4);
	void SetEffectName(const char *arg0);
	void SetEffectClass(const char *arg0);
	void SetFriendlyFire(EFriendyFireType arg0);
#endif
	
	static inline auto FSerializeWith = PreyFunction<void(ExplosionInfo *const _this, TSerialize ser)>(0x172CA70);
};

