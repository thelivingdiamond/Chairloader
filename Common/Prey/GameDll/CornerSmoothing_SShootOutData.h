// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/CornerSmoothing_SHermiteSpline.h>
#include <Prey/GameDll/CornerSmoothing_SPrediction_tpl.h>

namespace CornerSmoothing
{

// CornerSmoothing::SShootOutData
// Header:  _unknown/CornerSmoothing__SShootOutData.h
struct SShootOutData
{ // Size=772 (0x304)
	Vec3 moveTarget;
	bool hasInflectionPoint;
	Vec3 inflectionPoint;
	CornerSmoothing::SHermiteSpline spline;
	float minimumTurnRadius;
	CornerSmoothing::SPrediction_tpl<CornerSmoothing::SSplineSample> prediction;
	CornerSmoothing::SPrediction_tpl<CornerSmoothing::SSimpleSample> simplifiedPrediction;

#if 0
	float GetMaximumEntrySpeedSq() const;
	float GetMaximumExitSpeedSq() const;
	void SetMaximumExitSpeedSq(const float _arg0_);
	float GetLength() const;
#endif
};


} // namespace CornerSmoothing

