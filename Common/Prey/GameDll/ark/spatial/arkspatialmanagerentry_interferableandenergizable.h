// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

struct IEntity;

#ifdef MOONCRASH
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#endif
class ArkSpatialManagerKeyType_InterferableAndEnergizable {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferableandenergizable.h
class ArkSpatialManagerEntryImpl_InterferableAndEnergizable // Id=801612F Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>;
	
#ifndef MOONCRASH
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> AddObject(IEntity const &_entity) { return FAddObject(this,_entity); }
#else
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> AddObject(const IEntity& _entity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>)]; return std::move(*FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>*>(_return_buf_), _entity)); }
#endif
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> &_key) { FRemoveObject(this,_key); }
	
#ifndef MOONCRASH
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>(ArkSpatialManagerEntryImpl_InterferableAndEnergizable *const _this, IEntity const &_entity)>(0x133DE30);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_InterferableAndEnergizable *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable> &_key)>(0x133DE60);
#else
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>*(ArkSpatialManagerEntryImpl_InterferableAndEnergizable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>* _return_value_, const IEntity& _entity)>(0x141A2B0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_InterferableAndEnergizable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_InterferableAndEnergizable>& _key)>(0x141A2E0);
#endif
};
