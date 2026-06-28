// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeEntityLink
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeEntityLink.h
class CArkFlowNodeEntityLink : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPorts
	{
		linkToEntity = 0,
		addLink = 1,
		removeLink = 2,
	};

	enum class OutPorts
	{
		out = 0,
	};

	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeEntityLink(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeEntityLink* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeEntityLink* const _this, SFlowNodeConfig& _config)>(0x13144B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeEntityLink* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1314870);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeEntityLink* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
