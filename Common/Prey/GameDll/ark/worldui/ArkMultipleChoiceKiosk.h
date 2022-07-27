// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/worldui/ArkKioskBase.h>

struct IEntity;
struct IUIElement;
struct SEntityUpdateContext;
struct SUIArguments;
struct SUIEventDesc;

// Header: FromCpp
// Prey/GameDll/ark/worldui/ArkMultipleChoiceKiosk.h
class ArkMultipleChoiceKiosk : public ArkKioskBase // Id=801B8D1 Size=552
{
public:
	enum class EArkMultipleChoiceKioskState
	{
		Invalid = 0,
		StartPage = 1,
		QuestionPage = 2,
		RorschachPage = 3,
		LogoPage = 4,
	};

	ArkMultipleChoiceKiosk::EArkMultipleChoiceKioskState m_state;
	ArkSimpleTimer m_timer;
	string m_buttonPressed;
	string m_questionText;
	std::array<string,4> m_answers;
	
	ArkMultipleChoiceKiosk();
	virtual void FullSerialize(TSerialize _ser);
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	virtual void OnButtonPress(IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args);
	void SetMultipleChoiceAnswer(const char _answerId, const char *_answerText) { FSetMultipleChoiceAnswer(this,_answerId,_answerText); }
	void SetMultipleChoiceQuestion(const char *_questionText) { FSetMultipleChoiceQuestion(this,_questionText); }
	void DisplayNewQuestion() { FDisplayNewQuestion(this); }
	void DisplayRorschachPage() { FDisplayRorschachPage(this); }
	void DisplayLogoPage() { FDisplayLogoPage(this); }
	void DisplayStartPage() { FDisplayStartPage(this); }
	virtual bool PopulateInteractionInfo(IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray) const;
	virtual void RefreshUI(bool _bReinit);
	virtual void HandleInteraction(IUIElement *_pUIInstance);
	virtual void LoadProperties();
	virtual void OnReset(bool _bEnteringGameMode);
	virtual ~ArkMultipleChoiceKiosk();
	
#if 0
	void SetState(ArkMultipleChoiceKiosk::EArkMultipleChoiceKioskState arg0, bool arg1);
#endif
	
	static inline auto FFullSerialize = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, TSerialize _ser)>(0x13A1C30);
	static inline auto FUpdate = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x13A2680);
	static inline auto FOnButtonPress = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, IUIElement *const _pSender, SUIEventDesc const &_event, SUIArguments const &_args)>(0x13A2090);
	static inline auto FSetMultipleChoiceAnswer = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, const char _answerId, const char *_answerText)>(0x13A25C0);
	static inline auto FSetMultipleChoiceQuestion = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, const char *_questionText)>(0x13A2650);
	static inline auto FDisplayNewQuestion = PreyFunction<void(ArkMultipleChoiceKiosk *const _this)>(0x13A1B80);
	static inline auto FDisplayRorschachPage = PreyFunction<void(ArkMultipleChoiceKiosk *const _this)>(0x13A1BB0);
	static inline auto FDisplayLogoPage = PreyFunction<void(ArkMultipleChoiceKiosk *const _this)>(0x13A1B40);
	static inline auto FDisplayStartPage = PreyFunction<void(ArkMultipleChoiceKiosk *const _this)>(0x13A1BF0);
	static inline auto FPopulateInteractionInfo = PreyFunction<bool(ArkMultipleChoiceKiosk const *const _this, IEntity const *const _pEntity, std::array<ArkInteractionInfo,4> &_interactionArray)>(0x13A2150);
	static inline auto FRefreshUI = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, bool _bReinit)>(0x13A21F0);
	static inline auto FHandleInteraction = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, IUIElement *_pUIInstance)>(0x13A1EA0);
	static inline auto FLoadProperties = PreyFunction<void(ArkMultipleChoiceKiosk *const _this)>(0x13A1ED0);
	static inline auto FOnReset = PreyFunction<void(ArkMultipleChoiceKiosk *const _this, bool _bEnteringGameMode)>(0x13A2100);
};

