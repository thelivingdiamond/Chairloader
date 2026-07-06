// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkAbilityListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum class EArkPsiPowers;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNeuromod
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class ArkFlowNeuromod : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNeuromod*>>(0x2D72A10);

	ArkFlowNeuromod(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~ArkFlowNeuromod();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	static void OnNeuromodUsed();
#endif

	static inline auto FArkFlowNeuromodOv1 = PreyFunction<void(ArkFlowNeuromod* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x15C1750);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNeuromod* const _this, SFlowNodeConfig& _config)>(0x15C0A10);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNeuromod* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNeuromod* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNeuromod* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1E80);
};

// ArkFlowNodePlayerAlien
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class ArkFlowNodePlayerAlien : public CFlowBaseNode<1>, public IArkAbilityListener
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		test = 0,
	};

	enum class EArkOutputs
	{
		alien = 0,
		resultAlien = 1,
		resultHuman = 2,
	};

	IFlowNode::SActivationInfo m_actInfo;

	ArkFlowNodePlayerAlien(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~ArkFlowNodePlayerAlien();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnBecomeAlien();

	static inline auto FArkFlowNodePlayerAlienOv1 = PreyFunction<void(ArkFlowNodePlayerAlien* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x15C17A0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodePlayerAlien* const _this, SFlowNodeConfig& _config)>(0x15C2110);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodePlayerAlien* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C37E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodePlayerAlien* const _this, ICrySizer* _s)>(0x2D0150);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodePlayerAlien* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1DF0);
	static inline auto FOnBecomeAlien = PreyFunction<void(IArkAbilityListener* const _this)>(0x15C37A0);
};

// ArkFlowNodeScanAlienEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class ArkFlowNodeScanAlienEvent : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		enable = 0,
		researchTopicId = 1,
	};

	enum class EArkOutputs
	{
		enabled = 0,
		disabled = 1,
		scannedEntityId = 2,
		scanCompleted = 3,
		researchCompleted = 4,
	};

	IFlowNode::SActivationInfo m_actInfo;
	uint64_t m_researchTopicId;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNodeScanAlienEvent*>>(0x2D72A70);

	ArkFlowNodeScanAlienEvent(const IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~ArkFlowNodeScanAlienEvent();
	static void NotifyScanEvent(const uint64_t _researchTopicId, const unsigned _scannedEntityId, const bool _bIsFinished) { FNotifyScanEvent(_researchTopicId, _scannedEntityId, _bIsFinished); }
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

	static inline auto FArkFlowNodeScanAlienEventOv1 = PreyFunction<void(ArkFlowNodeScanAlienEvent* const _this, const IFlowNode::SActivationInfo* const _pActInfo)>(0x15C1800);
	static inline auto FNotifyScanEvent = PreyFunction<void(const uint64_t _researchTopicId, const unsigned _scannedEntityId, const bool _bIsFinished)>(0x15C35A0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeScanAlienEvent* const _this, SFlowNodeConfig& _config)>(0x15C2370);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeScanAlienEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3870);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeScanAlienEvent* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeScanAlienEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1E80);
};

// ArkFlowNodeUnhideAbility
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class ArkFlowNodeUnhideAbility : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		ability = 1,
		highlight = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeUnhideAbility(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeUnhideAbility* const _this, SFlowNodeConfig& _config)>(0x15BF6C0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeUnhideAbility* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15BFAD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeUnhideAbility* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeGiveAbility
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodeGiveAbility : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		abilityId = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeGiveAbility(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveAbility* const _this, SFlowNodeConfig& _config)>(0x15C0660);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGiveAbility* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGiveAbility* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeHasAbility
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodeHasAbility : public CFlowBaseNode<1>, public IArkAbilityListener
{ // Size=80 (0x50)
public:
	enum class EArkInputs
	{
		onAcquired = 0,
		trigger = 1,
		abilityId = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
		falseTrigger = 1,
		trueTrigger = 2,
	};

	uint64_t m_abilityId;
	IFlowNode::SActivationInfo m_activationInfo;

	CArkFlowNodeHasAbility(IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~CArkFlowNodeHasAbility();
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnAbilityAdded(uint64_t _abilityID);

	static inline auto FCArkFlowNodeHasAbilityOv1 = PreyFunction<void(CArkFlowNodeHasAbility* const _this, IFlowNode::SActivationInfo* const _pActInfo)>(0x15C1860);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeHasAbility* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x15C3BC0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasAbility* const _this, SFlowNodeConfig& _config)>(0x15C2760);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasAbility* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3930);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasAbility* const _this, ICrySizer* _pS)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeHasAbility* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1F00);
	static inline auto FOnAbilityAdded = PreyFunction<void(IArkAbilityListener* const _this, uint64_t _abilityID)>(0x15C3720);
};

// CArkFlowNodeLearnResearch
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodeLearnResearch : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		research = 1,
		numLevels = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeLearnResearch(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeLearnResearch* const _this, SFlowNodeConfig& _config)>(0x15C00F0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeLearnResearch* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C04F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeLearnResearch* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodePsiPowerActive
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodePsiPowerActive : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		psiPower = 0,
	};

	enum class EArkOutputs
	{
		activated = 0,
		deactivated = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodePsiPowerActive*>>(0x2D72A40);

	CArkFlowNodePsiPowerActive(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CArkFlowNodePsiPowerActive();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyPsiPowerActive(EArkPsiPowers _power, bool _bActivated) { FNotifyPsiPowerActive(_power, _bActivated); }

#if 0
	void OnPsiPowerActive(EArkPsiPowers _arg0_, bool _arg1_);
#endif

	static inline auto FCArkFlowNodePsiPowerActiveOv1 = PreyFunction<void(CArkFlowNodePsiPowerActive* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15C18C0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePsiPowerActive* const _this, SFlowNodeConfig& _rConfig)>(0x15C2BB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePsiPowerActive* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePsiPowerActive* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodePsiPowerActive* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1F90);
	static inline auto FNotifyPsiPowerActive = PreyFunction<void(EArkPsiPowers _power, bool _bActivated)>(0x15C3270);
};

// CArkFlowNodePsiPowerMenuActive
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodePsiPowerMenuActive : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkOutputs
	{
		activated = 0,
		deactivated = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodePsiPowerMenuActive*>>(0x2D72A58);

	CArkFlowNodePsiPowerMenuActive(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CArkFlowNodePsiPowerMenuActive();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	void OnPsiPowerMenuActive(bool _arg0_);
	static void NotifyPsiPowerMenuActive(bool _arg0_);
#endif

	static inline auto FCArkFlowNodePsiPowerMenuActiveOv1 = PreyFunction<void(CArkFlowNodePsiPowerMenuActive* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1910);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePsiPowerMenuActive* const _this, SFlowNodeConfig& _rConfig)>(0x15C2E60);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePsiPowerMenuActive* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePsiPowerMenuActive* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodePsiPowerMenuActive* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C2010);
};

// CArkFlowNodePsiPowerTargetingActive
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodePsiPowerTargetingActive : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		psiPower = 0,
	};

	enum class EArkOutputs
	{
		activated = 0,
		deactivated = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodePsiPowerTargetingActive*>>(0x2D72A28);

	CArkFlowNodePsiPowerTargetingActive(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CArkFlowNodePsiPowerTargetingActive();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyPsiPowerTargetingActive(EArkPsiPowers _power, bool _bActivated) { FNotifyPsiPowerTargetingActive(_power, _bActivated); }

#if 0
	void OnPsiPowerTargetingActive(EArkPsiPowers _arg0_, bool _arg1_);
#endif

	static inline auto FCArkFlowNodePsiPowerTargetingActiveOv1 = PreyFunction<void(CArkFlowNodePsiPowerTargetingActive* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15C1960);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePsiPowerTargetingActive* const _this, SFlowNodeConfig& _rConfig)>(0x15C2FC0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePsiPowerTargetingActive* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePsiPowerTargetingActive* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodePsiPowerTargetingActive* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C2090);
	static inline auto FNotifyPsiPowerTargetingActive = PreyFunction<void(EArkPsiPowers _power, bool _bActivated)>(0x15C3400);
};

// CArkFlowNodePurchaseRandomAbilities
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeabilities.h
class CArkFlowNodePurchaseRandomAbilities : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		numNeuromods = 1,
		requireResearch = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodePurchaseRandomAbilities(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodePurchaseRandomAbilities* const _this, SFlowNodeConfig& _config)>(0x15BFCB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodePurchaseRandomAbilities* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodePurchaseRandomAbilities* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
