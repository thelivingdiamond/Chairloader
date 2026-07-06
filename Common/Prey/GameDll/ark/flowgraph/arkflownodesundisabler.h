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

// ArkFlowNode_SunDisabler
// Header:  Prey/GameDll/ark/flowgraph/arkflownodesundisabler.h
class ArkFlowNode_SunDisabler : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum EInputs
	{
		eIN_DiableSun = 0,
	};

	enum EOutputs
	{
		eOUT_SunDisabled = 0,
	};

	bool m_bSunDisabled;

	virtual ~ArkFlowNode_SunDisabler();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	void Prepare(const IFlowNode::SActivationInfo& _actInfo) { FPrepare(this, _actInfo); }

#if 0
	ArkFlowNode_SunDisabler(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_SunDisabler* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x124D530);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_SunDisabler* const _this, SFlowNodeConfig& _config)>(0x124D580);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_SunDisabler* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124D840);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_SunDisabler* const _this, ICrySizer* _pS)>(0x4BC120);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNode_SunDisabler* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x124D890);
	static inline auto FPrepare = PreyFunction<void(ArkFlowNode_SunDisabler* const _this, const IFlowNode::SActivationInfo& _actInfo)>(0x124D780);
};
#endif // MOONCRASH
