// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

struct IEntity;

class ArkSpatialManagerKeyType_Interferable {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferable.h
class ArkSpatialManagerEntryImpl_Interferable // Id=8016104 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> AddObject(IEntity const &_entity) { return FAddObject(this,_entity); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>(ArkSpatialManagerEntryImpl_Interferable *const _this, IEntity const &_entity)>(0x133DDE0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Interferable *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> &_key)>(0x133DE10);
};

