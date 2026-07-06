// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkStoreItem
// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
class ArkStoreItem : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkStoreItem::ArkIDProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkStoreItem::ArkEntitlementProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkEntitlementProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEntitlementProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkEntitlementProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkStoreItem::ArkNameProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkStoreItem::ArkLabelProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkStoreItem::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkStoreItem::ArkImageProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkImageProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkImageProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkImageProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkImageProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkStoreItem::ArkRarityProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
	class ArkRarityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRarityProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkStoreItem::ArkRarityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreItem::ArkRarityProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkStoreItem::ArkIDProperty>(0x2D55AC0);
	uint64_t m_ID;
	static inline auto s_ArkEntitlementProperty = PreyGlobal<ArkStoreItem::ArkEntitlementProperty>(0x2D55AE0);
	uint64_t m_Entitlement;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkStoreItem::ArkNameProperty>(0x2D55B00);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkStoreItem::ArkLabelProperty>(0x2D55B20);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkStoreItem::ArkDescriptionProperty>(0x2D55B40);
	string m_Description;
	static inline auto s_ArkImageProperty = PreyGlobal<ArkStoreItem::ArkImageProperty>(0x2D55B60);
	string m_Image;
	static inline auto s_ArkRarityProperty = PreyGlobal<ArkStoreItem::ArkRarityProperty>(0x2D55B80);
	int m_Rarity;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetEntitlement(uint64_t _arg0_);
	const uint64_t& GetEntitlement() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetImage(string _arg0_);
	const string& GetImage() const;
	void SetRarity(int _arg0_);
	const int& GetRarity() const;
	ArkStoreItem();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x142DC80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x142DD00);
};

// ArkStoreCatalog
// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
class ArkStoreCatalog : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkStoreCatalog::ArkItemsProperty
	// Header:  Prey/GameDll/ark/ui/store/ArkStoreCatalog.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkStoreCatalog::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkStoreCatalog::ArkItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x142D700);
		static inline auto FIsArray = PreyFunction<bool(const ArkStoreCatalog::ArkItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkStoreCatalog::ArkItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x142D720);
	};

	static inline auto s_ArkItemsProperty = PreyGlobal<ArkStoreCatalog::ArkItemsProperty>(0x2D55BA0);
	std::vector<ArkStoreItem> m_Items;

	static ArkReflectedObject* Create() { return FCreate(); }
	void Reset() { FReset(this); }
	const ArkStoreItem* FindItem(const uint64_t _id) const { return FFindItem(this, _id); }

#if 0
	static ArkClass* GetClass();
	std::vector<ArkStoreItem>& GetItems();
	const std::vector<ArkStoreItem>& GetItems() const;
	void AddItem(ArkStoreItem* _arg0_);
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
	static inline auto FReset = PreyFunction<void(ArkStoreCatalog* const _this)>(0x142DDA0);
	static inline auto FFindItem = PreyFunction<const ArkStoreItem* (const ArkStoreCatalog* const _this, const uint64_t _id)>(0x142DCD0);
};
#endif // MOONCRASH
