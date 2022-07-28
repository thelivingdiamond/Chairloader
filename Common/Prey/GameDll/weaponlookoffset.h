// Header file automatically created from a PDB.

#pragma once
#include <_unknown/SGameWeaponSwayParams.h>

namespace Serialization
{
class IArchive;
} // namespace Serialization

// Header: FromCpp
// Prey/GameDll/weaponlookoffset.h
struct SStaticWeaponSwayParams // Id=8016D06 Size=108
{
	float easeFactorInc;
	float easeFactorDec;
	float strafeScopeFactor;
	float rotateScopeFactor;
	float velocityInterpolationMultiplier;
	float velocityLowPassFilter;
	float accelerationSmoothing;
	float accelerationFrontAugmentation;
	float verticalVelocityScale;
	float sprintCameraAnimation;
	Vec2 look_offset;
	Ang3 horiz_look_rot;
	Ang3 vert_look_rot;
	Vec3 strafe_offset;
	Ang3 side_strafe_rot;
	Ang3 front_strafe_rot;
	
	void Serialize(Serialization::IArchive &ar) { FSerialize(this,ar); }
	
	static inline auto FSerialize = PreyFunction<void(SStaticWeaponSwayParams *const _this, Serialization::IArchive &ar)>(0x1801E40);
};

// Header: FromCpp
// Prey/GameDll/weaponlookoffset.h
class CLookOffset // Id=8016D08 Size=168
{
public:
	SStaticWeaponSwayParams m_staticParams;
	SGameWeaponSwayParams m_gameParams;
	float m_interpHoriz;
	float m_interpVert;
	bool m_hasStaticParams;
	bool m_hasGameParams;
	
	CLookOffset();
	void SetStaticParams(SStaticWeaponSwayParams const &params) { FSetStaticParams(this,params); }
	void SetGameParams(SGameWeaponSwayParams const &params) { FSetGameParams(this,params); }
	QuatT Compute(float frameTime) { return FCompute(this,frameTime); }
	
#if 0
	SStaticWeaponSwayParams GetCurrentStaticParams() const;
#endif
	
	static inline auto FSetStaticParams = PreyFunction<void(CLookOffset *const _this, SStaticWeaponSwayParams const &params)>(0x18020F0);
	static inline auto FSetGameParams = PreyFunction<void(CLookOffset *const _this, SGameWeaponSwayParams const &params)>(0x18020C0);
	static inline auto FCompute = PreyFunction<QuatT(CLookOffset *const _this, float frameTime)>(0x1801770);
};

