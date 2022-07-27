// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/arkprojectile.h>

struct EventPhysCollision;
class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectilenightmareetherform.h
class CArkProjectileNightmareEtherForm : public CArkProjectile // Id=801BC1F Size=680
{
public:
	unsigned m_targetID;
	Vec3 m_destination;
	
	CArkProjectileNightmareEtherForm();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual bool Init(IGameObject *_pGameObject);
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void DoDamage(EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex);
	virtual void StartDestroy();
	virtual void LoadCachedProperties();
	
#if 0
	void SetDestination(unsigned arg0);
	void SetDestination(Vec3 const &arg0);
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileNightmareEtherForm const *const _this, ICrySizer *_s)>(0x1389300);
	static inline auto FInit = PreyFunction<bool(CArkProjectileNightmareEtherForm *const _this, IGameObject *_pGameObject)>(0x1655490);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileNightmareEtherForm *const _this, IGameObject *_pGameObject)>(0x137FD00);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileNightmareEtherForm *const _this, TSerialize _ser)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileNightmareEtherForm *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1389390);
	static inline auto FDoDamage = PreyFunction<void(CArkProjectileNightmareEtherForm *const _this, EventPhysCollision const &_collision, const unsigned &_targetId, const int _targetIndex)>(0x1388D50);
	static inline auto FStartDestroy = PreyFunction<void(CArkProjectileNightmareEtherForm *const _this)>(0x1389330);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileNightmareEtherForm *const _this)>(0x1389320);
};

