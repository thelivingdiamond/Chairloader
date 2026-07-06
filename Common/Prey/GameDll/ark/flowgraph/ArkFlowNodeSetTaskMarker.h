// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeSetTaskLocation
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSetTaskMarker.h
class CArkFlowNodeSetTaskLocation : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		TASK = 0,
		SET = 1,
		LOCATION = 2,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetTaskLocation(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetTaskLocation* const _this, SFlowNodeConfig& _rConfig)>(0x15F2CD0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetTaskLocation* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F3160);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetTaskLocation* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetTaskMarker
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSetTaskMarker.h
class CArkFlowNodeSetTaskMarker : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		TASK = 0,
		SET = 1,
		CLEAR = 2,
		DISTANCE = 3,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetTaskMarker(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetTaskMarker* const _this, SFlowNodeConfig& _rConfig)>(0x15F25E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetTaskMarker* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F2AF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetTaskMarker* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetTaskMarkerOverride
// Header:  Prey/GameDll/ark/flowgraph/ArkFlowNodeSetTaskMarker.h
class CArkFlowNodeSetTaskMarkerOverride : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		SET = 0,
		CLEAR = 1,
		OVERRIDEID = 2,
	};

	enum class EOutputs
	{
		OUTPIN = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetTaskMarkerOverride(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetTaskMarkerOverride* const _this, SFlowNodeConfig& _rConfig)>(0x15F3390);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetTaskMarkerOverride* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15F3730);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetTaskMarkerOverride* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
