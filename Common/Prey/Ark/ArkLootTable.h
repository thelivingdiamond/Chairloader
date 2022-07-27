// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkloottable.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkloottable.h
class ArkLootItem : public ArkReflectedObject // Id=8016A4C Size=32
{
public:
	class ArkArchetypeProperty : public ArkProperty // Id=8016A4D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootItem::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootItem::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkLootItem::ArkArchetypeProperty s_ArkArchetypeProperty;
	CCryName m_Archetype;
	
	class ArkCountMinProperty : public ArkProperty // Id=8016A4E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootItem::ArkCountMinProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootItem::ArkCountMinProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkLootItem::ArkCountMinProperty s_ArkCountMinProperty;
	int m_CountMin;
	
	class ArkCountMaxProperty : public ArkProperty // Id=8016A4F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootItem::ArkCountMaxProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootItem::ArkCountMaxProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkLootItem::ArkCountMaxProperty s_ArkCountMaxProperty;
	int m_CountMax;
	
	class ArkWeightProperty : public ArkProperty // Id=8016A50 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootItem::ArkWeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1360190);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootItem::ArkWeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkLootItem::ArkWeightProperty s_ArkWeightProperty;
	uint8_t m_Weight;
	
	class ArkLootRequirementProperty : public ArkProperty // Id=8016A51 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootItem::ArkLootRequirementProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootItem::ArkLootRequirementProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkLootItem::ArkLootRequirementProperty s_ArkLootRequirementProperty;
	uint64_t m_LootRequirement;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetArchetype(CCryName arg0);
	CCryName const &GetArchetype() const;
	void SetCountMin(int arg0);
	const int &GetCountMin() const;
	void SetCountMax(int arg0);
	const int &GetCountMax() const;
	void SetWeight(uint8_t arg0);
	const uint8_t &GetWeight() const;
	void SetLootRequirement(uint64_t arg0);
	const uint64_t &GetLootRequirement() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1071450);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1071640);
};

// Header: Exact
// Prey/Ark/arkloottable.h
class ArkLootSlot : public ArkReflectedObject // Id=8016A52 Size=32
{
public:
	class ArkPercentProperty : public ArkProperty // Id=8016A53 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootSlot::ArkPercentProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootSlot::ArkPercentProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkLootSlot::ArkPercentProperty s_ArkPercentProperty;
	float m_Percent;
	
	class ArkItemsProperty : public ArkProperty // Id=8016A54 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootSlot::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106F130);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootSlot::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106EDF0);
		static inline auto FIsArray = PreyFunction<bool(ArkLootSlot::ArkItemsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLootSlot::ArkItemsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106EE10);
	};

	static ArkLootSlot::ArkItemsProperty s_ArkItemsProperty;
	std::vector<ArkLootItem> m_Items;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetPercent(float arg0);
	const float &GetPercent() const;
	std::vector<ArkLootItem> &GetItems();
	std::vector<ArkLootItem> const &GetItems() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1071490);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10716E0);
};

// Header: Exact
// Prey/Ark/ArkLootTable.h
class ArkLootTable : public ArkReflectedObject // Id=8016A63 Size=32
{
public:
	class ArkNameProperty : public ArkProperty // Id=8016A64 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootTable::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootTable::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkLootTable::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkSlotsProperty : public ArkProperty // Id=8016A65 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootTable::ArkSlotsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EE90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootTable::ArkSlotsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106EEE0);
		static inline auto FIsArray = PreyFunction<bool(ArkLootTable::ArkSlotsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLootTable::ArkSlotsProperty const *const _this, ArkReflectedObject *_pObject)>(0x106EF00);
	};

	static ArkLootTable::ArkSlotsProperty s_ArkSlotsProperty;
	std::vector<ArkLootSlot> m_Slots;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	std::vector<unsigned int> SpawnItems(unsigned _ownerId) const { return FSpawnItems(this,_ownerId); }
	
#if 0
	void SetName(string arg0);
	string const &GetName() const;
	std::vector<ArkLootSlot> &GetSlots();
	std::vector<ArkLootSlot> const &GetSlots() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10714D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1071780);
	static inline auto FSpawnItems = PreyFunction<std::vector<unsigned int>(ArkLootTable const *const _this, unsigned _ownerId)>(0x1071B10);
};

// Header: Exact
// Prey/Ark/arkloottable.h
class ArkLootTables : public ArkReflectedLibrary // Id=8016A81 Size=32
{
public:
	class ArkTablesProperty : public ArkProperty // Id=8016A82 Size=32
	{
	public:
		ArkTablesProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkLootTables::ArkTablesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EFE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkLootTables::ArkTablesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106F060);
		static inline auto FIsArray = PreyFunction<bool(ArkLootTables::ArkTablesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkLootTables::ArkTablesProperty const *const _this, ArkReflectedObject *_pObject)>(0x106F0A0);
	};

	static ArkLootTables::ArkTablesProperty s_ArkTablesProperty;
	std::vector<ArkLootTable> m_Tables;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkLootTable const *Find(string const &_tableName) const { return FFind(this,_tableName); }
	
#if 0
	std::vector<ArkLootTable> &GetTables();
	std::vector<ArkLootTable> const &GetTables() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1071510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1071820);
	static inline auto FInit = PreyFunction<bool(ArkLootTables *const _this)>(0x1071910);
	static inline auto FFind = PreyFunction<ArkLootTable const *(ArkLootTables const *const _this, string const &_tableName)>(0x1071570);
};

