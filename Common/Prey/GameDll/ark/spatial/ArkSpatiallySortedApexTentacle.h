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
#ifndef MOONCRASH
	Vec3 GetPosition() const { return FGetPosition(this); }
#else
	Vec3 GetPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
#endif
	
#ifndef MOONCRASH
	static inline auto FGetTentacle = PreyFunction<ArkApexTentacle *(ArkSpatiallySortedApexTentacle const *const _this)>(0x12E5E70);
	static inline auto FIsValid = PreyFunction<bool(ArkSpatiallySortedApexTentacle const *const _this)>(0x12F72B0);
	static inline auto FGetPosition = PreyFunction<Vec3(ArkSpatiallySortedApexTentacle const *const _this)>(0x12F7260);
#else
	static inline auto FArkSpatiallySortedApexTentacleOv1 = PreyFunction<void(ArkSpatiallySortedApexTentacle* const _this)>(0x12A2F50);
	static inline auto FArkSpatiallySortedApexTentacleOv0 = PreyFunction<void(ArkSpatiallySortedApexTentacle* const _this, ArkApexTentacle& _tentacle)>(0x14124F0);
	static inline auto FGetTentacle = PreyFunction<ArkApexTentacle* (const ArkSpatiallySortedApexTentacle* const _this)>(0x1112EA0);
	static inline auto FIsValid = PreyFunction<bool(const ArkSpatiallySortedApexTentacle* const _this)>(0x13CA050);
	static inline auto FGetPosition = PreyFunction<Vec3*(const ArkSpatiallySortedApexTentacle* const _this, Vec3* _return_value_)>(0x13C9FA0);
#endif
};
