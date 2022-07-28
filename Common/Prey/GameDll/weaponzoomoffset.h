// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/weaponoffset.h>

// Header: FromCpp
// Prey/GameDll/weaponzoomoffset.h
class CWeaponZoomOffset // Id=8016D09 Size=208
{
public:
	CWeaponOffsetStack m_shoulderOffset;
	CWeaponOffsetStack m_leftHandOffset;
	SWeaponOffset m_zoomOffset;
	float m_zoomRotation;
	float m_zoomTransition;
	
	CWeaponZoomOffset();
	QuatT Compute(float frameTime) { return FCompute(this,frameTime); }
	QuatT GetLeftHandOffset(float frameTime) { return FGetLeftHandOffsetOv1(this,frameTime); }
	void SetZoomTransition(float transition) { FSetZoomTransition(this,transition); }
	void SetZoomTransitionRotation(float rotation) { FSetZoomTransitionRotation(this,rotation); }
	
#if 0
	CWeaponOffsetStack &GetLeftHandOffset();
	CWeaponOffsetStack &GetShoulderOffset();
	SWeaponOffset &GetZommOffset();
#endif
	
	static inline auto FCompute = PreyFunction<QuatT(CWeaponZoomOffset *const _this, float frameTime)>(0x1804180);
	static inline auto FGetLeftHandOffsetOv1 = PreyFunction<QuatT(CWeaponZoomOffset *const _this, float frameTime)>(0x18044B0);
	static inline auto FSetZoomTransition = PreyFunction<void(CWeaponZoomOffset *const _this, float transition)>(0x1804780);
	static inline auto FSetZoomTransitionRotation = PreyFunction<void(CWeaponZoomOffset *const _this, float rotation)>(0x1804790);
};

