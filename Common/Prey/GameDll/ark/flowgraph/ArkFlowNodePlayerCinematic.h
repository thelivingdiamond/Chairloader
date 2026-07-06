// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodePlayerCinematic
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePlayerCinematic.h
class CArkFlowNodePlayerCinematic : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enter = 0,
		exit = 1,
		allowLook = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodePlayerCinematic(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePlayerCinematic* const _this, SFlowNodeConfig& _config)>(0x124A360);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePlayerCinematic* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124A720);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePlayerCinematic* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
