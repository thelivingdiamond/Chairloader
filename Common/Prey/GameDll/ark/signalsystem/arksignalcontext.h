// Header file automatically created from a PDB.

#pragma once

struct HitInfo;
struct SExplosionContainer;

namespace ArkSignalSystem
{

// Header: FromCpp
// Prey/GameDll/ark/signalsystem/arksignalcontext.h
class CArkSignalContext // Id=80136D9 Size=16
{
public:
	boost::variant<boost::blank,HitInfo const *,SExplosionContainer *> m_pInfo;
	
	CArkSignalContext();
	CArkSignalContext(HitInfo const *const _pInfo);
	CArkSignalContext(void *const );
	Vec3 GetDamagePosition() const { return FGetDamagePosition(this); }
	Vec3 GetDamageDirection() const { return FGetDamageDirection(this); }
	unsigned GetDamageInstigatorId() const { return FGetDamageInstigatorId(this); }
	unsigned GetDamageWeaponId() const { return FGetDamageWeaponId(this); }
	HitInfo const *GetHitInfo() const { return FGetHitInfo(this); }
	
#if 0
	SExplosionContainer *GetExplosionInfo() const;
#endif
	
	static inline auto FGetDamagePosition = PreyFunction<Vec3(ArkSignalSystem::CArkSignalContext const *const _this)>(0x1375990);
	static inline auto FGetDamageDirection = PreyFunction<Vec3(ArkSignalSystem::CArkSignalContext const *const _this)>(0x13758E0);
	static inline auto FGetDamageInstigatorId = PreyFunction<unsigned(ArkSignalSystem::CArkSignalContext const *const _this)>(0x1375940);
	static inline auto FGetDamageWeaponId = PreyFunction<unsigned(ArkSignalSystem::CArkSignalContext const *const _this)>(0x13759F0);
	static inline auto FGetHitInfo = PreyFunction<HitInfo const *(ArkSignalSystem::CArkSignalContext const *const _this)>(0x1375A40);
};

} // namespace ArkSignalSystem

