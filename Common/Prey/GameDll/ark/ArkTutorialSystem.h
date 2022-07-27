// Header file automatically created from a PDB.

#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/IArkPDAListener.h>
#include <Prey/GameDll/ark/ui/IUIControlSchemeListener.h>

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

