#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CArkNpcSpawner;

// ArkSpatiallySortedNpcSpawner
// Header:  _unknown/ArkSpatiallySortedNpcSpawner.h
class ArkSpatiallySortedNpcSpawner
{ // Size=8 (0x8)
public:
	const CArkNpcSpawner* m_pNpcSpawner;

	ArkSpatiallySortedNpcSpawner();
	ArkSpatiallySortedNpcSpawner(const CArkNpcSpawner& _npcSpawner);
	const CArkNpcSpawner* GetNpcSpawner() const { return FGetNpcSpawner(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

	static inline auto FArkSpatiallySortedNpcSpawnerOv1 = PreyFunction<void(ArkSpatiallySortedNpcSpawner* const _this)>(0x12A2F50);
	static inline auto FArkSpatiallySortedNpcSpawnerOv0 = PreyFunction<void(ArkSpatiallySortedNpcSpawner* const _this, const CArkNpcSpawner& _npcSpawner)>(0x14124F0);
	static inline auto FGetNpcSpawner = PreyFunction<const CArkNpcSpawner* (const ArkSpatiallySortedNpcSpawner* const _this)>(0x1112EA0);
	static inline auto FIsValid = PreyFunction<bool(const ArkSpatiallySortedNpcSpawner* const _this)>(0x13CA050);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkSpatiallySortedNpcSpawner* const _this, Vec3* _return_value_)>(0x13C9FF0);
};

#endif
