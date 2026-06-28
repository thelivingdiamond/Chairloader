// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeConfirmDialog
// Header:  Prey/GameDll/ark/ui/arkflownodedialog.h
class CArkFlowNodeConfirmDialog : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		trigger = 0,
		label = 1,
		query = 2,
	};

	enum class EArkOutputs
	{
		onConfirm = 0,
		onCancel = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnConfirm() { FOnConfirm(this); }
	void OnCancel() { FOnCancel(this); }

#if 0
	CArkFlowNodeConfirmDialog(IFlowNode::SActivationInfo* const _arg0_);
	void ProcessOutput(const CArkFlowNodeConfirmDialog::EArkOutputs _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this, SFlowNodeConfig& _rConfig)>(0x1712140);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1712A90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeConfirmDialog* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeConfirmDialog* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x1711DD0);
	static inline auto FOnConfirm = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this)>(0x1712A50);
	static inline auto FOnCancel = PreyFunction<void(CArkFlowNodeConfirmDialog* const _this)>(0x1246AF0);
};

// CArkFlowNodeNotificationDialog
// Header:  Prey/GameDll/ark/ui/arkflownodedialog.h
class CArkFlowNodeNotificationDialog : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		trigger = 0,
		label = 1,
		message = 2,
	};

	enum class EArkOutputs
	{
		onClose = 0,
	};

	IFlowNode::SActivationInfo m_actInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnClose() { FOnClose(this); }

#if 0
	CArkFlowNodeNotificationDialog(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeNotificationDialog* const _this, SFlowNodeConfig& _rConfig)>(0x17125E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeNotificationDialog* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x1712C00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeNotificationDialog* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeNotificationDialog* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x17120E0);
	static inline auto FOnClose = PreyFunction<void(CArkFlowNodeNotificationDialog* const _this)>(0x1712A50);
};
#endif // MOONCRASH
