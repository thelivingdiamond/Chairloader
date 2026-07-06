// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ui/IHUDEventListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
struct SHUDEvent;

// CTacticalScanCompleteNode
// Header:  Prey/GameDll/nodes/TacticalScanNode.h
class CTacticalScanCompleteNode : public CFlowBaseNode<1>, private IHUDEventListener
{ // Size=80 (0x50)
public:
	enum INPUTS
	{
		EIP_Enable = 0,
		EIP_DelayResult = 1,
		EIP_Disable = 2,
	};

	enum OUTPUTS
	{
		EOP_OnEvent = 0,
		EOP_EntityID = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;
	bool m_enabled;
	bool m_delayResult;

	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual ~CTacticalScanCompleteNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void OnHUDEvent(const SHUDEvent& event);

#if 0
	CTacticalScanCompleteNode(IFlowNode::SActivationInfo* _arg0_);
	void SetEnabled(bool _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CTacticalScanCompleteNode* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CTacticalScanCompleteNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18BAC80);
	static inline auto FSerialize = PreyFunction<void(CTacticalScanCompleteNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B9E30);
	static inline auto FGetConfiguration = PreyFunction<void(CTacticalScanCompleteNode* const _this, SFlowNodeConfig& config)>(0x18B9F30);
	static inline auto FProcessEvent = PreyFunction<void(CTacticalScanCompleteNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18BA320);
	static inline auto FOnHUDEvent = PreyFunction<void(IHUDEventListener* const _this, const SHUDEvent& event)>(0x18BA420);
};

// CTacticalScanCurrentControlNode
// Header:  Prey/GameDll/nodes/TacticalScanNode.h
class CTacticalScanCurrentControlNode : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum INPUTS
	{
		EIP_FailCurrentScan = 0,
		EIP_SucceedCurrentScan = 1,
	};

	enum OUTPUTS
	{
		EOP_Failed = 0,
		EOP_Succeeded = 1,
	};

	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual ~CTacticalScanCurrentControlNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);

#if 0
	CTacticalScanCurrentControlNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CTacticalScanCurrentControlNode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FGetConfiguration = PreyFunction<void(CTacticalScanCurrentControlNode* const _this, SFlowNodeConfig& config)>(0x18BA650);
	static inline auto FProcessEvent = PreyFunction<void(CTacticalScanCurrentControlNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18BA950);
};

// CTacticalScanNode
// Header:  Prey/GameDll/nodes/TacticalScanNode.h
class CTacticalScanNode : public CFlowBaseNode<1>, private IHUDEventListener
{ // Size=80 (0x50)
public:
	enum INPUTS
	{
		EIP_Enable = 0,
		EIP_Disable = 1,
	};

	enum OUTPUTS
	{
		EOP_EntityID = 0,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;
	bool m_enabled;

	CTacticalScanNode(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual ~CTacticalScanNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void OnHUDEvent(const SHUDEvent& event);

	static inline auto FCTacticalScanNodeOv1 = PreyFunction<void(CTacticalScanNode* const _this, IFlowNode::SActivationInfo* pActInfo)>(0x18BAD80);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CTacticalScanNode* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CTacticalScanNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18B90A0);
	static inline auto FSerialize = PreyFunction<void(CTacticalScanNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B9130);
	static inline auto FGetConfiguration = PreyFunction<void(CTacticalScanNode* const _this, SFlowNodeConfig& config)>(0x18B9220);
	static inline auto FProcessEvent = PreyFunction<void(CTacticalScanNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B9500);
	static inline auto FOnHUDEvent = PreyFunction<void(IHUDEventListener* const _this, const SHUDEvent& event)>(0x18B9540);
};

// CTacticalScanStartNode
// Header:  Prey/GameDll/nodes/TacticalScanNode.h
class CTacticalScanStartNode : public CFlowBaseNode<1>, private IHUDEventListener
{ // Size=80 (0x50)
public:
	enum INPUTS
	{
		EIP_Enable = 0,
		EIP_DelayResult = 1,
		EIP_Disable = 2,
	};

	enum OUTPUTS
	{
		EOP_OnEvent = 0,
		EOP_EntityID = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;
	bool m_enabled;
	bool m_delayResult;

	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual ~CTacticalScanStartNode();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void OnHUDEvent(const SHUDEvent& event);

#if 0
	CTacticalScanStartNode(IFlowNode::SActivationInfo* _arg0_);
	void SetEnabled(bool _arg0_);
#endif

	static inline auto FGetMemoryUsage = PreyFunction<void(const CTacticalScanStartNode* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CTacticalScanStartNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18BAC10);
	static inline auto FSerialize = PreyFunction<void(CTacticalScanStartNode* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18B9620);
	static inline auto FGetConfiguration = PreyFunction<void(CTacticalScanStartNode* const _this, SFlowNodeConfig& config)>(0x18B9710);
	static inline auto FProcessEvent = PreyFunction<void(CTacticalScanStartNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x18B9B00);
	static inline auto FOnHUDEvent = PreyFunction<void(IHUDEventListener* const _this, const SHUDEvent& event)>(0x18B9C00);
};
#endif // MOONCRASH
