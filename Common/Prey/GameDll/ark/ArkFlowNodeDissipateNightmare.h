// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/ArkFlowNodeDissipateNightmare.h
class ArkFlowNodeDissipateNightmare : public CFlowBaseNode<0> // Id=80190D3 Size=16
{
public:
	enum class EInputPortIndex
	{
		dissipate = 0,
	};

	enum class EOutputPortIndex
	{
		success = 0,
		failure = 1,
		out = 2,
	};

	virtual ~ArkFlowNodeDissipateNightmare();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *__formal, XmlNodeRef const &__formal, bool __formal);
	virtual void Serialize(IFlowNode::SActivationInfo *__formal, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *__formal);
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, SFlowNodeConfig &config)>(0x11689F0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *_pActInfo)>(0x1168C50);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeDissipateNightmare const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::SActivationInfo *__formal, XmlNodeRef const &__formal, bool __formal)>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::SActivationInfo *__formal, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeDissipateNightmare *const _this, IFlowNode::SActivationInfo *__formal)>(0xA13080);
};

