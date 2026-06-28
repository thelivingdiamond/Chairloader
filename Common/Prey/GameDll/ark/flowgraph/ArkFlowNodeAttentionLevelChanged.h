// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <_unknown/ArkAttentionLevelsChangedListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

struct ArkAttentionLevelChange;
enum class EArkAttentionLevel;
class ICrySizer;
struct IEntity;
struct IFlowGraph;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodeAttentionLevelChanged
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeAttentionLevelChanged.h
class ArkFlowNodeAttentionLevelChanged : public CFlowBaseNode<1>, public ArkAttentionLevelsChangedListener
{ // Size=48 (0x30)
public:
	IFlowGraph* m_pGraph;
	const char* m_nodeName;
	unsigned m_entityId;
	bool m_bEnabled;

	ArkFlowNodeAttentionLevelChanged(IFlowNode::SActivationInfo* pActInfo);
	virtual ~ArkFlowNodeAttentionLevelChanged();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void DoOnAttentionLevelsChanged(const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange);
	void SetEntity(const IEntity* _pEntity) { FSetEntity(this, _pEntity); }
	void TryRegisterListener() { FTryRegisterListener(this); }
	void TryUnregisterListener() { FTryUnregisterListener(this); }
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	static void DoOutputAttentionLevel(IFlowNode::SActivationInfo& _arg0_, EArkAttentionLevel _arg1_);
#endif

	static inline auto FArkFlowNodeAttentionLevelChangedOv1 = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x150FC90);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this, SFlowNodeConfig& _config)>(0x150FFB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1510320);
	static inline auto FDoOnAttentionLevelsChanged = PreyFunction<void(ArkAttentionLevelsChangedListener* const _this, const ArkAttentionLevelChange* _pFirstChange, const ArkAttentionLevelChange* _pLastChange)>(0x150FDF0);
	static inline auto FSetEntity = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this, const IEntity* _pEntity)>(0x15104A0);
	static inline auto FTryRegisterListener = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this)>(0x1510530);
	static inline auto FTryUnregisterListener = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this)>(0x1510560);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeAttentionLevelChanged* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x150FD60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeAttentionLevelChanged* const _this, ICrySizer* s)>(0x4BAFC0);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodeAttentionLevelChanged* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x15103C0);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodeAttentionLevelChanged* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
