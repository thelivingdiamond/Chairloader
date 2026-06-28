// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	
	static inline auto FGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity **(ArkVisualPerceivable const *const _this, IPhysicalEntity **_ppFirstPhysicalEntity, IPhysicalEntity **_ppLastPhysicalEntity)>(0x13B26F0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

struct IPhysicalEntity;

// ArkVisualPerceivable
// Header:  Prey/GameDll/ark/perception/ArkVisualPerceivable.h
class ArkVisualPerceivable
{ // Size=8 (0x8)
public:
	IPhysicalEntity* * GetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const { return FGetIgnoredPhysicalEntitiesInLineOfSight(this, _ppFirstPhysicalEntity, _ppLastPhysicalEntity); }
	virtual IPhysicalEntity* * DoGetIgnoredPhysicalEntitiesInLineOfSight(IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity) const = 0;

#if 0
	~ArkVisualPerceivable();
	ArkVisualPerceivable& operator=(const ArkVisualPerceivable& _arg0_);
#endif

	static inline auto FGetIgnoredPhysicalEntitiesInLineOfSight = PreyFunction<IPhysicalEntity* * (const ArkVisualPerceivable* const _this, IPhysicalEntity* * _ppFirstPhysicalEntity, IPhysicalEntity* * _ppLastPhysicalEntity)>(0x14BE950);
};
#endif // !MOONCRASH
