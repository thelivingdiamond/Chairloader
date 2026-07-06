// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkSpatialManagerKey.h>

struct IEntity;

// ArkSpatialManagerEntryImpl_Energizable
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry_energizable.h
class ArkSpatialManagerEntryImpl_Energizable
{ // Size=1 (0x1)
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>;

	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable> AddObject(const IEntity& _entity) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>)]; return *FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>*>(_return_buf_), _entity); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>& _key) { FRemoveObject(this, _key); }

	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>*(ArkSpatialManagerEntryImpl_Energizable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>* _return_value_, const IEntity& _entity)>(0x141A210);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Energizable* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Energizable>& _key)>(0x141A240);
};
#endif // !MOONCRASH
