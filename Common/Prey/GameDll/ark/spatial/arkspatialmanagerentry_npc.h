// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>

class ArkNpc;

#ifdef MOONCRASH
#include <Prey/GameDll/ark/spatial/ArkSpatialManagerKey.h>
#endif
class ArkSpatialManagerKeyType_Npc {};

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatialmanagerentry_npc.h
class ArkSpatialManagerEntryImpl_Npc // Id=8014308 Size=1
{
public:
	using KeyType = ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>;
	
#ifndef MOONCRASH
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> AddObject(ArkNpc const &_npc) { return FAddObject(this,_npc); }
#else
	ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> AddObject(const ArkNpc& _npc) { alignas(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>) std::byte _return_buf_[sizeof(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>)]; return std::move(*FAddObject(this, reinterpret_cast<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>*>(_return_buf_), _npc)); }
#endif
	void RemoveObject(ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> &_key) { FRemoveObject(this,_key); }
	
#ifndef MOONCRASH
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>(ArkSpatialManagerEntryImpl_Npc *const _this, ArkNpc const &_npc)>(0x133DE80);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Npc *const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc> &_key)>(0x133DEB0);
#else
	static inline auto FAddObject = PreyFunction<ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>*(ArkSpatialManagerEntryImpl_Npc* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>* _return_value_, const ArkNpc& _npc)>(0x141A300);
	static inline auto FRemoveObject = PreyFunction<void(ArkSpatialManagerEntryImpl_Npc* const _this, ArkSpatialManagerKey<ArkSpatialManagerKeyType_Npc>& _key)>(0x141A330);
#endif
};
