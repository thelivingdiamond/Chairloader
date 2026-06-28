// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowEntityVelocity
// Header:  Prey/GameDll/nodes/g2flowentityvelocity.h
class CFlowEntityVelocity : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum EOutputPorts
	{
		EOP_Velocity_Horizontal = 0,
		EOP_Velocity_Vertical = 1,
		EOP_Velocity_ForwardBackward = 2,
		EOP_Velocity_RightLeft = 3,
	};

	enum class EInPorts
	{
		IN_ENABLED = 0,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;
	bool m_enabled;

	virtual ~CFlowEntityVelocity();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlowEntityVelocity(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowEntityVelocity* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18AEBA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowEntityVelocity* const _this, ICrySizer* s)>(0x35A360);
	static inline auto FSerialize = PreyFunction<void(CFlowEntityVelocity* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18AE320);
	static inline auto FGetConfiguration = PreyFunction<void(CFlowEntityVelocity* const _this, SFlowNodeConfig& config)>(0x18AE390);
	static inline auto FProcessEvent = PreyFunction<void(CFlowEntityVelocity* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18AE640);
};
#endif // MOONCRASH
