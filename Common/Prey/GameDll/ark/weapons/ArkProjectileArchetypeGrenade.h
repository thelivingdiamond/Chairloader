// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/weapons/ArkProjectileGrenade.h>

class ICrySizer;

// CArkProjectileArchetypeGrenade
// Header:  Prey/GameDll/ark/weapons/ArkProjectileArchetypeGrenade.h
class CArkProjectileArchetypeGrenade : public CArkProjectileGrenade
{ // Size=1912 (0x778)
public:
	uint64_t m_archetypeId;

	CArkProjectileArchetypeGrenade();
	virtual ~CArkProjectileArchetypeGrenade();
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual void LoadCachedProperties();
	virtual void DoDetonation();

#if 0
	static CArkProjectileArchetypeGrenade* GetProjectileGrenadeFromEntityId(const unsigned _arg0_);
#endif

	static inline auto FCArkProjectileArchetypeGrenadeOv1 = PreyFunction<void(CArkProjectileArchetypeGrenade* const _this)>(0x147C270);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkProjectileArchetypeGrenade* const _this, ICrySizer* _s)>(0x147C5B0);
	static inline auto FLoadCachedProperties = PreyFunction<void(CArkProjectileArchetypeGrenade* const _this)>(0x147C5D0);
	static inline auto FDoDetonation = PreyFunction<void(CArkProjectileArchetypeGrenade* const _this)>(0x147C390);
};
#endif // MOONCRASH
