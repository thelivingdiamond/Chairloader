// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CArkFlowNodeGiveKeyCode
// Header:  Prey/GameDll/ark/flowgraph/arkflownodekeycode.h
class CArkFlowNodeGiveKeyCode : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		keycode = 1,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CArkFlowNodeGiveKeyCode(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGiveKeyCode* const _this, SFlowNodeConfig& _rConfig)>(0x15EDCD0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGiveKeyCode* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EE800);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGiveKeyCode* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeGiveKeyCode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15EDC00);
};

// CArkFlowNodeHasKeyCode
// Header:  Prey/GameDll/ark/flowgraph/arkflownodekeycode.h
class CArkFlowNodeHasKeyCode : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		keycode = 1,
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
	CArkFlowNodeHasKeyCode(IFlowNode::SActivationInfo* const _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeHasKeyCode* const _this, SFlowNodeConfig& _rConfig)>(0x15EE000);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeHasKeyCode* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15EE9C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeHasKeyCode* const _this, ICrySizer* _pS)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeHasKeyCode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15ED880);
};

// CArkFlowNodeKeyCodeAcquired
// Header:  Prey/GameDll/ark/flowgraph/arkflownodekeycode.h
class CArkFlowNodeKeyCodeAcquired : public CFlowBaseNode<1>
{ // Size=64 (0x40)
public:
	enum class EArkInputs
	{
		keycode = 0,
	};

	enum class EArkOutputs
	{
		output = 0,
	};

	IFlowNode::SActivationInfo m_ActInfo;
	static inline auto k_nodes = PreyGlobal<std::vector<CArkFlowNodeKeyCodeAcquired*>>(0x2D780A0);

	CArkFlowNodeKeyCodeAcquired(IFlowNode::SActivationInfo* _pActInfo);
	virtual ~CArkFlowNodeKeyCodeAcquired();
	virtual void GetConfiguration(SFlowNodeConfig& _rConfig);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	static void NotifyKeyCodeAcquired(const uint64_t _KeyCodeId) { FNotifyKeyCodeAcquired(_KeyCodeId); }

#if 0
	void OnKeyCodeAcquired(const uint64_t _arg0_);
#endif

	static inline auto FCArkFlowNodeKeyCodeAcquiredOv1 = PreyFunction<void(CArkFlowNodeKeyCodeAcquired* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15EDAC0);
	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeKeyCodeAcquired* const _this, SFlowNodeConfig& _rConfig)>(0x15EE390);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeKeyCodeAcquired* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15C3BA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeKeyCodeAcquired* const _this, ICrySizer* _pS)>(0x182A3D0);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CArkFlowNodeKeyCodeAcquired* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15EDC50);
	static inline auto FNotifyKeyCodeAcquired = PreyFunction<void(const uint64_t _KeyCodeId)>(0x15EE610);
};
#endif // MOONCRASH
