// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/weaponrecoiloffset.h
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
	
	static inline auto FSerialize = PreyFunction<void(SStaticWeaponRecoilParams *const _this, Serialization::IArchive &ar)>(0x1803640);
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
	QuatT Compute(float frameTime) { return FCompute(this,frameTime); }
	void SetStaticParams(SStaticWeaponRecoilParams const &params) { FSetStaticParams(this,params); }
	void TriggerRecoil(bool firstFire) { FTriggerRecoil(this,firstFire); }
	
	static inline auto FCompute = PreyFunction<QuatT(CRecoilOffset *const _this, float frameTime)>(0x1803390);
	static inline auto FSetStaticParams = PreyFunction<void(CRecoilOffset *const _this, SStaticWeaponRecoilParams const &params)>(0x1803700);
	static inline auto FTriggerRecoil = PreyFunction<void(CRecoilOffset *const _this, bool firstFire)>(0x1803720);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

namespace Serialization
{
class IArchive;
} // namespace Serialization

// SStaticWeaponRecoilParams
// Header:  Prey/GameDll/weaponrecoiloffset.h
struct SStaticWeaponRecoilParams
{ // Size=24 (0x18)
	float dampStrength;
	float fireRecoilTime;
	float fireRecoilStrengthFirst;
	float fireRecoilStrength;
	float angleRecoilStrength;
	float randomness;

	SStaticWeaponRecoilParams();
	void Serialize(Serialization::IArchive& ar) { FSerialize(this, ar); }

	static inline auto FSStaticWeaponRecoilParams = PreyFunction<void(SStaticWeaponRecoilParams* const _this)>(0x1F4DF0);
	static inline auto FSerialize = PreyFunction<void(SStaticWeaponRecoilParams* const _this, Serialization::IArchive& ar)>(0x192B210);
};

// CRecoilOffset
// Header:  Prey/GameDll/weaponrecoiloffset.h
class CRecoilOffset
{ // Size=80 (0x50)
public:
	SStaticWeaponRecoilParams m_staticParams;
	Vec3 m_position;
	Vec3 m_fireDirection;
	Ang3 m_angle;
	Ang3 m_angleDirection;
	float m_fireTime;
	bool m_firstFire;

	CRecoilOffset();
	QuatT Compute(float frameTime) { alignas(QuatT) std::byte _return_buf_[sizeof(QuatT)]; return *FCompute(this, reinterpret_cast<QuatT*>(_return_buf_), frameTime); }
	void SetStaticParams(const SStaticWeaponRecoilParams& params) { FSetStaticParams(this, params); }
	void TriggerRecoil(bool firstFire) { FTriggerRecoil(this, firstFire); }

	static inline auto FCRecoilOffsetOv2 = PreyFunction<void(CRecoilOffset* const _this)>(0x192AF20);
	static inline auto FCompute = PreyFunction<QuatT*(CRecoilOffset* const _this, QuatT* _return_value_, float frameTime)>(0x192AF60);
	static inline auto FSetStaticParams = PreyFunction<void(CRecoilOffset* const _this, const SStaticWeaponRecoilParams& params)>(0x192B2D0);
	static inline auto FTriggerRecoil = PreyFunction<void(CRecoilOffset* const _this, bool firstFire)>(0x192B2F0);
};
#endif // !MOONCRASH
