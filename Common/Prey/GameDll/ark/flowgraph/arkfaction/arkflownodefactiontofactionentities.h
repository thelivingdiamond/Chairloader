// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionFactionToFactionEntities
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactiontofactionentities.h
class ArkFlowNodeClearDispositionFactionToFactionEntities : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionToFactionEntities>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionFactionToFactionEntities();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionFactionToFactionEntities(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionFactionToFactionEntities* const _this, SFlowNodeConfig& config)>(0x15B91D0);
};

// ArkFlowNodeSetDispositionFactionToFactionEntities
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactiontofactionentities.h
class ArkFlowNodeSetDispositionFactionToFactionEntities : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionToFactionEntities>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionFactionToFactionEntities();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionFactionToFactionEntities(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionFactionToFactionEntities* const _this, SFlowNodeConfig& config)>(0x15B8E50);
};
#endif // MOONCRASH
