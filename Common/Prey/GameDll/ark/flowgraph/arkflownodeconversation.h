// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ArkConversation;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeConversationEvent
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeconversation.h
class CArkFlowNodeConversationEvent : public CFlowBaseNode<1>
{ // Size=72 (0x48)
public:
	enum class EArkInputs
	{
		conversation = 0,
	};

	enum class EArkOutputs
	{
		start = 0,
		interrupted = 1,
		end = 2,
		owner = 3,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	uint64_t m_conversationId;

	virtual ~CArkFlowNodeConversationEvent();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnConversationStart(const uint64_t _hookId) { FOnConversationStart(this, _hookId); }
	void OnConversationEnd(const ArkConversation* _pConversation, const bool _bCompleted) { FOnConversationEnd(this, _pConversation, _bCompleted); }

#if 0
	CArkFlowNodeConversationEvent(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeConversationEvent* const _this, SFlowNodeConfig& _rConfig)>(0x15C8F10);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeConversationEvent* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C9A60);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeConversationEvent* const _this, ICrySizer* _pS)>(0x35A360);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeConversationEvent* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C8EA0);
	static inline auto FOnConversationStart = PreyFunction<void(CArkFlowNodeConversationEvent* const _this, const uint64_t _hookId)>(0x15C9980);
	static inline auto FOnConversationEnd = PreyFunction<void(CArkFlowNodeConversationEvent* const _this, const ArkConversation* _pConversation, const bool _bCompleted)>(0x15C98C0);
};

// CArkFlowNodeConversationStatus
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeconversation.h
class CArkFlowNodeConversationStatus : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		conversation = 1,
	};

	enum class EArkOutputs
	{
		not_started = 0,
		started = 1,
		interrupted = 2,
		completed = 3,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeConversationStatus(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeConversationStatus* const _this, SFlowNodeConfig& _rConfig)>(0x15C83A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeConversationStatus* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C8760);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeConversationStatus* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeConversationTrigger
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeconversation.h
class CArkFlowNodeConversationTrigger : public CFlowBaseNode<1>, public IArkConversationListener
{ // Size=96 (0x60)
public:
	enum class EArkInputs
	{
		trigger = 0,
		conversation = 1,
		paChannel = 2,
		stop = 3,
		priority = 4,
	};

	enum class EArkOutputs
	{
		triggered = 0,
		onInterrupt = 1,
		onComplete = 2,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	ArkConversation* m_pConversation;
	uint64_t m_conversationId;
	uint64_t m_loadConversationId;

	virtual ~CArkFlowNodeConversationTrigger();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser);
	virtual void PostSerialize(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnConversationComplete(const bool _bComplete);

#if 0
	CArkFlowNodeConversationTrigger(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeConversationTrigger* const _this, SFlowNodeConfig& _rConfig)>(0x15C9230);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeConversationTrigger* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C9B20);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeConversationTrigger* const _this, ICrySizer* _pS)>(0xA55F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeConversationTrigger* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15C8A20);
	static inline auto FSerialize = PreyFunction<void(CArkFlowNodeConversationTrigger* const _this, IFlowNode::SActivationInfo* _pActInfo, TSerialize _ser)>(0x159ED70);
	static inline auto FPostSerialize = PreyFunction<void(CArkFlowNodeConversationTrigger* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15C99D0);
	static inline auto FOnConversationComplete = PreyFunction<void(IArkConversationListener* const _this, const bool _bComplete)>(0x15C9870);
};
#endif // MOONCRASH
