// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

struct IEntity;

#ifdef MOONCRASH
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#endif
class ArkSpatialManagerKeyType_Interferable {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferable.h
class ArkSpatialManagerEntryImpl_Interferable // Id=8016104 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>;
	
#ifndef MOONCRASH
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> AddObject(IEntity const &_entity) { return FAddObject(this,_entity); }
#else
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> AddObject(const IEntity& _entity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>)]; return std::move(*FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>*>(_return_buf_), _entity)); }
#endif
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> &_key) { FRemoveObject(this,_key); }
	
#ifndef MOONCRASH
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>(ArkSpatialManagerEntryImpl_Interferable *const _this, IEntity const &_entity)>(0x133DDE0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Interferable *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> &_key)>(0x133DE10);
#else
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>*(ArkSpatialManagerEntryImpl_Interferable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>* _return_value_, const IEntity& _entity)>(0x141A260);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Interferable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>& _key)>(0x141A290);
#endif
};
