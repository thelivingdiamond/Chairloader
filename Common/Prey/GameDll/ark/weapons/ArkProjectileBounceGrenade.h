// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/weapons/ArkProjectileGrenade.h>

class ICrySizer;
struct IGameObject;
struct SEntityUpdateContext;
struct SGameObjectEvent;

// CArkProjectileBounceGrenade
// Header:  Prey/GameDll/ark/weapons/ArkProjectileBounceGrenade.h
class CArkProjectileBounceGrenade : public CArkProjectileGrenade
{ // Size=1912 (0x778)
public:
	int m_numBouncesAllowed;
	int m_numBounces;

	CArkProjectileBounceGrenade();
	virtual ~CArkProjectileBounceGrenade();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void HandleEvent(const SGameObjectEvent& _event);
	virtual void Update(SEntityUpdateContext& _ctx, int _slot);
	virtual void ReInitFromPool();
	virtual void LoadCachedProperties();

#if 0
	static CArkProjectileBounceGrenade* GetProjectileGrenadeFromEntityId(const unsigned _arg0_);
#endif

	static inline auto FCArkProjectileBounceGrenadeOv1 = PreyFunction<void(CArkProjectileBounceGrenade* const _this)>(0x147C6F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkProjectileBounceGrenade* const _this, ICrySizer* _s)>(0x147C5B0);
	static inline auto FPostInit = PreyFunction<void(CArkProjectileBounceGrenade* const _this, IGameObject* _pGameObject)>(0x1488050);
	static inline auto FFullSerialize = PreyFunction<void(CArkProjectileBounceGrenade* const _this, TSerialize _ser)>(0x1487F10);
	static inline auto FHandleEvent = PreyFunction<void(CArkProjectileBounceGrenade* const _this, const SGameObjectEvent& _event)>(0x147C810);
	static inline auto FUpdate = PreyFunction<void(CArkProjectileBounceGrenade* const _this, SEntityUpdateContext& _ctx, int _slot)>(0x147C9C0);
	static inline auto FReInitFromPool = PreyFunction<void(CArkProjectileBounceGrenade* const _this)>(0x147C9A0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileBounceGrenade* const _this)>(0x147C8A0);
};
#endif // MOONCRASH
