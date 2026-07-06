// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// ArkFlowNodeRemoveLocationAlternateName
// Header:  Prey/GameDll/ark/flowgraph/arkflownodelocation.h
class ArkFlowNodeRemoveLocationAlternateName : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		location = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeRemoveLocationAlternateName(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeRemoveLocationAlternateName* const _this, SFlowNodeConfig& _rConfig)>(0x15E3B40);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeRemoveLocationAlternateName* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E3E70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeRemoveLocationAlternateName* const _this, ICrySizer* _pS)>(0x455F00);
};

// ArkFlowNodeSetLocationAlternateName
// Header:  Prey/GameDll/ark/flowgraph/arkflownodelocation.h
class ArkFlowNodeSetLocationAlternateName : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		location = 1,
		name = 2,
		screenshot = 3,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	ArkFlowNodeSetLocationAlternateName(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeSetLocationAlternateName* const _this, SFlowNodeConfig& _rConfig)>(0x15E34D0);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeSetLocationAlternateName* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E3A70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeSetLocationAlternateName* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeDiscoverLocation
// Header:  Prey/GameDll/ark/flowgraph/arkflownodelocation.h
class CArkFlowNodeDiscoverLocation : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		location = 1,
		popup = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeDiscoverLocation(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeDiscoverLocation* const _this, SFlowNodeConfig& _rConfig)>(0x15E2900);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeDiscoverLocation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E2D10);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeDiscoverLocation* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeHasDiscoveredLocation
// Header:  Prey/GameDll/ark/flowgraph/arkflownodelocation.h
class CArkFlowNodeHasDiscoveredLocation : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		location = 1,
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

#if 0
	CArkFlowNodeHasDiscoveredLocation(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasDiscoveredLocation* const _this, SFlowNodeConfig& _rConfig)>(0x15E2F40);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasDiscoveredLocation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E32D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasDiscoveredLocation* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
