// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkentitlementunlock.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
#endif
class ArkEntitlementUnlock_Item : public ArkReflectedObject // Id=8013AFA Size=16
{
public:
	class ArkArchetypeProperty : public ArkProperty // Id=8013AFB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock_Item::ArkArchetypeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock_Item::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock_Item::ArkArchetypeProperty s_ArkArchetypeProperty;
#else
	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkEntitlementUnlock_Item::ArkArchetypeProperty>(0x2D23680);
#endif
	string m_Archetype;
	
	class ArkQuantityProperty : public ArkProperty // Id=8013AFC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock_Item::ArkQuantityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock_Item::ArkQuantityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock_Item::ArkQuantityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlock_Item::ArkQuantityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock_Item::ArkQuantityProperty s_ArkQuantityProperty;
#else
	static inline auto s_ArkQuantityProperty = PreyGlobal<ArkEntitlementUnlock_Item::ArkQuantityProperty>(0x2D236A0);
#endif
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
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1064510);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10646D0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1087430);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10875F0);
#endif
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
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlock::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkEntitlementUnlock::ArkIDProperty>(0x2D236C0);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013AFF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlock::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEntitlementUnlock::ArkNameProperty>(0x2D236E0);
#endif
	string m_Name;
	
	class ArkEntitlementProperty : public ArkProperty // Id=8013B00 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkEntitlementProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkEntitlementProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlock::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock::ArkEntitlementProperty s_ArkEntitlementProperty;
#else
	static inline auto s_ArkEntitlementProperty = PreyGlobal<ArkEntitlementUnlock::ArkEntitlementProperty>(0x2D23700);
#endif
	uint64_t m_Entitlement;
	
	class ArkTutorialProperty : public ArkProperty // Id=8013B01 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkTutorialProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlock::ArkTutorialProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock::ArkTutorialProperty s_ArkTutorialProperty;
#else
	static inline auto s_ArkTutorialProperty = PreyGlobal<ArkEntitlementUnlock::ArkTutorialProperty>(0x2D23720);
#endif
	uint64_t m_Tutorial;
	
	class ArkItemsProperty : public ArkProperty // Id=8013B02 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlock::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1063800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlock::ArkItemsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1063860);
		static inline auto FIsArray = PreyFunction<bool(ArkEntitlementUnlock::ArkItemsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEntitlementUnlock::ArkItemsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1063880);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlock::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlock::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x10865C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEntitlementUnlock::ArkItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEntitlementUnlock::ArkItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x10865E0);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlock::ArkItemsProperty s_ArkItemsProperty;
#else
	static inline auto s_ArkItemsProperty = PreyGlobal<ArkEntitlementUnlock::ArkItemsProperty>(0x2D23740);
#endif
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
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1064460);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1064540);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1087380);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1087460);
#endif
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
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1063630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10636D0);
		static inline auto FIsArray = PreyFunction<bool(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty const *const _this, ArkReflectedObject *_pObject)>(0x1063710);
#else
		static inline auto FArkEntitlementUnlocksPropertyOv2 = PreyFunction<void(ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty* const _this)>(0x1087070);
		static inline auto FSetValue = PreyFunction<void(const ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086650);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty* const _this, ArkReflectedObject* const _pObject)>(0x10866F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty* const _this, ArkReflectedObject* _pObject)>(0x1086730);
#endif
	};

#ifndef MOONCRASH
	static ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty s_ArkEntitlementUnlocksProperty;
#else
	static inline auto s_ArkEntitlementUnlocksProperty = PreyGlobal<ArkEntitlementUnlockLibrary::ArkEntitlementUnlocksProperty>(0x2D23760);
#endif
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
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10644B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10645E0);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementUnlockLibrary *const _this)>(0x1064770);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10873D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1087500);
	static inline auto FInit = PreyFunction<bool(ArkEntitlementUnlockLibrary* const _this)>(0x1087690);
#endif
};
