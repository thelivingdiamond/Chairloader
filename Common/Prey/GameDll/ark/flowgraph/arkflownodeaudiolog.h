// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeAudioLogEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeaudiolog.h
class ArkFlowNodeAudioLogEvent : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkOutputs
	{
		onStart = 0,
		onFail = 1,
		onInterrupt = 2,
		onComplete = 3,
	};

	enum class EArkInputs
	{
		conversation = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNodeAudioLogEvent*>>(0x2D4AC78);

	ArkFlowNodeAudioLogEvent(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~ArkFlowNodeAudioLogEvent();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyAudioLogEvent(const uint64_t _conversationId, ArkFlowNodeAudioLogEvent::EArkOutputs _event) { FNotifyAudioLogEvent(_conversationId, _event); }
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	void OnAudioLogEvent(const uint64_t _arg0_, ArkFlowNodeAudioLogEvent::EArkOutputs _arg1_);
#endif

	static inline auto FArkFlowNodeAudioLogEventOv1 = PreyFunction<void(ArkFlowNodeAudioLogEvent* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x1313010);
	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeAudioLogEvent* const _this, SFlowNodeConfig& _rConfig)>(0x1313170);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeAudioLogEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FNotifyAudioLogEvent = PreyFunction<void(const uint64_t _conversationId, ArkFlowNodeAudioLogEvent::EArkOutputs _event)>(0x1313970);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeAudioLogEvent* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeAudioLogEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x13130F0);
};

// CArkFlowNode_CollectAudioLog
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeaudiolog.h
class CArkFlowNode_CollectAudioLog : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		audioLog = 1,
		autoPlay = 2,
		force = 3,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_CollectAudioLog(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_CollectAudioLog* const _this, SFlowNodeConfig& _config)>(0x1313490);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_CollectAudioLog* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1313B60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_CollectAudioLog* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
