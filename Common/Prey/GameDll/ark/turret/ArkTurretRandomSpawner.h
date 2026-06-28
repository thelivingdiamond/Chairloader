// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/turret/ArkTurretSpawner.h>

class ICrySizer;
struct IEntityArchetype;
struct IGameObject;
struct SEntityUpdateContext;

// ArkTurretRandomSpawner
// Header:  Prey/GameDll/ark/turret/ArkTurretRandomSpawner.h
class ArkTurretRandomSpawner : public ArkTurretSpawner
{ // Size=96 (0x60)
public:
	float m_swapModelTimer;

	ArkTurretRandomSpawner();
	virtual ~ArkTurretRandomSpawner();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void Release();
	virtual void Update(SEntityUpdateContext& _rCtx, int _updateSlot);
	virtual IEntityArchetype* GetEntityArchetype() const;

	static inline auto FArkTurretRandomSpawnerOv1 = PreyFunction<void(ArkTurretRandomSpawner* const _this)>(0x13CE1B0);
	static inline auto FPostInit = PreyFunction<void(ArkTurretRandomSpawner* const _this, IGameObject* _pGameObject)>(0x152E070);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkTurretRandomSpawner* const _this, ICrySizer* _pSizer)>(0xA55F00);
	static inline auto FRelease = PreyFunction<void(ArkTurretRandomSpawner* const _this)>(0x3E3960);
	static inline auto FUpdate = PreyFunction<void(ArkTurretRandomSpawner* const _this, SEntityUpdateContext& _rCtx, int _updateSlot)>(0x1333E90);
	static inline auto FGetEntityArchetype = PreyFunction<IEntityArchetype* (const ArkTurretRandomSpawner* const _this)>(0x13CE240);
};
#endif // MOONCRASH
