// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeEffectiveDisposition_EntityToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/ArkFlowNodeEffectiveDisposition_EntityToFaction.h
class ArkFlowNodeEffectiveDisposition_EntityToFaction : public ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_EntityToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEffectiveDisposition_EntityToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEffectiveDisposition_EntityToFaction(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEffectiveDisposition_EntityToFaction* const _this, SFlowNodeConfig& config)>(0x15B5DC0);
};
#endif // MOONCRASH
