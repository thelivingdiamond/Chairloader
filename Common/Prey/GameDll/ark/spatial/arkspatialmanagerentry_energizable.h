// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

struct IEntity;

class ArkSpatialManagerKeyType_Energizable {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_energizable.h
class ArkSpatialManagerEntryImpl_Energizable // Id=80160D9 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> AddObject(IEntity const &_entity) { return FAddObject(this,_entity); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>(ArkSpatialManagerEntryImpl_Energizable *const _this, IEntity const &_entity)>(0x133DD90);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Energizable *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> &_key)>(0x133DDC0);
};

