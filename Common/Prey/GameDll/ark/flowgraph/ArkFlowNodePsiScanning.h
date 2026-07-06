// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeEnableScope
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePsiScanning.h
class CArkFlowNodeEnableScope : public CFlowBaseNode<0>
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
	CArkFlowNodeEnableScope(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeEnableScope* const _this, SFlowNodeConfig& _config)>(0x15EF440);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeEnableScope* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EF9C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeEnableScope* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodePsiScanning
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePsiScanning.h
class CArkFlowNodePsiScanning : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		activate = 0,
		deactivate = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodePsiScanning(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePsiScanning* const _this, SFlowNodeConfig& _config)>(0x15EF700);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePsiScanning* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EFA40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePsiScanning* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
