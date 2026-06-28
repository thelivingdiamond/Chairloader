// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
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
	virtual ~ArkLootTables();
	
#if 0
	std::vector<ArkLootTable> &GetTables();
	std::vector<ArkLootTable> const &GetTables() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1071510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1071820);
	static inline auto FInit = PreyFunction<bool(ArkLootTables *const _this)>(0x1071910);
	static inline auto FFind = PreyFunction<ArkLootTable const *(ArkLootTables const *const _this, string const &_tableName)>(0x1071570);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/iface/IArkItem.h>

class ArkClass;
class IArkValueBase;

// ArkLootItem
// Header:  Prey/Ark/ArkLootTable.h
class ArkLootItem : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkLootItem::ArkArchetypeProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootItem::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootItem::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkLootItem::ArkCountMinProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkCountMinProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCountMinProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootItem::ArkCountMinProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootItem::ArkCountMinProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkLootItem::ArkCountMaxProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkCountMaxProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCountMaxProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootItem::ArkCountMaxProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootItem::ArkCountMaxProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	// ArkLootItem::ArkWeightProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkWeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkWeightProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootItem::ArkWeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x108CF40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootItem::ArkWeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkLootItem::ArkLootRequirementProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkLootRequirementProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLootRequirementProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootItem::ArkLootRequirementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootItem::ArkLootRequirementProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkLootItem::ArkQualityOverrideProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkQualityOverrideProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;

	#if 0
		ArkQualityOverrideProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootItem::ArkQualityOverrideProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10930B0);
	};

	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkLootItem::ArkArchetypeProperty>(0x2D25DB0);
	CCryName m_Archetype;
	static inline auto s_ArkCountMinProperty = PreyGlobal<ArkLootItem::ArkCountMinProperty>(0x2D25DD0);
	int m_CountMin;
	static inline auto s_ArkCountMaxProperty = PreyGlobal<ArkLootItem::ArkCountMaxProperty>(0x2D25DF0);
	int m_CountMax;
	static inline auto s_ArkWeightProperty = PreyGlobal<ArkLootItem::ArkWeightProperty>(0x2D25E10);
	uint8_t m_Weight;
	static inline auto s_ArkLootRequirementProperty = PreyGlobal<ArkLootItem::ArkLootRequirementProperty>(0x2D25E30);
	uint64_t m_LootRequirement;
	static inline auto s_ArkQualityOverrideProperty = PreyGlobal<ArkLootItem::ArkQualityOverrideProperty>(0x2D25E50);
	IArkItem::EArkQualityTier m_QualityOverride;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkLootItem();
	void SetArchetype(CCryName _arg0_);
	const CCryName& GetArchetype() const;
	void SetCountMin(int _arg0_);
	const int& GetCountMin() const;
	void SetCountMax(int _arg0_);
	const int& GetCountMax() const;
	void SetWeight(uint8_t _arg0_);
	const uint8_t& GetWeight() const;
	void SetLootRequirement(uint64_t _arg0_);
	const uint64_t& GetLootRequirement() const;
	void SetQualityOverride(string _arg0_);
	const IArkItem::EArkQualityTier& GetQualityOverride() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1097260);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1097470);
};

// ArkLootSpawn
// Header:  Prey/Ark/ArkLootTable.h
class ArkLootSpawn : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkLootSpawn::ArkIDProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootSpawn::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootSpawn::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkLootSpawn::ArkNameProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootSpawn::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootSpawn::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkLootSpawn::ArkItemsProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkItemsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkItemsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootSpawn::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093270);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootSpawn::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10932F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkLootSpawn::ArkItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLootSpawn::ArkItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x1093310);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkLootSpawn::ArkIDProperty>(0x2D25E70);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkLootSpawn::ArkNameProperty>(0x2D25E90);
	string m_Name;
	static inline auto s_ArkItemsProperty = PreyGlobal<ArkLootSpawn::ArkItemsProperty>(0x2D25EB0);
	std::vector<ArkLootItem> m_Items;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<ArkLootItem>& GetItems();
	const std::vector<ArkLootItem>& GetItems() const;
	bool operator==(uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10972A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10975B0);
};

// ArkLootSpawns
// Header:  Prey/Ark/ArkLootTable.h
class ArkLootSpawns : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkLootSpawns::ArkLootsProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkLootsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLootsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootSpawns::ArkLootsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093100);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootSpawns::ArkLootsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093190);
		static inline auto FIsArray = PreyFunction<bool(const ArkLootSpawns::ArkLootsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLootSpawns::ArkLootsProperty* const _this, ArkReflectedObject* _pObject)>(0x10931D0);
	};

	static inline auto s_ArkLootsProperty = PreyGlobal<ArkLootSpawns::ArkLootsProperty>(0x2D25F70);
	std::vector<ArkLootSpawn> m_Loots;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkLootSpawn* Find(uint64_t _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkLootSpawn>& GetLoots();
	const std::vector<ArkLootSpawn>& GetLoots() const;
	const ArkLootSpawn* FindByName(const char* _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10972E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1097650);
	static inline auto FInit = PreyFunction<bool(ArkLootSpawns* const _this)>(0x1097830);
	static inline auto FFind = PreyFunction<const ArkLootSpawn* (const ArkLootSpawns* const _this, uint64_t _id)>(0x10973E0);
};

// ArkLootSlot
// Header:  Prey/Ark/ArkLootTable.h
class ArkLootSlot : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkLootSlot::ArkSpawnProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkSpawnProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSpawnProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootSlot::ArkSpawnProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootSlot::ArkSpawnProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkLootSlot::ArkPercentProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkPercentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPercentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootSlot::ArkPercentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootSlot::ArkPercentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkSpawnProperty = PreyGlobal<ArkLootSlot::ArkSpawnProperty>(0x2D25ED0);
	uint64_t m_Spawn;
	static inline auto s_ArkPercentProperty = PreyGlobal<ArkLootSlot::ArkPercentProperty>(0x2D25EF0);
	float m_Percent;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetSpawn(uint64_t _arg0_);
	const uint64_t& GetSpawn() const;
	void SetPercent(float _arg0_);
	const float& GetPercent() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109CF20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1097510);
};

// ArkLootTable
// Header:  Prey/Ark/ArkLootTable.h
class ArkLootTable : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkLootTable::ArkIDProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootTable::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootTable::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkLootTable::ArkNameProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootTable::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootTable::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkLootTable::ArkSlotsProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkSlotsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkSlotsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootTable::ArkSlotsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1092FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootTable::ArkSlotsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093000);
		static inline auto FIsArray = PreyFunction<bool(const ArkLootTable::ArkSlotsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLootTable::ArkSlotsProperty* const _this, ArkReflectedObject* _pObject)>(0x1093020);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkLootTable::ArkIDProperty>(0x2D25F10);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkLootTable::ArkNameProperty>(0x2D25F30);
	string m_Name;
	static inline auto s_ArkSlotsProperty = PreyGlobal<ArkLootTable::ArkSlotsProperty>(0x2D25F50);
	std::vector<ArkLootSlot> m_Slots;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkLootTable();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<ArkLootSlot>& GetSlots();
	const std::vector<ArkLootSlot>& GetSlots() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1097340);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10976F0);
};

// ArkLootTables
// Header:  Prey/Ark/ArkLootTable.h
class ArkLootTables : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkLootTables::ArkTablesProperty
	// Header:  Prey/Ark/ArkLootTable.h
	class ArkTablesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkTablesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkLootTables::ArkTablesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093390);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkLootTables::ArkTablesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093420);
		static inline auto FIsArray = PreyFunction<bool(const ArkLootTables::ArkTablesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkLootTables::ArkTablesProperty* const _this, ArkReflectedObject* _pObject)>(0x1093460);
	};

	static inline auto s_ArkTablesProperty = PreyGlobal<ArkLootTables::ArkTablesProperty>(0x2D25F90);
	std::vector<ArkLootTable> m_Tables;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkLootTable* Find(uint64_t _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkLootTable>& GetTables();
	const std::vector<ArkLootTable>& GetTables() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1097380);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1097790);
	static inline auto FInit = PreyFunction<bool(ArkLootTables* const _this)>(0x1097A50);
	static inline auto FFind = PreyFunction<const ArkLootTable* (const ArkLootTables* const _this, uint64_t _id)>(0x10973E0);
};
#endif // !MOONCRASH
