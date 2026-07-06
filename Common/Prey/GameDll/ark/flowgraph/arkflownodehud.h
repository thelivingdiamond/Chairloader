// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_EnableHUDArmor
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehud.h
class CArkFlowNode_EnableHUDArmor : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EnableHUDArmor(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EnableHUDArmor* const _this, SFlowNodeConfig& _config)>(0x1513B70);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EnableHUDArmor* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15140F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EnableHUDArmor* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_EnableHUDHealth
// Header:  Prey/GameDll/ark/flowgraph/arkflownodehud.h
class CArkFlowNode_EnableHUDHealth : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EnableHUDHealth(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EnableHUDHealth* const _this, SFlowNodeConfig& _config)>(0x1513E30);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EnableHUDHealth* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1514180);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EnableHUDHealth* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
