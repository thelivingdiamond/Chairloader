// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkVisualPerceivable.h>

// Header: Override
// Prey/GameDll/ark/perception/ArkSimpleVisualPerceivable.h
class ArkSimpleVisualPerceivable : public ArkVisualPerceivable // Id=8014319 Size=8
{
public:
	Vec3 *GetSimpleVisualPerceivableWorldPoints(Vec3 *_pFirstWorldPoint, Vec3 *_pLastWorldPoint) const { return FGetSimpleVisualPerceivableWorldPoints(this,_pFirstWorldPoint,_pLastWorldPoint); }
	virtual Vec3 *DoGetSimpleVisualPerceivableWorldPoints(Vec3 *arg0, Vec3 *arg1) const = 0;
	
	static inline auto FGetSimpleVisualPerceivableWorldPoints = PreyFunction<Vec3 *(ArkSimpleVisualPerceivable const *const _this, Vec3 *_pFirstWorldPoint, Vec3 *_pLastWorldPoint)>(0x172F070);
};

