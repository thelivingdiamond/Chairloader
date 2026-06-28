// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/Scaleform/IFlashUI.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IEntityArchetype;
struct IFlowNode;
struct IUIEventSystem;
struct SFlowNodeConfig;
struct SUIArguments;
struct SUIEvent;

// CArkFlowNodePlayerMimicEvent
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodePlayerMimicEvent.h
class CArkFlowNodePlayerMimicEvent : public CFlowBaseNode<1>, public IUIEventListener
{ // Size=96 (0x60)
public:
	enum class ArkInputPort
	{
		Enable = 0,
		Disable = 1,
		ArchetypeName = 2,
	};

	enum class ArkOutputPort
	{
		Out = 0,
		StartMorphIn = 1,
		FinishMorphIn = 2,
		StartMimicking = 3,
		FinishMimicking = 4,
		TargetedEntityId = 5,
		SpawnedEntityId = 6,
	};

	bool m_bIgnoreMimicEvents;
	const IEntityArchetype* m_pEntityArchetype;
	IFlowNode::SActivationInfo m_activationInfo;
	string m_uniqueName;

	CArkFlowNodePlayerMimicEvent(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual ~CArkFlowNodePlayerMimicEvent();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual SUIArguments OnEvent(const SUIEvent& _event);
	virtual void OnEventSystemDestroyed(IUIEventSystem* _pEventSystem);

#if 0
	void RegisterMimicUIEventListener();
	void UnregisterMimicUIEventListener();
#endif

	static inline auto FCArkFlowNodePlayerMimicEventOv1 = PreyFunction<void(CArkFlowNodePlayerMimicEvent* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x124AC90);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodePlayerMimicEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x124A8F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePlayerMimicEvent* const _this, ICrySizer* _pS)>(0xA55F00);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePlayerMimicEvent* const _this, SFlowNodeConfig& _config)>(0x124AE10);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePlayerMimicEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x124B540);
	static inline auto FOnEvent = PreyFunction<SUIArguments*(IUIEventListener* const _this, SUIArguments* _return_value_, const SUIEvent& _event)>(0x124B310);
	static inline auto FOnEventSystemDestroyed = PreyFunction<void(IUIEventListener* const _this, IUIEventSystem* _pEventSystem)>(0x1333E90);
};
#endif // MOONCRASH
