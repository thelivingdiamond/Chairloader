// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <_unknown/ArkSpatialManagerKey.h>

class ArkTyphonNest;

// ArkSpatialManagerEntryImpl_TyphonNest
// Header:  Prey/GameDll/ark/spatial/arkspatialmanagerentry_typhonnest.h
class ArkSpatialManagerEntryImpl_TyphonNest
{ // Size=1 (0x1)
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>;

	ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest> AddObject(ArkTyphonNest& _nest) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>)]; return *FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>*>(_return_buf_), _nest); }
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>& _key) { FRemoveObject(this, _key); }

	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>*(ArkSpatialManagerEntryImpl_TyphonNest* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>* _return_value_, ArkTyphonNest& _nest)>(0x13CA100);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_TyphonNest* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_TyphonNest>& _key)>(0x13CA130);
};
#endif // MOONCRASH
