// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <_unknown/IArkChecklistListener.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNode_CompleteChecklistEntry
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeprogress.h
class CArkFlowNode_CompleteChecklistEntry : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		checklistEntry = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_CompleteChecklistEntry(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_CompleteChecklistEntry* const _this, SFlowNodeConfig& _config)>(0x11E0CB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_CompleteChecklistEntry* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E0FD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_CompleteChecklistEntry* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_EnableChecklistEntry
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeprogress.h
class CArkFlowNode_EnableChecklistEntry : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		enable = 0,
		disable = 1,
		checklistEntry = 2,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_EnableChecklistEntry(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_EnableChecklistEntry* const _this, SFlowNodeConfig& _config)>(0x11E07B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_EnableChecklistEntry* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E0BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_EnableChecklistEntry* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_OnChecklistItemCompleted
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeprogress.h
class CArkFlowNode_OnChecklistItemCompleted : public CFlowBaseNode<1>, public IArkChecklistListener
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		checklist = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
		number = 1,
	};

	IFlowNode::SActivationInfo m_activationInfo;

	virtual ~CArkFlowNode_OnChecklistItemCompleted();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnChecklistItemCompleted(uint64_t _checklistId);

#if 0
	CArkFlowNode_OnChecklistItemCompleted(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_OnChecklistItemCompleted* const _this, SFlowNodeConfig& _config)>(0x11E17F0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_OnChecklistItemCompleted* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E1BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_OnChecklistItemCompleted* const _this, ICrySizer* _s)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNode_OnChecklistItemCompleted* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x11E1780);
	static inline auto FOnChecklistItemCompleted = PreyFunction<void(IArkChecklistListener* const _this, uint64_t _checklistId)>(0x11E1AA0);
};

// CArkFlowNode_TestChecklistEntry
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeprogress.h
class CArkFlowNode_TestChecklistEntry : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		checklistEntry = 1,
	};

	enum class EOutputs
	{
		output = 0,
		complete = 1,
		incomplete = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_TestChecklistEntry(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_TestChecklistEntry* const _this, SFlowNodeConfig& _config)>(0x11E10C0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_TestChecklistEntry* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E1440);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_TestChecklistEntry* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
