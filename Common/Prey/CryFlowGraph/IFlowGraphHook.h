// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
class TFlowInputData;

// Header: MadeUp
// _unknown/IFlowGraphHook.h
struct IFlowGraphHook // Id=80036A1 Size=8
{
	enum EActivation
	{
		eFGH_Stop = 0,
		eFGH_Pass = 1,
		eFGH_Debugger_Input = 2,
		eFGH_Debugger_Output = 3,
	};

	virtual ~IFlowGraphHook();
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual _smart_ptr<IFlowNode> CreateNode(IFlowNode::SActivationInfo *arg0, uint16_t arg1) = 0;
	virtual bool CreatedNode(uint16_t arg0, const char *arg1, uint16_t arg2, _smart_ptr<IFlowNode> arg3) = 0;
	virtual void CancelCreatedNode(uint16_t arg0, const char *arg1, uint16_t arg2, _smart_ptr<IFlowNode> arg3) = 0;
	virtual IFlowGraphHook::EActivation PerformActivation(_smart_ptr<IFlowGraph> arg0, uint16_t arg1, uint8_t arg2, uint16_t arg3, uint8_t arg4, TFlowInputData const *arg5) = 0;
	
#if 0
	void GetMemoryUsage(ICrySizer *arg0) const;
#endif
};

