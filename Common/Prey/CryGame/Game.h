#pragma once
#include <Chairloader/PreyFunction.h>

//#include "CScriptBind_Ark.h"
#include "Prey/GameDll/GameActions.h"
#include "IGame.h"
#include "Prey/CryCore/Platform/IPlatformOS.h"
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>

class CScriptBind_Ark;
struct IGameFramework;
class CGameCache;
class CGamePhysicsSettings;
class CScriptBind_Actor;
class CScriptBind_Item;
class CScriptBind_GameRules;
class CScriptBind_Game;
class CScriptBind_GameAI;
class CScriptBind_HitDeathReactions;
class CScriptBind_ProtectedBinds;
class CPlayerVisTable;
class CDataPatchDownloader;
class CGameLocalizationManager;
struct ITelemetryCollector;
struct IPlayerProfileManager;
struct SCVars;
struct SItemStrings;
class CGameSharedParametersStorage;
class CScreenEffects;
class CDownloadMgr;
class CDLCManager;
class CLightningGameEffect;
class CParameterGameEffect;
class CWorldBuilder;

namespace Graphics
{
class CColorGradientManager;
}

class CGameAISystem;
template <size_t S>
class RayCastQueue;
template <size_t S>
class IntersectionTestQueue;
class CUIManager;
class CHitDeathReactionsSystem;
class CBodyDamageManager;
class CMovementTransitionsSystem;
class CGameMechanismManager;
class CModInfoManager;
class CGameMechanismManager;
class ArkAiManager;
class ArkAttentionManager;
class ArkAttractionManager;
class ArkAuralPerceptionManager;
class ArkCharacterManager;
class ArkCombatManager;
class ArkCystoidManager;
class ArkDistractionEntitySink;
class ArkDistractionManager;
class ArkDynamicCorpseManager;
class ArkEncounterManager;
class CArkFlowGraphManager;
class ArkEthericFogManager;
class ArkFactionManager;
class ArkGameDataManager;
class ArkGlintConfigManager;
class CArkGlooIslandNavLinkManager;
class ArkInstigationManager;
class ArkLightTimeManager;
class ArkListenerManager;
class ArkLurkManager;
class ArkAiManager;
class ArkMetaTagManager;
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
class CArkPADialogManager;
class ArkPatrolManager;
class ArkPostEffectManager;
class CArkProjectileGooNetworkManager;
class CArkProjectileGooPhysicsManager;
class CArkProjectilePoolManager;
class ArkResponseManager;
class ArkRetreatManager;
class ArkRoomPerceptionManager;
class ArkSpatialManager;
class ArkTimeScaleManager;
class ArkVisualPerceptionManager;
class ArkWorldUIManager;
class CScriptBind_ArkBreakable;
class CScriptBind_ArkItem;
class CScriptBind_ArkFaction;
class CScriptBind_ArkKiosk;
class CScriptBind_ArkNpc;
class CScriptBind_ArkRoster;
class CScriptBind_ArkTurret;
class CScriptBind_Inventory;
class CScriptBind_ItemSystem;
class CScriptBind_LightningArc;
class ArkGame;
class ArkActiveUserManagerBase;

// class CGame
// {
// public:
// 	static inline auto FInit = PreyFunction<bool(CGame* _this, IGameFramework* pFramework)>(0x16D0A90);
// 	static inline auto FUpdate = PreyFunction<int(CGame* _this, bool haveFocus, unsigned int updateFlags)>(0x16D6230);
// 	static inline auto FShutdown = PreyFunction<void(CGame* _this)>(0x16D6150);
// };

class CGame : public IGame, IGameFrameworkListener, IPlatformOS::IPlatformListener, IInputEventListener, ISystemEventListener, IArkActiveUserManagerListener
{
public:
	static inline auto FInit = PreyFunction<bool(CGame* _this, IGameFramework* pFramework)>(0x16D0A90);
	static inline auto FUpdate = PreyFunction<int(CGame* _this, bool haveFocus, unsigned int updateFlags)>(0x16D6230);
	static inline auto FShutdown = PreyFunction<void(CGame* _this)>(0x16D6150);

	enum ESaveIconMode : __int32
	{
		eSIM_Off = 0x0,
		eSIM_SaveStart = 0x1,
		eSIM_Saving = 0x2,
		eSIM_Finished = 0x3,
	};
	enum EInviteAcceptedState : __int32
	{
		eIAS_None = 0x0,
		eIAS_Init = 0x1,
		eIAS_StartAcceptInvite = 0x2,
		eIAS_InitProfile = 0x3,
		eIAS_WaitForInitProfile = 0x4,
		eIAS_WaitForLoadToFinish = 0x5,
		eIAS_DisconnectGame = 0x6,
		eIAS_DisconnectLobby = 0x7,
		eIAS_WaitForSessionDelete = 0x8,
		eIAS_ConfirmInvite = 0x9,
		eIAS_WaitForInviteConfirmation = 0xA,
		eIAS_InitSinglePlayer = 0xB,
		eIAS_WaitForInitSinglePlayer = 0xC,
		eIAS_WaitForSplashScreen = 0xD,
		eIAS_WaitForValidUser = 0xE,
		eIAS_InitMultiplayer = 0xF,
		eIAS_WaitForInitMultiplayer = 0x10,
		eIAS_InitOnline = 0x11,
		eIAS_WaitForInitOnline = 0x12,
		eIAS_WaitForSquadManagerEnabled = 0x13,
		eIAS_Accept = 0x14,
		eIAS_Error = 0x15,
	};
	class IRenderSceneListener
	{
		void* vtable;
	};
	enum EHostMigrationState : __int32
	{
		eHMS_NotMigrating = 0x0,
		eHMS_WaitingForPlayers = 0x1,
		eHMS_Resuming = 0x2,
	};
	enum ERichPresenceState : __int32
	{
		eRPS_none = 0x0,
		eRPS_idle = 0x1,
		eRPS_frontend = 0x2,
		eRPS_lobby = 0x3,
		eRPS_inGame = 0x4,
	};
	class SPlatformInfo
	{
		EPlatform platformId;
		unsigned __int8 devices;
	};
	class SInviteAcceptedData
	{
		ECryLobbyService m_service;
		unsigned int m_user;
		_smart_ptr<SCrySessionID> m_id;
		ECryLobbyError m_error;
		ECryLobbyInviteType m_type;
		bool m_bannedFromSession;
		bool m_failedToAcceptInviteAsNotSignedIn;
	};
	virtual bool IsReloading() = 0;
	virtual EPlatform GetPlatform() = 0;
	virtual void UploadSessionTelemetry() = 0;
	virtual void ClearSessionTelemetry() = 0;
	virtual void CheckReloadLevel() = 0;
	virtual void RegisterConsoleVars() = 0;
	virtual void RegisterConsoleCommands() = 0;
	virtual void UnregisterConsoleCommands() = 0;
	virtual void RegisterGameObjectEvents() = 0;

	CUIManager* GetUI() { return m_pUIManager; }

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
	unsigned __int64 m_exclusiveControllerDeviceId;
	int m_currentXboxLivePartySize;
	unsigned int m_clientActorId;
	SCVars* m_pCVars;
	SItemStrings* m_pItemStrings;
	CGameSharedParametersStorage* m_pGameParametersStorage;
	CryStringT<char> m_lastSaveGame;
	CScreenEffects* m_pScreenEffects;
	CDownloadMgr* m_pDownloadMgr;
	CDLCManager* m_pDLCManager;
	CLightningGameEffect* m_pLightningGameEffect;
	CParameterGameEffect* m_pParameterGameEffect;
	CWorldBuilder* m_pWorldBuilder;
	IInputEventListener* m_pInputEventListenerOverride;
	std::map<CryStringT<char>, CryStringT<char>> m_variantOptions;
	std::map<CryFixedStringT<128>, int, std::less<CryFixedStringT<128> >, std::allocator<std::pair<CryFixedStringT<128> const, int> > > m_richPresence;
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
	std::unique_ptr<ArkDynamicCorpseManager> m_pArkDynamicCorpseManager;
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
	CryStringT<char> m_arkLoadLocation;
	XmlNodeRef m_gameLevelToLevelSave;
	std::unique_ptr<ArkGame> m_pArkGame;
	std::unique_ptr<ArkActiveUserManagerBase> m_pActiveUserManager;
};
static_assert(sizeof(CGame) == 0x450);

inline CGame* g_pGame = nullptr;
