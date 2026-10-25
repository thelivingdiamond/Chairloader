// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/weaponrecoiloffset.h
#ifdef MOONCRASH
namespace Serialization
{
class IArchive;
} // namespace Serialization
#endif
struct SStaticWeaponRecoilParams // Id=8016D29 Size=24
{
	float dampStrength;
	float fireRecoilTime;
	float fireRecoilStrengthFirst;
	float fireRecoilStrength;
	float angleRecoilStrength;
	float randomness;
	
	SStaticWeaponRecoilParams();
	void Serialize(Serialization::IArchive &ar) { FSerialize(this,ar); }
	
#ifndef MOONCRASH
	static inline auto FSerialize = PreyFunction<void(SStaticWeaponRecoilParams *const _this, Serialization::IArchive &ar)>(0x1803640);
#else
	static inline auto FSStaticWeaponRecoilParams = PreyFunction<void(SStaticWeaponRecoilParams* const _this)>(0x1F4DF0);
	static inline auto FSerialize = PreyFunction<void(SStaticWeaponRecoilParams* const _this, Serialization::IArchive& ar)>(0x192B210);
#endif
};

// Header: FromCpp
// Prey/GameDll/weaponrecoiloffset.h
class CRecoilOffset // Id=8016D28 Size=80
{
public:
	SStaticWeaponRecoilParams m_staticParams;
	Vec3 m_position;
	Vec3 m_fireDirection;
	Ang3 m_angle;
	Ang3 m_angleDirection;
	float m_fireTime;
	bool m_firstFire;
	
	CRecoilOffset();
#ifndef MOONCRASH
	QuatT Compute(float frameTime) { return FCompute(this,frameTime); }
#else
	QuatT Compute(float frameTime) { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FCompute(this, reinterpret_cast<QuatT*>(_return_buf_), frameTime); }
#endif
	void SetStaticParams(SStaticWeaponRecoilParams const &params) { FSetStaticParams(this,params); }
	void TriggerRecoil(bool firstFire) { FTriggerRecoil(this,firstFire); }
	
#ifndef MOONCRASH
	static inline auto FCompute = PreyFunction<QuatT(CRecoilOffset *const _this, float frameTime)>(0x1803390);
	static inline auto FSetStaticParams = PreyFunction<void(CRecoilOffset *const _this, SStaticWeaponRecoilParams const &params)>(0x1803700);
	static inline auto FTriggerRecoil = PreyFunction<void(CRecoilOffset *const _this, bool firstFire)>(0x1803720);
#else
	static inline auto FCRecoilOffsetOv2 = PreyFunction<void(CRecoilOffset* const _this)>(0x192AF20);
	static inline auto FCompute = PreyFunction<QuatT*(CRecoilOffset* const _this, QuatT* _return_value_, float frameTime)>(0x192AF60);
	static inline auto FSetStaticParams = PreyFunction<void(CRecoilOffset* const _this, const SStaticWeaponRecoilParams& params)>(0x192B2D0);
	static inline auto FTriggerRecoil = PreyFunction<void(CRecoilOffset* const _this, bool firstFire)>(0x192B2F0);
#endif
};
