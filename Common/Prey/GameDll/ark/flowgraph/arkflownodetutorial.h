// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNode_CollectTutorialCard
// Header:  Prey/GameDll/ark/flowgraph/arkflownodetutorial.h
class CArkFlowNode_CollectTutorialCard : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		tutorial = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_CollectTutorialCard(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_CollectTutorialCard* const _this, SFlowNodeConfig& _config)>(0x152A9D0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_CollectTutorialCard* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152B7A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_CollectTutorialCard* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_DisplayTutorial
// Header:  Prey/GameDll/ark/flowgraph/arkflownodetutorial.h
class CArkFlowNode_DisplayTutorial : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EInputs
	{
		trigger = 0,
		tutorial = 1,
	};

	enum class EOutputs
	{
		callback = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void CallbackTriggered() { FCallbackTriggered(this); }

#if 0
	CArkFlowNode_DisplayTutorial(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_DisplayTutorial* const _this, SFlowNodeConfig& _config)>(0x152ACB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_DisplayTutorial* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152B920);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_DisplayTutorial* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNode_DisplayTutorial* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x152A970);
	static inline auto FCallbackTriggered = PreyFunction<void(CArkFlowNode_DisplayTutorial* const _this)>(0x1712A50);
};

// CArkFlowNode_EnableGameStateCondition
// Header:  Prey/GameDll/ark/flowgraph/arkflownodetutorial.h
class CArkFlowNode_EnableGameStateCondition : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
		condition = 2,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EnableGameStateCondition(IFlowNode::SActivationInfo* _arg0_);
	void CallbackTriggered();
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EnableGameStateCondition* const _this, SFlowNodeConfig& _config)>(0x152AFD0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EnableGameStateCondition* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152BB50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EnableGameStateCondition* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_QueueTutorials
// Header:  Prey/GameDll/ark/flowgraph/arkflownodetutorial.h
class CArkFlowNode_QueueTutorials : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		queue = 0,
		resume = 1,
		forceResume = 2,
	};

	enum class EOutputs
	{
		queued = 0,
		resumed = 1,
		forceResumed = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_QueueTutorials(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_QueueTutorials* const _this, SFlowNodeConfig& _config)>(0x152B3C0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_QueueTutorials* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x152BD30);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_QueueTutorials* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
