// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/Containers/VectorMap.h>
#include <Prey/Ark/arkobjectiveutils.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkCharacterStatusListener.h>

class ArkFlowNodeObjectiveState;
class ArkFlowNodeTaskState;
class ArkObjective;
class ArkObjectiveTask;
namespace ArkObjectiveUtils
{
class CArkObjectiveClueData;
class CArkObjectiveData;
class CArkObjectiveDescriptionData;
class CArkObjectiveTaskData;
} // namespace ArkObjectiveUtils
enum class EArkTaskMarkerStyle;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SLabelMarker;
class XmlNodeRef;

// CArkTaskMarker
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class CArkTaskMarker
{ // Size=32 (0x20)
public:
	unsigned m_entityId;
	int64_t m_taskId;
	string m_levelName;
	float m_opaqueDistance;

	const IEntity* GetEntity() const { return FGetEntity(this); }
	static void UpdateTaskMarker(const IEntity* _pEntity, unsigned _actionscriptIdentifier, const ArkObjectiveTask* _pTask, const char* _overrideLabel, SLabelMarker& _labelMarker, float _opaqueDistance, float _textOpaqueDistance) { FUpdateTaskMarker(_pEntity, _actionscriptIdentifier, _pTask, _overrideLabel, _labelMarker, _opaqueDistance, _textOpaqueDistance); }

#if 0
	CArkTaskMarker();
	CArkTaskMarker(const string _arg0_, const IEntity& _arg1_, const int64_t _arg2_, const float _arg3_);
	void Show(EArkTaskMarkerStyle _arg0_) const;
	void Hide() const;
	unsigned GetEntityId() const;
	bool Update(SLabelMarker& _arg0_, const ArkObjectiveTask* _arg1_) const;
	void Serialize(TSerialize _arg0_);
	const string& GetLevelName() const;
#endif

	static inline auto FGetEntity = PreyFunction<const IEntity* (const CArkTaskMarker* const _this)>(0x1210510);
	static inline auto FUpdateTaskMarker = PreyFunction<void(const IEntity* _pEntity, unsigned _actionscriptIdentifier, const ArkObjectiveTask* _pTask, const char* _overrideLabel, SLabelMarker& _labelMarker, float _opaqueDistance, float _textOpaqueDistance)>(0x154A220);
};

// ArkObjectiveTask
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkObjectiveTask
{ // Size=80 (0x50)
public:
	std::vector<ArkFlowNodeTaskState*> m_stateFlowNodes;
	std::vector<CArkTaskMarker> m_markers;
	const ArkObjectiveUtils::CArkObjectiveTaskData* m_pData;
	uint64_t m_currentLocationId;
	unsigned m_transitionDoor;
	EArkObjectiveTaskState m_state;
	float m_fTimeRemaining;
	bool m_bShowTimerOnHud;

	const ArkObjectiveUtils::CArkObjectiveTaskData& GetData() const { return FGetData(this); }
	void SetDeactivated() { FSetDeactivated(this); }
	void SetCompleted() { FSetCompleted(this); }
	void SetFailed() { FSetFailed(this); }
	void SetMarker(const IEntity& _entity, const float _opaqueDistance) { FSetMarker(this, _entity, _opaqueDistance); }
	EArkObjectiveTaskState GetState() const { return FGetState(this); }
	void UpdateMarkers(SLabelMarker& _labelMarker) { FUpdateMarkers(this, _labelMarker); }
	void FlashMarkers() const { FFlashMarkers(this); }
	void HideMarkers() const { FHideMarkers(this); }
	float GetTimeRemaining() const { return FGetTimeRemaining(this); }
	const ArkObjective* GetObjective() const { return FGetObjective(this); }
	static wstring GetFormattedTaskTime(float _fTime) { return FGetFormattedTaskTime(_fTime); }

#if 0
	ArkObjectiveTask(const ArkObjectiveUtils::CArkObjectiveTaskData& _arg0_);
	void RegisterStateNode(ArkFlowNodeTaskState& _arg0_);
	void UnregisterStateNode(ArkFlowNodeTaskState& _arg0_);
	void SetData(const ArkObjectiveUtils::CArkObjectiveTaskData& _arg0_);
	void SetActivated();
	void ClearMarker(const IEntity& _arg0_);
	void ClearAllMarkers();
	void Update(float _arg0_);
	void ShowMarkers(const EArkTaskMarkerStyle _arg0_) const;
	void OnLevelLoadEnd(const bool _arg0_, const EArkTaskMarkerStyle _arg1_);
	void Serialize(TSerialize _arg0_);
	bool IsLocationDestination(const uint64_t _arg0_) const;
	void SetTimeRemaining(float _arg0_);
	void SetShowTimerOnHud(bool _arg0_);
	bool GetShowTimerOnHud() const;
	bool ShouldActivateTimer() const;
	uint64_t GetCurrentLocationId() const;
	void SetCurrentLocationId(const uint64_t _arg0_);
	void UpdateTransitionDoor(EArkTaskMarkerStyle _arg0_);
	unsigned GetTransitionDoor() const;
	const std::vector<CArkTaskMarker>& GetMarkers() const;
#endif

	static inline auto FGetData = PreyFunction<const ArkObjectiveUtils::CArkObjectiveTaskData& (const ArkObjectiveTask* const _this)>(0x862100);
	static inline auto FSetDeactivated = PreyFunction<void(ArkObjectiveTask* const _this)>(0x1548150);
	static inline auto FSetCompleted = PreyFunction<void(ArkObjectiveTask* const _this)>(0x1548070);
	static inline auto FSetFailed = PreyFunction<void(ArkObjectiveTask* const _this)>(0x1548230);
	static inline auto FSetMarker = PreyFunction<void(ArkObjectiveTask* const _this, const IEntity& _entity, const float _opaqueDistance)>(0x1548440);
	static inline auto FGetState = PreyFunction<EArkObjectiveTaskState(const ArkObjectiveTask* const _this)>(0x12BDB0);
	static inline auto FUpdateMarkers = PreyFunction<void(ArkObjectiveTask* const _this, SLabelMarker& _labelMarker)>(0x154A050);
	static inline auto FFlashMarkers = PreyFunction<void(const ArkObjectiveTask* const _this)>(0x1544F70);
	static inline auto FHideMarkers = PreyFunction<void(const ArkObjectiveTask* const _this)>(0x1545BB0);
	static inline auto FGetTimeRemaining = PreyFunction<float(const ArkObjectiveTask* const _this)>(0x86E780);
	static inline auto FGetObjective = PreyFunction<const ArkObjective* (const ArkObjectiveTask* const _this)>(0x15452E0);
	static inline auto FGetFormattedTaskTime = PreyFunction<wstring(float _fTime)>(0x1545110);
};

// CArkObjectiveClue
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class CArkObjectiveClue
{ // Size=16 (0x10)
public:
	bool m_bHidden;
	const ArkObjectiveUtils::CArkObjectiveClueData& m_data;

#if 0
	CArkObjectiveClue(const ArkObjectiveUtils::CArkObjectiveClueData& _arg0_);
	void SetHidden(const bool _arg0_);
	bool IsHidden() const;
	const ArkObjectiveUtils::CArkObjectiveClueData& GetData() const;
	void Serialize(TSerialize _arg0_);
#endif
};

// ArkObjective
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkObjective
{ // Size=136 (0x88)
public:
	std::vector<ArkFlowNodeObjectiveState*> m_stateFlowNodes;
	std::vector<ArkObjectiveTask> m_tasks;
	std::vector<CArkObjectiveClue> m_clues;
	std::list<ArkObjectiveUtils::CArkObjectiveTaskData,std::allocator<ArkObjectiveUtils::CArkObjectiveTaskData> > m_dynamicTasks;
	const ArkObjectiveUtils::CArkObjectiveData* m_pData;
	int64_t m_currentDescriptionId;
	EArkObjectiveState m_state;
	int64_t m_lastActiveTimerTask;
	int64_t m_dynamicTaskCounter;
	bool m_bTracked;

	const ArkObjectiveUtils::CArkObjectiveData& GetData() const { return FGetData(this); }
	void SetHidden() { FSetHidden(this); }
	void SetActive() { FSetActive(this); }
	const ArkObjectiveTask* FindTask(const int64_t _taskId) const { return FFindTaskOv1(this, _taskId); }
	ArkObjectiveTask* FindTask(const int64_t _taskId) { return FFindTaskOv0(this, _taskId); }
	EArkObjectiveState GetState() const { return FGetState(this); }
	bool IsLocationActiveDestination(const uint64_t _locationId) const { return FIsLocationActiveDestination(this, _locationId); }
	void ShowTaskNotifications() const { FShowTaskNotifications(this); }
	void HideMarkers() const { FHideMarkers(this); }
	const ArkObjectiveUtils::CArkObjectiveDescriptionData& GetDescription() const { return FGetDescription(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void RemoveTask(ArkObjectiveTask& _task) { FRemoveTask(this, _task); }
	void ShowLastActiveTimer() const { FShowLastActiveTimer(this); }
	void SetTracked(bool _bTracked) { FSetTracked(this, _bTracked); }

#if 0
	ArkObjective(const ArkObjectiveUtils::CArkObjectiveData& _arg0_);
	void SetDescription(const ArkObjectiveUtils::CArkObjectiveDescriptionData& _arg0_);
	void SetCompleted();
	void SetFailed();
	void RegisterStateNode(ArkFlowNodeObjectiveState& _arg0_);
	void UnregisterStateNode(ArkFlowNodeObjectiveState& _arg0_);
	const CArkObjectiveClue* FindClue(const int64_t _arg0_) const;
	CArkObjectiveClue* FindClue(const int64_t _arg0_);
	void Update(float _arg0_);
	void UpdateMarkers(SLabelMarker& _arg0_);
	void ShowMarkers(EArkTaskMarkerStyle _arg0_) const;
	void UpdateTransitionDoors(EArkTaskMarkerStyle _arg0_);
	std::vector<ArkObjectiveTask>& GetTasks();
	const std::vector<ArkObjectiveTask>& GetTasks() const;
	const std::vector<CArkObjectiveClue>& GetClues() const;
	void OnLevelLoadEnd(EArkTaskMarkerStyle _arg0_);
	void DeactivateTasks();
	const ArkObjectiveTask* AddTask(const XmlNodeRef _arg0_);
	void SetLastActiveTimerTask(int64_t _arg0_);
	int64_t GetLastActiveTimerTask() const;
	bool IsTracked() const;
#endif

	static inline auto FGetData = PreyFunction<const ArkObjectiveUtils::CArkObjectiveData& (const ArkObjective* const _this)>(0x1545000);
	static inline auto FSetHidden = PreyFunction<void(ArkObjective* const _this)>(0x1548310);
	static inline auto FSetActive = PreyFunction<void(ArkObjective* const _this)>(0x1547EB0);
	static inline auto FFindTaskOv1 = PreyFunction<const ArkObjectiveTask* (const ArkObjective* const _this, const int64_t _taskId)>(0x1544ED0);
	static inline auto FFindTaskOv0 = PreyFunction<ArkObjectiveTask* (ArkObjective* const _this, const int64_t _taskId)>(0x1544EA0);
	static inline auto FGetState = PreyFunction<EArkObjectiveState(const ArkObjective* const _this)>(0x3EBAF0);
	static inline auto FIsLocationActiveDestination = PreyFunction<bool(const ArkObjective* const _this, const uint64_t _locationId)>(0x1545FA0);
	static inline auto FShowTaskNotifications = PreyFunction<void(const ArkObjective* const _this)>(0x1548CA0);
	static inline auto FHideMarkers = PreyFunction<void(const ArkObjective* const _this)>(0x1545B20);
	static inline auto FGetDescription = PreyFunction<const ArkObjectiveUtils::CArkObjectiveDescriptionData& (const ArkObjective* const _this)>(0x1545010);
	static inline auto FSerialize = PreyFunction<void(ArkObjective* const _this, TSerialize _ser)>(0x1547860);
	static inline auto FRemoveTask = PreyFunction<void(ArkObjective* const _this, ArkObjectiveTask& _task)>(0x1546ED0);
	static inline auto FShowLastActiveTimer = PreyFunction<void(const ArkObjective* const _this)>(0x1548A00);
	static inline auto FSetTracked = PreyFunction<void(ArkObjective* const _this, bool _bTracked)>(0x1548800);
};

// ArkPathMapNode
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkPathMapNode
{ // Size=16 (0x10)
public:
	uint64_t m_source;
	uint64_t m_target;

#if 0
	ArkPathMapNode();
	ArkPathMapNode(const uint64_t _arg0_, const uint64_t _arg1_);
	bool operator==(const ArkPathMapNode& _arg0_) const;
	bool IsValid() const;
	uint64_t GetOtherLocation(const uint64_t _arg0_) const;
#endif
};

// ArkObjectiveComponent
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkObjectiveComponent : public IArkCharacterStatusListener, public IEntitySystemSink
{ // Size=352 (0x160)
public:
	using transitionDoorMap = std::unordered_map<uint64_t, unsigned int>;

	ArkObjectiveUtils::CArkObjectiveLib m_objectiveLib;
	std::vector<ArkObjective> m_objectives;
	int64_t m_trackingObjectiveId;
	int64_t m_lastClueObjectiveId;
	unsigned m_lastLabelMarker;
	Vec3 m_lastDoorUpdatePos;
	std::vector<int64_t> m_taskNotifications;
	std::unordered_map<uint64_t, unsigned int> m_transitionDoorsByLocation;
	VectorMap<unsigned int,enum EArkTaskMarkerStyle,std::less<unsigned int>,std::allocator<std::pair<unsigned int,enum EArkTaskMarkerStyle> > > m_markedTransitionDoors;
	std::unordered_map<unsigned int, unsigned int> m_taskMarkerOverrides;
	ArkSimpleTimer m_failPersonnelTaskTimer;
	unsigned m_failPersonnelTickCount;
	std::unordered_map<ArkPathMapNode, std::unordered_map<ArkPathMapNode, float>> m_cachedLocationCost;

	ArkObjectiveComponent();
	virtual ~ArkObjectiveComponent();
	void CreateObjectives() { FCreateObjectives(this); }
	void AssignObjective(const int64_t _objectiveId, const bool _bShowOnHUD) { FAssignObjective(this, _objectiveId, _bShowOnHUD); }
	void UnassignObjective(const int64_t _objectiveId) { FUnassignObjective(this, _objectiveId); }
	void CompleteObjective(const int64_t _objectiveId, const bool _bShowOnHUD) { FCompleteObjective(this, _objectiveId, _bShowOnHUD); }
	void FailObjective(const int64_t _objectiveId, const bool _bShowOnHUD) { FFailObjective(this, _objectiveId, _bShowOnHUD); }
	void SetObjectiveDescription(const int64_t _descriptionId) { FSetObjectiveDescription(this, _descriptionId); }
	void RegisterObjectiveStateNode(const int64_t _objectiveId, ArkFlowNodeObjectiveState& _rNode) { FRegisterObjectiveStateNode(this, _objectiveId, _rNode); }
	void UnregisterObjectiveStateNode(ArkFlowNodeObjectiveState& _node) { FUnregisterObjectiveStateNode(this, _node); }
	void RegisterTaskStateNode(const int64_t _taskId, ArkFlowNodeTaskState& _rNode) { FRegisterTaskStateNode(this, _taskId, _rNode); }
	void UnregisterTaskStateNode(ArkFlowNodeTaskState& _node) { FUnregisterTaskStateNode(this, _node); }
	void ActivateTask(const int64_t _taskId) { FActivateTask(this, _taskId); }
	void DeactivateTask(const int64_t _taskId) { FDeactivateTask(this, _taskId); }
	void CompleteTask(const int64_t _taskId) { FCompleteTask(this, _taskId); }
	void FailTask(const int64_t _taskId) { FFailTask(this, _taskId); }
	void Reset() { FReset(this); }
	void TriggerObjectiveNotification(int64_t _objectiveId) { FTriggerObjectiveNotification(this, _objectiveId); }
	void ShowTaskNotification(const int64_t _taskId) { FShowTaskNotification(this, _taskId); }
	void SetTaskMarker(const int64_t _taskId, const IEntity& _rEntity, const float _opaqueDistance) { FSetTaskMarker(this, _taskId, _rEntity, _opaqueDistance); }
	void ClearTaskMarker(const int64_t _taskId, const IEntity& _rEntity) { FClearTaskMarker(this, _taskId, _rEntity); }
	void OverrideTaskMarkerEntity(unsigned _markerEntity, unsigned _overrideEntity) { FOverrideTaskMarkerEntity(this, _markerEntity, _overrideEntity); }
	void ClearTaskMarkerOverride(unsigned _markerEntity) { FClearTaskMarkerOverride(this, _markerEntity); }
	IEntity* GetEntityForTaskMarker(unsigned _markerEntity) const { return FGetEntityForTaskMarker(this, _markerEntity); }
	void ClearAllMarkers(const int64_t _taskId) { FClearAllMarkers(this, _taskId); }
	void SetTaskLocation(const int64_t _taskId, const uint64_t _locationId) { FSetTaskLocation(this, _taskId, _locationId); }
	EArkObjectiveState GetObjectiveState(const int64_t _objectiveId) const { return FGetObjectiveState(this, _objectiveId); }
	EArkObjectiveTaskState GetTaskState(const int64_t _taskId) const { return FGetTaskState(this, _taskId); }
	void Update(const float _fDeltaTime) { FUpdate(this, _fDeltaTime); }
	void UpdateMarkers() { FUpdateMarkers(this); }
	bool IsLocatePersonnelObjective(const int64_t _objectiveId) const { return FIsLocatePersonnelObjective(this, _objectiveId); }
	void CleanUp() { FCleanUp(this); }
	const std::vector<ArkObjective>& GetObjectives() const { return FGetObjectives(this); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void OnLevelEnd() const { FOnLevelEnd(this); }
	static int GetObjectiveStateValueForUI(const ArkObjective& _objective) { return FGetObjectiveStateValueForUI(_objective); }
	static int GetTaskStateValueForUI(const ArkObjectiveTask& _task) { return FGetTaskStateValueForUI(_task); }
	static string GetLocationNameForUI(const ArkObjectiveTask& _task) { return FGetLocationNameForUI(_task); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void GetOrCreateTrackingTask(const uint64_t _characterId, const bool _bTrack) { FGetOrCreateTrackingTask(this, _characterId, _bTrack); }
	const ArkObjectiveTask* GetTaskForCharacter(const uint64_t _characterId) const { return FGetTaskForCharacterOv1(this, _characterId); }
	ArkObjectiveTask* GetTaskForCharacter(const uint64_t _characterId) { return FGetTaskForCharacterOv0(this, _characterId); }
	const ArkObjective* FindObjective(const int64_t _objectiveId) const { return FFindObjectiveOv1(this, _objectiveId); }
	ArkObjective* FindObjective(const int64_t _objectiveId) { return FFindObjectiveOv0(this, _objectiveId); }
	bool SetClueHidden(int64_t _clueId, bool _bHidden) { return FSetClueHidden(this, _clueId, _bHidden); }
	const ArkObjectiveTask* FindTask(const int64_t _taskId) const { return FFindTaskOv1(this, _taskId); }
	void SetTaskTimeRemaining(const int64_t _taskId, float _fTimeRemaining, bool _bShowOnHud) { FSetTaskTimeRemaining(this, _taskId, _fTimeRemaining, _bShowOnHud); }
	float GetTaskTimeRemaining(const int64_t _taskId) const { return FGetTaskTimeRemaining(this, _taskId); }
	void SetObjectiveTracked(int64_t _objectiveId, bool _bTracked) { FSetObjectiveTracked(this, _objectiveId, _bTracked); }
	std::vector<const ArkObjective*> GetTrackedObjectives() const { alignas(std::vector<const ArkObjective*>) std::byte _return_buf_[sizeof(std::vector<const ArkObjective*>)]; return *FGetTrackedObjectives(this, reinterpret_cast<std::vector<const ArkObjective*>*>(_return_buf_)); }
	void OnGameEnded() { FOnGameEnded(this); }
	ArkObjective* GetTrackingObjective() { return FGetTrackingObjective(this); }
	uint64_t FindNextLocation(const uint64_t _targetLocation) const { return FFindNextLocation(this, _targetLocation); }
	void ReevaluateTransitionDoors() { FReevaluateTransitionDoors(this); }
	void ResetPersonnelTaskFailTimer() { FResetPersonnelTaskFailTimer(this); }
	static void TogglePersonnelObjectiveForCharacter(const char* _characterIdString) { FTogglePersonnelObjectiveForCharacter(_characterIdString); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams& params);
	virtual void OnSpawn(IEntity* _pEntity, SEntitySpawnParams& params);
	virtual bool OnRemove(IEntity* _pEntity);
	virtual void OnReused(IEntity* _pEntity, SEntitySpawnParams& params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& event);
	bool UpdateLocatePersonnelObjectiveTaskMarker(const uint64_t _characterId, bool _bFailOnMissing) { return FUpdateLocatePersonnelObjectiveTaskMarker(this, _characterId, _bFailOnMissing); }
	void GotoLastClue() { FGotoLastClue(this); }
	virtual void OnCharacterStatusChanged(const uint64_t _characterId);
	virtual void OnCharacterDiscovered(const uint64_t _characterId, bool _bDiscovered);
	void UpdateTransitionDoorMarkers(VectorMap<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > >,std::less<unsigned int>,std::allocator<std::pair<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > > > > >& _markedDoors, SLabelMarker& _labelMarker) { FUpdateTransitionDoorMarkers(this, _markedDoors, _labelMarker); }
	void ClearMarkedTransitionDoors() { FClearMarkedTransitionDoors(this); }

#if 0
	bool RemoveTrackingTask(const uint64_t _arg0_);
	ArkObjectiveTask* FindTask(const int64_t _arg0_);
	void ToastAssignedStoryObjectives() const;
	int64_t GetTrackingObjectiveId() const;
	const std::unordered_map<uint64_t, unsigned int>& GetTransitionDoors() const;
	void OnTaskMarkerEntityRemoved(const int64_t _arg0_);
	EArkTaskMarkerStyle GetMarkerStyle(const ArkObjectiveUtils::CArkObjectiveData& _arg0_) const;
#endif

	static inline auto FArkObjectiveComponentOv1 = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x15419E0);
	static inline auto FBitNotArkObjectiveComponent = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1542400);
	static inline auto FCreateObjectives = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1543920);
	static inline auto FAssignObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _objectiveId, const bool _bShowOnHUD)>(0x15431E0);
	static inline auto FUnassignObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _objectiveId)>(0x1549020);
	static inline auto FCompleteObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _objectiveId, const bool _bShowOnHUD)>(0x15436C0);
	static inline auto FFailObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _objectiveId, const bool _bShowOnHUD)>(0x1543CF0);
	static inline auto FSetObjectiveDescription = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _descriptionId)>(0x1548540);
	static inline auto FRegisterObjectiveStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _objectiveId, ArkFlowNodeObjectiveState& _rNode)>(0x1546DA0);
	static inline auto FUnregisterObjectiveStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, ArkFlowNodeObjectiveState& _node)>(0x1549070);
	static inline auto FRegisterTaskStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId, ArkFlowNodeTaskState& _rNode)>(0x1546E20);
	static inline auto FUnregisterTaskStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, ArkFlowNodeTaskState& _node)>(0x15490E0);
	static inline auto FActivateTask = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1542FB0);
	static inline auto FDeactivateTask = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1543C30);
	static inline auto FCompleteTask = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1543860);
	static inline auto FFailTask = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1543E90);
	static inline auto FReset = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1546FB0);
	static inline auto FTriggerObjectiveNotification = PreyFunction<void(ArkObjectiveComponent* const _this, int64_t _objectiveId)>(0x1548FD0);
	static inline auto FShowTaskNotification = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1548B90);
	static inline auto FSetTaskMarker = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId, const IEntity& _rEntity, const float _opaqueDistance)>(0x1548700);
	static inline auto FClearTaskMarker = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId, const IEntity& _rEntity)>(0x1543590);
	static inline auto FOverrideTaskMarkerEntity = PreyFunction<void(ArkObjectiveComponent* const _this, unsigned _markerEntity, unsigned _overrideEntity)>(0x15468B0);
	static inline auto FClearTaskMarkerOverride = PreyFunction<void(ArkObjectiveComponent* const _this, unsigned _markerEntity)>(0x15436A0);
	static inline auto FGetEntityForTaskMarker = PreyFunction<IEntity* (const ArkObjectiveComponent* const _this, unsigned _markerEntity)>(0x1545040);
	static inline auto FClearAllMarkers = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1543310);
	static inline auto FSetTaskLocation = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId, const uint64_t _locationId)>(0x1548630);
	static inline auto FGetObjectiveState = PreyFunction<EArkObjectiveState(const ArkObjectiveComponent* const _this, const int64_t _objectiveId)>(0x1545360);
	static inline auto FGetTaskState = PreyFunction<EArkObjectiveTaskState(const ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x15455F0);
	static inline auto FUpdate = PreyFunction<void(ArkObjectiveComponent* const _this, const float _fDeltaTime)>(0x1549190);
	static inline auto FUpdateMarkers = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x15497C0);
	static inline auto FIsLocatePersonnelObjective = PreyFunction<bool(const ArkObjectiveComponent* const _this, const int64_t _objectiveId)>(0x1545F90);
	static inline auto FCleanUp = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1543280);
	static inline auto FGetObjectives = PreyFunction<const std::vector<ArkObjective>& (const ArkObjectiveComponent* const _this)>(0x10BDA70);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x15461F0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1546210);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1546740);
	static inline auto FOnLevelEnd = PreyFunction<void(const ArkObjectiveComponent* const _this)>(0x1546130);
	static inline auto FGetObjectiveStateValueForUI = PreyFunction<int(const ArkObjective& _objective)>(0x15453A0);
	static inline auto FGetTaskStateValueForUI = PreyFunction<int(const ArkObjectiveTask& _task)>(0x1545660);
	static inline auto FGetLocationNameForUI = PreyFunction<string(const ArkObjectiveTask& _task)>(0x1545200);
	static inline auto FSerialize = PreyFunction<void(ArkObjectiveComponent* const _this, TSerialize _ser)>(0x1547C90);
	static inline auto FPostSerialize = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1546A20);
	static inline auto FGetOrCreateTrackingTask = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _characterId, const bool _bTrack)>(0x15453C0);
	static inline auto FGetTaskForCharacterOv1 = PreyFunction<const ArkObjectiveTask* (const ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x15455E0);
	static inline auto FGetTaskForCharacterOv0 = PreyFunction<ArkObjectiveTask* (ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x1545560);
	static inline auto FFindObjectiveOv1 = PreyFunction<const ArkObjective* (const ArkObjectiveComponent* const _this, const int64_t _objectiveId)>(0x1544E70);
	static inline auto FFindObjectiveOv0 = PreyFunction<ArkObjective* (ArkObjectiveComponent* const _this, const int64_t _objectiveId)>(0x1544E30);
	static inline auto FSetClueHidden = PreyFunction<bool(ArkObjectiveComponent* const _this, int64_t _clueId, bool _bHidden)>(0x1547F80);
	static inline auto FFindTaskOv1 = PreyFunction<const ArkObjectiveTask* (const ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1544F00);
	static inline auto FSetTaskTimeRemaining = PreyFunction<void(ArkObjectiveComponent* const _this, const int64_t _taskId, float _fTimeRemaining, bool _bShowOnHud)>(0x1548780);
	static inline auto FGetTaskTimeRemaining = PreyFunction<float(const ArkObjectiveComponent* const _this, const int64_t _taskId)>(0x1545670);
	static inline auto FSetObjectiveTracked = PreyFunction<void(ArkObjectiveComponent* const _this, int64_t _objectiveId, bool _bTracked)>(0x15485A0);
	static inline auto FGetTrackedObjectives = PreyFunction<std::vector<const ArkObjective*>*(const ArkObjectiveComponent* const _this, std::vector<const ArkObjective*>* _return_value_)>(0x1545A30);
	static inline auto FOnGameEnded = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x15460F0);
	static inline auto FGetTrackingObjective = PreyFunction<ArkObjective* (ArkObjectiveComponent* const _this)>(0x1545AA0);
	static inline auto FFindNextLocation = PreyFunction<uint64_t(const ArkObjectiveComponent* const _this, const uint64_t _targetLocation)>(0x1543F50);
	static inline auto FReevaluateTransitionDoors = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1546CC0);
	static inline auto FResetPersonnelTaskFailTimer = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1547830);
	static inline auto FTogglePersonnelObjectiveForCharacter = PreyFunction<void(const char* _characterIdString)>(0x1548D60);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(IEntitySystemSink* const _this, SEntitySpawnParams& params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntitySpawnParams& params)>(0xA13080);
	static inline auto FOnRemove = PreyFunction<bool(IEntitySystemSink* const _this, IEntity* _pEntity)>(0x1546780);
	static inline auto FOnReused = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntitySpawnParams& params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntityEvent& event)>(0xA13080);
	static inline auto FUpdateLocatePersonnelObjectiveTaskMarker = PreyFunction<bool(ArkObjectiveComponent* const _this, const uint64_t _characterId, bool _bFailOnMissing)>(0x1549400);
	static inline auto FGotoLastClue = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1545AE0);
	static inline auto FOnCharacterStatusChanged = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x15460B0);
	static inline auto FOnCharacterDiscovered = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _characterId, bool _bDiscovered)>(0x1546040);
	static inline auto FUpdateTransitionDoorMarkers = PreyFunction<void(ArkObjectiveComponent* const _this, VectorMap<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > >,std::less<unsigned int>,std::allocator<std::pair<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > > > > >& _markedDoors, SLabelMarker& _labelMarker)>(0x154A930);
	static inline auto FClearMarkedTransitionDoors = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1543390);
};

namespace ArkObjectiveUtils
{

// ArkObjectiveUtils::CArkObjectiveDescriptionData
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class CArkObjectiveDescriptionData
{ // Size=24 (0x18)
public:
	int64_t m_id;
	string m_text;
	string m_displayName;

#if 0
	CArkObjectiveDescriptionData(const XmlNodeRef _arg0_);
	int64_t operator __int64();
	int64_t GetId() const;
	const string& GetDisplayName() const;
	const string& GetText() const;
#endif
};


} // namespace ArkObjectiveUtils
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/crystring.h>
#include <Prey/Ark/arkobjectiveutils.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/IArkCharacterStatusListener.h>
#include <_unknown/VectorMap.h>

class ArkFlowNodeObjectiveState;
class ArkFlowNodeTaskState;
class ArkObjective;
class ArkObjectiveTask;
namespace ArkObjectiveUtils
{
class CArkObjectiveClueData;
class CArkObjectiveData;
class CArkObjectiveDescriptionData;
class CArkObjectiveTaskData;
} // namespace ArkObjectiveUtils
enum class EArkTaskMarkerStyle;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;
struct SLabelMarker;
class XmlNodeRef;

// CArkTaskMarker
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class CArkTaskMarker
{ // Size=32 (0x20)
public:
	unsigned m_entityId;
	uint64_t m_taskId;
	string m_levelName;
	float m_opaqueDistance;

	const IEntity* GetEntity() const { return FGetEntity(this); }
	static void UpdateTaskMarker(const IEntity* _pEntity, unsigned _actionscriptIdentifier, const ArkObjectiveTask* _pTask, const char* _overrideLabel, SLabelMarker& _labelMarker, float _opaqueDistance, float _textOpaqueDistance) { FUpdateTaskMarker(_pEntity, _actionscriptIdentifier, _pTask, _overrideLabel, _labelMarker, _opaqueDistance, _textOpaqueDistance); }

#if 0
	CArkTaskMarker();
	CArkTaskMarker(const string _arg0_, const IEntity& _arg1_, const uint64_t _arg2_, const float _arg3_);
	void Show(EArkTaskMarkerStyle _arg0_) const;
	void Hide() const;
	unsigned GetEntityId() const;
	bool Update(SLabelMarker& _arg0_, const ArkObjectiveTask* _arg1_) const;
	void Serialize(TSerialize _arg0_);
	const string& GetLevelName() const;
#endif

	static inline auto FGetEntity = PreyFunction<const IEntity* (const CArkTaskMarker* const _this)>(0x129F6E0);
	static inline auto FUpdateTaskMarker = PreyFunction<void(const IEntity* _pEntity, unsigned _actionscriptIdentifier, const ArkObjectiveTask* _pTask, const char* _overrideLabel, SLabelMarker& _labelMarker, float _opaqueDistance, float _textOpaqueDistance)>(0x166CAB0);
};

// ArkObjectiveTask
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkObjectiveTask
{ // Size=80 (0x50)
public:
	std::vector<ArkFlowNodeTaskState*> m_stateFlowNodes;
	std::vector<CArkTaskMarker> m_markers;
	const ArkObjectiveUtils::CArkObjectiveTaskData* m_pData;
	uint64_t m_currentLocationId;
	unsigned m_transitionDoor;
	EArkObjectiveTaskState m_state;
	float m_fTimeRemaining;
	bool m_bShowTimerOnHud;

	const ArkObjectiveUtils::CArkObjectiveTaskData& GetData() const { return FGetData(this); }
	void SetDeactivated() { FSetDeactivated(this); }
	void SetCompleted() { FSetCompleted(this); }
	void SetFailed() { FSetFailed(this); }
	void SetMarker(const IEntity& _entity, const float _opaqueDistance) { FSetMarker(this, _entity, _opaqueDistance); }
	EArkObjectiveTaskState GetState() const { return FGetState(this); }
	void UpdateMarkers(SLabelMarker& _labelMarker) { FUpdateMarkers(this, _labelMarker); }
	void FlashMarkers() const { FFlashMarkers(this); }
	void HideMarkers() const { FHideMarkers(this); }
	float GetTimeRemaining() const { return FGetTimeRemaining(this); }
	const ArkObjective* GetObjective() const { return FGetObjective(this); }
	static wstring GetFormattedTaskTime(float _fTime) { return FGetFormattedTaskTime(_fTime); }

#if 0
	ArkObjectiveTask(const ArkObjectiveUtils::CArkObjectiveTaskData& _arg0_);
	void RegisterStateNode(ArkFlowNodeTaskState& _arg0_);
	void UnregisterStateNode(ArkFlowNodeTaskState& _arg0_);
	void SetData(const ArkObjectiveUtils::CArkObjectiveTaskData& _arg0_);
	void SetActivated();
	void ClearMarker(const IEntity& _arg0_);
	void ClearAllMarkers();
	void Update(float _arg0_);
	void ShowMarkers(const EArkTaskMarkerStyle _arg0_) const;
	void OnLevelLoadEnd(const bool _arg0_, const EArkTaskMarkerStyle _arg1_);
	void Serialize(TSerialize _arg0_);
	bool IsLocationDestination(const uint64_t _arg0_) const;
	void SetTimeRemaining(float _arg0_);
	void SetShowTimerOnHud(bool _arg0_);
	bool GetShowTimerOnHud() const;
	bool ShouldActivateTimer() const;
	uint64_t GetCurrentLocationId() const;
	void SetCurrentLocationId(const uint64_t _arg0_);
	void UpdateTransitionDoor(EArkTaskMarkerStyle _arg0_);
	unsigned GetTransitionDoor() const;
	const std::vector<CArkTaskMarker>& GetMarkers() const;
#endif

	static inline auto FGetData = PreyFunction<const ArkObjectiveUtils::CArkObjectiveTaskData& (const ArkObjectiveTask* const _this)>(0x19B580);
	static inline auto FSetDeactivated = PreyFunction<void(ArkObjectiveTask* const _this)>(0x166A7B0);
	static inline auto FSetCompleted = PreyFunction<void(ArkObjectiveTask* const _this)>(0x166A680);
	static inline auto FSetFailed = PreyFunction<void(ArkObjectiveTask* const _this)>(0x166A890);
	static inline auto FSetMarker = PreyFunction<void(ArkObjectiveTask* const _this, const IEntity& _entity, const float _opaqueDistance)>(0x166AAA0);
	static inline auto FGetState = PreyFunction<EArkObjectiveTaskState(const ArkObjectiveTask* const _this)>(0xFFD010);
	static inline auto FUpdateMarkers = PreyFunction<void(ArkObjectiveTask* const _this, SLabelMarker& _labelMarker)>(0x166C8E0);
	static inline auto FFlashMarkers = PreyFunction<void(const ArkObjectiveTask* const _this)>(0x1666660);
	static inline auto FHideMarkers = PreyFunction<void(const ArkObjectiveTask* const _this)>(0x16678D0);
	static inline auto FGetTimeRemaining = PreyFunction<float(const ArkObjectiveTask* const _this)>(0xE11930);
	static inline auto FGetObjective = PreyFunction<const ArkObjective* (const ArkObjectiveTask* const _this)>(0x16669F0);
	static inline auto FGetFormattedTaskTime = PreyFunction<wstring(float _fTime)>(0x1666810);
};

// CArkObjectiveClue
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class CArkObjectiveClue
{ // Size=16 (0x10)
public:
	bool m_bHidden;
	const ArkObjectiveUtils::CArkObjectiveClueData& m_data;

#if 0
	CArkObjectiveClue(const ArkObjectiveUtils::CArkObjectiveClueData& _arg0_);
	void SetHidden(const bool _arg0_);
	bool IsHidden() const;
	const ArkObjectiveUtils::CArkObjectiveClueData& GetData() const;
	void Serialize(TSerialize _arg0_);
#endif
};

// ArkObjective
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkObjective
{ // Size=128 (0x80)
public:
	std::vector<ArkFlowNodeObjectiveState*> m_stateFlowNodes;
	std::vector<ArkObjectiveTask> m_tasks;
	std::vector<CArkObjectiveClue> m_clues;
	std::list<ArkObjectiveUtils::CArkObjectiveDynamicTaskData,std::allocator<ArkObjectiveUtils::CArkObjectiveDynamicTaskData> > m_dynamicTasks;
	const ArkObjectiveUtils::CArkObjectiveData* m_pData;
	uint64_t m_currentDescriptionId;
	EArkObjectiveState m_state;
	uint64_t m_lastActiveTimerTask;
	bool m_bTracked;

	const ArkObjectiveUtils::CArkObjectiveData& GetData() const { return FGetData(this); }
	void SetHidden() { FSetHidden(this); }
	void SetActive() { FSetActive(this); }
	void SetCompleted() { FSetCompleted(this); }
	const ArkObjectiveTask* FindTask(const uint64_t _taskId) const { return FFindTaskOv1(this, _taskId); }
	ArkObjectiveTask* FindTask(const uint64_t _taskId) { return FFindTaskOv0(this, _taskId); }
	EArkObjectiveState GetState() const { return FGetState(this); }
	bool IsLocationActiveDestination(const uint64_t _locationId) const { return FIsLocationActiveDestination(this, _locationId); }
	void ShowTaskNotifications() const { FShowTaskNotifications(this); }
	void HideMarkers() const { FHideMarkers(this); }
	const ArkObjectiveUtils::CArkObjectiveDescriptionData& GetDescription() const { return FGetDescription(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void DeactivateTasks() { FDeactivateTasks(this); }
	const ArkObjectiveTask* AddTask(const XmlNodeRef _node, uint64_t _taskId) { return FAddTask(this, _node, _taskId); }
	void RemoveTask(ArkObjectiveTask& _task) { FRemoveTask(this, _task); }
	void RemoveAllDynamicTasks() { FRemoveAllDynamicTasks(this); }
	void ShowLastActiveTimer() const { FShowLastActiveTimer(this); }
	void SetTracked(bool _bTracked) { FSetTracked(this, _bTracked); }

#if 0
	ArkObjective(const ArkObjectiveUtils::CArkObjectiveData& _arg0_);
	void SetDescription(const ArkObjectiveUtils::CArkObjectiveDescriptionData& _arg0_);
	void SetFailed();
	void Reset();
	void RegisterStateNode(ArkFlowNodeObjectiveState& _arg0_);
	void UnregisterStateNode(ArkFlowNodeObjectiveState& _arg0_);
	const CArkObjectiveClue* FindClue(const uint64_t _arg0_) const;
	CArkObjectiveClue* FindClue(const uint64_t _arg0_);
	void Update(float _arg0_);
	void UpdateMarkers(SLabelMarker& _arg0_);
	void ShowMarkers(EArkTaskMarkerStyle _arg0_) const;
	void UpdateTransitionDoors(EArkTaskMarkerStyle _arg0_);
	std::vector<ArkObjectiveTask>& GetTasks();
	const std::vector<ArkObjectiveTask>& GetTasks() const;
	const std::vector<CArkObjectiveClue>& GetClues() const;
	void OnLevelLoadEnd(EArkTaskMarkerStyle _arg0_);
	void RemoveAllTasks();
	void SetLastActiveTimerTask(uint64_t _arg0_);
	uint64_t GetLastActiveTimerTask() const;
	bool IsTracked() const;
#endif

	static inline auto FGetData = PreyFunction<const ArkObjectiveUtils::CArkObjectiveData& (const ArkObjective* const _this)>(0x3E0300);
	static inline auto FSetHidden = PreyFunction<void(ArkObjective* const _this)>(0x166A970);
	static inline auto FSetActive = PreyFunction<void(ArkObjective* const _this)>(0x166A310);
	static inline auto FSetCompleted = PreyFunction<void(ArkObjective* const _this)>(0x166A4D0);
	static inline auto FFindTaskOv1 = PreyFunction<const ArkObjectiveTask* (const ArkObjective* const _this, const uint64_t _taskId)>(0x16665D0);
	static inline auto FFindTaskOv0 = PreyFunction<ArkObjectiveTask* (ArkObjective* const _this, const uint64_t _taskId)>(0x16665A0);
	static inline auto FGetState = PreyFunction<EArkObjectiveState(const ArkObjective* const _this)>(0xA55490);
	static inline auto FIsLocationActiveDestination = PreyFunction<bool(const ArkObjective* const _this, const uint64_t _locationId)>(0x1667CC0);
	static inline auto FShowTaskNotifications = PreyFunction<void(const ArkObjective* const _this)>(0x166B340);
	static inline auto FHideMarkers = PreyFunction<void(const ArkObjective* const _this)>(0x1667840);
	static inline auto FGetDescription = PreyFunction<const ArkObjectiveUtils::CArkObjectiveDescriptionData& (const ArkObjective* const _this)>(0x16666F0);
	static inline auto FSerialize = PreyFunction<void(ArkObjective* const _this, TSerialize _ser)>(0x1669A30);
	static inline auto FDeactivateTasks = PreyFunction<void(ArkObjective* const _this)>(0x1665280);
	static inline auto FAddTask = PreyFunction<const ArkObjectiveTask* (ArkObjective* const _this, const XmlNodeRef _node, uint64_t _taskId)>(0x16646C0);
	static inline auto FRemoveTask = PreyFunction<void(ArkObjective* const _this, ArkObjectiveTask& _task)>(0x1669070);
	static inline auto FRemoveAllDynamicTasks = PreyFunction<void(ArkObjective* const _this)>(0x1668F40);
	static inline auto FShowLastActiveTimer = PreyFunction<void(const ArkObjective* const _this)>(0x166B0E0);
	static inline auto FSetTracked = PreyFunction<void(ArkObjective* const _this, bool _bTracked)>(0x166AE70);
};

// ArkPathMapNode
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkPathMapNode
{ // Size=16 (0x10)
public:
	uint64_t m_source;
	uint64_t m_target;

#if 0
	ArkPathMapNode();
	ArkPathMapNode(const uint64_t _arg0_, const uint64_t _arg1_);
	bool operator==(const ArkPathMapNode& _arg0_) const;
	bool IsValid() const;
	uint64_t GetOtherLocation(const uint64_t _arg0_) const;
#endif
};

// ArkObjectiveComponent
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class ArkObjectiveComponent : public IArkCharacterStatusListener, public IEntitySystemSink
{ // Size=368 (0x170)
public:
	using transitionDoorMap = std::unordered_map<uint64_t, unsigned int>;

	ArkObjectiveUtils::CArkObjectiveLib m_objectiveLib;
	std::vector<ArkObjective> m_objectives;
	uint64_t m_trackingObjectiveId;
	uint64_t m_bountyObjectiveId;
	uint64_t m_lastClueObjectiveId;
	uint64_t m_dynamicTaskCounter;
	unsigned m_lastLabelMarker;
	Vec3 m_lastDoorUpdatePos;
	std::vector<uint64_t> m_taskNotifications;
	std::unordered_map<uint64_t, unsigned int> m_transitionDoorsByLocation;
	VectorMap<unsigned int,enum EArkTaskMarkerStyle,std::less<unsigned int>,std::allocator<std::pair<unsigned int,enum EArkTaskMarkerStyle> > > m_markedTransitionDoors;
	std::unordered_map<unsigned int, unsigned int> m_taskMarkerOverrides;
	ArkSimpleTimer m_failPersonnelTaskTimer;
	unsigned m_failPersonnelTickCount;
	std::unordered_map<ArkPathMapNode, std::unordered_map<ArkPathMapNode, float>> m_cachedLocationCost;

	ArkObjectiveComponent();
	virtual ~ArkObjectiveComponent();
	void CreateObjectives() { FCreateObjectives(this); }
	void AssignObjective(const uint64_t _objectiveId, const bool _bShowOnHUD) { FAssignObjective(this, _objectiveId, _bShowOnHUD); }
	void UnassignObjective(const uint64_t _objectiveId) { FUnassignObjective(this, _objectiveId); }
	void CompleteObjective(const uint64_t _objectiveId, const bool _bShowOnHUD) { FCompleteObjective(this, _objectiveId, _bShowOnHUD); }
	void FailObjective(const uint64_t _objectiveId, const bool _bShowOnHUD) { FFailObjective(this, _objectiveId, _bShowOnHUD); }
	void ResetObjective(const uint64_t _objectiveId) { FResetObjective(this, _objectiveId); }
	void SetObjectiveDescription(const uint64_t _descriptionId) { FSetObjectiveDescription(this, _descriptionId); }
	void RegisterObjectiveStateNode(const uint64_t _objectiveId, ArkFlowNodeObjectiveState& _rNode) { FRegisterObjectiveStateNode(this, _objectiveId, _rNode); }
	void UnregisterObjectiveStateNode(ArkFlowNodeObjectiveState& _node) { FUnregisterObjectiveStateNode(this, _node); }
	void RegisterTaskStateNode(const uint64_t _taskId, ArkFlowNodeTaskState& _rNode) { FRegisterTaskStateNode(this, _taskId, _rNode); }
	void UnregisterTaskStateNode(ArkFlowNodeTaskState& _node) { FUnregisterTaskStateNode(this, _node); }
	void ActivateTask(const uint64_t _taskId) { FActivateTask(this, _taskId); }
	void DeactivateTask(const uint64_t _taskId) { FDeactivateTask(this, _taskId); }
	void CompleteTask(const uint64_t _taskId) { FCompleteTask(this, _taskId); }
	void FailTask(const uint64_t _taskId) { FFailTask(this, _taskId); }
	void Reset() { FReset(this); }
	void TriggerObjectiveNotification(uint64_t _objectiveId) { FTriggerObjectiveNotification(this, _objectiveId); }
	void ShowTaskNotification(const uint64_t _taskId) { FShowTaskNotification(this, _taskId); }
	void SetTaskMarker(const uint64_t _taskId, const IEntity& _rEntity, const float _opaqueDistance) { FSetTaskMarker(this, _taskId, _rEntity, _opaqueDistance); }
	void ClearTaskMarker(const uint64_t _taskId, const IEntity& _rEntity) { FClearTaskMarker(this, _taskId, _rEntity); }
	void OverrideTaskMarkerEntity(unsigned _markerEntity, unsigned _overrideEntity) { FOverrideTaskMarkerEntity(this, _markerEntity, _overrideEntity); }
	void ClearTaskMarkerOverride(unsigned _markerEntity) { FClearTaskMarkerOverride(this, _markerEntity); }
	IEntity* GetEntityForTaskMarker(unsigned _markerEntity) const { return FGetEntityForTaskMarker(this, _markerEntity); }
	void ClearAllMarkers(const uint64_t _taskId) { FClearAllMarkers(this, _taskId); }
	void SetTaskLocation(const uint64_t _taskId, const uint64_t _locationId) { FSetTaskLocation(this, _taskId, _locationId); }
	EArkObjectiveState GetObjectiveState(const uint64_t _objectiveId) const { return FGetObjectiveState(this, _objectiveId); }
	EArkObjectiveTaskState GetTaskState(const uint64_t _taskId) const { return FGetTaskState(this, _taskId); }
	void Update(const float _fDeltaTime) { FUpdate(this, _fDeltaTime); }
	void UpdateMarkers() { FUpdateMarkers(this); }
	bool IsLocatePersonnelObjective(const uint64_t _objectiveId) const { return FIsLocatePersonnelObjective(this, _objectiveId); }
	void CleanUp() { FCleanUp(this); }
	const std::vector<ArkObjective>& GetObjectives() const { return FGetObjectives(this); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void OnLevelEnd() const { FOnLevelEnd(this); }
	static int GetObjectiveStateValueForUI(const ArkObjective& _objective) { return FGetObjectiveStateValueForUI(_objective); }
	static int GetTaskStateValueForUI(const ArkObjectiveTask& _task) { return FGetTaskStateValueForUI(_task); }
	static string GetLocationNameForUI(const ArkObjectiveTask& _task) { return FGetLocationNameForUI(_task); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void GetOrCreateTrackingTask(const uint64_t _characterId, const bool _bTrack) { FGetOrCreateTrackingTask(this, _characterId, _bTrack); }
	const ArkObjectiveTask* GetTaskForCharacter(const uint64_t _characterId) const { return FGetTaskForCharacterOv1(this, _characterId); }
	ArkObjectiveTask* GetTaskForCharacter(const uint64_t _characterId) { return FGetTaskForCharacterOv0(this, _characterId); }
	const ArkObjective* FindObjective(const uint64_t _objectiveId) const { return FFindObjectiveOv1(this, _objectiveId); }
	ArkObjective* FindObjective(const uint64_t _objectiveId) { return FFindObjectiveOv0(this, _objectiveId); }
	bool SetClueHidden(uint64_t _clueId, bool _bHidden) { return FSetClueHidden(this, _clueId, _bHidden); }
	const ArkObjectiveTask* FindTask(const uint64_t _taskId) const { return FFindTaskOv1(this, _taskId); }
	void SetTaskTimeRemaining(const uint64_t _taskId, float _fTimeRemaining, bool _bShowOnHud) { FSetTaskTimeRemaining(this, _taskId, _fTimeRemaining, _bShowOnHud); }
	float GetTaskTimeRemaining(const uint64_t _taskId) const { return FGetTaskTimeRemaining(this, _taskId); }
	void SetObjectiveTracked(uint64_t _objectiveId, bool _bTracked) { FSetObjectiveTracked(this, _objectiveId, _bTracked); }
	std::vector<const ArkObjective*> GetTrackedObjectives() const { alignas(std::vector<const ArkObjective*>) std::byte _return_buf_[sizeof(std::vector<const ArkObjective*>)]; return *FGetTrackedObjectives(this, reinterpret_cast<std::vector<const ArkObjective*>*>(_return_buf_)); }
	void OnGameEnded() { FOnGameEnded(this); }
	ArkObjective* GetTrackingObjective() { return FGetTrackingObjective(this); }
	void StartNewBounty(const string& _verb, uint64_t _weapon, uint64_t _target) { FStartNewBounty(this, _verb, _weapon, _target); }
	void MarkBountyComplete() { FMarkBountyComplete(this); }
	void ClearBountyHistory() { FClearBountyHistory(this); }
	void DeactivateBounties() { FDeactivateBounties(this); }
	uint64_t FindNextLocation(const uint64_t _targetLocation) const { return FFindNextLocation(this, _targetLocation); }
	void ReevaluateTransitionDoors() { FReevaluateTransitionDoors(this); }
	void ResetPersonnelTaskFailTimer() { FResetPersonnelTaskFailTimer(this); }
	const ArkObjective* FindCharacterObjective(const uint64_t _characterId) const { return FFindCharacterObjective(this, _characterId); }
	static void TogglePersonnelObjectiveForCharacter(const uint64_t _characterId) { FTogglePersonnelObjectiveForCharacter(_characterId); }
	void OnPlayableCharacterChanged(uint64_t _characterId) { FOnPlayableCharacterChanged(this, _characterId); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams& params);
	virtual void OnSpawn(IEntity* _pEntity, SEntitySpawnParams& params);
	virtual bool OnRemove(IEntity* _pEntity);
	virtual void OnReused(IEntity* _pEntity, SEntitySpawnParams& params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& event);
	bool UpdateLocatePersonnelObjectiveTaskMarker(const uint64_t _characterId, bool _bFailOnMissing) { return FUpdateLocatePersonnelObjectiveTaskMarker(this, _characterId, _bFailOnMissing); }
	void GotoLastClue() { FGotoLastClue(this); }
	virtual void OnCharacterStatusChanged(const uint64_t _characterId);
	virtual void OnCharacterDiscovered(const uint64_t _characterId, bool _bDiscovered);
	void UpdateTransitionDoorMarkers(VectorMap<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > >,std::less<unsigned int>,std::allocator<std::pair<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > > > > >& _markedDoors, SLabelMarker& _labelMarker) { FUpdateTransitionDoorMarkers(this, _markedDoors, _labelMarker); }
	void ClearMarkedTransitionDoors() { FClearMarkedTransitionDoors(this); }

#if 0
	bool RemoveTrackingTask(const uint64_t _arg0_);
	ArkObjectiveTask* FindTask(const uint64_t _arg0_);
	void ToastAssignedStoryObjectives() const;
	uint64_t GetTrackingObjectiveId() const;
	uint64_t GetBountyObjectiveId() const;
	const std::unordered_map<uint64_t, unsigned int>& GetTransitionDoors() const;
	void OnTaskMarkerEntityRemoved(const uint64_t _arg0_);
	EArkTaskMarkerStyle GetMarkerStyle(const ArkObjectiveUtils::CArkObjectiveData& _arg0_) const;
	uint64_t GetNextDynamicTaskId();
	static int GetTaskMarkerPriority(EArkTaskMarkerStyle _arg0_);
#endif

	static inline auto FArkObjectiveComponentOv1 = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1662F00);
	static inline auto FBitNotArkObjectiveComponent = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1663810);
	static inline auto FCreateObjectives = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1664E90);
	static inline auto FAssignObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _objectiveId, const bool _bShowOnHUD)>(0x1664790);
	static inline auto FUnassignObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _objectiveId)>(0x166B8D0);
	static inline auto FCompleteObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _objectiveId, const bool _bShowOnHUD)>(0x1664D20);
	static inline auto FFailObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _objectiveId, const bool _bShowOnHUD)>(0x16653C0);
	static inline auto FResetObjective = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _objectiveId)>(0x1669980);
	static inline auto FSetObjectiveDescription = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _descriptionId)>(0x166ABB0);
	static inline auto FRegisterObjectiveStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _objectiveId, ArkFlowNodeObjectiveState& _rNode)>(0x1668E20);
	static inline auto FUnregisterObjectiveStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, ArkFlowNodeObjectiveState& _node)>(0x166B920);
	static inline auto FRegisterTaskStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId, ArkFlowNodeTaskState& _rNode)>(0x1668E90);
	static inline auto FUnregisterTaskStateNode = PreyFunction<void(ArkObjectiveComponent* const _this, ArkFlowNodeTaskState& _node)>(0x166B990);
	static inline auto FActivateTask = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x1664480);
	static inline auto FDeactivateTask = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x16651C0);
	static inline auto FCompleteTask = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x1664DD0);
	static inline auto FFailTask = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x1665570);
	static inline auto FReset = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1669130);
	static inline auto FTriggerObjectiveNotification = PreyFunction<void(ArkObjectiveComponent* const _this, uint64_t _objectiveId)>(0x166B880);
	static inline auto FShowTaskNotification = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x166B210);
	static inline auto FSetTaskMarker = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId, const IEntity& _rEntity, const float _opaqueDistance)>(0x166AD70);
	static inline auto FClearTaskMarker = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId, const IEntity& _rEntity)>(0x1664BF0);
	static inline auto FOverrideTaskMarkerEntity = PreyFunction<void(ArkObjectiveComponent* const _this, unsigned _markerEntity, unsigned _overrideEntity)>(0x1668920);
	static inline auto FClearTaskMarkerOverride = PreyFunction<void(ArkObjectiveComponent* const _this, unsigned _markerEntity)>(0x1664D00);
	static inline auto FGetEntityForTaskMarker = PreyFunction<IEntity* (const ArkObjectiveComponent* const _this, unsigned _markerEntity)>(0x1666720);
	static inline auto FClearAllMarkers = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x16648A0);
	static inline auto FSetTaskLocation = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId, const uint64_t _locationId)>(0x166ACA0);
	static inline auto FGetObjectiveState = PreyFunction<EArkObjectiveState(const ArkObjectiveComponent* const _this, const uint64_t _objectiveId)>(0x1666A70);
	static inline auto FGetTaskState = PreyFunction<EArkObjectiveTaskState(const ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x1666CF0);
	static inline auto FUpdate = PreyFunction<void(ArkObjectiveComponent* const _this, const float _fDeltaTime)>(0x166BA40);
	static inline auto FUpdateMarkers = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x166C050);
	static inline auto FIsLocatePersonnelObjective = PreyFunction<bool(const ArkObjectiveComponent* const _this, const uint64_t _objectiveId)>(0x1667CB0);
	static inline auto FCleanUp = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1664840);
	static inline auto FGetObjectives = PreyFunction<const std::vector<ArkObjective>& (const ArkObjectiveComponent* const _this)>(0x23E600);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x16680B0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x16680D0);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x16685B0);
	static inline auto FOnLevelEnd = PreyFunction<void(const ArkObjectiveComponent* const _this)>(0x1667FF0);
	static inline auto FGetObjectiveStateValueForUI = PreyFunction<int(const ArkObjective& _objective)>(0x1666AB0);
	static inline auto FGetTaskStateValueForUI = PreyFunction<int(const ArkObjectiveTask& _task)>(0x1666D60);
	static inline auto FGetLocationNameForUI = PreyFunction<string(const ArkObjectiveTask& _task)>(0x1666900);
	static inline auto FSerialize = PreyFunction<void(ArkObjectiveComponent* const _this, TSerialize _ser)>(0x1669E50);
	static inline auto FPostSerialize = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1668A90);
	static inline auto FGetOrCreateTrackingTask = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _characterId, const bool _bTrack)>(0x1666AD0);
	static inline auto FGetTaskForCharacterOv1 = PreyFunction<const ArkObjectiveTask* (const ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x1666CB0);
	static inline auto FGetTaskForCharacterOv0 = PreyFunction<ArkObjectiveTask* (ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x1666C30);
	static inline auto FFindObjectiveOv1 = PreyFunction<const ArkObjective* (const ArkObjectiveComponent* const _this, const uint64_t _objectiveId)>(0x1666570);
	static inline auto FFindObjectiveOv0 = PreyFunction<ArkObjective* (ArkObjectiveComponent* const _this, const uint64_t _objectiveId)>(0x1666540);
	static inline auto FSetClueHidden = PreyFunction<bool(ArkObjectiveComponent* const _this, uint64_t _clueId, bool _bHidden)>(0x166A3E0);
	static inline auto FFindTaskOv1 = PreyFunction<const ArkObjectiveTask* (const ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x1666600);
	static inline auto FSetTaskTimeRemaining = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _taskId, float _fTimeRemaining, bool _bShowOnHud)>(0x166ADF0);
	static inline auto FGetTaskTimeRemaining = PreyFunction<float(const ArkObjectiveComponent* const _this, const uint64_t _taskId)>(0x1666D70);
	static inline auto FSetObjectiveTracked = PreyFunction<void(ArkObjectiveComponent* const _this, uint64_t _objectiveId, bool _bTracked)>(0x166AC10);
	static inline auto FGetTrackedObjectives = PreyFunction<std::vector<const ArkObjective*>*(const ArkObjectiveComponent* const _this, std::vector<const ArkObjective*>* _return_value_)>(0x1667750);
	static inline auto FOnGameEnded = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1667FB0);
	static inline auto FGetTrackingObjective = PreyFunction<ArkObjective* (ArkObjectiveComponent* const _this)>(0x16677C0);
	static inline auto FStartNewBounty = PreyFunction<void(ArkObjectiveComponent* const _this, const string& _verb, uint64_t _weapon, uint64_t _target)>(0x166B410);
	static inline auto FMarkBountyComplete = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1667D60);
	static inline auto FClearBountyHistory = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1664920);
	static inline auto FDeactivateBounties = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x16650E0);
	static inline auto FFindNextLocation = PreyFunction<uint64_t(const ArkObjectiveComponent* const _this, const uint64_t _targetLocation)>(0x1665660);
	static inline auto FReevaluateTransitionDoors = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1668D30);
	static inline auto FResetPersonnelTaskFailTimer = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1669A00);
	static inline auto FFindCharacterObjective = PreyFunction<const ArkObjective* (const ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x1665630);
	static inline auto FTogglePersonnelObjectiveForCharacter = PreyFunction<void(const uint64_t _characterId)>(0x166B680);
	static inline auto FOnPlayableCharacterChanged = PreyFunction<void(ArkObjectiveComponent* const _this, uint64_t _characterId)>(0x16685F0);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(IEntitySystemSink* const _this, SEntitySpawnParams& params)>(0x1A302A0);
	static inline auto FOnSpawn = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FOnRemove = PreyFunction<bool(IEntitySystemSink* const _this, IEntity* _pEntity)>(0x16687F0);
	static inline auto FOnReused = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntitySpawnParams& params)>(0x1333E90);
	static inline auto FOnEvent = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntityEvent& event)>(0x1333E90);
	static inline auto FUpdateLocatePersonnelObjectiveTaskMarker = PreyFunction<bool(ArkObjectiveComponent* const _this, const uint64_t _characterId, bool _bFailOnMissing)>(0x166BCB0);
	static inline auto FGotoLastClue = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x1667800);
	static inline auto FOnCharacterStatusChanged = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _characterId)>(0x1667F70);
	static inline auto FOnCharacterDiscovered = PreyFunction<void(ArkObjectiveComponent* const _this, const uint64_t _characterId, bool _bDiscovered)>(0x1667F00);
	static inline auto FUpdateTransitionDoorMarkers = PreyFunction<void(ArkObjectiveComponent* const _this, VectorMap<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > >,std::less<unsigned int>,std::allocator<std::pair<unsigned int,std::vector<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle>,std::allocator<std::pair<ArkObjectiveTask const *,enum EArkTaskMarkerStyle> > > > > >& _markedDoors, SLabelMarker& _labelMarker)>(0x166D1C0);
	static inline auto FClearMarkedTransitionDoors = PreyFunction<void(ArkObjectiveComponent* const _this)>(0x16649F0);
};

namespace ArkObjectiveUtils
{

// ArkObjectiveUtils::CArkObjectiveDescriptionData
// Header:  Prey/GameDll/ark/player/ArkObjectiveComponent.h
class CArkObjectiveDescriptionData
{ // Size=24 (0x18)
public:
	uint64_t m_id;
	string m_text;
	string m_displayName;

#if 0
	CArkObjectiveDescriptionData(const XmlNodeRef _arg0_);
	uint64_t operator unsigned __int64();
	uint64_t GetId() const;
	const string& GetDisplayName() const;
	const string& GetText() const;
#endif
};


} // namespace ArkObjectiveUtils
#endif // !MOONCRASH
