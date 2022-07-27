// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/player/IArkPlayerStatusListener.h>
#include <Prey/GameDll/ark/ui/IArkPDAPage.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkAbility;
class ArkClass;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkAbilityRow : public ArkReflectedObject // Id=80193B4 Size=24
{
public:
	class ArkAbilitiesProperty : public ArkProperty // Id=80193B5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FSetValue = PreyFunction<void(ArkAbilityRow::ArkAbilitiesProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x15A4050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkAbilityRow::ArkAbilitiesProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1610DD0);
		static inline auto FIsArray = PreyFunction<bool(ArkAbilityRow::ArkAbilitiesProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbilityRow::ArkAbilitiesProperty const* const _this, ArkReflectedObject* _pObject)>(0x1073510);
	};

	static ArkAbilityRow::ArkAbilitiesProperty s_ArkAbilitiesProperty;
	std::vector<unsigned __int64> m_Abilities;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	std::vector<unsigned __int64>& GetAbilities();
	std::vector<unsigned __int64> const& GetAbilities() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16140D0);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkpdapageabilities.h
class ArkAbilityCategory : public ArkReflectedObject // Id=80193B6 Size=64
{
public:
	class ArkNameProperty : public ArkProperty // Id=80193B7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityCategory::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityCategory::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkAbilityCategory::ArkNameProperty s_ArkNameProperty;
	CCryName m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=80193B8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityCategory::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1067250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityCategory::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkAbilityCategory::ArkLabelProperty s_ArkLabelProperty;
	CCryName m_Label;
	
	class ArkDescriptionProperty : public ArkProperty // Id=80193B9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityCategory::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityCategory::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkAbilityCategory::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkIconProperty : public ArkProperty // Id=80193BA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityCategory::ArkIconProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityCategory::ArkIconProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkAbilityCategory::ArkIconProperty s_ArkIconProperty;
	string m_Icon;
	
	class ArkIsAlienProperty : public ArkProperty // Id=80193BB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityCategory::ArkIsAlienProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13602F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityCategory::ArkIsAlienProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkAbilityCategory::ArkIsAlienProperty s_ArkIsAlienProperty;
	bool m_IsAlien;
	
	class ArkRowsProperty : public ArkProperty // Id=80193BC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityCategory::ArkRowsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1610DF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityCategory::ArkRowsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1610E30);
		static inline auto FIsArray = PreyFunction<bool(ArkAbilityCategory::ArkRowsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbilityCategory::ArkRowsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1610E50);
	};

	static ArkAbilityCategory::ArkRowsProperty s_ArkRowsProperty;
	std::vector<ArkAbilityRow> m_Rows;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	std::vector<unsigned __int64> GetAbilities() const { return FGetAbilities(this); }
	boost::optional<std::pair<int,int> > GetAbilityLocation(uint64_t _abilityId) const { return FGetAbilityLocation(this,_abilityId); }
	
#if 0
	void SetName(CCryName arg0);
	CCryName const &GetName() const;
	void SetLabel(CCryName arg0);
	CCryName const &GetLabel() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetIcon(string arg0);
	string const &GetIcon() const;
	void SetIsAlien(bool arg0);
	const bool &GetIsAlien() const;
	std::vector<ArkAbilityRow> &GetRows();
	std::vector<ArkAbilityRow> const &GetRows() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1614080);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1614350);
	static inline auto FGetAbilities = PreyFunction<std::vector<unsigned __int64>(ArkAbilityCategory const *const _this)>(0x1614100);
	static inline auto FGetAbilityLocation = PreyFunction<boost::optional<std::pair<int,int> >(ArkAbilityCategory const *const _this, uint64_t _abilityId)>(0x1614290);
};

// Header: Exact
// Prey/GameDll/ark/ui/arkpdapageabilities.h
class ArkAbilityPDA : public ArkReflectedObject // Id=80193D8 Size=24
{
public:
	class ArkCategoriesProperty : public ArkProperty // Id=80193D9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityPDA::ArkCategoriesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1610EB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityPDA::ArkCategoriesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1610FE0);
		static inline auto FIsArray = PreyFunction<bool(ArkAbilityPDA::ArkCategoriesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbilityPDA::ArkCategoriesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1611000);
	};

	static ArkAbilityPDA::ArkCategoriesProperty s_ArkCategoriesProperty;
	std::vector<ArkAbilityCategory> m_Categories;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	bool Init() { return FInit(this); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkAbilityCategory> &GetCategories();
	std::vector<ArkAbilityCategory> const &GetCategories() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
	static inline auto FInit = PreyFunction<bool(ArkAbilityPDA *const _this)>(0x16145B0);
};

// Header: FromCpp
// Prey/GameDll/ark/ui/arkpdapageabilities.h
class CArkPDAPageAbilities : public IArkPDAPage, public ArkUIMenuBase<CArkPDAPageAbilities>, public IUIControlSchemeListener, public IArkPlayerStatusListener // Id=80193DD Size=112
{
public:
	ArkAbilityPDA m_layoutDesc;
	ArkAbilityCategory const *m_pCurrentCategory;
	uint64_t m_purchaseAbility;
	uint64_t m_highlightedAbility;
	bool m_bTutorialOpen;
	
	CArkPDAPageAbilities();
	virtual ~CArkPDAPageAbilities();
	void SelectAbility(const uint64_t _abilityId) { FSelectAbility(this,_abilityId); }
	virtual void OnStatusChanged(uint64_t _statusId, bool _bActive);
	virtual void Open();
	virtual void Close();
	virtual bool HasNew() const;
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual bool ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue);
	void OnSelectCategory(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSelectCategory(this,_pSender,_event,_args); }
	void OnSelectAbility(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSelectAbility(this,_pSender,_event,_args); }
	void OnPurchaseAbility(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnPurchaseAbility(this,_pSender,_event,_args); }
	void OnTutorialClose(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnTutorialClose(this,_pSender,_event,_args); }
	void SelectCategory(const char *_categoryName) { FSelectCategory(this,_categoryName); }
	void PurchaseAbility() { FPurchaseAbility(this); }
	void UpdateGrid() const { FUpdateGrid(this); }
	void UpdateDisplayPane(ArkAbility const &_ability) const { FUpdateDisplayPane(this,_ability); }
	void UpdateInputPrompt(const bool _bCanAcquire, const bool _bHasTutorial, const bool _bUpdateUI) const { FUpdateInputPrompt(this,_bCanAcquire,_bHasTutorial,_bUpdateUI); }
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	void UpdateTutorial() const { FUpdateTutorial(this); }
	bool ShouldShowTutorialForHighlightAbility() const { return FShouldShowTutorialForHighlightAbility(this); }
	void PopulateCategoryDetails(ArkAbilityCategory const &_category, bool &_bNew, bool &_bHidden) const { FPopulateCategoryDetails(this,_category,_bNew,_bHidden); }
	
#if 0
	static ArkPDAPage GetPDAPage();
#endif
	
	static inline auto FSelectAbility = PreyFunction<void(CArkPDAPageAbilities *const _this, const uint64_t _abilityId)>(0x16159B0);
	static inline auto FOnStatusChanged = PreyFunction<void(CArkPDAPageAbilities *const _this, uint64_t _statusId, bool _bActive)>(0x16150A0);
	static inline auto FOpen = PreyFunction<void(CArkPDAPageAbilities *const _this)>(0x1615120);
	static inline auto FClose = PreyFunction<void(CArkPDAPageAbilities *const _this)>(0x1613FF0);
	static inline auto FHasNew = PreyFunction<bool(CArkPDAPageAbilities const *const _this)>(0x16143F0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(CArkPDAPageAbilities *const _this, EControlScheme _controlScheme)>(0x1614740);
	static inline auto FProcessInput = PreyFunction<bool(CArkPDAPageAbilities *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0x16155C0);
	static inline auto FOnSelectCategory = PreyFunction<void(CArkPDAPageAbilities *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1615000);
	static inline auto FOnSelectAbility = PreyFunction<void(CArkPDAPageAbilities *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1614D10);
	static inline auto FOnPurchaseAbility = PreyFunction<void(CArkPDAPageAbilities *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1614760);
	static inline auto FOnTutorialClose = PreyFunction<void(CArkPDAPageAbilities *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x1615110);
	static inline auto FSelectCategory = PreyFunction<void(CArkPDAPageAbilities *const _this, const char *_categoryName)>(0x1615D40);
	static inline auto FPurchaseAbility = PreyFunction<void(CArkPDAPageAbilities *const _this)>(0x1615700);
	static inline auto FUpdateGrid = PreyFunction<void(CArkPDAPageAbilities const *const _this)>(0x1616E50);
	static inline auto FUpdateDisplayPane = PreyFunction<void(CArkPDAPageAbilities const *const _this, ArkAbility const &_ability)>(0x16163D0);
	static inline auto FUpdateInputPrompt = PreyFunction<void(CArkPDAPageAbilities const *const _this, const bool _bCanAcquire, const bool _bHasTutorial, const bool _bUpdateUI)>(0x16176D0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(CArkPDAPageAbilities const *const _this)>(0x1B933B0);
	static inline auto FSetupInputPrompts = PreyFunction<void(CArkPDAPageAbilities *const _this)>(0x1616240);
	static inline auto FUpdateTutorial = PreyFunction<void(CArkPDAPageAbilities const *const _this)>(0x16178C0);
	static inline auto FShouldShowTutorialForHighlightAbility = PreyFunction<bool(CArkPDAPageAbilities const *const _this)>(0x1616350);
	static inline auto FPopulateCategoryDetails = PreyFunction<void(CArkPDAPageAbilities const *const _this, ArkAbilityCategory const &_category, bool &_bNew, bool &_bHidden)>(0x1615470);
};

