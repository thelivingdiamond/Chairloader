// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeChangeHelmet
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeHelmet.h
class CArkFlowNodeChangeHelmet : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		none = 0,
		standard = 1,
		special = 2,
	};

	enum class EOutputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeChangeHelmet(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeChangeHelmet* const _this, SFlowNodeConfig& _config)>(0x1318E70);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeChangeHelmet* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1319280);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeChangeHelmet* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeHelmet
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeHelmet.h
class CArkFlowNodeHelmet : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		query = 0,
		on = 1,
		off = 2,
	};

	enum class EOutputs
	{
		out = 0,
		on = 1,
		off = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeHelmet(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHelmet* const _this, SFlowNodeConfig& _config)>(0x1318910);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHelmet* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1318D10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHelmet* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
