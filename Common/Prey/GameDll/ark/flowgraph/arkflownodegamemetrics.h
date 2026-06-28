// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeGameMetric
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegamemetrics.h
class CArkFlowNodeGameMetric : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class ArkInputPort
	{
		Trigger = 0,
		TriggerOnChanged = 1,
		Metric = 2,
	};

	enum class ArkOutputPort
	{
		Out = 0,
	};

	IFlowNode::SActivationInfo m_activationInfo;
	static inline auto k_eventListeners = PreyGlobal<std::vector<CArkFlowNodeGameMetric*>>(0x2D4B650);

	CArkFlowNodeGameMetric(IFlowNode::SActivationInfo* _pActivationInfo);
	virtual ~CArkFlowNodeGameMetric();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void OnGameMetricChanged(const uint64_t _id, const float _value) { FOnGameMetricChanged(_id, _value); }

	static inline auto FCArkFlowNodeGameMetricOv1 = PreyFunction<void(CArkFlowNodeGameMetric* const _this, IFlowNode::SActivationInfo* _pActivationInfo)>(0x1318100);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGameMetric* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1317D40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGameMetric* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGameMetric* const _this, SFlowNodeConfig& _config)>(0x1318210);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGameMetric* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x13187F0);
	static inline auto FOnGameMetricChanged = PreyFunction<void(const uint64_t _id, const float _value)>(0x1318620);
};

// CArkFlowNodeIncrementGameMetric
// Header:  Prey/GameDll/ark/flowgraph/arkflownodegamemetrics.h
class CArkFlowNodeIncrementGameMetric : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		Trigger = 0,
		Metric = 1,
		Amount = 2,
	};

	enum class EOutputs
	{
		Out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeIncrementGameMetric(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeIncrementGameMetric* const _this, SFlowNodeConfig& _rConfig)>(0x13176E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeIncrementGameMetric* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1317AE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeIncrementGameMetric* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
