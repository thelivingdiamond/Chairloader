// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/ArkSpatiallySortedTurret.h>

class ArkCystoidNest;
class ArkTurret;

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatiallysortedturret.h
#ifndef MOONCRASH
class ArkSpatiallySortedCystoidNest // Id=8016175 Size=8
{
public:
	ArkCystoidNest *m_pNest;
	
	ArkSpatiallySortedCystoidNest();
	ArkSpatiallySortedCystoidNest(ArkCystoidNest &_nest);
	ArkCystoidNest *GetNest() const { return FGetNest(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	
	static inline auto FGetNest = PreyFunction<ArkCystoidNest *(ArkSpatiallySortedCystoidNest const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedCystoidNest const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedCystoidNest const *const _this)>(0x12F72C0);
};
#endif

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatiallySortedTurret.h
class ArkSpatiallySortedTurret // Id=80161E1 Size=8
{
public:
	ArkTurret const *m_pTurret;
	
	ArkSpatiallySortedTurret();
	ArkSpatiallySortedTurret(ArkTurret const &_turret);
	ArkTurret const *GetTurret() const { return FGetTurret(this); }
	bool IsValid() const { return FIsValid(this); }
#ifndef MOONCRASH
	Vec3 GetPosition() const { return FGetPosition(this); }
#else
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
#endif
	
#ifndef MOONCRASH
	static inline auto FGetTurret = PreyFunction<ArkTurret const *(ArkSpatiallySortedTurret const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedTurret const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedTurret const *const _this)>(0x12F72C0);
#else
	static inline auto FArkSpatiallySortedTurretOv1 = PreyFunction<void(ArkSpatiallySortedTurret* const _this)>(0x12A2F50);
	static inline auto FArkSpatiallySortedTurretOv0 = PreyFunction<void(ArkSpatiallySortedTurret* const _this, const ArkTurret& _turret)>(0x14124F0);
	static inline auto FGetTurret = PreyFunction<const ArkTurret* (const ArkSpatiallySortedTurret* const _this)>(0x1112EA0);
	static inline auto FIsValid = PreyFunction<bool(const ArkSpatiallySortedTurret* const _this)>(0x13CA050);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkSpatiallySortedTurret* const _this, Vec3* _return_value_)>(0x13C9FF0);
#endif
};
