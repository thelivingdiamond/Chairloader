// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowConsoleEvent
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowConsoleEvent.h
class CArkFlowConsoleEvent : public CFlowBaseNode<eNCT_Instanced>
{ // Size=40 (0x28)
public:
	enum EInputs
	{
		IN_COMMAND = 0,
	};
	
	enum EOutputs
	{
		OUT_TRIGGERED = 0,
	};
	
	bool m_bNeedToCheckConnectedPorts;
	string m_attemptedCommand;
	unsigned m_graphId;
	uint16_t m_id;
	
	virtual ~CArkFlowConsoleEvent();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _Event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void SetExecutionString(const string& _rCommandString) { FSetExecutionString(this, _rCommandString); }
	
#if 0
	CArkFlowConsoleEvent(IFlowNode::SActivationInfo* _arg0_);
#endif
	
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowConsoleEvent* const _this, SFlowNodeConfig& _rConfig)>(0x14A7720);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowConsoleEvent* const _this, IFlowNode::EFlowEvent _Event, IFlowNode::SActivationInfo* _pActInfo)>(0xA13080);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowConsoleEvent* const _this, ICrySizer* _pSizer)>(0x8CFFA0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowConsoleEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x14A76C0);
	static inline auto FSetExecutionString = PreyFunction<void(CArkFlowConsoleEvent* const _this, const string& _rCommandString)>(0x14A79A0);
};


