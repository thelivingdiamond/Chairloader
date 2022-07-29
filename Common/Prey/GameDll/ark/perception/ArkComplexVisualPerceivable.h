// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkVisualPerceivable.h>

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkComplexVisualPerceivable.h
class ArkComplexVisualPerceivable : public ArkVisualPerceivable // Id=8016220 Size=8
{
public:
	std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *> GetComplexVisualPerceivableWorldPoints(Vec3 *_pFirstAnyWorldPoint, Vec3 *_pLastAnyWorldPoint, Vec3 *_pFirstAcuteWorldPoint, Vec3 *_pLastAcuteWorldPoint, Vec3 *_pFirstAllWorldPoint, Vec3 *_pLastAllWorldPoint) const { return FGetComplexVisualPerceivableWorldPoints(this,_pFirstAnyWorldPoint,_pLastAnyWorldPoint,_pFirstAcuteWorldPoint,_pLastAcuteWorldPoint,_pFirstAllWorldPoint,_pLastAllWorldPoint); }
	float GetVisibilityScalar() const { return FGetVisibilityScalar(this); }
	virtual std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *> DoGetComplexVisualPerceivableWorldPoints(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2, Vec3 *arg3, Vec3 *arg4, Vec3 *arg5) const = 0;
	virtual float DoGetVisibilityScalar() const = 0;
	
	static inline auto FGetComplexVisualPerceivableWorldPoints = PreyFunction<std::tuple<Vec3_tpl<float> *,Vec3_tpl<float> *,Vec3_tpl<float> *>(ArkComplexVisualPerceivable const *const _this, Vec3 *_pFirstAnyWorldPoint, Vec3 *_pLastAnyWorldPoint, Vec3 *_pFirstAcuteWorldPoint, Vec3 *_pLastAcuteWorldPoint, Vec3 *_pFirstAllWorldPoint, Vec3 *_pLastAllWorldPoint)>(0x1528750);
	static inline auto FGetVisibilityScalar = PreyFunction<float(ArkComplexVisualPerceivable const *const _this)>(0x15AAEA0);
};

