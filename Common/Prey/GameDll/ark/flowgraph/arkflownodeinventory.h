// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/CryFlowGraph/IFlowBaseNode.h>
#include <Prey/CryFlowGraph/IFlowSystem.h>

class ICrySizer;
struct IFlowNode;
struct SFlowNodeConfig;

// CFlowNode_AddEquipmentPack
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_AddEquipmentPack : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EInputs
	{
		EIP_Trigger = 0,
		EIP_EquipmentPack = 1,
		EIP_AddToggle = 2,
		EIP_SelectPrimary = 3,
	};

	enum EOutputs
	{
		EOP_Done = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_AddEquipmentPack(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_AddEquipmentPack* const _this, SFlowNodeConfig& config)>(0x15DFBD0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_AddEquipmentPack* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E00D0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_AddEquipmentPack* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowNode_AddLoot
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_AddLoot : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class inputs
	{
		trigger = 0,
		table = 1,
	};

	enum class outputs
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pS) const;

#if 0
	CFlowNode_AddLoot(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_AddLoot* const _this, SFlowNodeConfig& _config)>(0x15E02C0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_AddLoot* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E0610);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_AddLoot* const _this, ICrySizer* _pS)>(0x455F00);
};

// CFlowNode_InventoryAddItem
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryAddItem : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	enum class EArkInputPorts
	{
		trigger = 0,
		archetype = 1,
		quantity = 2,
		quality = 3,
		fanfare = 4,
	};

	enum class EArkOutputPorts
	{
		returnValue = 0,
		success = 1,
		failure = 2,
	};

	ArkAudioTrigger m_fanfare;

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_InventoryAddItem(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryAddItem* const _this, SFlowNodeConfig& config)>(0x15DCB10);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryAddItem* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x15DD1C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryAddItem* const _this, ICrySizer* s)>(0x4BC120);
};

// CFlowNode_InventoryAddItemById
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryAddItemById : public CFlowBaseNode<0>
{ // Size=24 (0x18)
public:
	enum class EArkInputPorts
	{
		trigger = 0,
		entityId = 1,
		visible = 2,
		fanfare = 3,
	};

	enum class EArkOutputPorts
	{
		output = 0,
		success = 1,
		failure = 2,
	};

	ArkAudioTrigger m_fanfare;

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;

#if 0
	CFlowNode_InventoryAddItemById(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryAddItemById* const _this, SFlowNodeConfig& config)>(0x15DD890);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryAddItemById* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DDDA0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryAddItemById* const _this, ICrySizer* _pSizer)>(0x4BC120);
};

// CFlowNode_InventoryGetItemQuantity
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryGetItemQuantity : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		trigger = 0,
		archetype = 1,
	};

	enum class EArkOutputPorts
	{
		quantity = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_InventoryGetItemQuantity(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryGetItemQuantity* const _this, SFlowNodeConfig& _config)>(0x15DF690);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryGetItemQuantity* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DF9E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryGetItemQuantity* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowNode_InventoryHasItem
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryHasItem : public CFlowBaseNode<1>, public IArkInventoryListener
{ // Size=80 (0x50)
public:
	enum class EArkInputPorts
	{
		onAcquired = 0,
		trigger = 1,
		archetype = 2,
		itemClass = 3,
	};

	enum class EArkOutputPorts
	{
		output = 0,
		falseTrigger = 1,
		trueTrigger = 2,
		entityId = 3,
	};

	IFlowNode::SActivationInfo mActivationInfo;
	unsigned m_entityId;
	bool m_bRegistered;

	virtual ~CFlowNode_InventoryHasItem();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnItemEquipped(unsigned _itemId);
	virtual void OnItemUnequipped(unsigned _itemId);
	virtual void OnItemAdded(unsigned _entityId, unsigned _originalId, bool _bPrimaryInventory);
	virtual void OnItemRemoved(unsigned _entityId, bool _bPrimaryInventory);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);
	void ResetInventory(IFlowNode::SActivationInfo* _pActInfo) { FResetInventory(this, _pActInfo); }

#if 0
	CFlowNode_InventoryHasItem(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryHasItem* const _this, SFlowNodeConfig& config)>(0x15DEAB0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryHasItem* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DF0B0);
	static inline auto FOnItemEquipped = PreyFunction<void(CFlowNode_InventoryHasItem* const _this, unsigned _itemId)>(0x1333E90);
	static inline auto FOnItemUnequipped = PreyFunction<void(CFlowNode_InventoryHasItem* const _this, unsigned _itemId)>(0x1333E90);
	static inline auto FOnItemAdded = PreyFunction<void(IArkInventoryListener* const _this, unsigned _entityId, unsigned _originalId, bool _bPrimaryInventory)>(0x15DF380);
	static inline auto FOnItemRemoved = PreyFunction<void(IArkInventoryListener* const _this, unsigned _entityId, bool _bPrimaryInventory)>(0x15DF4C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryHasItem* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_InventoryHasItem* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15DD780);
	static inline auto FResetInventory = PreyFunction<void(CFlowNode_InventoryHasItem* const _this, IFlowNode::SActivationInfo* _pActInfo)>(0x15E1440);
};

// CFlowNode_InventoryItemListener
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryItemListener : public CFlowBaseNode<1>, public IArkInventoryListener
{ // Size=80 (0x50)
public:
	enum class EArkInputPorts
	{
		archetype = 0,
	};

	enum class EArkOutputPorts
	{
		output = 0,
		entityId = 1,
	};

	IFlowNode::SActivationInfo m_actInfo;
	unsigned m_entityId;

	virtual ~CFlowNode_InventoryItemListener();
	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void OnItemEquipped(unsigned _itemId);
	virtual void OnItemUnequipped(unsigned _itemId);
	virtual void OnItemAdded(unsigned _entityId, unsigned _originalId, bool _bPrimaryInventory);
	virtual void OnItemRemoved(unsigned _entityId, bool _bPrimaryInventory);
	virtual void GetMemoryUsage(ICrySizer* s) const;
	virtual _smart_ptr<IFlowNode> Clone(IFlowNode::SActivationInfo* _pActInfo);

#if 0
	CFlowNode_InventoryItemListener(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryItemListener* const _this, SFlowNodeConfig& config)>(0x15E0980);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryItemListener* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* _pActInfo)>(0x15E0C30);
	static inline auto FOnItemEquipped = PreyFunction<void(CFlowNode_InventoryItemListener* const _this, unsigned _itemId)>(0x1333E90);
	static inline auto FOnItemUnequipped = PreyFunction<void(CFlowNode_InventoryItemListener* const _this, unsigned _itemId)>(0x1333E90);
	static inline auto FOnItemAdded = PreyFunction<void(IArkInventoryListener* const _this, unsigned _entityId, unsigned _originalId, bool _bPrimaryInventory)>(0x15E0CC0);
	static inline auto FOnItemRemoved = PreyFunction<void(IArkInventoryListener* const _this, unsigned _entityId, bool _bPrimaryInventory)>(0x1333E90);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryItemListener* const _this, ICrySizer* s)>(0x4B5230);
	static inline auto FClone = PreyFunction<_smart_ptr<IFlowNode>*(CFlowNode_InventoryItemListener* const _this, _smart_ptr<IFlowNode>* _return_value_, IFlowNode::SActivationInfo* _pActInfo)>(0x15DE0A0);
};

// CFlowNode_InventoryRemoveAllItems
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryRemoveAllItems : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		trigger = 0,
	};

	enum class EArkOutputPorts
	{
		out = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& _config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo);
	virtual void GetMemoryUsage(ICrySizer* _s) const;

#if 0
	CFlowNode_InventoryRemoveAllItems(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryRemoveAllItems* const _this, SFlowNodeConfig& _config)>(0x15DE830);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryRemoveAllItems* const _this, IFlowNode::EFlowEvent _event, IFlowNode::SActivationInfo* _pActInfo)>(0x15DEA40);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryRemoveAllItems* const _this, ICrySizer* _s)>(0x455F00);
};

// CFlowNode_InventoryRemoveItem
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_InventoryRemoveItem : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum class EArkInputPorts
	{
		trigger = 0,
		archetype = 1,
		quantity = 2,
	};

	enum class EArkOutputPorts
	{
		returnValue = 0,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_InventoryRemoveItem(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_InventoryRemoveItem* const _this, SFlowNodeConfig& config)>(0x15DE1B0);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_InventoryRemoveItem* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x15DE5E0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_InventoryRemoveItem* const _this, ICrySizer* s)>(0x455F00);
};

// CFlowNode_SpawnItemArchetype
// Header:  Prey/GameDll/ark/flowgraph/arkflownodeinventory.h
class CFlowNode_SpawnItemArchetype : public CFlowBaseNode<0>
{ // Size=16 (0x10)
public:
	enum EArkInputPorts
	{
		EIP_Spawn = 0,
		EIP_ArchetypeName = 1,
		EIP_Name = 2,
		EIP_Pos = 3,
		EIP_Rot = 4,
		EIP_Scale = 5,
		EIP_Count = 6,
		EIP_QualityTier = 7,
	};

	enum EArkOutputPorts
	{
		EOP_Done = 0,
		EOP_Succeeded = 1,
		EOP_Failed = 2,
	};

	virtual void GetConfiguration(SFlowNodeConfig& config);
	virtual void ProcessEvent(IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo);
	virtual void GetMemoryUsage(ICrySizer* s) const;

#if 0
	CFlowNode_SpawnItemArchetype(IFlowNode::SActivationInfo* _arg0_);
#endif

	static inline auto FGetConfiguration = PreyFunction<void(CFlowNode_SpawnItemArchetype* const _this, SFlowNodeConfig& config)>(0x15DB850);
	static inline auto FProcessEvent = PreyFunction<void(CFlowNode_SpawnItemArchetype* const _this, IFlowNode::EFlowEvent event, IFlowNode::SActivationInfo* pActInfo)>(0x15DC2C0);
	static inline auto FGetMemoryUsage = PreyFunction<void(const CFlowNode_SpawnItemArchetype* const _this, ICrySizer* s)>(0x455F00);
};
#endif // MOONCRASH
