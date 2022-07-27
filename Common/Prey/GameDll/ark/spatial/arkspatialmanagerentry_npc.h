// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

class ArkNpc;

class ArkSpatialManagerKeyType_Npc {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_npc.h
class ArkSpatialManagerEntryImpl_Npc // Id=8014308 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> AddObject(ArkNpc const &_npc) { return FAddObject(this,_npc); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>(ArkSpatialManagerEntryImpl_Npc *const _this, ArkNpc const &_npc)>(0x133DE80);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Npc *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> &_key)>(0x133DEB0);
};

