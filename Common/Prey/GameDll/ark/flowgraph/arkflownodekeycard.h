// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeGiveKeyCard
// Header:  Prey/GameDll/ark/flowgraph/arkflownodekeycard.h
class CArkFlowNodeGiveKeyCard : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		keycard = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeGiveKeyCard(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveKeyCard* const _this, SFlowNodeConfig& _rConfig)>(0x15E1980);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGiveKeyCard* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E24B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGiveKeyCard* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGiveKeyCard* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15E18B0);
};

// CArkFlowNodeHasKeyCard
// Header:  Prey/GameDll/ark/flowgraph/arkflownodekeycard.h
class CArkFlowNodeHasKeyCard : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		keycard = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		outTrue = 1,
		outFalse = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeHasKeyCard(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasKeyCard* const _this, SFlowNodeConfig& _rConfig)>(0x15E1CB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasKeyCard* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E2670);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasKeyCard* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeHasKeyCard* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15E1530);
};

// CArkFlowNodeKeyCardAcquired
// Header:  Prey/GameDll/ark/flowgraph/arkflownodekeycard.h
class CArkFlowNodeKeyCardAcquired : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		keycard = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodeKeyCardAcquired*>>(0x2D76A80);

	CArkFlowNodeKeyCardAcquired(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CArkFlowNodeKeyCardAcquired();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyKeyCardAcquired(const uint64_t _keycardId) { FNotifyKeyCardAcquired(_keycardId); }

#if 0
	void OnKeyCardAcquired(const uint64_t _arg0_);
#endif

	static inline auto FCArkFlowNodeKeyCardAcquiredOv1 = PreyFunction<void(CArkFlowNodeKeyCardAcquired* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15E1770);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeKeyCardAcquired* const _this, SFlowNodeConfig& _rConfig)>(0x15E2040);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeKeyCardAcquired* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeKeyCardAcquired* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeKeyCardAcquired* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15E1900);
	static inline auto FNotifyKeyCardAcquired = PreyFunction<void(const uint64_t _keycardId)>(0x15E22C0);
};
#endif // MOONCRASH
