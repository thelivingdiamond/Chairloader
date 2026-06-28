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

// CArkFlowNodeGate
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeGate.h
class CArkFlowNodeGate : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum class InPorts
	{
		INP_In = 0,
		INP_SetClosed = 1,
		INP_Open = 2,
		INP_Close = 3,
		INP_AutoCloseCount = 4,
		INP_Reset = 5,
	};

	enum class OutPorts
	{
		OUTP_Out = 0,
		OUTP_SetClosed = 1,
		OUTP_Opened = 2,
		OUTP_Closed = 3,
		OUTP_Reset = 4,
	};

	bool m_bClosed;
	int m_activationCount;

	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeGate(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGate* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15CB090);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeGate* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x15CB0F0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGate* const _this, SFlowNodeConfig& _config)>(0x15CB140);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGate* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CB850);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGate* const _this, ICrySizer* _pSizer)>(0x4BC120);
};
#endif // MOONCRASH
