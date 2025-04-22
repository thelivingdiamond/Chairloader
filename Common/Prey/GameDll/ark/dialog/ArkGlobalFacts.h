// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryGame/IGameTokens.h>
#include <Prey/GameDll/ark/iface/IArkAbilityListener.h>
#include <Prey/GameDll/ark/iface/IArkObjectiveStateListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerHealthListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerPsiListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerStatusListener.h>

struct ArkResponseFact;
class ICrySizer;
struct IGameToken;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkGlobalFacts.h
class ArkGlobalFacts : public IGameTokenEventListener, public IArkObjectiveStateListener, public IArkPlayerHealthListener, public IArkPlayerStatusListener, public IArkAbilityListener, public IArkPlayerPsiListener // Id=8013977 Size=72
{
public:
	std::vector<ArkResponseFact> m_facts;
	
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	void Reset() { FReset(this); }
	virtual void OnGameTokenEvent(EGameTokenEvent _event, IGameToken *_pGameToken);
	virtual void GetMemoryUsage(ICrySizer *pSizer) const;
	void UpdateConversationFact(uint64_t _conversationId, EArkConversationStatus _status) { FUpdateConversationFact(this,_conversationId,_status); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	virtual void OnObjectiveAssigned(uint64_t _objectiveId);
	virtual void OnObjectiveUnassigned(uint64_t _objectiveId);
	virtual void OnObjectiveCompleted(uint64_t _objectiveId);
	virtual void OnObjectiveFailed(uint64_t _objectiveId);
	virtual void OnTaskActivated(uint64_t _taskId);
	virtual void OnTaskDeactivated(uint64_t _taskId);
	virtual void OnTaskCompleted(uint64_t _taskId);
	virtual void OnTaskFailed(uint64_t _taskId);
	virtual void OnHealthChanged();
	virtual void OnPsiChanged();
	virtual void OnStatusChanged(uint64_t _statusId, bool _bActive);
	virtual void OnAbilityAdded(const uint64_t _abilityID);
    virtual void OnBecomeAlien();
	void ResetFacts() { FResetFacts(this); }
	ArkResponseFact &GetFact(uint64_t _id) { return FGetFactOv1(this,_id); }
	ArkResponseFact &GetFact(EArkResponseKey _key) { return FGetFactOv0(this,_key); }
	void UpdateToken(IGameToken *_pGameToken) { FUpdateToken(this,_pGameToken); }
	void UpdateTraumaFacts(bool _bSuitIntegrity) { FUpdateTraumaFacts(this,_bSuitIntegrity); }
	void UpdateNeuromodsUsed() { FUpdateNeuromodsUsed(this); }
	
#if 0
	std::vector<ArkResponseFact> const &GetFacts() const;
	bool IsSupportedTokenType(EFlowDataTypes arg0) const;
#endif
	
	static inline auto FInit = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488970);
	static inline auto FShutdown = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488FF0);
	static inline auto FReset = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488D30);
	static inline auto FOnGameTokenEvent = PreyFunction<void(ArkGlobalFacts *const _this, EGameTokenEvent _event, IGameToken *_pGameToken)>(0x1488A50);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkGlobalFacts const *const _this, ICrySizer *pSizer)>(0x1488920);
	static inline auto FUpdateConversationFact = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _conversationId, EArkConversationStatus _status)>(0x1489080);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488BD0);
	static inline auto FOnObjectiveAssigned = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _objectiveId)>(0x1488D10);
	static inline auto FOnObjectiveUnassigned = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _objectiveId)>(0x1488C50);
	static inline auto FOnObjectiveCompleted = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _objectiveId)>(0x1488C10);
	static inline auto FOnObjectiveFailed = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _objectiveId)>(0x1488C30);
	static inline auto FOnTaskActivated = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _taskId)>(0x1488C50);
	static inline auto FOnTaskDeactivated = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _taskId)>(0x1488D10);
	static inline auto FOnTaskCompleted = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _taskId)>(0x1488C10);
	static inline auto FOnTaskFailed = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _taskId)>(0x1488C30);
	static inline auto FOnHealthChanged = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488B40);
	static inline auto FOnPsiChanged = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488C70);
	static inline auto FOnStatusChanged = PreyFunction<void(ArkGlobalFacts *const _this, uint64_t _statusId, bool _bActive)>(0x1488D00);
	static inline auto FOnAbilityAdded = PreyFunction<void(ArkGlobalFacts *const _this, const uint64_t _abilityID)>(0x1488A40);
	static inline auto FResetFacts = PreyFunction<void(ArkGlobalFacts *const _this)>(0x1488DD0);
	static inline auto FGetFactOv1 = PreyFunction<ArkResponseFact &(ArkGlobalFacts *const _this, uint64_t _id)>(0x1488830);
	static inline auto FGetFactOv0 = PreyFunction<ArkResponseFact &(ArkGlobalFacts *const _this, EArkResponseKey _key)>(0x1488800);
	static inline auto FUpdateToken = PreyFunction<void(ArkGlobalFacts *const _this, IGameToken *_pGameToken)>(0x1489120);
	static inline auto FUpdateTraumaFacts = PreyFunction<void(ArkGlobalFacts *const _this, bool _bSuitIntegrity)>(0x14893F0);
	static inline auto FUpdateNeuromodsUsed = PreyFunction<void(ArkGlobalFacts *const _this)>(0x14890B0);
};

