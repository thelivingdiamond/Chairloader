// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct SFlowNodeConfig;

// CArkFlowNodeGetEquippedItem
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayerequip.h
class CArkFlowNodeGetEquippedItem : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
	};

	enum class EArkOutputs
	{
		itemId = 0,
		itemClass = 1,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeGetEquippedItem(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeGetEquippedItem* const _this, SFlowNodeConfig& _config)>(0x15CA480);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeGetEquippedItem* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CA6A0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeGetEquippedItem* const _this, ICrySizer* _pSizer)>(0x455F00);
};

// CArkFlowNodeSetEquippedItem
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayerequip.h
class CArkFlowNodeSetEquippedItem : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
		itemId = 1,
	};

	enum class EArkOutputs
	{
		success = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeSetEquippedItem(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeSetEquippedItem* const _this, SFlowNodeConfig& _config)>(0x15CA8D0);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeSetEquippedItem* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CABA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeSetEquippedItem* const _this, ICrySizer* _pSizer)>(0x455F00);
};

// CArkFlowNodeUnequipItem
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeplayerequip.h
class CArkFlowNodeUnequipItem : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputs
	{
		trigger = 0,
	};

	enum class EArkOutputs
	{
		success = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CArkFlowNodeUnequipItem(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CArkFlowNodeUnequipItem* const _this, SFlowNodeConfig& _config)>(0x15CAC80);
	static inline auto FProcessEvent = PreyFunction<void(CArkFlowNodeUnequipItem* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15CAE70);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CArkFlowNodeUnequipItem* const _this, ICrySizer* _pSizer)>(0x455F00);
};
#endif // MOONCRASH
