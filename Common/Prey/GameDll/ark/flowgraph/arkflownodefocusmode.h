// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeFocusModeEnabled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodefocusmode.h
class CArkFlowNodeFocusModeEnabled : public CFlowBaseNode<0>
{ // Size=64 (0x40)
public:
	enum EArkInputs
	{
		enable = 0,
	};

	enum class EArkOutputs
	{
		enabled = 0,
		disabled = 1,
	};

	IFlowNode::SActivationInfo m_activationInfo;

	virtual ~CArkFlowNodeFocusModeEnabled();
	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	void OnFocusModeEnabled() const { FOnFocusModeEnabled(this); }
	void OnFocusModeDisabled() const { FOnFocusModeDisabled(this); }

#if 0
	CArkFlowNodeFocusModeEnabled(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeFocusModeEnabled* const _this, SFlowNodeConfig& _config)>(0x1241C90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeFocusModeEnabled* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeFocusModeEnabled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1241EC0);
	static inline auto FOnFocusModeEnabled = PreyFunction<void(const CArkFlowNodeFocusModeEnabled* const _this)>(0x1242050);
	static inline auto FOnFocusModeDisabled = PreyFunction<void(const CArkFlowNodeFocusModeEnabled* const _this)>(0x1241FC0);
};
#endif // MOONCRASH
