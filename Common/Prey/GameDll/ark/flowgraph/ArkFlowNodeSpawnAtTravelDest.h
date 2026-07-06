// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeSpawnAtTravelDest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSpawnAtTravelDest.h
class CArkFlowNodeSpawnAtTravelDest : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		token = 0,
		spawn = 1,
	};

	enum class EArkOutputs
	{
		spawned = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSpawnAtTravelDest(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSpawnAtTravelDest* const _this, SFlowNodeConfig& _config)>(0x15F39F0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSpawnAtTravelDest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F3CC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSpawnAtTravelDest* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
