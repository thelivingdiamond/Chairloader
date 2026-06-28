// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/ArkExclusiveActionFilter.h>
#include <Prey/GameDll/ark/ui/IArkPauseMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/GameDll/ark/ui/ArkButtonPrompt.h>

class ArkButtonPrompt;
class CCryName;
struct IUIElement;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkButtonPromptCollection.h
class ArkButtonPromptCollection : public IUIControlSchemeListener, public IArkPauseMenuListener // Id=801703B Size=584
{
public:
	std::array<ArkButtonPrompt,8> m_buttonPrompts;
	uint8_t m_maxUsed;
	string m_formatFunction;
	string m_setFunctionOrArrayName;
	ArkExclusiveActionFilter m_filter;
	bool m_bInitialized;
	
	ArkButtonPromptCollection();
	ArkButtonPromptCollection(ArkButtonPromptCollection const &_source);
	ArkButtonPromptCollection(string const &_formatFunction, string const &_setFunctionOrArrayName);
	virtual ~ArkButtonPromptCollection();
	void Init() { FInit(this); }
	void CleanUp() { FCleanUp(this); }
	void SetMaxInputsUsed(uint8_t _maxUsed) { FSetMaxInputsUsed(this,_maxUsed); }
	void ProcessInput(CCryName const &_actionId, const int _activationMode, const float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	bool Update(float _frameTime) { return FUpdate(this,_frameTime); }
	void EnableFilter(const char *_filterName, std::vector<CCryName> const &_allowedActions) { FEnableFilter(this,_filterName,_allowedActions); }
	void ClearAll() { FClearAll(this); }
	void ClearFrom(int _index) { FClearFrom(this,_index); }
	void ClearPromptTextForAll() { FClearPromptTextForAll(this); }
	void CallActionscript(IUIElement *_pUIElement) { FCallActionscript(this,_pUIElement); }
	void CallActionscriptPerformant(IUIElement *_pUIElement) { FCallActionscriptPerformant(this,_pUIElement); }
	void HidePerformant(IUIElement *const _pUIElement) { FHidePerformant(this,_pUIElement); }
	ArkButtonPrompt &GetButtonPrompt(int _index) { return FGetButtonPrompt(this,_index); }
	bool operator==(ArkButtonPromptCollection const &_rhs) const { return FoperatorEqEq(this,_rhs); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	virtual void OnOptionMenuClosed();
	
#if 0
	void Hide(IUIElement *const arg0);
	ArkButtonPrompt &operator[](int arg0);
	int GetMaxNumButtonPrompts() const;
#endif
	
	static inline auto FBitNotArkButtonPromptCollection = PreyFunction<void(ArkButtonPromptCollection *const _this)>(0x1351C00);
	static inline auto FInit = PreyFunction<void(ArkButtonPromptCollection *const _this)>(0x1352A30);
	static inline auto FCleanUp = PreyFunction<void(ArkButtonPromptCollection *const _this)>(0x13524D0);
	static inline auto FSetMaxInputsUsed = PreyFunction<void(ArkButtonPromptCollection *const _this, uint8_t _maxUsed)>(0x1352B90);
	static inline auto FProcessInput = PreyFunction<void(ArkButtonPromptCollection *const _this, CCryName const &_actionId, const int _activationMode, const float _value)>(0x1352B20);
	static inline auto FUpdate = PreyFunction<bool(ArkButtonPromptCollection *const _this, float _frameTime)>(0x1352BA0);
	static inline auto FEnableFilter = PreyFunction<void(ArkButtonPromptCollection *const _this, const char *_filterName, std::vector<CCryName> const &_allowedActions)>(0x1352660);
	static inline auto FClearAll = PreyFunction<void(ArkButtonPromptCollection *const _this)>(0x1352570);
	static inline auto FClearFrom = PreyFunction<void(ArkButtonPromptCollection *const _this, int _index)>(0x13525C0);
	static inline auto FClearPromptTextForAll = PreyFunction<void(ArkButtonPromptCollection *const _this)>(0x1352610);
	static inline auto FCallActionscript = PreyFunction<void(ArkButtonPromptCollection *const _this, IUIElement *_pUIElement)>(0x1351FC0);
	static inline auto FCallActionscriptPerformant = PreyFunction<void(ArkButtonPromptCollection *const _this, IUIElement *_pUIElement)>(0x1352230);
	static inline auto FHidePerformant = PreyFunction<void(ArkButtonPromptCollection *const _this, IUIElement *const _pUIElement)>(0x13527F0);
	static inline auto FGetButtonPrompt = PreyFunction<ArkButtonPrompt &(ArkButtonPromptCollection *const _this, int _index)>(0x13527E0);
	static inline auto FoperatorEqEq = PreyFunction<bool(ArkButtonPromptCollection const *const _this, ArkButtonPromptCollection const &_rhs)>(0x1351E10);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkButtonPromptCollection *const _this, EControlScheme _controlScheme)>(0x1352A80);
	static inline auto FOnOptionMenuClosed = PreyFunction<void(ArkButtonPromptCollection *const _this)>(0x1352AE0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryString/CryName.h>
#include <Prey/GameDll/ark/ArkExclusiveActionFilter.h>
#include <Prey/GameDll/ark/ui/ArkButtonPrompt.h>
#include <Prey/GameDll/ark/ui/IArkPauseMenuListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

enum EControlScheme;
struct IUIElement;

// ArkButtonPromptCollection
// Header:  Prey/GameDll/ark/ui/ArkButtonPromptCollection.h
class ArkButtonPromptCollection : public IUIControlSchemeListener, public IArkPauseMenuListener
{ // Size=840 (0x348)
public:
	std::array<ArkButtonPrompt, 8> m_buttonPrompts;
	uint8_t m_maxUsed;
	string m_formatFunction;
	string m_setFunctionOrArrayName;
	ArkExclusiveActionFilter m_filter;
	bool m_bInitialized;

	ArkButtonPromptCollection();
	ArkButtonPromptCollection(const ArkButtonPromptCollection& _source);
	ArkButtonPromptCollection(const string& _formatFunction, const string& _setFunctionOrArrayName);
	virtual ~ArkButtonPromptCollection();
	void Init() { FInit(this); }
	void CleanUp() { FCleanUp(this); }
	void SetMaxInputsUsed(uint8_t _maxUsed) { FSetMaxInputsUsed(this, _maxUsed); }
	void ProcessInput(const CCryName& _actionId, const int _activationMode, const float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void EnableFilter(const char* _filterName, const std::vector<CCryName>& _allowedActions) { FEnableFilter(this, _filterName, _allowedActions); }
	void ClearAll() { FClearAll(this); }
	void ClearFrom(int _index) { FClearFrom(this, _index); }
	void ClearPromptTextForAll() { FClearPromptTextForAll(this); }
	void CallActionscript(IUIElement* _pUIElement) { FCallActionscript(this, _pUIElement); }
	void CallNonHoldActionscript(IUIElement* _pUIElement) { FCallNonHoldActionscript(this, _pUIElement); }
	void CallActionscriptPerformant(IUIElement* _pUIElement) { FCallActionscriptPerformant(this, _pUIElement); }
	void HidePerformant(IUIElement* const _pUIElement) { FHidePerformant(this, _pUIElement); }
	ArkButtonPrompt& GetButtonPrompt(int _index) { return FGetButtonPrompt(this, _index); }
	bool operator==(const ArkButtonPromptCollection& _rhs) const { return FoperatorEqEq(this, _rhs); }
	void OnClick(int _index) { FOnClick(this, _index); }
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	virtual void OnOptionMenuClosed();

#if 0
	void Hide(IUIElement* const _arg0_);
	ArkButtonPrompt& operator[](int _arg0_);
	int GetMaxNumButtonPrompts() const;
	ArkButtonPromptCollection& operator=(const ArkButtonPromptCollection& _arg0_);
#endif

	static inline auto FArkButtonPromptCollectionOv2 = PreyFunction<void(ArkButtonPromptCollection* const _this)>(0x1434490);
	static inline auto FArkButtonPromptCollectionOv1 = PreyFunction<void(ArkButtonPromptCollection* const _this, const ArkButtonPromptCollection& _source)>(0x14342E0);
	static inline auto FArkButtonPromptCollectionOv0 = PreyFunction<void(ArkButtonPromptCollection* const _this, const string& _formatFunction, const string& _setFunctionOrArrayName)>(0x14343C0);
	static inline auto FBitNotArkButtonPromptCollection = PreyFunction<void(ArkButtonPromptCollection* const _this)>(0x1434660);
	static inline auto FInit = PreyFunction<void(ArkButtonPromptCollection* const _this)>(0x14356E0);
	static inline auto FCleanUp = PreyFunction<void(ArkButtonPromptCollection* const _this)>(0x1435180);
	static inline auto FSetMaxInputsUsed = PreyFunction<void(ArkButtonPromptCollection* const _this, uint8_t _maxUsed)>(0x1435900);
	static inline auto FProcessInput = PreyFunction<void(ArkButtonPromptCollection* const _this, const CCryName& _actionId, const int _activationMode, const float _value)>(0x1435890);
	static inline auto FUpdate = PreyFunction<bool(ArkButtonPromptCollection* const _this, float _frameTime)>(0x1435910);
	static inline auto FEnableFilter = PreyFunction<void(ArkButtonPromptCollection* const _this, const char* _filterName, const std::vector<CCryName>& _allowedActions)>(0x1435310);
	static inline auto FClearAll = PreyFunction<void(ArkButtonPromptCollection* const _this)>(0x1435220);
	static inline auto FClearFrom = PreyFunction<void(ArkButtonPromptCollection* const _this, int _index)>(0x1435270);
	static inline auto FClearPromptTextForAll = PreyFunction<void(ArkButtonPromptCollection* const _this)>(0x14352C0);
	static inline auto FCallActionscript = PreyFunction<void(ArkButtonPromptCollection* const _this, IUIElement* _pUIElement)>(0x1434A30);
	static inline auto FCallNonHoldActionscript = PreyFunction<void(ArkButtonPromptCollection* const _this, IUIElement* _pUIElement)>(0x1434F40);
	static inline auto FCallActionscriptPerformant = PreyFunction<void(ArkButtonPromptCollection* const _this, IUIElement* _pUIElement)>(0x1434CA0);
	static inline auto FHidePerformant = PreyFunction<void(ArkButtonPromptCollection* const _this, IUIElement* const _pUIElement)>(0x14354A0);
	static inline auto FGetButtonPrompt = PreyFunction<ArkButtonPrompt& (ArkButtonPromptCollection* const _this, int _index)>(0x1435490);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkButtonPromptCollection* const _this, const ArkButtonPromptCollection& _rhs)>(0x1434880);
	static inline auto FOnClick = PreyFunction<void(ArkButtonPromptCollection* const _this, int _index)>(0x1435730);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkButtonPromptCollection* const _this, const EControlScheme _controlScheme)>(0x14357F0);
	static inline auto FOnOptionMenuClosed = PreyFunction<void(IArkPauseMenuListener* const _this)>(0x1435850);
};
#endif // !MOONCRASH
