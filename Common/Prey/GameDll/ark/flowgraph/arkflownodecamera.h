// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNode_ForceStopCameraShakes
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecamera.h
class CArkFlowNode_ForceStopCameraShakes : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		cameraShake = 1,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_ForceStopCameraShakes(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_ForceStopCameraShakes* const _this, SFlowNodeConfig& _config)>(0x123E180);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_ForceStopCameraShakes* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123E8B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_ForceStopCameraShakes* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNode_TriggerCameraShake
// Header:  Prey/GameDll/ark/flowgraph/arkflownodecamera.h
class CArkFlowNode_TriggerCameraShake : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		cameraShake = 1,
		position = 2,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_TriggerCameraShake(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_TriggerCameraShake* const _this, SFlowNodeConfig& _config)>(0x123E4A0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_TriggerCameraShake* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x123E980);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_TriggerCameraShake* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
