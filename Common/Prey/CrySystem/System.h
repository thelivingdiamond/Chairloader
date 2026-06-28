// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/ITimer.h>
#include <Prey/CryMath/Cry_Camera.h>
#include <Prey/CryString/CryName.h>
#include <Chairloader/PreyFunction.h>
#include <Prey/Ark/ArkBuildInfo.h>

namespace minigui
{
struct IMiniGUI;
}

namespace Telemetry
{
struct CFileStream;
struct CUDPStream;
}

struct IEngineModule;
struct SDefaultValidator;
class CCpuFeatures;
class CStreamEngine;
class CPhysRenderer;
struct IFFont;
class CXmlUtils;
class CrySizerStats;
class CrySizerImpl;
class CLocalizedStringsManager;
struct IThreadTask;
class CServerThrottle;
class CDownloadManager;
class CCmdLine;
class CThreadTaskManager;
class CResourceManager;
struct IFlashPlayer;

class CFrameProfileSystem { void* pad; };
class CThreadProfiler {};
class CProfilingSystem { void* pad; };
class CMemoryFragmentationProfiler { unsigned pad; };

class CTimer : public ITimer
{
public:
	struct STimeInfo
	{
		CTimeValue timeValue;
		int64 currentTime;
		float scale;
		float frameTime;
		float averageFrameTime;
		float channelScales[3];
		float arrFrameTimes[100];
		unsigned int scaleRtpc_m_controlId;
		bool bPaused;
		bool bRealTime;
		bool bPausable;
		bool bSmoothable;
	};

	STimeInfo m_CurrTime[4];
	int64 m_lBaseTime;
	int64 m_lLastTime;
	int64 m_lTicksPerSec;
	double m_fSecsPerTick;
	bool m_bEnabled;
	float m_fProfileBlend;
	float m_fSmoothTime;
	float m_fAvgFrameTime;
	float m_fixed_time_step;
	float m_max_time_step;
	float m_cvar_time_scale;
	int m_TimeSmoothing;
	float m_profile_smooth_time;
	int m_profile_weighting;
	unsigned int m_nFrameCounter;

	// Inherited via ITimer
	virtual void ResetTimer() override;
	virtual void UpdateOnFrameStart() override;
	virtual float GetCurrTime(ETimer which = ETIMER_GAME) const override;
	virtual const CTimeValue& GetFrameStartTime(ETimer which = ETIMER_GAME) const override;
	virtual CTimeValue GetAsyncTime() const override;
	virtual float GetAsyncCurTime() override;
	virtual float GetFrameTime(ETimer which = ETIMER_GAME) const override;
	virtual float GetRealFrameTime() const override;
	virtual float GetTimeScale(ETimer which = ETIMER_GAME) const override;
	virtual void SetTimeScale(ETimer which, float s, ETimeDilationChannel channel = GENERIC) override;
	virtual void EnableTimer(const bool bEnable) override;
	virtual bool IsTimerEnabled() const override;
	virtual float GetFrameRate() override;
	virtual float GetProfileFrameBlending(float* pfBlendTime = 0, int* piBlendMode = 0) override;
	virtual void Serialize(TSerialize ser) override;
	virtual bool PauseTimer(ETimer which, bool bPause) override;
	virtual bool IsTimerPaused(ETimer which) override;
	virtual bool SetTimer(ETimer which, float timeInSeconds) override;
	virtual void SecondsToDateUTC(time_t time, tm& outDateUTC) override;
	virtual time_t DateToSecondsUTC(tm& timePtr) override;
	virtual float TicksToSeconds(int64 ticks) const override;
	virtual int64 GetTicksPerSecond() override;
	virtual ITimer* CreateNewTimer() override;
};

static_assert(sizeof(CTimer) == 0x758);

struct SModuleInitInfo // Id=800248B Size=24
{
	const char* szDllName;
	const char* szClassName;
	std::shared_ptr<IEngineModule>(*pInitFunc)();
};

class CSystem : public ISystem, public ILoadConfigurationEntrySink, public ISystemEventListener
{
public:
	struct SDllHandles
	{
		void* hRenderer;
		void* hInput;
		void* hFlash;
		void* hSound;
		void* hEntitySystem;
		void* hNetwork;
		void* hAI;
		void* hMovie;
		void* hPhysics;
		void* hFont;
		void* hScript;
		void* h3DEngine;
		void* hAnimation;
		void* hIndoor;
		void* hGame;
	};

	struct SErrorMessage
	{
		string m_Message;
		float m_fTimeToShow;
		float m_Color[4];
		bool m_HardFailure;
	};

	static inline auto FSetDevMode = PreyFunction<void(CSystem* _this, bool bEnable)>(0xDC7720);
	static inline auto FInitializeEngineModule = PreyFunction<bool(
		CSystem* _this,
		const SModuleInitInfo* _initInfo,
		const SSystemInitParams* initParams,
		bool bQuitIfNotFound)>(0xDD7A50);
	static inline auto FShutdown = PreyFunction<void(CSystem* _this)>(0xDC79F0);
	static inline auto FUpdate = PreyFunction<bool(CSystem* const _this, int updateFlags, int nPauseMode)>(0xDC8A50);
	static inline auto FRender = PreyFunction<void(CSystem* const _this)>(0xDDF040);
	static inline auto FRenderEnd = PreyFunction<void(CSystem* const _this, bool bRenderStats)>(0xDDF450);
	static inline auto FInitSoundSystem = PreyFunction<bool(CSystem* const _this, const SSystemInitParams & _initParams)>(0xDD7730);
	static inline auto FCreateSystemVars = PreyFunction<void(CSystem* const _this)>(0xDCF790);
	static inline auto FChangeUserPath = PreyFunction<void(CSystem* const _this, const char* sUserPath)>(0xDE0720);
	static inline auto FLoadConfiguration = PreyFunction<void(CSystem* const _this, const char* sFilename, ILoadConfigurationEntrySink* pSink, bool allowMissing)>(0xDCB5B0);
	static inline auto FOpenBasicPaks = PreyFunction<void(CSystem* const _this)>(0xDD95F0);
	static inline auto FCreateFlashPlayerInstance = PreyFunction<IFlashPlayer*(CSystem* const _this)>(0xE5CC10);
	static inline auto FCreateFlashPlayerBootStrapper = PreyFunction<IFlashPlayerBootStrapper*(CSystem* const _this)>(0xE5CB40);
	//! Sets whether dev mode is enabled.
	inline void SetDevMode(bool bEnable) { FSetDevMode(this, bEnable); }

	SSystemGlobalEnvironment* m_env;
	CTimer m_Time;
	CCamera m_ViewCamera;
	volatile bool m_bQuit;
	bool m_bShaderCacheGenMode;
	bool m_bRelaunch;
	int m_iLoadingMode;
	bool m_bTestMode;
	bool m_bEditor;
	bool m_bNoCrashDialog;
	bool m_bAutoSubmitCrash;
	bool m_bPreviewMode;
	bool m_bUIFrameworkMode;
	bool m_bDedicatedServer;
	bool m_bIgnoreUpdates;
	IValidator* m_pValidator;
	bool m_bForceNonDevMode;
	bool m_bWasInDevMode;
	bool m_bInDevMode;
	bool m_bGameFolderWritable;
	SDefaultValidator* m_pDefaultValidator;
	int m_nStrangeRatio;
	string m_sDelayedScreeenshot;
	CCpuFeatures* m_pCpu;
	int m_ttMemStatSS;
	string m_szCmdLine;
	int m_iTraceAllocations;
	SDllHandles m_dll;
	std::map<CCryNameCRC, void*> m_moduleDLLHandles;
	CStreamEngine* m_pStreamEngine;
	IProcess* m_pProcess;
	IMemoryManager* m_pMemoryManager;
	CPhysRenderer* m_pPhysRenderer;
	CCamera m_PhysRendererCamera;
	ICVar* m_p_draw_helpers_str;
	int m_iJumpToPhysProfileEnt;
	CTimeValue m_lastTickTime;
	ISystemEventDispatcher* m_pSystemEventDispatcher;
	IFFont* m_pIFont;
	IBudgetingSystem* m_pIBudgetingSystem;
	IZLibCompressor* m_pIZLibCompressor;
	IZLibDecompressor* m_pIZLibDecompressor;
	ILZ4Decompressor* m_pILZ4Decompressor;
	CXmlUtils* m_pXMLUtils;
	Serialization::IArchiveHost* m_pArchiveHost;
	string m_root;
	int m_iApplicationInstance;
	int m_iHeight;
	int m_iWidth;
	int m_iColorBits;
	ICVar* m_sys_dll_ai;
	ICVar* m_sys_dll_game;
	ICVar* m_sys_game_folder;
	ICVar* m_sys_user_folder;
	ICVar* m_sys_initpreloadpacks;
	ICVar* m_sys_menupreloadpacks;
	ICVar* m_cvAIUpdate;
	ICVar* m_rWidth;
	ICVar* m_rHeight;
	ICVar* m_rColorBits;
	ICVar* m_rDepthBits;
	ICVar* m_rStencilBits;
	ICVar* m_rFullscreen;
	ICVar* m_rDriver;
	ICVar* m_cvGameName;
	ICVar* m_rDisplayInfo;
	ICVar* m_rLogDisplayInfo;
	ICVar* m_rDisplayInfoTargetFPS;
	ICVar* m_rOverscanBordersDrawDebugView;
	ICVar* m_sysNoUpdate;
	ICVar* m_cvEntitySuppressionLevel;
	ICVar* m_pCVarQuit;
	ICVar* m_cvMemStats;
	ICVar* m_cvMemStatsThreshold;
	ICVar* m_cvMemStatsMaxDepth;
	ICVar* m_sysKeyboard;
	ICVar* m_sysWarnings;
	ICVar* m_cvSSInfo;
	ICVar* m_svDedicatedMaxRate;
	ICVar* m_svAISystem;
	ICVar* m_clAISystem;
	ICVar* m_sys_profile;
	ICVar* m_sys_profile_additionalsub;
	ICVar* m_sys_profile_graph;
	ICVar* m_sys_profile_graphScale;
	ICVar* m_sys_profile_pagefaultsgraph;
	ICVar* m_sys_profile_filter;
	ICVar* m_sys_profile_filter_thread;
	ICVar* m_sys_profile_allThreads;
	ICVar* m_sys_profile_network;
	ICVar* m_sys_profile_peak;
	ICVar* m_sys_profile_peak_time;
	ICVar* m_sys_profile_memory;
	ICVar* m_sys_profile_sampler;
	ICVar* m_sys_profile_sampler_max_samples;
	ICVar* m_sys_job_system_filter;
	ICVar* m_sys_job_system_enable;
	ICVar* m_sys_job_system_profiler;
	ICVar* m_sys_job_system_max_worker;
	ICVar* m_sys_spec;
	ICVar* m_sys_firstlaunch;
	ICVar* m_sys_audio_disable;
	ICVar* m_sys_SimulateTask;
	ICVar* m_sys_min_step;
	ICVar* m_sys_max_step;
	ICVar* m_sys_budget;
	ICVar* m_sys_enable_budgetmonitoring;
	ICVar* m_ark_budget;
	ICVar* m_sys_memory_debug;
	ICVar* m_sys_preload;
	ICVar* m_gpu_particle_physics;
	string m_sSavedRDriver;
	ISystemUserCallback* m_pUserCallback;
	ICVarsWhitelist* m_pCVarsWhitelist;
	ILoadConfigurationEntrySink* m_pCVarsWhitelistConfigSink;
	void* m_hWnd;
	void* m_hInst;
	std::vector<SArkFrameProfileInfo> m_profileStats;
	CrySizerStats* m_pMemStats;
	CrySizerImpl* m_pSizer;
	CFrameProfileSystem m_FrameProfileSystem;
	CThreadProfiler* m_pThreadProfiler;
	struct IDiskProfiler* m_pDiskProfiler;
	std::unique_ptr<IPlatformOS> m_pPlatformOS;
	ICryPerfHUD* m_pPerfHUD;
	minigui::IMiniGUI* m_pMiniGUI;
	std::unique_ptr<IArkBethesdaNetManager> m_pBethesdaNetManager;
	SFileVersion m_fileVersion;
	SFileVersion m_productVersion;
	SFileVersion m_buildVersion;
	ArkBuildInfo m_buildInfo;
	IDataProbe* m_pDataProbe;
	CLocalizedStringsManager* m_pLocalizationManager;
	CNameTable m_nameTable;
	IThreadTask* m_PhysThread;
	Telemetry::CFileStream* m_pTelemetryFileStream;
	Telemetry::CUDPStream* m_pTelemetryUDPStream;
	ESystemConfigSpec m_nServerConfigSpec;
	ESystemConfigSpec m_nMaxConfigSpec;
	std::unique_ptr<CServerThrottle> m_pServerThrottle;
	CProfilingSystem m_ProfilingSystem;
	sUpdateTimes m_UpdateTimes[128];
	unsigned int m_UpdateTimesIdx;
	bool m_bPaused;
	unsigned __int8 m_PlatformOSCreateFlags;
	bool m_bNoUpdate;
	unsigned __int64 m_nUpdateCounter;
	int sys_ProfileLevelLoading;
	int sys_ProfileLevelLoadingDump;
	CDownloadManager* m_pDownloadManager;
	std::vector<IErrorObserver*> m_errorObservers;
	ESystemGlobalState m_systemGlobalState;
	ISystem::ILoadingProgressListener* m_pProgressListener;
	CCmdLine* m_pCmdLine;
	ITestSystem* m_pTestSystem;
	CThreadTaskManager* m_pThreadTaskManager;
	CResourceManager* m_pResourceManager;
	ITextModeConsole* m_pTextModeConsole;
	INotificationNetwork* m_pNotificationNetwork;
	string m_binariesDir;
	string m_currentLanguageAudio;
	std::vector<std::pair<CTimeValue, float>> m_updateTimes;
	CMemoryFragmentationProfiler m_MemoryFragmentationProfiler;
	std::list<CSystem::SErrorMessage> m_ErrorMessages;
	bool m_bHasRenderedErrorMessage;
	bool m_bNeedDoWorkDuringOcclusionChecks;
	ESystemEvent m_eRuntimeState;
	bool m_bIsAsserting;
	bool m_bIsSteamInitialized;
	std::unordered_map<string, string, std::hash<string >, std::equal_to<string >, std::allocator<std::pair<string const, string > > > m_mappedPathLocations;
	string m_LastSaveFile;
};

static_assert(sizeof(CSystem) == 0x2E38);
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/crycommon/cryfixedstring.h>
#include <Prey/Ark/ArkBuildInfo.h>
#include <Prey/CryInput/IInput.h>
#include <Prey/CryMath/Cry_Camera.h>
#include <Prey/CryString/CryName.h>
#include <Prey/CrySystem/CryVersion.h>
#include <Prey/CrySystem/FrameProfileSystem.h>
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/MemoryFragmentationProfiler.h>
#include <Prey/CrySystem/System.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/CrySystem/Timer.h>
#include <Prey/CryThreading/CryThread_win32.h>
#include <_unknown/ISystem.h>
#include <_unknown/IThreadTask.h>
#include <_unknown/SArkFrameProfileInfo.h>
#include <_unknown/SThreadTaskInfo.h>

class CBootProfilerRecord;
class CCmdLine;
class CCpuFeatures;
class CDownloadManager;
struct CLoadingTimeProfiler;
class CLocalizedStringsManager;
class CPNoise3;
class CPhysRenderer;
class CResourceManager;
class CServerThrottle;
class CStreamEngine;
class CThreadProfiler;
class CThreadTaskManager;
class CXmlUtils;
class CrySizerImpl;
class CrySizerStats;
enum EPLM_Event;
enum ESubsystem;
enum class EValidatorModule;
enum class EValidatorSeverity;
struct I3DEngine;
struct IAISystem;
struct IAVI_Reader;
class IArkBethesdaNetManager;
class IArkRoomVolumeManager;
struct IAudioSystem;
struct IBudgetingSystem;
struct ICVar;
struct ICVarsWhitelist;
struct ICharacterManager;
class ICmdLine;
struct IConsole;
struct ICryFactoryRegistry;
struct ICryFont;
struct ICryPak;
struct ICryPerfHUD;
class ICrySizer;
struct IDataProbe;
class IDebugCallStack;
struct IDialogSystem;
class IDiskProfiler;
struct IEntitySystem;
struct IErrorObserver;
struct IEvaluationManager;
struct IFFont;
struct IFileChangeMonitor;
struct IFlashLoadMovieHandler;
struct IFlashPlayer;
struct IFlashPlayerBootStrapper;
struct IFlashUI;
struct IFlowSystem;
struct IFrameProfileSystem;
struct IGame;
struct IGameStartup;
struct IHardwareMouse;
struct IInput;
struct ILZ4Decompressor;
struct ILevelEncrypter;
struct ILocalizationManager;
struct ILog;
struct IMaterialEffects;
struct IMemoryManager;
struct IMovieSystem;
struct INameTable;
struct INetwork;
struct INotificationNetwork;
class IOpticsManager;
struct IParticleManager;
struct IPhysRenderer;
struct IPhysicalWorld;
struct IPhysicsDebugRenderer;
struct IPlatformOS;
struct IProcess;
struct IRemoteConsole;
struct IRenderer;
struct IResourceCollector;
struct IResourceManager;
struct IScriptSystem;
struct IStreamEngine;
struct ISystemEventDispatcher;
struct ISystemUserCallback;
struct ITestSystem;
struct ITextModeConsole;
struct IThreadTaskManager;
struct ITimer;
struct IValidator;
struct IVisualLog;
struct IXmlUtils;
struct IZLibCompressor;
struct IZLibDecompressor;
struct SCryEngineStatsGlobalMemInfo;
struct SDefaultValidator;
struct SInputEvent;
struct SLoadingTimeContainer;
struct SModuleInitInfo;
struct SSystemGlobalEnvironment;
struct SSystemInitParams;
struct SSystemUpdateStats;
namespace Serialization
{
struct IArchiveHost;
} // namespace Serialization
namespace Telemetry
{
class CFileStream;
class CUDPStream;
} // namespace Telemetry
class XmlNodeRef;
namespace minigui
{
struct IMiniGUI;
} // namespace minigui

// BreakListener
// Header:  CryEngine/crysystem/System.h
// Include: Prey/CrySystem/System.cpp
class BreakListener : public IInputEventListener
{ // Size=8 (0x8)
public:
	virtual bool OnInputEvent(const SInputEvent& ie);

	static inline auto FOnInputEvent = PreyFunction<bool(BreakListener* const _this, const SInputEvent& ie)>(0xDDEAE0);
};

// CPhysicsThreadTask
// Header:  CryEngine/crysystem/System.h
// Include: Prey/CrySystem/System.cpp
class CPhysicsThreadTask : public IThreadTask
{ // Size=120 (0x78)
public:
	volatile int m_bStopRequested;
	volatile int m_bIsActive;
	volatile float m_stepRequested;
	volatile int m_bProcessing;
	volatile int m_doZeroStep;
	volatile uint64_t m_lastStepTimeTaken;
	volatile uint64_t m_lastWaitTimeTaken;
	CryEvent m_FrameEvent;
	CryEvent m_FrameDone;
	SThreadTaskInfo m_TaskInfo;

	virtual void OnUpdate();
	virtual void Stop();
	virtual SThreadTaskInfo* GetTaskInfo();
	virtual void Run();
	virtual void Cancel();
	int Pause() { return FPause(this); }
	int Resume() { return FResume(this); }

#if 0
	CPhysicsThreadTask();
	int IsActive();
	int RequestStep(float _arg0_);
	float GetRequestedStep();
	uint64_t LastStepTaken() const;
	uint64_t LastWaitTime() const;
	void EnsureStepDone();
#endif

	static inline auto FOnUpdate = PreyFunction<void(CPhysicsThreadTask* const _this)>(0xDE3CF0);
	static inline auto FStop = PreyFunction<void(CPhysicsThreadTask* const _this)>(0x5A35F0);
	static inline auto FGetTaskInfo = PreyFunction<SThreadTaskInfo* (CPhysicsThreadTask* const _this)>(0x1368F30);
	static inline auto FRun = PreyFunction<void(CPhysicsThreadTask* const _this)>(0xDE4420);
	static inline auto FCancel = PreyFunction<void(CPhysicsThreadTask* const _this)>(0xDE1600);
	static inline auto FPause = PreyFunction<int(CPhysicsThreadTask* const _this)>(0xDE4090);
	static inline auto FResume = PreyFunction<int(CPhysicsThreadTask* const _this)>(0xDE43D0);
};

// CSystem
// Header:  CryEngine/crysystem/System.h
// Include: Prey/CrySystem/NullImplementation/NullResponseSystem.h
class CSystem
	: public ISystem
	, public ILoadConfigurationEntrySink
	, public ISystemEventListener
{ // Size=11824 (0x2E30)
public:
	enum class MemStatsPurposeEnum
	{
		nMSP_ForDisplay = 0,
		nMSP_ForDump = 1,
		nMSP_ForCrashLog = 2,
		nMSP_ForBudget = 3,
	};

	// CSystem::SDllHandles
	// Header:  CryEngine/crysystem/System.h
	struct SDllHandles
	{ // Size=120 (0x78)
		void* hRenderer;
		void* hInput;
		void* hFlash;
		void* hSound;
		void* hEntitySystem;
		void* hNetwork;
		void* hAI;
		void* hMovie;
		void* hPhysics;
		void* hFont;
		void* hScript;
		void* h3DEngine;
		void* hAnimation;
		void* hIndoor;
		void* hGame;
	};

	// CSystem::SErrorMessage
	// Header:  CryEngine/crysystem/System.h
	struct SErrorMessage
	{ // Size=32 (0x20)
		string m_Message;
		float m_fTimeToShow;
		float m_Color[4];
		bool m_HardFailure;
	};

	using TErrorMessages = std::list<CSystem::SErrorMessage,std::allocator<CSystem::SErrorMessage> >;

	SSystemGlobalEnvironment& m_env;
	CTimer m_Time;
	CCamera m_ViewCamera;
	volatile bool m_bQuit;
	bool m_bShaderCacheGenMode;
	bool m_bRelaunch;
	int m_iLoadingMode;
	bool m_bTestMode;
	bool m_bEditor;
	bool m_bNoCrashDialog;
	bool m_bAutoSubmitCrash;
	bool m_bPreviewMode;
	bool m_bUIFrameworkMode;
	bool m_bDedicatedServer;
	bool m_bIgnoreUpdates;
	IValidator* m_pValidator;
	bool m_bForceNonDevMode;
	bool m_bWasInDevMode;
	bool m_bInDevMode;
	bool m_bGameFolderWritable;
	SDefaultValidator* m_pDefaultValidator;
	int m_nStrangeRatio;
	string m_sDelayedScreeenshot;
	CCpuFeatures* m_pCpu;
	int m_ttMemStatSS;
	string m_szCmdLine;
	int m_iTraceAllocations;
	CSystem::SDllHandles m_dll;
	std::map<CCryNameCRC, void*> m_moduleDLLHandles;
	CStreamEngine* m_pStreamEngine;
	IProcess* m_pProcess;
	IMemoryManager* m_pMemoryManager;
	CPhysRenderer* m_pPhysRenderer;
	CCamera m_PhysRendererCamera;
	ICVar* m_p_draw_helpers_str;
	int m_iJumpToPhysProfileEnt;
	CTimeValue m_lastTickTime;
	ISystemEventDispatcher* m_pSystemEventDispatcher;
	IFFont* m_pIFont;
	IBudgetingSystem* m_pIBudgetingSystem;
	IZLibCompressor* m_pIZLibCompressor;
	IZLibDecompressor* m_pIZLibDecompressor;
	ILZ4Decompressor* m_pILZ4Decompressor;
	CXmlUtils* m_pXMLUtils;
	Serialization::IArchiveHost* m_pArchiveHost;
	string m_root;
	int m_iApplicationInstance;
	int m_iHeight;
	int m_iWidth;
	int m_iColorBits;
	ICVar* m_sys_dll_ai;
	ICVar* m_sys_dll_game;
	ICVar* m_sys_game_folder;
	ICVar* m_sys_user_folder;
	ICVar* m_sys_initpreloadpacks;
	ICVar* m_sys_menupreloadpacks;
	ICVar* m_cvAIUpdate;
	ICVar* m_rWidth;
	ICVar* m_rHeight;
	ICVar* m_rColorBits;
	ICVar* m_rDepthBits;
	ICVar* m_rStencilBits;
	ICVar* m_rFullscreen;
	ICVar* m_rDriver;
	ICVar* m_cvGameName;
	ICVar* m_rDisplayInfo;
	ICVar* m_rLogDisplayInfo;
	ICVar* m_rDisplayInfoTargetFPS;
	ICVar* m_rOverscanBordersDrawDebugView;
	ICVar* m_sysNoUpdate;
	ICVar* m_cvEntitySuppressionLevel;
	ICVar* m_pCVarQuit;
	ICVar* m_cvMemStats;
	ICVar* m_cvMemStatsThreshold;
	ICVar* m_cvMemStatsMaxDepth;
	ICVar* m_sysKeyboard;
	ICVar* m_sysWarnings;
	ICVar* m_cvSSInfo;
	ICVar* m_svDedicatedMaxRate;
	ICVar* m_svAISystem;
	ICVar* m_clAISystem;
	ICVar* m_sys_profile;
	ICVar* m_sys_profile_additionalsub;
	ICVar* m_sys_profile_graph;
	ICVar* m_sys_profile_graphScale;
	ICVar* m_sys_profile_pagefaultsgraph;
	ICVar* m_sys_profile_filter;
	ICVar* m_sys_profile_filter_thread;
	ICVar* m_sys_profile_allThreads;
	ICVar* m_sys_profile_network;
	ICVar* m_sys_profile_peak;
	ICVar* m_sys_profile_peak_time;
	ICVar* m_sys_profile_memory;
	ICVar* m_sys_profile_sampler;
	ICVar* m_sys_profile_sampler_max_samples;
	ICVar* m_sys_job_system_filter;
	ICVar* m_sys_job_system_enable;
	ICVar* m_sys_job_system_profiler;
	ICVar* m_sys_job_system_max_worker;
	ICVar* m_sys_spec;
	ICVar* m_sys_firstlaunch;
	ICVar* m_sys_audio_disable;
	ICVar* m_sys_SimulateTask;
	ICVar* m_sys_min_step;
	ICVar* m_sys_max_step;
	ICVar* m_sys_budget;
	ICVar* m_sys_enable_budgetmonitoring;
	ICVar* m_ark_budget;
	ICVar* m_sys_memory_debug;
	ICVar* m_sys_preload;
	ICVar* m_gpu_particle_physics;
	string m_sSavedRDriver;
	ISystemUserCallback* m_pUserCallback;
	ICVarsWhitelist* m_pCVarsWhitelist;
	ILoadConfigurationEntrySink* m_pCVarsWhitelistConfigSink;
	void* m_hWnd;
	void* m_hInst;
	std::vector<SArkFrameProfileInfo> m_profileStats;
	CrySizerStats* m_pMemStats;
	CrySizerImpl* m_pSizer;
	CFrameProfileSystem m_FrameProfileSystem;
	CThreadProfiler* m_pThreadProfiler;
	IDiskProfiler* m_pDiskProfiler;
	std::unique_ptr<IPlatformOS> m_pPlatformOS;
	ICryPerfHUD* m_pPerfHUD;
	minigui::IMiniGUI* m_pMiniGUI;
	std::unique_ptr<IArkBethesdaNetManager> m_pBethesdaNetManager;
	SFileVersion m_fileVersion;
	SFileVersion m_productVersion;
	SFileVersion m_buildVersion;
	ArkBuildInfo m_buildInfo;
	IDataProbe* m_pDataProbe;
	CLocalizedStringsManager* m_pLocalizationManager;
	CNameTable m_nameTable;
	IThreadTask* m_PhysThread;
	Telemetry::CFileStream* m_pTelemetryFileStream;
	Telemetry::CUDPStream* m_pTelemetryUDPStream;
	ESystemConfigSpec m_nServerConfigSpec;
	ESystemConfigSpec m_nMaxConfigSpec;
	std::unique_ptr<CServerThrottle> m_pServerThrottle;
	sUpdateTimes m_UpdateTimes[128];
	unsigned m_UpdateTimesIdx;
	bool m_bPaused;
	uint8_t m_PlatformOSCreateFlags;
	bool m_bNoUpdate;
	uint64_t m_nUpdateCounter;
	int sys_ProfileLevelLoading;
	int sys_ProfileLevelLoadingDump;
	CDownloadManager* m_pDownloadManager;
	std::vector<IErrorObserver*> m_errorObservers;
	ESystemGlobalState m_systemGlobalState;
	ISystem::ILoadingProgressListener* m_pProgressListener;
	CCmdLine* m_pCmdLine;
	ITestSystem* m_pTestSystem;
	CThreadTaskManager* m_pThreadTaskManager;
	CResourceManager* m_pResourceManager;
	ITextModeConsole* m_pTextModeConsole;
	INotificationNetwork* m_pNotificationNetwork;
	string m_binariesDir;
	string m_currentLanguageAudio;
	std::vector<std::pair<CTimeValue, float>> m_updateTimes;
	CMemoryFragmentationProfiler m_MemoryFragmentationProfiler;
	std::list<CSystem::SErrorMessage,std::allocator<CSystem::SErrorMessage> > m_ErrorMessages;
	bool m_bHasRenderedErrorMessage;
	bool m_bNeedDoWorkDuringOcclusionChecks;
	ESystemEvent m_eRuntimeState;
	bool m_bIsAsserting;
	bool m_bIsSteamInitialized;
	std::unordered_map<string, string> m_mappedPathLocations;
	string m_LastSaveFile;

	CSystem();
	virtual ~CSystem();
	virtual bool IsUIFrameworkMode();
	static void OnLanguageCVarChanged(ICVar* const pLanguage) { FOnLanguageCVarChanged(pLanguage); }
	static void OnLanguageAudioCVarChanged(ICVar* const pLanguageAudio) { FOnLanguageAudioCVarChanged(pLanguageAudio); }
	static void OnLocalizationFolderCVarChanged(ICVar* const pLocalizationFolder) { FOnLocalizationFolderCVarChanged(pLocalizationFolder); }
	virtual void OnLoadConfigurationEntry(const char* szKey, const char* szValue, const char* szGroup);
	virtual void OnSystemEvent(ESystemEvent event, uint64_t wparam, uint64_t lparam);
	virtual bool Init(const SSystemInitParams& startupParams);
	virtual void Release();
	virtual SSystemGlobalEnvironment* GetGlobalEnvironment();
	virtual const char* GetRootFolder() const;
	void LimitFramerate() { FLimitFramerate(this); }
	virtual bool Update(int updateFlags, int nPauseMode);
	virtual bool UpdateLoadtime();
	virtual void DoWorkDuringOcclusionChecks();
	virtual bool NeedDoWorkDuringOcclusionChecks();
	virtual void RenderBegin(bool _bUpdateFrameId);
	virtual void Render();
	virtual void RenderEnd(bool bRenderStats);
	void UpdateLoadingScreen() { FUpdateLoadingScreen(this); }
	virtual void SynchronousLoadingTick(const char* pFunc, int line);
	virtual void RenderStatistics();
	virtual void RenderPhysicsStatistics(IPhysicalWorld* pWorld);
	virtual unsigned GetUsedMemory();
	virtual void DumpMemoryUsageStatistics(bool bUseKB);
	virtual void DumpMemoryCoverage();
	virtual bool SteamInit();
	virtual void Relaunch(bool bRelaunch);
	virtual bool IsRelaunch() const;
	virtual void SerializingFile(int mode);
	virtual int IsSerializingFile() const;
	virtual void Quit();
	virtual bool IsQuitting() const;
	virtual bool IsShaderCacheGenMode() const;
	void SetAffinity() { FSetAffinity(this); }
	virtual const char* GetUserName();
	virtual int GetApplicationInstance();
	virtual sUpdateTimes& GetCurrentUpdateTimeStats();
	virtual const sUpdateTimes* GetUpdateTimeStats(unsigned& index, unsigned& num);
	virtual IGame* GetIGame();
	virtual INetwork* GetINetwork();
	virtual IRenderer* GetIRenderer();
	virtual IInput* GetIInput();
	virtual ITimer* GetITimer();
	virtual ICryPak* GetIPak();
	virtual IConsole* GetIConsole();
	virtual IRemoteConsole* GetIRemoteConsole();
	virtual IScriptSystem* GetIScriptSystem();
	virtual I3DEngine* GetI3DEngine();
	virtual ICharacterManager* GetIAnimationSystem();
	virtual IAudioSystem* GetIAudioSystem();
	virtual IArkRoomVolumeManager* GetIArkRoomVolumeManager();
	virtual IPhysicalWorld* GetIPhysicalWorld();
	virtual IMovieSystem* GetIMovieSystem();
	virtual IAISystem* GetAISystem();
	virtual IMemoryManager* GetIMemoryManager();
	virtual IEntitySystem* GetIEntitySystem();
	virtual ICryFont* GetICryFont();
	virtual ILog* GetILog();
	virtual ICmdLine* GetICmdLine();
	virtual IStreamEngine* GetStreamEngine();
	virtual IValidator* GetIValidator();
	virtual IPhysicsDebugRenderer* GetIPhysicsDebugRenderer();
	virtual IPhysRenderer* GetIPhysRenderer();
	virtual IFrameProfileSystem* GetIProfileSystem();
	virtual IDiskProfiler* GetIDiskProfiler();
	virtual INameTable* GetINameTable();
	virtual IBudgetingSystem* GetIBudgetingSystem();
	virtual IFlowSystem* GetIFlowSystem();
	virtual IDialogSystem* GetIDialogSystem();
	virtual IHardwareMouse* GetIHardwareMouse();
	virtual ISystemEventDispatcher* GetISystemEventDispatcher();
	virtual ITestSystem* GetITestSystem();
	virtual IThreadTaskManager* GetIThreadTaskManager();
	virtual IResourceManager* GetIResourceManager();
	virtual ITextModeConsole* GetITextModeConsole();
	virtual IFileChangeMonitor* GetIFileChangeMonitor();
	virtual IVisualLog* GetIVisualLog();
	virtual INotificationNetwork* GetINotificationNetwork();
	virtual IPlatformOS* GetPlatformOS();
	virtual ICryPerfHUD* GetPerfHUD();
	virtual IZLibCompressor* GetIZLibCompressor();
	virtual IZLibDecompressor* GetIZLibDecompressor();
	virtual ILZ4Decompressor* GetLZ4Decompressor();
	virtual IArkBethesdaNetManager* GetIArkBethesdaNetManager();
	virtual void* GetHWND();
	virtual CPNoise3* GetNoiseGen();
	virtual uint64_t GetUpdateCounter();
	virtual void SetLoadingProgressListener(ISystem::ILoadingProgressListener* pLoadingProgressListener);
	virtual ISystem::ILoadingProgressListener* GetLoadingProgressListener() const;
	virtual void SetIGame(IGame* pGame);
	virtual void SetIFlowSystem(IFlowSystem* pFlowSystem);
	virtual void SetIDialogSystem(IDialogSystem* pDialogSystem);
	virtual void SetIMaterialEffects(IMaterialEffects* pMaterialEffects);
	virtual void SetIParticleManager(IParticleManager* pParticleManager);
	virtual void SetIOpticsManager(IOpticsManager* pOpticsManager);
	virtual void SetIArkRoomVolumeManager(IArkRoomVolumeManager* pRoomVolumeManager);
	virtual void SetIFileChangeMonitor(IFileChangeMonitor* pFileChangeMonitor);
	virtual void SetIVisualLog(IVisualLog* pVisualLog);
	virtual void SetIFlashUI(IFlashUI* pFlashUI);
	virtual void ChangeUserPath(const char* sUserPath);
	void DetectGameFolderAccessRights() { FDetectGameFolderAccessRights(this); }
	virtual void ExecuteCommandLine();
	virtual void GetUpdateStats(SSystemUpdateStats& stats);
	virtual XmlNodeRef CreateXmlNode(const char* sNodeName, bool bReuseStrings);
	virtual XmlNodeRef LoadXmlFromFile(const char* sFilename, bool bReuseStrings, unsigned _nFileFlags);
	virtual XmlNodeRef LoadXmlFromBuffer(const char* buffer, uint64_t size, bool bReuseStrings);
	virtual IXmlUtils* GetXmlUtils();
	virtual Serialization::IArchiveHost* GetArchiveHost() const;
	virtual void SetViewCamera(CCamera& Camera);
	virtual CCamera& GetViewCamera();
	virtual unsigned GetCPUFlags();
	virtual int GetLogicalCPUCount();
	virtual void IgnoreUpdates(bool bIgnore);
	virtual void SetIProcess(IProcess* process);
	virtual IProcess* GetIProcess();
	virtual bool IsTestMode() const;
	virtual void DisplayErrorMessage(const char* acMessage, float fTime, const float* pfColor, bool bHardError);
	virtual void FatalError(const char* format, ... ArgList);
	virtual void ReportBug(const char* format, ... szBuffer);
	virtual void OpenArkBugReporter(const char* _bugString);
	virtual void SetLastSaveFile(const char* _saveGameFileName);
	virtual const char* GetLastSaveFile();
	virtual void WarningV(EValidatorModule module, EValidatorSeverity severity, int flags, const char* file, const char* format, char* args);
	virtual void Warning(EValidatorModule module, EValidatorSeverity severity, int flags, const char* file, const char* format, ... _arg5_);
	virtual int ShowMessage(const char* text, const char* caption, unsigned uType);
	virtual bool CheckLogVerbosity(int verbosity);
	virtual void DebugStats(bool checkpoint, bool leaks);
	virtual void DumpWinHeaps();
	virtual int DumpMMStats(bool log);
	virtual ICVarsWhitelist* GetCVarsWhiteList() const;
	virtual ILoadConfigurationEntrySink* GetCVarsWhiteListConfigSink() const;
	virtual void SaveConfiguration();
	virtual void LoadConfiguration(const char* sFilename, ILoadConfigurationEntrySink* pSink, bool allowMissing);
	virtual ESystemConfigSpec GetConfigSpec(bool bClient);
	virtual void SetConfigSpec(ESystemConfigSpec spec, bool bClient);
	virtual ESystemConfigSpec GetMaxConfigSpec() const;
	virtual int SetThreadState(ESubsystem subsys, bool bActive);
	virtual ICrySizer* CreateSizer();
	virtual bool IsPaused() const;
	virtual IFlashPlayer* CreateFlashPlayerInstance() const;
	virtual IFlashPlayerBootStrapper* CreateFlashPlayerBootStrapper() const;
	virtual void SetFlashLoadMovieHandler(IFlashLoadMovieHandler* pHandler) const;
	virtual void GetFlashProfileResults(float& accumTime, bool __unnamed1) const;
	virtual void ResetFlashMeshCache() const;
	virtual void GFxAmpEnable(bool bEnable);
	virtual void GFxAmpAdvanceFrame();
	virtual void ResetFlashDirtyState();
	virtual IAVI_Reader* CreateAVIReader();
	virtual void ReleaseAVIReader(IAVI_Reader* pAVIReader);
	virtual ILocalizationManager* GetLocalizationManager();
	virtual IDebugCallStack* GetIDebugCallstack();
	virtual void debug_LogCallStack(int nMaxFuncs, int nFlags);
	virtual ICryFactoryRegistry* GetCryFactoryRegistry() const;
	virtual ILevelEncrypter* GetLevelEncrypter();
	virtual IEvaluationManager* GetEvaluationManager();
	virtual char* GetDeveloperName(char* devName);
	void CollectMemStats(ICrySizer* pSizer, CSystem::MemStatsPurposeEnum nPurpose, std::vector<SmallModuleInfo>* pStats) { FCollectMemStats(this, pSizer, nPurpose, pStats); }
	void GetExeSizes(ICrySizer* pSizer, CSystem::MemStatsPurposeEnum nPurpose) { FGetExeSizes(this, pSizer, nPurpose); }
	void TickMemStats(CSystem::MemStatsPurposeEnum nPurpose, IResourceCollector* pResourceCollector) { FTickMemStats(this, nPurpose, pResourceCollector); }
	virtual bool InitializeEngineModule(const SModuleInitInfo& _initInfo, const SSystemInitParams& initParams, bool bQuitIfNotFound);
	virtual bool UnloadEngineModule(const SModuleInitInfo& _initInfo);
	void ShutDown() { FShutDown(this); }
	bool InitRenderer(void* hinst, void* hwnd, const SSystemInitParams& initParams) { return FInitRenderer(this, hinst, hwnd, initParams); }
	bool InitPhysics(const SSystemInitParams& initParams) { return FInitPhysics(this, initParams); }
	bool InitPhysicsRenderer(const SSystemInitParams& initParams) { return FInitPhysicsRenderer(this, initParams); }
	bool InitFont(const SSystemInitParams& initParams) { return FInitFont(this, initParams); }
	bool InitFileSystem(const IGameStartup* pGameStartup) { return FInitFileSystem(this, pGameStartup); }
	bool InitFileSystem_LoadEngineFolders() { return FInitFileSystem_LoadEngineFolders(this); }
	bool InitSoundSystem(const SSystemInitParams& _initParams) { return FInitSoundSystem(this, _initParams); }
	bool OpenRenderLibrary(int type, const SSystemInitParams& initParams) { return FOpenRenderLibraryOv1(this, type, initParams); }
	void LoadPathMappings() { FLoadPathMappings(this); }
	virtual void OverridePathMappings(const char* const _mappedPathFileLoc);
	void LoadBuildInfo() { FLoadBuildInfo(this); }
	void ShutdownArkProfile() { FShutdownArkProfile(this); }
	void StopArkProfile() { FStopArkProfile(this); }
	virtual const std::vector<SArkFrameProfileInfo>& GetProfileData() const;
	virtual void ClearProfileData();
	void CreateRendererVars(const SSystemInitParams& startupParams) { FCreateRendererVars(this, startupParams); }
	void CreateSystemVars() { FCreateSystemVars(this); }
	void RenderFlashInfo() { FRenderFlashInfo(this); }
	virtual void GetFlashMemoryUsage(ICrySizer* pSizer) const;
	void QueryVersionInfo() { FQueryVersionInfo(this); }
	void LogVersion() { FLogVersion(this); }
	void LogBuildInfo() { FLogBuildInfo(this); }
	void SetDevMode(bool bEnable) { FSetDevMode(this, bEnable); }
	static void TelemetryStreamFileChanged(ICVar* pCVar) { FTelemetryStreamFileChanged(pCVar); }
	static void TelemetryStreamIPChanged(ICVar* pCVar) { FTelemetryStreamIPChanged(pCVar); }
	bool ReLaunchMediaCenter() { return FReLaunchMediaCenter(this); }
	void LogSystemInfo() { FLogSystemInfo(this); }
	void UpdateAudioSystems() { FUpdateAudioSystems(this); }
	void AddCVarGroupDirectory(const string& sPath) { FAddCVarGroupDirectory(this, sPath); }
	void EnableFloatExceptions(int type) { FEnableFloatExceptions(this, type); }
	virtual string GetMappedPathLocation(const string& _identifier) const;
	virtual IDataProbe* GetIDataProbe();
	virtual void SetForceNonDevMode(const bool bValue);
	virtual bool GetForceNonDevMode() const;
	virtual bool WasInDevMode() const;
	virtual bool IsDevMode() const;
	virtual void AutoDetectSpec(const bool detectResolution);
	virtual void AsyncMemcpy(void* dst, const void* src, uint64_t size, int nFlags, volatile int* sync);
	virtual void OnPLMEvent(EPLM_Event event);
	virtual void SetFrameProfiler(bool on, bool display, char* prefix);
	virtual const SFileVersion& GetFileVersion();
	virtual const SFileVersion& GetProductVersion();
	virtual const SFileVersion& GetBuildVersion();
	virtual const ArkBuildInfo& GetBuildInfo();
	virtual void AddRuntimeBuildInfo(const char* key, const char* value);
	virtual bool WriteCompressedFile(const char* filename, void* data, unsigned bitlen);
	virtual unsigned ReadCompressedFile(const char* filename, void* data, unsigned maxbitlen);
	virtual unsigned GetCompressedFileSizeA(const char* filename);
	virtual bool CompressDataBlock(const void* input, uint64_t inputSize, void* output, uint64_t& outputSize, int level);
	virtual bool DecompressDataBlock(const void* input, uint64_t inputSize, void* output, uint64_t& outputSize);
	void OpenBasicPaks() { FOpenBasicPaks(this); }
	void OpenLanguagePak(const char* const sLanguage) { FOpenLanguagePak(this, sLanguage); }
	void OpenLanguageAudioPak(const char* const sLanguage) { FOpenLanguageAudioPak(this, sLanguage); }
	void GetLocalizedPath(const char* const szLanguage, CryStackStringT<char,512>& sLocalizedPath, bool bPatchPath) { FGetLocalizedPath(this, szLanguage, sLocalizedPath, bPatchPath); }
	void GetLocalizedAudioPath(const char* const szLanguage, CryStackStringT<char,512>& sLocalizedPath, bool bPatchPath) { FGetLocalizedAudioPath(this, szLanguage, sLocalizedPath, bPatchPath); }
	void CloseLanguagePak(const char* const szLanguage) { FCloseLanguagePak(this, szLanguage); }
	void CloseLanguageAudioPak(const char* const szLanguage) { FCloseLanguageAudioPak(this, szLanguage); }
	virtual void OutputLoadingTimeStats();
	virtual SLoadingTimeContainer* StartLoadingSectionProfiling(CLoadingTimeProfiler* pProfiler, const char* szFuncName);
	virtual void EndLoadingSectionProfiling(CLoadingTimeProfiler* pProfiler);
	virtual const char* GetLoadingProfilerCallstack();
	virtual CBootProfilerRecord* StartBootSectionProfiler(const char* name, const char* args);
	virtual void StopBootSectionProfiler(CBootProfilerRecord* record);
	virtual void StartBootProfilerSessionFrames(const char* pName);
	virtual void StopBootProfilerSessionFrames();
	virtual bool RegisterErrorObserver(IErrorObserver* errorObserver);
	virtual bool UnregisterErrorObserver(IErrorObserver* errorObserver);
	virtual void OnAssert(const char* condition, const char* message, const char* fileName, unsigned fileLineNumber);
	virtual void OnScriptWarning(const char* _message);
	void OnFatalError(const char* message) { FOnFatalError(this, message); }
	virtual bool IsAssertDialogVisible() const;
	virtual void SetAssertVisible(bool bAssertVisble);
	virtual void ClearErrorMessages();
	virtual void AddPlatformOSCreateFlag(const uint8_t createFlag);
	virtual ESystemGlobalState GetSystemGlobalState();
	virtual void SetSystemGlobalState(const ESystemGlobalState systemGlobalState);
	void InitLocalization(const char* languageName) { FInitLocalization(this, languageName); }

#if 0
	void RenderPhysicsHelpers();
	void CollectMemInfo(SCryEngineStatsGlobalMemInfo& _arg0_);
	CThreadProfiler* GetThreadProfiler();
	void SetGCFrequency(const float _arg0_);
	void SleepIfNeeded();
	void LogCallStack();
	ISystemUserCallback* GetUserCallback() const;
	static void debug_GetCallStackRaw(void* * _arg0_, unsigned& _arg1_);
	void SleepIfInactive();
	bool LoadEngineDLLs();
	bool InitNetwork(const SSystemInitParams& _arg0_);
	bool InitOnline(const SSystemInitParams& _arg0_);
	bool InitLobby(const SSystemInitParams& _arg0_);
	bool InitInput(const SSystemInitParams& _arg0_);
	bool InitConsole();
	bool InitFlash();
	bool InitAISystem(const SSystemInitParams& _arg0_);
	bool InitScriptSystem(const SSystemInitParams& _arg0_);
	void LoadPatchPaks();
	bool InitStreamEngine();
	bool Init3DEngine(const SSystemInitParams& _arg0_);
	bool InitAnimationSystem(const SSystemInitParams& _arg0_);
	bool InitMovieSystem(const SSystemInitParams& _arg0_);
	bool InitEntitySystem(const SSystemInitParams& _arg0_);
	bool OpenRenderLibrary(const char* _arg0_, const SSystemInitParams& _arg1_);
	bool CloseRenderLibrary();
	void Strange();
	bool ParseSystemConfig(string& _arg0_);
	bool InitArkProfile(const SSystemInitParams& _arg0_);
	bool StartArkProfile(int _arg0_);
	void UpdateArkProfile();
	void CreateAudioVars();
	void RenderStats();
	void RenderOverscanBorders();
	void RenderJobStats();
	void RenderMemStats();
	void RenderThreadInfo();
	void* LoadDLL(const char* _arg0_, bool _arg1_);
	bool UnloadDLL(const char* _arg0_);
	void FreeLib(void* _arg0_);
	void InitScriptDebugger();
	void CreatePhysicsThread();
	void KillPhysicsThread();
	void* LoadDynamiclibrary(const char* _arg0_) const;
	bool GetWinGameFolder(char* _arg0_, int _arg1_);
	ICVar* attachVariable(const char* _arg0_, int* _arg1_, const char* _arg2_, int _arg3_);
	CCpuFeatures* GetCPUFeatures();
	string& GetDelayedScreeenshot();
	const CTimeValue& GetLastTickTime() const;
	const ICVar* GetDedicatedMaxRate() const;
	void Deltree(const char* _arg0_, bool _arg1_);
	void UpdateMovieSystem(const int _arg0_, const float _arg1_, const bool _arg2_);
	bool IsLoading();
	static const char* GetSystemGlobalStateName(const ESystemGlobalState _arg0_);
	void UpdateUpdateTimes();
	bool InitArkRewardSystem();
	bool InitArkEntitlementSystem();
	bool InitArkCommerceSystem();
#endif

	static inline auto FCSystem = PreyFunction<void(CSystem* const _this)>(0xDDFF90);
	static inline auto FBitNotCSystem = PreyFunction<void(CSystem* const _this)>(0xDE08D0);
	static inline auto FIsUIFrameworkMode = PreyFunction<bool(CSystem* const _this)>(0xDE32A0);
	static inline auto FOnLanguageCVarChanged = PreyFunction<void(ICVar* const pLanguage)>(0xDE3840);
	static inline auto FOnLanguageAudioCVarChanged = PreyFunction<void(ICVar* const pLanguageAudio)>(0xDE36D0);
	static inline auto FOnLocalizationFolderCVarChanged = PreyFunction<void(ICVar* const pLocalizationFolder)>(0xDE39C0);
	static inline auto FOnLoadConfigurationEntry = PreyFunction<void(ILoadConfigurationEntrySink* const _this, const char* szKey, const char* szValue, const char* szGroup)>(0xDE89E0);
	static inline auto FOnSystemEvent = PreyFunction<void(ISystemEventListener* const _this, ESystemEvent event, uint64_t wparam, uint64_t lparam)>(0xDE3CA0);
	static inline auto FInit = PreyFunction<bool(CSystem* const _this, const SSystemInitParams& startupParams)>(0xDEF550);
	static inline auto FRelease = PreyFunction<void(CSystem* const _this)>(0x3E3960);
	static inline auto FGetGlobalEnvironment = PreyFunction<SSystemGlobalEnvironment* (CSystem* const _this)>(0x598E60);
	static inline auto FGetRootFolder = PreyFunction<const char* (const CSystem* const _this)>(0xDE3090);
	static inline auto FLimitFramerate = PreyFunction<void(CSystem* const _this)>(0xDE32B0);
	static inline auto FUpdate = PreyFunction<bool(CSystem* const _this, int updateFlags, int nPauseMode)>(0xDE5B10);
	static inline auto FUpdateLoadtime = PreyFunction<bool(CSystem* const _this)>(0xDE6FD0);
	static inline auto FDoWorkDuringOcclusionChecks = PreyFunction<void(CSystem* const _this)>(0xDE1D80);
	static inline auto FNeedDoWorkDuringOcclusionChecks = PreyFunction<bool(CSystem* const _this)>(0xDE36C0);
	static inline auto FRenderBegin = PreyFunction<void(CSystem* const _this, bool _bUpdateFrameId)>(0xDFC3B0);
	static inline auto FRender = PreyFunction<void(CSystem* const _this)>(0xDFC060);
	static inline auto FRenderEnd = PreyFunction<void(CSystem* const _this, bool bRenderStats)>(0xDFC470);
	static inline auto FUpdateLoadingScreen = PreyFunction<void(CSystem* const _this)>(0xDFC820);
	static inline auto FSynchronousLoadingTick = PreyFunction<void(CSystem* const _this, const char* pFunc, int line)>(0xDFC690);
	static inline auto FRenderStatistics = PreyFunction<void(CSystem* const _this)>(0xDFC600);
	static inline auto FRenderPhysicsStatistics = PreyFunction<void(CSystem* const _this, IPhysicalWorld* pWorld)>(0x1333E90);
	static inline auto FGetUsedMemory = PreyFunction<unsigned(CSystem* const _this)>(0xDE31D0);
	static inline auto FDumpMemoryUsageStatistics = PreyFunction<void(CSystem* const _this, bool bUseKB)>(0xDFF450);
	static inline auto FDumpMemoryCoverage = PreyFunction<void(CSystem* const _this)>(0xDE2380);
	static inline auto FSteamInit = PreyFunction<bool(CSystem* const _this)>(0x13B0900);
	static inline auto FRelaunch = PreyFunction<void(CSystem* const _this, bool bRelaunch)>(0xDE4350);
	static inline auto FIsRelaunch = PreyFunction<bool(const CSystem* const _this)>(0xDE3260);
	static inline auto FSerializingFile = PreyFunction<void(CSystem* const _this, int mode)>(0xDE4770);
	static inline auto FIsSerializingFile = PreyFunction<int(const CSystem* const _this)>(0xDE3270);
	static inline auto FQuit = PreyFunction<void(CSystem* const _this)>(0xDE4100);
	static inline auto FIsQuitting = PreyFunction<bool(const CSystem* const _this)>(0xDE3250);
	static inline auto FIsShaderCacheGenMode = PreyFunction<bool(const CSystem* const _this)>(0xDE3280);
	static inline auto FSetAffinity = PreyFunction<void(CSystem* const _this)>(0xE00D70);
	static inline auto FGetUserName = PreyFunction<const char* (CSystem* const _this)>(0xE002E0);
	static inline auto FGetApplicationInstance = PreyFunction<int(CSystem* const _this)>(0xDFFE90);
	static inline auto FGetCurrentUpdateTimeStats = PreyFunction<sUpdateTimes& (CSystem* const _this)>(0xDE2700);
	static inline auto FGetUpdateTimeStats = PreyFunction<const sUpdateTimes* (CSystem* const _this, unsigned& index, unsigned& num)>(0xDE31B0);
	static inline auto FGetIGame = PreyFunction<IGame* (CSystem* const _this)>(0xDE28E0);
	static inline auto FGetINetwork = PreyFunction<INetwork* (CSystem* const _this)>(0xDE2950);
	static inline auto FGetIRenderer = PreyFunction<IRenderer* (CSystem* const _this)>(0xDE2A60);
	static inline auto FGetIInput = PreyFunction<IInput* (CSystem* const _this)>(0xDE2900);
	static inline auto FGetITimer = PreyFunction<ITimer* (CSystem* const _this)>(0xDE2AE0);
	static inline auto FGetIPak = PreyFunction<ICryPak* (CSystem* const _this)>(0xDE2970);
	static inline auto FGetIConsole = PreyFunction<IConsole* (CSystem* const _this)>(0xDE2860);
	static inline auto FGetIRemoteConsole = PreyFunction<IRemoteConsole* (CSystem* const _this)>(0xDE29E0);
	static inline auto FGetIScriptSystem = PreyFunction<IScriptSystem* (CSystem* const _this)>(0xDE2A80);
	static inline auto FGetI3DEngine = PreyFunction<I3DEngine* (CSystem* const _this)>(0x18515F0);
	static inline auto FGetIAnimationSystem = PreyFunction<ICharacterManager* (CSystem* const _this)>(0xDE2800);
	static inline auto FGetIAudioSystem = PreyFunction<IAudioSystem* (CSystem* const _this)>(0xDE2830);
	static inline auto FGetIArkRoomVolumeManager = PreyFunction<IArkRoomVolumeManager* (CSystem* const _this)>(0xDE2820);
	static inline auto FGetIPhysicalWorld = PreyFunction<IPhysicalWorld* (CSystem* const _this)>(0xDE29A0);
	static inline auto FGetIMovieSystem = PreyFunction<IMovieSystem* (CSystem* const _this)>(0xDE2930);
	static inline auto FGetAISystem = PreyFunction<IAISystem* (CSystem* const _this)>(0xDE2670);
	static inline auto FGetIMemoryManager = PreyFunction<IMemoryManager* (CSystem* const _this)>(0xDE2920);
	static inline auto FGetIEntitySystem = PreyFunction<IEntitySystem* (CSystem* const _this)>(0xDE28B0);
	static inline auto FGetICryFont = PreyFunction<ICryFont* (CSystem* const _this)>(0xDE2870);
	static inline auto FGetILog = PreyFunction<ILog* (CSystem* const _this)>(0xDE2910);
	static inline auto FGetICmdLine = PreyFunction<ICmdLine* (CSystem* const _this)>(0xDE2850);
	static inline auto FGetStreamEngine = PreyFunction<IStreamEngine* (CSystem* const _this)>(0xDE30A0);
	static inline auto FGetIValidator = PreyFunction<IValidator* (CSystem* const _this)>(0xDE2AF0);
	static inline auto FGetIPhysicsDebugRenderer = PreyFunction<IPhysicsDebugRenderer* (CSystem* const _this)>(0xDE29B0);
	static inline auto FGetIPhysRenderer = PreyFunction<IPhysRenderer* (CSystem* const _this)>(0xDE2980);
	static inline auto FGetIProfileSystem = PreyFunction<IFrameProfileSystem* (CSystem* const _this)>(0xDE29D0);
	static inline auto FGetIDiskProfiler = PreyFunction<IDiskProfiler* (CSystem* const _this)>(0xDE28A0);
	static inline auto FGetINameTable = PreyFunction<INameTable* (CSystem* const _this)>(0xDE2940);
	static inline auto FGetIBudgetingSystem = PreyFunction<IBudgetingSystem* (CSystem* const _this)>(0xDE2840);
	static inline auto FGetIFlowSystem = PreyFunction<IFlowSystem* (CSystem* const _this)>(0xDE28D0);
	static inline auto FGetIDialogSystem = PreyFunction<IDialogSystem* (CSystem* const _this)>(0xDE2890);
	static inline auto FGetIHardwareMouse = PreyFunction<IHardwareMouse* (CSystem* const _this)>(0xDE28F0);
	static inline auto FGetISystemEventDispatcher = PreyFunction<ISystemEventDispatcher* (CSystem* const _this)>(0xDE2A90);
	static inline auto FGetITestSystem = PreyFunction<ITestSystem* (CSystem* const _this)>(0xDE2AA0);
	static inline auto FGetIThreadTaskManager = PreyFunction<IThreadTaskManager* (CSystem* const _this)>(0xDE2AD0);
	static inline auto FGetIResourceManager = PreyFunction<IResourceManager* (CSystem* const _this)>(0xDE2A70);
	static inline auto FGetITextModeConsole = PreyFunction<ITextModeConsole* (CSystem* const _this)>(0xDE2AB0);
	static inline auto FGetIFileChangeMonitor = PreyFunction<IFileChangeMonitor* (CSystem* const _this)>(0xDE28C0);
	static inline auto FGetIVisualLog = PreyFunction<IVisualLog* (CSystem* const _this)>(0xDE2B00);
	static inline auto FGetINotificationNetwork = PreyFunction<INotificationNetwork* (CSystem* const _this)>(0xDE2960);
	static inline auto FGetPlatformOS = PreyFunction<IPlatformOS* (CSystem* const _this)>(0xDE3080);
	static inline auto FGetPerfHUD = PreyFunction<ICryPerfHUD* (CSystem* const _this)>(0xDE3070);
	static inline auto FGetIZLibCompressor = PreyFunction<IZLibCompressor* (CSystem* const _this)>(0xDE2B10);
	static inline auto FGetIZLibDecompressor = PreyFunction<IZLibDecompressor* (CSystem* const _this)>(0xDE2B20);
	static inline auto FGetLZ4Decompressor = PreyFunction<ILZ4Decompressor* (CSystem* const _this)>(0xDE2B30);
	static inline auto FGetIArkBethesdaNetManager = PreyFunction<IArkBethesdaNetManager* (CSystem* const _this)>(0xDE2810);
	static inline auto FGetHWND = PreyFunction<void* (CSystem* const _this)>(0xDE27F0);
	static inline auto FGetNoiseGen = PreyFunction<CPNoise3* (CSystem* const _this)>(0xDE2E30);
	static inline auto FGetUpdateCounter = PreyFunction<uint64_t(CSystem* const _this)>(0xDE30C0);
	static inline auto FSetLoadingProgressListener = PreyFunction<void(CSystem* const _this, ISystem::ILoadingProgressListener* pLoadingProgressListener)>(0xDE48C0);
	static inline auto FGetLoadingProgressListener = PreyFunction<ISystem::ILoadingProgressListener* (const CSystem* const _this)>(0xDE2B50);
	static inline auto FSetIGame = PreyFunction<void(CSystem* const _this, IGame* pGame)>(0xDE4830);
	static inline auto FSetIFlowSystem = PreyFunction<void(CSystem* const _this, IFlowSystem* pFlowSystem)>(0xDE4820);
	static inline auto FSetIDialogSystem = PreyFunction<void(CSystem* const _this, IDialogSystem* pDialogSystem)>(0xDE47F0);
	static inline auto FSetIMaterialEffects = PreyFunction<void(CSystem* const _this, IMaterialEffects* pMaterialEffects)>(0xDE4840);
	static inline auto FSetIParticleManager = PreyFunction<void(CSystem* const _this, IParticleManager* pParticleManager)>(0xDE4860);
	static inline auto FSetIOpticsManager = PreyFunction<void(CSystem* const _this, IOpticsManager* pOpticsManager)>(0xDE4850);
	static inline auto FSetIArkRoomVolumeManager = PreyFunction<void(CSystem* const _this, IArkRoomVolumeManager* pRoomVolumeManager)>(0xDE47E0);
	static inline auto FSetIFileChangeMonitor = PreyFunction<void(CSystem* const _this, IFileChangeMonitor* pFileChangeMonitor)>(0xDE4800);
	static inline auto FSetIVisualLog = PreyFunction<void(CSystem* const _this, IVisualLog* pVisualLog)>(0xDE4880);
	static inline auto FSetIFlashUI = PreyFunction<void(CSystem* const _this, IFlashUI* pFlashUI)>(0xDE4810);
	static inline auto FChangeUserPath = PreyFunction<void(CSystem* const _this, const char* sUserPath)>(0xDFD6D0);
	static inline auto FDetectGameFolderAccessRights = PreyFunction<void(CSystem* const _this)>(0xDFF280);
	static inline auto FExecuteCommandLine = PreyFunction<void(CSystem* const _this)>(0xDE2390);
	static inline auto FGetUpdateStats = PreyFunction<void(CSystem* const _this, SSystemUpdateStats& stats)>(0xDE30D0);
	static inline auto FCreateXmlNode = PreyFunction<XmlNodeRef*(CSystem* const _this, XmlNodeRef* _return_value_, const char* sNodeName, bool bReuseStrings)>(0xDE1A60);
	static inline auto FLoadXmlFromFile = PreyFunction<XmlNodeRef*(CSystem* const _this, XmlNodeRef* _return_value_, const char* sFilename, bool bReuseStrings, unsigned _nFileFlags)>(0xDE3620);
	static inline auto FLoadXmlFromBuffer = PreyFunction<XmlNodeRef*(CSystem* const _this, XmlNodeRef* _return_value_, const char* buffer, uint64_t size, bool bReuseStrings)>(0xDE35F0);
	static inline auto FGetXmlUtils = PreyFunction<IXmlUtils* (CSystem* const _this)>(0xDE31F0);
	static inline auto FGetArchiveHost = PreyFunction<Serialization::IArchiveHost* (const CSystem* const _this)>(0xDE2680);
	static inline auto FSetViewCamera = PreyFunction<void(CSystem* const _this, CCamera& Camera)>(0xDE4A30);
	static inline auto FGetViewCamera = PreyFunction<CCamera& (CSystem* const _this)>(0xDE31E0);
	static inline auto FGetCPUFlags = PreyFunction<unsigned(CSystem* const _this)>(0xDE2690);
	static inline auto FGetLogicalCPUCount = PreyFunction<int(CSystem* const _this)>(0xDE2B90);
	static inline auto FIgnoreUpdates = PreyFunction<void(CSystem* const _this, bool bIgnore)>(0xDE3200);
	static inline auto FSetIProcess = PreyFunction<void(CSystem* const _this, IProcess* process)>(0xDE4870);
	static inline auto FGetIProcess = PreyFunction<IProcess* (CSystem* const _this)>(0xDE29C0);
	static inline auto FIsTestMode = PreyFunction<bool(const CSystem* const _this)>(0xDE3290);
	static inline auto FDisplayErrorMessage = PreyFunction<void(CSystem* const _this, const char* acMessage, float fTime, const float* pfColor, bool bHardError)>(0xDFBEE0);
	static inline auto FFatalError = PreyFunction<void(CSystem* const _this, const char* format, ... ArgList)>(0xDFFB60);
	static inline auto FReportBug = PreyFunction<void(CSystem* const _this, const char* format, ... szBuffer)>(0xE00CD0);
	static inline auto FOpenArkBugReporter = PreyFunction<void(CSystem* const _this, const char* _bugString)>(0x1333E90);
	static inline auto FSetLastSaveFile = PreyFunction<void(CSystem* const _this, const char* _saveGameFileName)>(0xDE4890);
	static inline auto FGetLastSaveFile = PreyFunction<const char* (CSystem* const _this)>(0xDE2B40);
	static inline auto FWarningV = PreyFunction<void(CSystem* const _this, EValidatorModule module, EValidatorSeverity severity, int flags, const char* file, const char* format, char* args)>(0xDE7050);
	static inline auto FWarning = PreyFunction<void(CSystem* const _this, EValidatorModule module, EValidatorSeverity severity, int flags, const char* file, const char* format, ... _arg5_)>(0xDE7020);
	static inline auto FShowMessage = PreyFunction<int(CSystem* const _this, const char* text, const char* caption, unsigned uType)>(0xDE4A40);
	static inline auto FCheckLogVerbosity = PreyFunction<bool(CSystem* const _this, int verbosity)>(0xDE1630);
	static inline auto FDebugStats = PreyFunction<void(CSystem* const _this, bool checkpoint, bool leaks)>(0xDFEC90);
	static inline auto FDumpWinHeaps = PreyFunction<void(CSystem* const _this)>(0xDFF5B0);
	static inline auto FDumpMMStats = PreyFunction<int(CSystem* const _this, bool log)>(0xDFF3E0);
	static inline auto FGetCVarsWhiteList = PreyFunction<ICVarsWhitelist* (const CSystem* const _this)>(0xDE26B0);
	static inline auto FGetCVarsWhiteListConfigSink = PreyFunction<ILoadConfigurationEntrySink* (const CSystem* const _this)>(0xDE26C0);
	static inline auto FSaveConfiguration = PreyFunction<void(CSystem* const _this)>(0x1333E90);
	static inline auto FLoadConfiguration = PreyFunction<void(CSystem* const _this, const char* sFilename, ILoadConfigurationEntrySink* pSink, bool allowMissing)>(0xDE8690);
	static inline auto FGetConfigSpec = PreyFunction<ESystemConfigSpec(CSystem* const _this, bool bClient)>(0xDE26D0);
	static inline auto FSetConfigSpec = PreyFunction<void(CSystem* const _this, ESystemConfigSpec spec, bool bClient)>(0xDE4780);
	static inline auto FGetMaxConfigSpec = PreyFunction<ESystemConfigSpec(const CSystem* const _this)>(0xDE2DB0);
	static inline auto FSetThreadState = PreyFunction<int(CSystem* const _this, ESubsystem subsys, bool bActive)>(0xDE4A00);
	static inline auto FCreateSizer = PreyFunction<ICrySizer* (CSystem* const _this)>(0xDE1A30);
	static inline auto FIsPaused = PreyFunction<bool(const CSystem* const _this)>(0xDE3240);
	static inline auto FCreateFlashPlayerInstance = PreyFunction<IFlashPlayer* (const CSystem* const _this)>(0xE79980);
	static inline auto FCreateFlashPlayerBootStrapper = PreyFunction<IFlashPlayerBootStrapper* (const CSystem* const _this)>(0xE798B0);
	static inline auto FSetFlashLoadMovieHandler = PreyFunction<void(const CSystem* const _this, IFlashLoadMovieHandler* pHandler)>(0xE7E0E0);
	static inline auto FGetFlashProfileResults = PreyFunction<void(const CSystem* const _this, float& accumTime, bool __unnamed1)>(0xE7AEC0);
	static inline auto FResetFlashMeshCache = PreyFunction<void(const CSystem* const _this)>(0xE7D360);
	static inline auto FGFxAmpEnable = PreyFunction<void(CSystem* const _this, bool bEnable)>(0x1333E90);
	static inline auto FGFxAmpAdvanceFrame = PreyFunction<void(CSystem* const _this)>(0x1333E90);
	static inline auto FResetFlashDirtyState = PreyFunction<void(CSystem* const _this)>(0xE7D340);
	static inline auto FCreateAVIReader = PreyFunction<IAVI_Reader* (CSystem* const _this)>(0xD7CAB0);
	static inline auto FReleaseAVIReader = PreyFunction<void(CSystem* const _this, IAVI_Reader* pAVIReader)>(0xD7CF80);
	static inline auto FGetLocalizationManager = PreyFunction<ILocalizationManager* (CSystem* const _this)>(0xDE2B60);
	static inline auto FGetIDebugCallstack = PreyFunction<IDebugCallStack* (CSystem* const _this)>(0xE002D0);
	static inline auto Fdebug_LogCallStack = PreyFunction<void(CSystem* const _this, int nMaxFuncs, int nFlags)>(0xE013C0);
	static inline auto FGetCryFactoryRegistry = PreyFunction<ICryFactoryRegistry* (const CSystem* const _this)>(0xE8B140);
	static inline auto FGetLevelEncrypter = PreyFunction<ILevelEncrypter* (CSystem* const _this)>(0x1CBB0B0);
	static inline auto FGetEvaluationManager = PreyFunction<IEvaluationManager* (CSystem* const _this)>(0x1CBB0B0);
	static inline auto FGetDeveloperName = PreyFunction<char* (CSystem* const _this, char* devName)>(0x1CBB0B0);
	static inline auto FCollectMemStats = PreyFunction<void(CSystem* const _this, ICrySizer* pSizer, CSystem::MemStatsPurposeEnum nPurpose, std::vector<SmallModuleInfo>* pStats)>(0xDFDE50);
	static inline auto FGetExeSizes = PreyFunction<void(CSystem* const _this, ICrySizer* pSizer, CSystem::MemStatsPurposeEnum nPurpose)>(0xE000B0);
	static inline auto FTickMemStats = PreyFunction<void(CSystem* const _this, CSystem::MemStatsPurposeEnum nPurpose, IResourceCollector* pResourceCollector)>(0xE00EA0);
	static inline auto FInitializeEngineModule = PreyFunction<bool(CSystem* const _this, const SModuleInitInfo& _initInfo, const SSystemInitParams& initParams, bool bQuitIfNotFound)>(0xDF52E0);
	static inline auto FUnloadEngineModule = PreyFunction<bool(CSystem* const _this, const SModuleInitInfo& _initInfo)>(0xDFB110);
	static inline auto FShutDown = PreyFunction<void(CSystem* const _this)>(0xDE4A70);
	static inline auto FInitRenderer = PreyFunction<bool(CSystem* const _this, void* hinst, void* hwnd, const SSystemInitParams& initParams)>(0xDF4C50);
	static inline auto FInitPhysics = PreyFunction<bool(CSystem* const _this, const SSystemInitParams& initParams)>(0xDF2F90);
	static inline auto FInitPhysicsRenderer = PreyFunction<bool(CSystem* const _this, const SSystemInitParams& initParams)>(0xDF48E0);
	static inline auto FInitFont = PreyFunction<bool(CSystem* const _this, const SSystemInitParams& initParams)>(0xDF2720);
	static inline auto FInitFileSystem = PreyFunction<bool(CSystem* const _this, const IGameStartup* pGameStartup)>(0xDF1D00);
	static inline auto FInitFileSystem_LoadEngineFolders = PreyFunction<bool(CSystem* const _this)>(0xDF24D0);
	static inline auto FInitSoundSystem = PreyFunction<bool(CSystem* const _this, const SSystemInitParams& _initParams)>(0xDF4FC0);
	static inline auto FOpenRenderLibraryOv1 = PreyFunction<bool(CSystem* const _this, int type, const SSystemInitParams& initParams)>(0xDF7EA0);
	static inline auto FLoadPathMappings = PreyFunction<void(CSystem* const _this)>(0xDE35A0);
	static inline auto FOverridePathMappings = PreyFunction<void(CSystem* const _this, const char* const _mappedPathFileLoc)>(0xDE3D20);
	static inline auto FLoadBuildInfo = PreyFunction<void(CSystem* const _this)>(0xDE3460);
	static inline auto FShutdownArkProfile = PreyFunction<void(CSystem* const _this)>(0x18C9930);
	static inline auto FStopArkProfile = PreyFunction<void(CSystem* const _this)>(0x1333E90);
	static inline auto FGetProfileData = PreyFunction<const std::vector<SArkFrameProfileInfo>& (const CSystem* const _this)>(0xDFC050);
	static inline auto FClearProfileData = PreyFunction<void(CSystem* const _this)>(0xDFBB70);
	static inline auto FCreateRendererVars = PreyFunction<void(CSystem* const _this, const SSystemInitParams& startupParams)>(0xDFBB80);
	static inline auto FCreateSystemVars = PreyFunction<void(CSystem* const _this)>(0xDECA30);
	static inline auto FRenderFlashInfo = PreyFunction<void(CSystem* const _this)>(0x1333E90);
	static inline auto FGetFlashMemoryUsage = PreyFunction<void(const CSystem* const _this, ICrySizer* pSizer)>(0xE7AEA0);
	static inline auto FQueryVersionInfo = PreyFunction<void(CSystem* const _this)>(0xDE9D10);
	static inline auto FLogVersion = PreyFunction<void(CSystem* const _this)>(0xDE8840);
	static inline auto FLogBuildInfo = PreyFunction<void(CSystem* const _this)>(0xDE87D0);
	static inline auto FSetDevMode = PreyFunction<void(CSystem* const _this, bool bEnable)>(0xDE47A0);
	static inline auto FTelemetryStreamFileChanged = PreyFunction<void(ICVar* pCVar)>(0xDE5830);
	static inline auto FTelemetryStreamIPChanged = PreyFunction<void(ICVar* pCVar)>(0xDE5930);
	static inline auto FReLaunchMediaCenter = PreyFunction<bool(CSystem* const _this)>(0xE00B30);
	static inline auto FLogSystemInfo = PreyFunction<void(CSystem* const _this)>(0xE003B0);
	static inline auto FUpdateAudioSystems = PreyFunction<void(CSystem* const _this)>(0xDE6F80);
	static inline auto FAddCVarGroupDirectory = PreyFunction<void(CSystem* const _this, const string& sPath)>(0xDEBBB0);
	static inline auto FEnableFloatExceptions = PreyFunction<void(CSystem* const _this, int type)>(0x1333E90);
	static inline auto FGetMappedPathLocation = PreyFunction<string*(const CSystem* const _this, string* _return_value_, const string& _identifier)>(0xDE2BA0);
	static inline auto FGetIDataProbe = PreyFunction<IDataProbe* (CSystem* const _this)>(0xDE2880);
	static inline auto FSetForceNonDevMode = PreyFunction<void(CSystem* const _this, const bool bValue)>(0xDE47C0);
	static inline auto FGetForceNonDevMode = PreyFunction<bool(const CSystem* const _this)>(0xDE27E0);
	static inline auto FWasInDevMode = PreyFunction<bool(const CSystem* const _this)>(0xDE7700);
	static inline auto FIsDevMode = PreyFunction<bool(const CSystem* const _this)>(0xDE3210);
	static inline auto FAutoDetectSpec = PreyFunction<void(CSystem* const _this, const bool detectResolution)>(0xD7B1A0);
	static inline auto FAsyncMemcpy = PreyFunction<void(CSystem* const _this, void* dst, const void* src, uint64_t size, int nFlags, volatile int* sync)>(0xDE1470);
	static inline auto FOnPLMEvent = PreyFunction<void(CSystem* const _this, EPLM_Event event)>(0xDE3B30);
	static inline auto FSetFrameProfiler = PreyFunction<void(CSystem* const _this, bool on, bool display, char* prefix)>(0x1333E90);
	static inline auto FGetFileVersion = PreyFunction<const SFileVersion& (CSystem* const _this)>(0xDE8670);
	static inline auto FGetProductVersion = PreyFunction<const SFileVersion& (CSystem* const _this)>(0xDE8680);
	static inline auto FGetBuildVersion = PreyFunction<const SFileVersion& (CSystem* const _this)>(0xDE8660);
	static inline auto FGetBuildInfo = PreyFunction<const ArkBuildInfo& (CSystem* const _this)>(0xDE8650);
	static inline auto FAddRuntimeBuildInfo = PreyFunction<void(CSystem* const _this, const char* key, const char* value)>(0xDE8600);
	static inline auto FWriteCompressedFile = PreyFunction<bool(CSystem* const _this, const char* filename, void* data, unsigned bitlen)>(0xD7DFC0);
	static inline auto FReadCompressedFile = PreyFunction<unsigned(CSystem* const _this, const char* filename, void* data, unsigned maxbitlen)>(0xD7DF40);
	static inline auto FGetCompressedFileSizeA = PreyFunction<unsigned(CSystem* const _this, const char* filename)>(0xD7DD40);
	static inline auto FCompressDataBlock = PreyFunction<bool(CSystem* const _this, const void* input, uint64_t inputSize, void* output, uint64_t& outputSize, int level)>(0xD7DCC0);
	static inline auto FDecompressDataBlock = PreyFunction<bool(CSystem* const _this, const void* input, uint64_t inputSize, void* output, uint64_t& outputSize)>(0xD7DD00);
	static inline auto FOpenBasicPaks = PreyFunction<void(CSystem* const _this)>(0xDF6D80);
	static inline auto FOpenLanguagePak = PreyFunction<void(CSystem* const _this, const char* const sLanguage)>(0xDF7B80);
	static inline auto FOpenLanguageAudioPak = PreyFunction<void(CSystem* const _this, const char* const sLanguage)>(0xDF76E0);
	static inline auto FGetLocalizedPath = PreyFunction<void(CSystem* const _this, const char* const szLanguage, CryStackStringT<char,512>& sLocalizedPath, bool bPatchPath)>(0xDE2B80);
	static inline auto FGetLocalizedAudioPath = PreyFunction<void(CSystem* const _this, const char* const szLanguage, CryStackStringT<char,512>& sLocalizedPath, bool bPatchPath)>(0xDE2B70);
	static inline auto FCloseLanguagePak = PreyFunction<void(CSystem* const _this, const char* const szLanguage)>(0xDE1960);
	static inline auto FCloseLanguageAudioPak = PreyFunction<void(CSystem* const _this, const char* const szLanguage)>(0xDE1670);
	static inline auto FOutputLoadingTimeStats = PreyFunction<void(CSystem* const _this)>(0x1333E90);
	static inline auto FStartLoadingSectionProfiling = PreyFunction<SLoadingTimeContainer* (CSystem* const _this, CLoadingTimeProfiler* pProfiler, const char* szFuncName)>(0x1CBB0B0);
	static inline auto FEndLoadingSectionProfiling = PreyFunction<void(CSystem* const _this, CLoadingTimeProfiler* pProfiler)>(0x1333E90);
	static inline auto FGetLoadingProfilerCallstack = PreyFunction<const char* (CSystem* const _this)>(0x1CBB0B0);
	static inline auto FStartBootSectionProfiler = PreyFunction<CBootProfilerRecord* (CSystem* const _this, const char* name, const char* args)>(0x1CBB0B0);
	static inline auto FStopBootSectionProfiler = PreyFunction<void(CSystem* const _this, CBootProfilerRecord* record)>(0x1333E90);
	static inline auto FStartBootProfilerSessionFrames = PreyFunction<void(CSystem* const _this, const char* pName)>(0x1333E90);
	static inline auto FStopBootProfilerSessionFrames = PreyFunction<void(CSystem* const _this)>(0x1333E90);
	static inline auto FRegisterErrorObserver = PreyFunction<bool(CSystem* const _this, IErrorObserver* errorObserver)>(0xDF98A0);
	static inline auto FUnregisterErrorObserver = PreyFunction<bool(CSystem* const _this, IErrorObserver* errorObserver)>(0xDFB4E0);
	static inline auto FOnAssert = PreyFunction<void(CSystem* const _this, const char* condition, const char* message, const char* fileName, unsigned fileLineNumber)>(0xDF63A0);
	static inline auto FOnScriptWarning = PreyFunction<void(CSystem* const _this, const char* _message)>(0xDF6AD0);
	static inline auto FOnFatalError = PreyFunction<void(CSystem* const _this, const char* message)>(0xDF64C0);
	static inline auto FIsAssertDialogVisible = PreyFunction<bool(const CSystem* const _this)>(0xDF5640);
	static inline auto FSetAssertVisible = PreyFunction<void(CSystem* const _this, bool bAssertVisble)>(0xDFAAB0);
	static inline auto FClearErrorMessages = PreyFunction<void(CSystem* const _this)>(0xDE1660);
	static inline auto FAddPlatformOSCreateFlag = PreyFunction<void(CSystem* const _this, const uint8_t createFlag)>(0xDE1460);
	static inline auto FGetSystemGlobalState = PreyFunction<ESystemGlobalState(CSystem* const _this)>(0xDE30B0);
	static inline auto FSetSystemGlobalState = PreyFunction<void(CSystem* const _this, const ESystemGlobalState systemGlobalState)>(0xDE48D0);
	static inline auto FInitLocalization = PreyFunction<void(CSystem* const _this, const char* languageName)>(0xDF2950);
};

// SBreakListenerTask
// Header:  CryEngine/crysystem/System.h
// Include: Prey/CrySystem/System.cpp
struct SBreakListenerTask : public IThreadTask
{ // Size=72 (0x48)
	volatile int m_bStop;
	int m_nBreakIdle;
	SThreadTaskInfo m_TaskInfo;

	virtual void OnUpdate();
	virtual void Stop();
	virtual SThreadTaskInfo* GetTaskInfo();

#if 0
	SBreakListenerTask();
#endif

	static inline auto FOnUpdate = PreyFunction<void(SBreakListenerTask* const _this)>(0xDDEB10);
	static inline auto FStop = PreyFunction<void(SBreakListenerTask* const _this)>(0xDDEBA0);
	static inline auto FGetTaskInfo = PreyFunction<SThreadTaskInfo* (SBreakListenerTask* const _this)>(0x10ED260);
};

// SCVarsWhitelistConfigSink
// Header:  CryEngine/crysystem/System.h
// Include: Prey/CrySystem/System.cpp
struct SCVarsWhitelistConfigSink : public ILoadConfigurationEntrySink
{ // Size=8 (0x8)
	virtual void OnLoadConfigurationEntry(const char* szKey, const char* szValue, const char* szGroup);

	static inline auto FOnLoadConfigurationEntry = PreyFunction<void(SCVarsWhitelistConfigSink* const _this, const char* szKey, const char* szValue, const char* szGroup)>(0xDDEBF0);
};
#endif // !MOONCRASH
