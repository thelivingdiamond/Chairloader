// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionbase.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkDisposition;
struct SFlowNodeConfig;

// ArkFlowNodeClearDispositionFactionFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionfactionfaction.h
class ArkFlowNodeClearDispositionFactionFaction : public ArkFlowNodeClearDispositionBase<ArkFlowNodeClearDispositionFactionFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeClearDispositionFactionFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeClearDispositionFactionFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const bool _arg1_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeClearDispositionFactionFaction* const _this, SFlowNodeConfig& config)>(0x15BB4D0);
};

// ArkFlowNodeGetDispositionFactionFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionfactionfaction.h
class ArkFlowNodeGetDispositionFactionFaction : public ArkFlowNodeGetDispositionBase<ArkFlowNodeGetDispositionFactionFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeGetDispositionFactionFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeGetDispositionFactionFaction(IFlowNode::SActivationInfo* _arg0_);
	EArkDisposition OnActivate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetDispositionFactionFaction* const _this, SFlowNodeConfig& config)>(0x15BB1D0);
};

// ArkFlowNodeSetDispositionFactionFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodedispositionfactionfaction.h
class ArkFlowNodeSetDispositionFactionFaction : public ArkFlowNodeSetDispositionBase<ArkFlowNodeSetDispositionFactionFaction>
{ // Size=16 (0x10)
public:
	virtual ~ArkFlowNodeSetDispositionFactionFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);

#if 0
	ArkFlowNodeSetDispositionFactionFaction(IFlowNode::SActivationInfo* _arg0_);
	void OnActivate(IFlowNode::SActivationInfo* _arg0_, const EArkDisposition _arg1_, const bool _arg2_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetDispositionFactionFaction* const _this, SFlowNodeConfig& config)>(0x15BAEA0);
};
#endif // MOONCRASH
