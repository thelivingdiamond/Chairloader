// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryScriptSystem/IScriptSystem.h>

struct IFunctionHandler;
struct ISystem;

// Header: FromCpp
// Prey/GameDll/ark/scriptbind_arkfaction.h
class CScriptBind_ArkFaction : public CScriptableBase // Id=801663C Size=96
{
public:
	CScriptBind_ArkFaction(ISystem *pSystem);
	int GetEntityFaction(IFunctionHandler *pH) { return FGetEntityFaction(this,pH); }
	int SetEntityFaction(IFunctionHandler *pH) { return FSetEntityFaction(this,pH); }
	int GetEffectiveEntityDispositionTowardsEntity(IFunctionHandler *pH) { return FGetEffectiveEntityDispositionTowardsEntity(this,pH); }
	int GetEffectiveEntityDispositionTowardsFaction(IFunctionHandler *pH) { return FGetEffectiveEntityDispositionTowardsFaction(this,pH); }
	int GetEffectiveFactionDispositionTowardsEntity(IFunctionHandler *pH) { return FGetEffectiveFactionDispositionTowardsEntity(this,pH); }
	int GetEffectiveFactionDispositionTowardsFaction(IFunctionHandler *pH) { return FGetEffectiveFactionDispositionTowardsFaction(this,pH); }
	int GetAssignedFactionDispositionTowardsFaction(IFunctionHandler *pH) { return FGetAssignedFactionDispositionTowardsFaction(this,pH); }
	int GetAssignedEntityDispositionTowardsEntity(IFunctionHandler *pH) { return FGetAssignedEntityDispositionTowardsEntity(this,pH); }
	int GetAssignedEntityDispositionTowardsFaction(IFunctionHandler *pH) { return FGetAssignedEntityDispositionTowardsFaction(this,pH); }
	int GetAssignedFactionDispositionTowardsEntity(IFunctionHandler *pH) { return FGetAssignedFactionDispositionTowardsEntity(this,pH); }
	int SetFactionDispositionTowardFaction(IFunctionHandler *pH) { return FSetFactionDispositionTowardFaction(this,pH); }
	int SetFactionDispositionTowardsEntity(IFunctionHandler *pH) { return FSetFactionDispositionTowardsEntity(this,pH); }
	int SetFactionDispositionTowardsFactionEntities(IFunctionHandler *pH) { return FSetFactionDispositionTowardsFactionEntities(this,pH); }
	int SetFactionEntitiesDispositionTowardsFaction(IFunctionHandler *pH) { return FSetFactionEntitiesDispositionTowardsFaction(this,pH); }
	int SetFactionEntitiesDispositionTowardsEntity(IFunctionHandler *pH) { return FSetFactionEntitiesDispositionTowardsEntity(this,pH); }
	int SetFactionEntitiesDispositionTowardsFactionEntities(IFunctionHandler *pH) { return FSetFactionEntitiesDispositionTowardsFactionEntities(this,pH); }
	int SetEntityDispositionTowardsEntity(IFunctionHandler *pH) { return FSetEntityDispositionTowardsEntity(this,pH); }
	int SetEntityDispositionTowardsFaction(IFunctionHandler *pH) { return FSetEntityDispositionTowardsFaction(this,pH); }
	int SetEntityDispositionTowardsFactionEntities(IFunctionHandler *pH) { return FSetEntityDispositionTowardsFactionEntities(this,pH); }
	int ClearFactionDispositionTowardFaction(IFunctionHandler *pH) { return FClearFactionDispositionTowardFaction(this,pH); }
	int ClearFactionDispositionTowardsEntity(IFunctionHandler *pH) { return FClearFactionDispositionTowardsEntity(this,pH); }
	int ClearFactionDispositionTowardsFactionEntities(IFunctionHandler *pH) { return FClearFactionDispositionTowardsFactionEntities(this,pH); }
	int ClearFactionEntitiesDispositionTowardsFaction(IFunctionHandler *pH) { return FClearFactionEntitiesDispositionTowardsFaction(this,pH); }
	int ClearFactionEntitiesDispositionTowardsEntity(IFunctionHandler *pH) { return FClearFactionEntitiesDispositionTowardsEntity(this,pH); }
	int ClearFactionEntitiesDispositionTowardsFactionEntities(IFunctionHandler *pH) { return FClearFactionEntitiesDispositionTowardsFactionEntities(this,pH); }
	int ClearEntityDispositionTowardsEntity(IFunctionHandler *pH) { return FClearEntityDispositionTowardsEntity(this,pH); }
	int ClearEntityDispositionTowardsFaction(IFunctionHandler *pH) { return FClearEntityDispositionTowardsFaction(this,pH); }
	int ClearEntityDispositionTowardsFactionEntities(IFunctionHandler *pH) { return FClearEntityDispositionTowardsFactionEntities(this,pH); }
	int EndFactionHostilityWithEntity(IFunctionHandler *pH) { return FEndFactionHostilityWithEntity(this,pH); }
	int EndFactionHostilityWithFaction(IFunctionHandler *pH) { return FEndFactionHostilityWithFaction(this,pH); }
	int EndEntityHostilityWithEntity(IFunctionHandler *pH) { return FEndEntityHostilityWithEntity(this,pH); }
	int EndEntityHostilityWithFaction(IFunctionHandler *pH) { return FEndEntityHostilityWithFaction(this,pH); }
	int IsFactionFriendlyToFaction(IFunctionHandler *pH) { return FIsFactionFriendlyToFaction(this,pH); }
	int IsFactionNeutralToFaction(IFunctionHandler *pH) { return FIsFactionNeutralToFaction(this,pH); }
	int IsFactionHostileToFaction(IFunctionHandler *pH) { return FIsFactionHostileToFaction(this,pH); }
	int IsFactionFriendlyToEntity(IFunctionHandler *pH) { return FIsFactionFriendlyToEntity(this,pH); }
	int IsFactionNeutralToEntity(IFunctionHandler *pH) { return FIsFactionNeutralToEntity(this,pH); }
	int IsFactionHostileToEntity(IFunctionHandler *pH) { return FIsFactionHostileToEntity(this,pH); }
	int IsEntityFriendlyToFaction(IFunctionHandler *pH) { return FIsEntityFriendlyToFaction(this,pH); }
	int IsEntityNeutralToFaction(IFunctionHandler *pH) { return FIsEntityNeutralToFaction(this,pH); }
	int IsEntityHostileToFaction(IFunctionHandler *pH) { return FIsEntityHostileToFaction(this,pH); }
	int IsEntityFriendlyToEntity(IFunctionHandler *pH) { return FIsEntityFriendlyToEntity(this,pH); }
	int IsEntityNeutralToEntity(IFunctionHandler *pH) { return FIsEntityNeutralToEntity(this,pH); }
	int IsEntityHostileToEntity(IFunctionHandler *pH) { return FIsEntityHostileToEntity(this,pH); }
	virtual ~CScriptBind_ArkFaction();
	
#if 0
	void RegisterGlobals() const;
#endif
	
	static inline auto FGetEntityFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CBB40);
	static inline auto FSetEntityFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CD230);
	static inline auto FGetEffectiveEntityDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB5E0);
	static inline auto FGetEffectiveEntityDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB700);
	static inline auto FGetEffectiveFactionDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB820);
	static inline auto FGetEffectiveFactionDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB950);
	static inline auto FGetAssignedFactionDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB4C0);
	static inline auto FGetAssignedEntityDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB160);
	static inline auto FGetAssignedEntityDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB280);
	static inline auto FGetAssignedFactionDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CB3A0);
	static inline auto FSetFactionDispositionTowardFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CD350);
	static inline auto FSetFactionDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CD590);
	static inline auto FSetFactionDispositionTowardsFactionEntities = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CD7D0);
	static inline auto FSetFactionEntitiesDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CDC50);
	static inline auto FSetFactionEntitiesDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CDA10);
	static inline auto FSetFactionEntitiesDispositionTowardsFactionEntities = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CDE90);
	static inline auto FSetEntityDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CCB70);
	static inline auto FSetEntityDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CCDB0);
	static inline auto FSetEntityDispositionTowardsFactionEntities = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CCFF0);
	static inline auto FClearFactionDispositionTowardFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CA120);
	static inline auto FClearFactionDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CA2C0);
	static inline auto FClearFactionDispositionTowardsFactionEntities = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CA460);
	static inline auto FClearFactionEntitiesDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CA7A0);
	static inline auto FClearFactionEntitiesDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CA600);
	static inline auto FClearFactionEntitiesDispositionTowardsFactionEntities = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CA940);
	static inline auto FClearEntityDispositionTowardsEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15C9C40);
	static inline auto FClearEntityDispositionTowardsFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15C9DE0);
	static inline auto FClearEntityDispositionTowardsFactionEntities = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15C9F80);
	static inline auto FEndFactionHostilityWithEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CAE20);
	static inline auto FEndFactionHostilityWithFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CAFC0);
	static inline auto FEndEntityHostilityWithEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CAAE0);
	static inline auto FEndEntityHostilityWithFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CAC80);
	static inline auto FIsFactionFriendlyToFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC5D0);
	static inline auto FIsFactionNeutralToFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CCA50);
	static inline auto FIsFactionHostileToFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC810);
	static inline auto FIsFactionFriendlyToEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC4B0);
	static inline auto FIsFactionNeutralToEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC930);
	static inline auto FIsFactionHostileToEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC6F0);
	static inline auto FIsEntityFriendlyToFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CBF10);
	static inline auto FIsEntityNeutralToFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC390);
	static inline auto FIsEntityHostileToFaction = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC150);
	static inline auto FIsEntityFriendlyToEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CBDF0);
	static inline auto FIsEntityNeutralToEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC270);
	static inline auto FIsEntityHostileToEntity = PreyFunction<int(CScriptBind_ArkFaction *const _this, IFunctionHandler *pH)>(0x15CC030);
};

