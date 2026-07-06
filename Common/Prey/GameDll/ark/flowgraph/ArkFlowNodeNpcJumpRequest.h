// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkNpcMovementDesireCallbackEvent;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeNpcJumpRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcJumpRequest.h
class ArkFlowNodeNpcJumpRequest : public CFlowBaseNode<1>
{ // Size=328 (0x148)
public:
	enum class EInputPortIndex
	{
		request = 0,
		destination = 1,
		jumpDistance = 2,
		jumpStyle = 3,
		jumpGoal = 4,
		goalDistance = 5,
		forcePath = 6,
		cancel = 7,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		completed = 1,
		failed = 2,
		canceled = 3,
	};

	IFlowNode::SActivationInfo m_activationInfo;
	ArkNpcMovementDesire m_movementDesire;
	Vec3 m_destination;

	ArkFlowNodeNpcJumpRequest(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	void SetParams(const IFlowNode::SActivationInfo& _activationInfo) { FSetParams(this, _activationInfo); }
	void MovementDesireCallback(EArkNpcMovementDesireCallbackEvent _event) { FMovementDesireCallback(this, _event); }

#if 0
	bool AttemptJump(IFlowNode::SActivationInfo& _arg0_);
	void AddMovementDesire(const IFlowNode::SActivationInfo& _arg0_);
	void RemoveMovementDesire(const IFlowNode::SActivationInfo& _arg0_);
#endif

	static inline auto FArkFlowNodeNpcJumpRequestOv1 = PreyFunction<void(ArkFlowNodeNpcJumpRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x12451B0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcJumpRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1245150);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcJumpRequest* const _this, SFlowNodeConfig& _configuration)>(0x1245290);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcJumpRequest* const _this, ICrySizer* _pSizer)>(0x1245B30);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcJumpRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1245BF0);
	static inline auto FSetParams = PreyFunction<void(ArkFlowNodeNpcJumpRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x1245CE0);
	static inline auto FMovementDesireCallback = PreyFunction<void(ArkFlowNodeNpcJumpRequest* const _this, EArkNpcMovementDesireCallbackEvent _event)>(0x1245B50);
};
#endif // MOONCRASH
