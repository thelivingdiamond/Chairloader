// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeRenderAlways
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeRenderAlways.h
class CArkFlowNodeRenderAlways : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPorts
	{
		k_enable = 0,
		k_disable = 1,
	};

	enum class OutPorts
	{
		k_out = 0,
	};

	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeRenderAlways(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeRenderAlways* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeRenderAlways* const _this, SFlowNodeConfig& _config)>(0x124CAE0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeRenderAlways* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124CDC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeRenderAlways* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
