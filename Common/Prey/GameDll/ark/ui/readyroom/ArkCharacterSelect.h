// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/GameDll/ark/ui/arkuimenubase.h>
#include <_unknown/IArkReadyRoomUI.h>

class ArkReadyRoomManager;
class CCryName;
enum class EArkCanAdvanceResult;
enum class EArkReadyRoomPage;
class IAction;
class IActionController;
class IAnimationDatabase;
struct ICharacterInstance;
struct IUIElement;
struct SAnimationContext;
struct SUIArguments;
struct SUIEventDesc;

// ArkCharacterSelect
// Header:  Prey/GameDll/ark/ui/readyroom/ArkCharacterSelect.h
class ArkCharacterSelect : public ArkUIMenuBase<ArkCharacterSelect>, public IArkReadyRoomUI
{ // Size=136 (0x88)
public:
	ArkReadyRoomManager& m_readyRoomManager;
	std::vector<uint64_t> m_characterOrder;
	unsigned m_selectedCharacterIndex;
	unsigned m_prevCharacterIndex;
	unsigned m_viewCharacter;
	unsigned m_handProp;
	unsigned m_environmentProp;
	bool m_bFirstOpen;
	int m_hideCharacterTicks;
	IActionController* m_pActionController;
	SAnimationContext* m_pAnimContext;
	const IAnimationDatabase* m_pAnimationDB;
	_smart_ptr<IAction> m_pCurrentAction;
	ArkAudioTrigger m_cycleTrigger;

	ArkCharacterSelect(ArkReadyRoomManager& _readyRoomManager);
	virtual ~ArkCharacterSelect();
	virtual EArkCanAdvanceResult CanAdvance() const;
	virtual void Reset();
	virtual void Cleanup();
	virtual void Open();
	void UpdateAnimatedCharacter(float _frameTime) { FUpdateAnimatedCharacter(this, _frameTime); }
	virtual bool ProcessInput(CCryName _action, int _activationMode, float _value);
	virtual void Close(bool _bImmediate, bool _bExitReadyRoom);
	virtual unsigned SetupInputPrompts(unsigned _startingIndex);
	virtual const char* GetLabel() const;
	uint64_t GetSelectedCharacter() const { return FGetSelectedCharacter(this); }
	void ShowCharacter(unsigned _characterIndex, bool _bForce) { FShowCharacter(this, _characterIndex, _bForce); }
	void PlayAnimOnEntity(const char* _animName, ICharacterInstance* _pCharacter, bool _bLooping, bool _bStopAnimations) const { FPlayAnimOnEntity(this, _animName, _pCharacter, _bLooping, _bStopAnimations); }
	void OnCharacterToggle(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCharacterToggle(this, _pSender, _event, _args); }
	void OnCharacterSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnCharacterSelect(this, _pSender, _event, _args); }
	void OnPipSelect(IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args) { FOnPipSelect(this, _pSender, _event, _args); }

#if 0
	static EArkReadyRoomPage GetID();
	bool CanSelectCurrentCharacter() const;
	void SelectCharacterAndAdvance();
	void AnimateResetButton();
#endif

	static inline auto FArkCharacterSelectOv1 = PreyFunction<void(ArkCharacterSelect* const _this, ArkReadyRoomManager& _readyRoomManager)>(0x14614E0);
	static inline auto FCanAdvance = PreyFunction<EArkCanAdvanceResult(const IArkReadyRoomUI* const _this)>(0x1461AC0);
	static inline auto FReset = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1462500);
	static inline auto FCleanup = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1461B60);
	static inline auto FOpen = PreyFunction<void(IArkReadyRoomUI* const _this)>(0x1461ED0);
	static inline auto FUpdateAnimatedCharacter = PreyFunction<void(ArkCharacterSelect* const _this, float _frameTime)>(0x1464790);
	static inline auto FProcessInput = PreyFunction<bool(IArkReadyRoomUI* const _this, CCryName _action, int _activationMode, float _value)>(0x14622D0);
	static inline auto FClose = PreyFunction<void(IArkReadyRoomUI* const _this, bool _bImmediate, bool _bExitReadyRoom)>(0x1461C40);
	static inline auto FSetupInputPrompts = PreyFunction<unsigned(IArkReadyRoomUI* const _this, unsigned _startingIndex)>(0x1462860);
	static inline auto FGetLabel = PreyFunction<const char* (const IArkReadyRoomUI* const _this)>(0x1461CF0);
	static inline auto FGetSelectedCharacter = PreyFunction<uint64_t(const ArkCharacterSelect* const _this)>(0x1461D00);
	static inline auto FShowCharacter = PreyFunction<void(ArkCharacterSelect* const _this, unsigned _characterIndex, bool _bForce)>(0x1462A00);
	static inline auto FPlayAnimOnEntity = PreyFunction<void(const ArkCharacterSelect* const _this, const char* _animName, ICharacterInstance* _pCharacter, bool _bLooping, bool _bStopAnimations)>(0x14621D0);
	static inline auto FOnCharacterToggle = PreyFunction<void(ArkCharacterSelect* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1461D60);
	static inline auto FOnCharacterSelect = PreyFunction<void(ArkCharacterSelect* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1461D10);
	static inline auto FOnPipSelect = PreyFunction<void(ArkCharacterSelect* const _this, IUIElement* const _pSender, const SUIEventDesc& _event, const SUIArguments& _args)>(0x1461E30);
};
#endif // MOONCRASH
