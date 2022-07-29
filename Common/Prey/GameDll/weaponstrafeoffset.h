// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/weaponlookoffset.h>
#include <Prey/GameDll/SGameWeaponSwayParams.h>

// Header: FromCpp
// Prey/GameDll/weaponstrafeoffset.h
class CStrafeOffset // Id=8016D27 Size=200
{
public:
	SStaticWeaponSwayParams m_staticParams;
	SGameWeaponSwayParams m_gameParams;
	Vec3 m_smoothedVelocity;
	Vec3 m_lastVelocity;
	float m_interpFront;
	float m_interpSide;
	float m_runFactor;
	float m_sprintFactor;
	float m_noiseFactor;
	
	CStrafeOffset();
	void SetStaticParams(SStaticWeaponSwayParams const &params) { FSetStaticParams(this,params); }
	void SetGameParams(SGameWeaponSwayParams const &params) { FSetGameParams(this,params); }
	QuatT Compute(float frameTime) { return FCompute(this,frameTime); }
	
	static inline auto FSetStaticParams = PreyFunction<void(CStrafeOffset *const _this, SStaticWeaponSwayParams const &params)>(0x18040A0);
	static inline auto FSetGameParams = PreyFunction<void(CStrafeOffset *const _this, SGameWeaponSwayParams const &params)>(0x1804080);
	static inline auto FCompute = PreyFunction<QuatT(CStrafeOffset *const _this, float frameTime)>(0x18039C0);
};

