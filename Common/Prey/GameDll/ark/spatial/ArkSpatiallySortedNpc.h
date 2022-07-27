// Header file automatically created from a PDB.

#pragma once

class ArkNpc;

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatiallySortedNpc.h
class ArkSpatiallySortedNpc // Id=80161BD Size=8
{
public:
	ArkNpc const *m_pNpc;
	
	ArkSpatiallySortedNpc();
	ArkSpatiallySortedNpc(ArkNpc const &_npc);
	ArkNpc const *GetNpc() const { return FGetNpc(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	
	static inline auto FGetNpc = PreyFunction<ArkNpc const *(ArkSpatiallySortedNpc const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedNpc const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedNpc const *const _this)>(0x1336970);
};

