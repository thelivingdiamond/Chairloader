// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeCheckDownloadHidden
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCheckDownloadHidden : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		download = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		hidden = 1,
		shown = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeCheckDownloadHidden(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCheckDownloadHidden* const _this, SFlowNodeConfig& _rConfig)>(0x15CFBB0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCheckDownloadHidden* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CFF40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCheckDownloadHidden* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeCheckUtilityButtonEnabled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCheckUtilityButtonEnabled : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		utilityButton = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		enabled = 1,
		disabled = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeCheckUtilityButtonEnabled(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCheckUtilityButtonEnabled* const _this, SFlowNodeConfig& _rConfig)>(0x15D2D30);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCheckUtilityButtonEnabled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D30C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCheckUtilityButtonEnabled* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeCheckUtilityButtonHidden
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCheckUtilityButtonHidden : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		utilityButton = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		hidden = 1,
		shown = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeCheckUtilityButtonHidden(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCheckUtilityButtonHidden* const _this, SFlowNodeConfig& _rConfig)>(0x15D37E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCheckUtilityButtonHidden* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D3B70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCheckUtilityButtonHidden* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeCheckUtilityEnabled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCheckUtilityEnabled : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		utility = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		enabled = 1,
		disabled = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeCheckUtilityEnabled(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCheckUtilityEnabled* const _this, SFlowNodeConfig& _rConfig)>(0x15D0A50);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCheckUtilityEnabled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D0DE0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCheckUtilityEnabled* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeCheckUtilityHidden
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCheckUtilityHidden : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		utility = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
		hidden = 1,
		shown = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeCheckUtilityHidden(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCheckUtilityHidden* const _this, SFlowNodeConfig& _rConfig)>(0x15D1E90);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCheckUtilityHidden* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D2220);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCheckUtilityHidden* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeCompareUtility
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCompareUtility : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		input = 0,
		utility = 1,
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
	CArkFlowNodeCompareUtility(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCompareUtility* const _this, SFlowNodeConfig& _rConfig)>(0x15D0060);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCompareUtility* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D0490);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCompareUtility* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeCompareUtilityButton
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeCompareUtilityButton : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		input = 0,
		utilityButton = 1,
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
	CArkFlowNodeCompareUtilityButton(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeCompareUtilityButton* const _this, SFlowNodeConfig& _rConfig)>(0x15D2340);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeCompareUtilityButton* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D2770);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeCompareUtilityButton* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeDownloadAcquired
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeDownloadAcquired : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		download = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodeDownloadAcquired*>>(0x2D745D0);

	CArkFlowNodeDownloadAcquired(IFlowNode::SActivationInfo* const _pActInfo);
	virtual ~CArkFlowNodeDownloadAcquired();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyDownloadAcquired(const uint64_t _downloadID) { FNotifyDownloadAcquired(_downloadID); }

#if 0
	void OnDownloadAcquired(const uint64_t _arg0_);
#endif

	static inline auto FCArkFlowNodeDownloadAcquiredOv1 = PreyFunction<void(CArkFlowNodeDownloadAcquired* const _this, IFlowNode::SActivationInfo* const _pActInfo)>(0x15D4EC0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeDownloadAcquired* const _this, SFlowNodeConfig& _rConfig)>(0x15D52E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeDownloadAcquired* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeDownloadAcquired* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeDownloadAcquired* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D5140);
	static inline auto FNotifyDownloadAcquired = PreyFunction<void(const uint64_t _downloadID)>(0x15D6E40);
};

// CArkFlowNodeEmailAcquired
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeEmailAcquired : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum EArkInputs
	{
		email = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodeEmailAcquired*>>(0x2D745B8);

	CArkFlowNodeEmailAcquired(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CArkFlowNodeEmailAcquired();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyEmailAcquired(const uint64_t _emailId) { FNotifyEmailAcquired(_emailId); }

#if 0
	void OnEmailAcquired(const uint64_t _arg0_);
#endif

	static inline auto FCArkFlowNodeEmailAcquiredOv1 = PreyFunction<void(CArkFlowNodeEmailAcquired* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15D4F10);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeEmailAcquired* const _this, SFlowNodeConfig& _rConfig)>(0x15D5560);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeEmailAcquired* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeEmailAcquired* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeEmailAcquired* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D51C0);
	static inline auto FNotifyEmailAcquired = PreyFunction<void(const uint64_t _emailId)>(0x15D6FD0);
};

// CArkFlowNodeHasDownload
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeHasDownload : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		download = 1,
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
	CArkFlowNodeHasDownload(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasDownload* const _this, SFlowNodeConfig& _rConfig)>(0x15D57E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasDownload* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D71F0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasDownload* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeHasDownload* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D5240);
};

// CArkFlowNodeHasEmail
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeHasEmail : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		email = 1,
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
	CArkFlowNodeHasEmail(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasEmail* const _this, SFlowNodeConfig& _rConfig)>(0x15D5B70);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasEmail* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D7300);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasEmail* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeHasEmail* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D5290);
};

// CArkFlowNodeHideEmail
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeHideEmail : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		email = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeHideEmail(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHideEmail* const _this, SFlowNodeConfig& _rConfig)>(0x15CF2B0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHideEmail* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CF5E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHideEmail* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSendEmail
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeSendEmail : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		email = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSendEmail(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSendEmail* const _this, SFlowNodeConfig& _rConfig)>(0x15CEE90);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSendEmail* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CF1C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSendEmail* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetDownloadHidden
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeSetDownloadHidden : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		hide = 0,
		show = 1,
		download = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetDownloadHidden(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetDownloadHidden* const _this, SFlowNodeConfig& _rConfig)>(0x15CF6D0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetDownloadHidden* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CFAD0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetDownloadHidden* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetUtilityButtonEnabled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeSetUtilityButtonEnabled : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		enable = 0,
		disable = 1,
		utilityButton = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetUtilityButtonEnabled(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetUtilityButtonEnabled* const _this, SFlowNodeConfig& _rConfig)>(0x15D2850);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetUtilityButtonEnabled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D2C50);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetUtilityButtonEnabled* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetUtilityButtonHidden
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeSetUtilityButtonHidden : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		hide = 0,
		show = 1,
		utilityButton = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetUtilityButtonHidden(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetUtilityButtonHidden* const _this, SFlowNodeConfig& _rConfig)>(0x15D31E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetUtilityButtonHidden* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D3670);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetUtilityButtonHidden* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetUtilityEnabled
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeSetUtilityEnabled : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		enable = 0,
		disable = 1,
		utility = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetUtilityEnabled(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetUtilityEnabled* const _this, SFlowNodeConfig& _rConfig)>(0x15D0570);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetUtilityEnabled* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D0970);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetUtilityEnabled* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeSetUtilityHidden
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeSetUtilityHidden : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		hide = 0,
		show = 1,
		utility = 2,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNodeSetUtilityHidden(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetUtilityHidden* const _this, SFlowNodeConfig& _rConfig)>(0x15D0F00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetUtilityHidden* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D1300);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetUtilityHidden* const _this, ICrySizer* _pS)>(0x455F00);
};

// CArkFlowNodeWorkstationPopup
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeWorkstationPopup : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		trigger = 0,
		clear = 1,
		title = 2,
		body = 3,
		duration = 4,
		allowConfirm = 5,
		allowCancel = 6,
	};

	enum class EArkOutputs
	{
		output = 0,
		confirmed = 1,
		cancelled = 2,
		triggered = 3,
		cleared = 4,
		completed = 5,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnPopupInteraction(bool _bConfirm) { FOnPopupInteraction(this, _bConfirm); }
	void OnPopupDurationComplete() { FOnPopupDurationComplete(this); }

#if 0
	CArkFlowNodeWorkstationPopup(IFlowNode::SActivationInfo* const _arg0_);
	const IFlowNode::SActivationInfo& GetActivationInfo() const;
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeWorkstationPopup* const _this, SFlowNodeConfig& _rConfig)>(0x15D5F00);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeWorkstationPopup* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D7420);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeWorkstationPopup* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeWorkstationPopup* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D4450);
	static inline auto FOnPopupInteraction = PreyFunction<void(CArkFlowNodeWorkstationPopup* const _this, bool _bConfirm)>(0x15D71A0);
	static inline auto FOnPopupDurationComplete = PreyFunction<void(CArkFlowNodeWorkstationPopup* const _this)>(0x15D7160);
};

// CArkFlowNodeWorkstationResult
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNodeWorkstationResult : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		trigger = 0,
		clear = 1,
		title = 2,
		body = 3,
		error = 4,
	};

	enum class EArkOutputs
	{
		output = 0,
		confirmed = 1,
	};

	IFlowNode::SActivationInfo m_ActInfo;

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void OnResultConfirmation() { FOnResultConfirmation(this); }

#if 0
	CArkFlowNodeWorkstationResult(IFlowNode::SActivationInfo* const _arg0_);
	const IFlowNode::SActivationInfo& GetActivationInfo() const;
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeWorkstationResult* const _this, SFlowNodeConfig& _rConfig)>(0x15D67F0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeWorkstationResult* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D7690);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeWorkstationResult* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeWorkstationResult* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15D43F0);
	static inline auto FOnResultConfirmation = PreyFunction<void(CArkFlowNodeWorkstationResult* const _this)>(0x1246AF0);
};

// CArkFlowNode_WhiplashPopup
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeworkstation.h
class CArkFlowNode_WhiplashPopup : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EInputs
	{
		trigger = 0,
		craterState = 1,
		labsState = 2,
		moonworksState = 3,
		crewState = 4,
		locKey0 = 5,
		locKey1 = 6,
		locKey2 = 7,
	};

	enum class EOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CArkFlowNode_WhiplashPopup(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNode_WhiplashPopup* const _this, SFlowNodeConfig& _config)>(0x15D13E0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNode_WhiplashPopup* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15D1D00);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNode_WhiplashPopup* const _this, ICrySizer* _pS)>(0x455F00);
};
#endif // MOONCRASH
