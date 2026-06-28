// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkNpc;

// ArkSpatiallySortedNpc
// Header:  Prey/GameDll/ark/spatial/ArkSpatiallySortedNpc.h
class ArkSpatiallySortedNpc
{ // Size=8 (0x8)
public:
	const ArkNpc* m_pNpc;

	ArkSpatiallySortedNpc();
	ArkSpatiallySortedNpc(const ArkNpc& _npc);
	const ArkNpc* GetNpc() const { return FGetNpc(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

	static inline auto FArkSpatiallySortedNpcOv1 = PreyFunction<void(ArkSpatiallySortedNpc* const _this)>(0x12A2F50);
	static inline auto FArkSpatiallySortedNpcOv0 = PreyFunction<void(ArkSpatiallySortedNpc* const _this, const ArkNpc& _npc)>(0x14124F0);
	static inline auto FGetNpc = PreyFunction<const ArkNpc* (const ArkSpatiallySortedNpc* const _this)>(0x1112EA0);
	static inline auto FIsValid = PreyFunction<bool(const ArkSpatiallySortedNpc* const _this)>(0x13CA050);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkSpatiallySortedNpc* const _this, Vec3* _return_value_)>(0x1412500);
};
#endif // !MOONCRASH
