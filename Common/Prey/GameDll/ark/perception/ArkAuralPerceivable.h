// Header file automatically created from a PDB.

#pragma once

// Header: Override
// Prey/GameDll/ark/perception/ArkAuralPerceivable.h
class ArkAuralPerceivable // Id=801431B Size=8
{
public:
	bool GetAuralPerceivableIsInVacuum() const { return FGetAuralPerceivableIsInVacuum(this); }
	bool GetAuralPerceivableIsComplexAttentionObject() const { return FGetAuralPerceivableIsComplexAttentionObject(this); }
	virtual unsigned DoGetEntityId() const = 0;
	virtual bool DoGetAuralPerceivableIsInVacuum() const = 0;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const = 0;
	
#if 0
	unsigned GetEntityId() const;
#endif
	
	static inline auto FGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkAuralPerceivable const *const _this)>(0x172F070);
	static inline auto FGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkAuralPerceivable const *const _this)>(0x15AAEA0);
};

