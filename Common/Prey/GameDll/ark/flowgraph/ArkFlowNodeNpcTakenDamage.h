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

// ArkFlowNodeNpcTakenDamage
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcTakenDamage.h
class ArkFlowNodeNpcTakenDamage : public CFlowBaseNode<1>, public IEntityEventListener
{ // Size=88 (0x58)
public:
	enum class EInputPortIndex
	{
		k_enable = 0,
		k_disable = 1,
	};

	enum class EOutputPortIndex
	{
		k_out = 0,
		k_packageId = 1,
		k_attackerId = 2,
	};

	bool m_bActivated;
	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;

	virtual ~ArkFlowNodeNpcTakenDamage();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcTakenDamage(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcTakenDamage* const _this, SFlowNodeConfig& config)>(0x151FC80);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcTakenDamage* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcTakenDamage* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x151FFC0);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcTakenDamage* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1520010);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x1520050);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcTakenDamage* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15201C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcTakenDamage* const _this, ICrySizer* _pSizer)>(0xE98E40);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcTakenDamage* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x1520270);
};
#endif // MOONCRASH
