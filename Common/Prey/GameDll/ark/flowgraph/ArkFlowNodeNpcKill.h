// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeNpcKill
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcKill.h
class CArkFlowNodeNpcKill : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class InPorts
	{
		k_activate = 0,
		k_entityId = 1,
		k_archetype = 2,
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
	CArkFlowNodeNpcKill(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeNpcKill* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x1333E90);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeNpcKill* const _this, SFlowNodeConfig& _config)>(0x151AA10);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeNpcKill* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x151AE30);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeNpcKill* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
