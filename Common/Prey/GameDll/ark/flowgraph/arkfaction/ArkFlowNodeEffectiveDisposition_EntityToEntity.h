// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeEffectiveDisposition_EntityToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/ArkFlowNodeEffectiveDisposition_EntityToEntity.h
class ArkFlowNodeEffectiveDisposition_EntityToEntity : public ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEffectiveDisposition_EntityToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEffectiveDisposition_EntityToEntity(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEffectiveDisposition_EntityToEntity* const _this, SFlowNodeConfig& config)>(0x15B7540);
};
#endif // MOONCRASH
