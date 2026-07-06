// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	
	CArkSignalContext(){m_pInfo = boost::blank();}
	CArkSignalContext(HitInfo const *const _pInfo) {
        m_pInfo = _pInfo;
    };
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct HitInfo;
struct SExplosionContainer;

namespace ArkSignalSystem
{

// ArkSignalSystem::CArkSignalContext
// Header:  Prey/GameDll/ark/signalsystem/ArkSignalContext.h
class CArkSignalContext
{ // Size=16 (0x10)
public:
	boost::variant<boost::blank,HitInfo const *,SExplosionContainer *> m_pInfo;

	CArkSignalContext();
	CArkSignalContext(const HitInfo* const _pInfo);
	CArkSignalContext(void* const __unnamed1);
	Vec3 GetDamagePosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetDamagePosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	Vec3 GetDamageDirection() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetDamageDirection(this, reinterpret_cast<Vec3*>(_return_buf_)); }
	unsigned GetDamageInstigatorId() const { return FGetDamageInstigatorId(this); }
	const HitInfo* GetHitInfo() const { return FGetHitInfo(this); }

#if 0
	CArkSignalContext(SExplosionContainer* _arg0_);
	unsigned GetDamageWeaponId() const;
	SExplosionContainer* GetExplosionInfo() const;
#endif

	static inline auto FCArkSignalContextOv5 = PreyFunction<void(ArkSignalSystem::CArkSignalContext* const _this)>(0x1643FB0);
	static inline auto FCArkSignalContextOv4 = PreyFunction<void(ArkSignalSystem::CArkSignalContext* const _this, const HitInfo* const _pInfo)>(0x1458700);
	static inline auto FCArkSignalContextOv2 = PreyFunction<void(ArkSignalSystem::CArkSignalContext* const _this, void* const __unnamed1)>(0x1643FB0);
	static inline auto FGetDamagePosition = PreyFunction<Vec3*(const ArkSignalSystem::CArkSignalContext* const _this, Vec3* _return_value_)>(0x14587C0);
	static inline auto FGetDamageDirection = PreyFunction<Vec3*(const ArkSignalSystem::CArkSignalContext* const _this, Vec3* _return_value_)>(0x1458710);
	static inline auto FGetDamageInstigatorId = PreyFunction<unsigned(const ArkSignalSystem::CArkSignalContext* const _this)>(0x1458770);
	static inline auto FGetHitInfo = PreyFunction<const HitInfo* (const ArkSignalSystem::CArkSignalContext* const _this)>(0x1458820);
};


} // namespace ArkSignalSystem
#endif // !MOONCRASH
