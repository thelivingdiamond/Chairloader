// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionEntityToFactionEntities
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeentitytofactionentities.h
class ArkFlowNodeClearDispositionEntityToFactionEntities : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionEntityToFactionEntities>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionEntityToFactionEntities();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionEntityToFactionEntities(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionEntityToFactionEntities* const _this, SFlowNodeConfig& config)>(0x15B68F0);
};

// ArkFlowNodeSetDispositionEntityToFactionEntities
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodeentitytofactionentities.h
class ArkFlowNodeSetDispositionEntityToFactionEntities : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionEntityToFactionEntities>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionEntityToFactionEntities();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionEntityToFactionEntities(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionEntityToFactionEntities* const _this, SFlowNodeConfig& config)>(0x15B6540);
};
#endif // MOONCRASH
