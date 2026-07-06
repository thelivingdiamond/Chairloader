// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryInput/IInput.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

enum EXBoxKey;
class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;
struct SInputEvent;

// CG4FlowNode_XBoxAnalog
// Header:  Prey/GameDll/nodes/flownodesinput.h
class CG4FlowNode_XBoxAnalog : public CFlowBaseNode<1>, public IInputEventListener
{ // Size=80 (0x50)
public:
	enum EInputPorts
	{
		EIP_Enable = 0,
		EIP_Disable = 1,
		EIP_Key = 2,
		EIP_NonDevMode = 3,
	};

	enum EOutputPorts
	{
		EOP_ChangedX = 0,
		EOP_ChangedY = 1,
	};

	bool m_bActive;
	IFlowNode::SActivationInfo m_actInfo;

	virtual ~CG4FlowNode_XBoxAnalog();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual bool OnInputEvent(const SInputEvent& event);

#if 0
	CG4FlowNode_XBoxAnalog(IFlowNode::SActivationInfo* _arg0_);
	void Register(bool _arg0_);
	EXBoxKey TranslateKeyIntoFGInputEnum(int _arg0_, bool& _arg1_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CG4FlowNode_XBoxAnalog* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A6EF0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CG4FlowNode_XBoxAnalog* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FSerialize = PreyFunction<void(CG4FlowNode_XBoxAnalog* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18A6F60);
	static inline auto FGetConfiguration = PreyFunction<void(CG4FlowNode_XBoxAnalog* const _this, SFlowNodeConfig& config)>(0x18A6FD0);
	static inline auto FProcessEvent = PreyFunction<void(CG4FlowNode_XBoxAnalog* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x13B0900);
};

// CG4FlowNode_XBoxKey
// Header:  Prey/GameDll/nodes/flownodesinput.h
class CG4FlowNode_XBoxKey : public CFlowBaseNode<1>, public IInputEventListener
{ // Size=80 (0x50)
public:
	enum EInputPorts
	{
		EIP_Enable = 0,
		EIP_Disable = 1,
		EIP_Key = 2,
		EIP_NonDevMode = 3,
	};

	enum EOutputPorts
	{
		EOP_Pressed = 0,
		EOP_Released = 1,
	};

	bool m_bActive;
	IFlowNode::SActivationInfo m_actInfo;

	virtual ~CG4FlowNode_XBoxKey();
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual void Serialize(IFlowNode::SActivationInfo* pActInfo, TSerialize ser);
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual bool OnInputEvent(const SInputEvent& event);

#if 0
	CG4FlowNode_XBoxKey(IFlowNode::SActivationInfo* _arg0_);
	void Register(bool _arg0_);
	int TranslateKey(int _arg0_);
#endif

	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CG4FlowNode_XBoxKey* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x18A69B0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CG4FlowNode_XBoxKey* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FSerialize = PreyFunction<void(CG4FlowNode_XBoxKey* const _this, IFlowNode::SActivationInfo* pActInfo, TSerialize ser)>(0x18A6F60);
	static inline auto FGetConfiguration = PreyFunction<void(CG4FlowNode_XBoxKey* const _this, SFlowNodeConfig& config)>(0x18A6A20);
	static inline auto FProcessEvent = PreyFunction<void(CG4FlowNode_XBoxKey* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x1333E90);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& event)>(0x13B0900);
};
#endif // MOONCRASH
