// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_EndGame
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegame.h
class CArkFlowNode_EndGame : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EndGame(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EndGame* const _this, SFlowNodeConfig& _config)>(0x12420E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EndGame* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x12422D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EndGame* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_PopulateEndGameUI
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegame.h
class CArkFlowNode_PopulateEndGameUI : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_PopulateEndGameUI(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_PopulateEndGameUI* const _this, SFlowNodeConfig& _config)>(0x1242420);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_PopulateEndGameUI* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1242610);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_PopulateEndGameUI* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
