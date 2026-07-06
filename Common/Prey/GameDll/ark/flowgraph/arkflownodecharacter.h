// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeSetCharacterAlternateName
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecharacter.h
class ArkFlowNodeSetCharacterAlternateName : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		character = 1,
		name = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeSetCharacterAlternateName(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetCharacterAlternateName* const _this, SFlowNodeConfig& _rConfig)>(0x1313D70);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetCharacterAlternateName* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x13141E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeSetCharacterAlternateName* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
