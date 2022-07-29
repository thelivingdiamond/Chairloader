// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ui/ArkInputLegendHandler.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>

class ArkFocusModeComponentProperties;
class ArkFocusModeMenuPower;
class ArkFocusModeMenuWeapon;
struct IUIElement;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkFocusModeUIComponent.h
class ArkFocusModeUIComponent : public ArkUIMenuBase<ArkFocusModeUIComponent>, public IUIControlSchemeListener // Id=8017261 Size=168
{
public:
	enum class ArkMenuAction
	{
		SelectItem = 0,
		SelectPower = 1,
		UsePsiHypo = 2,
		UseMedKit = 3,
		UseFood = 4,
		UseSuitKit = 5,
	};

	enum class ArkActiveControllerStick
	{
		None = 0,
		Left = 1,
		Right = 2,
	};

	enum class EArkConsumeResult
	{
		empty = 0,
		fail = 1,
		success = 2,
	};

	std::vector<ArkFocusModeMenuPower> m_menuPowers;
	std::vector<ArkFocusModeMenuWeapon> m_menuWeapons;
	ArkInputLegendHandler m_powerInputLegendHandler;
	ArkInputLegendHandler m_weaponInputLegendHandler;
	unsigned m_emptyLegendHandle;
	Vec2 m_menuInputVec;
	Vec2 m_prevMenuInputVec;
	float m_currentMenuAngle;
	float m_desiredMenuAngle;
	float m_menuAngularSpeed;
	ArkFocusModeComponentProperties const &m_properties;
	ArkFocusModeUIComponent::ArkActiveControllerStick m_activeControllerStick;
	int m_selectedItemIndex;
	bool m_bVisible;
	std::vector<unsigned __int64> m_foodArchetypes;
	
	ArkFocusModeUIComponent();
	virtual ~ArkFocusModeUIComponent();
	void Show() { FShow(this); }
	void Hide() { FHide(this); }
	void Close() { FClose(this); }
	void Update() { FUpdate(this); }
	unsigned GetSelectedWeapon() const { return FGetSelectedWeapon(this); }
	EArkPsiPowers GetSelectedPower() const { return FGetSelectedPower(this); }
	void SelectMenuItem(const float _angleRad) { FSelectMenuItemOv1(this,_angleRad); }
	void ProcessInput(CCryName _actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	static bool ConsumePsiHypo() { return FConsumePsiHypo(); }
	bool InitializeMenu() { return FInitializeMenu(this); }
	void UpdateResourcePrompts() const { FUpdateResourcePrompts(this); }
	void ShowActionSucceeded(ArkFocusModeUIComponent::ArkMenuAction const &_action) const { FShowActionSucceeded(this,_action); }
	void ShowItemDetails(ArkFocusModeMenuPower const &_menuItem) { FShowItemDetailsOv1(this,_menuItem); }
	void ShowItemDetails(ArkFocusModeMenuWeapon const &_menuItem) { FShowItemDetailsOv0(this,_menuItem); }
	void OnSelectMenuItem(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args) { FOnSelectMenuItem(this,_pSender,_event,_args); }
	static ArkFocusModeUIComponent::EArkConsumeResult ConsumeItem(const uint64_t _archetypeId) { return FConsumeItem(_archetypeId); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	
#if 0
	bool IsVisible() const;
	void SelectMenuItem(const int arg0);
	void PopulateFoods();
	int GetMenuItemCount() const;
#endif
	
	static inline auto FBitNotArkFocusModeUIComponent = PreyFunction<void(ArkFocusModeUIComponent *const _this)>(0x1353C10);
	static inline auto FShow = PreyFunction<void(ArkFocusModeUIComponent *const _this)>(0x13564B0);
	static inline auto FHide = PreyFunction<void(ArkFocusModeUIComponent *const _this)>(0x1354710);
	static inline auto FClose = PreyFunction<void(ArkFocusModeUIComponent *const _this)>(0x1354220);
	static inline auto FUpdate = PreyFunction<void(ArkFocusModeUIComponent *const _this)>(0x13570F0);
	static inline auto FGetSelectedWeapon = PreyFunction<unsigned(ArkFocusModeUIComponent const *const _this)>(0x1354650);
	static inline auto FGetSelectedPower = PreyFunction<EArkPsiPowers(ArkFocusModeUIComponent const *const _this)>(0x1354620);
	static inline auto FSelectMenuItemOv1 = PreyFunction<void(ArkFocusModeUIComponent *const _this, const float _angleRad)>(0x1356350);
	static inline auto FProcessInput = PreyFunction<void(ArkFocusModeUIComponent *const _this, CCryName _actionId, const int _activationMode, const float _value)>(0x1355B80);
	static inline auto FConsumePsiHypo = PreyFunction<bool()>(0x1354500);
	static inline auto FInitializeMenu = PreyFunction<bool(ArkFocusModeUIComponent *const _this)>(0x1354980);
	static inline auto FUpdateResourcePrompts = PreyFunction<void(ArkFocusModeUIComponent const *const _this)>(0x1357630);
	static inline auto FShowActionSucceeded = PreyFunction<void(ArkFocusModeUIComponent const *const _this, ArkFocusModeUIComponent::ArkMenuAction const &_action)>(0x1356800);
	static inline auto FShowItemDetailsOv1 = PreyFunction<void(ArkFocusModeUIComponent *const _this, ArkFocusModeMenuPower const &_menuItem)>(0x13569F0);
	static inline auto FShowItemDetailsOv0 = PreyFunction<void(ArkFocusModeUIComponent *const _this, ArkFocusModeMenuWeapon const &_menuItem)>(0x1356BD0);
	static inline auto FOnSelectMenuItem = PreyFunction<void(ArkFocusModeUIComponent *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13559A0);
	static inline auto FConsumeItem = PreyFunction<ArkFocusModeUIComponent::EArkConsumeResult(const uint64_t _archetypeId)>(0x13543C0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkFocusModeUIComponent *const _this, EControlScheme _controlScheme)>(0x1355980);
};

