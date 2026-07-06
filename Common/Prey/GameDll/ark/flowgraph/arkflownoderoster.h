// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeCharacterPasswordAcquired
// Header:  Prey/GameDll/ark/flowgraph/arkflownoderoster.h
class CArkFlowNodeCharacterPasswordAcquired : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		character = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual ~CArkFlowNodeCharacterPasswordAcquired();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnPasswordAcquired(const uint64_t _characterId) { FOnPasswordAcquired(this, _characterId); }

#if 0
	CArkFlowNodeCharacterPasswordAcquired(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCharacterPasswordAcquired* const _this, SFlowNodeConfig& _rConfig)>(0x15F0250);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCharacterPasswordAcquired* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F11B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCharacterPasswordAcquired* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeCharacterPasswordAcquired* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F0150);
	static inline auto FOnPasswordAcquired = PreyFunction<void(CArkFlowNodeCharacterPasswordAcquired* const _this, const uint64_t _characterId)>(0x15F0FA0);
};

// CArkFlowNodeGiveCharacterInfo
// Header:  Prey/GameDll/ark/flowgraph/arkflownoderoster.h
class CArkFlowNodeGiveCharacterInfo : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		character = 1,
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
	CArkFlowNodeGiveCharacterInfo(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveCharacterInfo* const _this, SFlowNodeConfig& _rConfig)>(0x15F04D0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGiveCharacterInfo* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1200);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGiveCharacterInfo* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGiveCharacterInfo* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F01B0);
};

// CArkFlowNodeGiveCharacterPassword
// Header:  Prey/GameDll/ark/flowgraph/arkflownoderoster.h
class CArkFlowNodeGiveCharacterPassword : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		character = 1,
		showHUDNotification = 2,
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
	CArkFlowNodeGiveCharacterPassword(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveCharacterPassword* const _this, SFlowNodeConfig& _rConfig)>(0x15F0800);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGiveCharacterPassword* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1400);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGiveCharacterPassword* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGiveCharacterPassword* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F0200);
};

// CArkFlowNodeHasCharacterPassword
// Header:  Prey/GameDll/ark/flowgraph/arkflownoderoster.h
class CArkFlowNodeHasCharacterPassword : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		character = 1,
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
	CArkFlowNodeHasCharacterPassword(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasCharacterPassword* const _this, SFlowNodeConfig& _rConfig)>(0x15F0C10);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasCharacterPassword* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F1660);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasCharacterPassword* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeHasCharacterPassword* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15F0090);
};
#endif // MOONCRASH
