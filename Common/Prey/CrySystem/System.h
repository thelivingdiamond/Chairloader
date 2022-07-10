#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/CrySystem/ITimer.h>
#include <Prey/CryMath/Cry_Camera.h>
#include <ChairLoader/PreyFunction.h>

namespace minigui
{
struct IMiniGUI;
}

namespace Telemetry
{
struct CFileStream;
struct CUDPStream;
}

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
