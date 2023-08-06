#pragma once

#include <Prey/CryCore/functor.h>


struct IGameObjectExtensionCreatorBase
{
	// <interfuscator:shuffle>
	virtual ~IGameObjectExtensionCreatorBase() {}
	virtual IGameObjectExtensionPtr Create() = 0;
	virtual void                    GetGameObjectExtensionRMIData(void** ppRMI, size_t* nCount) = 0;
	// </interfuscator:shuffle>
};
namespace ArkGameNoise
{
    struct Params;
} // namespace ArkGameNoise
class ArkGameNoiseLoudness;
class CTimeValue;
struct CryGUID;
struct IActionMapManager;
struct IActor;
struct IActorSystem;
class IArkSaveLoadSystem;
struct IBreakEventListener;
struct ICheckpointSystem;
struct ICooperativeAnimationManager;
class ICrySizer;
struct ICustomActionManager;
struct ICustomEventManager;
struct IDebugHistoryManager;
struct IDialogSystem;
struct IEffectSystem;
struct IEntity;
struct IEntityProxy;
struct IFlowSystem;
struct IForceFeedbackSystem;
struct IGameFrameworkListener;
struct IGameObject;
struct IGameObjectExtension;
struct IGameObjectSystem;
struct IGameRulesSystem;
struct IGameSessionHandler;
struct IGameStatistics;
struct IGameToEditorInterface;
struct IGameTokenSystem;
struct IGameVolumes;
struct IGameplayRecorder;
struct IItemSystem;
struct ILanQueryListener;
struct ILevelSystem;
struct ILoadGame;
struct IMannequin;
struct IMaterialEffects;
struct INetChannel;
struct INetContext;
struct INetNub;
struct IPersistantDebug;
struct IPhysicalEntity;
struct IPlayerProfileManager;
struct ISaveGame;
struct IScriptTable;
struct ISerializeHelper;
class ISharedParamsManager;
struct ISubtitleManager;
struct ISystem;
struct ITweakMenuController;
struct IUIDraw;
struct IViewSystem;
struct IVisualLog;
struct SGameContextParams;
struct SGameStartParams;
struct SSystemInitParams;
struct ICryUnknown;
struct SEntityTagParams;

enum EFRAMEWORKLISTENERPRIORITY
{
    //! Default priority should not be used unless you don't care about order (it will be called first).
    FRAMEWORKLISTENERPRIORITY_DEFAULT,

    //! Add your order somewhere here if you need to be called between one of them.
    FRAMEWORKLISTENERPRIORITY_GAME,
    FRAMEWORKLISTENERPRIORITY_HUD,
    FRAMEWORKLISTENERPRIORITY_MENU
};

struct IPersistantDebug
{
    virtual ~IPersistantDebug() {}
    virtual void Begin(const char* name, bool clear) = 0;
    virtual void AddSphere(const Vec3& pos, float radius, ColorF clr, float timeout) = 0;
    virtual void AddDirection(const Vec3& pos, float radius, const Vec3& dir, ColorF clr, float timeout) = 0;
    virtual void AddLine(const Vec3& pos1, const Vec3& pos2, ColorF clr, float timeout) = 0;
    virtual void AddPlanarDisc(const Vec3& pos, float innerRadius, float outerRadius, ColorF clr, float timeout) = 0;
    virtual void AddCone(const Vec3& pos, const Vec3& dir, float baseRadius, float height, ColorF clr, float timeout) = 0;
    virtual void AddCylinder(const Vec3& pos, const Vec3& dir, float radius, float height, ColorF clr, float timeout) = 0;
    virtual void Add2DText(const char* text, float size, ColorF clr, float timeout) = 0;
    virtual void AddText(float x, float y, float size, ColorF clr, float timeout, const char* fmt, ...) = 0;
    virtual void Add2DLine(float x1, float y1, float x2, float y2, ColorF clr, float timeout) = 0;
    virtual void AddQuat(const Vec3& pos, const Quat& q, float r, ColorF clr, float timeout) = 0;
    virtual void AddAABB(const Vec3& min, const Vec3& max, ColorF clr, float timeout) = 0;
    virtual void AddEntityTag(const SEntityTagParams& params, const char* tagContext) = 0;
    virtual void ClearEntityTags(unsigned entityId) = 0;
    virtual void ClearStaticTag(unsigned entityId, const char* staticId) = 0;
    virtual void ClearTagContext(const char* tagContext) = 0;
    virtual void ClearTagContext(const char* tagContext, unsigned entityId) = 0;
    virtual void Reset() = 0;
};

static const EntityId LOCAL_PLAYER_ENTITY_ID = 0x7777u; //!< 30583 between static and dynamic EntityIDs.

//! When you add stuff here, you must also update in CCryAction::Init.
enum EGameFrameworkEvent
{
    eGFE_PauseGame = 0,
    eGFE_ResumeGame = 1,
    eGFE_OnCollision = 2,
    eGFE_OnPostStep = 3,
    eGFE_OnStateChange = 4,
    eGFE_ResetAnimationGraphs = 5,
    eGFE_OnBreakable2d = 6,
    eGFE_OnBecomeVisible = 7,
    eGFE_PreShatter = 8,
    eGFE_BecomeLocalPlayer = 9,
    eGFE_DisablePhysics = 10,
    eGFE_EnablePhysics = 11,
    eGFE_ScriptEvent = 12,
    eGFE_StoodOnChange = 13,
    eGFE_QueueRagdollCreation = 14,
    eGFE_QueueBlendFromRagdoll = 15,
    eGFE_RagdollPhysicalized = 16,
    eGFE_RagdollUnPhysicalized = 17,
    eGFE_EnableBlendRagdoll = 18,
    eGFE_DisableBlendRagdoll = 19,
    eGFE_BlendFromRagdollFinish = 20,
    eGFE_AIActive = 21,
    eGFE_AIInactive = 22,

    eGFE_Last = 23,
};

// Header: MadeUp
// _unknown/IGameFramework.h
struct IGameFramework // Id=8001CF0 Size=8
{
    struct IActorCreator : public IGameObjectExtensionCreatorBase // Id=8001E4B Size=8
    {
        virtual ~IActorCreator();
    };

    struct IItemCreator : public IGameObjectExtensionCreatorBase // Id=8001E4C Size=8
    {
        virtual ~IItemCreator();
    };

    struct IGameObjectExtensionCreator : public IGameObjectExtensionCreatorBase // Id=8001E4D Size=8
    {
        virtual ~IGameObjectExtensionCreator();
    };

    using TimerID = unsigned;
    using TimerCallback = Functor2<void *,unsigned int>;
    using TEntryFunction = IGameFramework *(*)();

    virtual void RegisterFactory(const char *arg0, ISaveGame *(*arg1)(), bool arg2) = 0;
    virtual void RegisterFactory(const char *arg0, ILoadGame *(*arg1)(), bool arg2) = 0;
    virtual void RegisterFactory(const char *arg0, IGameFramework::IActorCreator *arg1, bool arg2) = 0;
    virtual void RegisterFactory(const char *arg0, IGameFramework::IItemCreator *arg1, bool arg2) = 0;
    virtual void RegisterFactory(const char *arg0, IGameFramework::IGameObjectExtensionCreator *arg1, bool arg2) = 0;
    virtual ~IGameFramework() = default;
    virtual bool Init(SSystemInitParams &arg0) = 0;
    virtual void InitGameType(bool arg0, bool arg1) = 0;
    virtual bool CompleteInit() = 0;
    virtual void Shutdown() = 0;
    virtual bool PreUpdate(bool arg0, unsigned arg1) = 0;
    virtual void PostUpdate(bool arg0, unsigned arg1) = 0;
    virtual void Reset(bool arg0) = 0;
    virtual void PauseGame(bool pause, bool force, unsigned nFadeOutMS, bool bPauseAudio) = 0;
    virtual bool IsGamePaused() = 0;
    virtual bool IsGameStarted() = 0;
    virtual bool IsLevelPrecachingDone() const = 0;
    virtual void SetLevelPrecachingDone(bool arg0) = 0;
    virtual ISystem *GetISystem() = 0;
    virtual ILanQueryListener *GetILanQueryListener() = 0;
    virtual IUIDraw *GetIUIDraw() = 0;
    virtual IMannequin &GetMannequinInterface() = 0;
    virtual IGameObjectSystem *GetIGameObjectSystem() = 0;
    virtual ILevelSystem *GetILevelSystem() = 0;
    virtual IActorSystem *GetIActorSystem() = 0;
    virtual IItemSystem *GetIItemSystem() = 0;
    virtual IActionMapManager *GetIActionMapManager() = 0;
    virtual IViewSystem *GetIViewSystem() = 0;
    virtual IGameplayRecorder *GetIGameplayRecorder() = 0;
    virtual IGameRulesSystem *GetIGameRulesSystem() = 0;
    virtual IFlowSystem *GetIFlowSystem() = 0;
    virtual IGameTokenSystem *GetIGameTokenSystem() = 0;
    virtual IEffectSystem *GetIEffectSystem() = 0;
    virtual IMaterialEffects *GetIMaterialEffects() = 0;
    virtual IDialogSystem *GetIDialogSystem() = 0;
    virtual IPlayerProfileManager *GetIPlayerProfileManager() = 0;
    virtual ISubtitleManager *GetISubtitleManager() = 0;
    virtual ITweakMenuController *CreateITweakMenuController() = 0;
    virtual IGameStatistics *GetIGameStatistics() = 0;
    virtual IVisualLog *GetIVisualLog() = 0;
    virtual ICooperativeAnimationManager *GetICooperativeAnimationManager() = 0;
    virtual ICheckpointSystem *GetICheckpointSystem() = 0;
    virtual IForceFeedbackSystem *GetIForceFeedbackSystem() const = 0;
    virtual ICustomActionManager *GetICustomActionManager() const = 0;
    virtual ICustomEventManager *GetICustomEventManager() const = 0;
    virtual IGameSessionHandler *GetIGameSessionHandler() = 0;
    virtual ISharedParamsManager *GetISharedParamsManager() = 0;
    virtual bool StartGameContext(SGameStartParams const *arg0) = 0;
    virtual bool ChangeGameContext(SGameContextParams const *arg0) = 0;
    virtual void EndGameContext() = 0;
    virtual bool StartedGameContext() const = 0;
    virtual bool StartingGameContext() const = 0;
    virtual void SetGameSessionHandler(IGameSessionHandler *arg0) = 0;
    virtual bool BlockingSpawnPlayer() = 0;
    virtual void FlushBreakableObjects() = 0;
    virtual void ResetBrokenGameObjects() = 0;
    virtual IEntityProxy *CreateGameObject(unsigned arg0) = 0;
    virtual void RegisterProjectileExtension(const char *arg0) = 0;
    virtual void DeleteAllProjectiles() = 0;
    virtual IArkSaveLoadSystem &GetArkSaveLoadSystem() = 0;
    virtual void OnGameModeChanged() const = 0;
    virtual void ReloadArkGameNoises() = 0;
    virtual void EmitArkGameNoise(unsigned arg0, Vec3 const &arg1, ArkGameNoise::Params const &arg2) const = 0;
    virtual ArkGameNoiseLoudness const *FindArkGameNoiseLoudness(uint64_t arg0) const = 0;
    virtual void InitEditor(IGameToEditorInterface *arg0) = 0;
    virtual void SetEditorLevel(const char *arg0, const char *arg1) = 0;
    virtual void GetEditorLevel(char **arg0, char **arg1) = 0;
    virtual void BeginLanQuery() = 0;
    virtual void EndCurrentQuery() = 0;
    virtual IActor *GetClientActor() const = 0;
    virtual unsigned GetClientActorId() const = 0;
    virtual IEntity *GetClientEntity() const = 0;
    virtual unsigned GetClientEntityId() const = 0;
    virtual INetChannel *GetClientChannel() const = 0;
    virtual void DelegateAuthority(unsigned arg0, uint16_t arg1) = 0;
    virtual CTimeValue GetServerTime() = 0;
    virtual uint16_t GetGameChannelId(INetChannel *arg0) = 0;
    virtual bool IsChannelOnHold(uint16_t arg0) = 0;
    virtual INetChannel *GetNetChannel(uint16_t arg0) = 0;
    virtual IGameObject *GetGameObject(unsigned arg0) = 0;
    virtual bool GetNetworkSafeClassId(uint16_t &arg0, const char *arg1) = 0;
    virtual bool GetNetworkSafeClassName(char *arg0, uint64_t arg1, uint16_t arg2) = 0;
    virtual IGameObjectExtension *QueryGameObjectExtension(unsigned arg0, const char *arg1) = 0;
    virtual bool SaveGame(const char* path, bool bQuick = false, bool bForceImmediate = false, ESaveGameReason reason = eSGR_QuickSave, bool ignoreDelay = false, const char* checkPointName = nullptr) = 0;
    virtual ELoadGameResult LoadGame(const char* path, bool quick = false, bool ignoreDelay = false) = 0;
    virtual void ScheduleEndLevelNow(const char *arg0) = 0;
    virtual void OnEditorSetGameMode(int arg0) = 0;
    virtual bool IsEditing() = 0;
    virtual bool IsInLevelLoad() = 0;
    virtual bool IsLoadingSaveGame() = 0;
    virtual bool IsInTimeDemo() = 0;
    virtual bool IsTimeDemoRecording() = 0;
    virtual void AllowSave(bool arg0) = 0;
    virtual void AllowLoad(bool arg0) = 0;
    virtual bool CanSave() = 0;
    virtual bool CanLoad() = 0;
    virtual bool IsSavePending() const = 0;
    virtual void FinishWritingSave() const = 0;
    virtual bool IsWritingSave() const = 0;
    virtual ISerializeHelper *GetSerializeHelper() const = 0;
    virtual bool CanCheat() = 0;
    virtual const char *GetLevelName() = 0;
    virtual const char *GetAbsLevelPath(char *const arg0, const unsigned arg1) = 0;
    virtual IPersistantDebug *GetIPersistantDebug() = 0;
    virtual void AddBreakEventListener(IBreakEventListener *arg0) = 0;
    virtual void RemoveBreakEventListener(IBreakEventListener *arg0) = 0;
    virtual void RegisterListener(IGameFrameworkListener *arg0, const char *arg1, EFRAMEWORKLISTENERPRIORITY arg2) = 0;
    virtual void UnregisterListener(IGameFrameworkListener *arg0) = 0;
    virtual INetNub *GetServerNetNub() = 0;
    virtual INetNub *GetClientNetNub() = 0;
    virtual void SetGameGUID(const char *arg0) = 0;
    virtual const char *GetGameGUID() = 0;
    virtual INetContext *GetNetContext() = 0;
    virtual void GetMemoryUsage(ICrySizer *arg0) const = 0;
    virtual void EnableVoiceRecording(const bool arg0) = 0;
    virtual void MutePlayerById(unsigned arg0) = 0;
    virtual IDebugHistoryManager *CreateDebugHistoryManager() = 0;
    virtual void DumpMemInfo(const char *arg0, ...) = 0;
    virtual bool IsVoiceRecordingEnabled() = 0;
    virtual bool IsImmersiveMPEnabled() = 0;
    virtual void ExecuteCommandNextFrame(const char *arg0) = 0;
    virtual const char *GetNextFrameCommand() const = 0;
    virtual void ClearNextFrameCommand() = 0;
    virtual void ShowPageInBrowser(const char *arg0) = 0;
    virtual bool StartProcess(const char *arg0) = 0;
    virtual bool SaveServerConfig(const char *arg0) = 0;
    virtual void PrefetchLevelAssets(const bool arg0) = 0;
    virtual void ReleaseGameStats() = 0;
    virtual void OnBreakageSpawnedEntity(IEntity *arg0, IPhysicalEntity *arg1, IPhysicalEntity *arg2) = 0;
    virtual bool IsGameSession(unsigned arg0) = 0;
    virtual bool ShouldMigrateNub(unsigned arg0) = 0;
    virtual unsigned AddTimer(CTimeValue arg0, bool arg1, Functor2<void *,unsigned int> arg2, void *arg3) = 0;
    virtual void *RemoveTimer(unsigned arg0) = 0;
    virtual void ClearTimers() = 0;
    virtual unsigned GetPreUpdateTicks() = 0;
    virtual float GetLoadSaveDelay() const = 0;
    virtual void StartNetworkStallTicker(bool arg0) = 0;
    virtual void StopNetworkStallTicker() = 0;
    virtual IGameVolumes *GetIGameVolumesManager() const = 0;
    virtual void PreloadAnimatedCharacter(IScriptTable *arg0) = 0;
    virtual void RegisterExtension(std::shared_ptr<ICryUnknown> arg0) = 0;
    virtual void ReleaseExtensions() = 0;
    virtual std::shared_ptr<ICryUnknown> QueryExtensionInterfaceById(CryGUID const &arg0) const = 0;
};
