// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionEntityFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionentityfaction.h
class ArkFlowNodeClearDispositionEntityFaction : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionEntityFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionEntityFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionEntityFaction* const _this, SFlowNodeConfig& config)>(0x15B9D40);
};

// ArkFlowNodeGetDispositionEntityFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionentityfaction.h
class ArkFlowNodeGetDispositionEntityFaction : public ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionEntityFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionEntityFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeGetDispositionEntityFaction(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetDispositionEntityFaction* const _this, SFlowNodeConfig& config)>(0x15B9A20);
};

// ArkFlowNodeSetDispositionEntityFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionentityfaction.h
class ArkFlowNodeSetDispositionEntityFaction : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionEntityFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionEntityFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionEntityFaction* const _this, SFlowNodeConfig& config)>(0x15B96C0);
};
#endif // MOONCRASH
