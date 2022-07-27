// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#include <Prey/GameDll/ark/spatial/arkspatialmanagerentry.h>

class ArkCystoidNest;

class ArkSpatialManagerKeyType_CystoidNest {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_cystoidnest.h
class ArkSpatialManagerEntryImpl_CystoidNest // Id=80160C4 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest> AddObject(ArkCystoidNest &_nest) { return FAddObject(this,_nest); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest>(ArkSpatialManagerEntryImpl_CystoidNest *const _this, ArkCystoidNest &_nest)>(0x12F7370);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_CystoidNest *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_CystoidNest> &_key)>(0x12F73A0);
};

