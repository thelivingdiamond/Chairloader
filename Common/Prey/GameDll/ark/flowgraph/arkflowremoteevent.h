// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeRemoteEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflowremoteevent.h
class CArkFlowNodeRemoteEvent : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class InPort
	{
		INP_Name = 0,
	};

	enum class OutPort
	{
		OUTP_Out = 0,
	};

	IFlowNode::SActivationInfo m_actInfo;
	string m_debugTrigger;

	static const char* GetFlowNodeTypeName() { return FGetFlowNodeTypeName(); }
	CArkFlowNodeRemoteEvent(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~CArkFlowNodeRemoteEvent();
	void Trigger(const string& _name) { FTrigger(this, _name); }
	void DebugTrigger(const string& _name) { FDebugTrigger(this, _name); }
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

	static inline auto FGetFlowNodeTypeName = PreyFunction<const char* ()>(0x15F57C0);
	static inline auto FCArkFlowNodeRemoteEventOv1 = PreyFunction<void(CArkFlowNodeRemoteEvent* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x15F4FA0);
	static inline auto FTrigger = PreyFunction<void(CArkFlowNodeRemoteEvent* const _this, const string& _name)>(0x15F5AF0);
	static inline auto FDebugTrigger = PreyFunction<void(CArkFlowNodeRemoteEvent* const _this, const string& _name)>(0x15F5170);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeRemoteEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F50E0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeRemoteEvent* const _this, SFlowNodeConfig& _config)>(0x15F5220);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeRemoteEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F57D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeRemoteEvent* const _this, ICrySizer* _pS)>(0x35A360);
};

// CArkFlowNodeSendRemoteEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflowremoteevent.h
class CArkFlowNodeSendRemoteEvent : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class InPort
	{
		INP_Send = 0,
		INP_Name = 1,
	};

	enum class OutPort
	{
		OUTP_Out = 0,
	};

	virtual ~CArkFlowNodeSendRemoteEvent();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSendRemoteEvent(const IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeSendRemoteEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F4DB0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSendRemoteEvent* const _this, SFlowNodeConfig& _config)>(0x15F54A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSendRemoteEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F58F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSendRemoteEvent* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
