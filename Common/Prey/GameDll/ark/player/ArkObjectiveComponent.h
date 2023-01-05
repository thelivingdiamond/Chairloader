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

