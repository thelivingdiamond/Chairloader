// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

class ArkApexTentacle;

#ifdef MOONCRASH
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#endif
class ArkSpatialManagerKeyType_ApexTentacle {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_apextentacle.h
class ArkSpatialManagerEntryImpl_ApexTentacle // Id=80160BE Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>;
	
#ifndef MOONCRASH
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> AddObject(ArkApexTentacle &_tentacle) { return FAddObject(this,_tentacle); }
#else
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> AddObject(ArkApexTentacle& _tentacle) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>)]; return std::move(*FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>*>(_return_buf_), _tentacle)); }
#endif
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> &_key) { FRemoveObject(this,_key); }
	
#ifndef MOONCRASH
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>(ArkSpatialManagerEntryImpl_ApexTentacle *const _this, ArkApexTentacle &_tentacle)>(0x12F7320);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_ApexTentacle *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> &_key)>(0x12F7350);
#else
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>*(ArkSpatialManagerEntryImpl_ApexTentacle* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>* _return_value_, ArkApexTentacle& _tentacle)>(0x13CA060);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_ApexTentacle* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>& _key)>(0x13CA090);
#endif
};
