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

// ArkFlowNodeNpcSpawnedEntityId
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeNpcSpawnedEntityId.h
class ArkFlowNodeNpcSpawnedEntityId : public CFlowBaseNode<1>, public IEntityEventListener
{ // Size=80 (0x50)
public:
	enum class EOutputPortIndex
	{
		k_spawnedNpcEntityIdOutputPortIndex = 0,
	};

	unsigned m_entityId;
	IFlowNode::SActivationInfo m_actInfo;

	virtual ~ArkFlowNodeNpcSpawnedEntityId();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);
	virtual void OnEntityEvent(IEntity* pEntity, SEntityEvent& event);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	ArkFlowNodeNpcSpawnedEntityId(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNpcSpawnedEntityId* const _this, SFlowNodeConfig& config)>(0x15EC2E0);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeNpcSpawnedEntityId* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeNpcSpawnedEntityId* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x15EC400);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeNpcSpawnedEntityId* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x15EC420);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* pEntity, SEntityEvent& event)>(0x15EC450);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNpcSpawnedEntityId* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EC4D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNpcSpawnedEntityId* const _this, ICrySizer* _pSizer)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNpcSpawnedEntityId* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x15EC560);
};
#endif // MOONCRASH
