// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/ArkSaveMetaData.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/iface/ISaveGameEnumerator.h>

class ArkApexVolumeManager;
class ArkCameraShakeManager;
class ArkDialogSubtitleManager;
class ArkDifficultyComponent;
class ArkEventScheduler;
class ArkGameModeManager;
class ArkGameStateConditionManager;
class ArkHackingUI;
class ArkIndicatorIconManager;
class ArkItemSystem;
class ArkLevelMapComponent;
class ArkLightManager;
class ArkLocationManager;
class ArkNewGamePlus;
struct ArkNoiseAttentionParams;
class ArkObjectiveComponent;
namespace ArkSignalSystem
{
class Manager;
} // namespace ArkSignalSystem
class ArkTipComponent;
class ArkTutorialSystem;
class CCryName;
class CScriptBind_ArkPlayer;
class IArkGameLoadSaveListener;
struct IEntityArchetype;
struct IPlayerProfile;
struct ISaveGame;
struct ISaveGameEnumerator;

// Header: Exact
// Prey/GameDll/ark/ArkGame.h
class ArkGame : private IArkActiveUserManagerListener, public ISystemEventListener // Id=801665F Size=472
{
public:
	enum class EArkSafeBoundsResult
	{
		Safe = 0,
		Warning = 1,
		Unsafe = 2,
	};

	struct ScreenBlackFadeInfo // Id=80169EC Size=8
	{
		float m_blackDuration;
		float m_fadeOutDuration;
		
#if 0
		void LoadConfig(XmlNodeRef arg0);
#endif
	};

	ArkGame::ScreenBlackFadeInfo m_levelLoadFade;
	ArkGame::ScreenBlackFadeInfo m_quickLoadFade;
	std::vector<string> m_captureVolumeWhiteList;
	std::array<_smart_ptr<ISaveGameEnumerator>,3> m_saveGameEnumerators;
	std::array<std::vector<string>,3> m_saveGameToUpdate;
	std::array<unsigned __int64,3> m_campaignGuids;
	ArkSimpleTimer m_autoSaveDelay;
	ArkSimpleTimer m_blockAutoSaveWindow;
	ArkSimpleTimer m_screenBlackTimer;
	ArkSimpleTimer m_screenFadeOutTimer;
	string m_saveFileToLoad;
	string m_loadLocationOverride;
	IArkGameLoadSaveListener *m_pLoadListener;
	uint64_t m_campaignPlayTime;
	float m_campaignTimerAccumulator;
	uint64_t m_currentLocationId;
	XmlNodeRef m_levelProperties;
	std::unique_ptr<CScriptBind_ArkPlayer> m_pScriptBindArkPlayer;
	std::unique_ptr<ArkCameraShakeManager> m_pArkCameraShakeManager;
	std::unique_ptr<ArkDialogSubtitleManager> m_pArkDialogSubtitleManager;
	std::unique_ptr<ArkDifficultyComponent> m_pArkDifficultyComponent;
	std::unique_ptr<ArkEventScheduler> m_pArkEventScheduler;
	std::unique_ptr<ArkGameStateConditionManager> m_pArkGameStateConditionManager;
	std::unique_ptr<ArkHackingUI> m_pArkHackingUI;
	std::unique_ptr<ArkIndicatorIconManager> m_pArkIndicatorIconManager;
	std::unique_ptr<ArkItemSystem> m_pArkItemSystem;
	std::unique_ptr<ArkLevelMapComponent> m_pArkLevelMapComponent;
	std::unique_ptr<ArkLightManager> m_pArkLightManager;
	std::unique_ptr<ArkLocationManager> m_pArkLocationManager;
	std::unique_ptr<ArkNoiseAttentionParams> m_pArkNoiseAttentionParams;
	std::unique_ptr<ArkObjectiveComponent> m_pArkObjectiveComponent;
	std::unique_ptr<ArkSignalSystem::Manager> m_pArkSignalManager;
	std::unique_ptr<ArkTipComponent> m_pArkTipComponent;
	std::unique_ptr<ArkTutorialSystem> m_pArkTutorialSystem;
	std::unique_ptr<ArkApexVolumeManager> m_pApexVolumeManager;
	std::unique_ptr<ArkGameModeManager> m_pArkGameModeManager;
	std::unique_ptr<ArkNewGamePlus> m_pNewGamePlus;
	AABB m_playerSafeBounds;
	EArkLoadDisconnectReason m_loadDisconnectReason;
	
	enum class PauseRequestStatus
	{
		none = 0,
		pause = 1,
		pausedByRequest = 2,
		unpause = 3,
	};

	ArkGame::PauseRequestStatus m_pauseRequestStatus;
	float m_playerWarningBuffer;
	float m_timeSinceLastAutoSave;
	bool m_bLevelToLevelTransition;
	bool m_bSaveHasJustBeenDeletedBySystem;
	bool m_bPreTextureStreamerRunning;
	bool m_bNeedsToAutosaveOnMapLoad;
	bool m_bPerformingIronmanSave;
	static int g_skipContinuePrompt;
	
	virtual ~ArkGame();
	static std::unique_ptr<ArkGame> Create() { return FCreate(); }
	static IPlayerProfile *GetCurrentProfile() { return FGetCurrentProfile(); }
	static EArkSaveFileType GetSaveFileType(ISaveGameEnumerator::SGameDescription const &_desc) { return FGetSaveFileType(_desc); }
	boost::optional<ISaveGameEnumerator::SGameDescription> GetMostRecentSave(int _campaignSlot) { return FGetMostRecentSaveOv1(this,_campaignSlot); }
	boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> > GetMostRecentSave() { return FGetMostRecentSaveOv0(this); }
	static ArkSaveMetaData GetSaveMetadata(ISaveGameEnumerator::SGameDescription const &_desc) { return FGetSaveMetadata(_desc); }
	static bool CanAutoSave() { return FCanAutoSave(); }
	static bool CanManualSave() { return FCanManualSave(); }
	static bool CanIronmanSave() { return FCanIronmanSave(); }
	void AutoSave(bool _bForceImmediate) { FAutoSave(this,_bForceImmediate); }
	void QuickSave() { FQuickSave(this); }
	void IronmanSave() { FIronmanSave(this); }
	bool ManualSave() { return FManualSave(this); }
	bool IsMaxManualSaveCountReached() { return FIsMaxManualSaveCountReachedOv1(this); }
	void ClearIronmanSave() { FClearIronmanSave(this); }
	void Init() { FInit(this); }
	void CompleteInit() { FCompleteInit(this); }
	void Reset() { FReset(this); }
	void ResetGameState() { FResetGameState(this); }
	void Shutdown() { FShutdown(this); }
	void ProcessInput(CCryName const &_actionId, int _activationMode, float _value) { FProcessInput(this,_actionId,_activationMode,_value); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	uint64_t GetCampaignPlayTime() const { return FGetCampaignPlayTime(this); }
	uint64_t GetCurrentCampaignGuid() const { return FGetCurrentCampaignGuid(this); }
	ELoadGameResult LoadLastSave(IArkGameLoadSaveListener *_pListener) { return FLoadLastSave(this,_pListener); }
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	ArkGame::EArkSafeBoundsResult GetPlayerSafeBoundsResult(Vec3 const &_pos, float &_warningMagnitude) const { return FGetPlayerSafeBoundsResult(this,_pos,_warningMagnitude); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelEnd() const { FOnLevelEnd(this); }
	void OnLevelUnload() const { FOnLevelUnload(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void SerializeBeforeEntities(TSerialize _serializer) const { FSerializeBeforeEntities(this,_serializer); }
	void Serialize(TSerialize _serializer) const { FSerialize(this,_serializer); }
	void SerializeForLevelState(TSerialize _serializer) const { FSerializeForLevelState(this,_serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void PostSerializeBeforeEntities() { FPostSerializeBeforeEntities(this); }
	void SerializeLTL(TSerialize _serializer) { FSerializeLTL(this,_serializer); }
	void DumpObjectiveStateToFile(const char *_fileName) const { FDumpObjectiveStateToFile(this,_fileName); }
	void AddSaveMetadata(ISaveGame &_save) const { FAddSaveMetadata(this,_save); }
	float GetTimeSinceLastAutoSave() const { return FGetTimeSinceLastAutoSave(this); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void OnNewGame(const int _campaignSlot) { FOnNewGame(this,_campaignSlot); }
	void OnSaveGame() { FOnSaveGame(this); }
	void OnSetCampaignSlot() { FOnSetCampaignSlot(this); }
	uint64_t GetCurrentLocationId() const { return FGetCurrentLocationId(this); }
	bool InLevelToLevelTransition() const { return FInLevelToLevelTransition(this); }
	const char *GetLoadingScreenTip(bool _bUseLevelTip) const { return FGetLoadingScreenTip(this,_bUseLevelTip); }
	void SetRichPresence(string const &_rpKey) const { FSetRichPresence(this,_rpKey); }
	const char *GetGameMode() const { return FGetGameMode(this); }
	void SetArkLevelProperties(XmlNodeRef _xmlNode) { FSetArkLevelProperties(this,_xmlNode); }
	XmlNodeRef GetArkLevelProperties() const { return FGetArkLevelProperties(this); }
	XmlNodeRef GetArkLevelPropertiesGroup() const { return FGetArkLevelPropertiesGroup(this); }
	CScriptBind_ArkPlayer &GetArkPlayerScriptBind() const { return FGetArkPlayerScriptBind(this); }
	ArkNoiseAttentionParams const &GetArkNoiseAttentionParams() const { return FGetArkNoiseAttentionParams(this); }
	ArkDialogSubtitleManager &GetArkDialogSubtitleManager() const { return FGetArkDialogSubtitleManager(this); }
	ArkDifficultyComponent &GetArkDifficultyComponent() const { return FGetArkDifficultyComponent(this); }
	ArkEventScheduler &GetArkEventScheduler() const { return FGetArkEventScheduler(this); }
	ArkGameStateConditionManager &GetArkGameStateConditionManager() const { return FGetArkGameStateConditionManager(this); }
	ArkHackingUI &GetArkHackingUI() const { return FGetArkHackingUI(this); }
	ArkIndicatorIconManager &GetArkIndicatorIconManager() const { return FGetArkIndicatorIconManager(this); }
	ArkItemSystem &GetArkItemSystem() const { return FGetArkItemSystem(this); }
	ArkLevelMapComponent &GetArkLevelMapComponent() const { return FGetArkLevelMapComponent(this); }
	ArkLocationManager &GetArkLocationManager() const { return FGetArkLocationManager(this); }
	ArkObjectiveComponent &GetArkObjectiveComponent() const { return FGetArkObjectiveComponent(this); }
	ArkSignalSystem::Manager &GetArkSignalManager() const { return FGetArkSignalManager(this); }
	ArkTipComponent &GetArkTipComponent() const { return FGetArkTipComponent(this); }
	ArkTutorialSystem &GetArkTutorialSystem() const { return FGetArkTutorialSystem(this); }
	ArkCameraShakeManager &GetArkCameraShakeManager() const { return FGetArkCameraShakeManager(this); }
	ArkLightManager &GetArkLightManager() const { return FGetArkLightManager(this); }
	ArkNewGamePlus &GetArkNewGamePlus() const { return FGetArkNewGamePlus(this); }
	_smart_ptr<ISaveGameEnumerator> GetSaveGameEnumerator(const int _campaignSlot) { return FGetSaveGameEnumerator(this,_campaignSlot); }
	_smart_ptr<ISaveGameEnumerator> GetCurrentCampaignSaveGameEnumerator() { return FGetCurrentCampaignSaveGameEnumerator(this); }
	void DeleteSave(const int _campaignSlot, const char *const _name) { FDeleteSave(this,_campaignSlot,_name); }
	void SaveProfile() const { FSaveProfile(this); }
	void UpdateCampaignGuids() { FUpdateCampaignGuids(this); }
	ArkGame();
	void LoadConfig() { FLoadConfig(this); }
	bool PerformAutoSave(bool _bImmediate) { return FPerformAutoSave(this,_bImmediate); }
	bool CreateRollingSave(EArkSaveFileType _type, const uint8_t _maxCount, bool _bImmediate) { return FCreateRollingSave(this,_type,_maxCount,_bImmediate); }
	bool SaveGame(const char *const _name, const bool _bImmediate) { return FSaveGame(this,_name,_bImmediate); }
	void ReleaseSaveGameEnumerators() { FReleaseSaveGameEnumerators(this); }
	void HandleDisconnectRequest() { FHandleDisconnectRequest(this); }
	virtual void OnActiveUserIdChanged(unsigned );
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual void OnActiveUserSignedOut();
	
#if 0
	static void RegisterCVars();
	bool NewGamePlusFileExists() const;
	bool OverwriteSave(const char *const arg0);
	bool IsMaxManualSaveCountReached(const int arg0);
	uint64_t GetCampaignPlayTimeWithAccumulator() const;
	ELoadGameResult LoadSave(string const &arg0, string const &arg1, IArkGameLoadSaveListener *arg2);
	ArkApexVolumeManager &GetApexVolumeManager() const;
	ArkGameModeManager &GetArkGameModeManager() const;
	void UpdateBlockAutoSaveWindow(float arg0);
	void OnSaveDeletedBySystem();
	void RequestDisconnect(EArkLoadDisconnectReason arg0);
	EArkLoadDisconnectReason GetDisconnectReason() const;
	bool ShouldArchetypeBeConsideredByCaptureVolume(IEntityArchetype const *const arg0) const;
	static bool CanSkipContinuePrompt();
	void StartQuickLoadFade();
	void RequestPause(const bool arg0);
	bool IsPauseRequestedBySystem() const;
	void OnCloseContinuePrompt();
	void StartFade(ArkGame::ScreenBlackFadeInfo arg0);
	bool CreateManualSave(const char *const arg0, const bool arg1);
#endif
	
	static inline auto FBitNotArkGame = PreyFunction<void(ArkGame *const _this)>(0x116C3D0);
	static inline auto FCreate = PreyFunction<std::unique_ptr<ArkGame>()>(0x116D0A0);
	static inline auto FGetCurrentProfile = PreyFunction<IPlayerProfile *()>(0x116D970);
	static inline auto FGetSaveFileType = PreyFunction<EArkSaveFileType(ISaveGameEnumerator::SGameDescription const &_desc)>(0x116E1E0);
	static inline auto FGetMostRecentSaveOv1 = PreyFunction<boost::optional<ISaveGameEnumerator::SGameDescription>(ArkGame *const _this, int _campaignSlot)>(0x116DE10);
	static inline auto FGetMostRecentSaveOv0 = PreyFunction<boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> >(ArkGame *const _this)>(0x116DC20);
	static inline auto FGetSaveMetadata = PreyFunction<ArkSaveMetaData(ISaveGameEnumerator::SGameDescription const &_desc)>(0x116E390);
	static inline auto FCanAutoSave = PreyFunction<bool()>(0x116CA90);
	static inline auto FCanManualSave = PreyFunction<bool()>(0x116CB40);
	static inline auto FCanIronmanSave = PreyFunction<bool()>(0x116CB10);
	static inline auto FAutoSave = PreyFunction<void(ArkGame *const _this, bool _bForceImmediate)>(0x116C9F0);
	static inline auto FQuickSave = PreyFunction<void(ArkGame *const _this)>(0x116FBE0);
	static inline auto FIronmanSave = PreyFunction<void(ArkGame *const _this)>(0x116E810);
	static inline auto FManualSave = PreyFunction<bool(ArkGame *const _this)>(0x116EE20);
	static inline auto FIsMaxManualSaveCountReachedOv1 = PreyFunction<bool(ArkGame *const _this)>(0x116E850);
	static inline auto FClearIronmanSave = PreyFunction<void(ArkGame *const _this)>(0x116CDA0);
	static inline auto FInit = PreyFunction<void(ArkGame *const _this)>(0x116E520);
	static inline auto FCompleteInit = PreyFunction<void(ArkGame *const _this)>(0x116CE30);
	static inline auto FReset = PreyFunction<void(ArkGame *const _this)>(0x116FC80);
	static inline auto FResetGameState = PreyFunction<void(ArkGame *const _this)>(0x116FD80);
	static inline auto FShutdown = PreyFunction<void(ArkGame *const _this)>(0x1170740);
	static inline auto FProcessInput = PreyFunction<void(ArkGame *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0x116FB70);
	static inline auto FUpdate = PreyFunction<void(ArkGame *const _this, float _frameTime)>(0x11707C0);
	static inline auto FGetCampaignPlayTime = PreyFunction<uint64_t(ArkGame const *const _this)>(0x155ADA0);
	static inline auto FGetCurrentCampaignGuid = PreyFunction<uint64_t(ArkGame const *const _this)>(0x116D8E0);
	static inline auto FLoadLastSave = PreyFunction<ELoadGameResult(ArkGame *const _this, IArkGameLoadSaveListener *_pListener)>(0x116EB30);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkGame *const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x116FA00);
	static inline auto FGetPlayerSafeBoundsResult = PreyFunction<ArkGame::EArkSafeBoundsResult(ArkGame const *const _this, Vec3 const &_pos, float &_warningMagnitude)>(0x116E080);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkGame *const _this)>(0x116F070);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkGame *const _this)>(0x116F0D0);
	static inline auto FOnLevelEnd = PreyFunction<void(ArkGame const *const _this)>(0x116F060);
	static inline auto FOnLevelUnload = PreyFunction<void(ArkGame const *const _this)>(0x116F200);
	static inline auto FOnGameEnded = PreyFunction<void(ArkGame *const _this)>(0x116EFF0);
	static inline auto FSerializeBeforeEntities = PreyFunction<void(ArkGame const *const _this, TSerialize _serializer)>(0x1170380);
	static inline auto FSerialize = PreyFunction<void(ArkGame const *const _this, TSerialize _serializer)>(0x11701B0);
	static inline auto FSerializeForLevelState = PreyFunction<void(ArkGame const *const _this, TSerialize _serializer)>(0x11703B0);
	static inline auto FPostSerialize = PreyFunction<void(ArkGame *const _this)>(0x116FAE0);
	static inline auto FPostSerializeBeforeEntities = PreyFunction<void(ArkGame *const _this)>(0x116FB60);
	static inline auto FSerializeLTL = PreyFunction<void(ArkGame *const _this, TSerialize _serializer)>(0x1170410);
	static inline auto FDumpObjectiveStateToFile = PreyFunction<void(ArkGame const *const _this, const char *_fileName)>(0x116D440);
	static inline auto FAddSaveMetadata = PreyFunction<void(ArkGame const *const _this, ISaveGame &_save)>(0x116C8E0);
	static inline auto FGetTimeSinceLastAutoSave = PreyFunction<float(ArkGame const *const _this)>(0x116E450);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkGame *const _this)>(0x116F190);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkGame *const _this)>(0x116F1A0);
	static inline auto FOnNewGame = PreyFunction<void(ArkGame *const _this, const int _campaignSlot)>(0x116F210);
	static inline auto FOnSaveGame = PreyFunction<void(ArkGame *const _this)>(0x116F4B0);
	static inline auto FOnSetCampaignSlot = PreyFunction<void(ArkGame *const _this)>(0x116F630);
	static inline auto FGetCurrentLocationId = PreyFunction<uint64_t(ArkGame const *const _this)>(0x36CFD0);
	static inline auto FInLevelToLevelTransition = PreyFunction<bool(ArkGame const *const _this)>(0x116E510);
	static inline auto FGetLoadingScreenTip = PreyFunction<const char *(ArkGame const *const _this, bool _bUseLevelTip)>(0x116DA20);
	static inline auto FSetRichPresence = PreyFunction<void(ArkGame const *const _this, string const &_rpKey)>(0xA13080);
	static inline auto FGetGameMode = PreyFunction<const char *(ArkGame const *const _this)>(0x116D9C0);
	static inline auto FSetArkLevelProperties = PreyFunction<void(ArkGame *const _this, XmlNodeRef _xmlNode)>(0x1170440);
	static inline auto FGetArkLevelProperties = PreyFunction<XmlNodeRef(ArkGame const *const _this)>(0x116D860);
	static inline auto FGetArkLevelPropertiesGroup = PreyFunction<XmlNodeRef(ArkGame const *const _this)>(0x116D890);
	static inline auto FGetArkPlayerScriptBind = PreyFunction<CScriptBind_ArkPlayer &(ArkGame const *const _this)>(0x9046A0);
	static inline auto FGetArkNoiseAttentionParams = PreyFunction<ArkNoiseAttentionParams const &(ArkGame const *const _this)>(0xA91EA0);
	static inline auto FGetArkDialogSubtitleManager = PreyFunction<ArkDialogSubtitleManager &(ArkGame const *const _this)>(0x155AD20);
	static inline auto FGetArkDifficultyComponent = PreyFunction<ArkDifficultyComponent &(ArkGame const *const _this)>(0xE98550);
	static inline auto FGetArkEventScheduler = PreyFunction<ArkEventScheduler &(ArkGame const *const _this)>(0x116D810);
	static inline auto FGetArkGameStateConditionManager = PreyFunction<ArkGameStateConditionManager &(ArkGame const *const _this)>(0x155AD60);
	static inline auto FGetArkHackingUI = PreyFunction<ArkHackingUI &(ArkGame const *const _this)>(0xD59700);
	static inline auto FGetArkIndicatorIconManager = PreyFunction<ArkIndicatorIconManager &(ArkGame const *const _this)>(0x116D830);
	static inline auto FGetArkItemSystem = PreyFunction<ArkItemSystem &(ArkGame const *const _this)>(0x116D840);
	static inline auto FGetArkLevelMapComponent = PreyFunction<ArkLevelMapComponent &(ArkGame const *const _this)>(0x116D850);
	static inline auto FGetArkLocationManager = PreyFunction<ArkLocationManager &(ArkGame const *const _this)>(0x1ED260);
	static inline auto FGetArkObjectiveComponent = PreyFunction<ArkObjectiveComponent &(ArkGame const *const _this)>(0x1645C70);
	static inline auto FGetArkSignalManager = PreyFunction<ArkSignalSystem::Manager &(ArkGame const *const _this)>(0x8BD1E0);
	static inline auto FGetArkTipComponent = PreyFunction<ArkTipComponent &(ArkGame const *const _this)>(0x116D8D0);
	static inline auto FGetArkTutorialSystem = PreyFunction<ArkTutorialSystem &(ArkGame const *const _this)>(0xDF4C20);
	static inline auto FGetArkCameraShakeManager = PreyFunction<ArkCameraShakeManager &(ArkGame const *const _this)>(0x1906510);
	static inline auto FGetArkLightManager = PreyFunction<ArkLightManager &(ArkGame const *const _this)>(0xE95990);
	static inline auto FGetArkNewGamePlus = PreyFunction<ArkNewGamePlus &(ArkGame const *const _this)>(0x12F0BB0);
	static inline auto FGetSaveGameEnumerator = PreyFunction<_smart_ptr<ISaveGameEnumerator>(ArkGame *const _this, const int _campaignSlot)>(0x116E240);
	static inline auto FGetCurrentCampaignSaveGameEnumerator = PreyFunction<_smart_ptr<ISaveGameEnumerator>(ArkGame *const _this)>(0x116D920);
	static inline auto FDeleteSave = PreyFunction<void(ArkGame *const _this, const int _campaignSlot, const char *const _name)>(0x116D390);
	static inline auto FSaveProfile = PreyFunction<void(ArkGame const *const _this)>(0x1170000);
	static inline auto FUpdateCampaignGuids = PreyFunction<void(ArkGame *const _this)>(0x16D6F00);
	static inline auto FLoadConfig = PreyFunction<void(ArkGame *const _this)>(0x116E950);
	static inline auto FPerformAutoSave = PreyFunction<bool(ArkGame *const _this, bool _bImmediate)>(0x116FA80);
	static inline auto FCreateRollingSave = PreyFunction<bool(ArkGame *const _this, EArkSaveFileType _type, const uint8_t _maxCount, bool _bImmediate)>(0x116D0E0);
	static inline auto FSaveGame = PreyFunction<bool(ArkGame *const _this, const char *const _name, const bool _bImmediate)>(0x116FE80);
	static inline auto FReleaseSaveGameEnumerators = PreyFunction<void(ArkGame *const _this)>(0x116FBF0);
	static inline auto FHandleDisconnectRequest = PreyFunction<void(ArkGame *const _this)>(0x116E460);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkGame *const _this, unsigned )>(0xA13080);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkGame *const _this, bool _bControllerDisconnect)>(0xA13080);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkGame *const _this)>(0x116EFE0);

	static inline auto GetArkGame = PreyFunction<ArkGame* ()>(0x116D820);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/iface/IArkActiveUserManagerListener.h>
#include <Prey/GameDll/ark/iface/ISaveGameEnumerator.h>
#include <_unknown/ArkHighlight.h>
#include <_unknown/ArkHighlightGroup.h>
#include <_unknown/ArkHighlightLocalizedPair.h>

class ArkApexVolumeManager;
class ArkCameraShakeManager;
class ArkChallengeManager;
class ArkDialogSubtitleManager;
class ArkDifficultyComponent;
class ArkEventScheduler;
class ArkGameModeManager;
class ArkGameStateConditionManager;
class ArkHackingUI;
class ArkIndicatorIconManager;
class ArkItemSystem;
class ArkLevelMapComponent;
class ArkLightManager;
class ArkLocationManager;
struct ArkNoiseAttentionParams;
class ArkObjectiveComponent;
class ArkPlayableCharacterManager;
class ArkRandomValueManager;
class ArkSaveMetaData;
namespace ArkSignalSystem
{
class Manager;
} // namespace ArkSignalSystem
class ArkSimulationManager;
class ArkTipComponent;
class ArkTutorialSystem;
class ArkWeaponSkinComponent;
class CCryName;
class CScriptBind_ArkPlayer;
enum class EArkSaveFileType;
enum ELoadGameResult;
enum ESystemEvent;
class IArkGameLoadSaveListener;
struct IEntityArchetype;
struct IPlayerProfile;
struct ISaveGame;
struct ISaveGameEnumerator;

// ArkGame
// Header:  Prey/GameDll/ark/ArkGame.h
class ArkGame : private IArkActiveUserManagerListener, public ISystemEventListener
{ // Size=464 (0x1D0)
public:
	enum class EArkSafeBoundsResult
	{
		Safe = 0,
		Warning = 1,
		Unsafe = 2,
	};

	enum class PauseRequestStatus
	{
		none = 0,
		pause = 1,
		pausedByRequest = 2,
		unpause = 3,
	};

	// ArkGame::ScreenBlackFadeInfo
	// Header:  Prey/GameDll/ark/ArkGame.h
	struct ScreenBlackFadeInfo
	{ // Size=8 (0x8)
		float m_blackDuration;
		float m_fadeOutDuration;

	#if 0
		ScreenBlackFadeInfo();
		void LoadConfig(const XmlNodeRef _arg0_);
	#endif
	};

	ArkGame::ScreenBlackFadeInfo m_levelLoadFade;
	ArkGame::ScreenBlackFadeInfo m_quickLoadFade;
	std::vector<string> m_captureVolumeWhiteList;
	std::array<_smart_ptr<ISaveGameEnumerator>, 1> m_saveGameEnumerators;
	std::array<std::vector<string>, 1> m_saveGameToUpdate;
	std::array<uint64_t, 1> m_campaignGuids;
	ArkSimpleTimer m_screenBlackTimer;
	ArkSimpleTimer m_screenFadeOutTimer;
	string m_saveFileToLoad;
	string m_loadLocationOverride;
	IArkGameLoadSaveListener* m_pLoadListener;
	uint64_t m_campaignPlayTime;
	float m_campaignTimerAccumulator;
	uint64_t m_currentLocationId;
	XmlNodeRef m_levelProperties;
	std::unique_ptr<CScriptBind_ArkPlayer> m_pScriptBindArkPlayer;
	std::unique_ptr<ArkCameraShakeManager> m_pArkCameraShakeManager;
	std::unique_ptr<ArkDialogSubtitleManager> m_pArkDialogSubtitleManager;
	std::unique_ptr<ArkDifficultyComponent> m_pArkDifficultyComponent;
	std::unique_ptr<ArkEventScheduler> m_pArkEventScheduler;
	std::unique_ptr<ArkGameStateConditionManager> m_pArkGameStateConditionManager;
	std::unique_ptr<ArkHackingUI> m_pArkHackingUI;
	std::unique_ptr<ArkIndicatorIconManager> m_pArkIndicatorIconManager;
	std::unique_ptr<ArkItemSystem> m_pArkItemSystem;
	std::unique_ptr<ArkLevelMapComponent> m_pArkLevelMapComponent;
	std::unique_ptr<ArkLightManager> m_pArkLightManager;
	std::unique_ptr<ArkLocationManager> m_pArkLocationManager;
	std::unique_ptr<ArkNoiseAttentionParams> m_pArkNoiseAttentionParams;
	std::unique_ptr<ArkObjectiveComponent> m_pArkObjectiveComponent;
	std::unique_ptr<ArkSignalSystem::Manager> m_pArkSignalManager;
	std::unique_ptr<ArkTipComponent> m_pArkTipComponent;
	std::unique_ptr<ArkTutorialSystem> m_pArkTutorialSystem;
	std::unique_ptr<ArkApexVolumeManager> m_pApexVolumeManager;
	std::unique_ptr<ArkGameModeManager> m_pArkGameModeManager;
	std::unique_ptr<ArkRandomValueManager> m_pRandomValueManager;
	std::unique_ptr<ArkPlayableCharacterManager> m_pPlayableCharacterManager;
	std::unique_ptr<ArkSimulationManager> m_pSimulationManager;
	std::unique_ptr<ArkChallengeManager> m_pChallengeManager;
	std::unique_ptr<ArkWeaponSkinComponent> m_pWeaponSkinComponent;
	AABB m_playerSafeBounds;
	EArkLoadDisconnectReason m_loadDisconnectReason;
	ArkGame::PauseRequestStatus m_pauseRequestStatus;
	float m_playerWarningBuffer;
	bool m_bLevelToLevelTransition;
	bool m_bSaveHasJustBeenDeletedBySystem;
	bool m_bPreTextureStreamerRunning;
	bool m_bTriggerReadyRoom;
	bool m_bNeedsToAutosaveOnMapLoad;
	static inline auto g_skipContinuePrompt = PreyGlobal<int>(0x2D3C358);
	static constexpr const int kPlayerDeathHighlightId = 0;
	static constexpr const int kScorecardHighlightId = 1;
	std::vector<ArkHighlight> m_highlights;
	ArkHighlightGroup m_highlightGroup;

	virtual ~ArkGame();
	static std::unique_ptr<ArkGame> Create() { return FCreate(); }
	static void RegisterCVars() { FRegisterCVars(); }
	static IPlayerProfile* GetCurrentProfile() { return FGetCurrentProfile(); }
	static EArkSaveFileType GetSaveFileType(const ISaveGameEnumerator::SGameDescription& _desc) { return FGetSaveFileType(_desc); }
	boost::optional<ISaveGameEnumerator::SGameDescription> GetMostRecentSave(int _campaignSlot) { alignas(boost::optional<ISaveGameEnumerator::SGameDescription>) std::byte _return_buf_[sizeof(boost::optional<ISaveGameEnumerator::SGameDescription>)]; return *FGetMostRecentSaveOv1(this, reinterpret_cast<boost::optional<ISaveGameEnumerator::SGameDescription>*>(_return_buf_), _campaignSlot); }
	boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> > GetMostRecentSave() { alignas(boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> >) std::byte _return_buf_[sizeof(boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> >)]; return *FGetMostRecentSaveOv0(this, reinterpret_cast<boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> >*>(_return_buf_)); }
	static ArkSaveMetaData GetSaveMetadata(const ISaveGameEnumerator::SGameDescription& _desc) { return FGetSaveMetadata(_desc); }
	static bool CanSave(bool _bManual) { return FCanSave(_bManual); }
	bool CampaignSave(bool _bImmediate) { return FCampaignSave(this, _bImmediate); }
	bool ManualSave() { return FManualSave(this); }
	bool IsMaxManualSaveCountReached() { return FIsMaxManualSaveCountReachedOv1(this); }
	void Init() { FInit(this); }
	void CompleteInit() { FCompleteInit(this); }
	void Reset() { FReset(this); }
	void ResetGameState() { FResetGameState(this); }
	void Shutdown() { FShutdown(this); }
	void ProcessInput(const CCryName& _actionId, int _activationMode, float _value) { FProcessInput(this, _actionId, _activationMode, _value); }
	void Update(float _frameTime) { FUpdate(this, _frameTime); }
	uint64_t GetCampaignPlayTime() const { return FGetCampaignPlayTime(this); }
	ELoadGameResult LoadLastSave(IArkGameLoadSaveListener* _pListener) { return FLoadLastSave(this, _pListener); }
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	ArkGame::EArkSafeBoundsResult GetPlayerSafeBoundsResult(const Vec3& _pos, float& _warningMagnitude) const { return FGetPlayerSafeBoundsResult(this, _pos, _warningMagnitude); }
	void OnLevelLoad() { FOnLevelLoad(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void OnLevelEnd() const { FOnLevelEnd(this); }
	void OnLevelUnload() const { FOnLevelUnload(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	void SerializeBeforeEntities(TSerialize _serializer) const { FSerializeBeforeEntities(this, _serializer); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	void SerializeForLevelState(TSerialize _serializer) const { FSerializeForLevelState(this, _serializer); }
	void PostSerialize() { FPostSerialize(this); }
	void PostSerializeBeforeEntities() { FPostSerializeBeforeEntities(this); }
	void SerializeLTL(TSerialize _serializer) { FSerializeLTL(this, _serializer); }
	void DumpObjectiveStateToFile(const char* _fileName) const { FDumpObjectiveStateToFile(this, _fileName); }
	void AddSaveMetadata(ISaveGame& _save) const { FAddSaveMetadata(this, _save); }
	void OnLevelToLevelTransition() { FOnLevelToLevelTransition(this); }
	void OnLevelTransitionFinished() { FOnLevelTransitionFinished(this); }
	void OnNewGame(const int _campaignSlot) { FOnNewGame(this, _campaignSlot); }
	void OnSaveGame() { FOnSaveGame(this); }
	void OnSetCampaignSlot() { FOnSetCampaignSlot(this); }
	void StartHighlightGroup() const { FStartHighlightGroup(this); }
	void EndHighlightGroup() const { FEndHighlightGroup(this); }
	uint64_t GetCurrentLocationId() const { return FGetCurrentLocationId(this); }
	bool InLevelToLevelTransition() const { return FInLevelToLevelTransition(this); }
	const char* GetLoadingScreenTip(bool _bUseLevelTip) const { return FGetLoadingScreenTip(this, _bUseLevelTip); }
	void SetRichPresence(const string& _rpKey) const { FSetRichPresence(this, _rpKey); }
	const char* GetGameMode() const { return FGetGameMode(this); }
	void SetArkLevelProperties(XmlNodeRef _xmlNode) { FSetArkLevelProperties(this, _xmlNode); }
	XmlNodeRef GetArkLevelProperties() const { alignas(XmlNodeRef) std::byte _return_buf_[sizeof(XmlNodeRef)]; return *FGetArkLevelProperties(this, reinterpret_cast<XmlNodeRef*>(_return_buf_)); }
	XmlNodeRef GetArkLevelPropertiesGroup() const { alignas(XmlNodeRef) std::byte _return_buf_[sizeof(XmlNodeRef)]; return *FGetArkLevelPropertiesGroup(this, reinterpret_cast<XmlNodeRef*>(_return_buf_)); }
	CScriptBind_ArkPlayer& GetArkPlayerScriptBind() const { return FGetArkPlayerScriptBind(this); }
	const ArkNoiseAttentionParams& GetArkNoiseAttentionParams() const { return FGetArkNoiseAttentionParams(this); }
	ArkDialogSubtitleManager& GetArkDialogSubtitleManager() const { return FGetArkDialogSubtitleManager(this); }
	ArkDifficultyComponent& GetArkDifficultyComponent() const { return FGetArkDifficultyComponent(this); }
	ArkEventScheduler& GetArkEventScheduler() const { return FGetArkEventScheduler(this); }
	ArkGameStateConditionManager& GetArkGameStateConditionManager() const { return FGetArkGameStateConditionManager(this); }
	ArkHackingUI& GetArkHackingUI() const { return FGetArkHackingUI(this); }
	ArkIndicatorIconManager& GetArkIndicatorIconManager() const { return FGetArkIndicatorIconManager(this); }
	ArkItemSystem& GetArkItemSystem() const { return FGetArkItemSystem(this); }
	ArkLevelMapComponent& GetArkLevelMapComponent() const { return FGetArkLevelMapComponent(this); }
	ArkLocationManager& GetArkLocationManager() const { return FGetArkLocationManager(this); }
	ArkObjectiveComponent& GetArkObjectiveComponent() const { return FGetArkObjectiveComponent(this); }
	ArkSignalSystem::Manager& GetArkSignalManager() const { return FGetArkSignalManager(this); }
	ArkTipComponent& GetArkTipComponent() const { return FGetArkTipComponent(this); }
	ArkTutorialSystem& GetArkTutorialSystem() const { return FGetArkTutorialSystem(this); }
	ArkCameraShakeManager& GetArkCameraShakeManager() const { return FGetArkCameraShakeManager(this); }
	ArkLightManager& GetArkLightManager() const { return FGetArkLightManager(this); }
	_smart_ptr<ISaveGameEnumerator> GetSaveGameEnumerator(const int _campaignSlot) { alignas(_smart_ptr<ISaveGameEnumerator>) std::byte _return_buf_[sizeof(_smart_ptr<ISaveGameEnumerator>)]; return *FGetSaveGameEnumerator(this, reinterpret_cast<_smart_ptr<ISaveGameEnumerator>*>(_return_buf_), _campaignSlot); }
	_smart_ptr<ISaveGameEnumerator> GetCurrentCampaignSaveGameEnumerator() { alignas(_smart_ptr<ISaveGameEnumerator>) std::byte _return_buf_[sizeof(_smart_ptr<ISaveGameEnumerator>)]; return *FGetCurrentCampaignSaveGameEnumerator(this, reinterpret_cast<_smart_ptr<ISaveGameEnumerator>*>(_return_buf_)); }
	void DeleteSave(const int _campaignSlot, const char* const _name) { FDeleteSave(this, _campaignSlot, _name); }
	void SaveProfile() const { FSaveProfile(this); }
	void UpdateCampaignGuids() { FUpdateCampaignGuids(this); }
	void CheckSaveStatusOnReturnToMainMenu() { FCheckSaveStatusOnReturnToMainMenu(this); }
	static std::vector<ArkHighlightLocalizedPair> CreateHighlightLocalizedPairForId(int _id) { return FCreateHighlightLocalizedPairForId(_id); }
	ArkGame();
	void LoadConfig() { FLoadConfig(this); }
	bool CreateRollingSave(const EArkSaveFileType _type, const uint8_t _maxCount, bool _bImmediate) { return FCreateRollingSave(this, _type, _maxCount, _bImmediate); }
	bool SaveGame(const char* const _name, const bool _bImmediate) { return FSaveGame(this, _name, _bImmediate); }
	void ReleaseSaveGameEnumerators() { FReleaseSaveGameEnumerators(this); }
	void HandleDisconnectRequest() { FHandleDisconnectRequest(this); }
	virtual void OnActiveUserIdChanged(unsigned __unnamed1);
	virtual void OnActiveUserDisconnected(bool _bControllerDisconnect);
	virtual void OnActiveUserSignedOut();

#if 0
	bool OverwriteSave(const char* const _arg0_);
	bool IsMaxManualSaveCountReached(const int _arg0_);
	uint64_t GetCampaignPlayTimeWithAccumulator() const;
	uint64_t GetCurrentCampaignGuid() const;
	ELoadGameResult LoadSave(const string& _arg0_, const string& _arg1_, IArkGameLoadSaveListener* _arg2_);
	ArkApexVolumeManager& GetApexVolumeManager() const;
	ArkGameModeManager& GetArkGameModeManager() const;
	ArkRandomValueManager& GetRandomValueManager() const;
	ArkPlayableCharacterManager& GetPlayableCharacterManager() const;
	ArkSimulationManager& GetSimulationManager() const;
	ArkChallengeManager& GetChallengeManager() const;
	ArkWeaponSkinComponent& GetWeaponSkinComponent() const;
	void OnSaveDeletedBySystem();
	void RequestDisconnect(EArkLoadDisconnectReason _arg0_);
	EArkLoadDisconnectReason GetDisconnectReason() const;
	bool ShouldArchetypeBeConsideredByCaptureVolume(const IEntityArchetype* const _arg0_) const;
	static bool CanSkipContinuePrompt();
	void StartQuickLoadFade();
	void RequestPause(const bool _arg0_);
	bool IsPauseRequestedBySystem() const;
	void OnCloseContinuePrompt();
	const ArkHighlightGroup& GetDefaultHighlightGroup() const;
	const ArkHighlight& GetPlayerDeathHighlight() const;
	const ArkHighlight& GetScorecardHighlight() const;
	void StartFade(const ArkGame::ScreenBlackFadeInfo _arg0_);
	bool CreateManualSave(const char* const _arg0_, const bool _arg1_);
#endif

	static inline auto FBitNotArkGame = PreyFunction<void(ArkGame* const _this)>(0x11E5800);
	static inline auto FCreate = PreyFunction<std::unique_ptr<ArkGame>()>(0x11E6180);
	static inline auto FRegisterCVars = PreyFunction<void()>(0x11E9040);
	static inline auto FGetCurrentProfile = PreyFunction<IPlayerProfile* ()>(0x11E6D10);
	static inline auto FGetSaveFileType = PreyFunction<EArkSaveFileType(const ISaveGameEnumerator::SGameDescription& _desc)>(0x11E7580);
	static inline auto FGetMostRecentSaveOv1 = PreyFunction<boost::optional<ISaveGameEnumerator::SGameDescription>*(ArkGame* const _this, boost::optional<ISaveGameEnumerator::SGameDescription>* _return_value_, int _campaignSlot)>(0x11E7180);
	static inline auto FGetMostRecentSaveOv0 = PreyFunction<boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> >*(ArkGame* const _this, boost::optional<std::pair<ISaveGameEnumerator::SGameDescription,int> >* _return_value_)>(0x11E6FC0);
	static inline auto FGetSaveMetadata = PreyFunction<ArkSaveMetaData(const ISaveGameEnumerator::SGameDescription& _desc)>(0x11E76F0);
	static inline auto FCanSave = PreyFunction<bool(bool _bManual)>(0x11E5D60);
	static inline auto FCampaignSave = PreyFunction<bool(ArkGame* const _this, bool _bImmediate)>(0x11E5D50);
	static inline auto FManualSave = PreyFunction<bool(ArkGame* const _this)>(0x11E8300);
	static inline auto FIsMaxManualSaveCountReachedOv1 = PreyFunction<bool(ArkGame* const _this)>(0x11E7D00);
	static inline auto FInit = PreyFunction<void(ArkGame* const _this)>(0x11E7870);
	static inline auto FCompleteInit = PreyFunction<void(ArkGame* const _this)>(0x11E5F10);
	static inline auto FReset = PreyFunction<void(ArkGame* const _this)>(0x11E90D0);
	static inline auto FResetGameState = PreyFunction<void(ArkGame* const _this)>(0x11E9240);
	static inline auto FShutdown = PreyFunction<void(ArkGame* const _this)>(0x11E9C80);
	static inline auto FProcessInput = PreyFunction<void(ArkGame* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x11E8FD0);
	static inline auto FUpdate = PreyFunction<void(ArkGame* const _this, float _frameTime)>(0x11E9D50);
	static inline auto FGetCampaignPlayTime = PreyFunction<uint64_t(const ArkGame* const _this)>(0x11E6CB0);
	static inline auto FLoadLastSave = PreyFunction<ELoadGameResult(ArkGame* const _this, IArkGameLoadSaveListener* _pListener)>(0x11E8010);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0x11E8EC0);
	static inline auto FGetPlayerSafeBoundsResult = PreyFunction<ArkGame::EArkSafeBoundsResult(const ArkGame* const _this, const Vec3& _pos, float& _warningMagnitude)>(0x11E73F0);
	static inline auto FOnLevelLoad = PreyFunction<void(ArkGame* const _this)>(0x11E8520);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkGame* const _this)>(0x11E8580);
	static inline auto FOnLevelEnd = PreyFunction<void(const ArkGame* const _this)>(0x11E8510);
	static inline auto FOnLevelUnload = PreyFunction<void(const ArkGame* const _this)>(0x11E8700);
	static inline auto FOnGameEnded = PreyFunction<void(ArkGame* const _this)>(0x11E84D0);
	static inline auto FSerializeBeforeEntities = PreyFunction<void(const ArkGame* const _this, TSerialize _serializer)>(0x11E98C0);
	static inline auto FSerialize = PreyFunction<void(ArkGame* const _this, TSerialize _serializer)>(0x11E96D0);
	static inline auto FSerializeForLevelState = PreyFunction<void(const ArkGame* const _this, TSerialize _serializer)>(0x11E98F0);
	static inline auto FPostSerialize = PreyFunction<void(ArkGame* const _this)>(0x11E8F40);
	static inline auto FPostSerializeBeforeEntities = PreyFunction<void(ArkGame* const _this)>(0x11E8FC0);
	static inline auto FSerializeLTL = PreyFunction<void(ArkGame* const _this, TSerialize _serializer)>(0x11E9950);
	static inline auto FDumpObjectiveStateToFile = PreyFunction<void(const ArkGame* const _this, const char* _fileName)>(0x11E6800);
	static inline auto FAddSaveMetadata = PreyFunction<void(const ArkGame* const _this, ISaveGame& _save)>(0x11E5C40);
	static inline auto FOnLevelToLevelTransition = PreyFunction<void(ArkGame* const _this)>(0x11E8670);
	static inline auto FOnLevelTransitionFinished = PreyFunction<void(ArkGame* const _this)>(0x11E86A0);
	static inline auto FOnNewGame = PreyFunction<void(ArkGame* const _this, const int _campaignSlot)>(0x11E8740);
	static inline auto FOnSaveGame = PreyFunction<void(ArkGame* const _this)>(0x11E89C0);
	static inline auto FOnSetCampaignSlot = PreyFunction<void(ArkGame* const _this)>(0x11E8B30);
	static inline auto FStartHighlightGroup = PreyFunction<void(const ArkGame* const _this)>(0x11E9D20);
	static inline auto FEndHighlightGroup = PreyFunction<void(const ArkGame* const _this)>(0x11E6BD0);
	static inline auto FGetCurrentLocationId = PreyFunction<uint64_t(const ArkGame* const _this)>(0x1B7C8C0);
	static inline auto FInLevelToLevelTransition = PreyFunction<bool(const ArkGame* const _this)>(0x11E7860);
	static inline auto FGetLoadingScreenTip = PreyFunction<const char* (const ArkGame* const _this, bool _bUseLevelTip)>(0x11E6DC0);
	static inline auto FSetRichPresence = PreyFunction<void(const ArkGame* const _this, const string& _rpKey)>(0x1333E90);
	static inline auto FGetGameMode = PreyFunction<const char* (const ArkGame* const _this)>(0x11E6D60);
	static inline auto FSetArkLevelProperties = PreyFunction<void(ArkGame* const _this, XmlNodeRef _xmlNode)>(0x11E9980);
	static inline auto FGetArkLevelProperties = PreyFunction<XmlNodeRef*(const ArkGame* const _this, XmlNodeRef* _return_value_)>(0x11E6C30);
	static inline auto FGetArkLevelPropertiesGroup = PreyFunction<XmlNodeRef*(const ArkGame* const _this, XmlNodeRef* _return_value_)>(0x11E6C60);
	static inline auto FGetArkPlayerScriptBind = PreyFunction<CScriptBind_ArkPlayer& (const ArkGame* const _this)>(0xAB5630);
	static inline auto FGetArkNoiseAttentionParams = PreyFunction<const ArkNoiseAttentionParams& (const ArkGame* const _this)>(0x1834030);
	static inline auto FGetArkDialogSubtitleManager = PreyFunction<ArkDialogSubtitleManager& (const ArkGame* const _this)>(0x9FCEC0);
	static inline auto FGetArkDifficultyComponent = PreyFunction<ArkDifficultyComponent& (const ArkGame* const _this)>(0x9FCC40);
	static inline auto FGetArkEventScheduler = PreyFunction<ArkEventScheduler& (const ArkGame* const _this)>(0x11E6C10);
	static inline auto FGetArkGameStateConditionManager = PreyFunction<ArkGameStateConditionManager& (const ArkGame* const _this)>(0x84FDC0);
	static inline auto FGetArkHackingUI = PreyFunction<ArkHackingUI& (const ArkGame* const _this)>(0x105410);
	static inline auto FGetArkIndicatorIconManager = PreyFunction<ArkIndicatorIconManager& (const ArkGame* const _this)>(0x84FDD0);
	static inline auto FGetArkItemSystem = PreyFunction<ArkItemSystem& (const ArkGame* const _this)>(0x9FCC50);
	static inline auto FGetArkLevelMapComponent = PreyFunction<ArkLevelMapComponent& (const ArkGame* const _this)>(0x5D9010);
	static inline auto FGetArkLocationManager = PreyFunction<ArkLocationManager& (const ArkGame* const _this)>(0x84FDB0);
	static inline auto FGetArkObjectiveComponent = PreyFunction<ArkObjectiveComponent& (const ArkGame* const _this)>(0x5D8F30);
	static inline auto FGetArkSignalManager = PreyFunction<ArkSignalSystem::Manager& (const ArkGame* const _this)>(0x11E6CA0);
	static inline auto FGetArkTipComponent = PreyFunction<ArkTipComponent& (const ArkGame* const _this)>(0x19E85A0);
	static inline auto FGetArkTutorialSystem = PreyFunction<ArkTutorialSystem& (const ArkGame* const _this)>(0x16804C0);
	static inline auto FGetArkCameraShakeManager = PreyFunction<ArkCameraShakeManager& (const ArkGame* const _this)>(0x11C8520);
	static inline auto FGetArkLightManager = PreyFunction<ArkLightManager& (const ArkGame* const _this)>(0x9ED890);
	static inline auto FGetSaveGameEnumerator = PreyFunction<_smart_ptr<ISaveGameEnumerator>*(ArkGame* const _this, _smart_ptr<ISaveGameEnumerator>* _return_value_, const int _campaignSlot)>(0x11E75E0);
	static inline auto FGetCurrentCampaignSaveGameEnumerator = PreyFunction<_smart_ptr<ISaveGameEnumerator>*(ArkGame* const _this, _smart_ptr<ISaveGameEnumerator>* _return_value_)>(0x11E6CC0);
	static inline auto FDeleteSave = PreyFunction<void(ArkGame* const _this, const int _campaignSlot, const char* const _name)>(0x11E6750);
	static inline auto FSaveProfile = PreyFunction<void(const ArkGame* const _this)>(0x11E9520);
	static inline auto FUpdateCampaignGuids = PreyFunction<void(ArkGame* const _this)>(0x17FAA80);
	static inline auto FCheckSaveStatusOnReturnToMainMenu = PreyFunction<void(ArkGame* const _this)>(0x11E5EB0);
	static inline auto FCreateHighlightLocalizedPairForId = PreyFunction<std::vector<ArkHighlightLocalizedPair>(int _id)>(0x11E61C0);
	static inline auto FArkGame = PreyFunction<void(ArkGame* const _this)>(0x11E4740);
	static inline auto FLoadConfig = PreyFunction<void(ArkGame* const _this)>(0x11E7E00);
	static inline auto FCreateRollingSave = PreyFunction<bool(ArkGame* const _this, const EArkSaveFileType _type, const uint8_t _maxCount, bool _bImmediate)>(0x11E64A0);
	static inline auto FSaveGame = PreyFunction<bool(ArkGame* const _this, const char* const _name, const bool _bImmediate)>(0x11E93A0);
	static inline auto FReleaseSaveGameEnumerators = PreyFunction<void(ArkGame* const _this)>(0x11E9050);
	static inline auto FHandleDisconnectRequest = PreyFunction<void(ArkGame* const _this)>(0x11E77B0);
	static inline auto FOnActiveUserIdChanged = PreyFunction<void(ArkGame* const _this, unsigned __unnamed1)>(0x1333E90);
	static inline auto FOnActiveUserDisconnected = PreyFunction<void(ArkGame* const _this, bool _bControllerDisconnect)>(0x1333E90);
	static inline auto FOnActiveUserSignedOut = PreyFunction<void(ArkGame* const _this)>(0x11E84C0);
};
#endif // !MOONCRASH
