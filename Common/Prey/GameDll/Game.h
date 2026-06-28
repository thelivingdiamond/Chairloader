// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <CryEngine/crysystem/platformos/PlatformOS_PC.h>
#include <Prey/CryGame/IGame.h>
#include <Prey/CryGame/IGameFramework.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryMath/LCGRandom.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <_unknown/IGame.h>
#include <_unknown/IntersectionTestQueue.h>
#include <_unknown/RayCastQueue.h>

class ArkActiveUserManagerBase;
class ArkAiManager;
class ArkAttentionManager;
class ArkAttractionManager;
class ArkAuralPerceptionManager;
class ArkCharacterManager;
class ArkCombatManager;
class ArkCystoidManager;
class ArkDistractionEntitySink;
class ArkDistractionManager;
class ArkDoomClockManager;
class ArkDynamicCalledMimicManager;
class ArkDynamicCorpseManager;
class ArkEncounterManager;
class ArkEthericFogManager;
class ArkFactionManager;
class ArkGame;
class ArkGameDataManager;
struct ArkGameNoiseInfo;
class ArkGlintConfigManager;
class ArkInstigationManager;
class ArkItemSystem;
class ArkLightTimeManager;
class ArkListenerManager;
class ArkLurkManager;
class ArkMetaTagManager;
class ArkMoonRockManager;
class ArkNightmareEtherformManager;
class ArkNightmareSpawnManager;
class ArkNpcAbilityManager;
class ArkNpcAreaManager;
class ArkNpcBlackboardManager;
class ArkNpcGameEffectManager;
class ArkNpcManager;
class ArkNpcSpawnManager;
class ArkNpcThrowPropManager;
class ArkNpcUnreachableTargetingManager;
class ArkPatrolManager;
class ArkPostEffectManager;
class ArkResponseManager;
class ArkRetreatManager;
class ArkRoomPerceptionManager;
class ArkSeismicPerceptionManager;
class ArkSpatialManager;
class ArkTimeScaleManager;
class ArkVisualPerceptionManager;
class ArkWorldUIManager;
class CArkFlowGraphManager;
class CArkGlooIslandNavLinkManager;
class CArkPADialogManager;
class CArkProjectileGooNetworkManager;
class CArkProjectileGooPhysicsManager;
class CArkProjectilePoolManager;
class CBodyDamageManager;
class CDLCManager;
class CDataPatchDownloader;
class CDownloadMgr;
class CGameAISystem;
class CGameActions;
class CGameCache;
class CGameLocalizationManager;
class CGameMechanismManager;
class CGamePhysicsSettings;
class CGameRules;
class CGameSharedParametersStorage;
class CHitDeathReactionsSystem;
class CLightningGameEffect;
class CModInfoManager;
class CMovementTransitionsSystem;
class CParameterGameEffect;
class CPlayerVisTable;
class CRevertibleConfigLoader;
class CScreenEffects;
class CScriptBind_Actor;
class CScriptBind_Ark;
class CScriptBind_ArkBreakable;
class CScriptBind_ArkFaction;
class CScriptBind_ArkItem;
class CScriptBind_ArkKiosk;
class CScriptBind_ArkNpc;
class CScriptBind_ArkRoster;
class CScriptBind_ArkTurret;
class CScriptBind_Game;
class CScriptBind_GameAI;
class CScriptBind_GameRules;
class CScriptBind_HitDeathReactions;
class CScriptBind_Inventory;
class CScriptBind_Item;
class CScriptBind_ItemSystem;
class CScriptBind_LightningArc;
class CScriptBind_ProtectedBinds;
class CUIManager;
class CWorldBuilder;
enum class EArkLoadDisconnectReason;
enum EDifficulty;
enum ESystemEvent;
namespace Graphics
{
class CColorGradientManager;
} // namespace Graphics
struct IAntiCheatManager;
class IArkDoomClockManager;
class IArkDoor;
class IArkEncounterManager;
class IArkFactionManager;
struct IArkGlintConfigManager;
class IArkGlooIslandNavLinkManager;
class IArkGravShaft;
class IArkMetaTagManager;
class IArkNpc;
class IArkPADialogManager;
class IArkPatrolManager;
class IArkPlayer;
struct IArkPostEffectManager;
class IArkResponseManager;
struct ICVar;
struct IConsole;
struct IConsoleCmdArgs;
class ICrySizer;
struct IGameFramework;
struct IGamePhysicsSettings;
struct IGameStateRecorder;
struct IGameWarningsListener;
struct IGameplayListener;
struct ILoadGame;
struct IPlayerProfile;
struct IPlayerProfileManager;
struct ISaveGame;
class ITelemetryCollector;
struct SActionEvent;
struct SCVars;
struct SCrySessionID;
struct SInputEvent;
struct SItemStrings;
struct SRenderingPassInfo;
union UCryLobbyEventData;

// BufferUtil
// Header:  Prey/GameDll/Game.h
class BufferUtil
{ // Size=24 (0x18)
public:
	char* m_pBuffer;
	int m_pos;
	int m_size;
	bool m_bufferOverflow;

	void WriteString(const char* string, int length) { FWriteString(this, string, length); }

#if 0
	BufferUtil(int _arg0_);
	~BufferUtil();
	const char* GetBuffer();
	int GetUsedSize();
	bool Overflow();
#endif

	static inline auto FWriteString = PreyFunction<void(BufferUtil* const _this, const char* string, int length)>(0x17FBE70);
};

// CGame
// Header:  Prey/GameDll/Game.h
class CGame
	: public IGame
	, public IGameFrameworkListener
	, public IPlatformOS::IPlatformListener
	, public IInputEventListener
	, public ISystemEventListener
	, private IArkActiveUserManagerListener
{ // Size=1136 (0x470)
public:
	enum EHostMigrationState
	{
		eHMS_NotMigrating = 0,
		eHMS_WaitingForPlayers = 1,
		eHMS_Resuming = 2,
	};

	enum ERichPresenceState
	{
		eRPS_none = 0,
		eRPS_idle = 1,
		eRPS_frontend = 2,
		eRPS_lobby = 3,
		eRPS_inGame = 4,
	};

	enum ERichPresenceType
	{
		eRPT_String = 0,
		eRPT_Param1 = 1,
		eRPT_Param2 = 2,
		eRPT_Max = 3,
	};

	enum EInviteAcceptedState
	{
		eIAS_None = 0,
		eIAS_Init = 1,
		eIAS_StartAcceptInvite = 2,
		eIAS_InitProfile = 3,
		eIAS_WaitForInitProfile = 4,
		eIAS_WaitForLoadToFinish = 5,
		eIAS_DisconnectGame = 6,
		eIAS_DisconnectLobby = 7,
		eIAS_WaitForSessionDelete = 8,
		eIAS_ConfirmInvite = 9,
		eIAS_WaitForInviteConfirmation = 10,
		eIAS_InitSinglePlayer = 11,
		eIAS_WaitForInitSinglePlayer = 12,
		eIAS_WaitForSplashScreen = 13,
		eIAS_WaitForValidUser = 14,
		eIAS_InitMultiplayer = 15,
		eIAS_WaitForInitMultiplayer = 16,
		eIAS_InitOnline = 17,
		eIAS_WaitForInitOnline = 18,
		eIAS_WaitForSquadManagerEnabled = 19,
		eIAS_Accept = 20,
		eIAS_Error = 21,
	};

	enum ESaveIconMode
	{
		eSIM_Off = 0,
		eSIM_SaveStart = 1,
		eSIM_Saving = 2,
		eSIM_Finished = 3,
	};

	enum ELogoutReason
	{
		eLR_SetExclusiveController = 0,
		eLR_RemoveExclusiveController = 1,
		eLR_StorageDeviceChange = 2,
		eLR_PlatformUserSignout = 3,
	};

	// CGame::IRenderSceneListener
	// Header:  Prey/GameDll/Game.h
	struct IRenderSceneListener
	{ // Size=8 (0x8)
		virtual ~IRenderSceneListener();
		virtual void OnRenderScene(const SRenderingPassInfo& _arg0_) = 0;
	};

	// CGame::CDifficultyConfigSink
	// Header:  Prey/GameDll/Game.h
	class CDifficultyConfigSink : public ILoadConfigurationEntrySink
	{ // Size=16 (0x10)
	public:
		const char* m_szWho;

		virtual void OnLoadConfigurationEntry(const char* szKey, const char* szValue, const char* szGroup);

	#if 0
		CDifficultyConfigSink(const char* _arg0_);
	#endif

		static inline auto FOnLoadConfigurationEntry = PreyFunction<void(CGame::CDifficultyConfigSink* const _this, const char* szKey, const char* szValue, const char* szGroup)>(0x17F7680);
	};

	// CGame::CMPConfigSink
	// Header:  Prey/GameDll/Game.h
	class CMPConfigSink : public ILoadConfigurationEntrySink
	{ // Size=8 (0x8)
	public:
		virtual void OnLoadConfigurationEntry(const char* _arg0_, const char* _arg1_, const char* _arg2_);

	#if 0
		CMPConfigSink();
	#endif
	};

	// CGame::SDedicatedConfigSink
	// Header:  Prey/GameDll/Game.h
	struct SDedicatedConfigSink : public ILoadConfigurationEntrySink
	{ // Size=8 (0x8)
		virtual void OnLoadConfigurationEntry(const char* _arg0_, const char* _arg1_, const char* _arg2_);
	};

	// CGame::SPlatformInfo
	// Header:  Prey/GameDll/Game.h
	struct SPlatformInfo
	{ // Size=8 (0x8)
		EPlatform platformId;
		uint8_t devices;

	#if 0
		SPlatformInfo(EPlatform _arg0_);
	#endif
	};

	// CGame::SInviteAcceptedData
	// Header:  Prey/GameDll/Game.h
	struct SInviteAcceptedData
	{ // Size=32 (0x20)
		ECryLobbyService m_service;
		unsigned m_user;
		_smart_ptr<SCrySessionID> m_id;
		ECryLobbyError m_error;
		ECryLobbyInviteType m_type;
		bool m_bannedFromSession;
		bool m_failedToAcceptInviteAsNotSignedIn;
	};

	using BlockingConditionFunction = bool (*)();
	using GlobalRayCaster = RayCastQueue<41>;
	using GlobalIntersectionTester = IntersectionTestQueue<43>;
	using TRenderSceneListeners = std::vector<CGame::IRenderSceneListener*>;
	using TStringStringMap = std::map<string, string, stl::less_stricmp<CryStringT<char>>>;
	using TRichPresenceMap = std::map<CryFixedStringT<128>, int>;
	using DeferredKills = std::vector<unsigned int>;

	CGame::SPlatformInfo m_platformInfo;
	CGameCache* m_pGameCache;
	CRndGen m_randomGenerator;
	IGameFramework* m_pFramework;
	IConsole* m_pConsole;
	CGamePhysicsSettings* m_pGamePhysicsSettings;
	bool m_bReload;
	bool m_gameTypeMultiplayer;
	bool m_gameTypeInitialized;
	bool m_userProfileChanged;
	bool m_bLastSaveDirty;
	bool m_needsInitPatchables;
	bool m_editorDisplayHelpers;
	CScriptBind_Actor* m_pScriptBindActor;
	CScriptBind_Item* m_pScriptBindItem;
	CScriptBind_GameRules* m_pScriptBindGameRules;
	CScriptBind_Game* m_pScriptBindGame;
	CScriptBind_GameAI* m_pScriptBindGameAI;
	CScriptBind_HitDeathReactions* m_pScriptBindHitDeathReactions;
	CScriptBind_ProtectedBinds* m_pScriptBindProtected;
	CPlayerVisTable* m_pPlayerVisTable;
	CDataPatchDownloader* m_pDataPatchDownloader;
	IAntiCheatManager* m_pAntiCheatManager;
	CGameLocalizationManager* m_pGameLocalizationManager;
	ITelemetryCollector* m_telemetryCollector;
	CGameActions* m_pGameActions;
	IPlayerProfileManager* m_pPlayerProfileManager;
	bool m_inDevMode;
	bool m_hasExclusiveController;
	bool m_bExclusiveControllerConnected;
	bool m_rebindExclusiveControllerOnNextInput;
	bool m_bPausedForControllerDisconnect;
	bool m_bPausedForSystemMenu;
	bool m_bDeferredSystemMenuPause;
	bool m_previousPausedGameState;
	bool m_wasGamePausedByPLM;
	uint64_t m_exclusiveControllerDeviceId;
	int m_currentXboxLivePartySize;
	unsigned m_clientActorId;
	SCVars* m_pCVars;
	SItemStrings* m_pItemStrings;
	CGameSharedParametersStorage* m_pGameParametersStorage;
	string m_lastSaveGame;
	CScreenEffects* m_pScreenEffects;
	CDownloadMgr* m_pDownloadMgr;
	CDLCManager* m_pDLCManager;
	CLightningGameEffect* m_pLightningGameEffect;
	CParameterGameEffect* m_pParameterGameEffect;
	CWorldBuilder* m_pWorldBuilder;
	IInputEventListener* m_pInputEventListenerOverride;
	std::map<string, string, stl::less_stricmp<CryStringT<char>>> m_variantOptions;
	std::map<CryFixedStringT<128>, int> m_richPresence;
	std::vector<CGame::IRenderSceneListener*> m_renderSceneListeners;
	Graphics::CColorGradientManager* m_colorGradientManager;
	CGameAISystem* m_pGameAISystem;
	RayCastQueue<41>* m_pRayCaster;
	IntersectionTestQueue<43>* m_pIntersectionTester;
	CUIManager* m_pUIManager;
	CHitDeathReactionsSystem* m_pHitDeathReactionsSystem;
	CBodyDamageManager* m_pBodyDamageManager;
	CMovementTransitionsSystem* m_pMovementTransitionsSystem;
	CGameMechanismManager* m_gameMechanismManager;
	CModInfoManager* m_pModInfoManager;
	float m_hostMigrationTimeStateChanged;
	float m_hostMigrationNetTimeoutLength;
	CGame::EHostMigrationState m_hostMigrationState;
	CGame::ERichPresenceState m_desiredRichPresenceState;
	CGame::ERichPresenceState m_pendingRichPresenceState;
	CGame::ERichPresenceState m_currentRichPresenceState;
	_smart_ptr<SCrySessionID> m_pendingRichPresenceSessionID;
	_smart_ptr<SCrySessionID> m_currentRichPresenceSessionID;
	float m_updateRichPresenceTimer;
	bool m_settingRichPresence;
	bool m_bRefreshRichPresence;
	bool m_bSignInOrOutEventOccured;
	CGame::SInviteAcceptedData m_inviteAcceptedData;
	CGame::EInviteAcceptedState m_inviteAcceptedState;
	bool m_bLoggedInFromInvite;
	bool m_gameDataInstalled;
	bool m_postLocalisationBootChecksDone;
	CTimeValue m_levelStartTime;
	int m_iCachedGsmValue;
	float m_fCachedGsmRangeValue;
	float m_fCachedGsmRangeStepValue;
	CGame::ESaveIconMode m_saveIconMode;
	float m_saveIconTimer;
	int m_cachedUserRegion;
	bool m_bUserHasPhysicalStorage;
	bool m_bCheckPointSave;
	std::vector<unsigned int> m_deferredKills;
	std::unique_ptr<ArkAiManager> m_pArkAiManager;
	std::unique_ptr<ArkAttentionManager> m_pArkAttentionManager;
	std::unique_ptr<ArkAttractionManager> m_pArkAttractionManager;
	std::unique_ptr<ArkAuralPerceptionManager> m_pArkAuralPerceptionManager;
	std::unique_ptr<ArkCharacterManager> m_pArkCharacterManager;
	std::unique_ptr<ArkCombatManager> m_pArkCombatManager;
	std::unique_ptr<ArkCystoidManager> m_pArkCystoidManager;
	std::unique_ptr<ArkDistractionEntitySink> m_pArkDistractionEntitySink;
	std::unique_ptr<ArkDistractionManager> m_pArkDistractionManager;
	std::unique_ptr<ArkDoomClockManager> m_pArkDoomClockManager;
	std::unique_ptr<ArkDynamicCorpseManager> m_pArkDynamicCorpseManager;
	std::unique_ptr<ArkDynamicCalledMimicManager> m_pArkDynamicCalledMimicManager;
	std::unique_ptr<ArkEncounterManager> m_pArkEncounterManager;
	std::unique_ptr<CArkFlowGraphManager> m_pArkFlowGraphManager;
	std::unique_ptr<ArkEthericFogManager> m_pArkEthericFogManager;
	std::unique_ptr<ArkFactionManager> m_pArkFactionManager;
	std::unique_ptr<ArkGameDataManager> m_pArkGameDataManager;
	std::unique_ptr<ArkGlintConfigManager> m_pArkGlintConfigManager;
	std::unique_ptr<CArkGlooIslandNavLinkManager> m_pArkGlooIslandNavLinkManager;
	std::unique_ptr<ArkInstigationManager> m_pArkInstigationManager;
	std::unique_ptr<ArkLightTimeManager> m_pArkLightTimeManager;
	std::unique_ptr<ArkListenerManager> m_pArkListenerManager;
	std::unique_ptr<ArkLurkManager> m_pArkLurkManager;
	std::unique_ptr<ArkMetaTagManager> m_pArkMetaTagManager;
	std::unique_ptr<ArkMoonRockManager> m_pArkMoonRockManager;
	std::unique_ptr<ArkNightmareEtherformManager> m_pArkNightmareEtherformManager;
	std::unique_ptr<ArkNightmareSpawnManager> m_pArkNightmareSpawnManager;
	std::unique_ptr<ArkNpcAbilityManager> m_pArkNpcAbilityManager;
	std::unique_ptr<ArkNpcAreaManager> m_pArkNpcAreaManager;
	std::unique_ptr<ArkNpcBlackboardManager> m_pArkNpcBlackboardManager;
	std::unique_ptr<ArkNpcGameEffectManager> m_pArkNpcGameEffectManager;
	std::unique_ptr<ArkNpcManager> m_pArkNpcManager;
	std::unique_ptr<ArkNpcSpawnManager> m_pArkNpcSpawnManager;
	std::unique_ptr<ArkNpcThrowPropManager> m_pArkNpcThrowPropManager;
	std::unique_ptr<ArkNpcUnreachableTargetingManager> m_pArkNpcUnreachableTargetingManager;
	std::unique_ptr<CArkPADialogManager> m_pArkPADialogManager;
	std::unique_ptr<ArkPatrolManager> m_pArkPatrolManager;
	std::unique_ptr<ArkPostEffectManager> m_pArkPostEffectManager;
	std::unique_ptr<CArkProjectileGooNetworkManager> m_pArkProjectileGooNetworkManager;
	std::unique_ptr<CArkProjectileGooPhysicsManager> m_pArkProjectileGooPhysicsManager;
	std::unique_ptr<CArkProjectilePoolManager> m_pArkProjectilePoolManager;
	std::unique_ptr<ArkResponseManager> m_pArkResponseManager;
	std::unique_ptr<ArkRetreatManager> m_pArkRetreatManager;
	std::unique_ptr<ArkRoomPerceptionManager> m_pArkRoomPerceptionManager;
	std::unique_ptr<ArkSeismicPerceptionManager> m_pArkSeismicPerceptionManager;
	std::unique_ptr<ArkSpatialManager> m_pArkSpatialManager;
	std::unique_ptr<ArkTimeScaleManager> m_pArkTimeScaleManager;
	std::unique_ptr<ArkVisualPerceptionManager> m_pArkVisualPerceptionManager;
	std::unique_ptr<ArkWorldUIManager> m_pArkWorldUIManager;
	CScriptBind_Ark* m_pScriptBindArk;
	std::unique_ptr<CScriptBind_ArkBreakable> m_pScriptBindArkBreakable;
	std::unique_ptr<CScriptBind_ArkItem> m_pScriptBindArkItem;
	std::unique_ptr<CScriptBind_ArkFaction> m_pScriptBindArkFaction;
	std::unique_ptr<CScriptBind_ArkKiosk> m_pScriptBindArkKiosk;
	std::unique_ptr<CScriptBind_ArkNpc> m_pScriptBindArkNpc;
	std::unique_ptr<CScriptBind_ArkRoster> m_pScriptBindArkRoster;
	std::unique_ptr<CScriptBind_ArkTurret> m_pScriptBindArkTurret;
	std::unique_ptr<CScriptBind_Inventory> m_pScriptBindInventory;
	std::unique_ptr<CScriptBind_ItemSystem> m_pScriptBindItemSystem;
	std::unique_ptr<CScriptBind_LightningArc> m_pScriptBindLightningArc;
	string m_arkLoadLocation;
	XmlNodeRef m_gameLevelToLevelSave;
	std::unique_ptr<ArkGame> m_pArkGame;
	std::unique_ptr<ArkActiveUserManagerBase> m_pActiveUserManager;

	CGame();
	virtual ~CGame();
	virtual bool Init(IGameFramework* pFramework);
	virtual bool CompleteInit();
	virtual void Shutdown();
	virtual int Update(bool haveFocus, unsigned updateFlags);
	virtual void EditorResetGame(bool bStart);
	virtual void PlayerIdSet(unsigned playerId);
	virtual bool IsReloading();
	virtual IGameFramework* GetIGameFramework();
	virtual const char* GetLongName();
	virtual const char* GetName();
	virtual EPlatform GetPlatform() const;
	virtual void UploadSessionTelemetry();
	virtual void ClearSessionTelemetry();
	virtual void GetMemoryStatistics(ICrySizer* s);
	virtual void OnClearPlayerIds();
	virtual CryStackStringT<char,256> CreateSaveGameName();
	virtual const char* GetMappedLevelName(const char* levelName) const;
	void LoadPatchLocalizationData() { FLoadPatchLocalizationData(this); }
	virtual IGameStateRecorder* CreateGameStateRecorder(IGameplayListener* pL);
	virtual const bool DoInitialSavegame() const;
	virtual unsigned AddGameWarning(const char* stringId, const char* paramMessage, IGameWarningsListener* pListener);
	virtual void RemoveGameWarning(const char* stringId);
	virtual void RenderGameWarnings();
	virtual void OnRenderScene(const SRenderingPassInfo& passInfo);
	virtual bool GameEndLevel(const char* nextLevel);
	virtual void SetUserProfileChanged(bool yesNo);
	virtual IGame::ExportFilesInfo ExportLevelData(const char* levelName, const char* missionName) const;
	virtual const char* ExportAudioPropagation(const char* _levelName) const;
	virtual void LoadExportedLevelData(const char* levelName, const char* missionName);
	virtual void LoadAudioPropagation(const char* _levelName);
	virtual const uint8_t* GetDRMKey(unsigned* pKeySize);
	virtual const char* GetDRMFileList();
	virtual void RegisterGameFlowNodes();
	virtual IGamePhysicsSettings* GetIGamePhysicsSettings();
	virtual void OnPostUpdate(float fDeltaTime);
	virtual void OnSaveGame(ISaveGame* pSaveGame);
	virtual void OnLoadGame(ILoadGame* pLoadGame);
	virtual void OnLevelEnd(const char* nextLevel);
	virtual void OnActionEvent(const SActionEvent& event);
	virtual void OnSavegameFileLoadedInMemory(const char* pLevelName);
	virtual void OnForceLoadingWithFlash();
	void PreSerialize() { FPreSerialize(this); }
	virtual void FullSerializeBeforeEntities(TSerialize serializer);
	virtual void FullSerialize(TSerialize serializer);
	virtual void SerializeForLevelState(TSerialize serializer);
	virtual void PostSerialize();
	virtual void PostSerializeForLevelState();
	virtual bool CanSave() const;
	virtual void PostSerializeBeforeEntities();
	virtual void SerializeLTL(bool _bReading);
	virtual const bool LevelIsTalosExterior() const;
	virtual bool OnInputEvent(const SInputEvent& inputEvent);
	virtual bool OnInputEventUI(const SInputEvent& inputEvent);
	void RemoveExclusiveController() { FRemoveExclusiveController(this); }
	virtual void OnPlatformEvent(const IPlatformOS::SPlatformEvent& event);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual void* GetGameInterface();
	void InitRichPresence() { FInitRichPresence(this); }
	void AddRichPresence(const char* path) { FAddRichPresence(this, path); }
	virtual unsigned GetExclusiveControllerDeviceIndex() const;
	virtual unsigned GetPlatformUserIdPairedToDevice(uint64_t deviceId) const;
	virtual unsigned GetCurrentUserPlatformUserId() const;
	virtual unsigned GetPlayerProfilePlatformUserId(const char* profileName) const;
	virtual bool IsPlayerProfileSignedInToOS(const char* profileName) const;
	virtual bool IsPlatformUserSignedInToOS(unsigned userId) const;
	virtual void RefreshControlScheme() const;
	void SetActiveUser(unsigned platformUserId) { FSetActiveUser(this, platformUserId); }
	void ClearActiveUser() { FClearActiveUser(this); }
	void LoginUser(unsigned platformUserId) { FLoginUser(this, platformUserId); }
	void InitGameType(bool multiplayer, bool fromInit) { FInitGameType(this, multiplayer, fromInit); }
	void InitPatchableModules(bool inIsMultiplayer) { FInitPatchableModules(this, inIsMultiplayer); }
	void SetDifficultyLevel(EDifficulty difficulty) { FSetDifficultyLevel(this, difficulty); }
	virtual IAntiCheatManager* GetAntiCheatManager();
	CGameRules* GetGameRules() const { return FGetGameRules(this); }
	const string& GetLastSaveGame(string& levelName, string& locationName) { return FGetLastSaveGameOv1(this, levelName, locationName); }
	Graphics::CColorGradientManager& GetColorGradientManager() { return FGetColorGradientManager(this); }
	bool HasIntersectionTester() const { return FHasIntersectionTester(this); }
	float GetTimeSinceHostMigrationStateChanged() const { return FGetTimeSinceHostMigrationStateChanged(this); }
	float GetRemainingHostMigrationTimeoutTime() const { return FGetRemainingHostMigrationTimeoutTime(this); }
	void SetHostMigrationState(CGame::EHostMigrationState newState) { FSetHostMigrationState(this, newState); }
	void SetHostMigrationStateAndTime(CGame::EHostMigrationState newState, float timeOfChange) { FSetHostMigrationStateAndTime(this, newState, timeOfChange); }
	void AbortHostMigration() { FAbortHostMigration(this); }
	virtual void LoadActionMaps(const char* filename);
	void QueueDeferredKill(const unsigned entityID) { FQueueDeferredKill(this, entityID); }
	virtual IArkDoomClockManager& GetIArkDoomClockManager() const;
	virtual IArkDoor* GetIArkDoorSafe(unsigned _entityId) const;
	virtual IArkEncounterManager& GetIArkEncounterManager() const;
	virtual IArkFactionManager& GetIArkFactionManager() const;
	virtual IArkGlintConfigManager& GetIArkGlintConfigManager() const;
	virtual IArkGravShaft* GetIArkGravShaftSafe(unsigned _entityId) const;
	virtual IArkMetaTagManager& GetIArkMetaTagManager() const;
	virtual IArkPADialogManager& GetIArkPADialogManager() const;
	virtual IArkPatrolManager& GetIArkPatrolManager() const;
	virtual IArkPlayer* GetIArkPlayerPtr() const;
	virtual IArkPostEffectManager& GetIArkPostEffectManager() const;
	virtual IArkResponseManager& GetIArkResponseManager() const;
	virtual IArkGlooIslandNavLinkManager& GetIArkGlooIslandNavLinkManager() const;
	virtual IArkNpc* SafeGetIArkNpc(unsigned _entityId) const;
	ArkItemSystem& GetArkItemSystem() const { return FGetArkItemSystem(this); }
	virtual void AddArkGameNoise(const unsigned _emitter, const Vec3& _position, const uint64_t _type, const uint64_t _loudness);
	void AddArkGameNoise(const unsigned _emitterId, const Vec3& _position, const ArkGameNoiseInfo& _noiseInfo, const uint64_t _loudness) { FAddArkGameNoiseOv0(this, _emitterId, _position, _noiseInfo, _loudness); }
	virtual void TryAddArkSeismicEffectAtLocation(unsigned _emitterEntityId, const Vec3& _position, float _magnitude) const;
	virtual void AddArkSeismicEvent(unsigned _emitterEntityId, const Vec3& _position, float _magnitude) const;
	virtual void OnNewGame(const int _campaignSlot);
	virtual void ResetGameState();
	virtual void OnLevelToLevelTransition();
	virtual void OnLevelTransitionFinished();
	virtual void LoadArkLevelProperties(const XmlNodeRef& _node);
	virtual void SetArkAutoMapScale(const float _scale);
	virtual XmlNodeRef GetArkLevelProperties();
	virtual const char* GetCurrentArkLocationLabel() const;
	virtual void SetArkLoadLocationLabel(const char* const _pLocation);
	virtual const char* GetArkLoadLocationLabel() const;
	virtual const char* GetArkLoadingScreenTip(bool _bUseLevelTip) const;
	virtual const char* GetArkGameMode() const;
	virtual void OnSaveDeletedBySystem();
	virtual void RequestDisconnect(EArkLoadDisconnectReason _reason);
	virtual void RequestPause(const bool _bPause);
	virtual EArkLoadDisconnectReason GetDisconnectReason() const;
	virtual void CheckSaveStatusOnReturnToMainMenu() const;
	virtual void DebugDraw() const;
	virtual void UnlockPlayerCamera(float _interpolateToUnlockTime) const;
	virtual void LockPlayerCameraToAnimation(float _interpolateToLockTime) const;
	virtual void LockPlayerCameraToEntityBone(const unsigned _entityId, const int _attachmentIndex, float _interpolateToLockTime) const;
	virtual std::vector<IGame::CaptureVolumeInfo> GetCaptureVolumeInfos() const;
	virtual void OpenPauseMenu(bool open);
	virtual void DumpObjectiveStateToFile(const char* _fileName) const;
	void OnNeuromodUsed(const uint64_t& _abilityId, bool _bIsAlienPower) { FOnNeuromodUsed(this, _abilityId, _bIsAlienPower); }
	void InitScriptBinds() { FInitScriptBinds(this); }
	void UpdateSaveIcon() { FUpdateSaveIcon(this); }
	virtual void CheckReloadLevel();
	virtual void RegisterConsoleVars();
	virtual void RegisterConsoleCommands();
	virtual void UnregisterConsoleCommands();
	virtual void RegisterGameObjectEvents();
	static void CmdRestartGame(IConsoleCmdArgs* pArgs) { FCmdRestartGame(pArgs); }
	static void CmdDumpAmmoPoolStats(IConsoleCmdArgs* pArgs) { FCmdDumpAmmoPoolStats(pArgs); }
	static void CmdName(IConsoleCmdArgs* pArgs) { FCmdName(pArgs); }
	static void CmdTeam(IConsoleCmdArgs* pArgs) { FCmdTeam(pArgs); }
	static void CmdSpectator(IConsoleCmdArgs* pArgs) { FCmdSpectator(pArgs); }
	static void CmdJoinGame(IConsoleCmdArgs* pArgs) { FCmdJoinGame(pArgs); }
	static void CmdKill(IConsoleCmdArgs* pArgs) { FCmdKill(pArgs); }
	static void CmdTakeDamage(IConsoleCmdArgs* pArgs) { FCmdTakeDamage(pArgs); }
	static void CmdRestart(IConsoleCmdArgs* pArgs) { FCmdRestart(pArgs); }
	static void CmdSay(IConsoleCmdArgs* pArgs) { FCmdSay(pArgs); }
	static void CmdEcho(IConsoleCmdArgs* pArgs) { FCmdEcho(pArgs); }
	static void CmdLoadActionmap(IConsoleCmdArgs* pArgs) { FCmdLoadActionmap(pArgs); }
	static void CmdReloadGameRules(IConsoleCmdArgs* pArgs) { FCmdReloadGameRules(pArgs); }
	static void CmdNextLevel(IConsoleCmdArgs* pArgs) { FCmdNextLevel(pArgs); }
	static void CmdReloadHitDeathReactions(IConsoleCmdArgs* pArgs) { FCmdReloadHitDeathReactions(pArgs); }
	static void CmdDumpHitDeathReactionsAssetUsage(IConsoleCmdArgs* pArgs) { FCmdDumpHitDeathReactionsAssetUsage(pArgs); }
	static void CmdReloadSpectacularKill(IConsoleCmdArgs* pArgs) { FCmdReloadSpectacularKill(pArgs); }
	static void CmdReloadPickAndThrowProxies(IConsoleCmdArgs* pArgs) { FCmdReloadPickAndThrowProxies(pArgs); }
	static void CmdReloadMovementTransitions(IConsoleCmdArgs* pArgs) { FCmdReloadMovementTransitions(pArgs); }
	static void CmdStartKickVoting(IConsoleCmdArgs* pArgs) { FCmdStartKickVoting(pArgs); }
	static void CmdVote(IConsoleCmdArgs* pArgs) { FCmdVote(pArgs); }
	static void CmdListAllRandomLoadingMessages(IConsoleCmdArgs* pArgs) { FCmdListAllRandomLoadingMessages(pArgs); }
	static bool IsFreeCamActive() { return FIsFreeCamActive(); }
	static void CmdFreeCamEnable(IConsoleCmdArgs* pArgs) { FCmdFreeCamEnable(pArgs); }
	static void CmdFreeCamDisable(IConsoleCmdArgs* pArgs) { FCmdFreeCamDisable(pArgs); }
	static void CmdFreeCamLockCamera(IConsoleCmdArgs* pArgs) { FCmdFreeCamLockCamera(pArgs); }
	static void CmdFreeCamUnlockCamera(IConsoleCmdArgs* pArgs) { FCmdFreeCamUnlockCamera(pArgs); }
	static void CmdFlyCamSetPoint(IConsoleCmdArgs* pArgs) { FCmdFlyCamSetPoint(pArgs); }
	static void CmdFlyCamPlay(IConsoleCmdArgs* pArgs) { FCmdFlyCamPlay(pArgs); }
	static void CmdIgnoreAllAsserts(IConsoleCmdArgs* pArgs) { FCmdIgnoreAllAsserts(pArgs); }
	static void CmdReloadPlayer(IConsoleCmdArgs* pArgs) { FCmdReloadPlayer(pArgs); }
	static void CmdSetPlayerHealth(IConsoleCmdArgs* pArgs) { FCmdSetPlayerHealth(pArgs); }
	static void CmdSwitchGameMultiplayer(IConsoleCmdArgs* pArgs) { FCmdSwitchGameMultiplayer(pArgs); }
	static void CmdSpawnActor(IConsoleCmdArgs* pArgs) { FCmdSpawnActor(pArgs); }
	static void CmdReloadGameFx(IConsoleCmdArgs* pArgs) { FCmdReloadGameFx(pArgs); }
	static void OnHostMigrationNetTimeoutChanged(ICVar* pVar) { FOnHostMigrationNetTimeoutChanged(pVar); }
	static void VerifyMaxPlayers(ICVar* pVar) { FVerifyMaxPlayers(pVar); }
	static void PartyMembersCallback(UCryLobbyEventData eventData, void* arg) { FPartyMembersCallback(eventData, arg); }
	static void UserProfileChangedCallback(UCryLobbyEventData eventData, void* arg) { FUserProfileChangedCallback(eventData, arg); }
	static void InviteAcceptedCallback(UCryLobbyEventData eventData, void* arg) { FInviteAcceptedCallback(eventData, arg); }
	static void OnlineStateCallback(UCryLobbyEventData eventData, void* arg) { FOnlineStateCallback(eventData, arg); }
	static void EthernetStateCallback(UCryLobbyEventData eventData, void* arg) { FEthernetStateCallback(eventData, arg); }
	virtual void OnActiveUserIdChanged(unsigned platformUserId);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual void OnActiveUserSignedOut();

#if 0
	void OnEditorGameInitComplete();
	void OnBeforeEditorLevelLoad();
	int GetDifficultyForTelemetry(int _arg0_) const;
	int GetCheckpointIDForTelemetry(const char* _arg0_) const;
	void OnExitGameSession();
	void SetInputEventListenerOverride(IInputEventListener* _arg0_);
	void AddRenderSceneListener(CGame::IRenderSceneListener* _arg0_);
	void RemoveRenderSceneListener(CGame::IRenderSceneListener* _arg0_);
	void SetExclusiveController(uint64_t _arg0_);
	void RebindExclusiveControllerOnNextInput();
	uint64_t GetExclusiveControllerDeviceId() const;
	ArkActiveUserManagerBase& GetActiveUserManager();
	bool HasExclusiveControllerIndex() const;
	bool IsExclusiveControllerConnected() const;
	bool IsPausedForControllerDisconnect() const;
	uint64_t GetControllerDeviceId(unsigned _arg0_) const;
	bool SetControllerLayouts(const char* _arg0_, const char* _arg1_, bool _arg2_);
	bool ShouldShowLanguageSelect();
	static void SetRichPresenceCallback(unsigned _arg0_, ECryLobbyError _arg1_, void* _arg2_);
	void RefreshRichPresence();
	_smart_ptr<SCrySessionID> GetPendingRichPresenceSessionID();
	IPlayerProfile* ChoosePlayerProfile(uint64_t _arg0_);
	void ReloadPlayerParamFiles();
	void LogoutCurrentUser(CGame::ELogoutReason _arg0_);
	void ResetSignInOrOutEventOccured();
	bool SignInOrOutEventOccured() const;
	bool IsGameTypeFullyInitialised() const;
	void DestroyHUD();
	bool IsGameActive() const;
	CScriptBind_HitDeathReactions* GetHitDeathReactionsScriptBind();
	CScriptBind_Actor* GetActorScriptBind();
	CScriptBind_Item* GetItemScriptBind();
	CScriptBind_GameRules* GetGameRulesScriptBind();
	CGamePhysicsSettings* GetGamePhysicsSettings();
	CGameSharedParametersStorage* GetGameSharedParametersStorage();
	CDataPatchDownloader* GetDataPatchDownloader();
	CGameLocalizationManager* GetGameLocalizationManager();
	ITelemetryCollector* GetITelemetryCollector();
	CGameActions& Actions() const;
	bool IsLevelLoaded() const;
	CPlayerVisTable* GetPlayerVisTable();
	CLightningGameEffect* GetLightningGameEffect();
	CParameterGameEffect* GetParameterGameEffect();
	CScreenEffects* GetScreenEffects() const;
	CHitDeathReactionsSystem& GetHitDeathReactionsSystem() const;
	CMovementTransitionsSystem& GetMovementTransitionsSystem() const;
	CBodyDamageManager* GetBodyDamageManager();
	const CBodyDamageManager* GetBodyDamageManager() const;
	const string& GetLastSaveGame();
	void SetLastSaveDirty();
	SCVars* GetCVars();
	static void DumpMemInfo(const char* _arg0_, ... _arg1_);
	CGameAISystem* GetGameAISystem();
	RayCastQueue<41>& GetRayCaster();
	IntersectionTestQueue<43>& GetIntersectionTester();
	void ClearGameSessionHandler();
	CDownloadMgr* GetDownloadMgr();
	CDLCManager* GetDLCManager();
	CWorldBuilder* GetWorldBuilder();
	CGameCache& GetGameCache();
	const CGameCache& GetGameCache() const;
	CUIManager* GetUI();
	CModInfoManager* GetModInfoManager() const;
	static void ExpandTimeSeconds(int _arg0_, int& _arg1_, int& _arg2_, int& _arg3_, int& _arg4_);
	int GetCurrentXboxLivePartySize();
	float GetHostMigrationTimeTillResume() const;
	CGame::EHostMigrationState GetHostMigrationState() const;
	bool IsGameSessionHostMigrating() const;
	bool GetUserProfileChanged() const;
	bool GameDataInstalled() const;
	bool BootChecksComplete() const;
	void SetUserRegion(int _arg0_);
	int GetUserRegion() const;
	unsigned GetRandomNumber();
	float GetRandomFloat();
	void SetInviteAcceptedState(CGame::EInviteAcceptedState _arg0_);
	CGame::EInviteAcceptedState GetInviteAcceptedState();
	void SetInviteData(ECryLobbyService _arg0_, unsigned _arg1_, _smart_ptr<SCrySessionID> _arg2_, ECryLobbyError _arg3_, ECryLobbyInviteType _arg4_);
	void InvalidateInviteData();
	void UpdateInviteAcceptedState();
	void SetInviteUserFromPreviousControllerIndex();
	const int GetInviteUser() const;
	const bool IsInviteInProgress() const;
	int GetCachedGsmValue();
	float GetCachedGsmRangeValue();
	float GetCachedGsmRangeStepValue();
	void SetCrashDebugMessage(const char* const _arg0_);
	void AppendCrashDebugMessage(const char* const _arg0_);
	CRevertibleConfigLoader& GetGameModeCVars();
	void OnDedicatedConfigEntry(const char* _arg0_, const char* _arg1_);
	unsigned GetClientActorId() const;
	void OnEditorDisplayRenderUpdated(bool _arg0_);
	bool DisplayEditorHelpersEnabled() const;
	float GetFOV() const;
	float GetPowerSprintTargetFov() const;
	ArkAiManager& GetArkAiManager() const;
	ArkAttentionManager& GetArkAttentionManager() const;
	ArkAttractionManager& GetArkAttractionManager() const;
	ArkAuralPerceptionManager& GetArkAuralPerceptionManager() const;
	ArkRoomPerceptionManager& GetArkRoomPerceptionManager() const;
	ArkCharacterManager& GetArkCharacterManager() const;
	ArkCombatManager& GetArkCombatManager() const;
	ArkDistractionEntitySink& GetArkDistractionEntitySink() const;
	ArkDistractionManager& GetArkDistractionManager() const;
	ArkDoomClockManager& GetArkDoomClockManager() const;
	ArkDynamicCorpseManager& GetArkDynamicCorpseManager() const;
	ArkDynamicCalledMimicManager& GetArkDynamicCalledMimicManager() const;
	ArkEthericFogManager& GetArkEthericFogManager() const;
	ArkFactionManager& GetArkFactionManager() const;
	CArkFlowGraphManager& GetArkFlowGraphManager() const;
	ArkGameDataManager& GetArkGameDataManager();
	const ArkGameDataManager& GetArkGameDataManager() const;
	ArkGlintConfigManager& GetArkGlintConfigManager() const;
	ArkInstigationManager& GetArkInstigationManager() const;
	ArkCystoidManager& GetArkCystoidManager() const;
	ArkLightTimeManager& GetArkLightTimeManager() const;
	ArkListenerManager& GetArkListenerManager() const;
	ArkMoonRockManager& GetArkMoonRockManager() const;
	ArkNightmareEtherformManager& GetArkNightmareEtherformManager() const;
	ArkNightmareSpawnManager& GetArkNightmareSpawnManager() const;
	ArkNpcAbilityManager& GetArkNpcAbilityManager() const;
	ArkNpcAreaManager& GetArkNpcAreaManager() const;
	ArkNpcBlackboardManager& GetArkNpcBlackboardManager() const;
	ArkNpcGameEffectManager& GetArkNpcGameEffectManager() const;
	ArkNpcManager& GetArkNpcManager() const;
	ArkNpcThrowPropManager& GetArkNpcThrowPropManager() const;
	ArkNpcUnreachableTargetingManager& GetArkNpcUnreachableTargetingManager() const;
	ArkNpcSpawnManager& GetArkNpcSpawnManager() const;
	ArkMetaTagManager& GetArkMetaTagManager() const;
	CArkPADialogManager& GetArkPADialogManager() const;
	ArkPatrolManager& GetArkPatrolManager() const;
	ArkEncounterManager& GetArkEncounterManager() const;
	ArkPostEffectManager& GetArkPostEffectManager() const;
	CArkGlooIslandNavLinkManager& GetArkGlooIslandNavLinkManager() const;
	ArkLurkManager& GetArkLurkManager() const;
	CArkProjectileGooPhysicsManager& GetArkProjectileGooPhysicsManager() const;
	CArkProjectileGooNetworkManager& GetArkProjectileGooNetworkManager() const;
	CArkProjectilePoolManager& GetArkProjectilePoolManager() const;
	ArkResponseManager& GetArkResponseManager() const;
	ArkRetreatManager& GetArkRetreatManager() const;
	ArkSeismicPerceptionManager& GetArkSeismicPerceptionManager() const;
	ArkSpatialManager& GetArkSpatialManager() const;
	ArkTimeScaleManager& GetArkTimeScaleManager() const;
	ArkVisualPerceptionManager& GetArkVisualPerceptionManager() const;
	ArkWorldUIManager& GetArkWorldUIManager() const;
	bool HasArkResponseManager() const;
	CScriptBind_ArkBreakable& GetArkBreakableScriptBind() const;
	CScriptBind_ArkItem& GetArkItemScriptBind() const;
	CScriptBind_ArkNpc& GetArkNpcScriptBind() const;
	CScriptBind_ArkTurret& GetArkTurretScriptBind() const;
	CScriptBind_Inventory& GetInventoryScriptBind() const;
	CScriptBind_ItemSystem& GetItemSystemScriptBind() const;
	CScriptBind_LightningArc& GetLightingArcScriptBind() const;
	void InitPlatformOS();
	void ReleaseScriptBinds();
	static void CmdReloadItems(IConsoleCmdArgs* _arg0_);
	static void CmdReloadSkillSystem(IConsoleCmdArgs* _arg0_);
	static void CmdReportLag(IConsoleCmdArgs* _arg0_);
	static void GetTelemetryTimers(int& _arg0_, int& _arg1_, int& _arg2_, void* _arg3_);
	void CommitDeferredKills();
	void RefreshPlayerProfilePlatformData();
	void PLMPauseGame();
	void PLMResumeGame();
	std::map<string, string, stl::less_stricmp<CryStringT<char>>>* GetVariantOptions();
#endif

	static inline auto FCGame = PreyFunction<void(CGame* const _this)>(0x17E7350);
	static inline auto FBitNotCGame = PreyFunction<void(CGame* const _this)>(0x17EB090);
	static inline auto FInit = PreyFunction<bool(CGame* const _this, IGameFramework* pFramework)>(0x17F4560);
	static inline auto FCompleteInit = PreyFunction<bool(CGame* const _this)>(0x17F2F50);
	static inline auto FShutdown = PreyFunction<void(CGame* const _this)>(0x17F9B50);
	static inline auto FUpdate = PreyFunction<int(CGame* const _this, bool haveFocus, unsigned updateFlags)>(0x17F9D70);
	static inline auto FEditorResetGame = PreyFunction<void(CGame* const _this, bool bStart)>(0x17F32F0);
	static inline auto FPlayerIdSet = PreyFunction<void(CGame* const _this, unsigned playerId)>(0x159D2B0);
	static inline auto FIsReloading = PreyFunction<bool(CGame* const _this)>(0x12E67E0);
	static inline auto FGetIGameFramework = PreyFunction<IGameFramework* (CGame* const _this)>(0x9F24D0);
	static inline auto FGetLongName = PreyFunction<const char* (CGame* const _this)>(0x17F4300);
	static inline auto FGetName = PreyFunction<const char* (CGame* const _this)>(0x17F44D0);
	static inline auto FGetPlatform = PreyFunction<EPlatform(const CGame* const _this)>(0x1948930);
	static inline auto FUploadSessionTelemetry = PreyFunction<void(CGame* const _this)>(0x17FAFC0);
	static inline auto FClearSessionTelemetry = PreyFunction<void(CGame* const _this)>(0x1333E90);
	static inline auto FGetMemoryStatistics = PreyFunction<void(CGame* const _this, ICrySizer* s)>(0x17F4310);
	static inline auto FOnClearPlayerIds = PreyFunction<void(CGame* const _this)>(0x1333E90);
	static inline auto FCreateSaveGameName = PreyFunction<CryStackStringT<char,256>*(CGame* const _this, CryStackStringT<char,256>* _return_value_)>(0x17F2F70);
	static inline auto FGetMappedLevelName = PreyFunction<const char* (const CGame* const _this, const char* levelName)>(0x1088870);
	static inline auto FLoadPatchLocalizationData = PreyFunction<void(CGame* const _this)>(0x17F6480);
	static inline auto FCreateGameStateRecorder = PreyFunction<IGameStateRecorder* (CGame* const _this, IGameplayListener* pL)>(0x1CBB0B0);
	static inline auto FDoInitialSavegame = PreyFunction<const bool(const CGame* const _this)>(0x1A302A0);
	static inline auto FAddGameWarning = PreyFunction<unsigned(CGame* const _this, const char* stringId, const char* paramMessage, IGameWarningsListener* pListener)>(0x1CBB0B0);
	static inline auto FRemoveGameWarning = PreyFunction<void(CGame* const _this, const char* stringId)>(0x1333E90);
	static inline auto FRenderGameWarnings = PreyFunction<void(CGame* const _this)>(0x1333E90);
	static inline auto FOnRenderScene = PreyFunction<void(CGame* const _this, const SRenderingPassInfo& passInfo)>(0x17F7C70);
	static inline auto FGameEndLevel = PreyFunction<bool(CGame* const _this, const char* nextLevel)>(0x13B0900);
	static inline auto FSetUserProfileChanged = PreyFunction<void(CGame* const _this, bool yesNo)>(0x17F9B40);
	static inline auto FExportLevelData = PreyFunction<IGame::ExportFilesInfo*(const CGame* const _this, IGame::ExportFilesInfo* _return_value_, const char* levelName, const char* missionName)>(0x17F3950);
	static inline auto FExportAudioPropagation = PreyFunction<const char* (const CGame* const _this, const char* _levelName)>(0x17F38F0);
	static inline auto FLoadExportedLevelData = PreyFunction<void(CGame* const _this, const char* levelName, const char* missionName)>(0x17F6410);
	static inline auto FLoadAudioPropagation = PreyFunction<void(CGame* const _this, const char* _levelName)>(0x17F6370);
	static inline auto FGetDRMKey = PreyFunction<const uint8_t* (CGame* const _this, unsigned* pKeySize)>(0x17F3E40);
	static inline auto FGetDRMFileList = PreyFunction<const char* (CGame* const _this)>(0x17F3E30);
	static inline auto FRegisterGameFlowNodes = PreyFunction<void(CGame* const _this)>(0x17F8FA0);
	static inline auto FGetIGamePhysicsSettings = PreyFunction<IGamePhysicsSettings* (CGame* const _this)>(0x3E0300);
	static inline auto FOnPostUpdate = PreyFunction<void(IGameFrameworkListener* const _this, float fDeltaTime)>(0x17F7C60);
	static inline auto FOnSaveGame = PreyFunction<void(IGameFrameworkListener* const _this, ISaveGame* pSaveGame)>(0x17F7CF0);
	static inline auto FOnLoadGame = PreyFunction<void(IGameFrameworkListener* const _this, ILoadGame* pLoadGame)>(0x17F7700);
	static inline auto FOnLevelEnd = PreyFunction<void(IGameFrameworkListener* const _this, const char* nextLevel)>(0x17F7560);
	static inline auto FOnActionEvent = PreyFunction<void(IGameFrameworkListener* const _this, const SActionEvent& event)>(0x17F7060);
	static inline auto FOnSavegameFileLoadedInMemory = PreyFunction<void(IGameFrameworkListener* const _this, const char* pLevelName)>(0x1333E90);
	static inline auto FOnForceLoadingWithFlash = PreyFunction<void(IGameFrameworkListener* const _this)>(0x1333E90);
	static inline auto FPreSerialize = PreyFunction<void(CGame* const _this)>(0x17F8ED0);
	static inline auto FFullSerializeBeforeEntities = PreyFunction<void(CGame* const _this, TSerialize serializer)>(0x17F3D40);
	static inline auto FFullSerialize = PreyFunction<void(CGame* const _this, TSerialize serializer)>(0x17F3A00);
	static inline auto FSerializeForLevelState = PreyFunction<void(CGame* const _this, TSerialize serializer)>(0x17F9430);
	static inline auto FPostSerialize = PreyFunction<void(CGame* const _this)>(0x17F8CB0);
	static inline auto FPostSerializeForLevelState = PreyFunction<void(CGame* const _this)>(0x17F8EC0);
	static inline auto FCanSave = PreyFunction<bool(const CGame* const _this)>(0x17F2E50);
	static inline auto FPostSerializeBeforeEntities = PreyFunction<void(CGame* const _this)>(0x17F8EB0);
	static inline auto FSerializeLTL = PreyFunction<void(CGame* const _this, bool _bReading)>(0x17F95C0);
	static inline auto FLevelIsTalosExterior = PreyFunction<const bool(const CGame* const _this)>(0x17F6260);
	static inline auto FOnInputEvent = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& inputEvent)>(0x17F7370);
	static inline auto FOnInputEventUI = PreyFunction<bool(IInputEventListener* const _this, const SInputEvent& inputEvent)>(0x17F7540);
	static inline auto FRemoveExclusiveController = PreyFunction<void(CGame* const _this)>(0x17F9280);
	static inline auto FOnPlatformEvent = PreyFunction<void(IPlatformOS::IPlatformListener* const _this, const IPlatformOS::SPlatformEvent& event)>(0x17F77C0);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x17F8280);
	static inline auto FGetGameInterface = PreyFunction<void* (CGame* const _this)>(0x1CBB0B0);
	static inline auto FInitRichPresence = PreyFunction<void(CGame* const _this)>(0x17F59A0);
	static inline auto FAddRichPresence = PreyFunction<void(CGame* const _this, const char* path)>(0x17F2C30);
	static inline auto FGetExclusiveControllerDeviceIndex = PreyFunction<unsigned(const CGame* const _this)>(0x17F3E60);
	static inline auto FGetPlatformUserIdPairedToDevice = PreyFunction<unsigned(const CGame* const _this, uint64_t deviceId)>(0x1CBB0B0);
	static inline auto FGetCurrentUserPlatformUserId = PreyFunction<unsigned(const CGame* const _this)>(0x1CBB0B0);
	static inline auto FGetPlayerProfilePlatformUserId = PreyFunction<unsigned(const CGame* const _this, const char* profileName)>(0x1CBB0B0);
	static inline auto FIsPlayerProfileSignedInToOS = PreyFunction<bool(const CGame* const _this, const char* profileName)>(0x17F6210);
	static inline auto FIsPlatformUserSignedInToOS = PreyFunction<bool(const CGame* const _this, unsigned userId)>(0x17F61E0);
	static inline auto FRefreshControlScheme = PreyFunction<void(const CGame* const _this)>(0x17F8F80);
	static inline auto FSetActiveUser = PreyFunction<void(CGame* const _this, unsigned platformUserId)>(0x17F96F0);
	static inline auto FClearActiveUser = PreyFunction<void(CGame* const _this)>(0x17F2F20);
	static inline auto FLoginUser = PreyFunction<void(CGame* const _this, unsigned platformUserId)>(0x17F6BE0);
	static inline auto FInitGameType = PreyFunction<void(CGame* const _this, bool multiplayer, bool fromInit)>(0x17F5060);
	static inline auto FInitPatchableModules = PreyFunction<void(CGame* const _this, bool inIsMultiplayer)>(0x17F5650);
	static inline auto FSetDifficultyLevel = PreyFunction<void(CGame* const _this, EDifficulty difficulty)>(0x17F97F0);
	static inline auto FGetAntiCheatManager = PreyFunction<IAntiCheatManager* (CGame* const _this)>(0x11C8520);
	static inline auto FGetGameRules = PreyFunction<CGameRules* (const CGame* const _this)>(0x17F3EA0);
	static inline auto FGetLastSaveGameOv1 = PreyFunction<const string& (CGame* const _this, string& levelName, string& locationName)>(0x17F40F0);
	static inline auto FGetColorGradientManager = PreyFunction<Graphics::CColorGradientManager& (CGame* const _this)>(0xE11AA0);
	static inline auto FHasIntersectionTester = PreyFunction<bool(const CGame* const _this)>(0x17F4550);
	static inline auto FGetTimeSinceHostMigrationStateChanged = PreyFunction<float(const CGame* const _this)>(0x17F4520);
	static inline auto FGetRemainingHostMigrationTimeoutTime = PreyFunction<float(const CGame* const _this)>(0x17F44E0);
	static inline auto FSetHostMigrationState = PreyFunction<void(CGame* const _this, CGame::EHostMigrationState newState)>(0x17F98A0);
	static inline auto FSetHostMigrationStateAndTime = PreyFunction<void(CGame* const _this, CGame::EHostMigrationState newState, float timeOfChange)>(0x17F98E0);
	static inline auto FAbortHostMigration = PreyFunction<void(CGame* const _this)>(0x17F2860);
	static inline auto FLoadActionMaps = PreyFunction<void(CGame* const _this, const char* filename)>(0x17F62C0);
	static inline auto FQueueDeferredKill = PreyFunction<void(CGame* const _this, const unsigned entityID)>(0x17F8F30);
	static inline auto FGetIArkDoomClockManager = PreyFunction<IArkDoomClockManager& (const CGame* const _this)>(0x29F930);
	static inline auto FGetIArkDoorSafe = PreyFunction<IArkDoor* (const CGame* const _this, unsigned _entityId)>(0x17F3EC0);
	static inline auto FGetIArkEncounterManager = PreyFunction<IArkEncounterManager& (const CGame* const _this)>(0x17F3F80);
	static inline auto FGetIArkFactionManager = PreyFunction<IArkFactionManager& (const CGame* const _this)>(0x17F3F90);
	static inline auto FGetIArkGlintConfigManager = PreyFunction<IArkGlintConfigManager& (const CGame* const _this)>(0x17F3FA0);
	static inline auto FGetIArkGravShaftSafe = PreyFunction<IArkGravShaft* (const CGame* const _this, unsigned _entityId)>(0x17F3FC0);
	static inline auto FGetIArkMetaTagManager = PreyFunction<IArkMetaTagManager& (const CGame* const _this)>(0x17F4080);
	static inline auto FGetIArkPADialogManager = PreyFunction<IArkPADialogManager& (const CGame* const _this)>(0x17F4090);
	static inline auto FGetIArkPatrolManager = PreyFunction<IArkPatrolManager& (const CGame* const _this)>(0x17F40A0);
	static inline auto FGetIArkPlayerPtr = PreyFunction<IArkPlayer* (const CGame* const _this)>(0x17F40B0);
	static inline auto FGetIArkPostEffectManager = PreyFunction<IArkPostEffectManager& (const CGame* const _this)>(0x17F40D0);
	static inline auto FGetIArkResponseManager = PreyFunction<IArkResponseManager& (const CGame* const _this)>(0x17F40E0);
	static inline auto FGetIArkGlooIslandNavLinkManager = PreyFunction<IArkGlooIslandNavLinkManager& (const CGame* const _this)>(0x17F3FB0);
	static inline auto FSafeGetIArkNpc = PreyFunction<IArkNpc* (const CGame* const _this, unsigned _entityId)>(0x17F9420);
	static inline auto FGetArkItemSystem = PreyFunction<ArkItemSystem& (const CGame* const _this)>(0x17F3DA0);
	static inline auto FAddArkGameNoiseOv1 = PreyFunction<void(CGame* const _this, const unsigned _emitter, const Vec3& _position, const uint64_t _type, const uint64_t _loudness)>(0x17F2B20);
	static inline auto FAddArkGameNoiseOv0 = PreyFunction<void(CGame* const _this, const unsigned _emitterId, const Vec3& _position, const ArkGameNoiseInfo& _noiseInfo, const uint64_t _loudness)>(0x17F28D0);
	static inline auto FTryAddArkSeismicEffectAtLocation = PreyFunction<void(const CGame* const _this, unsigned _emitterEntityId, const Vec3& _position, float _magnitude)>(0x17F9C00);
	static inline auto FAddArkSeismicEvent = PreyFunction<void(const CGame* const _this, unsigned _emitterEntityId, const Vec3& _position, float _magnitude)>(0x17F2B80);
	static inline auto FOnNewGame = PreyFunction<void(CGame* const _this, const int _campaignSlot)>(0x17F7780);
	static inline auto FResetGameState = PreyFunction<void(CGame* const _this)>(0x17F9410);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(CGame* const _this)>(0x17F7570);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(CGame* const _this)>(0x17F7630);
	static inline auto FLoadArkLevelProperties = PreyFunction<void(CGame* const _this, const XmlNodeRef& _node)>(0x17F6330);
	static inline auto FSetArkAutoMapScale = PreyFunction<void(CGame* const _this, const float _scale)>(0x17F9720);
	static inline auto FGetArkLevelProperties = PreyFunction<XmlNodeRef*(CGame* const _this, XmlNodeRef* _return_value_)>(0x17F3DB0);
	static inline auto FGetCurrentArkLocationLabel = PreyFunction<const char* (const CGame* const _this)>(0x17F3E10);
	static inline auto FSetArkLoadLocationLabel = PreyFunction<void(CGame* const _this, const char* const _pLocation)>(0x17F9750);
	static inline auto FGetArkLoadLocationLabel = PreyFunction<const char* (const CGame* const _this)>(0x17F3DD0);
	static inline auto FGetArkLoadingScreenTip = PreyFunction<const char* (const CGame* const _this, bool _bUseLevelTip)>(0x17F3DE0);
	static inline auto FGetArkGameMode = PreyFunction<const char* (const CGame* const _this)>(0x17F3D90);
	static inline auto FOnSaveDeletedBySystem = PreyFunction<void(CGame* const _this)>(0x17F7CE0);
	static inline auto FRequestDisconnect = PreyFunction<void(CGame* const _this, EArkLoadDisconnectReason _reason)>(0x17F93C0);
	static inline auto FRequestPause = PreyFunction<void(CGame* const _this, const bool _bPause)>(0x17F93D0);
	static inline auto FGetDisconnectReason = PreyFunction<EArkLoadDisconnectReason(const CGame* const _this)>(0x17F3E50);
	static inline auto FCheckSaveStatusOnReturnToMainMenu = PreyFunction<void(const CGame* const _this)>(0x17F2F10);
	static inline auto FDebugDraw = PreyFunction<void(const CGame* const _this)>(0x1333E90);
	static inline auto FUnlockPlayerCamera = PreyFunction<void(const CGame* const _this, float _interpolateToUnlockTime)>(0x17F9D40);
	static inline auto FLockPlayerCameraToAnimation = PreyFunction<void(const CGame* const _this, float _interpolateToLockTime)>(0x17F6620);
	static inline auto FLockPlayerCameraToEntityBone = PreyFunction<void(const CGame* const _this, const unsigned _entityId, const int _attachmentIndex, float _interpolateToLockTime)>(0x17F6900);
	static inline auto FGetCaptureVolumeInfos = PreyFunction<std::vector<IGame::CaptureVolumeInfo>*(const CGame* const _this, std::vector<IGame::CaptureVolumeInfo>* _return_value_)>(0x17F3DF0);
	static inline auto FOpenPauseMenu = PreyFunction<void(CGame* const _this, bool open)>(0x17F8C30);
	static inline auto FDumpObjectiveStateToFile = PreyFunction<void(const CGame* const _this, const char* _fileName)>(0x17F32E0);
	static inline auto FOnNeuromodUsed = PreyFunction<void(CGame* const _this, const uint64_t& _abilityId, bool _bIsAlienPower)>(0x17F7770);
	static inline auto FInitScriptBinds = PreyFunction<void(CGame* const _this)>(0x17F5BF0);
	static inline auto FUpdateSaveIcon = PreyFunction<void(CGame* const _this)>(0x17FAE00);
	static inline auto FCheckReloadLevel = PreyFunction<void(CGame* const _this)>(0x17F2E60);
	static inline auto FRegisterConsoleVars = PreyFunction<void(CGame* const _this)>(0x181E060);
	static inline auto FRegisterConsoleCommands = PreyFunction<void(CGame* const _this)>(0x181D6F0);
	static inline auto FUnregisterConsoleCommands = PreyFunction<void(CGame* const _this)>(0x1820790);
	static inline auto FRegisterGameObjectEvents = PreyFunction<void(CGame* const _this)>(0x17F9010);
	static inline auto FCmdRestartGame = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DE90);
	static inline auto FCmdDumpAmmoPoolStats = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdName = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180D230);
	static inline auto FCmdTeam = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180E500);
	static inline auto FCmdSpectator = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdJoinGame = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdKill = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180D0D0);
	static inline auto FCmdTakeDamage = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180E3C0);
	static inline auto FCmdRestart = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DE50);
	static inline auto FCmdSay = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DEC0);
	static inline auto FCmdEcho = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180C6B0);
	static inline auto FCmdLoadActionmap = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180D1E0);
	static inline auto FCmdReloadGameRules = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DAD0);
	static inline auto FCmdNextLevel = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdReloadHitDeathReactions = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DBC0);
	static inline auto FCmdDumpHitDeathReactionsAssetUsage = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180C630);
	static inline auto FCmdReloadSpectacularKill = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdReloadPickAndThrowProxies = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdReloadMovementTransitions = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DDD0);
	static inline auto FCmdStartKickVoting = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdVote = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180E5A0);
	static inline auto FCmdListAllRandomLoadingMessages = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FIsFreeCamActive = PreyFunction<bool()>(0x181CA10);
	static inline auto FCmdFreeCamEnable = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180C780);
	static inline auto FCmdFreeCamDisable = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180C6F0);
	static inline auto FCmdFreeCamLockCamera = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180C810);
	static inline auto FCmdFreeCamUnlockCamera = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180C860);
	static inline auto FCmdFlyCamSetPoint = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdFlyCamPlay = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x1333E90);
	static inline auto FCmdIgnoreAllAsserts = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180D0C0);
	static inline auto FCmdReloadPlayer = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DDF0);
	static inline auto FCmdSetPlayerHealth = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DFA0);
	static inline auto FCmdSwitchGameMultiplayer = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180E390);
	static inline auto FCmdSpawnActor = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180E0F0);
	static inline auto FCmdReloadGameFx = PreyFunction<void(IConsoleCmdArgs* pArgs)>(0x180DA80);
	static inline auto FOnHostMigrationNetTimeoutChanged = PreyFunction<void(ICVar* pVar)>(0x17F7350);
	static inline auto FVerifyMaxPlayers = PreyFunction<void(ICVar* pVar)>(0x17FBE20);
	static inline auto FPartyMembersCallback = PreyFunction<void(UCryLobbyEventData eventData, void* arg)>(0x17F8C80);
	static inline auto FUserProfileChangedCallback = PreyFunction<void(UCryLobbyEventData eventData, void* arg)>(0x17FBDA0);
	static inline auto FInviteAcceptedCallback = PreyFunction<void(UCryLobbyEventData eventData, void* arg)>(0x1333E90);
	static inline auto FOnlineStateCallback = PreyFunction<void(UCryLobbyEventData eventData, void* arg)>(0x17F8BD0);
	static inline auto FEthernetStateCallback = PreyFunction<void(UCryLobbyEventData eventData, void* arg)>(0x17F3880);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(IArkActiveUserManagerListener* const _this, unsigned platformUserId)>(0x17F7320);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(IArkActiveUserManagerListener* const _this, bool _bControllerDisconnect)>(0x1333E90);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(IArkActiveUserManagerListener* const _this)>(0x17F7330);
};
#endif // MOONCRASH
