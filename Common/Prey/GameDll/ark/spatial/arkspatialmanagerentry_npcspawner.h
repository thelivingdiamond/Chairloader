// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkSpatialManagerKey.h>

class CArkNpcSpawner;

// ArkSpatialManagerEntryImpl_NpcSpawner
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry_npcspawner.h
class ArkSpatialManagerEntryImpl_NpcSpawner
{ // Size=1 (0x1)
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>;

	ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner> AddObject(const CArkNpcSpawner& _spawner) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>)]; return *FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>*>(_return_buf_), _spawner); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>& _spawnerKey) { FRemoveObject(this, _spawnerKey); }

	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>*(ArkSpatialManagerEntryImpl_NpcSpawner* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>* _return_value_, const CArkNpcSpawner& _spawner)>(0x13CA0B0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_NpcSpawner* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_NpcSpawner>& _spawnerKey)>(0x13CA0E0);
};
#endif // MOONCRASH
