// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ui/ArkPDAPageAbilities.h>

class ArkClass;
class IArkValueBase;

// ArkAbilityCategory
// Header:  Prey/Ark/ArkAbilityLayout.h
class ArkAbilityCategory : public ArkReflectedObject
{ // Size=64 (0x40)
public:
	// ArkAbilityCategory::ArkNameProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkAbilityCategory::ArkLabelProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkAbilityCategory::ArkDescriptionProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkAbilityCategory::ArkIconProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkAbilityCategory::ArkIsAlienProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkIsAlienProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsAlienProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkIsAlienProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkIsAlienProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkAbilityCategory::ArkIsPetsProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkIsPetsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIsPetsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkIsPetsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1075BE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkIsPetsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1075BF0);
	};

	// ArkAbilityCategory::ArkRowsProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkRowsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkRowsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityCategory::ArkRowsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1075C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityCategory::ArkRowsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1075C40);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbilityCategory::ArkRowsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbilityCategory::ArkRowsProperty* const _this, ArkReflectedObject* _pObject)>(0x1075C60);
	};

	static inline auto s_ArkNameProperty = PreyGlobal<ArkAbilityCategory::ArkNameProperty>(0x2D21190);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkAbilityCategory::ArkLabelProperty>(0x2D211B0);
	string m_Label;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkAbilityCategory::ArkDescriptionProperty>(0x2D211D0);
	string m_Description;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkAbilityCategory::ArkIconProperty>(0x2D21210);
	string m_Icon;
	static inline auto s_ArkIsAlienProperty = PreyGlobal<ArkAbilityCategory::ArkIsAlienProperty>(0x2D21230);
	bool m_IsAlien;
	static inline auto s_ArkIsPetsProperty = PreyGlobal<ArkAbilityCategory::ArkIsPetsProperty>(0x2D21250);
	bool m_IsPets;
	static inline auto s_ArkRowsProperty = PreyGlobal<ArkAbilityCategory::ArkRowsProperty>(0x2D211F0);
	std::vector<ArkAbilityRow> m_Rows;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	std::vector<uint64_t> GetAbilities() const { alignas(std::vector<uint64_t>) std::byte _return_buf_[sizeof(std::vector<uint64_t>)]; return *FGetAbilities(this, reinterpret_cast<std::vector<uint64_t>*>(_return_buf_)); }
	boost::optional<std::pair<int,int> > GetAbilityLocation(uint64_t _abilityId) const { alignas(boost::optional<std::pair<int,int> >) std::byte _return_buf_[sizeof(boost::optional<std::pair<int,int> >)]; return *FGetAbilityLocation(this, reinterpret_cast<boost::optional<std::pair<int,int> >*>(_return_buf_), _abilityId); }

#if 0
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetIcon(string _arg0_);
	const string& GetIcon() const;
	void SetIsAlien(bool _arg0_);
	const bool& GetIsAlien() const;
	void SetIsPets(bool _arg0_);
	const bool& GetIsPets() const;
	std::vector<ArkAbilityRow>& GetRows();
	const std::vector<ArkAbilityRow>& GetRows() const;
	ArkAbilityCategory();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10770B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10772D0);
	static inline auto FGetAbilities = PreyFunction<std::vector<uint64_t>*(const ArkAbilityCategory* const _this, std::vector<uint64_t>* _return_value_)>(0x1077190);
	static inline auto FGetAbilityLocation = PreyFunction<boost::optional<std::pair<int,int> >*(const ArkAbilityCategory* const _this, boost::optional<std::pair<int,int> >* _return_value_, uint64_t _abilityId)>(0x1077210);
};

// ArkAbilityLayout
// Header:  Prey/Ark/ArkAbilityLayout.h
class ArkAbilityLayout : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkAbilityLayout::ArkIDProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityLayout::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityLayout::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkAbilityLayout::ArkNameProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityLayout::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityLayout::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkAbilityLayout::ArkCategoriesProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
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

		static inline auto FSetValue = PreyFunction<void(const ArkAbilityLayout::ArkCategoriesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1075880);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityLayout::ArkCategoriesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10759B0);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbilityLayout::ArkCategoriesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbilityLayout::ArkCategoriesProperty* const _this, ArkReflectedObject* _pObject)>(0x10759D0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkAbilityLayout::ArkIDProperty>(0x2D21270);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkAbilityLayout::ArkNameProperty>(0x2D21290);
	string m_Name;
	static inline auto s_ArkCategoriesProperty = PreyGlobal<ArkAbilityLayout::ArkCategoriesProperty>(0x2D212B0);
	std::vector<ArkAbilityCategory> m_Categories;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	std::vector<ArkAbilityCategory>& GetCategories();
	const std::vector<ArkAbilityCategory>& GetCategories() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10972A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1077370);
};

// ArkAbilityLayoutLibrary
// Header:  Prey/Ark/ArkAbilityLayout.h
class ArkAbilityLayoutLibrary : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkAbilityLayoutLibrary::ArkLayoutsProperty
	// Header:  Prey/Ark/ArkAbilityLayout.h
	class ArkLayoutsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkLayoutsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkLayoutsPropertyOv2 = PreyFunction<void(ArkAbilityLayoutLibrary::ArkLayoutsProperty* const _this)>(0x1076D00);
		static inline auto FSetValue = PreyFunction<void(const ArkAbilityLayoutLibrary::ArkLayoutsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1075A80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkAbilityLayoutLibrary::ArkLayoutsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1075B10);
		static inline auto FIsArray = PreyFunction<bool(const ArkAbilityLayoutLibrary::ArkLayoutsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkAbilityLayoutLibrary::ArkLayoutsProperty* const _this, ArkReflectedObject* _pObject)>(0x1075B50);
	};

	static inline auto s_ArkLayoutsProperty = PreyGlobal<ArkAbilityLayoutLibrary::ArkLayoutsProperty>(0x2D212D0);
	std::vector<ArkAbilityLayout> m_Layouts;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	const ArkAbilityLayout* Find(const uint64_t _id) const { return FFind(this, _id); }
	virtual bool Init();

#if 0
	std::vector<ArkAbilityLayout>& GetLayouts();
	const std::vector<ArkAbilityLayout>& GetLayouts() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077100);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1077410);
	static inline auto FFind = PreyFunction<const ArkAbilityLayout* (const ArkAbilityLayoutLibrary* const _this, const uint64_t _id)>(0x10AABE0);
	static inline auto FInit = PreyFunction<bool(ArkAbilityLayoutLibrary* const _this)>(0x1077500);
};
#endif // MOONCRASH
