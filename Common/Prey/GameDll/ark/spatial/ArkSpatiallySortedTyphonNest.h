#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkTyphonNest;

// ArkSpatiallySortedTyphonNest
// Header:  _unknown/ArkSpatiallySortedTyphonNest.h
class ArkSpatiallySortedTyphonNest
{ // Size=8 (0x8)
public:
	ArkTyphonNest* m_pNest;

	ArkSpatiallySortedTyphonNest();
	ArkSpatiallySortedTyphonNest(ArkTyphonNest& _nest);
	ArkTyphonNest* GetNest() const { return FGetNest(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

	static inline auto FArkSpatiallySortedTyphonNestOv1 = PreyFunction<void(ArkSpatiallySortedTyphonNest* const _this)>(0x12A2F50);
	static inline auto FArkSpatiallySortedTyphonNestOv0 = PreyFunction<void(ArkSpatiallySortedTyphonNest* const _this, ArkTyphonNest& _nest)>(0x14124F0);
	static inline auto FGetNest = PreyFunction<ArkTyphonNest* (const ArkSpatiallySortedTyphonNest* const _this)>(0x1112EA0);
	static inline auto FIsValid = PreyFunction<bool(const ArkSpatiallySortedTyphonNest* const _this)>(0x13CA050);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkSpatiallySortedTyphonNest* const _this, Vec3* _return_value_)>(0x13C9FF0);
};

#endif
