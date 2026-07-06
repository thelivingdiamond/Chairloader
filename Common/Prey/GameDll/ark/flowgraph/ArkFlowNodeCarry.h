// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeCarry
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeCarry.h
class ArkFlowNodeCarry : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class OutPort
	{
		OUTP_PickedUp = 0,
		OUTP_Dropped = 1,
		OUTP_Thrown = 2,
	};

	IFlowNode::SActivationInfo m_actInfo;

	ArkFlowNodeCarry(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~ArkFlowNodeCarry();
	static void OnPickedUp(const IEntity& _entity) { FOnPickedUp(_entity); }
	static void OnDropped(const IEntity& _entity) { FOnDropped(_entity); }
	static void OnThrown(const IEntity& _entity) { FOnThrown(_entity); }
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	static void Trigger(const IEntity& _entity, const ArkFlowNodeCarry::OutPort _port) { FTrigger(_entity, _port); }

	static inline auto FArkFlowNodeCarryOv1 = PreyFunction<void(ArkFlowNodeCarry* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x15C3E20);
	static inline auto FOnPickedUp = PreyFunction<void(const IEntity& _entity)>(0x15C42B0);
	static inline auto FOnDropped = PreyFunction<void(const IEntity& _entity)>(0x15C42A0);
	static inline auto FOnThrown = PreyFunction<void(const IEntity& _entity)>(0x15C42C0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeCarry* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3F00);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeCarry* const _this, SFlowNodeConfig& _config)>(0x15C3F80);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeCarry* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C42D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeCarry* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FTrigger = PreyFunction<void(const IEntity& _entity, const ArkFlowNodeCarry::OutPort _port)>(0x15C4350);
};
#endif // MOONCRASH
