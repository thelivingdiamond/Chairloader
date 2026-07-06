// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeEffectiveDisposition_FactionToEntity
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/ArkFlowNodeEffectiveDisposition_FactionToEntity.h
class ArkFlowNodeEffectiveDisposition_FactionToEntity : public ArkFlowNodeGetDispositionBase<ArkFlowNodeEffectiveDisposition_FactionToEntity>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeEffectiveDisposition_FactionToEntity();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeEffectiveDisposition_FactionToEntity(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeEffectiveDisposition_FactionToEntity* const _this, SFlowNodeConfig& config)>(0x15B6120);
};
#endif // MOONCRASH
