// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/arkflownodenpctrackview_setdynamicentity.h
class ArkFlowNodeNpcTrackView_SetDynamicNode : public CFlowBaseNode<0> // Id=801BFF9 Size=16
{
public:
	enum class EInputPortIndex
	{
		set = 0,
		clear = 1,
		dynNodeName = 2,
	};

	enum class EOutputPortIndex
	{
		succeeded = 0,
		failed = 1,
		cleared = 2,
		out = 3,
	};

	virtual ~ArkFlowNodeNpcTrackView_SetDynamicNode();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *__formal, XmlNodeRef const &__formal, bool __formal);
	virtual void Serialize(IFlowNode::SActivationInfo *__formal, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *__formal);
	
#if 0
	void ProcessSet(IFlowNode::SActivationInfo *arg0);
	void ProcessClear(IFlowNode::SActivationInfo *arg0);
#endif
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, SFlowNodeConfig &config)>(0x1435DF0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x1436280);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::SActivationInfo *__formal, XmlNodeRef const &__formal, bool __formal)>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::SActivationInfo *__formal, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_SetDynamicNode *const _this, IFlowNode::SActivationInfo *__formal)>(0xA13080);
};

