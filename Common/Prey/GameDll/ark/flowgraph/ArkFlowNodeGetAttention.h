// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkAttentionLevel;
class ICrySizer;
struct IEntity;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeGetAttention
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeGetAttention.h
class ArkFlowNodeGetAttention : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputPortIndex
	{
		get = 0,
	};

	enum class EOutputPortIndex
	{
		unknown = 0,
		noticed = 1,
		curious = 2,
		interested = 3,
		known = 4,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	ArkFlowNodeGetAttention(IFlowNode::SActivationInfo* _arg0_);
	static EArkAttentionLevel DoGetAttentionLevel(const IEntity* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeGetAttention* const _this, SFlowNodeConfig& _config)>(0x1513640);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeGetAttention* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1513900);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeGetAttention* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeGetAttention* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeGetAttention* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeGetAttention* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
