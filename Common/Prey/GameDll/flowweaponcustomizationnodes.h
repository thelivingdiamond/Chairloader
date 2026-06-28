// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlashUIGetCompatibleAccessoriesNode
// Header:  Prey/GameDll/flowweaponcustomizationnodes.h
class CFlashUIGetCompatibleAccessoriesNode : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eI_Call = 0,
		eI_Weapon = 1,
	};

	enum EOutputs
	{
		eO_OnCall = 0,
		eO_Args = 1,
	};

	virtual ~CFlashUIGetCompatibleAccessoriesNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlashUIGetCompatibleAccessoriesNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlashUIGetCompatibleAccessoriesNode* const _this, SFlowNodeConfig& config)>(0x17E4760);
	static inline auto FProcessEvent = PreyFunction<void(CFlashUIGetCompatibleAccessoriesNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x17E4AC0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlashUIGetCompatibleAccessoriesNode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlashUIGetCompatibleAccessoriesNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x17E4B10);
};

// CFlashUIGetEquippedAccessoriesNode
// Header:  Prey/GameDll/flowweaponcustomizationnodes.h
class CFlashUIGetEquippedAccessoriesNode : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eI_Call = 0,
		eI_Weapon = 1,
	};

	enum EOutputs
	{
		eO_OnCall = 0,
		eO_Args = 1,
	};

	virtual ~CFlashUIGetEquippedAccessoriesNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlashUIGetEquippedAccessoriesNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlashUIGetEquippedAccessoriesNode* const _this, SFlowNodeConfig& config)>(0x17E4080);
	static inline auto FProcessEvent = PreyFunction<void(CFlashUIGetEquippedAccessoriesNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x17E43E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlashUIGetEquippedAccessoriesNode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlashUIGetEquippedAccessoriesNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x17E4B60);
};

// CFlashUIInventoryNode
// Header:  Prey/GameDll/flowweaponcustomizationnodes.h
class CFlashUIInventoryNode : public CFlowBaseNode<1>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		eI_Call = 0,
	};

	enum EOutputs
	{
		eO_OnCall = 0,
		eO_Args = 1,
	};

	virtual ~CFlashUIInventoryNode();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* pActInfo);

#if 0
	CFlashUIInventoryNode(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlashUIInventoryNode* const _this, SFlowNodeConfig& config)>(0x17E4C00);
	static inline auto FProcessEvent = PreyFunction<void(CFlashUIInventoryNode* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x17E4EB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlashUIInventoryNode* const _this, ICrySizer* s)>(0x455F00);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlashUIInventoryNode* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* pActInfo)>(0x17E4BB0);
};
#endif // MOONCRASH
