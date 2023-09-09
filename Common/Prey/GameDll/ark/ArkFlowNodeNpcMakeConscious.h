// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryAISystem/FlowNodes/AIFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>
#include <Prey/CryNetwork/ISerialize.h>

class ICrySizer;
struct SFlowNodeConfig;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/ArkFlowNodeNpcMakeConscious.h
class ArkFlowNodeNpcMakeConscious : public CFlowBaseNode<0> // Id=80190DD Size=16
{
public:
	enum class EInputPortIndex
	{
		wakeUp = 0,
	};

	enum class EOutputPortIndex
	{
		out = 0,
	};

	virtual ~ArkFlowNodeNpcMakeConscious();
	virtual void GetConfiguration(SFlowNodeConfig &config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *_pActInfo);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo *, XmlNodeRef const &, bool );
	virtual void Serialize(IFlowNode::SActivationInfo *, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo *);
	
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcMakeConscious *const _this, SFlowNodeConfig &config)>(0x116A050);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcMakeConscious *const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo *_pActInfo)>(0x116A260);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkFlowNodeNpcMakeConscious const *const _this, ICrySizer *s)>(0x44D760);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcMakeConscious *const _this, IFlowNode::SActivationInfo *, XmlNodeRef const &, bool )>(0x1B933B0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcMakeConscious *const _this, IFlowNode::SActivationInfo *, TSerialize ser)>(0xA13080);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcMakeConscious *const _this, IFlowNode::SActivationInfo *)>(0xA13080);
};

