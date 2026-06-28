// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkEffectParameters.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>

struct EventPhysCollision;
class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/arkethericdoppelganger.h
class CArkEthericDoppelganger : public CArkProjectile // Id=801BD13 Size=768
{
public:
	bool m_bHasHitPlayer;
	float m_playerCollisionCheckRadius;
	bool m_bShouldSpawnTrailFogEntities;
	float m_ethericFogTrailSpawnTimer;
	float m_timeBetweenEthericFogTrailSpawns;
	float m_ethericFogSpawnDistanceBehindProjectile;
	ArkEffectParameters m_destroyParticleParams;
	ArkEffectParameters m_spawnParticleParams;
	
	CArkEthericDoppelganger();
	virtual ~CArkEthericDoppelganger();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void DoDamage(EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex);
	virtual void LoadCachedProperties();
	virtual void StartDestroy();
	void DoCollisionWithPlayer() { FDoCollisionWithPlayer(this); }
	void SpawnTrailingEthricFogSpawn() { FSpawnTrailingEthricFogSpawn(this); }
	
#if 0
	void CheckForPlayerCollision();
	void CheckForTrailingEthericFogSpawn(SEntityUpdateContext &arg0);
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkEthericDoppelganger const *const _this, ICrySizer *_s)>(0x13B7810);
	static inline auto FInit = PreyFunction<bool(CArkEthericDoppelganger *const _this, IGameObject *_pGameObject)>(0x1655490);
	static inline auto FPostInit = PreyFunction<void(CArkEthericDoppelganger *const _this, IGameObject *_pGameObject)>(0x13B7D10);
	static inline auto FFullSerialize = PreyFunction<void(CArkEthericDoppelganger *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkEthericDoppelganger *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x13B81C0);
	static inline auto FDoDamage = PreyFunction<void(CArkEthericDoppelganger *const _this, EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex)>(0x13B77E0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkEthericDoppelganger *const _this)>(0x13B7830);
	static inline auto FStartDestroy = PreyFunction<void(CArkEthericDoppelganger *const _this)>(0x13B8150);
	static inline auto FDoCollisionWithPlayer = PreyFunction<void(CArkEthericDoppelganger *const _this)>(0x13B7540);
	static inline auto FSpawnTrailingEthricFogSpawn = PreyFunction<void(CArkEthericDoppelganger *const _this)>(0x13B7E80);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkEffectParameters.h>
#include <Prey/GameDll/ark/weapons/ArkProjectile.h>

struct EventPhysCollision;
class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// CArkEthericDoppelganger
// Header:  Prey/GameDll/ark/ArkEthericDoppelganger.h
class CArkEthericDoppelganger : public CArkProjectile
{ // Size=776 (0x308)
public:
	bool m_bHasHitPlayer;
	float m_playerCollisionCheckRadius;
	bool m_bShouldSpawnTrailFogEntities;
	float m_ethericFogTrailSpawnTimer;
	float m_timeBetweenEthericFogTrailSpawns;
	float m_ethericFogSpawnDistanceBehindProjectile;
	ArkEffectParameters m_destroyParticleParams;
	ArkEffectParameters m_spawnParticleParams;

	CArkEthericDoppelganger();
	virtual ~CArkEthericDoppelganger();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void DoDamage(const EventPhysCollision& _collision, const unsigned& _targetId, const int _targetIndex);
	virtual void LoadCachedProperties();
	virtual void StartDestroy();
	void DoCollisionWithPlayer() { FDoCollisionWithPlayer(this); }
	void SpawnTrailingEthricFogSpawn() { FSpawnTrailingEthricFogSpawn(this); }

#if 0
	void CheckForPlayerCollision();
	void CheckForTrailingEthericFogSpawn(SEntityUpdateContext& _arg0_);
#endif

	static inline auto FCArkEthericDoppelgangerOv1 = PreyFunction<void(CArkEthericDoppelganger* const _this)>(0x14C3790);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkEthericDoppelganger* const _this, ICrySizer* _s)>(0x14AF2C0);
	static inline auto FInit = PreyFunction<bool(CArkEthericDoppelganger* const _this, IGameObject* _pGameObject)>(0x148A5E0);
	static inline auto FPostInit = PreyFunction<void(CArkEthericDoppelganger* const _this, IGameObject* _pGameObject)>(0x14C40D0);
	static inline auto FFullSerialize = PreyFunction<void(CArkEthericDoppelganger* const _this, TSerialize _ser)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(CArkEthericDoppelganger* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x14C4590);
	static inline auto FDoDamage = PreyFunction<void(CArkEthericDoppelganger* const _this, const EventPhysCollision& _collision, const unsigned& _targetId, const int _targetIndex)>(0x14C3BC0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkEthericDoppelganger* const _this)>(0x14C3BF0);
	static inline auto FStartDestroy = PreyFunction<void(CArkEthericDoppelganger* const _this)>(0x14C4520);
	static inline auto FDoCollisionWithPlayer = PreyFunction<void(CArkEthericDoppelganger* const _this)>(0x14C3920);
	static inline auto FSpawnTrailingEthricFogSpawn = PreyFunction<void(CArkEthericDoppelganger* const _this)>(0x14C4250);
};
#endif // !MOONCRASH
