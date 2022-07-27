// Header file automatically created from a PDB.

#pragma once

template <typename UnusedType>
class ArkDelegate;

template <typename RT, typename ... AT>
class ArkDelegate<RT(AT ...)> // Id=8013774 Size=16
{
public:
	using ReturnType = RT;
	using CallerFuncPtr = RT (*)(AT ...);

	void* m_pObject;
	CallerFuncPtr m_pCaller;

#if 0
	//int* operator int ArkSafeBool<class ArkDelegate<void __cdecl(unsigned int)> >::* () const;
	void operator()(unsigned arg0) const;
	void Swap(ArkDelegate& arg0);
#endif
};

#if 0
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ArkObjectiveComponent;
class ICrySizer;
struct SFlowNodeConfig;

// Header: Exact
// Prey/ArkCommon/arkdelegate.h
class ArkFlowNodeObjectiveState : public CFlowBaseNode<1> // Id=801680C Size=64
{
public:
	enum class EInputs
	{
		OBJECTIVE = 0,
		ASSIGN = 1,
		UNASSIGN = 2,
		COMPLETE = 3,
		FAIL = 4,
		SETTRACKED = 5,
		SHOWONHUD = 6,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
		ASSIGNED = 1,
		UNASSIGNED = 2,
		COMPLETED = 3,
		FAILED = 4,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnObjectiveAssigned() { FOnObjectiveAssigned(this); }
	void OnObjectiveUnassigned() { FOnObjectiveUnassigned(this); }
	void OnObjectiveCompleted() { FOnObjectiveCompleted(this); }
	void OnObjectiveFailed() { FOnObjectiveFailed(this); }

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeObjectiveState* const _this, SFlowNodeConfig& _rConfig)>(0x14D17C0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeObjectiveState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14D2020);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeObjectiveState const* const _this, ICrySizer* _pS)>(0x1187D80);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>(ArkFlowNodeObjectiveState* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x14D15A0);
	static inline auto FOnObjectiveAssigned = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x11C6510);
	static inline auto FOnObjectiveUnassigned = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x11C64D0);
	static inline auto FOnObjectiveCompleted = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x14D95F0);
	static inline auto FOnObjectiveFailed = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x14D1FE0);
};

// Header: Exact
// Prey/ArkCommon/arkdelegate.h
class ArkFlowNodeTaskState : public CFlowBaseNode<1> // Id=801680D Size=64
{
public:
	enum class EInputs
	{
		TASK = 0,
		ACTIVATE = 1,
		DEACTIVATE = 2,
		COMPLETE = 3,
		FAIL = 4,
		SHOWONHUD = 5,
		TIMER = 6,
		SHOWTIMERONHUD = 7,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
		ACTIVATED = 1,
		DEACTIVATED = 2,
		COMPLETED = 3,
		FAILED = 4,
		TIME_ELAPSED = 5,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnTaskActivated() { FOnTaskActivated(this); }
	void OnTaskDeactivated() { FOnTaskDeactivated(this); }
	void OnTaskCompleted() { FOnTaskCompleted(this); }
	void OnTaskFailed() { FOnTaskFailed(this); }
	void OnTaskTimeElapsed() { FOnTaskTimeElapsed(this); }
	void CallCommon(void (* const _pFunc)(const int64_t), IFlowNode::SActivationInfo& _rActInfo) { FCallCommon(this, _pFunc, _rActInfo); }

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeTaskState* const _this, SFlowNodeConfig& _rConfig)>(0x14D8CC0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeTaskState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14D9630);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeTaskState const* const _this, ICrySizer* _pS)>(0x1187D80);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>(ArkFlowNodeTaskState* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x14D89F0);
	static inline auto FOnTaskActivated = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x11C6510);
	static inline auto FOnTaskDeactivated = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x11C64D0);
	static inline auto FOnTaskCompleted = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x14D95F0);
	static inline auto FOnTaskFailed = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x14D1FE0);
	static inline auto FOnTaskTimeElapsed = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x14BE670);
	static inline auto FCallCommon = PreyFunction<void(ArkFlowNodeTaskState* const _this, void (* const _pFunc)(const int64_t), IFlowNode::SActivationInfo& _rActInfo)>(0x14D8AC0);
};

// Header: Exact
// Prey/ArkCommon/arkdelegate.h
class CArkFlowNodeWorkstationResult : public CFlowBaseNode<1> // Id=801BCC1 Size=64
{
public:
	enum class EArkInputs
	{
		trigger = 0,
		clear = 1,
		title = 2,
		body = 3,
		error = 4,
	};

	enum class EArkOutputs
	{
		output = 0,
		confirmed = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnResultConfirmation() { FOnResultConfirmation(this); }

#if 0
	IFlowNode::SActivationInfo const& GetActivationInfo() const;
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeWorkstationResult* const _this, SFlowNodeConfig& _rConfig)>(0x14BDD40);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeWorkstationResult* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x14BEC40);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkFlowNodeWorkstationResult const* const _this, ICrySizer* _pS)>(0x1187D80);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>(CArkFlowNodeWorkstationResult* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x14BC7D0);
	static inline auto FOnResultConfirmation = PreyFunction<void(CArkFlowNodeWorkstationResult* const _this)>(0x11C6510);
};

// Header: Exact
// Prey/ArkCommon/arkdelegate.h
class CArkFlowNodeConfirmDialog : public CFlowBaseNode<1> // Id=801CBA9 Size=64
{
public:
	enum class EArkInputs
	{
		trigger = 0,
		label = 1,
		query = 2,
	};

	enum class EArkOutputs
	{
		onConfirm = 0,
		onCancel = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnConfirm() { FOnConfirm(this); }
	void OnCancel() { FOnCancel(this); }

#if 0
	void ProcessOutput(CArkFlowNodeConfirmDialog::EArkOutputs arg0);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this, SFlowNodeConfig& _rConfig)>(0x15F16B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1FC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(CArkFlowNodeConfirmDialog const* const _this, ICrySizer* _pS)>(0x1187D80);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>(CArkFlowNodeConfirmDialog* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1650);
	static inline auto FOnConfirm = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this)>(0x1414860);
	static inline auto FOnCancel = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this)>(0x11C6510);
};

#endif
