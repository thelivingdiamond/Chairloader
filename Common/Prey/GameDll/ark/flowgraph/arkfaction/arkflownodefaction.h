// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/flowgraph/arkfaction/arkfactionflowgraphcommon.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct SFlowNodeConfig;

// ArkFlowNodeGetFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefaction.h
class ArkFlowNodeGetFaction : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		activate = 0,
	};

	enum class EOutput
	{
		factionName = 0,
		noFaction = 1,
	};

	virtual ~ArkFlowNodeGetFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeGetFaction(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetFaction* const _this, SFlowNodeConfig& config)>(0x15B6FF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetFaction* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B71E0);
};

// ArkFlowNodeSetFaction
// Header:  Prey/GameDll/ark/flowgraph/arkfaction/arkflownodefaction.h
class ArkFlowNodeSetFaction : public ArkFactionFlow::ArkFlowNodeFactionBase
{ // Size=16 (0x10)
public:
	enum class EInput
	{
		activate = 0,
		faction = 1,
	};

	enum class EOutput
	{
		succeeded = 0,
		failed = 1,
		out = 2,
	};

	virtual ~ArkFlowNodeSetFaction();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);

#if 0
	ArkFlowNodeSetFaction(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetFaction* const _this, SFlowNodeConfig& config)>(0x15B6C30);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetFaction* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15B6EF0);
};
#endif // MOONCRASH
