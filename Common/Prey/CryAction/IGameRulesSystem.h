// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/StdAfx.h>
#include <Chairloader/PreyFunction.h>
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

enum EFriendyFireType;
class ICrySizer;
struct IParticleEffect;

// ExplosionInfo
// Header:  CryEngine/cryaction/igamerulessystem.h
// Include: Prey/CryAction/IGameRulesSystem.h
struct ExplosionInfo
{ // Size=168 (0xA8)
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
	IParticleEffect* pParticleEffect;
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

	void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

#if 0
	ExplosionInfo();
	ExplosionInfo(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, float _arg3_, const Vec3& _arg4_, const Vec3& _arg5_, float _arg6_, float _arg7_, float _arg8_, float _arg9_, float _arg10_, float _arg11_, float _arg12_, int _arg13_);
	void SetImpact(const Vec3& _arg0_, const Vec3& _arg1_, unsigned _arg2_);
	void SetEffect(const char* _arg0_, float _arg1_, float _arg2_, float _arg3_, float _arg4_);
	void SetEffectName(const char* _arg0_);
	void SetEffectClass(const char* _arg0_);
	void SetFriendlyFire(EFriendyFireType _arg0_);
#endif

	static inline auto FSerializeWith = PreyFunction<void(ExplosionInfo* const _this, TSerialize ser)>(0x1853DB0);
};

// HitInfo
// Header:  CryEngine/cryaction/igamerulessystem.h
// Include: Prey/CryAction/IGameRulesSystem.h
struct HitInfo
{ // Size=108 (0x6C)
	enum class HitInfoFlag
	{
		remote = 1,
		aimed = 2,
		knocksDown = 4,
		knocksDownLeg = 8,
		hitViaProxy = 16,
		explosion = 32,
		forceLocalKill = 64,
		critical = 128,
		resistant = 256,
		shielded = 512,
		armored = 1024,
		hideHitDamageUI = 2048,
		onHitFeedback = 4096,
	};

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
	unsigned m_hitInfoFlags;
	int penetrationCount;

	void SerializeWith(TSerialize ser) { FSerializeWith(this, ser); }

#if 0
	bool GetHitInfoFlag(HitInfo::HitInfoFlag _arg0_) const;
	void SetHitInfoFlag(HitInfo::HitInfoFlag _arg0_, bool _arg1_);
	HitInfo();
	HitInfo(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, float _arg3_, float _arg4_, int _arg5_, int _arg6_, int _arg7_);
	HitInfo(unsigned _arg0_, unsigned _arg1_, unsigned _arg2_, float _arg3_, float _arg4_, int _arg5_, int _arg6_, int _arg7_, const Vec3& _arg8_, const Vec3& _arg9_, const Vec3& _arg10_);
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif

	static inline auto FSerializeWith = PreyFunction<void(HitInfo* const _this, TSerialize ser)>(0x1854190);
};
#endif // !MOONCRASH
