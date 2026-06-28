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
class XmlNodeRef;

// ArkFlowNodeNpcDistractRequest
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcDistractRequest.h
class ArkFlowNodeNpcDistractRequest : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EInputPortIndex
	{
		request = 0,
		distractorEntityId = 1,
	};

	enum class EOutputPortIndex
	{
		out = 0,
		success = 1,
		fail = 2,
		distractionEntityIdUsed = 3,
	};

	IFlowNode::SActivationInfo m_prevActivationInfo;

	virtual ~ArkFlowNodeNpcDistractRequest();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	void DistractResultCallback(const unsigned _distractionEntityId, const bool _bResult) { FDistractResultCallback(this, _distractionEntityId, _bResult); }
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcDistractRequest(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcDistractRequest* const _this, SFlowNodeConfig& config)>(0x1515E70);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcDistractRequest* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15161E0);
	static inline auto FDistractResultCallback = PreyFunction<void(ArkFlowNodeNpcDistractRequest* const _this, const unsigned _distractionEntityId, const bool _bResult)>(0x15164C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcDistractRequest* const _this, ICrySizer* s)>(0x182A3D0);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcDistractRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcDistractRequest* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcDistractRequest* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcDistractRequest* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1516440);
};
#endif // MOONCRASH
