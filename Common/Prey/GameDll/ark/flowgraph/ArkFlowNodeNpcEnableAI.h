// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeNpcEnableAI
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcEnableAI.h
class ArkFlowNodeNpcEnableAI : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum INPUTS
	{
		eInputPort_Enable = 0,
		eInputPort_Disable = 1,
	};

	enum OUTPUTS
	{
		eOutputPort_Out = 0,
	};

	virtual ~ArkFlowNodeNpcEnableAI();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeNpcEnableAI(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcEnableAI* const _this, SFlowNodeConfig& config)>(0x15E6B70);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcEnableAI* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E6E50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcEnableAI* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcEnableAI* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcEnableAI* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcEnableAI* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
