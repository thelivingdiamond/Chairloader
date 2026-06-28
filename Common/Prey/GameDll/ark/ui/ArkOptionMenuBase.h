// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class ArkUIOptionMenuBase;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkOptionMenuBase.h
class ArkOptionMenuBase // Id=8019131 Size=104
{
public:
	union SelectedOption // Id=801915C Size=4
	{
	public:
		int n;
		float f;
	};

	using TCommandQueue = std::vector<string>;
	
	unsigned m_currentAttribute;
	ArkUIOptionMenuBase *m_pOptionMenu;
	
	using TSelectedOptions = std::vector<ArkOptionMenuBase::SelectedOption>;
	
	std::vector<ArkOptionMenuBase::SelectedOption> m_selectedOptions;
	std::vector<string> m_commands;
	std::vector<string> m_queuedCommands;
	bool m_bProcessingCommands;
	
	virtual void Init() = 0;
	virtual void LoadOptionProfile(const char *arg0, bool arg1) = 0;
	virtual bool Update();
	virtual void Reset();
	virtual string GetSubPageLabel() const = 0;
	virtual void SelectPage(string const &arg0) = 0;
	virtual void SelectSubPage(string const &arg0) = 0;
	virtual void SelectNextPage() = 0;
	virtual void SelectPrevPage() = 0;
	virtual void SelectNextSubPage() = 0;
	virtual void SelectPrevSubPage() = 0;
	virtual void SetCurrentAttribute(unsigned arg0);
	virtual void SelectNextAttribute() = 0;
	virtual void SelectPrevAttribute() = 0;
	virtual void SelectNextOption(const int arg0) = 0;
	virtual void SelectPrevOption(const int arg0) = 0;
	virtual void SetOptionValue(int arg0, float arg1) = 0;
	virtual bool SetAttribute(unsigned arg0) = 0;
	virtual bool CanResetDefaults() = 0;
	virtual void ResetDefaults() = 0;
	virtual void ApplyDirtyAttributes();
	virtual void ClearDirtyAttributes();
	virtual void ProcessPostApplyAction();
	virtual bool OnPressConfirm();
	virtual void OnPressBack();
	virtual void OnPressButton(string const &arg0);
	virtual void OnDropDownOpen(int arg0);
	virtual void OnDropDownItemSelected(int arg0, int arg1);
	virtual bool IsActive();
	virtual bool IsControlMapOpen();
	virtual bool IsClosing();
	virtual bool IsDropDownOpen();
	virtual void UpdateInputPrompts();
	virtual void WriteGameCfg();
	virtual std::pair<char const *,char const *> GetPageAndSubPageLabels() const;
	void AddCommand(const char *_command) { FAddCommand(this,_command); }
	
#if 0
	unsigned GetCurrentAttribute() const;
	unsigned GetNumAttributeOptions() const;
	void StoreSelectedOption(const unsigned arg0, const int arg1);
	void StoreSelectedOption(const unsigned arg0, const float arg1);
	void ClearSelectedOptions();
	void ResizeSelectedOptions(const unsigned arg0);
#endif
	
	static inline auto FUpdate = PreyFunction<bool(ArkOptionMenuBase *const _this)>(0x136D660);
	static inline auto FReset = PreyFunction<void(ArkOptionMenuBase *const _this)>(0x136D630);
	static inline auto FOnPressConfirm = PreyFunction<bool(ArkOptionMenuBase *const _this)>(0x136D5F0);
	static inline auto FOnPressBack = PreyFunction<void(ArkOptionMenuBase *const _this)>(0x90D3B0);
	static inline auto FAddCommand = PreyFunction<void(ArkOptionMenuBase *const _this, const char *_command)>(0x136D5C0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ArkUIOptionMenuBase;

// ArkOptionMenuBase
// Header:  Prey/GameDll/ark/ui/ArkOptionMenuBase.h
class ArkOptionMenuBase
{ // Size=104 (0x68)
public:
	// ArkOptionMenuBase::SelectedOption
	// Header:  Prey/GameDll/ark/ui/ArkOptionMenuBase.h
	union SelectedOption
	{ // Size=4 (0x4)
		int n;
		float f;

	#if 0
		SelectedOption();
	#endif
	};

	using TCommandQueue = std::vector<string>;
	using TSelectedOptions = std::vector<ArkOptionMenuBase::SelectedOption>;

	unsigned m_currentAttribute;
	ArkUIOptionMenuBase* m_pOptionMenu;
	std::vector<ArkOptionMenuBase::SelectedOption> m_selectedOptions;
	std::vector<string> m_commands;
	std::vector<string> m_queuedCommands;
	bool m_bProcessingCommands;

	virtual void Init() = 0;
	virtual void LoadOptionProfile(const char* _filename, bool __unnamed1) = 0;
	virtual bool Update();
	virtual void Reset();
	virtual string GetSubPageLabel() const = 0;
	virtual void SelectPage(const string& _pageId) = 0;
	virtual void SelectSubPage(const string& _pageId) = 0;
	virtual void SelectNextPage() = 0;
	virtual void SelectPrevPage() = 0;
	virtual void SelectNextSubPage() = 0;
	virtual void SelectPrevSubPage() = 0;
	virtual void SetCurrentAttribute(unsigned _arg0_);
	virtual void SelectNextAttribute() = 0;
	virtual void SelectPrevAttribute() = 0;
	virtual void SelectNextOption(const int _attributeIndex) = 0;
	virtual void SelectPrevOption(const int _attributeIndex) = 0;
	virtual void SetOptionValue(int _attributeIndex, float _value) = 0;
	virtual bool SetAttribute(unsigned _attributeIndex) = 0;
	virtual bool CanResetDefaults() = 0;
	virtual void ResetDefaults() = 0;
	virtual void ApplyDirtyAttributes();
	virtual void ClearDirtyAttributes();
	virtual void ProcessPostApplyAction();
	virtual bool OnPressConfirm();
	virtual void OnPressBack();
	virtual void OnPressButton(const string& _arg0_);
	virtual void OnDropDownOpen(int _arg0_);
	virtual void OnDropDownItemSelected(int _arg0_, int _arg1_);
	virtual bool IsActive();
	virtual bool IsControlMapOpen();
	virtual bool IsClosing();
	virtual bool IsDropDownOpen();
	virtual void UpdateInputPrompts();
	virtual void OnInputPromptPressed(int _arg0_);
	virtual void OnShow();
	virtual void OnHide();
	virtual void WriteGameCfg();
	virtual std::pair<const char*, const char*> GetPageAndSubPageLabels() const;
	void AddCommand(const char* _command) { FAddCommand(this, _command); }

#if 0
	ArkOptionMenuBase(ArkUIOptionMenuBase* _arg0_);
	unsigned GetCurrentAttribute() const;
	unsigned GetNumAttributeOptions() const;
	void StoreSelectedOption(const unsigned _arg0_, const int _arg1_);
	void StoreSelectedOption(const unsigned _arg0_, const float _arg1_);
	void ClearSelectedOptions();
	void ResizeSelectedOptions(const unsigned _arg0_);
#endif

	static inline auto FUpdate = PreyFunction<bool(ArkOptionMenuBase* const _this)>(0x1451360);
	static inline auto FReset = PreyFunction<void(ArkOptionMenuBase* const _this)>(0x1451330);
	static inline auto FOnPressConfirm = PreyFunction<bool(ArkOptionMenuBase* const _this)>(0x14512F0);
	static inline auto FOnPressBack = PreyFunction<void(ArkOptionMenuBase* const _this)>(0x984A70);
	static inline auto FAddCommand = PreyFunction<void(ArkOptionMenuBase* const _this, const char* _command)>(0x14512C0);
};
#endif // !MOONCRASH
