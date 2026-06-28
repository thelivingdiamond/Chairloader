// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkChecklistCategory
// Header:  Prey/Ark/ArkChecklist.h
class ArkChecklistCategory : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkChecklistCategory::ArkIDProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistCategory::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistCategory::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkChecklistCategory::ArkNameProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistCategory::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistCategory::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkChecklistCategory::ArkLabelProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistCategory::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistCategory::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkChecklistCategory::ArkIDProperty>(0x2D22800);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkChecklistCategory::ArkNameProperty>(0x2D22820);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkChecklistCategory::ArkLabelProperty>(0x2D22840);
	string m_Label;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkChecklistCategory();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x108AE00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10818F0);
};

// ArkChecklistEntry
// Header:  Prey/Ark/ArkChecklist.h
class ArkChecklistEntry : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkChecklistEntry::ArkIDProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkChecklistEntry::ArkNameProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkChecklistEntry::ArkLabelProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkChecklistEntry::ArkCryptoProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkCryptoProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCryptoProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkCryptoProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkCryptoProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkChecklistEntry::ArkSuppressNotificationProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkSuppressNotificationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSuppressNotificationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkSuppressNotificationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080C80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkSuppressNotificationProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkChecklistEntry::ArkStartsDisabledProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkStartsDisabledProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartsDisabledProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkStartsDisabledProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkStartsDisabledProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CA0);
	};

	// ArkChecklistEntry::ArkCategoryProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkCategoryProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCategoryProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkCategoryProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1077BD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkCategoryProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkChecklistEntry::ArkGameMetricProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkGameMetricProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGameMetricProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkGameMetricProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B7770);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkGameMetricProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkChecklistEntry::ArkMetricTotalProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkMetricTotalProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMetricTotalProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklistEntry::ArkMetricTotalProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklistEntry::ArkMetricTotalProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkChecklistEntry::ArkIDProperty>(0x2D22860);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkChecklistEntry::ArkNameProperty>(0x2D22880);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkChecklistEntry::ArkLabelProperty>(0x2D228A0);
	string m_Label;
	static inline auto s_ArkCryptoProperty = PreyGlobal<ArkChecklistEntry::ArkCryptoProperty>(0x2D228C0);
	float m_Crypto;
	static inline auto s_ArkSuppressNotificationProperty = PreyGlobal<ArkChecklistEntry::ArkSuppressNotificationProperty>(0x2D228E0);
	bool m_SuppressNotification;
	static inline auto s_ArkStartsDisabledProperty = PreyGlobal<ArkChecklistEntry::ArkStartsDisabledProperty>(0x2D22900);
	bool m_StartsDisabled;
	static inline auto s_ArkCategoryProperty = PreyGlobal<ArkChecklistEntry::ArkCategoryProperty>(0x2D22920);
	uint64_t m_Category;
	static inline auto s_ArkGameMetricProperty = PreyGlobal<ArkChecklistEntry::ArkGameMetricProperty>(0x2D22940);
	uint64_t m_GameMetric;
	static inline auto s_ArkMetricTotalProperty = PreyGlobal<ArkChecklistEntry::ArkMetricTotalProperty>(0x2D22960);
	int m_MetricTotal;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkChecklistEntry();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetCrypto(float _arg0_);
	const float& GetCrypto() const;
	void SetSuppressNotification(bool _arg0_);
	const bool& GetSuppressNotification() const;
	void SetStartsDisabled(bool _arg0_);
	const bool& GetStartsDisabled() const;
	void SetCategory(uint64_t _arg0_);
	const uint64_t& GetCategory() const;
	void SetGameMetric(uint64_t _arg0_);
	const uint64_t& GetGameMetric() const;
	void SetMetricTotal(int _arg0_);
	const int& GetMetricTotal() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1081780);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1081990);
};

// ArkChecklist
// Header:  Prey/Ark/ArkChecklist.h
class ArkChecklist : public ArkReflectedLibrary
{ // Size=56 (0x38)
public:
	// ArkChecklist::ArkEntriesProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkEntriesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkEntriesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklist::ArkEntriesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080CD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklist::ArkEntriesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080DB0);
		static inline auto FIsArray = PreyFunction<bool(const ArkChecklist::ArkEntriesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChecklist::ArkEntriesProperty* const _this, ArkReflectedObject* _pObject)>(0x1080DF0);
	};

	// ArkChecklist::ArkCategoriesProperty
	// Header:  Prey/Ark/ArkChecklist.h
	class ArkCategoriesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkCategoriesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChecklist::ArkCategoriesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1080B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChecklist::ArkCategoriesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080C00);
		static inline auto FIsArray = PreyFunction<bool(const ArkChecklist::ArkCategoriesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChecklist::ArkCategoriesProperty* const _this, ArkReflectedObject* _pObject)>(0x1080C40);
	};

	static inline auto s_ArkEntriesProperty = PreyGlobal<ArkChecklist::ArkEntriesProperty>(0x2D22980);
	std::vector<ArkChecklistEntry> m_Entries;
	static inline auto s_ArkCategoriesProperty = PreyGlobal<ArkChecklist::ArkCategoriesProperty>(0x2D229A0);
	std::vector<ArkChecklistCategory> m_Categories;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkChecklistEntry* Find(const uint64_t _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkChecklistEntry>& GetEntries();
	const std::vector<ArkChecklistEntry>& GetEntries() const;
	std::vector<ArkChecklistCategory>& GetCategories();
	const std::vector<ArkChecklistCategory>& GetCategories() const;
	const ArkChecklistCategory* FindCategory(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1081720);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1081800);
	static inline auto FInit = PreyFunction<bool(ArkChecklist* const _this)>(0x1081A30);
	static inline auto FFind = PreyFunction<const ArkChecklistEntry* (const ArkChecklist* const _this, const uint64_t _id)>(0x10817D0);
};
#endif // MOONCRASH
