// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionFactionEntitiesToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactionentitiestofaction.h
class ArkFlowNodeClearDispositionFactionEntitiesToFaction : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionEntitiesToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionFactionEntitiesToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionFactionEntitiesToFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionFactionEntitiesToFaction* const _this, SFlowNodeConfig& config)>(0x15B5620);
};

// ArkFlowNodeSetDispositionFactionEntitiesToFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefactionentitiestofaction.h
class ArkFlowNodeSetDispositionFactionEntitiesToFaction : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionEntitiesToFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionFactionEntitiesToFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionFactionEntitiesToFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionFactionEntitiesToFaction* const _this, SFlowNodeConfig& config)>(0x15B52A0);
};
#endif // MOONCRASH
