// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntity;
struct IFlowNode;
struct SEntityEvent;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeFactionwideAttention
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeFactionwideAttention.h
class ArkFlowNodeFactionwideAttention : public CFlowBaseNode<1>, public IEntityEventListener
{ // Size=80 (0x50)
public:
	enum class EInputPortIndex
	{
		k_enable = 0,
		k_disable = 1,
		k_faction = 2,
	};

	enum class EOutputPortIndex
	{
		k_entityId = 0,
		k_unknown = 1,
		k_noticed = 2,
		k_curious = 3,
		k_interested = 4,
		k_known = 5,
	};

	bool m_bActivated;
	IFlowNode::SActivationInfo m_actInfo;

	virtual ~ArkFlowNodeFactionwideAttention();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeFactionwideAttention(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeFactionwideAttention* const _this, SFlowNodeConfig& config)>(0x1316D40);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeFactionwideAttention* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeFactionwideAttention* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1317230);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeFactionwideAttention* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1317250);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x1317280);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeFactionwideAttention* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1317560);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeFactionwideAttention* const _this, ICrySizer* _pSizer)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeFactionwideAttention* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1317670);
};
#endif // MOONCRASH
