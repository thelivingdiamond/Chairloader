// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/iface/IArkAbilityListener.h>
#include <Prey/GameDll/ark/iface/IArkInventoryListener.h>
#include <Prey/GameDll/ark/iface/IArkObjectiveStateListener.h>
#include <Prey/GameDll/ark/player/IArkHUDListener.h>
#include <Prey/GameDll/ark/player/IArkPlayerCombatListener.h>

class ArkDelayedResult;
class ArkGameStateCondition;

// Header: FromCpp
// Prey/GameDll/ark/ArkGameStateConditionManager.h
class ArkGameStateConditionManager : public IArkInventoryListener, public IArkAbilityListener, public IArkObjectiveStateListener, public IArkHUDListener, public IArkPlayerCombatListener // Id=80166D1 Size=200
{
public:
	std::unordered_map<unsigned __int64,int> m_conditionExecutionCounts;
	std::vector<ArkConditionEvaluationData> m_triggers;
	std::vector<ArkGameStateCondition const *> m_enabledConditions;
	std::vector<std::pair<ArkGameStateCondition const *,bool>> m_delayedEnables;
	
	class DelayedResultEntry // Id=80166FA Size=24
	{
	public:
		ArkDelayedResult const *m_pDelayedResult;
		uint64_t m_parentCondition;
		ArkTimeRemaining m_timer;
		
		void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
		
		static inline auto FSerialize = PreyFunction<void(ArkGameStateConditionManager::DelayedResultEntry *const _this, TSerialize _ser)>(0x13C1D20);
	};

	std::vector<ArkGameStateConditionManager::DelayedResultEntry> m_delayedResults;
	
	void TriggerReevaluation(EArkConditionTriggerType _type) { FTriggerReevaluationOv3(this,_type); }
	void TriggerReevaluation(EArkConditionTriggerType _type, uint64_t _changeId) { FTriggerReevaluationOv2(this,_type,_changeId); }
	void TriggerReevaluation(EArkConditionTriggerType _type, unsigned _entityId) { FTriggerReevaluationOv1(this,_type,_entityId); }
	void TriggerReevaluation(EArkConditionTriggerType _type, uint64_t _archetypeId, unsigned _entityId) { FTriggerReevaluationOv0(this,_type,_archetypeId,_entityId); }
	void Init() { FInit(this); }
	void Shutdown() { FShutdown(this); }
	void Reset() { FReset(this); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	void OnGameEnded() { FOnGameEnded(this); }
	virtual void OnItemAdded(unsigned _itemId, unsigned _originalId);
	virtual void OnItemRemoved(unsigned _itemId);
	virtual void OnAbilityAdded(uint64_t _abilityID);
	virtual void OnObjectiveAssigned(uint64_t _objectiveId);
	virtual void OnObjectiveUnassigned(uint64_t _objectiveId);
	virtual void OnObjectiveCompleted(uint64_t _objectiveId);
	virtual void OnObjectiveFailed(uint64_t _objectiveId);
	virtual void OnTaskActivated(uint64_t _taskId);
	virtual void OnTaskDeactivated(uint64_t _taskId);
	virtual void OnTaskCompleted(uint64_t _taskId);
	virtual void OnTaskFailed(uint64_t _taskId);
	virtual void OnEntityUnderReticleChanged(const unsigned _oldEntity, const unsigned _newEntity);
	virtual void OnCombatChange(bool _bInCombat);
	void SetConditionEnabled(uint64_t _gameStateConditionId, bool _bEnable) { FSetConditionEnabled(this,_gameStateConditionId,_bEnable); }
	void ExecuteCondition(ArkGameStateCondition const &_condition) { FExecuteCondition(this,_condition); }
	
#if 0
	int GetExecutionCount(uint64_t arg0) const;
	void AddDelayedResult(ArkDelayedResult const *const arg0, uint64_t arg1);
	void BuildEnabledList();
#endif
	
	static inline auto FTriggerReevaluationOv3 = PreyFunction<void(ArkGameStateConditionManager *const _this, EArkConditionTriggerType _type)>(0x13C1FD0);
	static inline auto FTriggerReevaluationOv2 = PreyFunction<void(ArkGameStateConditionManager *const _this, EArkConditionTriggerType _type, uint64_t _changeId)>(0x13C2070);
	static inline auto FTriggerReevaluationOv1 = PreyFunction<void(ArkGameStateConditionManager *const _this, EArkConditionTriggerType _type, unsigned _entityId)>(0x13C2020);
	static inline auto FTriggerReevaluationOv0 = PreyFunction<void(ArkGameStateConditionManager *const _this, EArkConditionTriggerType _type, uint64_t _archetypeId, unsigned _entityId)>(0x13C20C0);
	static inline auto FInit = PreyFunction<void(ArkGameStateConditionManager *const _this)>(0x13C1540);
	static inline auto FShutdown = PreyFunction<void(ArkGameStateConditionManager *const _this)>(0x13C1F40);
	static inline auto FReset = PreyFunction<void(ArkGameStateConditionManager *const _this)>(0x13C18D0);
	static inline auto FUpdate = PreyFunction<void(ArkGameStateConditionManager *const _this, float _frameTime)>(0x13C2110);
	static inline auto FSerialize = PreyFunction<void(ArkGameStateConditionManager *const _this, TSerialize ser)>(0x13C19B0);
	static inline auto FOnGameEnded = PreyFunction<void(ArkGameStateConditionManager *const _this)>(0x13C16D0);
	static inline auto FOnItemAdded = PreyFunction<void(ArkGameStateConditionManager *const _this, unsigned _itemId, unsigned _originalId)>(0x13C16F0);
	static inline auto FOnItemRemoved = PreyFunction<void(ArkGameStateConditionManager *const _this, unsigned _itemId)>(0x13C1790);
	static inline auto FOnAbilityAdded = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _abilityID)>(0x13C15D0);
	static inline auto FOnObjectiveAssigned = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _objectiveId)>(0x13C1830);
	static inline auto FOnObjectiveUnassigned = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _objectiveId)>(0x13C1830);
	static inline auto FOnObjectiveCompleted = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _objectiveId)>(0x13C1830);
	static inline auto FOnObjectiveFailed = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _objectiveId)>(0x13C1830);
	static inline auto FOnTaskActivated = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _taskId)>(0x13C1880);
	static inline auto FOnTaskDeactivated = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _taskId)>(0x13C1880);
	static inline auto FOnTaskCompleted = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _taskId)>(0x13C1880);
	static inline auto FOnTaskFailed = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _taskId)>(0x13C1880);
	static inline auto FOnEntityUnderReticleChanged = PreyFunction<void(ArkGameStateConditionManager *const _this, const unsigned _oldEntity, const unsigned _newEntity)>(0x13C1670);
	static inline auto FOnCombatChange = PreyFunction<void(ArkGameStateConditionManager *const _this, bool _bInCombat)>(0x13C1620);
	static inline auto FSetConditionEnabled = PreyFunction<void(ArkGameStateConditionManager *const _this, uint64_t _gameStateConditionId, bool _bEnable)>(0x13C1EB0);
	static inline auto FExecuteCondition = PreyFunction<void(ArkGameStateConditionManager *const _this, ArkGameStateCondition const &_condition)>(0x13C1350);
};

