// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/ArkFlowNodeNpcTrackView_GetStartPos.h
class ArkFlowNodeNpcTrackView_GetStartPos : public CFlowBaseNode<0> // Id=801BFF7 Size=16
{
public:
	enum class EInputPortIndex
	{
		get = 0,
		sequenceName = 1,
		nodeName = 2,
	};

	enum class EOutputPortIndex
	{
		succeeded = 0,
		failed = 1,
		pos = 2,
		out = 3,
	};

	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo);
	void ProcessGet(IFlowNode::SActivationInfo *_pActInfo) { FProcessGet(this,_pActInfo); }
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *__formal, XmlNodeRef const &__formal, bool __formal);
	virtual void Serialize(IFlowNode::SActivationInfo *__formal, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *__formal);
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcTrackView_GetStartPos *const _this, SFlowNodeConfig &config)>(0x1435300);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcTrackView_GetStartPos *const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo *_pActInfo)>(0x1435810);
	static inline auto FProcessGet = PreyFunction<void(ArkFlowNodeNpcTrackView_GetStartPos *const _this, IFlowNode::SActivationInfo *_pActInfo)>(0x1435A00);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeNpcTrackView_GetStartPos const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcTrackView_GetStartPos *const _this, IFlowNode::SActivationInfo *__formal, XmlNodeRef const &__formal, bool __formal)>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_GetStartPos *const _this, IFlowNode::SActivationInfo *__formal, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcTrackView_GetStartPos *const _this, IFlowNode::SActivationInfo *__formal)>(0xA13080);
};

