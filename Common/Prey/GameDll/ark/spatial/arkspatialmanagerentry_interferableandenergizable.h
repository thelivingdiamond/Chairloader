// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

struct IEntity;

class ArkSpatialManagerKeyType_InterferableAndEnergizable {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferableandenergizable.h
class ArkSpatialManagerEntryImpl_InterferableAndEnergizable // Id=801612F Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> AddObject(IEntity const &_entity) { return FAddObject(this,_entity); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>(ArkSpatialManagerEntryImpl_InterferableAndEnergizable *const _this, IEntity const &_entity)>(0x133DE30);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_InterferableAndEnergizable *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> &_key)>(0x133DE60);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkSpatialManagerKey.h>

struct IEntity;

// ArkSpatialManagerEntryImpl_InterferableAndEnergizable
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferableandenergizable.h
class ArkSpatialManagerEntryImpl_InterferableAndEnergizable
{ // Size=1 (0x1)
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>;

	ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> AddObject(const IEntity& _entity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>)]; return *FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>*>(_return_buf_), _entity); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>& _key) { FRemoveObject(this, _key); }

	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>*(ArkSpatialManagerEntryImpl_InterferableAndEnergizable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>* _return_value_, const IEntity& _entity)>(0x141A2B0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_InterferableAndEnergizable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>& _key)>(0x141A2E0);
};
#endif // !MOONCRASH
