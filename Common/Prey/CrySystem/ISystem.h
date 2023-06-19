// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#ifdef CRYSYSTEM_EXPORTS
	#define CRYSYSTEM_API DLL_EXPORT
#else
	#define CRYSYSTEM_API DLL_IMPORT
#endif

#include <Prey/CryCore/Platform/platform.h> // Needed for LARGE_INTEGER (for consoles).

#include <Prey/CryCore/Assert/CryAssert.h>
#include <Prey/CryCore/Assert/CompileTimeAssert.h>

#include <Prey/CrySystem/XML/IXml.h> // <> required for Interfuscator
#include "IValidator.h"         // <> required for Interfuscator
#include <Prey/CrySystem/ILog.h>     // <> required for Interfuscator
#include <Prey/CryString/StringUtils.h>
#include "CryVersion.h"
#include <Prey/CryCore/smartptr.h>

#include "Prey/CryGame/IGame.h"
#include <Chairloader/ChairVars.h>

//#include <Prey/CryMemory/IMemory.h>          // <> required for Interfuscator
//#include <Prey/CrySystem/ISystemScheduler.h> // <> required for Interfuscator

struct ISystem;
struct ILog;
struct IProfileLogSystem;
struct IEntitySystem;
struct IEntity;
struct ICryPak;
struct IKeyboard;
struct IMouse;
struct IConsole;
struct IRemoteConsole;
struct IInput;
struct IRenderer;
struct IRenderAuxGeom;
struct IConsole;
namespace Telemetry {
struct ITelemetrySystem;
}
struct IProcess;
struct I3DEngine;
struct ITimer;
struct IGameStartup;
struct IScriptSystem;
struct IAISystem;
struct IFlash;
struct INetwork;
struct IOnline;
struct ICryLobby;
struct ICryFont;
struct IMovieSystem;
struct IPhysicalWorld;
struct IMemoryManager;
struct IAudioSystem;
struct IFrameProfileSystem;
struct IStatoscope;
struct IDiskProfiler;
struct FrameProfiler;
struct IStreamEngine;
struct ICharacterManager;
struct SFileVersion;
struct INameTable;
struct IBudgetingSystem;
struct IFlowSystem;
struct IDialogSystem;
namespace DRS {
struct IDynamicResponseSystem;
}
struct IMaterialEffects;
struct IParticleManager;
class IOpticsManager;
struct IHardwareMouse;
struct IFlashPlayer;
struct IFlashPlayerBootStrapper;
struct IFlashLoadMovieHandler;
struct IHmdDevice;
class ICrySizer;
struct ITestSystem;
class IXMLBinarySerializer;
struct IReadWriteXMLSink;
struct IResourceManager;
struct ITextModeConsole;
struct IAVI_Reader;
class CPNoise3;
struct IFileChangeMonitor;
struct ILocalizationManager;
struct ICryFactoryRegistry;
struct ICodeCheckpointMgr;
struct IZLibCompressor;
struct IZLibDecompressor;
struct ILZ4Decompressor;
struct IOutputPrintSink;
struct IPhysicsDebugRenderer;
struct IPhysRenderer;
struct IOverloadSceneManager;
struct IFlashUI;
struct IThreadManager;
struct IServiceNetwork;
struct IRemoteCommandManager;
struct IWindowMessageHandler;
struct SFunctor;
struct IScaleformHelper;
struct ICryPluginManager;
struct IArkDlcSystem;
struct IArkRewardSystem;
struct IArkEntitlementSystem;
struct IArkDlcSystem;
class IArkRoomVolumeManager;
class ArkBuildInfo;
struct ILevelEncrypter;
struct IEvaluationManager;
struct IArkBethesdaNetManager;
struct IThreadTaskManager;
struct IVisualLog;
struct SArkFrameProfileInfo;
struct IDataProbe;
struct IDebugCallStack;
enum EValidatorModule;
enum EValidatorSeverity;
enum EPLM_Event;
enum EPLM_State;

class CBootProfilerRecord;

namespace UIFramework
{
struct IUIFramework;
}

namespace Serialization {
struct IArchiveHost;
}

namespace LiveCreate
{
struct IManager;
struct IHost;
}

namespace Telemetry
{
struct ITelemetrySystem;
}

struct IMonoRuntime;

struct ILocalMemoryUsage;

typedef void* WIN_HWND;

class CCamera;
struct CLoadingTimeProfiler;

class ICmdLine;
class CFrameProfilerSection;

struct INotificationNetwork;
struct IPlatformOS;
struct ICryPerfHUD;

namespace JobManager {
struct IJobManager;
}

#define PROC_MENU     1
#define PROC_3DENGINE 2

// Maybe they should be moved into the game.dll .
//! IDs for script userdata typing.
//! ##@{
#define USER_DATA_SOUND       1
#define USER_DATA_TEXTURE     2
#define USER_DATA_OBJECT      3
#define USER_DATA_LIGHT       4
#define USER_DATA_BONEHANDLER 5
#define USER_DATA_POINTER     6
//! ##@}.

enum ESystemUpdateFlags
{
	ESYSUPDATE_IGNORE_AI         = 0x0001,
	ESYSUPDATE_IGNORE_PHYSICS    = 0x0002,
	//! Special update mode for editor.
	ESYSUPDATE_EDITOR            = 0x0004,
	ESYSUPDATE_MULTIPLAYER       = 0x0008,
	ESYSUPDATE_EDITOR_AI_PHYSICS = 0x0010,
	ESYSUPDATE_EDITOR_ONLY       = 0x0020
};

//! Configuration specification, depends on user selected machine specification.
enum ESystemConfigSpec
{
	CONFIG_CUSTOM        = 0, //!< Should always be first.
	CONFIG_LOW_SPEC      = 1,
	CONFIG_MEDIUM_SPEC   = 2,
	CONFIG_HIGH_SPEC     = 3,
	CONFIG_VERYHIGH_SPEC = 4,

	CONFIG_DURANGO       = 5,
	CONFIG_ORBIS         = 6,

	//! Specialized detail config setting.
	CONFIG_DETAIL_SPEC = 7,

	END_CONFIG_SPEC_ENUM, //!< Must be the last value, used for error checking.
};

enum ESubsystem
{
	ESubsys_3DEngine = 0,
	ESubsys_AI       = 1,
	ESubsys_Physics  = 2,
	ESubsys_Renderer = 3,
	ESubsys_Script   = 4
};

//! Collates cycles taken per update.
struct sUpdateTimes
{
	uint32 PhysYields;
	uint64 SysUpdateTime;
	uint64 PhysStepTime;
	uint64 RenderTime;
	uint64 physWaitTime;  //!< Extended yimes info.
	uint64 streamingWaitTime;
	uint64 animationWaitTime;
};

enum ESystemGlobalState
{
	ESYSTEM_GLOBAL_STATE_UNKNOWN,
	ESYSTEM_GLOBAL_STATE_INIT,
	ESYSTEM_GLOBAL_STATE_RUNNING,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_PREPARE,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_MATERIALS,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_OBJECTS,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_CHARACTERS,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_STATIC_WORLD,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_ENTITIES,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_PRECACHE,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_START_TEXTURES,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_END,
	ESYSTEM_GLOBAL_STATE_LEVEL_LOAD_COMPLETE
};

//! System wide events.
enum ESystemEvent
{
	//! Seeds all random number generators to the same seed number, WParam will hold seed value.
	//! ##@{
	ESYSTEM_EVENT_RANDOM_SEED = 1,
	ESYSTEM_EVENT_RANDOM_ENABLE,
	ESYSTEM_EVENT_RANDOM_DISABLE,
	//! ##@}.

	//! Changes to main window focus.
	//! wparam is not 0 is focused, 0 if not focused.
	ESYSTEM_EVENT_CHANGE_FOCUS = 10,

	//! Moves of the main window.
	//! wparam=x, lparam=y.
	ESYSTEM_EVENT_MOVE = 11,

	//! Resizes of the main window.
	//! wparam=width, lparam=height.
	ESYSTEM_EVENT_RESIZE = 12,

	//! Activation of the main window.
	//! wparam=1/0, 1=active 0=inactive.
	ESYSTEM_EVENT_ACTIVATE = 13,

	//! Main window position changed.
	ESYSTEM_EVENT_POS_CHANGED = 14,

	//! Main window style changed.
	ESYSTEM_EVENT_STYLE_CHANGED = 15,

	//! Sent before the loading movie is begun.
	ESYSTEM_EVENT_LEVEL_LOAD_START_PRELOADINGSCREEN,

	//! Sent before the loading last save.
	ESYSTEM_EVENT_LEVEL_LOAD_RESUME_GAME,

	//! Sent before starting level, before game rules initialization and before ESYSTEM_EVENT_LEVEL_LOAD_START event.
	//! Used mostly for level loading profiling
	ESYSTEM_EVENT_LEVEL_LOAD_PREPARE,

	//! Sent to start the active loading screen rendering.
	ESYSTEM_EVENT_LEVEL_LOAD_START_LOADINGSCREEN,

	//! Sent when loading screen is active.
	ESYSTEM_EVENT_LEVEL_LOAD_LOADINGSCREEN_ACTIVE,

	//! Sent before starting loading a new level.
	//! Used for a more efficient resource management.
	ESYSTEM_EVENT_LEVEL_LOAD_START,

	//! Sent after loading a level finished.
	//! Used for a more efficient resource management.
	ESYSTEM_EVENT_LEVEL_LOAD_END,

	//! Sent after trying to load a level failed.
	//! Used for resetting the front end.
	ESYSTEM_EVENT_LEVEL_LOAD_ERROR,

	//! Sent in case the level was requested to load, but it's not ready.
	//! Used in streaming install scenario for notifying the front end.
	ESYSTEM_EVENT_LEVEL_NOT_READY,

	//! Sent after precaching of the streaming system has been done.
	ESYSTEM_EVENT_LEVEL_PRECACHE_START,

	ESYSTEM_EVENT_LEVEL_PRECACHE_CAMERA_READY,

	//! Sent before object/texture precache stream requests are submitted.
	ESYSTEM_EVENT_LEVEL_PRECACHE_FIRST_FRAME,

	//! Sent when level loading is completely finished with no more onscreen movie or info rendering, and when actual gameplay can start.
	ESYSTEM_EVENT_LEVEL_GAMEPLAY_START,

	//! Level is unloading.
	ESYSTEM_EVENT_LEVEL_UNLOAD,

	//! Sent after level have been unloaded. For cleanup code.
	ESYSTEM_EVENT_LEVEL_POST_UNLOAD,

	ESYSTEM_EVENT_GAME_MATERIALS_UNLOADED,
	ESYSTEM_EVENT_GAME_CONTEXT_END_START,
	ESYSTEM_EVENT_GAME_CONTEXT_END_DONE,
	ESYSTEM_EVENT_TRANSITION_GAME_STATE_LOADED,

	//! Called when the game framework has been initialized.
	ESYSTEM_EVENT_GAME_POST_INIT,

	//! Called when the game framework has been initialized, not loading should happen in this event.
	ESYSTEM_EVENT_GAME_POST_INIT_DONE,

	//! Sent when the system is doing a full shutdown.
	ESYSTEM_EVENT_FULL_SHUTDOWN,

	//! Sent when the system is doing a fast shutdown.
	ESYSTEM_EVENT_FAST_SHUTDOWN,

	//! When keyboard layout changed.
	ESYSTEM_EVENT_LANGUAGE_CHANGE,

	//! Toggle fullscreen.
	//! wparam is 1 means we switched to fullscreen, 0 if for windowed.
	ESYSTEM_EVENT_TOGGLE_FULLSCREEN,
	ESYSTEM_EVENT_SHARE_SHADER_COMBINATIONS,

	//! Start 3D post rendering.
	ESYSTEM_EVENT_3D_POST_RENDERING_START,

	//! End 3D post rendering.
	ESYSTEM_EVENT_3D_POST_RENDERING_END,

	ESYSTEM_EVENT_SWITCHING_TO_LEVEL_HEAP = 0x2C,
	ESYSTEM_EVENT_SWITCHED_TO_LEVEL_HEAP = 0x2D,
	ESYSTEM_EVENT_SWITCHING_TO_GLOBAL_HEAP = 0x2E,
	ESYSTEM_EVENT_SWITCHED_TO_GLOBAL_HEAP = 0x2F,

	//! Sent after precaching of the streaming system has been done.
	ESYSTEM_EVENT_LEVEL_PRECACHE_END,

	//! Sent when game mode switch begins.
	ESYSTEM_EVENT_GAME_MODE_SWITCH_START,

	//! Sent when game mode switch ends.
	ESYSTEM_EVENT_GAME_MODE_SWITCH_END,

	//! Video notifications.
	//! wparam=[0/1/2/3] : [stop/play/pause/resume].
	ESYSTEM_EVENT_VIDEO,

	//! Sent if the game is paused.
	ESYSTEM_EVENT_GAME_PAUSED,

	//! Sent if the game is resumed.
	ESYSTEM_EVENT_GAME_RESUMED,

	//! Sent when time of day is set.
	ESYSTEM_EVENT_TIME_OF_DAY_SET,

	//! Sent once the Editor finished initialization.
	ESYSTEM_EVENT_EDITOR_ON_INIT,

	//! Sent when frontend is initialised.
	ESYSTEM_EVENT_FRONTEND_INITIALISED,

	//! Sent once the Editor switches between in-game and editing mode.
	ESYSTEM_EVENT_EDITOR_GAME_MODE_CHANGED,

	//! Sent once the Editor switches simulation mode (AI/Physics).
	ESYSTEM_EVENT_EDITOR_SIMULATION_MODE_CHANGED,

	//! Sent when environment settings are reloaded
	//ESYSTEM_EVENT_ENVIRONMENT_SETTINGS_CHANGED,

	//! Sent when frontend is reloaded.
	ESYSTEM_EVENT_FRONTEND_RELOADED,

	//! Sent before triggering a force loading of specified segments.
	//ESYSTEM_EVENT_SW_FORCE_LOAD_START,

	//! Sent after triggering a force loading of specified segments.
	//ESYSTEM_EVENT_SW_FORCE_LOAD_END,

	//! Sent once segmented world manager shifts the world.
	//ESYSTEM_EVENT_SW_SHIFT_WORLD,

	// Description: PLM (Process Life Management) events.
	ESYSTEM_EVENT_PLM_ON_RESUMING,
	ESYSTEM_EVENT_PLM_ON_SUSPENDING,
	ESYSTEM_EVENT_PLM_ON_CONSTRAINED,
	ESYSTEM_EVENT_PLM_ON_FULL,  //!< Back from constrained to full resources.
	ESYSTEM_EVENT_PLM_ON_TERMINATED,

	ESYSTEM_EVENT_PLM_ON_SUSPENDING_COMPLETED, //!< Safe to call Deferral's Complete.

#if CRY_PLATFORM_DURANGO
	//! Durango only so far. They are triggered by voice/gesture standard commands.
	ESYSTEM_EVENT_GLOBAL_SYSCMD_PAUSE,
	ESYSTEM_EVENT_GLOBAL_SYSCMD_SHOW_MENU,
	ESYSTEM_EVENT_GLOBAL_SYSCMD_PLAY,
	ESYSTEM_EVENT_GLOBAL_SYSCMD_BACK,
	ESYSTEM_EVENT_GLOBAL_SYSCMD_CHANGE_VIEW,

	ESYSTEM_EVENT_ACTIVATION_EVENT, //!< Sent from external programs or the system.

	//! ESYSTEM_EVENT_DURANGO_CHANGE_VISIBILITY is called when the app totally disappears or reappears.
	//! ESYSTEM_EVENT_CHANGE_FOCUS is called in that situation, but also when the app is constantly visible and only the focus changes.
	//! wparam = 0 -> visibility lost,  wparam = 1 -> visibility recovered.
	ESYSTEM_EVENT_DURANGO_CHANGE_VISIBILITY,

	//! Matchmaking system events.
	//! wParam on state change is match search state.
	//! lParam unused.
	ESYSTEM_EVENT_MATCHMAKING_SEARCH_STATE_CHANGE,

	//! WParam and lParam unused.
	ESYSTEM_EVENT_MATCHMAKING_GAME_SESSION_READY,

	//! Triggers when current user has been changed or started being signed out.
	ESYSTEM_EVENT_USER_SIGNOUT_STARTED,
	ESYSTEM_EVENT_USER_SIGNOUT_COMPLETED,

	//! Triggers when the user has completed the sign in process.
	ESYSTEM_EVENT_USER_SIGNIN_COMPLETED,

	ESYSTEM_EVENT_USER_ADDED,
	ESYSTEM_EVENT_USER_REMOVED,
	ESYSTEM_EVENT_USER_CHANGED,

	//! Durango only so far. Triggers when the controller pairing changes, e.g. change user in account picker or handing over the controller to another user.
	ESYSTEM_EVENT_CONTROLLER_PAIRING_CHANGED,
#endif
	ESYSTEM_EVENT_CONTROLLER_REMOVED,
	ESYSTEM_EVENT_CONTROLLER_ADDED,

	//! Currently durango only.
	//! Triggers when streaming install had failed to open newly recevied pak files
	//! + may be triggerd on platform error as well: like scratched disks or network problems
	//! when installing from store
	ESYSTEM_EVENT_STREAMING_INSTALL_ERROR,

	//! Sent when the online services are initialized.
	ESYSTEM_EVENT_ONLINE_SERVICES_INITIALISED,

	//! Sent when a new audio implementation is loaded.
	ESYSTEM_EVENT_AUDIO_IMPLEMENTATION_LOADED,

	//! Purpose of this event is to enable different modules to communicate with each other without knowing about each other.
	//ESYSTEM_EVENT_URI,

	ESYSTEM_EVENT_USER = 0x1000,

	//ESYSTEM_EVENT_BEAM_PLAYER_TO_CAMERA_POS,

	//! Sent if the CrySystem module initialized successfully.
	ESYSTEM_EVENT_CRYSYSTEM_INIT_DONE,

	//! Sent if the window containing the running game loses focus, but application itself still has focus
	//! This is needed because some sub-systems still want to work even without focus on main application
	//! while others would prefer to suspend their operation
	//ESYSTEM_EVENT_GAMEWINDOW_ACTIVATE,

	ESYSTEM_EVENT_ENTITY_UNLOAD,
	ESYSTEM_EVENT_LOAD_SAVE_STARTED,
	ESYSTEM_EVENT_QUICKLOAD_SAVE_FINISHED,
};

//! User defined callback, which can be passed to ISystem.
struct ISystemUserCallback
{
	// <interfuscator:shuffle>
	virtual ~ISystemUserCallback(){}

	//! This method is called at the earliest point the ISystem pointer can be used the log might not be yet there.
	virtual void OnSystemConnect(ISystem* pSystem) {}

	//! Signals to User that engine error occurred.
	//! \return true to Halt execution or false to ignore this error.
	virtual bool OnError(const char* szErrorString) = 0;

	//! If working in Editor environment notify user that engine want to Save current document.
	//! This happens if critical error have occurred and engine gives a user way to save data and not lose it due to crash.
#if CRY_PLATFORM_WINDOWS
	virtual bool OnSaveDocument() = 0;
#endif

	//! Notifies user that system wants to switch out of current process.
	//! Example: Called when pressing ESC in game mode to go to Menu.
	virtual void OnProcessSwitch() = 0;

	//! Notifies user, usually editor, about initialization progress in system.
	virtual void OnInitProgress(const char* sProgressMsg) = 0;

	//! Initialization callback.
	//! This is called early in CSystem::Init(), before any of the other callback methods is called.
	virtual void OnInit(ISystem*) {}

	//! Shutdown callback.
	virtual void OnShutdown() {}

	//! Quit callback.
	virtual void OnQuit() {}

	//! Notify user of an update iteration. Called in the update loop.
	virtual void OnUpdate() {}

	//! Show message by provider.
	virtual int ShowMessage(const char* text, const char* caption, unsigned int uType) { return CryMessageBox(text, caption, uType); }

	//! Collects the memory information in the user program/application.
	virtual void GetMemoryUsage(ICrySizer* pSizer) = 0;
	// </interfuscator:shuffle>
};

//! Interface used for getting notified when a system event occurs.
struct ISystemEventListener
{
	// <interfuscator:shuffle>
	virtual ~ISystemEventListener(){}
	virtual void OnSystemEventAnyThread(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) {}
	virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) = 0;
	// </interfuscator:shuffle>
};

//! Structure used for getting notified when a system event occurs.
struct ISystemEventDispatcher
{
	// <interfuscator:shuffle>
	virtual ~ISystemEventDispatcher(){}
	virtual bool RegisterListener(ISystemEventListener* pListener) = 0;
	virtual bool RemoveListener(ISystemEventListener* pListener) = 0;

	virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) = 0;
	virtual void Update() = 0;

	//virtual void OnLocaleChange() = 0;
	// </interfuscator:shuffle>
};

struct IErrorObserver
{
	// <interfuscator:shuffle>
	virtual ~IErrorObserver() {}
	virtual void OnAssert(const char* condition, const char* message, const char* fileName, unsigned int fileLineNumber) = 0;
	virtual void OnScriptWarning(const char* message) = 0;
	virtual void OnFatalError(const char* message) = 0;
	// </interfuscator:shuffle>
};

enum ESystemProtectedFunctions
{
	eProtectedFunc_Save = 0,
	eProtectedFunc_Load = 1,
	eProtectedFuncsLast = 10,
};

struct SCvarsDefault
{
	SCvarsDefault()
	{
		sz_r_DriverDef = NULL;
	}

	const char* sz_r_DriverDef;
};

#if defined(CVARS_WHITELIST)
struct ICVarsWhitelist
{
	// <interfuscator:shuffle>
	virtual ~ICVarsWhitelist() {};
	virtual bool IsWhiteListed(const string& command, bool silent) = 0;
	// </interfuscator:shuffle>
};
#endif // defined(CVARS_WHITELIST)

#if CRY_PLATFORM_DURANGO
struct SControllerPairingChanged
{
	struct SUserIdInfo
	{
		uint32 currentUserId;
		uint32 previousUserId;
	};

	SControllerPairingChanged(uint64 _raw) : raw(_raw) {}
	SControllerPairingChanged(uint32 currentUserId_ = 0, uint32 previousUserId_ = 0)
	{
		userInfo.currentUserId = currentUserId_;
		userInfo.previousUserId = previousUserId_;
	}

	union
	{
		SUserIdInfo userInfo;
		uint64      raw;
	};
};
#endif

//! Structure passed to Init method of ISystem interface.
struct SSystemInitParams
{
	void*                hInstance;
	void*                hWnd;
	ILog*                pLog;           //!< You can specify your own ILog to be used by System.
	ILogCallback*        pLogCallback;   //!< You can specify your own ILogCallback to be added on log creation (used by Editor).
	ISystemUserCallback* pUserCallback;
#if defined(CVARS_WHITELIST)
	ICVarsWhitelist*     pCVarsWhitelist;       //!< CVars whitelist callback.
#endif                                        // defined(CVARS_WHITELIST)
	const char*          sLogFileName;          //!< File name to use for log.
	IValidator*          pValidator;            //!< You can specify different validator object to use by System.
	IOutputPrintSink*    pPrintSync;            //!< Print Sync which can be used to catch all output from engine.
	char                 szSystemCmdLine[2048]; //!< Command line.
	char                 szUserPath[256];       //!< User alias path relative to My Documents folder.
	char                 szBinariesDir[256];
	//char                 szProjectDllDir[256];
	char                 szLanguageName[64];

	bool                 bEditor;             //!< When running in Editor mode.
	bool                 bPreview;            //!< When running in Preview mode (Minimal initialization).
	bool                 bTestMode;           //!< When running in Automated testing mode.
	//bool                 bDedicatedServer;    //!< When running a dedicated server.
	bool                 bExecuteCommandLine; //!< can be switched of to suppress the feature or do it later during the initialization.
	bool                 bUIFramework;
	bool                 bSkipFont;            //!< Don't load CryFont.dll.
	bool                 bSkipRenderer;        //!< Don't load Renderer.
	bool                 bSkipConsole;         //!< Don't create console.
	bool                 bSkipNetwork;         //!< Don't create Network.
	//bool                 bSkipLiveCreate;      //!< Don't create LiveCreate.
	bool                 bSkipWebsocketServer; //!< Don't create the WebSocket server.
	bool                 bMinimal;             //!< Don't load banks.
	bool                 bSkipInput;           //!< do not load CryInput.
	bool                 bTesting;             //!< CryUnit.
	bool                 bNoRandom;            //!< use fixed generator init/seed.
	bool                 bShaderCacheGen;      //!< When running in shadercache gen mode.
	bool                 bUnattendedMode;      //!< When running as part of a build on build-machines: Prevent popping up of any dialog.
	bool                 bEditorViewOnlyMode;
	IArkDlcSystem*       pArkDlcSystem;

#//if CRY_PLATFORM_DURANGO
	const EPLM_Event* pLastPLMEvent;
//#endif

	ISystem*      pSystem;                //!< Pointer to existing ISystem interface, it will be reused if not NULL.
	IGameStartup* pGameStartup;           //!< Pointer to the calling GameStartup instance, to allow use of some game specific data during engine init.
	//! Char szLocalIP[256];              //! local IP address (needed if we have several servers on one machine).
#if CRY_PLATFORM_LINUX || CRY_PLATFORM_ANDROID || CRY_PLATFORM_APPLE
	void (* pCheckFunc)(void*);            //!< Authentication function (must be set).
#else
	void* pCheckFunc;                     //!< Authentication function (must be set).
#endif

	typedef void* (* ProtectedFunction)(void* param1, void* param2);
	ProtectedFunction pProtectedFunctions[eProtectedFuncsLast];  //!< Protected functions.

	SCvarsDefault*    pCvarsDefault;      //!< To override the default value of some cvar.

	//! Initialization defaults.
	SSystemInitParams()
	{
		hInstance = NULL;
		hWnd = NULL;
		pLog = NULL;
		pLogCallback = NULL;
		pUserCallback = NULL;
#if defined(CVARS_WHITELIST)
		pCVarsWhitelist = NULL;
#endif // defined(CVARS_WHITELIST)
		sLogFileName = NULL;
		pValidator = NULL;
		pPrintSync = NULL;
		memset(szSystemCmdLine, 0, sizeof(szSystemCmdLine));
		memset(szUserPath, 0, sizeof(szUserPath));
		memset(szBinariesDir, 0, sizeof(szBinariesDir));
		//memset(szProjectDllDir, 0, sizeof(szProjectDllDir));
		memset(szLanguageName, 0, sizeof(szLanguageName));
		bEditor = false;
		bPreview = false;
		bTestMode = false;
		//bDedicatedServer = false;
		bExecuteCommandLine = true;
		bUIFramework = false;
		bSkipFont = false;
		bSkipRenderer = false;
		bSkipConsole = false;
		bSkipNetwork = false;
#if CRY_PLATFORM_WINDOWS
		// create websocket server by default. bear in mind that USE_HTTP_WEBSOCKETS is not defined in release.
		bSkipWebsocketServer = false;
#else
		// CTCPStreamSocket does not support XBOX ONE and PS4 at all, and some of its functionality only seems to support Win32 and 64
		bSkipWebsocketServer = true;
#endif
		bMinimal = false;
		bSkipInput = false;
		//bSkipLiveCreate = false;
		bTesting = false;
		bNoRandom = false;
		bShaderCacheGen = false;
		bUnattendedMode = false;
		bEditorViewOnlyMode = 0;

		pSystem = NULL;
		pGameStartup = NULL;
		pCheckFunc = NULL;
		pArkDlcSystem = nullptr;

//#if CRY_PLATFORM_DURANGO
		pLastPLMEvent = NULL;
//#endif

		memset(pProtectedFunctions, 0, sizeof(pProtectedFunctions));
		pCvarsDefault = NULL;
	}
};

//! Typedef for frame profile callback function.
typedef void (* FrameProfilerSectionCallback)(class CFrameProfilerSection* pSection);

//! \note Can be used for LoadConfiguration().
struct ILoadConfigurationEntrySink
{
	// <interfuscator:shuffle>
	virtual ~ILoadConfigurationEntrySink(){}
	virtual void OnLoadConfigurationEntry(const char* szKey, const char* szValue, const char* szGroup) = 0;
	virtual void OnLoadConfigurationEntry_End() {}
	// </interfuscator:shuffle>
};

enum ELoadConfigurationType
{
	eLoadConfigDefault,
	eLoadConfigInit,
	eLoadConfigSystemSpec,
	eLoadConfigGame,
	eLoadConfigLevel
};

struct SPlatformInfo
{
	unsigned int numCoresAvailableToProcess;
	unsigned int numLogicalProcessors;

#if CRY_PLATFORM_WINDOWS
	enum EWinVersion
	{
		WinUndetected,
		Win2000,
		WinXP,
		WinSrv2003,
		WinVista,
		Win7,
		Win8,
		Win8Point1,
		Win10
	};

	EWinVersion winVer;
	bool        win64Bit;
	bool        vistaKB940105Required;
#endif
};

//! Holds info about system update stats over perior of time (cvar-tweakable)
struct SSystemUpdateStats
{
	SSystemUpdateStats() : avgUpdateTime(0.0f), minUpdateTime(0.0f), maxUpdateTime(0.0f){}
	float avgUpdateTime;
	float minUpdateTime;
	float maxUpdateTime;
};

//! Union to handle communication between the AsycDIP jobs and the general job system.
//! To allow usage of CAS all informations are encoded in 32 bit.
union UAsyncDipState
{
	struct
	{
		uint32 nQueueGuard  : 1;
		uint32 nWorker_Idle : 4;
		uint32 nNumJobs     : 27;
	};
	uint32 nValue;
};

//!	Global environment. Contains pointers to all global often needed interfaces.
//!	This is a faster way to get interface pointer then calling ISystem interface to retrieve one.
//! \note Some pointers can be NULL, use with care.
//! \see ISystem
struct SSystemGlobalEnvironment
{
	IDialogSystem*               pDialogSystem;
	I3DEngine*                   p3DEngine;
	INetwork*                    pNetwork;
	IOnline*                     pOnline;
	ICryLobby*                   pLobby;
	IArkRewardSystem*            pArkRewardSystem;
	IArkEntitlementSystem*       pArkEntitlementSystem;
	IArkDlcSystem*               pArkDlcSystem;
	IScriptSystem*               pScriptSystem;
	IPhysicalWorld*              pPhysicalWorld;
	IFlowSystem*                 pFlowSystem;
	IInput*                      pInput;
	IStatoscope*                 pStatoscope;
	ICryPak*                     pCryPak;
	IFileChangeMonitor*          pFileChangeMonitor;
	IProfileLogSystem*           pProfileLogSystem;
	IParticleManager*            pParticleManager;
	IOpticsManager*              pOpticsManager;
	IFrameProfileSystem*         pFrameProfileSystem;
	ITimer*                      pTimer;
	ICryFont*                    pCryFont;
	IGame*                       pGame;
	ILocalMemoryUsage*           pLocalMemoryUsage;
	IEntitySystem*               pEntitySystem;
	IConsole*                    pConsole;
	Telemetry::ITelemetrySystem* pTelemetrySystem;
	IAudioSystem*                pAudioSystem;
	IArkRoomVolumeManager*       pArkRoomVolumeManager;
	ISystem*                     pSystem;
	ICharacterManager*           pCharacterManager;
	IAISystem*                   pAISystem;
	ILog*                        pLog;
	ICodeCheckpointMgr*          pCodeCheckpointMgr;
	IMovieSystem*                pMovieSystem;
	INameTable*                  pNameTable;
	IVisualLog*                  pVisualLog;
	IRenderer*                   pRenderer;
	IRenderAuxGeom*              pAuxGeomRenderer;
	IHardwareMouse*              pHardwareMouse;
	IMaterialEffects*            pMaterialEffects;
	JobManager::IJobManager*     pJobManager;
	IOverloadSceneManager*       pOverloadSceneManager;
	IFlashUI*                    pFlashUI;
	//UIFramework::IUIFramework*   pUIFramework;
	IServiceNetwork*             pServiceNetwork;
	IRemoteCommandManager*       pRemoteCommandManager;
	//DRS::IDynamicResponseSystem* pDynamicResponseSystem;
	//IThreadManager*              pThreadManager;
	//IScaleformHelper*            pScaleformHelper; // nullptr when Scaleform support is not enabled

//#if CRY_PLATFORM_DURANGO
//	void*      pWindow;
	EPLM_State ePLM_State;
//#endif

#if defined(MAP_LOADING_SLICING)
	ISystemScheduler*     pSystemScheduler;
#endif
	//LiveCreate::IManager* pLiveCreateManager;
	//LiveCreate::IHost*    pLiveCreateHost;

	//IMonoRuntime*         pMonoRuntime;

	threadID              mMainThreadId;      //!< The main thread ID is used in multiple systems so should be stored globally.

	uint32                nMainFrameID;

	const char*           szCmdLine;       //!< Startup command line.

	//! Generic debug string which can be easily updated by any system and output by the debug handler
	enum { MAX_DEBUG_STRING_LENGTH = 128 };
	char szDebugStatus[MAX_DEBUG_STRING_LENGTH];

	//! Used to tell if this is a server/multiplayer instance
	bool bServer;
	bool bMultiplayer;
	bool bHostMigrating;

#if defined(CRY_PLATFORM_ORBIS) && (!defined(_RELEASE) || defined(PERFORMANCE_BUILD))
	//! Specifies if we are on a PS4 development kit
	bool bPS4DevKit;
#endif

	//////////////////////////////////////////////////////////////////////////
	// Used by frame profiler.
	//int                          bDeepProfiling;
	//bool                         bBootProfilerEnabledFrames;
	bool                         bProfilerEnabled;
	FrameProfilerSectionCallback callbackStartSection;
	FrameProfilerSectionCallback callbackEndSection;
	struct tm_api*               pTelemetryAPI;
	unsigned int                 nTelemetryCaptureMask;
	bool                         bArkProfSystems[30];
	//////////////////////////////////////////////////////////////////////////

	// Indicate Editor status.

	//////////////////////////////////////////////////////////////////////////
	// Used by CRY_ASSERT
	bool bIgnoreAllAsserts;
	bool bNoAssertDialog;
	bool bTesting;
	//////////////////////////////////////////////////////////////////////////

	bool          bNoRandomSeed;

	SPlatformInfo pi;

	// Protected functions.
	SSystemInitParams::ProtectedFunction pProtectedFunctions[eProtectedFuncsLast];

	//////////////////////////////////////////////////////////////////////////
	//! Flag to able to print out of memory conditon
	bool             bIsOutOfMemory;
	bool             bIsOutOfVideoMemory;

	ILINE const bool IsClient() const
	{
#if CRY_PLATFORM_DESKTOP
		return bClient;
#else
		return true;
#endif
	}

#if CRY_PLATFORM_DESKTOP

	ILINE void SetIsClient(bool isClient)
	{
		bClient = isClient;
	}
#endif

	ILINE const bool IsFMVPlaying() const
	{
		return m_isFMVPlaying;
	}

	ILINE void SetFMVIsPlaying(const bool isPlaying)
	{
		m_isFMVPlaying = isPlaying;
	}

	ILINE const bool IsCutscenePlaying() const
	{
		return m_isCutscenePlaying;
	}

	ILINE void SetCutsceneIsPlaying(const bool isPlaying)
	{
		m_isCutscenePlaying = isPlaying;
	}

#if defined(SYS_ENV_AS_STRUCT)
	//! Remove pointer indirection.
	ILINE SSystemGlobalEnvironment* operator->()
	{
		return this;
	}

	ILINE SSystemGlobalEnvironment& operator*()
	{
		return *this;
	}

	ILINE const bool operator!() const
	{
		return false;
	}

	ILINE operator bool() const
	{
		return true;
	}
#endif

	//! Getter function for jobmanager.
	ILINE JobManager::IJobManager* GetJobManager()
	{
		return pJobManager;
	}

#if CRY_PLATFORM_DESKTOP
	// bool bDedicatedArbitrator;

private:
	bool bClient;
	//bool bEditor;          //!< Engine is running under editor.
	//bool bEditorGameMode;  //!< Engine is in editor game mode.
	//bool bDedicated;       //!< Engine is in dedicated.
#endif

	bool m_isFMVPlaying;
	bool m_isCutscenePlaying;

public:
	SSystemGlobalEnvironment() : szCmdLine("")
	{
		mAsyncDipState.nValue = 0;
	};

	CRY_ALIGN(32) UAsyncDipState mAsyncDipState;
};

// The ISystem interface that follows has a member function called 'GetUserName'. If we don't #undef'ine the same-named Win32 symbol here ISystem wouldn't even compile.
// There might be a better place for this.
#ifdef GetUserName
	#undef GetUserName
#endif

struct IProfilingSystem
{
	// <interfuscator:shuffle>
	virtual ~IProfilingSystem(){}
	//////////////////////////////////////////////////////////////////////////
	// VTune Profiling interface.

	//! Resumes vtune data collection.
	virtual void VTuneResume() = 0;

	//! Pauses vtune data collection.
	virtual void VTunePause() = 0;
	//////////////////////////////////////////////////////////////////////////
	// </interfuscator:shuffle>
};

//! Main Engine Interface.
//! Initialize and dispatch all engine's subsystems.
struct ISystem
{
	struct ILoadingProgressListener
	{
		// <interfuscator:shuffle>
		virtual ~ILoadingProgressListener(){}
		virtual void OnLoadingProgress(int steps) = 0;
		// </interfuscator:shuffle>
	};

#if 0 //#ifndef _RELEASE
	enum LevelLoadOrigin
	{
		eLLO_Unknown,
		eLLO_NewLevel,
		eLLO_Level2Level,
		eLLO_Resumed,
		eLLO_MapCmd,
	};

	struct ICheckpointData
	{
		int             m_totalLoads;
		LevelLoadOrigin m_loadOrigin;
	};
#endif

	// <interfuscator:shuffle>
	virtual ~ISystem(){}

	//! Releases ISystem.
	virtual void Release() = 0;

	//! Will return NULL if no whitelisting.
	virtual ILoadConfigurationEntrySink* GetCVarsWhiteListConfigSink() const = 0;

	//! Returns pointer to the global environment structure.
	virtual SSystemGlobalEnvironment* GetGlobalEnvironment() = 0;

	//! Returns the root folder specified by the command line option "-root <path>".
	virtual const char* GetRootFolder() const = 0;

	//! Updates all subsystems (including the ScriptSink() ).
	//! \param flags One or more flags from ESystemUpdateFlags structure.
	//! \param nPauseMode 0=normal(no pause), 1=menu/pause, 2=cutscene.
	virtual bool Update(int updateFlags = 0, int nPauseMode = 0) = 0;

	//! Updates only require components during loading.
	virtual bool UpdateLoadtime() = 0;

	//! Optimisation: do part of the update while waiting for occlusion queries to complete.
	virtual void DoWorkDuringOcclusionChecks() = 0;
	virtual bool NeedDoWorkDuringOcclusionChecks() = 0;

	//! Renders subsystems.
	virtual void Render() = 0;

	//! Begins rendering frame.
	virtual void RenderBegin() = 0;

	//! Ends rendering frame and swap back buffer.
	virtual void RenderEnd(bool bRenderStats = true) = 0;

	//! Update screen and call some important tick functions during loading.
	virtual void SynchronousLoadingTick(const char* pFunc, int line) = 0;

	//! Renders the statistics.
	//! This is called from RenderEnd, but if the Host application (Editor) doesn't employ the Render cycle in ISystem,
	//! it may call this method to render the essential statistics.
	virtual void RenderStatistics() = 0;
	virtual void RenderPhysicsStatistics(IPhysicalWorld* pWorld) = 0;

	virtual const std::vector<SArkFrameProfileInfo>* GetProfileData() = 0;
	virtual void ClearProfileData() = 0;

	//! Returns the current used memory.
	virtual uint32 GetUsedMemory() = 0;

	//! Retrieve the name of the user currently logged in to the computer.
	virtual const char* GetUserName() = 0;

	//! Gets current supported CPU features flags. (CPUF_SSE, CPUF_SSE2, CPUF_3DNOW, CPUF_MMX)
	virtual int GetCPUFlags() = 0;

	//! Gets number of CPUs
	virtual int GetLogicalCPUCount() = 0;

	//! Dumps the memory usage statistics to the logging default MB. (can be KB)
	virtual void DumpMemoryUsageStatistics(bool bUseKB = false) = 0;

	//! Quits the application.
	virtual void Quit() = 0;

	//! Tells the system if it is relaunching or not.
	virtual void Relaunch(bool bRelaunch) = 0;

	//! Returns true if the application is in the shutdown phase.
	virtual bool IsQuitting() const = 0;

	//! Returns true if the application was initialized to generate the shader cache.
	virtual bool IsShaderCacheGenMode() const = 0;

	//! Tells the system in which way we are using the serialization system.
	virtual void SerializingFile(int mode) = 0;
	virtual int  IsSerializingFile() const = 0;

	virtual bool IsRelaunch() const = 0;

	//! Displays an error message to display info for certain time
	//! \param acMessage Message to show.
	//! \param fTime Amount of seconds to show onscreen.
	virtual void DisplayErrorMessage(const char* acMessage, float fTime, const float* pfColor = 0, bool bHardError = true) = 0;

	//! Displays error message.
	//! Logs it to console and file and error message box then terminates execution.
	virtual void FatalError(const char* sFormat, ...) PRINTF_PARAMS(2, 3) = 0;

	//! Reports a bug using the crash handler.
	//! Logs an error to the console and launches the crash handler, then continues execution.
	virtual void ReportBug(const char* sFormat, ...) PRINTF_PARAMS(2, 3) = 0;

	virtual void OpenArkBugReporter(const char*) = 0;
	virtual void SetLastSaveFile(const char*) = 0;
	virtual const char* GetLastSaveFile() = 0;

	//! Report warning to current Validator object.
	//! Doesn't terminate the execution.
	//! ##@{
	virtual void WarningV(EValidatorModule module, EValidatorSeverity severity, int flags, const char* file, const char* format, va_list args) = 0;
	virtual void Warning(EValidatorModule module, EValidatorSeverity severity, int flags, const char* file, const char* format, ...) = 0;
	//! ##@}.

	//! Report message by provider or by using CryMessageBox.
	//! Doesn't terminate the execution.
	virtual int ShowMessage(const char* text, const char* caption, unsigned int uType) = 0;

	//! Compare specified verbosity level to the one currently set.
	virtual bool CheckLogVerbosity(int verbosity) = 0;

	virtual bool IsUIFrameworkMode() { return false; }

	//! Fills the output array by random numbers using CMTRand_int32 generator
	//virtual void FillRandomMT(uint32* pOutWords, uint32 numWords) = 0;

	// Return the related subsystem interface.

	virtual IZLibCompressor*       GetIZLibCompressor() = 0;
	virtual IZLibDecompressor*     GetIZLibDecompressor() = 0;
	virtual ILZ4Decompressor*      GetLZ4Decompressor() = 0;
	virtual ICryPerfHUD*           GetPerfHUD() = 0;
	virtual IPlatformOS*           GetPlatformOS() = 0;
	virtual INotificationNetwork*  GetINotificationNetwork() = 0;
	virtual IHardwareMouse*        GetIHardwareMouse() = 0;
	virtual IDialogSystem*         GetIDialogSystem() = 0;
	virtual IFlowSystem*           GetIFlowSystem() = 0;
	virtual IBudgetingSystem*      GetIBudgetingSystem() = 0;
	virtual INameTable*            GetINameTable() = 0;
	virtual IDiskProfiler*         GetIDiskProfiler() = 0;
	virtual IFrameProfileSystem*   GetIProfileSystem() = 0;
	virtual IValidator*            GetIValidator() = 0;
	virtual IPhysicsDebugRenderer* GetIPhysicsDebugRenderer() = 0;
	virtual IPhysRenderer*         GetIPhysRenderer() = 0;
	virtual ICharacterManager*     GetIAnimationSystem() = 0;
	virtual IStreamEngine*         GetStreamEngine() = 0;
	virtual ICmdLine*              GetICmdLine() = 0;
	virtual ILog*                  GetILog() = 0;
	virtual ICryPak*               GetIPak() = 0;
	virtual ICryFont*              GetICryFont() = 0;
	virtual IEntitySystem*         GetIEntitySystem() = 0;
	virtual IMemoryManager*        GetIMemoryManager() = 0;
	virtual IAISystem*             GetAISystem() = 0;
	virtual IMovieSystem*          GetIMovieSystem() = 0;
	virtual IPhysicalWorld*        GetIPhysicalWorld() = 0;
	virtual IAudioSystem*          GetIAudioSystem() = 0;
	virtual IArkRoomVolumeManager* GetIArkRoomVolumeManager() = 0;
	virtual I3DEngine*             GetI3DEngine() = 0;
	virtual IScriptSystem*         GetIScriptSystem() = 0;
	virtual IConsole*              GetIConsole() = 0;
	virtual IRemoteConsole*        GetIRemoteConsole() = 0;
	virtual IArkBethesdaNetManager* GetIArkBethesdaNetManager() = 0;
	//virtual ICryPluginManager*     GetIPluginManager() = 0;

	//! \return Can be NULL, because it only exists when running through the editor, not in pure game mode.
	virtual IResourceManager*                  GetIResourceManager() = 0;
	virtual IThreadTaskManager*                GetIThreadTaskManager() = 0;
	virtual IProfilingSystem*                  GetIProfilingSystem() = 0;
	virtual ISystemEventDispatcher*            GetISystemEventDispatcher() = 0;
	virtual IVisualLog*                        GetIVisualLog() = 0;
	virtual IFileChangeMonitor*                GetIFileChangeMonitor() = 0;

	virtual WIN_HWND                           GetHWND() = 0;

	virtual IGame*                             GetIGame() = 0;
	virtual INetwork*                          GetINetwork() = 0;
	virtual IRenderer*                         GetIRenderer() = 0;
	virtual IInput*                            GetIInput() = 0;
	virtual ITimer*                            GetITimer() = 0;

	//virtual IThreadManager*                    GetIThreadManager() = 0;
	//virtual IMonoRuntime*                      GetIMonoRuntime() = 0;

	virtual void                               SetLoadingProgressListener(ILoadingProgressListener* pListener) = 0;
	virtual ISystem::ILoadingProgressListener* GetLoadingProgressListener() const = 0;

	//! Game is created after System init, so has to be set explicitly.
	virtual void SetIGame(IGame* pGame) = 0;
	virtual void SetIFlowSystem(IFlowSystem* pFlowSystem) = 0;
	virtual void SetIDialogSystem(IDialogSystem* pDialogSystem) = 0;
	virtual void SetIMaterialEffects(IMaterialEffects* pMaterialEffects) = 0;
	virtual void SetIParticleManager(IParticleManager* pParticleManager) = 0;
	virtual void SetIOpticsManager(IOpticsManager* pOpticsManager) = 0;
	virtual void SetIArkRoomVolumeManager(IArkRoomVolumeManager*) = 0;
	virtual void SetIFileChangeMonitor(IFileChangeMonitor* pFileChangeMonitor) = 0;
	virtual void SetIVisualLog(IVisualLog*) = 0;
	virtual void SetIFlashUI(IFlashUI* pFlashUI) = 0;
	//virtual void SetIUIFramework(UIFramework::IUIFramework* pUIFramework) = 0;

	//! Changes current user sub path, the path is always relative to the user documents folder.
	//! Example: "My Games\Crysis"
	virtual void ChangeUserPath(const char* sUserPath) = 0;

	//virtual	const char			*GetGamePath()=0;

	virtual void DebugStats(bool checkpoint, bool leaks) = 0;
	virtual void DumpWinHeaps() = 0;
	virtual int  DumpMMStats(bool log) = 0;

	//! \param bValue Set to true when running on a cheat protected server or a client that is connected to it (not used in singleplayer).
	virtual void SetForceNonDevMode(const bool bValue) = 0;

	//! \return true when running on a cheat protected server or a client that is connected to it (not used in singleplayer).
	virtual bool GetForceNonDevMode() const = 0;
	virtual bool WasInDevMode() const = 0;
	virtual bool IsDevMode() const = 0;
	virtual bool IsMODValid(const char* szMODName) const = 0;
	//////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// IXmlNode interface.
	//!	 Creates new xml node.
	virtual XmlNodeRef CreateXmlNode(const char* sNodeName = "", bool bReuseStrings = false) = 0;

	//! Loads xml from memory buffer, returns 0 if load failed.
	virtual XmlNodeRef LoadXmlFromBuffer(const char* buffer, size_t size, bool bReuseStrings = false) = 0;

	//! Loads xml file, returns 0 if load failed.
	virtual XmlNodeRef LoadXmlFromFile(const char* sFilename, bool bReuseStrings = false) = 0;

	//! Retrieves access to XML utilities interface.
	virtual IXmlUtils* GetXmlUtils() = 0;

	//! Interface to access different implementations of Serialization::IArchive in a centralized way.
	virtual Serialization::IArchiveHost* GetArchiveHost() const = 0;

	virtual void                         SetViewCamera(CCamera& Camera) = 0;
	virtual CCamera&                     GetViewCamera() = 0;

	//! When ignore update sets to true, system will ignore and updates and render calls.
	virtual void IgnoreUpdates(bool bIgnore) = 0;

	//! Sets the active process.
	//! \param process Pointer to a class that implement the IProcess interface.
	virtual void SetIProcess(IProcess* process) = 0;

	//! Gets the active process.
	//! \return Pointer to the current active process.
	virtual IProcess* GetIProcess() = 0;

	//! \return true if system running in Test mode.
	virtual bool IsTestMode() const = 0;

	//! Frame profiler functions.
	virtual void SetFrameProfiler(bool on, bool display, char* prefix) = 0;

	//////////////////////////////////////////////////////////////////////////
	// Loading time/memory profiling
	//! Starts function loading stats profiling.
	virtual struct SLoadingTimeContainer* StartLoadingSectionProfiling(CLoadingTimeProfiler* pProfiler, const char* szFuncName) = 0;

	//! Ends function loading stats profiling.
	virtual void EndLoadingSectionProfiling(CLoadingTimeProfiler* pProfiler) = 0;

	//! Starts function profiling with bootprofiler (session must be started).
	virtual CBootProfilerRecord* StartBootSectionProfiler(const char* name, const char* args) = 0;

	//! Ends function profiling with bootprofiler.
	virtual void StopBootSectionProfiler(CBootProfilerRecord* record) = 0;

	// Summary:
	//	 Starts bootprofiler session.
	virtual void StartBootProfilerSession(const char* szName) = 0;

	// Summary:
	//	 Stops bootprofiler session.
	virtual void StopBootProfilerSession(const char* szName) = 0;

	//! game dll should call this on frame start
	//virtual void OnFrameStart(const char* szName) = 0;

	//! game dll should call this on frame end
	//virtual void OnFrameEnd() = 0;

	//! Prints loading stats into log.
	virtual void OutputLoadingTimeStats() = 0;

	//! Starts function loading stats profiling.
	virtual const char* GetLoadingProfilerCallstack() = 0;

	//////////////////////////////////////////////////////////////////////////
	// File version.
	//! Gets file version.
	virtual const SFileVersion& GetFileVersion() = 0;

	//! Gets product version.
	virtual const SFileVersion& GetProductVersion() = 0;

	//! Gets build version.
	virtual const SFileVersion& GetBuildVersion() = 0;

	virtual const ArkBuildInfo* GetBuildInfo() = 0;
	virtual void AddRuntimeBuildInfo(const char*, const char*) = 0;

	virtual bool WriteCompressedFile(const char*, void*, unsigned int) = 0;
	virtual unsigned int ReadCompressedFile(const char*, void*, unsigned int) = 0;
	virtual unsigned int GetCompressedFileSizeA(const char*) = 0;

	//! Data compression.
	//! ##@{
	virtual bool CompressDataBlock(const void* input, size_t inputSize, void* output, size_t& outputSize, int level = 3) = 0;
	virtual bool DecompressDataBlock(const void* input, size_t inputSize, void* output, size_t& outputSize) = 0;
	//! ##@}.

	virtual IDataProbe* GetIDataProbe() = 0;
	virtual string GetMappedPathLocation(string &) = 0;

	//////////////////////////////////////////////////////////////////////////
	// Configuration.
	//! Saves system configuration.
	virtual void SaveConfiguration() = 0;

	//! Loads system configuration
	//! \param pCallback 0 means normal LoadConfigVar behaviour is used.
	virtual void LoadConfiguration(const char* sFilename, ILoadConfigurationEntrySink* pSink = 0, ELoadConfigurationType configType = eLoadConfigDefault) = 0;

	//! Retrieves current configuration specification for client or server.
	//! \param bClient If true returns local client config spec, if false returns server config spec.
	virtual ESystemConfigSpec GetConfigSpec(bool bClient = true) = 0;

	virtual ESystemConfigSpec GetMaxConfigSpec() const = 0;

	//! Changes current configuration specification for client or server.
	//! \param bClient If true changes client config spec (sys_spec variable changed), if false changes only server config spec (as known on the client).
	virtual void SetConfigSpec(ESystemConfigSpec spec, bool bClient) = 0;

	//! Detects and set optimal spec.
	virtual void AutoDetectSpec(const bool detectResolution) = 0;

	//! Thread management for subsystems
	//! \return Non-0 if the state was indeed changed, 0 if already in that state.
	virtual int SetThreadState(ESubsystem subsys, bool bActive) = 0;

	//! Creates and returns a usable object implementing ICrySizer interface.
	virtual ICrySizer* CreateSizer() = 0;

	//! Query if system is now paused.
	//! Pause flag is set when calling system update with pause mode.
	virtual bool IsPaused() const = 0;

	//! Retrieves localized strings manager interface.
	virtual ILocalizationManager* GetLocalizationManager() = 0;

	//! Gets the head mounted display manager.
	//virtual struct IHmdManager* GetHmdManager() = 0;

	virtual IFlashPlayer* CreateFlashPlayerInstance() = 0;
	virtual IFlashPlayerBootStrapper* CreateFlashPlayerBootStrapper() = 0;
	virtual void SetFlashLoadMovieHandler(IFlashLoadMovieHandler*) = 0;
	virtual void GetFlashProfileResults(float*, bool) = 0;
	virtual void GetFlashMemoryUsage(ICrySizer*) = 0;
	virtual void ResetFlashMeshCache() = 0;
	virtual void GFxAmpEnable(bool) = 0;
	virtual void GFxAmpAdvanceFrame() = 0;
	virtual void ResetFlashDirtyState() = 0;

	//! Creates an instance of the AVI Reader class.
	virtual IAVI_Reader* CreateAVIReader() = 0;

	//! Release the AVI reader.
	virtual void              ReleaseAVIReader(IAVI_Reader* pAVIReader) = 0;

	virtual ITextModeConsole* GetITextModeConsole() = 0;

	//! Retrieves the perlin noise singleton instance.
	virtual CPNoise3* GetNoiseGen() = 0;

	//! Retrieves system update counter.
	virtual uint64 GetUpdateCounter() = 0;

	//! Gets access to all registered factories.
	virtual ICryFactoryRegistry* GetCryFactoryRegistry() const = 0;

	//////////////////////////////////////////////////////////////////////////
	// Error callback handling
	//! Registers listeners to CryAssert and error messages (may not be called if asserts are disabled).
	//! Each pointer can be registered only once (stl::push_back_unique).
	//! It will return false if the pointer is already registered. Returns true, otherwise.
	virtual bool RegisterErrorObserver(IErrorObserver* errorObserver) = 0;

	//! Unregisters listeners to CryAssert and error messages.
	//! It will return false if the pointer is not registered. Otherwise, returns true.
	virtual bool UnregisterErrorObserver(IErrorObserver* errorObserver) = 0;

	//! Called after the processing of the assert message box(Windows or Xbox).
	//! It will be called even when asserts are disabled by the console variables.
	virtual void OnAssert(const char* condition, const char* message, const char* fileName, unsigned int fileLineNumber) = 0;

	virtual void OnScriptWarning(const char*) = 0;

	//! Returns if the assert window from CryAssert is visible.
	//! OBS1: needed by the editor, as in some cases it can freeze if during an assert engine it will handle
	//! some events such as mouse movement in a CryPhysics assert.
	//! OBS2: it will always return false, if asserts are disabled or ignored.
	virtual bool IsAssertDialogVisible() const = 0;

	//! Returns address controlled by sys_asserts CVar, if available.
	//! The value at the address shall be non-zero if asserts are enabled.
	//! The function shall return nullptr if sys_asserts CVar is not available (ie, release config).
	//virtual int* GetAssertFlagAddress() const = 0;

	//! Sets the AssertVisisble internal variable.
	//! Typically it should only be called by CryAssert.
	virtual void SetAssertVisible(bool bAssertVisble) = 0;
	//////////////////////////////////////////////////////////////////////////

	//! Get the index of the currently running Crytek application, (0 = first instance, 1 = second instance, etc).
	virtual int GetApplicationInstance() = 0;

	//! Retrieves the current stats for systems to update the respective time taken.
	virtual sUpdateTimes& GetCurrentUpdateTimeStats() = 0;

	//! Retrieves the array of update times and the number of entries.
	virtual const sUpdateTimes* GetUpdateTimeStats(uint32&, uint32&) = 0;

	//! Clear all currently logged and drawn on screen error messages.
	virtual void ClearErrorMessages() = 0;

	//! Fills array of function pointers, nCount return number of functions.
	//! \note Pass nCount to indicate maximum number of functions to get.
	//! \note For debugging use only!, queries current C++ call stack.
	//virtual void debug_GetCallStack(const char** pFunctions, int& nCount) = 0;
	virtual IDebugCallStack* GetIDebugCallstack() = 0;

	//! Logs current callstack.
	//! \note For debugging use only!, queries current C++ call stack.
	virtual void debug_LogCallStack(int nMaxFuncs = 32, int nFlags = 0) = 0;

	//! Can be called through console
	//! Example: #System.ApplicationTest("testcase0")
	//! \param szParam 0 generates error.
	//virtual void ApplicationTest(const char* szParam) = 0;

	//! \return 0 if not activated, activate through #System.ApplicationTest.
	virtual ITestSystem* GetITestSystem() = 0;

	//! Execute command line arguments. Should be after init game.
	//! Example: +g_gametype ASSAULT +map "testy"
	virtual void ExecuteCommandLine() = 0;

	//! GetSystemUpdate stats (all systems update without except console).
	//! Very useful on dedicated server as we throttle it to fixed frequency.
	//! \return zeroes if no updates happened yet.
	virtual void GetUpdateStats(SSystemUpdateStats& stats) = 0;

	//! Useful to investigate memory fragmentation.
	//! Every time you call this from the console: #System.DumpMemoryCoverage()
	//! it adds a line to "MemoryCoverage.bmp" (generated the first time, there is a max line count).
	virtual void               DumpMemoryCoverage() = 0;
	virtual ESystemGlobalState GetSystemGlobalState(void) = 0;
	virtual void               SetSystemGlobalState(const ESystemGlobalState systemGlobalState) = 0;

	//! Add a PlatformOS create flag
	virtual void AddPlatformOSCreateFlag(const uint8 createFlag) = 0;

	//! Asynchronous memcpy.
	//! Note sync variable will be incremented (in calling thread) before job starts
	//! and decremented when job finishes. Multiple async copies can therefore be
	//! tied to the same sync variable, therefore it's advised to wait for completion with while(*sync) (yield());.
	virtual void AsyncMemcpy(void* dst, const void* src, size_t size, int nFlags, volatile int* sync) = 0;
	// </interfuscator:shuffle>

	virtual ILevelEncrypter* GetLevelEncrypter() = 0;
	virtual IEvaluationManager* GetEvaluationManager() = 0;
	virtual char* GetDeveloperName(char*) = 0;

#if defined(CVARS_WHITELIST)
	virtual ICVarsWhitelist* GetCVarsWhiteList() const = 0;
#endif // defined(CVARS_WHITELIST)

#if 0 // #ifndef _RELEASE
	virtual void GetCheckpointData(ICheckpointData& data) = 0;
	virtual void IncreaseCheckpointLoadCount() = 0;
	virtual void SetLoadOrigin(LevelLoadOrigin origin) = 0;
#endif

//#if CRY_PLATFORM_DURANGO
	virtual void OnPLMEvent(EPLM_Event event) = 0;
//#endif

#if 0 // #if !defined(_RELEASE)
	virtual bool IsSavingResourceList() const = 0;
#endif

	//! Initializes Steam if needed and returns if it was successful.
	virtual bool SteamInit() = 0;

	//! Loads a dynamic library, creates and initializes an instance of the module class
	//! \note HintEaaS is used to load EaaS release configuration, it's ignored in all other configurations; pass true if the sourcecode for the module is available to EaaS users.
	virtual bool InitializeEngineModule(const char* dllName, const char* moduleClassName, bool bQuitIfNotFound) = 0;

	//! Unloads a dynamic library as well as the corresponding instance of the module class
	virtual bool UnloadEngineModule(const char* dllName, const char* moduleClassName) = 0;

	virtual void OverridePathMappings(const char* const) = 0;

	//! Gets the root window message handler function.
	//! The returned pointer is platform-specific: for Windows OS, the pointer is of type WNDPROC
	//virtual void* GetRootWindowMessageHandler() = 0;

	//! Register a IWindowMessageHandler that will be informed about window messages.
	//! The delivered messages are platform-specific.
	//virtual void RegisterWindowMessageHandler(IWindowMessageHandler* pHandler) = 0;

	//! Unregister an IWindowMessageHandler that was previously registered using RegisterWindowMessageHandler.
	//virtual void UnregisterWindowMessageHandler(IWindowMessageHandler* pHandler) = 0;

	//! Pumps window messages, informing all registered IWindowMessageHandlers
	//! If bAll is true, all available messages will be pumped
	//! If hWnd is not NULL, only messages for the given window are processed (ignored on non-windows platforms)
	//! Returns the number of messages pumped, or -1 if the OS indicated the application should quit
	//! Note: Calling GetMessage or PeekMessage yourself will skip the pre-process handling required for IME support
	//virtual int PumpWindowMessage(bool bAll, WIN_HWND hWnd = 0) = 0;

	//! Check if IME is supported on the current platform
	//! Note: This flag depends on compile-time settings, it cannot be enabled or disabled at runtime
	//! However, the support itself can typically be enabled/disabled through CVar
	//virtual bool IsImeSupported() const = 0;
};

//! This is a very important function for the dedicated server - it lets us run >1000 players per piece of server hardware.
//! It this saves us lots of money on the dedicated server hardware.
#define SYNCHRONOUS_LOADING_TICK() do { if (gEnv && gEnv->pSystem) gEnv->pSystem->SynchronousLoadingTick(__FUNC__, __LINE__); } while (0)

#if defined(ENABLE_LOADING_PROFILER)

struct DiskOperationInfo
{
	DiskOperationInfo() : m_nSeeksCount(0), m_nFileOpenCount(0), m_nFileReadCount(0), m_dOperationSize(0.), m_dOperationTime(0.) {}
	int    m_nSeeksCount;
	int    m_nFileOpenCount;
	int    m_nFileReadCount;
	double m_dOperationTime;
	double m_dOperationSize;

	DiskOperationInfo& operator-=(const DiskOperationInfo& rv)
	{
		m_nSeeksCount -= rv.m_nSeeksCount;
		m_nFileOpenCount -= rv.m_nFileOpenCount;
		m_nFileReadCount -= rv.m_nFileReadCount;
		m_dOperationSize -= rv.m_dOperationSize;
		m_dOperationTime -= rv.m_dOperationTime;
		return *this;
	}

	DiskOperationInfo& operator+=(const DiskOperationInfo& rv)
	{
		m_nSeeksCount += rv.m_nSeeksCount;
		m_nFileOpenCount += rv.m_nFileOpenCount;
		m_nFileReadCount += rv.m_nFileReadCount;
		m_dOperationSize += rv.m_dOperationSize;
		m_dOperationTime += rv.m_dOperationTime;
		return *this;
	}

	DiskOperationInfo operator-(const DiskOperationInfo& rv)
	{
		DiskOperationInfo res(*this);
		return res -= rv;
	}

	DiskOperationInfo operator+(const DiskOperationInfo& rv)
	{
		DiskOperationInfo res(*this);
		return res += rv;
	}

};

struct CLoadingTimeProfiler
{
	CLoadingTimeProfiler(ISystem* pSystem, const char* szFuncName) : m_pSystem(pSystem)
	{
		m_pSystem = pSystem;
		m_pTimeContainer = m_pSystem->StartLoadingSectionProfiling(this, szFuncName);
	}

	~CLoadingTimeProfiler()
	{
		m_pSystem->EndLoadingSectionProfiling(this);
	}

	struct SLoadingTimeContainer* m_pTimeContainer;
	double                        m_fConstructorTime;
	double                        m_fConstructorMemUsage;

	DiskOperationInfo             m_constructorInfo;

	ISystem*                      m_pSystem;
};

class CSYSBootProfileBlock
{
	ISystem*             m_pSystem;
	CBootProfilerRecord* m_pRecord;
	unsigned int         m_sessionIndex;
public:
	CSYSBootProfileBlock(ISystem* pSystem, const char* name, const char* args = NULL) : m_pSystem(pSystem), m_sessionIndex(~0U)
	{
		m_pRecord = m_pSystem ? m_pSystem->StartBootSectionProfiler(name, args, m_sessionIndex) : nullptr;
	}

	~CSYSBootProfileBlock()
	{
		if (m_pRecord)
		{
			m_pSystem->StopBootSectionProfiler(m_pRecord, m_sessionIndex);
		}
	}
};

	#define LOADING_TIME_PROFILE_SECTION CSYSBootProfileBlock _profileBlockLine(gEnv->pSystem, __FUNC__);
	#define LOADING_TIME_PROFILE_SECTION_ARGS(args)                    CSYSBootProfileBlock _profileBlockLine_args(gEnv->pSystem, __FUNC__, args);
	#define LOADING_TIME_PROFILE_SECTION_NAMED(sectionName)            CSYSBootProfileBlock _profileBlockLine_named(gEnv->pSystem, sectionName);
	#define LOADING_TIME_PROFILE_SECTION_NAMED_ARGS(sectionName, args) CSYSBootProfileBlock _profileBlockLine_named_args(gEnv->pSystem, sectionName, args);

#else

	#define LOADING_TIME_PROFILE_SECTION
	#define LOADING_TIME_PROFILE_SECTION_ARGS(args)
	#define LOADING_TIME_PROFILE_SECTION_NAMED(sectionName)
	#define LOADING_TIME_PROFILE_SECTION_NAMED_ARGS(sectionName, args)
	#define LOADING_TIME_PROFILE_SESSION_SECTION(sessionName)
	#define LOADING_TIME_PROFILE_SESSION_START(sessionName)
	#define LOADING_TIME_PROFILE_SESSION_STOP(sessionName)

#endif

// CrySystem DLL Exports.
typedef ISystem* (* PFNCREATESYSTEMINTERFACE)(SSystemInitParams& initParams);

// Global environment variable.
#if defined(SYS_ENV_AS_STRUCT)
extern SSystemGlobalEnvironment gEnv;
#else
extern SSystemGlobalEnvironment* gEnv;
#endif

//! Gets the system interface.
inline ISystem* GetISystem()
{
	return gEnv->pSystem;
};

#if defined(MAP_LOADING_SLICING)
//! Gets the system scheduler interface.
inline ISystemScheduler* GetISystemScheduler(void)
{
	return gEnv->pSystemScheduler;
};
#endif // defined(MAP_LOADING_SLICING)
//! This function must be called once by each module at the beginning, to setup global pointers.
extern "C" DLL_EXPORT void ModuleInitISystem(ISystem* pSystem, const char* moduleName);
extern int g_iTraceAllocations;

//! Interface of the DLL.
extern "C"
{
	CRYSYSTEM_API ISystem* CreateSystemInterface(const SSystemInitParams& initParams);
}

#ifdef EXCLUDE_CVARHELP
	#define CVARHELP(_comment) 0
#else
	#define CVARHELP(_comment) _comment
#endif

//! Provide macros for fixing cvars for release mode on consoles to enums to allow for code stripping.
//! Do not enable for PC, apply VF_CHEAT there if required.
#if CRY_PLATFORM_DESKTOP
	#define CONST_CVAR_FLAGS (VF_NULL)
#else
	#define CONST_CVAR_FLAGS (VF_CHEAT)
#endif

#if defined(_RELEASE) && !CRY_PLATFORM_DESKTOP
	#ifndef LOG_CONST_CVAR_ACCESS
		#error LOG_CONST_CVAR_ACCESS should be defined in ProjectDefines.h
	#endif

	#include "IConsole.h"
namespace Detail
{
template<typename T>
struct SQueryTypeEnum;
template<>
struct SQueryTypeEnum<int>
{
	static const int type = CVAR_INT;
	static int ParseString(const char* s) { return atoi(s); }
};
template<>
struct SQueryTypeEnum<float>
{
	static const int type = CVAR_FLOAT;
	static float ParseString(const char* s) { return (float)atof(s); }
};

template<typename T>
struct SDummyCVar : ICVar
{
	const T      value;
	#if LOG_CONST_CVAR_ACCESS
	mutable bool bWasRead;
	mutable bool bWasChanged;
	SDummyCVar(T value) : value(value), bWasChanged(false), bWasRead(false) {}
	#else
	SDummyCVar(T value) : value(value) {}
	#endif

	void WarnUse() const
	{
	#if LOG_CONST_CVAR_ACCESS
		if (!bWasRead)
		{
			CryWarning(VALIDATOR_MODULE_SYSTEM, VALIDATOR_WARNING, "[CVAR] Read from const CVar '%s' via name look-up, this is non-optimal", GetName());
			bWasRead = true;
		}
	#endif
	}

	void InvalidAccess() const
	{
	#if LOG_CONST_CVAR_ACCESS
		if (!bWasChanged)
		{
			CryWarning(VALIDATOR_MODULE_SYSTEM, VALIDATOR_ERROR, "[CVAR] Write to const CVar '%s' with wrong value '%f' was ignored. This indicates a bug in code or a config file", GetName(), GetFVal());
			bWasChanged = true;
		}
	#endif
	}

	void            Release()                                             {}
	int             GetIVal() const                                       { WarnUse(); return static_cast<int>(value); }
	int64           GetI64Val() const                                     { WarnUse(); return static_cast<int64>(value); }
	float           GetFVal() const                                       { WarnUse(); return static_cast<float>(value); }
	const char*     GetString() const                                     { return ""; }
	const char*     GetDataProbeString() const                            { return ""; }
	void            Set(const char* s)                                    { if (SQueryTypeEnum<T>::ParseString(s) != value) InvalidAccess(); }
	void            ForceSet(const char* s)                               { Set(s); }
	void            Set(const float f)                                    { if (static_cast<T>(f) != value) InvalidAccess(); }
	void            Set(const int i)                                      { if (static_cast<T>(i) != value) InvalidAccess(); }
	void            ClearFlags(int flags)                                 {}
	int             GetFlags() const                                      { return VF_CONST_CVAR | VF_READONLY; }
	int             SetFlags(int flags)                                   { return 0; }
	int             GetType()                                             { return SQueryTypeEnum<T>::type; }
	const char*     GetHelp()                                             { return NULL; }
	bool            IsConstCVar() const                                   { return true; }
	void            SetOnChangeCallback(ConsoleVarFunc pChangeFunc)       { (void)pChangeFunc; }
	void            AddOnChangeFunctor(const SFunctor& /*changeFunctor*/) {}
	uint64          GetNumberOfOnChangeFunctors() const                   { return 0; }
	const SFunctor& GetOnChangeFunctor(uint64 nFunctorIndex) const        { InvalidAccess(); return *(const SFunctor*)NULL; }
	bool            RemoveOnChangeFunctor(const uint64 nElement)          { return true; }
	ConsoleVarFunc  GetOnChangeCallback() const                           { InvalidAccess(); return NULL; }
	void            GetMemoryUsage(class ICrySizer* pSizer) const         {}
	int             GetRealIVal() const                                   { return GetIVal(); }
	void            SetDataProbeString(const char* pDataProbeString)      { InvalidAccess(); }
};
}

	#define REGISTER_DUMMY_CVAR(type, name, value)                                       \
	  do {                                                                               \
	    static struct DummyCVar : Detail::SDummyCVar<type>                               \
	    {                                                                                \
	      DummyCVar() : Detail::SDummyCVar<type>(value) {}                               \
	      const char* GetName() const { return name; }                                   \
	    } DummyStaticInstance;                                                           \
	    if (!(gEnv->pConsole != 0 ? gEnv->pConsole->Register(&DummyStaticInstance) : 0)) \
	    {                                                                                \
	      __debugbreak();                                                                \
	      CryFatalError("Can not register dummy CVar");                                  \
	    }                                                                                \
	  } while (0)

	#define CONSOLE_CONST_CVAR_MODE
	#define DeclareConstIntCVar(name, defaultValue)                          enum : int { name = (defaultValue) }
	#define DeclareStaticConstIntCVar(name, defaultValue)                    enum : int { name = (defaultValue) }
	#define DefineConstIntCVarName(strname, name, defaultValue, flags, help) { COMPILE_TIME_ASSERT((int)(defaultValue) == (int)(name)); REGISTER_DUMMY_CVAR(int, strname, defaultValue); }
	#define DefineConstIntCVar(name, defaultValue, flags, help)              { COMPILE_TIME_ASSERT((int)(defaultValue) == (int)(name)); REGISTER_DUMMY_CVAR(int, ( # name), defaultValue); }

//! DefineConstIntCVar2 is deprecated, any such instance can be converted to the 3 variant by removing the quotes around the first parameter.
	#define DefineConstIntCVar3(name, _var_, defaultValue, flags, help) { COMPILE_TIME_ASSERT((int)(defaultValue) == (int)(_var_)); REGISTER_DUMMY_CVAR(int, name, defaultValue); }
	#define AllocateConstIntCVar(scope, name)

	#define DefineConstFloatCVar(name, flags, help) { REGISTER_DUMMY_CVAR(float, ( # name), name ## Default); }
	#define DeclareConstFloatCVar(name)
	#define DeclareStaticConstFloatCVar(name)
	#define AllocateConstFloatCVar(scope, name)

#else

	#define DeclareConstIntCVar(name, defaultValue)       int name
	#define DeclareStaticConstIntCVar(name, defaultValue) static int name
	#define DefineConstIntCVarName(strname, name, defaultValue, flags, help) \
	  (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(strname, &name, defaultValue, flags | CONST_CVAR_FLAGS, CVARHELP(help)))
	#define DefineConstIntCVar(name, defaultValue, flags, help) \
	  (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(( # name), &name, defaultValue, flags | CONST_CVAR_FLAGS, CVARHELP(help), 0, false))

//! DefineConstIntCVar2 is deprecated, any such instance can be converted to the 3 variant by removing the quotes around the first parameter.
	#define DefineConstIntCVar3(_name, _var, _def_val, _flags, help) \
	  (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(_name, &(_var), (_def_val), (_flags) | CONST_CVAR_FLAGS, CVARHELP(help), 0, false))
	#define AllocateConstIntCVar(scope, name) int scope::name

	#define DefineConstFloatCVar(name, flags, help) \
	  (gEnv->pConsole == 0 ? 0 : gEnv->pConsole->Register(( # name), &name, name ## Default, flags | CONST_CVAR_FLAGS, CVARHELP(help), 0, false))
	#define DeclareConstFloatCVar(name)         float name
	#define DeclareStaticConstFloatCVar(name)   static float name
	#define AllocateConstFloatCVar(scope, name) float scope::name
#endif

#if defined(USE_CRY_ASSERT)
static void AssertConsoleExists(void)
{
	CRY_ASSERT(gEnv->pConsole != NULL);
}
	#define ASSERT_CONSOLE_EXISTS AssertConsoleExists()
#else
	#define ASSERT_CONSOLE_EXISTS 0
#endif // defined(USE_CRY_ASSERT)

//! The following macros allow the help text to be easily stripped out.



//! Chairloader Specific Macros for Console Variables

//! Preferred way to register a CVar
#define REGISTER_CVAR(_var, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegister(( # _var), &(_var), (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register a CVar with a callback
#define REGISTER_CVAR_CB(_var, _def_val, _flags, _comment, _onchangefunction) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 :Internal::ChairRegister(( # _var), &(_var), (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register a string CVar
#define REGISTER_STRING(_name, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegisterString(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register a string CVar with a callback
#define REGISTER_STRING_CB(_name, _def_val, _flags, _comment, _onchangefunction) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegisterString(_name, (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register an int CVar
#define REGISTER_INT(_name, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegisterInt(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register an int CVar with a callback
#define REGISTER_INT_CB(_name, _def_val, _flags, _comment, _onchangefunction) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegisterInt(_name, (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register an int64 CVar
#define REGISTER_INT64(_name, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegisterInt64(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Preferred way to register a float CVar
#define REGISTER_FLOAT(_name, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegisterFloat(_name, (_def_val), (_flags), CVARHELP(_comment)))

//! Offers more flexibility but more code is required
#define REGISTER_CVAR2(_name, _var, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegister(_name, _var, (_def_val), (_flags), CVARHELP(_comment)))

//! Offers more flexibility but more code is required
#define REGISTER_CVAR2_CB(_name, _var, _def_val, _flags, _comment, _onchangefunction) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegister(_name, _var, (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Offers more flexibility but more code is required, explicit address taking of destination variable
#define REGISTER_CVAR3(_name, _var, _def_val, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegister(_name, &(_var), (_def_val), (_flags), CVARHELP(_comment)))

//! Offers more flexibility but more code is required, explicit address taking of destination variable
#define REGISTER_CVAR3_CB(_name, _var, _def_val, _flags, _comment, _onchangefunction) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? 0 : Internal::ChairRegister(_name, &(_var), (_def_val), (_flags), CVARHELP(_comment), _onchangefunction))

//! Preferred way to register a console command
#define REGISTER_COMMAND(_name, _func, _flags, _comment) (ASSERT_CONSOLE_EXISTS, gEnv->pConsole == 0 ? (void)0 : gEnv->pConsole->AddCommand(_name, _func, (_flags), CVARHELP(_comment)))

////////////////////////////////////////////////////////////////////////////////
//! Development only cvars.
//! (1) Registered as real cvars *in non release builds only*.
//! (2) Can still be manipulated in release by the mapped variable, so not the same as const cvars.
//! (3) Any 'OnChanged' callback will need guarding against in release builds since the cvar won't exist.
//! (4) Any code that tries to get ICVar* will need guarding against in release builds since the cvar won't exist.
//! ILLEGAL_DEV_FLAGS is a mask of all those flags which make no sense in a _DEV_ONLY or _DEDI_ONLY cvar since the.
//! Cvar potentially won't exist in a release build.
#define ILLEGAL_DEV_FLAGS (VF_NET_SYNCED | VF_CHEAT | VF_CHEAT_ALWAYS_CHECK | VF_CHEAT_NOCHECK | VF_READONLY | VF_CONST_CVAR)

#if defined(_RELEASE)
	#define REGISTER_CVAR_DEV_ONLY(_var, _def_val, _flags, _comment)                               NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0); _var = _def_val
	#define REGISTER_CVAR_CB_DEV_ONLY(_var, _def_val, _flags, _comment, _onchangefunction)         NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0); _var = _def_val /* _onchangefunction consumed; callback not available */
	#define REGISTER_STRING_DEV_ONLY(_name, _def_val, _flags, _comment)                            NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)                  /* consumed; pure cvar not available */
	#define REGISTER_STRING_CB_DEV_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)      NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)                  /* consumed; pure cvar not available */
	#define REGISTER_INT_DEV_ONLY(_name, _def_val, _flags, _comment)                               NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)                  /* consumed; pure cvar not available */
	#define REGISTER_INT_CB_DEV_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)         NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)                  /* consumed; pure cvar not available */
	#define REGISTER_INT64_DEV_ONLY(_name, _def_val, _flags, _comment)                             NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)                  /* consumed; pure cvar not available */
	#define REGISTER_FLOAT_DEV_ONLY(_name, _def_val, _flags, _comment)                             NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)                  /* consumed; pure cvar not available */
	#define REGISTER_CVAR2_DEV_ONLY(_name, _var, _def_val, _flags, _comment)                       NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0); *(_var) = _def_val
	#define REGISTER_CVAR2_CB_DEV_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0); *(_var) = _def_val
	#define REGISTER_CVAR3_DEV_ONLY(_name, _var, _def_val, _flags, _comment)                       NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0); _var = _def_val
	#define REGISTER_CVAR3_CB_DEV_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) NULL; COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0); _var = _def_val
	#define REGISTER_COMMAND_DEV_ONLY(_name, _func, _flags, _comment)                              /* consumed; command not available */
#else
	#define REGISTER_CVAR_DEV_ONLY(_var, _def_val, _flags, _comment)                               REGISTER_CVAR(_var, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR_CB_DEV_ONLY(_var, _def_val, _flags, _comment, _onchangefunction)         REGISTER_CVAR_CB(_var, _def_val, ((_flags) | VF_DEV_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_STRING_DEV_ONLY(_name, _def_val, _flags, _comment)                            REGISTER_STRING(_name, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_STRING_CB_DEV_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)      REGISTER_STRING_CB(_name, _def_val, ((_flags) | VF_DEV_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_INT_DEV_ONLY(_name, _def_val, _flags, _comment)                               REGISTER_INT(_name, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_INT_CB_DEV_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)         REGISTER_INT_CB(_name, _def_val, ((_flags) | VF_DEV_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_INT64_DEV_ONLY(_name, _def_val, _flags, _comment)                             REGISTER_INT64(_name, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_FLOAT_DEV_ONLY(_name, _def_val, _flags, _comment)                             REGISTER_FLOAT(_name, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR2_DEV_ONLY(_name, _var, _def_val, _flags, _comment)                       REGISTER_CVAR2(_name, _var, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR2_CB_DEV_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) REGISTER_CVAR2_CB(_name, _var, _def_val, ((_flags) | VF_DEV_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR3_DEV_ONLY(_name, _var, _def_val, _flags, _comment)                       REGISTER_CVAR3(_name, _var, _def_val, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR3_CB_DEV_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) REGISTER_CVAR3_CB(_name, _var, _def_val, ((_flags) | VF_DEV_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_COMMAND_DEV_ONLY(_name, _func, _flags, _comment)                              REGISTER_COMMAND(_name, _func, ((_flags) | VF_DEV_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
#endif // defined(_RELEASE)
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//! Dedicated server only cvars
//! (1) Registered as real cvars in all non release builds
//! (2) Registered as real cvars in release on dedi servers only, otherwise treated as DEV_ONLY type cvars (see above)
#if defined(_RELEASE) && defined(DEDICATED_SERVER)
	#define REGISTER_CVAR_DEDI_ONLY(_var, _def_val, _flags, _comment)                               REGISTER_CVAR(_var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR_CB_DEDI_ONLY(_var, _def_val, _flags, _comment, _onchangefunction)         REGISTER_CVAR_CB(_var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_STRING_DEDI_ONLY(_name, _def_val, _flags, _comment)                            REGISTER_STRING(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_STRING_CB_DEDI_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)      REGISTER_STRING_CB(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_INT_DEDI_ONLY(_name, _def_val, _flags, _comment)                               REGISTER_INT(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_INT_CB_DEDI_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)         REGISTER_INT_CB(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_INT64_DEDI_ONLY(_name, _def_val, _flags, _comment)                             REGISTER_INT64(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_FLOAT_DEDI_ONLY(_name, _def_val, _flags, _comment)                             REGISTER_FLOAT(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR2_DEDI_ONLY(_name, _var, _def_val, _flags, _comment)                       REGISTER_CVAR2(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR2_CB_DEDI_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) REGISTER_CVAR2_CB(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR3_DEDI_ONLY(_name, _var, _def_val, _flags, _comment)                       REGISTER_CVAR3(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_CVAR3_CB_DEDI_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) REGISTER_CVAR3_CB(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
	#define REGISTER_COMMAND_DEDI_ONLY(_name, _func, _flags, _comment)                              REGISTER_COMMAND(_name, _func, ((_flags) | VF_DEDI_ONLY), _comment); COMPILE_TIME_ASSERT(((_flags) & ILLEGAL_DEV_FLAGS) == 0)
#else
	#define REGISTER_CVAR_DEDI_ONLY(_var, _def_val, _flags, _comment)                               REGISTER_CVAR_DEV_ONLY(_var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_CVAR_CB_DEDI_ONLY(_var, _def_val, _flags, _comment, _onchangefunction)         REGISTER_CVAR_CB_DEV_ONLY(_var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction)
	#define REGISTER_STRING_DEDI_ONLY(_name, _def_val, _flags, _comment)                            REGISTER_STRING_DEV_ONLY(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_STRING_CB_DEDI_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)      REGISTER_STRING_CB_DEV_ONLY(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction)
	#define REGISTER_INT_DEDI_ONLY(_name, _def_val, _flags, _comment)                               REGISTER_INT_DEV_ONLY(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_INT_CB_DEDI_ONLY(_name, _def_val, _flags, _comment, _onchangefunction)         REGISTER_INT_CB_DEV_ONLY(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction)
	#define REGISTER_INT64_DEDI_ONLY(_name, _def_val, _flags, _comment)                             REGISTER_INT64_DEV_ONLY(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_FLOAT_DEDI_ONLY(_name, _def_val, _flags, _comment)                             REGISTER_FLOAT_DEV_ONLY(_name, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_CVAR2_DEDI_ONLY(_name, _var, _def_val, _flags, _comment)                       REGISTER_CVAR2_DEV_ONLY(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_CVAR2_CB_DEDI_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) REGISTER_CVAR2_CB_DEV_ONLY(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction)
	#define REGISTER_CVAR3_DEDI_ONLY(_name, _var, _def_val, _flags, _comment)                       REGISTER_CVAR3_DEV_ONLY(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment)
	#define REGISTER_CVAR3_CB_DEDI_ONLY(_name, _var, _def_val, _flags, _comment, _onchangefunction) REGISTER_CVAR3_CB_DEV_ONLY(_name, _var, _def_val, ((_flags) | VF_DEDI_ONLY), _comment, _onchangefunction)
	#define REGISTER_COMMAND_DEDI_ONLY(_name, _func, _flags, _comment)                              REGISTER_COMMAND_DEV_ONLY(_name, _func, ((_flags) | VF_DEDI_ONLY), _comment)
#endif // defined(_RELEASE)
//////////////////////////////////////////////////////////////////////////////

/*****************************************************
   ASYNC MEMCPY FUNCTIONS
*****************************************************/

//! Complex delegation required because it is not really easy to export a external standalone symbol like a memcpy function when building with modules.
//! Dlls pay an extra indirection cost for calling this function.
#if !defined(_LIB) || defined(IS_EAAS)
	#define CRY_ASYNC_MEMCPY_DELEGATE_TO_CRYSYSTEM
#endif
#define CRY_ASYNC_MEMCPY_API extern "C"

//! Note sync variable will be incremented (in calling thread) before job starts and decremented when job finishes.
//! Multiple async copies can therefore be tied to the same sync variable, therefore wait for completion with while(*sync) (yield());.
#if defined(CRY_ASYNC_MEMCPY_DELEGATE_TO_CRYSYSTEM)
inline void cryAsyncMemcpy(
  void* dst
  , const void* src
  , size_t size
  , int nFlags
  , volatile int* sync)
{
	GetISystem()->AsyncMemcpy(dst, src, size, nFlags, sync);
}
#else
CRY_ASYNC_MEMCPY_API void cryAsyncMemcpy(
  void* dst
  , const void* src
  , size_t size
  , int nFlags
  , volatile int* sync);
#endif

//#include <CrySystem/Profilers/FrameProfiler/FrameProfiler.h>
