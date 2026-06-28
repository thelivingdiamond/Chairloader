// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

class ArkApexTentacle;

class ArkSpatialManagerKeyType_ApexTentacle {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_apextentacle.h
class ArkSpatialManagerEntryImpl_ApexTentacle // Id=80160BE Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>;
	
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> AddObject(ArkApexTentacle &_tentacle) { return FAddObject(this,_tentacle); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> &_key) { FRemoveObject(this,_key); }
	
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>(ArkSpatialManagerEntryImpl_ApexTentacle *const _this, ArkApexTentacle &_tentacle)>(0x12F7320);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_ApexTentacle *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> &_key)>(0x12F7350);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkSpatialManagerKey.h>

class ArkApexTentacle;

// ArkSpatialManagerEntryImpl_ApexTentacle
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry_apextentacle.h
class ArkSpatialManagerEntryImpl_ApexTentacle
{ // Size=1 (0x1)
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>;

	ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle> AddObject(ArkApexTentacle& _tentacle) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>)]; return *FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>*>(_return_buf_), _tentacle); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>& _key) { FRemoveObject(this, _key); }

	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>*(ArkSpatialManagerEntryImpl_ApexTentacle* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>* _return_value_, ArkApexTentacle& _tentacle)>(0x13CA060);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_ApexTentacle* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_ApexTentacle>& _key)>(0x13CA090);
};
#endif // !MOONCRASH
