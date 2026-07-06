// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowGetRandomValue
// Header:  Prey/GameDll/ark/flowgraph/arkflowrandomvaluenodes.h
class ArkFlowGetRandomValue : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		randomValue = 1,
	};

	enum class EOutputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowGetRandomValue(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowGetRandomValue* const _this, SFlowNodeConfig& _config)>(0x11E1BE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowGetRandomValue* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E1F10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowGetRandomValue* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowGetShuffledListValue
// Header:  Prey/GameDll/ark/flowgraph/arkflowrandomvaluenodes.h
class ArkFlowGetShuffledListValue : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		get = 0,
		shuffledList = 1,
		index = 2,
	};

	enum class EOutputs
	{
		out = 0,
		outOfBounds = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowGetShuffledListValue(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowGetShuffledListValue* const _this, SFlowNodeConfig& _config)>(0x11E2490);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowGetShuffledListValue* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E28E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowGetShuffledListValue* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowLockRandomSeed
// Header:  Prey/GameDll/ark/flowgraph/arkflowrandomvaluenodes.h
class ArkFlowLockRandomSeed : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		locked = 1,
	};

	enum class EOutputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowLockRandomSeed(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowLockRandomSeed* const _this, SFlowNodeConfig& _config)>(0x11E2070);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowLockRandomSeed* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x11E2340);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowLockRandomSeed* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
