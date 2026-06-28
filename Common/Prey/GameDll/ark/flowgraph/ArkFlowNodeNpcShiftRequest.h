// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcFacingDesire.h>
#include <Prey/GameDll/ark/npc/desires/ArkNpcMovementDesire.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkNpcMovementDesireCallbackEvent;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeNpcShiftRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcShiftRequest.h
class CArkFlowNodeNpcShiftRequest : public CFlowBaseNode<1>
{ // Size=440 (0x1B8)
public:
	enum class EInputPortIndex
	{
		request = 0,
		destination = 1,
		rotationEnabled = 2,
		rotation = 3,
		animation = 4,
		cancel = 5,
	};

	enum class EOutputPortIndex
	{
		requested = 0,
		completed = 1,
		failed = 2,
		canceled = 3,
	};

	enum class EState
	{
		None = 0,
		Started = 1,
		Failed = 2,
		Fulfilled = 3,
	};

	ArkNpcMovementDesire m_movementDesire;
	ArkNpcFacingDesire m_facingDesire;
	CArkFlowNodeNpcShiftRequest::EState m_state;
	bool m_bRequestOnPostSerialize;

	CArkFlowNodeNpcShiftRequest(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _configuration);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void Serialize(IFlowNode::SActivationInfo* _pActivationInfo, TSerialize _serialize);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo);
	void SetParams(const IFlowNode::SActivationInfo& _activationInfo) { FSetParams(this, _activationInfo); }
	void AddDesires(const IFlowNode::SActivationInfo& _activationInfo) { FAddDesires(this, _activationInfo); }
	void RemoveDesires(const IFlowNode::SActivationInfo& _activationInfo) { FRemoveDesires(this, _activationInfo); }

#if 0
	void MovementDesireCallback(EArkNpcMovementDesireCallbackEvent _arg0_);
#endif

	static inline auto FCArkFlowNodeNpcShiftRequestOv1 = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15EB520);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeNpcShiftRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15EB690);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, SFlowNodeConfig& _configuration)>(0x15EB6E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeNpcShiftRequest* const _this, ICrySizer* _pSizer)>(0x15EBDC0);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo, TSerialize _serialize)>(0x15EBF90);
	static inline auto FPostSerialize = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15EBDE0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActivationInfo)>(0x15EBE20);
	static inline auto FSetParams = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x15EBFF0);
	static inline auto FAddDesires = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x15EB600);
	static inline auto FRemoveDesires = PreyFunction<void(CArkFlowNodeNpcShiftRequest* const _this, const IFlowNode::SActivationInfo& _activationInfo)>(0x15EBF10);
};
#endif // MOONCRASH
