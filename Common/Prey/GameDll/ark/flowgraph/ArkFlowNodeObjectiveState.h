// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeObjectiveState
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeObjectiveState.h
class ArkFlowNodeObjectiveState : public CFlowBaseNode<1>
{ // Size=64 (0x40)
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
		RESET = 7,
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

	virtual ~ArkFlowNodeObjectiveState();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnObjectiveAssigned() { FOnObjectiveAssigned(this); }
	void OnObjectiveUnassigned() { FOnObjectiveUnassigned(this); }
	void OnObjectiveCompleted() { FOnObjectiveCompleted(this); }
	void OnObjectiveFailed() { FOnObjectiveFailed(this); }

#if 0
	ArkFlowNodeObjectiveState(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeObjectiveState* const _this, SFlowNodeConfig& _rConfig)>(0x15ECCB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeObjectiveState* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15ED5E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeObjectiveState* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeObjectiveState* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15ECB10);
	static inline auto FOnObjectiveAssigned = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x1246AF0);
	static inline auto FOnObjectiveUnassigned = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x15ED5A0);
	static inline auto FOnObjectiveCompleted = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x15F4C00);
	static inline auto FOnObjectiveFailed = PreyFunction<void(ArkFlowNodeObjectiveState* const _this)>(0x15F4C40);
};
#endif // MOONCRASH
