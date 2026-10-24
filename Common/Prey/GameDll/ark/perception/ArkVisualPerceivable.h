// Header file automatically created from a PDB.

#pragma once

struct IPhysicalEntity;

// Header: Override
// Prey/GameDll/ark/perception/ArkVisualPerceivable.h
class ArkVisualPerceivable // Id=801431A Size=8
{
public:
	IPhysicalEntity **GetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity) const { return FGetIgnoredPhysicalEntitiesInLineOfSight(this,_ppFirstPhysicalEntity,_ppLastPhysicalEntity); }
	virtual IPhysicalEntity **DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity **arg0, IPhysicalEntity **arg1) const = 0;
	
#ifndef MOONCRASH
	static inline auto FGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkVisualPerceivable const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x13B26F0);
#else
	static inline auto FGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkVisualPerceivable* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x14BE950);
#endif
};
