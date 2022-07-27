// Header file automatically created from a PDB.

#pragma once

class ArkApexTentacle;

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatiallySortedApexTentacle.h
class ArkSpatiallySortedApexTentacle // Id=8016151 Size=8
{
public:
	ArkApexTentacle *m_pTentacle;
	
	ArkSpatiallySortedApexTentacle();
	ArkSpatiallySortedApexTentacle(ArkApexTentacle &_tentacle);
	ArkApexTentacle *GetTentacle() const { return FGetTentacle(this); }
	bool IsValid() const { return FIsValid(this); }
	Vec3 GetPosition() const { return FGetPosition(this); }
	
	static inline auto FGetTentacle = PreyFunction<ArkApexTentacle *(ArkSpatiallySortedApexTentacle const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedApexTentacle const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedApexTentacle const *const _this)>(0x12F7260);
};

