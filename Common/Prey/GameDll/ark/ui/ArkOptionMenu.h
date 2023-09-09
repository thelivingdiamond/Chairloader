// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryInput/IInput.h>
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/ui/ArkOptionLayout.h>
#include <Prey/GameDll/ark/ui/ArkOptionMenuBase.h>

class ArkOptionAttribute;
class ArkOptionDropDownBase;
class ArkOptionLayoutPage;
class ArkOptionLayoutSubPage;
class ArkOptionSlider;
class ArkUIOptionMenuBase;
struct IUIElement;
struct SInputEvent;

// Header: Exact
// Prey/GameDll/ark/ui/ArkOptionMenu.h
class ArkOptionMenu : public ArkOptionMenuBase, public IInputEventListener // Id=801B94A Size=328
{
public:
	enum class EMode
	{
		main = 0,
		dropdown = 1,
		brightness = 2,
		keybinds = 3,
		controlMap = 4,
		closing = 5,
	};

	enum class EPostApplyAction
	{
		none = 0,
		back = 1,
		page = 2,
		subPage = 3,
	};

	struct RingBuffer // Id=801B9B0 Size=68
	{
		std::array<int,16> m_buffer;
		unsigned m_currentIndex;
		
#if 0
		void Add(int arg0);
		bool IsFull() const;
		float GetAverage() const;
		void Reset();
#endif
	};

	ArkOptionLayout m_optionLayout;
	std::vector<std::pair<string,string>> m_resetCommands;
	std::vector<unsigned int> m_dirtyAttributes;
	ArkOptionMenu::RingBuffer m_precacheCountBuffer;
	ArkOptionLayoutPage const *m_pCurrentPage;
	ArkOptionLayoutSubPage const *m_pCurrentSubPage;
	int m_nWaitForRefreshFrames;
	bool m_bRequiresConfirmation;
	bool m_bIgnoreKeybindInput;
	bool m_bProcessPostApplyAction;
	bool m_bWaitForTextureReload;
	unsigned m_nKeybindWaitFrames;
	ArkOptionMenu::EMode m_mode;
	ArkOptionMenu::EPostApplyAction m_postApplyAction;
	string m_postApplyPageId;
	ArkSimpleTimer m_waitingForTextures;
	int m_keybindAttribute;
	int m_dropdownAttribute;
	int m_dropdownHighlight;
	
	ArkOptionMenu(ArkUIOptionMenuBase *_pOptionMenu);
	virtual ~ArkOptionMenu();
	virtual void LoadOptionProfile(const char *_filename, bool );
	virtual void Init();
	virtual bool Update();
	virtual void Reset();
	virtual bool OnInputEvent(SInputEvent const &_event);
	virtual string GetSubPageLabel() const;
	virtual void SelectPage(string const &_pageId);
	void SelectPage(ArkOptionLayoutPage const &_page) { FSelectPageOv0(this,_page); }
	virtual void SelectSubPage(string const &_pageId);
	void SelectSubPage(ArkOptionLayoutSubPage const &_subPage) { FSelectSubPageOv0(this,_subPage); }
	virtual void SelectNextPage();
	virtual void SelectPrevPage();
	virtual void SelectNextSubPage();
	virtual void SelectPrevSubPage();
	virtual void SetCurrentAttribute(unsigned _attribute);
	virtual void SelectNextAttribute();
	virtual void SelectPrevAttribute();
	virtual void SelectNextOption(const int _attributeIndex);
	virtual void SelectPrevOption(const int _attributeIndex);
	virtual void SetOptionValue(int _attributeIndex, float _value);
	virtual bool SetAttribute(unsigned _attributeIndex);
	virtual bool CanResetDefaults();
	virtual void ResetDefaults();
	virtual void ApplyDirtyAttributes();
	virtual void ClearDirtyAttributes();
	virtual void ProcessPostApplyAction();
	void SavePlayerProfile() { FSavePlayerProfile(this); }
	void LoadPlayerProfile() { FLoadPlayerProfile(this); }
	virtual void OnPressBack();
	virtual void OnPressButton(string const &_buttonId);
	virtual void OnDropDownOpen(int _attributeIndex);
	virtual void OnDropDownItemSelected(int _attributeIndex, int _selectedItem);
	virtual bool IsActive();
	virtual bool IsClosing();
	virtual bool IsDropDownOpen();
	virtual bool IsControlMapOpen();
	void OnBrightnessMenuClose() { FOnBrightnessMenuClose(this); }
	void UpdateKeybindAttribute(unsigned _attrIdx, const char *_actionMap, CCryName _actionId) { FUpdateKeybindAttribute(this,_attrIdx,_actionMap,_actionId); }
	int GetCurrentDisplayIndex() const { return FGetCurrentDisplayIndex(this); }
	virtual std::pair<char const *,char const *> GetPageAndSubPageLabels() const;
	virtual void WriteGameCfg();
	void ModifySliderValue(const int _attributeIndex, ArkOptionAttribute const &_attribute, const int _dir) { FModifySliderValue(this,_attributeIndex,_attribute,_dir); }
	void UpdateSliderValue(ArkOptionSlider const &_slider, string const &_action, const int _attributeIndex, const float _value, const bool _bRunCommand) { FUpdateSliderValue(this,_slider,_action,_attributeIndex,_value,_bRunCommand); }
	void SetSelectedOption(const int _attributeIdx, const int _optionIdx, const bool _bRunCommand) { FSetSelectedOption(this,_attributeIdx,_optionIdx,_bRunCommand); }
	void OnConfirmChanges() { FOnConfirmChanges(this); }
	void OnCancelChanges() { FOnCancelChanges(this); }
	virtual void UpdateInputPrompts();
	void RebindKeybindAttribute(ArkOptionAttribute const &_attribute, const char *const _newInput) { FRebindKeybindAttribute(this,_attribute,_newInput); }
	void UpdateDropdownOption(ArkOptionDropDownBase const &_widget, IUIElement *const _pUIElement, const unsigned _attrIndex, const unsigned _optionIndex) { FUpdateDropdownOption(this,_widget,_pUIElement,_attrIndex,_optionIndex); }
	void MarkAttributeDirty(unsigned _attributeIndex) { FMarkAttributeDirty(this,_attributeIndex); }
	
#if 0
	ArkOptionLayoutPage const *FindPage(string const &arg0) const;
	ArkOptionLayoutSubPage const *FindSubPage(string const &arg0) const;
	void QueueAttributeCommand(ArkOptionAttribute const &arg0, const int arg1);
	void QueueSubActions(std::vector<ArkOptionSubAction> const &arg0);
	void CloseDropDownMenu();
	void OpenBrightnessMenu();
	void OpenControlMap();
	void CloseControlMap();
	bool CanLeavePage();
	static EArkOptionPlatform GetPlatform();
	unsigned GetNumAvailableSubPages(ArkOptionLayoutPage const &arg0) const;
	void RefreshResolutionsForMonitorSwitch(const int arg0, const int arg1);
#endif
	
	static inline auto FLoadOptionProfile = PreyFunction<void(ArkOptionMenu *const _this, const char *_filename, bool )>(0x1368530);
	static inline auto FInit = PreyFunction<void(ArkOptionMenu *const _this)>(0x13682D0);
	static inline auto FUpdate = PreyFunction<bool(ArkOptionMenu *const _this)>(0x136BEB0);
	static inline auto FReset = PreyFunction<void(ArkOptionMenu *const _this)>(0x13697B0);
	static inline auto FOnInputEvent = PreyFunction<bool(ArkOptionMenu *const _this, SInputEvent const &_event)>(0x1368E80);
	static inline auto FGetSubPageLabel = PreyFunction<string(ArkOptionMenu const *const _this)>(0x1368280);
	static inline auto FSelectPageOv1 = PreyFunction<void(ArkOptionMenu *const _this, string const &_pageId)>(0x136A270);
	static inline auto FSelectPageOv0 = PreyFunction<void(ArkOptionMenu *const _this, ArkOptionLayoutPage const &_page)>(0x1369FD0);
	static inline auto FSelectSubPageOv1 = PreyFunction<void(ArkOptionMenu *const _this, string const &_pageId)>(0x136AFE0);
	static inline auto FSelectSubPageOv0 = PreyFunction<void(ArkOptionMenu *const _this, ArkOptionLayoutSubPage const &_subPage)>(0x136A6C0);
	static inline auto FSelectNextPage = PreyFunction<void(ArkOptionMenu *const _this)>(0x1369F20);
	static inline auto FSelectPrevPage = PreyFunction<void(ArkOptionMenu *const _this)>(0x136A5E0);
	static inline auto FSelectNextSubPage = PreyFunction<void(ArkOptionMenu *const _this)>(0x1369F70);
	static inline auto FSelectPrevSubPage = PreyFunction<void(ArkOptionMenu *const _this)>(0x136A650);
	static inline auto FSetCurrentAttribute = PreyFunction<void(ArkOptionMenu *const _this, unsigned _attribute)>(0x136B560);
	static inline auto FSelectNextAttribute = PreyFunction<void(ArkOptionMenu *const _this)>(0x1369C50);
	static inline auto FSelectPrevAttribute = PreyFunction<void(ArkOptionMenu *const _this)>(0x136A2E0);
	static inline auto FSelectNextOption = PreyFunction<void(ArkOptionMenu *const _this, const int _attributeIndex)>(0x1369D30);
	static inline auto FSelectPrevOption = PreyFunction<void(ArkOptionMenu *const _this, const int _attributeIndex)>(0x136A3C0);
	static inline auto FSetOptionValue = PreyFunction<void(ArkOptionMenu *const _this, int _attributeIndex, float _value)>(0x136B6C0);
	static inline auto FSetAttribute = PreyFunction<bool(ArkOptionMenu *const _this, unsigned _attributeIndex)>(0x136B090);
	static inline auto FCanResetDefaults = PreyFunction<bool(ArkOptionMenu *const _this)>(0x1368050);
	static inline auto FResetDefaults = PreyFunction<void(ArkOptionMenu *const _this)>(0x13697E0);
	static inline auto FApplyDirtyAttributes = PreyFunction<void(ArkOptionMenu *const _this)>(0x1367F50);
	static inline auto FClearDirtyAttributes = PreyFunction<void(ArkOptionMenu *const _this)>(0x1368120);
	static inline auto FProcessPostApplyAction = PreyFunction<void(ArkOptionMenu *const _this)>(0x1369640);
	static inline auto FSavePlayerProfile = PreyFunction<void(ArkOptionMenu *const _this)>(0x1369B40);
	static inline auto FLoadPlayerProfile = PreyFunction<void(ArkOptionMenu *const _this)>(0x1368620);
	static inline auto FOnPressBack = PreyFunction<void(ArkOptionMenu *const _this)>(0x13694B0);
	static inline auto FOnPressButton = PreyFunction<void(ArkOptionMenu *const _this, string const &_buttonId)>(0x13695C0);
	static inline auto FOnDropDownOpen = PreyFunction<void(ArkOptionMenu *const _this, int _attributeIndex)>(0x1368C90);
	static inline auto FOnDropDownItemSelected = PreyFunction<void(ArkOptionMenu *const _this, int _attributeIndex, int _selectedItem)>(0x13689E0);
	static inline auto FIsActive = PreyFunction<bool(ArkOptionMenu *const _this)>(0x13684E0);
	static inline auto FIsClosing = PreyFunction<bool(ArkOptionMenu *const _this)>(0x1368500);
	static inline auto FIsDropDownOpen = PreyFunction<bool(ArkOptionMenu *const _this)>(0x1368520);
	static inline auto FIsControlMapOpen = PreyFunction<bool(ArkOptionMenu *const _this)>(0x1368510);
	static inline auto FOnBrightnessMenuClose = PreyFunction<void(ArkOptionMenu *const _this)>(0x13688A0);
	static inline auto FUpdateKeybindAttribute = PreyFunction<void(ArkOptionMenu *const _this, unsigned _attrIdx, const char *_actionMap, CCryName _actionId)>(0x136CBF0);
	static inline auto FGetCurrentDisplayIndex = PreyFunction<int(ArkOptionMenu const *const _this)>(0x1368130);
	static inline auto FGetPageAndSubPageLabels = PreyFunction<std::pair<char const *,char const *>(ArkOptionMenu const *const _this)>(0x13681F0);
	static inline auto FWriteGameCfg = PreyFunction<void(ArkOptionMenu *const _this)>(0x136CFB0);
	static inline auto FModifySliderValue = PreyFunction<void(ArkOptionMenu *const _this, const int _attributeIndex, ArkOptionAttribute const &_attribute, const int _dir)>(0x13687D0);
	static inline auto FUpdateSliderValue = PreyFunction<void(ArkOptionMenu *const _this, ArkOptionSlider const &_slider, string const &_action, const int _attributeIndex, const float _value, const bool _bRunCommand)>(0x136CEC0);
	static inline auto FSetSelectedOption = PreyFunction<void(ArkOptionMenu *const _this, const int _attributeIdx, const int _optionIdx, const bool _bRunCommand)>(0x136B7A0);
	static inline auto FOnConfirmChanges = PreyFunction<void(ArkOptionMenu *const _this)>(0x1368990);
	static inline auto FOnCancelChanges = PreyFunction<void(ArkOptionMenu *const _this)>(0x13688E0);
	static inline auto FUpdateInputPrompts = PreyFunction<void(ArkOptionMenu *const _this)>(0x136C790);
	static inline auto FRebindKeybindAttribute = PreyFunction<void(ArkOptionMenu *const _this, ArkOptionAttribute const &_attribute, const char *const _newInput)>(0x1369650);
	static inline auto FUpdateDropdownOption = PreyFunction<void(ArkOptionMenu *const _this, ArkOptionDropDownBase const &_widget, IUIElement *const _pUIElement, const unsigned _attrIndex, const unsigned _optionIndex)>(0x136C3E0);
	static inline auto FMarkAttributeDirty = PreyFunction<void(ArkOptionMenu *const _this, unsigned _attributeIndex)>(0x1368730);
};

