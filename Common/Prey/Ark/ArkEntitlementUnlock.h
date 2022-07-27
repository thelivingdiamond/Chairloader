// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkentitlementunlock.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkentitlementunlock.h
class ArkEntitlementUnlock_Item : public ArkReflectedObject // Id=8013AFA Size=16
{
public:
	class ArkArchetypeProperty : public ArkProperty // Id=8013AFB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock_Item::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
	};

	static ArkEntitlementUnlock_Item::ArkArchetypeProperty s_ArkArchetypeProperty;
	string m_Archetype;
	
	class ArkQuantityProperty : public ArkProperty // Id=8013AFC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock_Item::ArkQuantityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock_Item::ArkQuantityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkEntitlementUnlock_Item::ArkQuantityProperty s_ArkQuantityProperty;
	int m_Quantity;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetArchetype(string arg0);
	uint64_t GetArchetype() const;
	string const &GetArchetypeString() const;
	void SetQuantity(int arg0);
	const int &GetQuantity() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1064510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10646D0);
};

// Header: Exact
// Prey/Ark/ArkEntitlementUnlock.h
class ArkEntitlementUnlock : public ArkReflectedObject // Id=8013AFD Size=56
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013AFE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkEntitlementUnlock::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013AFF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkEntitlementUnlock::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkEntitlementProperty : public ArkProperty // Id=8013B00 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkEntitlementProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkEntitlementProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkEntitlementUnlock::ArkEntitlementProperty s_ArkEntitlementProperty;
	uint64_t m_Entitlement;
	
	class ArkTutorialProperty : public ArkProperty // Id=8013B01 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkEntitlementUnlock::ArkTutorialProperty s_ArkTutorialProperty;
	uint64_t m_Tutorial;
	
	class ArkItemsProperty : public ArkProperty // Id=8013B02 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1063800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1063860);
		static inline auto FIsArray = PreyFunction<bool(ArkEntitlementUnlock::ArkItemsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEntitlementUnlock::ArkItemsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1063880);
	};

	static ArkEntitlementUnlock::ArkItemsProperty s_ArkItemsProperty;
	std::vector<ArkEntitlementUnlock_Item> m_Items;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetEntitlement(uint64_t arg0);
	const uint64_t &GetEntitlement() const;
	void SetTutorial(uint64_t arg0);
	const uint64_t &GetTutorial() const;
	std::vector<ArkEntitlementUnlock_Item> &GetItems();
	std::vector<ArkEntitlementUnlock_Item> const &GetItems() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1064460);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1064540);
};

// Header: Exact
// Prey/Ark/arkentitlementunlock.h
class ArkEntitlementUnlockLibrary : public ArkReflectedLibrary // Id=8013B1E Size=32
{
public:
	class ArkEntitlementUnlocksProperty : public ArkProperty // Id=8013B1F Size=32
	{
	public:
		ArkEntitlementUnlocksProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1063630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10636D0);
		static inline auto FIsArray = PreyFunction<bool(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this, ArkReflectedObject *_pObject)>(0x1063710);
	};

	static ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty s_ArkEntitlementUnlocksProperty;
	std::vector<ArkEntitlementUnlock> m_EntitlementUnlocks;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkEntitlementUnlockLibrary();
	
#if 0
	std::vector<ArkEntitlementUnlock> &GetEntitlementUnlocks();
	std::vector<ArkEntitlementUnlock> const &GetEntitlementUnlocks() const;
	ArkEntitlementUnlock const *FindByEntitlement(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10644B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10645E0);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementUnlockLibrary *const _this)>(0x1064770);
};

