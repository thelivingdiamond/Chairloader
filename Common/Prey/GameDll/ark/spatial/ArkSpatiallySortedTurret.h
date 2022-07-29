// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/spatial/arkspatiallysortedturret.h>

class ArkCystoidNest;
class ArkTurret;

// Header: FromCpp
// Prey/GameDll/ark/spatial/arkspatiallysortedturret.h
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
	Vec3 GetPosition() const { return FGetPosition(this); }
	
	static inline auto FGetTurret = PreyFunction<ArkTurret const *(ArkSpatiallySortedTurret const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedTurret const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedTurret const *const _this)>(0x12F72C0);
};

