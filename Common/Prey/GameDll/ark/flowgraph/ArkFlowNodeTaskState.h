// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeTaskState
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeTaskState.h
class ArkFlowNodeTaskState : public CFlowBaseNode<1>
{ // Size=64 (0x40)
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

	virtual ~ArkFlowNodeTaskState();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnTaskActivated() { FOnTaskActivated(this); }
	void OnTaskDeactivated() { FOnTaskDeactivated(this); }
	void OnTaskCompleted() { FOnTaskCompleted(this); }
	void OnTaskFailed() { FOnTaskFailed(this); }
	void OnTaskTimeElapsed() { FOnTaskTimeElapsed(this); }
	void CallCommon(void (* const_pFunc)(const uint64_t), IFlowNode::SActivationInfo& _rActInfo) { FCallCommon(this, _pFunc, _rActInfo); }

#if 0
	ArkFlowNodeTaskState(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeTaskState* const _this, SFlowNodeConfig& _rConfig)>(0x15F42D0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeTaskState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F4C80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeTaskState* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeTaskState* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F4270);
	static inline auto FOnTaskActivated = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x1246AF0);
	static inline auto FOnTaskDeactivated = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x15ED5A0);
	static inline auto FOnTaskCompleted = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x15F4C00);
	static inline auto FOnTaskFailed = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x15F4C40);
	static inline auto FOnTaskTimeElapsed = PreyFunction<void(ArkFlowNodeTaskState* const _this)>(0x15D7160);
	static inline auto FCallCommon = PreyFunction<void(ArkFlowNodeTaskState* const _this, void (* const_pFunc)(const uint64_t), IFlowNode::SActivationInfo& _rActInfo)>(0x15F4080);
};
#endif // MOONCRASH
