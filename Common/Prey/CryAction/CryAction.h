// Header file automatically created from a PDB.

#pragma once
#include <Chairloader/pch.h>
#include <Prey/Ark/arkgamenoise.h>
#include <Prey/CryAction/CryAction.h>
#include <Prey/CryCore/functor.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/TimeValue.h>
#include "Prey/CryAction/ark/ArkSaveLoadSystem.h"
#include "Prey/CryAction/ark/ArkAudioSwitchManager.h"
#include "Prey/CryAudio/IAudioInterfacesCommonData.h"
#include "Prey/CryAudio/SAudioRequest.h"
#include "Prey/CryAudio/SAudioManagerRequestData.h"

namespace ArkGameNoise
{
struct Params;
} // namespace ArkGameNoise
class ArkGameNoiseLoudness;
class CAIDebugRenderer;
class CAINetworkDebugRenderer;
class CAIProxyManager;
class CActionMapManager;
class CActorSystem;
struct CAnimationGraphCVars;
class CCryActionCVars;
class CCryActionPhysicQueues;
class CCustomActionManager;
class CCustomEventManager;
class CDevMode;
class CDialogSystem;
class CFlowSystem;
class CForceFeedBackSystem;
class CGameClientNub;
class CGameContext;
class CGameObjectSystem;
class CGameQueryListener;
class CGameRulesSystem;
class CGameSerialize;
class CGameServerNub;
class CGameStatsConfig;
class CGameplayAnalyst;
class CGameplayRecorder;
class CItemSystem;
class CLevelSystem;
class CMaterialEffects;
class CMaterialEffectsCVars;
class CNetMessageDistpatcher;
class CNetworkCVars;
class CNetworkStallTickerThread;
class CPersistantDebug;
class CPlayerProfileManager;
class CRConClientListener;
class CRangeSignaling;
class CRuntimeAreaManager;
class CScriptBind_Action;
class CScriptBind_ActionMapManager;
class CScriptBind_ActorSystem;
class CScriptBind_DialogSystem;
class CScriptBind_MaterialEffects;
class CScriptBind_Network;
class CScriptBind_UIAction;
class CScriptRMI;
class CSharedParamsManager;
class CSignalTimer;
class CSubtitleManager;
class CTimeDemoRecorder;
class CTimeOfDayScheduler;
class CUIDraw;
class CViewSystem;
class CVisualLog;
class CallbackTimer;
struct CryGUID;
struct I3DEngine;
struct IAIActorProxy;
struct IActionMapManager;
struct IActor;
struct IActorSystem;
class IArkSaveLoadSystem;
struct IBreakEventListener;
struct ICVar;
struct ICheckpointSystem;
struct IConsoleCmdArgs;
struct ICooperativeAnimationManager;
class ICrySizer;
struct ICustomActionManager;
struct ICustomEventManager;
struct IDebugHistoryManager;
struct IDialogSystem;
struct IEffectSystem;
struct IEntity;
struct IEntityProxy;
struct IEntitySystem;
struct IFlowSystem;
struct IForceFeedbackSystem;
struct IFunctionHandler;
struct IGameFrameworkListener;
struct IGameObject;
struct IGameObjectExtension;
struct IGameObjectSystem;
struct IGameRulesSystem;
struct IGameSessionHandler;
struct IGameStatistics;
struct IGameStatsConfig;
struct IGameToEditorInterface;
struct IGameTokenSystem;
struct IGameVolumes;
struct IGameplayRecorder;
struct IItemSystem;
struct ILanQueryListener;
struct ILevelSystem;
struct ILoadGame;
struct ILog;
struct IMannequin;
struct IMaterialEffects;
struct INetChannel;
struct INetContext;
struct INetNub;
struct INetwork;
struct IPersistantDebug;
struct IPhysicalEntity;
struct IPlayerProfileManager;
struct IRemoteControlClient;
struct IRemoteControlServer;
struct ISaveGame;
struct IScriptSystem;
struct IScriptTable;
struct ISerializeHelper;
class ISharedParamsManager;
struct ISimpleHttpServer;
struct ISubtitleManager;
struct ISystem;
struct ITimer;
struct ITweakMenuController;
struct IUIDraw;
struct IViewSystem;
struct IVisualLog;
struct SActionEvent;
struct SGameContextParams;
struct SGameStartParams;
struct SSystemInitParams;

class CActionGame;

// Header: Exact
// CryEngine/cryaction/cryaction.h
class CCryAction : public IGameFramework // Id=8004931 Size=2408
{
public:
	static IRemoteControlServer *s_rcon_server;
	static IRemoteControlClient *s_rcon_client;
	static CRConClientListener *s_rcon_client_listener;
	static ISimpleHttpServer *s_http_server;
	bool m_paused;
	bool m_forcedpause;
	bool m_levelPrecachingDone;
	bool m_usingLevelHeap;
	static CCryAction *m_pThis;
	ISystem *m_pSystem;
	INetwork *m_pNetwork;
	I3DEngine *m_p3DEngine;
	IScriptSystem *m_pScriptSystem;
	IEntitySystem *m_pEntitySystem;
	ITimer *m_pTimer;
	ILog *m_pLog;
	void *m_systemDll;
	_smart_ptr<CActionGame> m_pGame;
	char m_editorLevelName[512];
	char m_editorLevelFolder[512];
	char m_gameGUID[128];
	CLevelSystem *m_pLevelSystem;
	CActorSystem *m_pActorSystem;
	CItemSystem *m_pItemSystem;
	CSharedParamsManager *m_pSharedParamsManager;
	CActionMapManager *m_pActionMapManager;
	CViewSystem *m_pViewSystem;
	CGameplayRecorder *m_pGameplayRecorder;
	CGameRulesSystem *m_pGameRulesSystem;
	CFlowSystem *m_pFlowSystem;
	CGameObjectSystem *m_pGameObjectSystem;
	CUIDraw *m_pUIDraw;
	CScriptRMI *m_pScriptRMI;
	CAnimationGraphCVars *m_pAnimationGraphCvars;
	IMannequin *m_pMannequin;
	CMaterialEffects *m_pMaterialEffects;
	CPlayerProfileManager *m_pPlayerProfileManager;
	CDialogSystem *m_pDialogSystem;
	CSubtitleManager *m_pSubtitleManager;
	IGameTokenSystem *m_pGameTokenSystem;
	IEffectSystem *m_pEffectSystem;
	CGameSerialize *m_pGameSerialize;
	CallbackTimer *m_pCallbackTimer;
	CGameplayAnalyst *m_pGameplayAnalyst;
	CVisualLog *m_pVisualLog;
	CForceFeedBackSystem *m_pForceFeedBackSystem;
	ILanQueryListener *m_pLanQueryListener;
	CCustomActionManager *m_pCustomActionManager;
	CCustomEventManager *m_pCustomEventManager;
	CGameStatsConfig *m_pGameStatsConfig;
	IGameStatistics *m_pGameStatistics;
	ICooperativeAnimationManager *m_pCooperativeAnimationManager;
	IGameSessionHandler *m_pGameSessionHandler;
	CAIProxyManager *m_pAIProxyManager;
	IGameVolumes *m_pGameVolumesManager;
	CDevMode *m_pDevMode;
	CTimeDemoRecorder *m_pTimeDemoRecorder;
	CGameQueryListener *m_pGameQueryListener;
	CRuntimeAreaManager *m_pRuntimeAreaManager;
	CScriptBind_Action *m_pScriptA;
	CScriptBind_ActorSystem *m_pScriptAS;
	CScriptBind_Network *m_pScriptNet;
	CScriptBind_ActionMapManager *m_pScriptAMM;
	CScriptBind_DialogSystem *m_pScriptBindDS;
	CScriptBind_MaterialEffects *m_pScriptBindMFX;
	CScriptBind_UIAction *m_pScriptBindUIAction;
	CTimeOfDayScheduler *m_pTimeOfDayScheduler;
	CPersistantDebug *m_pPersistantDebug;
	CAIDebugRenderer *m_pAIDebugRenderer;
	CAINetworkDebugRenderer *m_pAINetworkDebugRenderer;
	CNetworkCVars *m_pNetworkCVars;
	CCryActionCVars *m_pCryActionCVars;
	CNetworkStallTickerThread *m_pNetworkStallTickerThread;
	unsigned m_networkStallTickerReferences;
	CMaterialEffectsCVars *m_pMaterialEffectsCVars;
	CCryActionPhysicQueues *m_pPhysicsQueues;
	
	using TFrameworkExtensions = std::vector<std::shared_ptr<ICryUnknown>>;
	
	std::vector<std::shared_ptr<ICryUnknown>> m_frameworkExtensions;
	ICVar *m_pEnableLoadingScreen;
	ICVar *m_pCheats;
	ICVar *m_pShowLanBrowserCVAR;
	ICVar *m_pDebugSignalTimers;
	ICVar *m_pDebugRangeSignaling;
	bool m_bShowLanBrowser;
	bool m_isEditing;
	bool m_bScheduleLevelEnd;
	
	enum ESaveGameMethod
	{
		eSGM_NoSave = 0,
		eSGM_QuickSave = 1,
		eSGM_Save = 2,
	};

	CCryAction::ESaveGameMethod m_delayedSaveGameMethod;
	ESaveGameReason m_delayedSaveGameReason;
	int m_delayedSaveCountDown;
	
	struct SLocalAllocs // Id=80058A5 Size=24
	{
		string m_delayedSaveGameName;
		string m_checkPointName;
		string m_nextLevelToLoad;
	};

	CCryAction::SLocalAllocs *m_pLocalAllocs;
	
	struct SGameFrameworkListener // Id=80058A6 Size=104
	{
		IGameFrameworkListener *pListener;
		CryStackStringT<char,64> name;
		EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority;
		
#if 0
		void GetMemoryUsage(ICrySizer *arg0) const;
#endif
	};

	using TGameFrameworkListeners = std::vector<CCryAction::SGameFrameworkListener>;
	
	std::vector<CCryAction::SGameFrameworkListener> *m_pGFListeners;
	IBreakEventListener *m_pBreakEventListener;
	std::vector<bool> m_validListeners;
	int m_VoiceRecordingEnabled;
	bool m_bAllowSave;
	bool m_bAllowLoad;
	string *m_nextFrameCommand;
	string *m_connectServer;
	float m_lastSaveLoad;
	float m_lastFrameTimeUI;
	bool m_pbSvEnabled;
	bool m_pbClEnabled;
	unsigned m_PreUpdateTicks;
	CNetMessageDistpatcher *m_pNetMsgDispatcher;
	ArkSaveLoadSystem m_arkSaveLoadSystem;
	ArkGameNoises m_arkGameNoiseData;
	std::vector<int> m_projectileExtensionIds;
	ArkAudioSwitchManager m_arkAudioSwitchManager;
	SAudioRequest m_pauseAudioRequest;
	SAudioRequest m_resumeAudioRequest;
	SAudioManagerRequestData<16777216> m_pauseAudioRequestData;
	SAudioManagerRequestData<33554432> m_resumeAudioRequestData;
	
	CCryAction();
	virtual ~CCryAction();
	virtual void ClearTimers();
	virtual unsigned AddTimer(CTimeValue interval, bool repeating, Functor2<void *,unsigned int> callback, void *userdata);
	virtual void *RemoveTimer(unsigned timerID);
	virtual unsigned GetPreUpdateTicks();
	virtual void RegisterFactory(const char *name, IGameFramework::IActorCreator *pCreator, bool isAI);
	virtual void RegisterFactory(const char *name, IGameFramework::IItemCreator *pCreator, bool isAI);
	virtual void RegisterFactory(const char *name, IGameFramework::IGameObjectExtensionCreator *pCreator, bool isAI);
	virtual void RegisterFactory(const char *name, ISaveGame *(*func)(), bool __formal);
	virtual void RegisterFactory(const char *name, ILoadGame *(*func)(), bool __formal);
	virtual bool Init(SSystemInitParams &startupParams);
	virtual void InitGameType(bool multiplayer, bool fromInit);
	virtual bool CompleteInit();
	virtual void Shutdown();
	virtual bool PreUpdate(bool haveFocus, unsigned updateFlags);
	virtual void PostUpdate(bool haveFocus, unsigned updateFlags);
	virtual void Reset(bool clients);
	virtual void GetMemoryUsage(ICrySizer *s) const;
	virtual void PauseGame(bool pause, bool force, unsigned nFadeOutInMS, bool bPauseAudio);
	virtual bool IsGamePaused();
	virtual bool IsGameStarted();
	virtual bool IsInLevelLoad();
	virtual bool IsLoadingSaveGame();
	virtual const char *GetLevelName();
	virtual const char *GetAbsLevelPath(char *const pPath, const unsigned cPathMaxLen);
	virtual bool IsInTimeDemo();
	virtual bool IsTimeDemoRecording();
	virtual bool IsLevelPrecachingDone() const;
	virtual void SetLevelPrecachingDone(bool bValue);
	virtual ISystem *GetISystem();
	virtual ILanQueryListener *GetILanQueryListener();
	virtual IUIDraw *GetIUIDraw();
	virtual IMannequin &GetMannequinInterface();
	virtual ILevelSystem *GetILevelSystem();
	virtual IActorSystem *GetIActorSystem();
	virtual IItemSystem *GetIItemSystem();
	virtual IActionMapManager *GetIActionMapManager();
	virtual IViewSystem *GetIViewSystem();
	virtual IGameplayRecorder *GetIGameplayRecorder();
	virtual IGameRulesSystem *GetIGameRulesSystem();
	virtual IGameObjectSystem *GetIGameObjectSystem();
	virtual IFlowSystem *GetIFlowSystem();
	virtual IGameTokenSystem *GetIGameTokenSystem();
	virtual IEffectSystem *GetIEffectSystem();
	virtual IMaterialEffects *GetIMaterialEffects();
	virtual IPlayerProfileManager *GetIPlayerProfileManager();
	virtual ISubtitleManager *GetISubtitleManager();
	virtual IDialogSystem *GetIDialogSystem();
	virtual ICooperativeAnimationManager *GetICooperativeAnimationManager();
	virtual ICheckpointSystem *GetICheckpointSystem();
	virtual IForceFeedbackSystem *GetIForceFeedbackSystem() const;
	virtual ICustomActionManager *GetICustomActionManager() const;
	virtual ICustomEventManager *GetICustomEventManager() const;
	virtual ITweakMenuController *CreateITweakMenuController();
	virtual bool StartGameContext(SGameStartParams const *pGameStartParams);
	virtual bool ChangeGameContext(SGameContextParams const *pGameContextParams);
	virtual void EndGameContext();
	virtual bool StartedGameContext() const;
	virtual bool StartingGameContext() const;
	virtual bool BlockingSpawnPlayer();
	virtual void ReleaseGameStats();
	virtual void ResetBrokenGameObjects();
	virtual IEntityProxy *CreateGameObject(unsigned _entityId);
	virtual void RegisterProjectileExtension(const char *name);
	virtual void DeleteAllProjectiles();
	virtual IArkSaveLoadSystem &GetIArkSaveLoadSystem();
	virtual void OnGameModeChanged() const;
	void Serialize(TSerialize ser) { FSerialize(this,ser); }
	virtual void FlushBreakableObjects();
	void ClearBreakHistory() { FClearBreakHistory(this); }
	void FullSerialize(TSerialize _ser) { FFullSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	virtual void InitEditor(IGameToEditorInterface *pGameToEditor);
	virtual void SetEditorLevel(const char *levelName, const char *levelFolder);
	virtual void GetEditorLevel(char **levelName, char **levelFolder);
	virtual void BeginLanQuery();
	virtual void EndCurrentQuery();
	virtual IActor *GetClientActor() const;
	virtual unsigned GetClientActorId() const;
	virtual IEntity *GetClientEntity() const;
	virtual unsigned GetClientEntityId() const;
	virtual INetChannel *GetClientChannel() const;
	virtual CTimeValue GetServerTime();
	virtual uint16_t GetGameChannelId(INetChannel *pNetChannel);
	virtual INetChannel *GetNetChannel(uint16_t channelId);
	virtual bool IsChannelOnHold(uint16_t channelId);
	virtual IGameObject *GetGameObject(unsigned id);
	virtual bool GetNetworkSafeClassId(uint16_t &id, const char *className);
	virtual bool GetNetworkSafeClassName(char *className, uint64_t maxn, uint16_t id);
	virtual IGameObjectExtension *QueryGameObjectExtension(unsigned id, const char *name);
	virtual void DelegateAuthority(unsigned entityId, uint16_t channelId);
	virtual INetContext *GetNetContext();
	virtual bool SaveGame(const char *path, bool bQuick, bool bForceImmediate, ESaveGameReason reason, bool ignoreDelay, const char *checkPointName);
	virtual ELoadGameResult LoadGame(const char *path, bool quick, bool ignoreDelay);
	virtual void ScheduleEndLevel(const char *nextLevel);
	virtual void ScheduleEndLevelNow(const char *nextLevel);
	virtual void OnEditorSetGameMode(int iMode);
	virtual bool IsEditing();
	virtual void OnBreakageSpawnedEntity(IEntity *pEntity, IPhysicalEntity *pPhysEntity, IPhysicalEntity *pSrcPhysEntity);
	virtual bool IsImmersiveMPEnabled();
	virtual void AllowSave(bool bAllow);
	virtual void AllowLoad(bool bAllow);
	virtual bool CanSave();
	virtual bool CanLoad();
	virtual ISerializeHelper *GetSerializeHelper() const;
	virtual bool CanCheat();
	virtual INetNub *GetServerNetNub();
	virtual INetNub *GetClientNetNub();
	virtual void SetGameGUID(const char *gameGUID);
	virtual const char *GetGameGUID();
	virtual bool IsVoiceRecordingEnabled();
	virtual bool IsGameSession(unsigned sessionHandle);
	virtual bool ShouldMigrateNub(unsigned sessionHandle);
	virtual ISharedParamsManager *GetISharedParamsManager();
	virtual float GetLoadSaveDelay() const;
	virtual IGameVolumes *GetIGameVolumesManager() const;
	virtual void PreloadAnimatedCharacter(IScriptTable *pEntityScript);
	virtual void RegisterExtension(std::shared_ptr<ICryUnknown> pExtension);
	virtual void ReleaseExtensions();
	virtual std::shared_ptr<ICryUnknown> QueryExtensionInterfaceById(CryGUID const &interfaceID) const;
	virtual CGameServerNub *GetGameServerNub();
	CGameClientNub *GetGameClientNub() { return FGetGameClientNub(this); }
	CGameContext *GetGameContext() { return FGetGameContext(this); }
	virtual void ReloadArkGameNoises();
	virtual void EmitArkGameNoise(const unsigned _emitter, Vec3 const &_position, ArkGameNoise::Params const &_params) const;
	virtual ArkGameNoiseLoudness const *FindArkGameNoiseLoudness(uint64_t _loudnessId) const;
	CSignalTimer *GetSignalTimer() { return FGetSignalTimer(this); }
	CRangeSignaling *GetRangeSignaling() { return FGetRangeSignaling(this); }
	virtual IPersistantDebug *GetIPersistantDebug();
	virtual IGameStatsConfig *GetIGameStatsConfig();
	virtual IVisualLog *GetIVisualLog();
	virtual void AddBreakEventListener(IBreakEventListener *pListener);
	virtual void RemoveBreakEventListener(IBreakEventListener *pListener);
	void OnBreakEvent(uint16_t uBreakEventIndex) { FOnBreakEvent(this,uBreakEventIndex); }
	virtual void RegisterListener(IGameFrameworkListener *pGameFrameworkListener, const char *name, EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority);
	virtual void UnregisterListener(IGameFrameworkListener *pGameFrameworkListener);
	CGameStatsConfig *GetGameStatsConfig() { return FGetGameStatsConfig(this); }
	virtual IGameStatistics *GetIGameStatistics();
	virtual IGameSessionHandler *GetIGameSessionHandler();
	virtual void SetGameSessionHandler(IGameSessionHandler *pSessionHandler);
	int NetworkExposeClass(IFunctionHandler *pFH) { return FNetworkExposeClass(this,pFH); }
	void NotifyGameFrameworkListeners(ISaveGame *pSaveGame) { FNotifyGameFrameworkListenersOv1(this,pSaveGame); }
	void NotifyGameFrameworkListeners(ILoadGame *pLoadGame) { FNotifyGameFrameworkListenersOv0(this,pLoadGame); }
	void NotifySavegameFileLoadedToListeners(const char *pLevelName) { FNotifySavegameFileLoadedToListeners(this,pLevelName); }
	virtual void EnableVoiceRecording(const bool enable);
	virtual void MutePlayerById(unsigned playerId);
	virtual IDebugHistoryManager *CreateDebugHistoryManager();
	virtual void ExecuteCommandNextFrame(const char *cmd);
	virtual const char *GetNextFrameCommand() const;
	virtual void ClearNextFrameCommand();
	virtual void PrefetchLevelAssets(const bool bEnforceAll);
	virtual void ShowPageInBrowser(const char *URL);
	virtual bool StartProcess(const char *cmd_line);
	virtual bool SaveServerConfig(const char *path);
	void OnActionEvent(SActionEvent const &ev) { FOnActionEvent(this,ev); }
	virtual void DumpMemInfo(const char *format, ... );
	const char *GetStartLevelSaveGameName() { return FGetStartLevelSaveGameName(this); }
	virtual IAIActorProxy *GetAIActorProxy(unsigned id) const;
	void CreatePhysicsQueues() { FCreatePhysicsQueues(this); }
	void ClearPhysicsQueues() { FClearPhysicsQueues(this); }
	CCryActionPhysicQueues &GetPhysicQueues() { return FGetPhysicQueues(this); }
	bool IsGameSessionMigrating() { return FIsGameSessionMigrating(this); }
	void SwitchToLevelHeap(const char *acLevelName) { FSwitchToLevelHeap(this,acLevelName); }
	virtual void StartNetworkStallTicker(bool includeMinimalUpdate);
	virtual void StopNetworkStallTicker();
	virtual ArkSaveLoadSystem &GetArkSaveLoadSystem();
	void GlobalActionsPostSerialize() const { FGlobalActionsPostSerialize(this); }
	virtual void FinishWritingSave() const;
	virtual bool IsSavePending() const;
	virtual bool IsWritingSave() const;
	void InitCVars() { FInitCVars(this); }
	void InitCommands() { FInitCommands(this); }
	static void OpenLogCmd(IConsoleCmdArgs *args) { FOpenLogCmd(args); }
	static void PauseCmd(IConsoleCmdArgs *_pArgs) { FPauseCmd(_pArgs); }
	static void DumpMapsCmd(IConsoleCmdArgs *args) { FDumpMapsCmd(args); }
	static void MapCmd(IConsoleCmdArgs *args) { FMapCmd(args); }
	static void ReloadReadabilityXML(IConsoleCmdArgs *__formal) { FReloadReadabilityXML(__formal); }
	static void UnloadCmd(IConsoleCmdArgs *args) { FUnloadCmd(args); }
	static void PlayCmd(IConsoleCmdArgs *args) { FPlayCmd(args); }
	static void ConnectCmd(IConsoleCmdArgs *args) { FConnectCmd(args); }
	static void DisconnectCmd(IConsoleCmdArgs *args) { FDisconnectCmd(args); }
	static void DisconnectChannelCmd(IConsoleCmdArgs *args) { FDisconnectChannelCmd(args); }
	static void StatusCmd(IConsoleCmdArgs *pArgs) { FStatusCmd(pArgs); }
	static void LegacyStatusCmd(IConsoleCmdArgs *args) { FLegacyStatusCmd(args); }
	static void VersionCmd(IConsoleCmdArgs *args) { FVersionCmd(args); }
	static void SaveGameCmd(IConsoleCmdArgs *args) { FSaveGameCmd(args); }
	static void GenStringsSaveGameCmd(IConsoleCmdArgs *pArgs) { FGenStringsSaveGameCmd(pArgs); }
	static void KickPlayerCmd(IConsoleCmdArgs *pArgs) { FKickPlayerCmd(pArgs); }
	static void KickPlayerByIdCmd(IConsoleCmdArgs *pArgs) { FKickPlayerByIdCmd(pArgs); }
	static void BanPlayerCmd(IConsoleCmdArgs *pArgs) { FBanPlayerCmd(pArgs); }
	static void BanStatusCmd(IConsoleCmdArgs *pArgs) { FBanStatusCmd(pArgs); }
	static void UnbanPlayerCmd(IConsoleCmdArgs *pArgs) { FUnbanPlayerCmd(pArgs); }
	static void OpenURLCmd(IConsoleCmdArgs *args) { FOpenURLCmd(args); }
	static void TestResetCmd(IConsoleCmdArgs *args) { FTestResetCmd(args); }
	static void DumpAnalysisStatsCmd(IConsoleCmdArgs *args) { FDumpAnalysisStatsCmd(args); }
	static void TestPlayerBoundsCmd(IConsoleCmdArgs *args) { FTestPlayerBoundsCmd(args); }
	static void DelegateCmd(IConsoleCmdArgs *args) { FDelegateCmd(args); }
	static void DumpStatsCmd(IConsoleCmdArgs *args) { FDumpStatsCmd(args); }
	static void rcon_startserver(IConsoleCmdArgs *args) { Frcon_startserver(args); }
	static void rcon_stopserver(IConsoleCmdArgs *args) { Frcon_stopserver(args); }
	static void rcon_connect(IConsoleCmdArgs *args) { Frcon_connect(args); }
	static void rcon_disconnect(IConsoleCmdArgs *args) { Frcon_disconnect(args); }
	static void rcon_command(IConsoleCmdArgs *args) { Frcon_command(args); }
	static void http_startserver(IConsoleCmdArgs *args) { Fhttp_startserver(args); }
	static void http_stopserver(IConsoleCmdArgs *args) { Fhttp_stopserver(args); }
	void CheckEndLevelSchedule() { FCheckEndLevelSchedule(this); }
	static void MutePlayer(IConsoleCmdArgs *pArgs) { FMutePlayer(pArgs); }
	static void VerifyMaxPlayers(ICVar *pVar) { FVerifyMaxPlayers(pVar); }
	static void ResetComments(ICVar *pVar) { FResetComments(pVar); }
	static void StaticSetPbSvEnabled(IConsoleCmdArgs *pArgs) { FStaticSetPbSvEnabled(pArgs); }
	static void StaticSetPbClEnabled(IConsoleCmdArgs *pArgs) { FStaticSetPbClEnabled(pArgs); }
	
#if 0
	ArkAudioSwitchManager &GetArkAudioSwitchManager();
	static CCryAction *GetCryAction();
	static void SeedRandomGenerator(unsigned arg0);
	bool ControlsEntity(unsigned arg0) const;
	CPersistantDebug *GetPersistantDebug();
	CVisualLog *GetVisualLog();
	void OnPartRemoveEvent(int arg0);
	CDialogSystem *GetDialogSystem();
	CTimeOfDayScheduler *GetTimeOfDayScheduler() const;
	CNetMessageDistpatcher *GetNetMessageDispatcher();
	bool LoadingScreenEnabled() const;
	void NotifyForceFlashLoadingListeners();
	bool IsPbSvEnabled() const;
	bool IsPbClEnabled() const;
	CAIProxyManager *GetAIProxyManager();
	CAIProxyManager const *GetAIProxyManager() const;
	void RestoreLevelState();
	ArkGameNoises const &GetArkGameNoiseData() const;
	CGameSerialize *GetGameSerializeObject();
	void InitScriptBinds();
	void ReleaseScriptBinds();
	void InitForceFeedbackSystem();
	void InitGameVolumesManager();
	void ReleaseCVars();
	static void FlowTest(IConsoleCmdArgs *arg0);
	static void SaveTagCmd(IConsoleCmdArgs *arg0);
	static void LoadTagCmd(IConsoleCmdArgs *arg0);
	static void LegacyKickPlayerCmd(IConsoleCmdArgs *arg0);
	static void LegacyKickPlayerByIdCmd(IConsoleCmdArgs *arg0);
	static void LegacyBanPlayerCmd(IConsoleCmdArgs *arg0);
	static void LegacyBanStatusCmd(IConsoleCmdArgs *arg0);
	static void LegacyUnbanPlayerCmd(IConsoleCmdArgs *arg0);
	static void TestTimeout(IConsoleCmdArgs *arg0);
	static void TestNSServerBrowser(IConsoleCmdArgs *arg0);
	static void TestNSServerReport(IConsoleCmdArgs *arg0);
	static void TestNSChat(IConsoleCmdArgs *arg0);
	static void TestNSStats(IConsoleCmdArgs *arg0);
	static void TestNSNat(IConsoleCmdArgs *arg0);
	void SetGameQueryListener(CGameQueryListener *arg0);
#endif
	
	static inline auto FClearTimers = PreyFunction<void(CCryAction *const _this)>(0x5BDCD0);
	static inline auto FAddTimer = PreyFunction<unsigned(CCryAction *const _this, CTimeValue interval, bool repeating, Functor2<void *,unsigned int> callback, void *userdata)>(0x5BCEF0);
	static inline auto FRemoveTimer = PreyFunction<void *(CCryAction *const _this, unsigned timerID)>(0x5C7BF0);
	static inline auto FGetPreUpdateTicks = PreyFunction<unsigned(CCryAction *const _this)>(0x5C0440);
	static inline auto FRegisterFactoryOv4 = PreyFunction<void(CCryAction *const _this, const char *name, IGameFramework::IActorCreator *pCreator, bool isAI)>(0x5C7840);
	static inline auto FRegisterFactoryOv3 = PreyFunction<void(CCryAction *const _this, const char *name, IGameFramework::IItemCreator *pCreator, bool isAI)>(0x5C7870);
	static inline auto FRegisterFactoryOv2 = PreyFunction<void(CCryAction *const _this, const char *name, IGameFramework::IGameObjectExtensionCreator *pCreator, bool isAI)>(0x5C7850);
	static inline auto FRegisterFactoryOv1 = PreyFunction<void(CCryAction *const _this, const char *name, ISaveGame *(*func)(), bool __formal)>(0x5C7820);
	static inline auto FRegisterFactoryOv0 = PreyFunction<void(CCryAction *const _this, const char *name, ILoadGame *(*func)(), bool __formal)>(0x5C7800);
	static inline auto FInit = PreyFunction<bool(CCryAction *const _this, SSystemInitParams &startupParams)>(0x5C07C0);
	static inline auto FInitGameType = PreyFunction<void(CCryAction *const _this, bool multiplayer, bool fromInit)>(0x5C2A80);
	static inline auto FCompleteInit = PreyFunction<bool(CCryAction *const _this)>(0x5BDCE0);
	static inline auto FShutdown = PreyFunction<void(CCryAction *const _this)>(0x5C8A90);
	static inline auto FPreUpdate = PreyFunction<bool(CCryAction *const _this, bool haveFocus, unsigned updateFlags)>(0x5C72B0);
	static inline auto FPostUpdate = PreyFunction<void(CCryAction *const _this, bool haveFocus, unsigned updateFlags)>(0x5C69D0);
	static inline auto FReset = PreyFunction<void(CCryAction *const _this, bool clients)>(0x5C7C00);
	static inline auto FGetMemoryUsage = PreyFunction<void(CCryAction const *const _this, ICrySizer *s)>(0x5BFC20);
	static inline auto FPauseGame = PreyFunction<void(CCryAction *const _this, bool pause, bool force, unsigned nFadeOutInMS, bool bPauseAudio)>(0x5C6660);
	static inline auto FIsGamePaused = PreyFunction<bool(CCryAction *const _this)>(0x5C2C50);
	static inline auto FIsGameStarted = PreyFunction<bool(CCryAction *const _this)>(0x5C2CD0);
	static inline auto FIsInLevelLoad = PreyFunction<bool(CCryAction *const _this)>(0x5C2D10);
	static inline auto FIsLoadingSaveGame = PreyFunction<bool(CCryAction *const _this)>(0x5C2D70);
	static inline auto FGetLevelName = PreyFunction<const char *(CCryAction *const _this)>(0x5BFB90);
	static inline auto FGetAbsLevelPath = PreyFunction<const char *(CCryAction *const _this, char *const pPath, const unsigned cPathMaxLen)>(0x5BF3A0);
	static inline auto FIsInTimeDemo = PreyFunction<bool(CCryAction *const _this)>(0x5C2D30);
	static inline auto FIsTimeDemoRecording = PreyFunction<bool(CCryAction *const _this)>(0x5C2DA0);
	static inline auto FIsLevelPrecachingDone = PreyFunction<bool(CCryAction const *const _this)>(0x5C2D60);
	static inline auto FSetLevelPrecachingDone = PreyFunction<void(CCryAction *const _this, bool bValue)>(0x5C8A10);
	static inline auto FGetISystem = PreyFunction<ISystem *(CCryAction *const _this)>(0x5BFB50);
	static inline auto FGetILanQueryListener = PreyFunction<ILanQueryListener *(CCryAction *const _this)>(0x5BFAE0);
	static inline auto FGetIUIDraw = PreyFunction<IUIDraw *(CCryAction *const _this)>(0x5BFB60);
	static inline auto FGetMannequinInterface = PreyFunction<IMannequin &(CCryAction *const _this)>(0x5BFC10);
	static inline auto FGetILevelSystem = PreyFunction<ILevelSystem *(CCryAction *const _this)>(0x5BFAF0);
	static inline auto FGetIActorSystem = PreyFunction<IActorSystem *(CCryAction *const _this)>(0x5BF970);
	static inline auto FGetIItemSystem = PreyFunction<IItemSystem *(CCryAction *const _this)>(0x5BFAC0);
	static inline auto FGetIActionMapManager = PreyFunction<IActionMapManager *(CCryAction *const _this)>(0x5BF960);
	static inline auto FGetIViewSystem = PreyFunction<IViewSystem *(CCryAction *const _this)>(0x5BFB70);
	static inline auto FGetIGameplayRecorder = PreyFunction<IGameplayRecorder *(CCryAction *const _this)>(0x1827D0);
	static inline auto FGetIGameRulesSystem = PreyFunction<IGameRulesSystem *(CCryAction *const _this)>(0x5BFA10);
	static inline auto FGetIGameObjectSystem = PreyFunction<IGameObjectSystem *(CCryAction *const _this)>(0x5BFA00);
	static inline auto FGetIFlowSystem = PreyFunction<IFlowSystem *(CCryAction *const _this)>(0x5BF9E0);
	static inline auto FGetIGameTokenSystem = PreyFunction<IGameTokenSystem *(CCryAction *const _this)>(0x5BFAA0);
	static inline auto FGetIEffectSystem = PreyFunction<IEffectSystem *(CCryAction *const _this)>(0x5BF9D0);
	static inline auto FGetIMaterialEffects = PreyFunction<IMaterialEffects *(CCryAction *const _this)>(0x5BFB00);
	static inline auto FGetIPlayerProfileManager = PreyFunction<IPlayerProfileManager *(CCryAction *const _this)>(0x5BFB20);
	static inline auto FGetISubtitleManager = PreyFunction<ISubtitleManager *(CCryAction *const _this)>(0x5BFB40);
	static inline auto FGetIDialogSystem = PreyFunction<IDialogSystem *(CCryAction *const _this)>(0x5BF9C0);
	static inline auto FGetICooperativeAnimationManager = PreyFunction<ICooperativeAnimationManager *(CCryAction *const _this)>(0x5BF990);
	static inline auto FGetICheckpointSystem = PreyFunction<ICheckpointSystem *(CCryAction *const _this)>(0x5BF980);
	static inline auto FGetIForceFeedbackSystem = PreyFunction<IForceFeedbackSystem *(CCryAction const *const _this)>(0x5BF9F0);
	static inline auto FGetICustomActionManager = PreyFunction<ICustomActionManager *(CCryAction const *const _this)>(0x5BF9A0);
	static inline auto FGetICustomEventManager = PreyFunction<ICustomEventManager *(CCryAction const *const _this)>(0x5BF9B0);
	static inline auto FCreateITweakMenuController = PreyFunction<ITweakMenuController *(CCryAction *const _this)>(0x5BE910);
	static inline auto FStartGameContext = PreyFunction<bool(CCryAction *const _this, SGameStartParams const *pGameStartParams)>(0x5C93D0);
	static inline auto FChangeGameContext = PreyFunction<bool(CCryAction *const _this, SGameContextParams const *pGameContextParams)>(0x5BD5E0);
	static inline auto FEndGameContext = PreyFunction<void(CCryAction *const _this)>(0x5BF010);
	static inline auto FStartedGameContext = PreyFunction<bool(CCryAction const *const _this)>(0x5C95E0);
	static inline auto FStartingGameContext = PreyFunction<bool(CCryAction const *const _this)>(0x5C9600);
	static inline auto FBlockingSpawnPlayer = PreyFunction<bool(CCryAction *const _this)>(0x5BD300);
	static inline auto FReleaseGameStats = PreyFunction<void(CCryAction *const _this)>(0x5C7BB0);
	static inline auto FResetBrokenGameObjects = PreyFunction<void(CCryAction *const _this)>(0x5C7CB0);
	static inline auto FCreateGameObject = PreyFunction<IEntityProxy *(CCryAction *const _this, unsigned _entityId)>(0x5BE8B0);
	static inline auto FRegisterProjectileExtension = PreyFunction<void(CCryAction *const _this, const char *name)>(0x5C7B30);
	static inline auto FDeleteAllProjectiles = PreyFunction<void(CCryAction *const _this)>(0x5BEB80);
	static inline auto FGetIArkSaveLoadSystem = PreyFunction<IArkSaveLoadSystem &(CCryAction *const _this)>(0x5BF500);
	static inline auto FOnGameModeChanged = PreyFunction<void(CCryAction const *const _this)>(0x5C6220);
	static inline auto FSerialize = PreyFunction<void(CCryAction *const _this, TSerialize ser)>(0x5B2A00);
	static inline auto FFlushBreakableObjects = PreyFunction<void(CCryAction *const _this)>(0x5AA190);
	static inline auto FClearBreakHistory = PreyFunction<void(CCryAction *const _this)>(0x5A8F90);
	static inline auto FFullSerialize = PreyFunction<void(CCryAction *const _this, TSerialize _ser)>(0x5BF320);
	static inline auto FPostSerialize = PreyFunction<void(CCryAction *const _this)>(0x5C69C0);
	static inline auto FInitEditor = PreyFunction<void(CCryAction *const _this, IGameToEditorInterface *pGameToEditor)>(0x5C27A0);
	static inline auto FSetEditorLevel = PreyFunction<void(CCryAction *const _this, const char *levelName, const char *levelFolder)>(0x5C88F0);
	static inline auto FGetEditorLevel = PreyFunction<void(CCryAction *const _this, char **levelName, char **levelFolder)>(0x5BF610);
	static inline auto FBeginLanQuery = PreyFunction<void(CCryAction *const _this)>(0x5BD280);
	static inline auto FEndCurrentQuery = PreyFunction<void(CCryAction *const _this)>(0x5BEFE0);
	static inline auto FGetClientActor = PreyFunction<IActor *(CCryAction const *const _this)>(0x5BF530);
	static inline auto FGetClientActorId = PreyFunction<unsigned(CCryAction const *const _this)>(0x5BF540);
	static inline auto FGetClientEntity = PreyFunction<IEntity *(CCryAction const *const _this)>(0x5BF5A0);
	static inline auto FGetClientEntityId = PreyFunction<unsigned(CCryAction const *const _this)>(0x5BF5D0);
	static inline auto FGetClientChannel = PreyFunction<INetChannel *(CCryAction const *const _this)>(0x5BF570);
	static inline auto FGetServerTime = PreyFunction<CTimeValue(CCryAction *const _this)>(0x5C0500);
	static inline auto FGetGameChannelId = PreyFunction<uint16_t(CCryAction *const _this, INetChannel *pNetChannel)>(0x5BF810);
	static inline auto FGetNetChannel = PreyFunction<INetChannel *(CCryAction *const _this, uint16_t channelId)>(0x5C0220);
	static inline auto FIsChannelOnHold = PreyFunction<bool(CCryAction *const _this, uint16_t channelId)>(0x5C2C00);
	static inline auto FGetGameObject = PreyFunction<IGameObject *(CCryAction *const _this, unsigned id)>(0x5BF880);
	static inline auto FGetNetworkSafeClassId = PreyFunction<bool(CCryAction *const _this, uint16_t &id, const char *className)>(0x5C0290);
	static inline auto FGetNetworkSafeClassName = PreyFunction<bool(CCryAction *const _this, char *className, uint64_t maxn, uint16_t id)>(0x5C0390);
	static inline auto FQueryGameObjectExtension = PreyFunction<IGameObjectExtension *(CCryAction *const _this, unsigned id, const char *name)>(0x5C7740);
	static inline auto FDelegateAuthority = PreyFunction<void(CCryAction *const _this, unsigned entityId, uint16_t channelId)>(0x5BEA30);
	static inline auto FGetNetContext = PreyFunction<INetContext *(CCryAction *const _this)>(0x5C0270);
	static inline auto FSaveGame = PreyFunction<bool(CCryAction *const _this, const char *path, bool bQuick, bool bForceImmediate, ESaveGameReason reason, bool ignoreDelay, const char *checkPointName)>(0x5C7DD0);
	static inline auto FLoadGame = PreyFunction<ELoadGameResult(CCryAction *const _this, const char *path, bool quick, bool ignoreDelay)>(0x5C38B0);
	static inline auto FScheduleEndLevel = PreyFunction<void(CCryAction *const _this, const char *nextLevel)>(0x5C8870);
	static inline auto FScheduleEndLevelNow = PreyFunction<void(CCryAction *const _this, const char *nextLevel)>(0x5C88B0);
	static inline auto FOnEditorSetGameMode = PreyFunction<void(CCryAction *const _this, int iMode)>(0x5C60F0);
	static inline auto FIsEditing = PreyFunction<bool(CCryAction *const _this)>(0x5C2C40);
	static inline auto FOnBreakageSpawnedEntity = PreyFunction<void(CCryAction *const _this, IEntity *pEntity, IPhysicalEntity *pPhysEntity, IPhysicalEntity *pSrcPhysEntity)>(0x5C5780);
	static inline auto FIsImmersiveMPEnabled = PreyFunction<bool(CCryAction *const _this)>(0x5C2CF0);
	static inline auto FAllowSave = PreyFunction<void(CCryAction *const _this, bool bAllow)>(0x5BCF30);
	static inline auto FAllowLoad = PreyFunction<void(CCryAction *const _this, bool bAllow)>(0x5BCF20);
	static inline auto FCanSave = PreyFunction<bool(CCryAction *const _this)>(0x5BD400);
	static inline auto FCanLoad = PreyFunction<bool(CCryAction *const _this)>(0x5BD3B0);
	static inline auto FGetSerializeHelper = PreyFunction<ISerializeHelper *(CCryAction const *const _this)>(0x5C0490);
	static inline auto FCanCheat = PreyFunction<bool(CCryAction *const _this)>(0x5BD380);
	static inline auto FGetServerNetNub = PreyFunction<INetNub *(CCryAction *const _this)>(0x5C04F0);
	static inline auto FGetClientNetNub = PreyFunction<INetNub *(CCryAction *const _this)>(0x5BF600);
	static inline auto FSetGameGUID = PreyFunction<void(CCryAction *const _this, const char *gameGUID)>(0x5C8990);
	static inline auto FGetGameGUID = PreyFunction<const char *(CCryAction *const _this)>(0x5BF870);
	static inline auto FIsVoiceRecordingEnabled = PreyFunction<bool(CCryAction *const _this)>(0x5C2DC0);
	static inline auto FIsGameSession = PreyFunction<bool(CCryAction *const _this, unsigned sessionHandle)>(0x5C2C80);
	static inline auto FShouldMigrateNub = PreyFunction<bool(CCryAction *const _this, unsigned sessionHandle)>(0x5C8A20);
	static inline auto FGetISharedParamsManager = PreyFunction<ISharedParamsManager *(CCryAction *const _this)>(0x5BFB30);
	static inline auto FGetLoadSaveDelay = PreyFunction<float(CCryAction const *const _this)>(0x5BFC00);
	static inline auto FGetIGameVolumesManager = PreyFunction<IGameVolumes *(CCryAction const *const _this)>(0x5BFAB0);
	static inline auto FPreloadAnimatedCharacter = PreyFunction<void(CCryAction *const _this, IScriptTable *pEntityScript)>(0x5C7670);
	static inline auto FRegisterExtension = PreyFunction<void(CCryAction *const _this, std::shared_ptr<ICryUnknown> pExtension)>(0x5C77A0);
	static inline auto FReleaseExtensions = PreyFunction<void(CCryAction *const _this)>(0x5C7B80);
	static inline auto FQueryExtensionInterfaceById = PreyFunction<std::shared_ptr<ICryUnknown>(CCryAction const *const _this, CryGUID const &interfaceID)>(0x5C7680);
	static inline auto FGetGameServerNub = PreyFunction<CGameServerNub *(CCryAction *const _this)>(0x5BF940);
	static inline auto FGetGameClientNub = PreyFunction<CGameClientNub *(CCryAction *const _this)>(0x5BF850);
	static inline auto FGetGameContext = PreyFunction<CGameContext *(CCryAction *const _this)>(0x5BF860);
	static inline auto FReloadArkGameNoises = PreyFunction<void(CCryAction *const _this)>(0x5C7BC0);
	static inline auto FEmitArkGameNoise = PreyFunction<void(CCryAction const *const _this, const unsigned _emitter, Vec3 const &_position, ArkGameNoise::Params const &_params)>(0x5BEFA0);
	static inline auto FFindArkGameNoiseLoudness = PreyFunction<ArkGameNoiseLoudness const *(CCryAction const *const _this, uint64_t _loudnessId)>(0x5BF2A0);
	static inline auto FGetSignalTimer = PreyFunction<CSignalTimer *(CCryAction *const _this)>(0x5C0590);
	static inline auto FGetRangeSignaling = PreyFunction<CRangeSignaling *(CCryAction *const _this)>(0x5C0480);
	static inline auto FGetIPersistantDebug = PreyFunction<IPersistantDebug *(CCryAction *const _this)>(0x5BFB10);
	static inline auto FGetIGameStatsConfig = PreyFunction<IGameStatsConfig *(CCryAction *const _this)>(0x5BFA90);
	static inline auto FGetIVisualLog = PreyFunction<IVisualLog *(CCryAction *const _this)>(0x5BFB80);
	static inline auto FAddBreakEventListener = PreyFunction<void(CCryAction *const _this, IBreakEventListener *pListener)>(0x5BCEE0);
	static inline auto FRemoveBreakEventListener = PreyFunction<void(CCryAction *const _this, IBreakEventListener *pListener)>(0x5C7BE0);
	static inline auto FOnBreakEvent = PreyFunction<void(CCryAction *const _this, uint16_t uBreakEventIndex)>(0x5C5760);
	static inline auto FRegisterListener = PreyFunction<void(CCryAction *const _this, IGameFrameworkListener *pGameFrameworkListener, const char *name, EFRAMEWORKLISTENERPRIORITY eFrameworkListenerPriority)>(0x5C7890);
	static inline auto FUnregisterListener = PreyFunction<void(CCryAction *const _this, IGameFrameworkListener *pGameFrameworkListener)>(0x5CA0D0);
	static inline auto FGetGameStatsConfig = PreyFunction<CGameStatsConfig *(CCryAction *const _this)>(0x5BFA90);
	static inline auto FGetIGameStatistics = PreyFunction<IGameStatistics *(CCryAction *const _this)>(0x5BFA80);
	static inline auto FGetIGameSessionHandler = PreyFunction<IGameSessionHandler *(CCryAction *const _this)>(0x5BFA20);
	static inline auto FSetGameSessionHandler = PreyFunction<void(CCryAction *const _this, IGameSessionHandler *pSessionHandler)>(0x5C89E0);
	static inline auto FNetworkExposeClass = PreyFunction<int(CCryAction *const _this, IFunctionHandler *pFH)>(0x5C4EF0);
	static inline auto FNotifyGameFrameworkListenersOv1 = PreyFunction<void(CCryAction *const _this, ISaveGame *pSaveGame)>(0x5C50F0);
	static inline auto FNotifyGameFrameworkListenersOv0 = PreyFunction<void(CCryAction *const _this, ILoadGame *pLoadGame)>(0x5C4F00);
	static inline auto FNotifySavegameFileLoadedToListeners = PreyFunction<void(CCryAction *const _this, const char *pLevelName)>(0x5C52E0);
	static inline auto FEnableVoiceRecording = PreyFunction<void(CCryAction *const _this, const bool enable)>(0x5BEFD0);
	static inline auto FMutePlayerById = PreyFunction<void(CCryAction *const _this, unsigned playerId)>(0xA13080);
	static inline auto FCreateDebugHistoryManager = PreyFunction<IDebugHistoryManager *(CCryAction *const _this)>(0x5BE7E0);
	static inline auto FExecuteCommandNextFrame = PreyFunction<void(CCryAction *const _this, const char *cmd)>(0x5BF260);
	static inline auto FGetNextFrameCommand = PreyFunction<const char *(CCryAction const *const _this)>(0x5C0420);
	static inline auto FClearNextFrameCommand = PreyFunction<void(CCryAction *const _this)>(0x5BDC60);
	static inline auto FPrefetchLevelAssets = PreyFunction<void(CCryAction *const _this, const bool bEnforceAll)>(0x5C7650);
	static inline auto FShowPageInBrowser = PreyFunction<void(CCryAction *const _this, const char *URL)>(0x5C8A60);
	static inline auto FStartProcess = PreyFunction<bool(CCryAction *const _this, const char *cmd_line)>(0x5C9570);
	static inline auto FSaveServerConfig = PreyFunction<bool(CCryAction *const _this, const char *path)>(0x5C86D0);
	static inline auto FOnActionEvent = PreyFunction<void(CCryAction *const _this, SActionEvent const &ev)>(0x5C54D0);
	static inline auto FDumpMemInfo = PreyFunction<void(CCryAction *const _this, const char *format)>(0x5BEEE0);
	static inline auto FGetStartLevelSaveGameName = PreyFunction<const char *(CCryAction *const _this)>(0x5C05A0);
	static inline auto FGetAIActorProxy = PreyFunction<IAIActorProxy *(CCryAction const *const _this, unsigned id)>(0x5BF390);
	static inline auto FCreatePhysicsQueues = PreyFunction<void(CCryAction *const _this)>(0x5BE940);
	static inline auto FClearPhysicsQueues = PreyFunction<void(CCryAction *const _this)>(0x5BDC80);
	static inline auto FGetPhysicQueues = PreyFunction<CCryActionPhysicQueues &(CCryAction *const _this)>(0x5C0430);
	static inline auto FIsGameSessionMigrating = PreyFunction<bool(CCryAction *const _this)>(0x5C2CB0);
	static inline auto FSwitchToLevelHeap = PreyFunction<void(CCryAction *const _this, const char *acLevelName)>(0x5C9A00);
	static inline auto FStartNetworkStallTicker = PreyFunction<void(CCryAction *const _this, bool includeMinimalUpdate)>(0x5C9470);
	static inline auto FStopNetworkStallTicker = PreyFunction<void(CCryAction *const _this)>(0x5C9960);
	static inline auto FGetArkSaveLoadSystem = PreyFunction<ArkSaveLoadSystem &(CCryAction *const _this)>(0x5BF500);
	static inline auto FGlobalActionsPostSerialize = PreyFunction<void(CCryAction const *const _this)>(0x5C0720);
	static inline auto FFinishWritingSave = PreyFunction<void(CCryAction const *const _this)>(0x5BF2B0);
	static inline auto FIsSavePending = PreyFunction<bool(CCryAction const *const _this)>(0x5C2D90);
	static inline auto FIsWritingSave = PreyFunction<bool(CCryAction const *const _this)>(0x5C2DD0);
	static inline auto FInitCVars = PreyFunction<void(CCryAction *const _this)>(0x5C1630);
	static inline auto FInitCommands = PreyFunction<void(CCryAction *const _this)>(0x5C2040);
	static inline auto FOpenLogCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C6450);
	static inline auto FPauseCmd = PreyFunction<void(IConsoleCmdArgs *_pArgs)>(0x5C6530);
	static inline auto FDumpMapsCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BEDF0);
	static inline auto FMapCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C3EF0);
	static inline auto FReloadReadabilityXML = PreyFunction<void(IConsoleCmdArgs *__formal)>(0x5C7BD0);
	static inline auto FUnloadCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CA090);
	static inline auto FPlayCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C6870);
	static inline auto FConnectCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BE2B0);
	static inline auto FDisconnectCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BECD0);
	static inline auto FDisconnectChannelCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BEC80);
	static inline auto FStatusCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5C98D0);
	static inline auto FLegacyStatusCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C3410);
	static inline auto FVersionCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CADD0);
	static inline auto FSaveGameCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C8270);
	static inline auto FGenStringsSaveGameCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5BF350);
	static inline auto FKickPlayerCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5C3160);
	static inline auto FKickPlayerByIdCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5C2F70);
	static inline auto FBanPlayerCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5BCF40);
	static inline auto FBanStatusCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5BD210);
	static inline auto FUnbanPlayerCmd = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5C9F40);
	static inline auto FOpenURLCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C64D0);
	static inline auto FTestResetCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C9F30);
	static inline auto FDumpAnalysisStatsCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BEDD0);
	static inline auto FTestPlayerBoundsCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5C9AA0);
	static inline auto FDelegateCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BEAA0);
	static inline auto FDumpStatsCmd = PreyFunction<void(IConsoleCmdArgs *args)>(0x5BEF80);
	static inline auto Frcon_startserver = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CC6A0);
	static inline auto Frcon_stopserver = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CCB30);
	static inline auto Frcon_connect = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CC140);
	static inline auto Frcon_disconnect = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CC630);
	static inline auto Frcon_command = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CBFE0);
	static inline auto Fhttp_startserver = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CB8C0);
	static inline auto Fhttp_stopserver = PreyFunction<void(IConsoleCmdArgs *args)>(0x5CBD20);
	static inline auto FCheckEndLevelSchedule = PreyFunction<void(CCryAction *const _this)>(0x5BD600);
	static inline auto FMutePlayer = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0xA13080);
	static inline auto FVerifyMaxPlayers = PreyFunction<void(ICVar *pVar)>(0x5CAD80);
	static inline auto FResetComments = PreyFunction<void(ICVar *pVar)>(0x5C7CE0);
	static inline auto FStaticSetPbSvEnabled = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5C9770);
	static inline auto FStaticSetPbClEnabled = PreyFunction<void(IConsoleCmdArgs *pArgs)>(0x5C9620);
};

// Header: FromCpp
// CryEngine/cryaction/cryaction.h
struct CSystemEventListner_Action : public ISystemEventListener // Id=800731B Size=8
{
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual ~CSystemEventListner_Action();
	
	static inline auto FOnSystemEvent = PreyFunction<void(CSystemEventListner_Action *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x5B8030);
};

