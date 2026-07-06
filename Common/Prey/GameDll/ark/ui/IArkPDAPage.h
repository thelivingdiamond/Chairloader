// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

class CCryName;

// Header: Override
// Prey/GameDll/ark/ui/IArkPDAPage.h
class IArkPDAPage // Id=8016FED Size=16
{
public:
	ArkPDATab m_tab;
	
	virtual ~IArkPDAPage();
	virtual void Open() = 0;
	virtual void Close();
	virtual void Refresh() const;
	virtual void Update(float _frameTime);
	virtual bool ProcessInput(CCryName const &_rActionId, const int _activationMode, const float _fValue);
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	virtual void OnClosePDA();
	virtual bool HasNew() const;
	
#if 0
	ArkPDATab GetTab() const;
#endif
	
	static inline auto FClose = PreyFunction<void(IArkPDAPage *const _this)>(0xA13080);
	static inline auto FRefresh = PreyFunction<void(IArkPDAPage const *const _this)>(0xA13080);
	static inline auto FUpdate = PreyFunction<void(IArkPDAPage *const _this, float _frameTime)>(0xA13080);
	static inline auto FProcessInput = PreyFunction<bool(IArkPDAPage *const _this, CCryName const &_rActionId, const int _activationMode, const float _fValue)>(0xDD23F0);
	static inline auto FManagesInputPrompts = PreyFunction<bool(IArkPDAPage const *const _this)>(0xDD23F0);
	static inline auto FSetupInputPrompts = PreyFunction<void(IArkPDAPage *const _this)>(0xA13080);
	static inline auto FOnClosePDA = PreyFunction<void(IArkPDAPage *const _this)>(0xA13080);
	static inline auto FHasNew = PreyFunction<bool(IArkPDAPage const *const _this)>(0xDD23F0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class CCryName;

// IArkPDAPage
// Header:  Prey/GameDll/ark/ui/IArkPDAPage.h
class IArkPDAPage
{ // Size=16 (0x10)
public:
	const ArkPDATab m_tab;

	virtual ~IArkPDAPage();
	virtual void Open() = 0;
	virtual void Close();
	virtual void Refresh() const;
	virtual void Update(float _frameTime);
	virtual bool ProcessInput(const CCryName& _rActionId, const int _activationMode, const float _fValue);
	virtual bool ManagesInputPrompts() const;
	virtual void SetupInputPrompts();
	virtual void OnClosePDA();
	virtual bool HasNew() const;

#if 0
	IArkPDAPage(const ArkPDATab _arg0_);
	ArkPDATab GetTab() const;
#endif

	static inline auto FClose = PreyFunction<void(IArkPDAPage* const _this)>(0x1333E90);
	static inline auto FRefresh = PreyFunction<void(const IArkPDAPage* const _this)>(0x1333E90);
	static inline auto FUpdate = PreyFunction<void(IArkPDAPage* const _this, float _frameTime)>(0x1333E90);
	static inline auto FProcessInput = PreyFunction<bool(IArkPDAPage* const _this, const CCryName& _rActionId, const int _activationMode, const float _fValue)>(0x13B0900);
	static inline auto FManagesInputPrompts = PreyFunction<bool(const IArkPDAPage* const _this)>(0x13B0900);
	static inline auto FSetupInputPrompts = PreyFunction<void(IArkPDAPage* const _this)>(0x1333E90);
	static inline auto FOnClosePDA = PreyFunction<void(IArkPDAPage* const _this)>(0x1333E90);
	static inline auto FHasNew = PreyFunction<bool(const IArkPDAPage* const _this)>(0x13B0900);
};
#endif // !MOONCRASH
