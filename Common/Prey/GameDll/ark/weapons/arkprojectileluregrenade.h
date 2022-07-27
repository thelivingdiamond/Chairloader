// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/perception/ArkGameNoise.h>
#include <Prey/GameDll/ark/weapons/arkprojectilegrenade.h>

class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/weapons/arkprojectileluregrenade.h
class CArkProjectileLureGrenade : public CArkProjectileGrenade // Id=801BC1E Size=1912
{
public:
	ArkGameNoise::Params m_noiseParams;
	
	CArkProjectileLureGrenade();
	virtual void GetMemoryUsage(ICrySizer *_s) const;
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _slot);
	virtual void LoadCachedProperties();
	virtual void Pulse();
	virtual void DoDetonation();
	
#if 0
	static CArkProjectileLureGrenade *GetProjectileGrenadeFromEntityId(const unsigned arg0);
#endif
	
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkProjectileLureGrenade const *const _this, ICrySizer *_s)>(0x1388860);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileLureGrenade *const _this, IGameObject *_pGameObject)>(0x1388890);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileLureGrenade *const _this, TSerialize _ser)>(0x1388840);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileLureGrenade *const _this, SEntityUpdateContext &_ctx, int _slot)>(0x1388AB0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileLureGrenade *const _this)>(0x1388880);
	static inline auto FPulse = PreyFunction<void(CArkProjectileLureGrenade *const _this)>(0x13888A0);
	static inline auto FDoDetonation = PreyFunction<void(CArkProjectileLureGrenade *const _this)>(0x1388820);
};

