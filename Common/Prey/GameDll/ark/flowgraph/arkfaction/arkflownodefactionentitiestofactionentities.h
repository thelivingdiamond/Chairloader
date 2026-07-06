// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactionentitiestofactionentities.h
class ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionFactionEntitiesToFactionEntities* const _this, SFlowNodeConfig& config)>(0x15B4DE0);
};

// ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactionentitiestofactionentities.h
class ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionFactionEntitiesToFactionEntities* const _this, SFlowNodeConfig& config)>(0x15B4A60);
};
#endif // MOONCRASH
