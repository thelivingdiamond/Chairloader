// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkSpatialManagerKey.h>

struct IEntity;

// ArkSpatialManagerEntryImpl_Interferable
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry_interferable.h
class ArkSpatialManagerEntryImpl_Interferable
{ // Size=1 (0x1)
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>;

	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable> AddObject(const IEntity& _entity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>)]; return *FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>*>(_return_buf_), _entity); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>& _key) { FRemoveObject(this, _key); }

	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>*(ArkSpatialManagerEntryImpl_Interferable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>* _return_value_, const IEntity& _entity)>(0x141A260);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Interferable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Interferable>& _key)>(0x141A290);
};
#endif // !MOONCRASH
