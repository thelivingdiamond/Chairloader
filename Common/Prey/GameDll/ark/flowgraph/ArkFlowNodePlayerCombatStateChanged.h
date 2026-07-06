// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkPlayerCombatListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowGraph;
struct IFlowNode;
struct SFlowNodeConfig;
class XmlNodeRef;

// ArkFlowNodePlayerCombatStateChanged
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePlayerCombatStateChanged.h
class ArkFlowNodePlayerCombatStateChanged : public CFlowBaseNode<1>, public IArkPlayerCombatListener
{ // Size=48 (0x30)
public:
	enum class EInputPortIndex
	{
		enable = 0,
		disable = 1,
	};

	enum class EOutputPortIndex
	{
		newCombatState = 0,
		isNotInCombat = 1,
		isInCombat = 2,
	};

	IFlowGraph* m_pGraph;
	const char* m_nodeName;
	bool m_bEnabled;

	ArkFlowNodePlayerCombatStateChanged(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNodePlayerCombatStateChanged();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnCombatChange(const bool _bPlayerInCombat);
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual bool SerializeXML(IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3);
	virtual void Serialize(IFlowNode::SActivationInfo* __unnamed1, TSerialize ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* __unnamed1);

#if 0
	void SetEnabled(const bool _arg0_);
#endif

	static inline auto FArkFlowNodePlayerCombatStateChangedOv1 = PreyFunction<void(ArkFlowNodePlayerCombatStateChanged* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x131B4E0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodePlayerCombatStateChanged* const _this, SFlowNodeConfig& _config)>(0x131AEB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodePlayerCombatStateChanged* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131B1E0);
	static inline auto FOnCombatChange = PreyFunction<void(IArkPlayerCombatListener* const _this, const bool _bPlayerInCombat)>(0x131B290);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodePlayerCombatStateChanged* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x131B380);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodePlayerCombatStateChanged* const _this, ICrySizer* s)>(0x4BAFC0);
	static inline auto FSerializeXML = PreyFunction<bool(ArkFlowNodePlayerCombatStateChanged* const _this, IFlowNode::SActivationInfo* __unnamed1, const XmlNodeRef& __unnamed2, bool __unnamed3)>(0x1A302A0);
	static inline auto FSerialize = PreyFunction<void(ArkFlowNodePlayerCombatStateChanged* const _this, IFlowNode::SActivationInfo* __unnamed1, TSerialize ser)>(0x1333E90);
	static inline auto FPostSerialize = PreyFunction<void(ArkFlowNodePlayerCombatStateChanged* const _this, IFlowNode::SActivationInfo* __unnamed1)>(0x1333E90);
};
#endif // MOONCRASH
