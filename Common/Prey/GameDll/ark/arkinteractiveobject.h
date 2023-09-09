// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/perception/ArkAuralPerceivable.h>

class ArkInteractiveMachine;
class ArkInteractiveObject;

// Header: FromCpp
// Prey/GameDll/ark/arkinteractiveobject.h
class ArkInteractiveMachinePerceivable : public ArkAuralPerceivable // Id=8019072 Size=16
{
public:
	ArkInteractiveMachine const &m_machine;

    ArkInteractiveMachinePerceivable();
	virtual unsigned DoGetEntityId() const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkInteractiveMachinePerceivable const *const _this)>(0x1184710);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkInteractiveMachinePerceivable const *const _this)>(0xDD23F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkInteractiveMachinePerceivable const *const _this)>(0xDD23F0);
};

// Header: FromCpp
// Prey/GameDll/ark/arkinteractiveobject.h
class ArkInteractiveObjectPerceivable : public ArkAuralPerceivable // Id=8019362 Size=16
{
public:
	ArkInteractiveObject const &m_interactiveObject;

    ArkInteractiveObjectPerceivable();
	virtual unsigned DoGetEntityId() const;
	virtual bool DoGetAuralPerceivableIsInVacuum() const;
	virtual bool DoGetAuralPerceivableIsComplexAttentionObject() const;
	
	static inline auto FDoGetEntityId = PreyFunction<unsigned(ArkInteractiveObjectPerceivable const *const _this)>(0x1184710);
	static inline auto FDoGetAuralPerceivableIsInVacuum = PreyFunction<bool(ArkInteractiveObjectPerceivable const *const _this)>(0xDD23F0);
	static inline auto FDoGetAuralPerceivableIsComplexAttentionObject = PreyFunction<bool(ArkInteractiveObjectPerceivable const *const _this)>(0xDD23F0);
};

