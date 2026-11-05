// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

class ArkTurret;

#ifdef MOONCRASH
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#endif
class ArkSpatialManagerKeyType_Turret {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_turret.h
class ArkSpatialManagerEntryImpl_Turret // Id=80152F0 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>;
	
#ifndef MOONCRASH
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> AddObject(ArkTurret const &_turret) { return FAddObject(this,_turret); }
#else
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> AddObject(const ArkTurret& _turret) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>)]; return std::move(*FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>*>(_return_buf_), _turret)); }
#endif
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> &_key) { FRemoveObject(this,_key); }
	
#ifndef MOONCRASH
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>(ArkSpatialManagerEntryImpl_Turret *const _this, ArkTurret const &_turret)>(0x12F73C0);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Turret *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret> &_key)>(0x12F73F0);
#else
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>*(ArkSpatialManagerEntryImpl_Turret* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>* _return_value_, const ArkTurret& _turret)>(0x13CA150);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Turret* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Turret>& _key)>(0x13CA180);
#endif
};
