// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>

class CArkWeaponDiscRifle;
class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilediscrifle.h
class CArkProjectileDiscRifle : public CArkProjectile // Id=801BC00 Size=712
{
public:
	float m_maxSpeed;
	float m_acceleration;
	float m_turnSpeed;
	float m_distanceClose;
	float m_minSpeedClose;
	float m_decelerationClose;
	float m_turnSpeedClose;
	float m_explosionRadius;
	float m_explosionImpulse;
	unsigned m_targetId;
	bool m_bUseCloseParameters;
	bool m_bExploded;
	bool m_bTargetKilled;
	unsigned m_hitEntity;
	
	CArkProjectileDiscRifle();
	virtual ~CArkProjectileDiscRifle();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void HandleEvent(SGameObjectEvent const &_event);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual const void *GetRMIBase() const;
	virtual void LoadCachedProperties();
	bool Detonate() { return FDetonate(this); }
	
#if 0
	void SetTarget(unsigned arg0);
	void DoExplosion();
	void NPCHit();
	void NPCMiss();
	CArkWeaponDiscRifle *GetDiscRifle() const;
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileDiscRifle const *const _this, ICrySizer *_s)>(0x137F480);
	static inline auto FInit = PreyFunction<bool(CArkProjectileDiscRifle *const _this, IGameObject *_pGameObject)>(0x137F820);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileDiscRifle *const _this, IGameObject *_pGameObject)>(0x137FD00);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileDiscRifle *const _this, TSerialize _ser)>(0x137F3C0);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileDiscRifle *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x137FF70);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileDiscRifle *const _this, SGameObjectEvent const &_event)>(0x137F4A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectileDiscRifle *const _this, SEntityEvent &_event)>(0x137FD10);
	static inline auto FGetRMIBase = PreyFunction<const void *(CArkProjectileDiscRifle const *const _this)>(0x158AEF0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileDiscRifle *const _this)>(0x137F840);
	static inline auto FDetonate = PreyFunction<bool(CArkProjectileDiscRifle *const _this)>(0x137F340);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkProjectile.h>

class CArkWeaponDiscRifle;
class ICrySizer;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkProjectileDiscRifle
// Header:  Prey/GameDll/ark/weapons/ArkProjectileDiscRifle.h
class CArkProjectileDiscRifle : public CArkProjectile
{ // Size=720 (0x2D0)
public:
	float m_maxSpeed;
	float m_acceleration;
	float m_turnSpeed;
	float m_distanceClose;
	float m_minSpeedClose;
	float m_decelerationClose;
	float m_turnSpeedClose;
	float m_explosionRadius;
	float m_explosionImpulse;
	unsigned m_targetId;
	bool m_bUseCloseParameters;
	bool m_bExploded;
	bool m_bTargetKilled;
	unsigned m_hitEntity;

	CArkProjectileDiscRifle();
	virtual ~CArkProjectileDiscRifle();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual bool Init(IGameObject* _pGameObject);
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual const void* GetRMIBase() const;
	virtual void LoadCachedProperties();
	bool Detonate() { return FDetonate(this); }

#if 0
	void SetTarget(unsigned _arg0_);
	void DoExplosion();
	void NPCHit();
	void NPCMiss();
	CArkWeaponDiscRifle* GetDiscRifle() const;
#endif

	static inline auto FCArkProjectileDiscRifleOv1 = PreyFunction<void(CArkProjectileDiscRifle* const _this)>(0x147CA00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkProjectileDiscRifle* const _this, ICrySizer* _s)>(0x147CBE0);
	static inline auto FInit = PreyFunction<bool(CArkProjectileDiscRifle* const _this, IGameObject* _pGameObject)>(0x147D010);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileDiscRifle* const _this, IGameObject* _pGameObject)>(0x148B6B0);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileDiscRifle* const _this, TSerialize _ser)>(0x147CB20);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileDiscRifle* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x147D760);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileDiscRifle* const _this, const SGameObjectEvent& _event)>(0x147CC00);
	static inline auto FProcessEvent = PreyFunction<void(CArkProjectileDiscRifle* const _this, SEntityEvent& _event)>(0x147D4F0);
	static inline auto FGetRMIBase = PreyFunction<const void* (const CArkProjectileDiscRifle* const _this)>(0x1CBB0B0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileDiscRifle* const _this)>(0x147D030);
	static inline auto FDetonate = PreyFunction<bool(CArkProjectileDiscRifle* const _this)>(0x147CAA0);
};
#endif // !MOONCRASH
