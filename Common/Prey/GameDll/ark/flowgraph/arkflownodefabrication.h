// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/iface/IArkFabricationPlanListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNode_FabricationPlanAcquired
// Header:  Prey/GameDll/ark/flowgraph/arkflownodefabrication.h
class ArkFlowNode_FabricationPlanAcquired : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		plan = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNode_FabricationPlanAcquired*>>(0x2D4AFD0);

	ArkFlowNode_FabricationPlanAcquired(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNode_FabricationPlanAcquired();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyFabricationPlanAcquired(const uint64_t _planId) { FNotifyFabricationPlanAcquired(_planId); }

#if 0
	void OnFabricationPlanAcquired(const uint64_t _arg0_);
#endif

	static inline auto FArkFlowNode_FabricationPlanAcquiredOv1 = PreyFunction<void(ArkFlowNode_FabricationPlanAcquired* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1315170);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_FabricationPlanAcquired* const _this, SFlowNodeConfig& _rConfig)>(0x1315790);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_FabricationPlanAcquired* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_FabricationPlanAcquired* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_FabricationPlanAcquired* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x13155A0);
	static inline auto FNotifyFabricationPlanAcquired = PreyFunction<void(const uint64_t _planId)>(0x1316560);
};

// ArkFlowNode_ItemFabricated
// Header:  Prey/GameDll/ark/flowgraph/arkflownodefabrication.h
class ArkFlowNode_ItemFabricated : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EInputs
	{
		fabricationPlanId = 0,
	};

	enum class EOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNode_ItemFabricated*>>(0x2D4B000);

	ArkFlowNode_ItemFabricated(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNode_ItemFabricated();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyItemFabricated(uint64_t _planId) { FNotifyItemFabricated(_planId); }

#if 0
	void OnItemFabricated(const uint64_t _arg0_);
#endif

	static inline auto FArkFlowNode_ItemFabricatedOv1 = PreyFunction<void(ArkFlowNode_ItemFabricated* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x13151C0);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_ItemFabricated* const _this, SFlowNodeConfig& _config)>(0x1315A10);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_ItemFabricated* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_ItemFabricated* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_ItemFabricated* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1315620);
	static inline auto FNotifyItemFabricated = PreyFunction<void(uint64_t _planId)>(0x1316880);
};

// ArkFlowNode_ReverseEngineeredPlan
// Header:  Prey/GameDll/ark/flowgraph/arkflownodefabrication.h
class ArkFlowNode_ReverseEngineeredPlan : public CFlowBaseNode<1>, public IArkFabricationPlanListener
{ // Size=72 (0x48)
public:
	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual ~ArkFlowNode_ReverseEngineeredPlan();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnFabricationPlanReverseEngineered(const uint64_t _oldId, const uint64_t _newId);

#if 0
	ArkFlowNode_ReverseEngineeredPlan(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_ReverseEngineeredPlan* const _this, SFlowNodeConfig& _rConfig)>(0x1315C90);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_ReverseEngineeredPlan* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1316BD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_ReverseEngineeredPlan* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_ReverseEngineeredPlan* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x13156A0);
	static inline auto FOnFabricationPlanReverseEngineered = PreyFunction<void(IArkFabricationPlanListener* const _this, const uint64_t _oldId, const uint64_t _newId)>(0x1316A70);
};

// ArkFlowNode_SetFabricationPlanError
// Header:  Prey/GameDll/ark/flowgraph/arkflownodefabrication.h
class ArkFlowNode_SetFabricationPlanError : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EInputs
	{
		setError = 0,
		clearError = 1,
		fabricationPlanId = 2,
		errorHeading = 3,
		errorLabel = 4,
	};

	enum class EOutputs
	{
		output = 0,
		errorTriggered = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNode_SetFabricationPlanError*>>(0x2D4AFE8);

	ArkFlowNode_SetFabricationPlanError(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNode_SetFabricationPlanError();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyFabricationErrorTriggered(uint64_t _planId) { FNotifyFabricationErrorTriggered(_planId); }

#if 0
	void OnFabricationErrorTriggered(const uint64_t _arg0_);
#endif

	static inline auto FArkFlowNode_SetFabricationPlanErrorOv1 = PreyFunction<void(ArkFlowNode_SetFabricationPlanError* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1315210);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNode_SetFabricationPlanError* const _this, SFlowNodeConfig& _config)>(0x1315DB0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNode_SetFabricationPlanError* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1316C10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNode_SetFabricationPlanError* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNode_SetFabricationPlanError* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1315710);
	static inline auto FNotifyFabricationErrorTriggered = PreyFunction<void(uint64_t _planId)>(0x1316440);
};
#endif // MOONCRASH
