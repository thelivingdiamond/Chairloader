// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowSetPlayerTimeDilation
// Header:  Prey/GameDll/ark/ArkFlowSetPlayerTimeDilation.h
class CArkFlowSetPlayerTimeDilation : public CFlowBaseNode<1>
{ // Size=24 (0x18)
public:
	enum class EInputs
	{
		IN_TRIGGER = 0,
		IN_VALUE = 1,
	};

	enum class EOutputs
	{
		OUT_TRIGGER = 0,
	};

	int m_timeScaleHandle;

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CArkFlowSetPlayerTimeDilation(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowSetPlayerTimeDilation* const _this, SFlowNodeConfig& config)>(0x154C300);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowSetPlayerTimeDilation* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x154C5D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowSetPlayerTimeDilation* const _this, ICrySizer* s)>(0x4BC120);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowSetPlayerTimeDilation* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x154C2B0);
};
#endif // MOONCRASH
