// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/player/IArkPlayerStatusListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// ArkFlowNodeNotifyTrauma
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayerstatus.h
class ArkFlowNodeNotifyTrauma : public CFlowBaseNode<1>, public IArkPlayerStatusListener
{ // Size=72 (0x48)
public:
	enum class ArkInputs
	{
		trauma = 0,
	};

	enum class ArkOutputs
	{
		activated = 0,
		deactivated = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<ArkFlowNodeNotifyTrauma*>>(0x0);

	virtual ~ArkFlowNodeNotifyTrauma();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnStatusChanged(uint64_t _statusId, bool _bActive);

#if 0
	ArkFlowNodeNotifyTrauma(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(ArkFlowNodeNotifyTrauma* const _this, SFlowNodeConfig& _config)>(0x131B620);
	static inline auto FProcessEvent = PreyFunction<void(ArkFlowNodeNotifyTrauma* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x131BAE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkFlowNodeNotifyTrauma* const _this, ICrySizer* _pS)>(0x2D0150);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(ArkFlowNodeNotifyTrauma* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x131B5B0);
	static inline auto FOnStatusChanged = PreyFunction<void(IArkPlayerStatusListener* const _this, uint64_t _statusId, bool _bActive)>(0x131B8C0);
};
#endif // MOONCRASH
