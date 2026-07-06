// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowSetWorldTimeDilation
// Header:  Prey/GameDll/ark/ArkFlowSetWorldTimeDilation.h
class CArkFlowSetWorldTimeDilation : public CFlowBaseNode<1>
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
	CArkFlowSetWorldTimeDilation(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowSetWorldTimeDilation* const _this, SFlowNodeConfig& config)>(0x154C710);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowSetWorldTimeDilation* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x154C9E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowSetWorldTimeDilation* const _this, ICrySizer* s)>(0x4BC120);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowSetWorldTimeDilation* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x154C6C0);
};
#endif // MOONCRASH
