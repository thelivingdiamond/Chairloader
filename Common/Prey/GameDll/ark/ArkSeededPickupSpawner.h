// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/CArkGameObjectExtension.h>

class ArkLootItem;
class CArkItem;
struct IEntityArchetype;
struct IGameObject;
struct SEntityEvent;

// CArkSeededPickupSpawner
// Header:  Prey/GameDll/ark/ArkSeededPickupSpawner.h
class CArkSeededPickupSpawner : public CArkGameObjectExtension<CArkSeededPickupSpawner>
{ // Size=64 (0x40)
public:
	static CArkItem* SpawnItem(const char* _lootTable, uint64_t _seed, const Vec3& _location, const Quat& _rotation) { return FSpawnItemOv1(_lootTable, _seed, _location, _rotation); }
	void SpawnItem() { FSpawnItemOv0(this); }
	virtual bool Init(IGameObject* _pGameObject);
	virtual void ProcessEvent(SEntityEvent& _event);
	static const ArkLootItem* FindLootArchetype(const uint64_t _lootTable, uint64_t _seed, bool _bAlwaysSelect) { return FFindLootArchetype(_lootTable, _seed, _bAlwaysSelect); }

#if 0
	IEntityArchetype* FindArchetype(bool _arg0_) const;
#endif

	static inline auto FSpawnItemOv1 = PreyFunction<CArkItem* (const char* _lootTable, uint64_t _seed, const Vec3& _location, const Quat& _rotation)>(0x11DD770);
	static inline auto FSpawnItemOv0 = PreyFunction<void(CArkSeededPickupSpawner* const _this)>(0x11DD410);
	static inline auto FInit = PreyFunction<bool(CArkSeededPickupSpawner* const _this, IGameObject* _pGameObject)>(0x37A880);
	static inline auto FProcessEvent = PreyFunction<void(CArkSeededPickupSpawner* const _this, SEntityEvent& _event)>(0x11DD400);
	static inline auto FFindLootArchetype = PreyFunction<const ArkLootItem* (const uint64_t _lootTable, uint64_t _seed, bool _bAlwaysSelect)>(0x11DD070);
};
#endif // MOONCRASH
