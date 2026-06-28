// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryCore/functor.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkPDAListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>
#include <Prey/Ark/ArkTutorial.h>

class ArkContextualTutorial;
class ArkNagTutorial;
class ArkTutorial;
class CCryName;

// Header: FromCpp
// Prey/GameDll/ark/ArkTutorialSystem.h
class ArkTutorialSystem : public IUIControlSchemeListener, public IArkPDAListener // Id=801691F Size=744
{
public:
	using TutorialCallback = Functor0;
	
	enum class ContextualType
	{
		tutorialPrompt = 0,
		pickup = 1,
		noImage = 2,
		count = 3,
	};

	std::unordered_map<unsigned __int64,float> m_tutorialCooldowns;
	std::vector<unsigned __int64> m_collectedCards;
	bool m_bPDAOpen;
	unsigned m_queueCount;
	ArkTimeRemaining m_nagTimeRemaining;
	std::vector<wstring> m_nagData;
	ArkNagTutorial const *m_pCurrentNag;
	
	class ContextualPackage // Id=801694E Size=64
	{
	public:
		Functor0 m_callback;
		std::vector<wstring> m_data;
		ArkContextualTutorial const *m_pTutorial;
		
#if 0
		bool operator==(const uint64_t arg0) const;
#endif
	};

	std::vector<ArkTutorialSystem::ContextualPackage> m_contextualQueue;
	
	class ContextualEntry : public ArkTutorialSystem::ContextualPackage // Id=8016964 Size=160
	{
	public:
		ArkTimeRemaining m_timer;
		ArkExclusiveActionFilter m_filter;
		
#if 0
		void Clear();
		bool IsValid() const;
#endif
	};

	std::array<ArkTutorialSystem::ContextualEntry,3> m_contextualTutorials;
	
	class CardEntry // Id=801696B Size=40
	{
	public:
		Functor0 m_callback;
		ArkCardTutorial const *m_pTutorial;
		
#if 0
		void Clear();
		bool IsValid() const;
		bool operator==(const uint64_t arg0) const;
#endif
	};

	std::vector<ArkTutorialSystem::CardEntry> m_cardQueue;
	int m_cardDelayTimeScaleHandle;
	ArkTimeRemaining m_cardDelay;
	ArkTutorialSystem::CardEntry m_currentCard;
	std::array<wstring,2> m_hudTutorialHints;
	
	ArkTutorialSystem();
	virtual ~ArkTutorialSystem();
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void OnPlayerDestroy() { FOnPlayerDestroy(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	bool DisplayTutorial(uint64_t _tutorialId, Functor0 _callback) { return FDisplayTutorial(this,_tutorialId,_callback); }
	bool DisplayTutorialWithData(uint64_t _tutorialId, wstring const &_data, Functor0 _callback) { return FDisplayTutorialWithDataOv1(this,_tutorialId,_data,_callback); }
	bool DisplayTutorialWithData(uint64_t _tutorialId, std::vector<wstring> const &_data, Functor0 _callback) { return FDisplayTutorialWithDataOv0(this,_tutorialId,_data,_callback); }
	void ClearTutorial(uint64_t _tutorialId) { FClearTutorial(this,_tutorialId); }
	void CollectTutorialCard(uint64_t _tutorialId) { FCollectTutorialCard(this,_tutorialId); }
	bool IsTutorialOnCooldown(uint64_t _tutorialId) const { return FIsTutorialOnCooldown(this,_tutorialId); }
	bool CheckCVarForTutorial(uint64_t _tutorialId) const { return FCheckCVarForTutorial(this,_tutorialId); }
	bool TriggerCooldownForTutorial(ArkTutorial const *_pTutorial) { return FTriggerCooldownForTutorial(this,_pTutorial); }
	void QueueTutorials(bool _bQueue) { FQueueTutorials(this,_bQueue); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	bool ProcessInput(CCryName const &_actionId, const int _activationMode, const float _fValue) { return FProcessInput(this,_actionId,_activationMode,_fValue); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	void SetHUDTutorialHint(EArkHUDTutorialHintChannel _channel, wstring const &_text) { FSetHUDTutorialHint(this,_channel,_text); }
	virtual bool OnControlSchemeChanged(EControlScheme _controlScheme);
	void TutorialCardUIClosed() { FTutorialCardUIClosed(this); }
	bool IsShowingContextualTutorial(ArkTutorialSystem::ContextualType _type) const { return FIsShowingContextualTutorial(this,_type); }
	static string const *GetRelevantBodyForTutorial(ArkTutorial const *_pTutorial) { return FGetRelevantBodyForTutorial(_pTutorial); }
	void ClearContextualTutorial(ArkTutorialSystem::ContextualType _type) { FClearContextualTutorial(this,_type); }
	void ClearNagTutorial() { FClearNagTutorial(this); }
	void ClearCardTutorial() { FClearCardTutorial(this); }
	void HandleContextualQueue() { FHandleContextualQueue(this); }
	bool ShowContextualTutorial(ArkTutorialSystem::ContextualType _type) { return FShowContextualTutorial(this,_type); }
	void HandleCardQueue() { FHandleCardQueue(this); }
	void ShowCardTutorial(bool _bIgnoreDelay) { FShowCardTutorial(this,_bIgnoreDelay); }
	virtual void OnPDAOpen();
	virtual void OnPDAClose();
	bool CanShowContextual(ArkContextualTutorial const *_pContextual, std::vector<enum ArkTutorialSystem::ContextualType> *_skipTypes) const { return FCanShowContextual(this,_pContextual,_skipTypes); }
	void ClearTutorials() { FClearTutorials(this); }
	void AddLocalizedData(wstring &_locString, std::vector<wstring> const &_data) const { FAddLocalizedData(this,_locString,_data); }
	void TriggerAudio(ArkTutorial const *_pTutorial) const { FTriggerAudio(this,_pTutorial); }
	
#if 0
	void CollectAllTutorialCards();
	std::vector<unsigned __int64> const &GetCollectedTutorialCards() const;
	bool IsQueued() const;
	ArkTutorialSystem::ContextualType GetContextualType(ArkContextualTutorial const *arg0) const;
	CCryName GetRelevantContextualActionId(ArkContextualTutorial const *arg0) const;
	bool CheckCVar(ArkTutorial const *arg0) const;
	void SetupExclusiveFilter(ArkTutorialSystem::ContextualType arg0);
#endif
	
	static inline auto FInit = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D92F0);
	static inline auto FReset = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D9CE0);
	static inline auto FOnPlayerDestroy = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D9A00);
	static inline auto FOnGameEnded = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D9A00);
	static inline auto FDisplayTutorial = PreyFunction<bool(ArkTutorialSystem *const _this, uint64_t _tutorialId, Functor0 _callback)>(0x13D88E0);
	static inline auto FDisplayTutorialWithDataOv1 = PreyFunction<bool(ArkTutorialSystem *const _this, uint64_t _tutorialId, wstring const &_data, Functor0 _callback)>(0x13D8930);
	static inline auto FDisplayTutorialWithDataOv0 = PreyFunction<bool(ArkTutorialSystem *const _this, uint64_t _tutorialId, std::vector<wstring> const &_data, Functor0 _callback)>(0x13D89B0);
	static inline auto FClearTutorial = PreyFunction<void(ArkTutorialSystem *const _this, uint64_t _tutorialId)>(0x13D8550);
	static inline auto FCollectTutorialCard = PreyFunction<void(ArkTutorialSystem *const _this, uint64_t _tutorialId)>(0x13D8860);
	static inline auto FIsTutorialOnCooldown = PreyFunction<bool(ArkTutorialSystem const *const _this, uint64_t _tutorialId)>(0x13D93A0);
	static inline auto FCheckCVarForTutorial = PreyFunction<bool(ArkTutorialSystem const *const _this, uint64_t _tutorialId)>(0x13D8260);
	static inline auto FTriggerCooldownForTutorial = PreyFunction<bool(ArkTutorialSystem *const _this, ArkTutorial const *_pTutorial)>(0x13DA790);
	static inline auto FQueueTutorials = PreyFunction<void(ArkTutorialSystem *const _this, bool _bQueue)>(0x13D9BF0);
	static inline auto FUpdate = PreyFunction<void(ArkTutorialSystem *const _this, float _frameTime)>(0x13DAA20);
	static inline auto FProcessInput = PreyFunction<bool(ArkTutorialSystem *const _this, CCryName const &_actionId, const int _activationMode, const float _fValue)>(0x13D9A10);
	static inline auto FSerialize = PreyFunction<void(ArkTutorialSystem *const _this, TSerialize ser)>(0x13D9D60);
	static inline auto FSetHUDTutorialHint = PreyFunction<void(ArkTutorialSystem *const _this, EArkHUDTutorialHintChannel _channel, wstring const &_text)>(0x13D9F20);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkTutorialSystem *const _this, EControlScheme _controlScheme)>(0x13D94B0);
	static inline auto FTutorialCardUIClosed = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13DA9A0);
	static inline auto FIsShowingContextualTutorial = PreyFunction<bool(ArkTutorialSystem const *const _this, ArkTutorialSystem::ContextualType _type)>(0x13D9380);
	static inline auto FGetRelevantBodyForTutorial = PreyFunction<string const *(ArkTutorial const *_pTutorial)>(0x13D8DC0);
	static inline auto FClearContextualTutorial = PreyFunction<void(ArkTutorialSystem *const _this, ArkTutorialSystem::ContextualType _type)>(0x13D83A0);
	static inline auto FClearNagTutorial = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D8470);
	static inline auto FClearCardTutorial = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D82E0);
	static inline auto FHandleContextualQueue = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D8E70);
	static inline auto FShowContextualTutorial = PreyFunction<bool(ArkTutorialSystem *const _this, ArkTutorialSystem::ContextualType _type)>(0x13DA1C0);
	static inline auto FHandleCardQueue = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D8DF0);
	static inline auto FShowCardTutorial = PreyFunction<void(ArkTutorialSystem *const _this, bool _bIgnoreDelay)>(0x13D9FF0);
	static inline auto FOnPDAOpen = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D9970);
	static inline auto FOnPDAClose = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D98F0);
	static inline auto FCanShowContextual = PreyFunction<bool(ArkTutorialSystem const *const _this, ArkContextualTutorial const *_pContextual, std::vector<enum ArkTutorialSystem::ContextualType> *_skipTypes)>(0x13D8120);
	static inline auto FClearTutorials = PreyFunction<void(ArkTutorialSystem *const _this)>(0x13D8670);
	static inline auto FAddLocalizedData = PreyFunction<void(ArkTutorialSystem const *const _this, wstring &_locString, std::vector<wstring> const &_data)>(0x13D7F60);
	static inline auto FTriggerAudio = PreyFunction<void(ArkTutorialSystem const *const _this, ArkTutorial const *_pTutorial)>(0x13DA6E0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkExclusiveActionFilter.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkPDAListener.h>
#include <Prey/GameDll/ark/ui/ArkButtonPromptCollection.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

class ArkCardTutorial;
class ArkContextualTutorial;
class ArkNagTutorial;
class ArkReadyRoomTutorial;
class ArkTutorial;
class CCryName;
enum class EArkHUDTutorialHintChannel;
enum EControlScheme;

// ArkTutorialSystem
// Header:  Prey/GameDll/ark/ArkTutorialSystem.h
class ArkTutorialSystem : public IUIControlSchemeListener, public IArkPDAListener
{ // Size=1680 (0x690)
public:
	enum class ContextualType
	{
		tutorialPrompt = 0,
		pickup = 1,
		noImage = 2,
		count = 3,
	};

	// ArkTutorialSystem::ReadyRoomEntry
	// Header:  Prey/GameDll/ark/ArkTutorialSystem.h
	class ReadyRoomEntry
	{ // Size=64 (0x40)
	public:
		Functor0 m_callback;
		std::vector<wstring> m_data;
		const ArkReadyRoomTutorial* m_pTutorial;

	#if 0
		ReadyRoomEntry();
		ReadyRoomEntry(const ArkReadyRoomTutorial* _arg0_, Functor0 _arg1_, const std::vector<wstring>& _arg2_);
		bool operator==(const uint64_t _arg0_) const;
		void Clear();
		bool IsValid() const;
	#endif
	};

	// ArkTutorialSystem::ContextualPackage
	// Header:  Prey/GameDll/ark/ArkTutorialSystem.h
	class ContextualPackage
	{ // Size=64 (0x40)
	public:
		Functor0 m_callback;
		std::vector<wstring> m_data;
		const ArkContextualTutorial* m_pTutorial;

	#if 0
		ContextualPackage();
		ContextualPackage(const ArkContextualTutorial* _arg0_, Functor0 _arg1_, const std::vector<wstring>& _arg2_);
		bool operator==(const uint64_t _arg0_) const;
	#endif
	};

	// ArkTutorialSystem::ContextualEntry
	// Header:  Prey/GameDll/ark/ArkTutorialSystem.h
	class ContextualEntry : public ArkTutorialSystem::ContextualPackage
	{ // Size=160 (0xA0)
	public:
		ArkTimeRemaining m_timer;
		ArkExclusiveActionFilter m_filter;

	#if 0
		ContextualEntry();
		void Clear();
		bool IsValid() const;
		ArkTutorialSystem::ContextualEntry& operator=(const ArkTutorialSystem::ContextualPackage& _arg0_);
	#endif
	};

	// ArkTutorialSystem::CardEntry
	// Header:  Prey/GameDll/ark/ArkTutorialSystem.h
	class CardEntry
	{ // Size=40 (0x28)
	public:
		Functor0 m_callback;
		const ArkCardTutorial* m_pTutorial;

	#if 0
		CardEntry();
		CardEntry(const ArkCardTutorial* _arg0_, Functor0 _arg1_);
		void Clear();
		bool IsValid() const;
		bool operator==(const uint64_t _arg0_) const;
	#endif
	};

	using TutorialCallback = Functor0;

	std::unordered_map<uint64_t, float> m_tutorialCooldowns;
	std::vector<uint64_t> m_collectedCards;
	bool m_bPDAOpen;
	unsigned m_queueCount;
	std::vector<ArkTutorialSystem::ReadyRoomEntry> m_readyRoomQueue;
	ArkTutorialSystem::ReadyRoomEntry m_currentReadyRoom;
	ArkButtonPromptCollection m_readyRoomPrompts;
	ArkTimeRemaining m_nagTimeRemaining;
	std::vector<wstring> m_nagData;
	const ArkNagTutorial* m_pCurrentNag;
	std::vector<ArkTutorialSystem::ContextualPackage> m_contextualQueue;
	std::array<ArkTutorialSystem::ContextualEntry, 3> m_contextualTutorials;
	std::vector<ArkTutorialSystem::CardEntry> m_cardQueue;
	int m_cardDelayTimeScaleHandle;
	ArkTimeRemaining m_cardDelay;
	ArkTutorialSystem::CardEntry m_currentCard;
	bool m_bHasViewedCard;
	std::array<wstring, 2> m_hudTutorialHints;

	ArkTutorialSystem();
	virtual ~ArkTutorialSystem();
	void Init() { FInit(this); }
	void Reset() { FReset(this); }
	void OnPlayerDestroy() { FOnPlayerDestroy(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	bool DisplayTutorial(uint64_t _tutorialId, Functor0 _callback) { return FDisplayTutorial(this, _tutorialId, _callback); }
	bool DisplayTutorialWithData(uint64_t _tutorialId, const wstring& _data, Functor0 _callback) { return FDisplayTutorialWithDataOv1(this, _tutorialId, _data, _callback); }
	bool DisplayTutorialWithData(uint64_t _tutorialId, const std::vector<wstring>& _data, Functor0 _callback) { return FDisplayTutorialWithDataOv0(this, _tutorialId, _data, _callback); }
	void ClearTutorial(uint64_t _tutorialId) { FClearTutorial(this, _tutorialId); }
	void CollectTutorialCard(uint64_t _tutorialId) { FCollectTutorialCard(this, _tutorialId); }
	bool IsTutorialOnCooldown(uint64_t _tutorialId) const { return FIsTutorialOnCooldown(this, _tutorialId); }
	bool CheckCVarForTutorial(uint64_t _tutorialId) const { return FCheckCVarForTutorial(this, _tutorialId); }
	bool TriggerCooldownForTutorial(const ArkTutorial* _pTutorial) { return FTriggerCooldownForTutorial(this, _pTutorial); }
	void QueueTutorials(bool _bQueue) { FQueueTutorials(this, _bQueue); }
	void ForceResumeTutorials() { FForceResumeTutorials(this); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	bool ProcessInput(const CCryName& _actionId, const int _activationMode, const float _fValue) { return FProcessInput(this, _actionId, _activationMode, _fValue); }
	void Serialize(TSerialize ser) { FSerialize(this, ser); }
	void SetHUDTutorialHint(EArkHUDTutorialHintChannel _channel, const wstring& _text) { FSetHUDTutorialHint(this, _channel, _text); }
	virtual bool OnControlSchemeChanged(const EControlScheme _controlScheme);
	void TutorialCardUIClosed() { FTutorialCardUIClosed(this); }
	bool IsShowingContextualTutorial(ArkTutorialSystem::ContextualType _type) const { return FIsShowingContextualTutorial(this, _type); }
	void OnTutorialButtonPromptPressed(int _promptIndex) { FOnTutorialButtonPromptPressed(this, _promptIndex); }
	static const string* GetRelevantBodyForTutorial(const ArkTutorial* _pTutorial) { return FGetRelevantBodyForTutorial(_pTutorial); }
	void ClearContextualTutorial(ArkTutorialSystem::ContextualType _type) { FClearContextualTutorial(this, _type); }
	void ClearNagTutorial() { FClearNagTutorial(this); }
	void ClearCardTutorial() { FClearCardTutorial(this); }
	void ClearReadyRoomTutorial() { FClearReadyRoomTutorial(this); }
	void OnReadyRoomConfirm() { FOnReadyRoomConfirm(this); }
	void HandleReadyRoomQueue() { FHandleReadyRoomQueue(this); }
	void ShowReadyRoomTutorial() { FShowReadyRoomTutorial(this); }
	void HandleContextualQueue() { FHandleContextualQueue(this); }
	bool ShowContextualTutorial(ArkTutorialSystem::ContextualType _type) { return FShowContextualTutorial(this, _type); }
	void HandleCardQueue() { FHandleCardQueue(this); }
	void ShowCardTutorial(bool _bIgnoreDelay) { FShowCardTutorial(this, _bIgnoreDelay); }
	virtual void OnPDAOpen();
	virtual void OnPDAClose();
	bool CanShowContextual(const ArkContextualTutorial* _pContextual, std::vector<enum::ArkTutorialSystem::ContextualType>* _skipTypes) const { return FCanShowContextual(this, _pContextual, _skipTypes); }
	bool CheckCVar(const ArkTutorial* _pTutorial) const { return FCheckCVar(this, _pTutorial); }
	void ClearTutorials() { FClearTutorials(this); }
	void AddLocalizedData(wstring& _locString, const std::vector<wstring>& _data) const { FAddLocalizedData(this, _locString, _data); }
	void TriggerAudio(const ArkTutorial* _pTutorial) const { FTriggerAudio(this, _pTutorial); }

#if 0
	void CollectAllTutorialCards();
	const std::vector<uint64_t>& GetCollectedTutorialCards() const;
	bool IsQueued() const;
	bool IsShowingReadyRoomTutorial() const;
	bool IsShowingReadyRoomTutorial(uint64_t _arg0_) const;
	void MarkCardViewed();
	bool HasViewedCard() const;
	ArkTutorialSystem::ContextualType GetContextualType(const ArkContextualTutorial* _arg0_) const;
	CCryName GetRelevantContextualActionId(const ArkContextualTutorial* _arg0_) const;
	void SetupExclusiveFilter(ArkTutorialSystem::ContextualType _arg0_);
#endif

	static inline auto FArkTutorialSystemOv1 = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E4050);
	static inline auto FInit = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E5E10);
	static inline auto FReset = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E69F0);
	static inline auto FOnPlayerDestroy = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E6610);
	static inline auto FOnGameEnded = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E6610);
	static inline auto FDisplayTutorial = PreyFunction<bool(ArkTutorialSystem* const _this, uint64_t _tutorialId, Functor0 _callback)>(0x14E5210);
	static inline auto FDisplayTutorialWithDataOv1 = PreyFunction<bool(ArkTutorialSystem* const _this, uint64_t _tutorialId, const wstring& _data, Functor0 _callback)>(0x14E5260);
	static inline auto FDisplayTutorialWithDataOv0 = PreyFunction<bool(ArkTutorialSystem* const _this, uint64_t _tutorialId, const std::vector<wstring>& _data, Functor0 _callback)>(0x14E52E0);
	static inline auto FClearTutorial = PreyFunction<void(ArkTutorialSystem* const _this, uint64_t _tutorialId)>(0x14E4DF0);
	static inline auto FCollectTutorialCard = PreyFunction<void(ArkTutorialSystem* const _this, uint64_t _tutorialId)>(0x14E5190);
	static inline auto FIsTutorialOnCooldown = PreyFunction<bool(const ArkTutorialSystem* const _this, uint64_t _tutorialId)>(0x14E5EC0);
	static inline auto FCheckCVarForTutorial = PreyFunction<bool(const ArkTutorialSystem* const _this, uint64_t _tutorialId)>(0x14E4A60);
	static inline auto FTriggerCooldownForTutorial = PreyFunction<bool(ArkTutorialSystem* const _this, const ArkTutorial* _pTutorial)>(0x14E7850);
	static inline auto FQueueTutorials = PreyFunction<void(ArkTutorialSystem* const _this, bool _bQueue)>(0x14E68C0);
	static inline auto FForceResumeTutorials = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E57A0);
	static inline auto FUpdate = PreyFunction<void(ArkTutorialSystem* const _this, float _frameTime)>(0x14E7AE0);
	static inline auto FProcessInput = PreyFunction<bool(ArkTutorialSystem* const _this, const CCryName& _actionId, const int _activationMode, const float _fValue)>(0x14E6680);
	static inline auto FSerialize = PreyFunction<void(ArkTutorialSystem* const _this, TSerialize ser)>(0x14E6B00);
	static inline auto FSetHUDTutorialHint = PreyFunction<void(ArkTutorialSystem* const _this, EArkHUDTutorialHintChannel _channel, const wstring& _text)>(0x14E6CD0);
	static inline auto FOnControlSchemeChanged = PreyFunction<bool(ArkTutorialSystem* const _this, const EControlScheme _controlScheme)>(0x14E5FD0);
	static inline auto FTutorialCardUIClosed = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E7A60);
	static inline auto FIsShowingContextualTutorial = PreyFunction<bool(const ArkTutorialSystem* const _this, ArkTutorialSystem::ContextualType _type)>(0x14E5EA0);
	static inline auto FOnTutorialButtonPromptPressed = PreyFunction<void(ArkTutorialSystem* const _this, int _promptIndex)>(0x14E6660);
	static inline auto FGetRelevantBodyForTutorial = PreyFunction<const string* (const ArkTutorial* _pTutorial)>(0x14E5840);
	static inline auto FClearContextualTutorial = PreyFunction<void(ArkTutorialSystem* const _this, ArkTutorialSystem::ContextualType _type)>(0x14E4B80);
	static inline auto FClearNagTutorial = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E4C50);
	static inline auto FClearCardTutorial = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E4AC0);
	static inline auto FClearReadyRoomTutorial = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E4D40);
	static inline auto FOnReadyRoomConfirm = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E6620);
	static inline auto FHandleReadyRoomQueue = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E5D70);
	static inline auto FShowReadyRoomTutorial = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E7410);
	static inline auto FHandleContextualQueue = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E58F0);
	static inline auto FShowContextualTutorial = PreyFunction<bool(ArkTutorialSystem* const _this, ArkTutorialSystem::ContextualType _type)>(0x14E6F80);
	static inline auto FHandleCardQueue = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E5870);
	static inline auto FShowCardTutorial = PreyFunction<void(ArkTutorialSystem* const _this, bool _bIgnoreDelay)>(0x14E6DA0);
	static inline auto FOnPDAOpen = PreyFunction<void(IArkPDAListener* const _this)>(0x14E6580);
	static inline auto FOnPDAClose = PreyFunction<void(IArkPDAListener* const _this)>(0x14E6500);
	static inline auto FCanShowContextual = PreyFunction<bool(const ArkTutorialSystem* const _this, const ArkContextualTutorial* _pContextual, std::vector<enum::ArkTutorialSystem::ContextualType>* _skipTypes)>(0x14E48A0);
	static inline auto FCheckCVar = PreyFunction<bool(const ArkTutorialSystem* const _this, const ArkTutorial* _pTutorial)>(0x14E49E0);
	static inline auto FClearTutorials = PreyFunction<void(ArkTutorialSystem* const _this)>(0x14E4F70);
	static inline auto FAddLocalizedData = PreyFunction<void(const ArkTutorialSystem* const _this, wstring& _locString, const std::vector<wstring>& _data)>(0x14E46E0);
	static inline auto FTriggerAudio = PreyFunction<void(const ArkTutorialSystem* const _this, const ArkTutorial* _pTutorial)>(0x14E77A0);
};
#endif // !MOONCRASH
