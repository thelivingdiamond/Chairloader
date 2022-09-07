#pragma once
#include "Prey/ArkEnums.h"
#include "Prey/CryEntitySystem/IEntity.h"
#include "Prey/CryNetwork/ISerialize.h"
#include "Prey/CryThreading/IJobManager.h"

struct IGameFramework;
class IArkDoor ;
class IArkPlayer;
class IArkEncounterManager ;
class IArkFactionManager ;
struct IArkGlintConfigManager ;
class IArkGravShaft ;
class IArkMetaTagManager ;
class IArkPADialogManager ;
class IArkPatrolManager;
struct IArkPostEffectManager;
class IGameToEditorInterface ;
class IGameWarningsListener ;
class IGameStateRecorder;
class IGameplayListener;
class IGamePhysicsSettings;
class IArkGlooIslandNavLinkManager;
class IArkResponseManager;
class IArkNpc;
struct SActionEvent;
struct SRenderingPassInfo;
struct IAntiCheatManager;

enum ESaveGameMethod {
	eSGM_NoSave = 0,
	eSGM_QuickSave = 1,
	eSGM_Save = 2
};

enum ESaveGameReason {
	eSGR_LevelStart = 0,
	eSGR_FlowGraph = 1,
	eSGR_Command = 2,
	eSGR_QuickSave = 3
};
struct ISaveGame
{
public:
	virtual ~ISaveGame() = 0;
	virtual bool Init(const char*) = 0;
	virtual void AddMetadata(const char*, int) = 0;
	virtual void AddMetadata(const char*, const char*) = 0;
	virtual CSerializeWrapper<ISerialize>* AddSection(CSerializeWrapper<ISerialize>* result, const char*) = 0;
	virtual unsigned __int8* SetThumbnail(const unsigned __int8*, int, int, int) = 0;
	virtual bool SetThumbnailFromBMP(const char*) = 0;
	virtual void StartAsyncWrite(JobManager::SJobState*) = 0;
	virtual XmlNodeRef* GetMetadata(XmlNodeRef* result) = 0;
	virtual bool Complete(bool) = 0;
	virtual const char* GetFileName() = 0;
	virtual void SetSaveGameReason(ESaveGameReason) = 0;
	virtual ESaveGameReason GetSaveGameReason() = 0;
	virtual void GetMemoryUsage(ICrySizer*) = 0;


};
struct ILoadGame
{
public:
	virtual ~ILoadGame() = 0;
	virtual bool Init(const char*) = 0;
	virtual unsigned int GetPlatformUserId() = 0;
	virtual IGeneralMemoryHeap* GetHeap() = 0;
	virtual bool GetMetadata(const char*, int*) = 0;
	virtual const char* GetMetadata(const char*) = 0;
	virtual bool HaveMetadata(const char*) = 0;
	virtual std::unique_ptr<CSerializeWrapper<ISerialize>>* GetSection(std::unique_ptr<CSerializeWrapper<ISerialize>>* result, const char*) = 0;
	virtual bool HaveSection(const char*) = 0;
	virtual void Complete() = 0;
	virtual const char* GetFileName() = 0;


};
class IGameFrameworkListener
{
public:
	virtual ~IGameFrameworkListener() = 0;
	virtual void OnPostUpdate(float) = 0;
	virtual void OnSaveGame(ISaveGame*) = 0;
	virtual void OnLoadGame(ILoadGame*) = 0;
	virtual void OnLevelEnd(const char*) = 0;
	virtual void OnActionEvent(const SActionEvent&) = 0;
	virtual void OnPreRender() = 0;
	virtual void OnSavegameFileLoadedInMemory(const char*) = 0;
	virtual void OnForceLoadingWithFlash() = 0;


};
class IGame
{
public:
	class ExportFilesInfo
	{
		const char* m_pBaseFileName;
		const unsigned int m_fileCount;
	};
	class CaptureVolumeInfo
	{
		class EntityInfo
		{
			IEntity* m_pEntity;
			Vec3_tpl<float> m_offset;
		};
		Vec3_tpl<float> m_position;
		CryStringT<char> m_name;
		std::vector<IGame::CaptureVolumeInfo::EntityInfo> m_entities;
		CryStringT<char> m_capturedNPCArchetype;
	};
	virtual ~IGame() = 0;
	virtual bool Init(IGameFramework*) = 0;
	virtual void InitEditor(IGameToEditorInterface*) = 0;
	virtual void GetMemoryStatistics(ICrySizer*) = 0;
	virtual bool CompleteInit() = 0;
	virtual void Shutdown() = 0;
	virtual int Update(bool, unsigned int) = 0;
	virtual void EditorResetGame(bool) = 0;
	virtual void PlayerIdSet(unsigned int) = 0;
	virtual const char* GetLongName() = 0;
	virtual const char* GetName() = 0;
	virtual void LoadActionMaps(const char*) = 0;
	virtual void OnClearPlayerIds() = 0;
	virtual CryStackStringT<char, 256>* CreateSaveGameName(CryStackStringT<char, 256>* result) = 0;
	virtual IGameFramework* GetIGameFramework() = 0;
	virtual const char* GetMappedLevelName(const char*) = 0;
	virtual IAntiCheatManager* GetAntiCheatManager() = 0;
	virtual bool DoInitialSavegame() = 0;
	virtual unsigned int AddGameWarning(const char*, const char*, IGameWarningsListener*) = 0;
	virtual void OnRenderScene(const SRenderingPassInfo*) = 0;
	virtual void RenderGameWarnings() = 0;
	virtual void RemoveGameWarning(const char*) = 0;
	virtual bool GameEndLevel(const char*) = 0;
	virtual void SetUserProfileChanged(bool) = 0;
	virtual const unsigned __int8* GetDRMKey(unsigned int*) = 0;
	virtual const char* GetDRMFileList() = 0;
	virtual IGameStateRecorder* CreateGameStateRecorder(IGameplayListener*) = 0;
	virtual void FullSerialize(CSerializeWrapper<ISerialize>) = 0;
	virtual void FullSerializeBeforeEntities(CSerializeWrapper<ISerialize>) = 0;
	virtual void SerializeForLevelState(CSerializeWrapper<ISerialize>) = 0;
	virtual void PostSerialize() = 0;
	virtual void PostSerializeForLevelState() = 0;
	virtual bool CanSave() = 0;
	virtual void PostSerializeBeforeEntities() = 0;
	virtual void SerializeLTL(bool) = 0;
	virtual bool LevelIsTalosExterior() = 0;
	virtual IGame::ExportFilesInfo* ExportLevelData(IGame::ExportFilesInfo* result, const char*, const char*) = 0;
	virtual const char* ExportAudioPropagation(const char*) = 0;
	virtual void LoadExportedLevelData(const char*, const char*) = 0;
	virtual void LoadAudioPropagation(const char*) = 0;
	virtual void RegisterGameFlowNodes() = 0;
	virtual IGamePhysicsSettings* GetIGamePhysicsSettings() = 0;
	virtual void* GetGameInterface() = 0;
	virtual IArkDoor* GetIArkDoorSafe(unsigned int) = 0;
	virtual IArkEncounterManager* GetIArkEncounterManager() = 0;
	virtual IArkFactionManager* GetIArkFactionManager() = 0;
	virtual IArkGlintConfigManager* GetIArkGlintConfigManager() = 0;
	virtual IArkGravShaft* GetIArkGravShaftSafe(unsigned int) = 0;
	virtual IArkMetaTagManager* GetIArkMetaTagManager() = 0;
	virtual IArkPADialogManager* GetIArkPADialogManager() = 0;
	virtual IArkPatrolManager* GetIArkPatrolManager() = 0;
	virtual IArkPlayer* GetIArkPlayerPtr() = 0;
	virtual IArkPostEffectManager* GetIArkPostEffectManager() = 0;
	virtual IArkResponseManager* GetIArkResponseManager() = 0;
	virtual IArkGlooIslandNavLinkManager* GetIArkGlooIslandNavLinkManager() = 0;
	virtual IArkNpc* SafeGetIArkNpc(unsigned int) = 0;
	virtual void AddArkGameNoise(const unsigned int, const Vec3_tpl<float>*, const unsigned __int64, const unsigned __int64) = 0;
	virtual void ResetGameState() = 0;
	virtual void OnLevelToLevelTransition() = 0;
	virtual void OnLevelTransitionFinished() = 0;
	virtual std::vector<IGame::CaptureVolumeInfo>* GetCaptureVolumeInfos(std::vector<IGame::CaptureVolumeInfo>* result) = 0;
	virtual void OnNewGame(const int) = 0;
	virtual void LoadArkLevelProperties(const XmlNodeRef*) = 0;
	virtual void SetArkAutoMapScale(const float) = 0;
	virtual XmlNodeRef* GetArkLevelProperties(XmlNodeRef* result) = 0;
	virtual const char* GetCurrentArkLocationLabel() = 0;
	virtual const char* GetArkLoadLocationLabel() = 0;
	virtual void SetArkLoadLocationLabel(const char* const) = 0;
	virtual const char* GetArkLoadingScreenTip(bool) = 0;
	virtual const char* GetArkGameMode() = 0;
	virtual void OnSaveDeletedBySystem() = 0;
	virtual void RequestDisconnect(EArkLoadDisconnectReason) = 0;
	virtual EArkLoadDisconnectReason GetDisconnectReason() = 0;
	virtual void RequestPause(const bool) = 0;
	virtual void DebugDraw() = 0;
	virtual unsigned int GetExclusiveControllerDeviceIndex() = 0;
	virtual unsigned int GetPlatformUserIdPairedToDevice(unsigned __int64) = 0;
	virtual unsigned int GetCurrentUserPlatformUserId() = 0;
	virtual unsigned int GetPlayerProfilePlatformUserId(const char*) = 0;
	virtual bool IsPlayerProfileSignedInToOS(const char*) = 0;
	virtual bool IsPlatformUserSignedInToOS(unsigned int) = 0;
	virtual void RefreshControlScheme() = 0;
	virtual void UnlockPlayerCamera(float) = 0;
	virtual void LockPlayerCameraToAnimation(float) = 0;
	virtual void LockPlayerCameraToEntityBone(const unsigned int, const int, float) = 0;
	virtual void OpenPauseMenu(bool) = 0;
	virtual void DumpObjectiveStateToFile(const char*) = 0;
};
static_assert(sizeof(IGame) == 0x8);