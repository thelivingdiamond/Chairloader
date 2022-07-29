// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

class ArkTurret;

class ArkSpatialManagerKeyType_Turret {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_turret.h
class ArkSpatialManagerEntryImpl_Turret // Id=80152F0 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> AddObject(ArkTurret const &_turret) { return FAddObject(this,_turret); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>(ArkSpatialManagerEntryImpl_Turret *const _this, ArkTurret const &_turret)>(0x12F73C0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Turret *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> &_key)>(0x12F73F0);
};

