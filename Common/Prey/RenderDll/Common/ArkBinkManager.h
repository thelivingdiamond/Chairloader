// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/ISystem.h>
#include <Prey/GameDll/ark/ui/ArkBinkPlayerHandle.h>
#include <Prey/Ark/IArkBinkManager.h>

struct ArkBinkPlaybackInfo;
class ArkBinkPlayer;
class ArkBinkRenderer;
class ArkBinkRendererCPU;
struct BINK;
struct ICVar;

// Header: Exact
// CryEngine/renderdll/common/ArkBinkManager.h
class ArkBinkManager : public IArkBinkManager, public ISystemEventListener // Id=8010731 Size=248
{
public:
	ArkBinkRendererCPU *m_pRendererCPU;
	
	using PlayerMap = std::unordered_map<ArkBinkPlayerHandle,_smart_ptr<ArkBinkPlayer>>;
	
	std::unordered_map<ArkBinkPlayerHandle,_smart_ptr<ArkBinkPlayer>> m_players;
	std::vector<ArkBinkPlayer *> m_fullscreenPlayers;
	std::vector<ArkBinkPlayer *> m_backgroundPlayers;
	std::vector<ArkBinkPlayer *> m_playersToRender;
	
	struct SDeletionEntry // Id=801077E Size=16
	{
		ArkBinkPlayer *pPlayer;
		int nDelay;
	};

	std::vector<ArkBinkManager::SDeletionEntry> m_deletionQueue;
	unsigned m_threads[4];
	int m_threadCount;
	CryCriticalSection m_playersLock;
	
	ArkBinkManager();
	virtual ~ArkBinkManager();
	void EF_UpdateTextureMovie(ArkBinkPlayer *_pPlayer) { FEF_UpdateTextureMovie(this,_pPlayer); }
	virtual void UseTelemetry(void *_pApi, unsigned _binkMask) const;
	virtual void EF_Update(int *_nFullscreenMovieCount);
	virtual void EF_Render();
	virtual ArkBinkPlayerHandle MT_LoadMovie(const char *_szPath, int16_t _instanceId, EArkBinkMovieType _type, EArkBinkLoadFlags _flags);
	virtual void MT_ReleaseMovie(ArkBinkPlayerHandle _handle);
	virtual bool MT_StartMovie(ArkBinkPlayerHandle _handle);
	virtual bool MT_StopMovie(ArkBinkPlayerHandle _handle);
	virtual bool MT_PauseMovie(ArkBinkPlayerHandle _handle, bool _bPaused);
	virtual bool MT_IsMoviePlaying(ArkBinkPlayerHandle _handle) const;
	virtual bool MT_GetMoviePlaybackInfo(ArkBinkPlayerHandle _handle, ArkBinkPlaybackInfo &_out_info) const;
	virtual bool MT_IsFullScreenMoviePlaying() const;
	virtual void MT_PauseMovies(const bool _bPause) const;
	ArkBinkPlayer *RT_LoadMovie(const char *_szPath, int16_t _instanceId, EArkBinkMovieType _type, EArkBinkLoadFlags _flags) { return FRT_LoadMovie(this,_szPath,_instanceId,_type,_flags); }
	void RT_RenderInternal(ArkBinkPlayer *_pPlayer, int _frame) { FRT_RenderInternal(this,_pPlayer,_frame); }
	ArkBinkPlayer const *GetPlayer(ArkBinkPlayerHandle _handle) const { return FGetPlayerOv0(this,_handle); }
	void DoFrameAsync(BINK *_hBink) { FDoFrameAsync(this,_hBink); }
	ArkBinkRenderer *GetCurrentRenderer() { return FGetCurrentRenderer(this); }
	static void OnAudioVolumeChange(ICVar *_pCVar, bool _bDialog) { FOnAudioVolumeChange(_pCVar,_bDialog); }
	void UpdateAudioVolumes(unsigned _trackID, unsigned _volume) { FUpdateAudioVolumes(this,_trackID,_volume); }
	virtual void OnSystemEvent(ESystemEvent _event, uint64_t _wparam, uint64_t _lparam);
	ArkBinkPlayerHandle CreatePlayer(const char *_szPath, int16_t _instanceId, EArkBinkMovieType _type, EArkBinkLoadFlags _flags) { return FCreatePlayer(this,_szPath,_instanceId,_type,_flags); }
	void QueuePlayerDelete(ArkBinkPlayer *_pPlayer) { FQueuePlayerDelete(this,_pPlayer); }
	
#if 0
	ArkBinkPlayer *GetPlayer(ArkBinkPlayerHandle arg0);
	void SetPlayerInitialVolumes(ArkBinkPlayer *arg0);
	ArkBinkPlayer *CreatePlayerInternal(const char *arg0, EArkBinkMovieType arg1, EArkBinkLoadFlags arg2);
#endif
	
	static inline auto FEF_UpdateTextureMovie = PreyFunction<void(ArkBinkManager *const _this, ArkBinkPlayer *_pPlayer)>(0xECD4E0);
	static inline auto FUseTelemetry = PreyFunction<void(ArkBinkManager const *const _this, void *_pApi, unsigned _binkMask)>(0xA13080);
	static inline auto FEF_Update = PreyFunction<void(ArkBinkManager *const _this, int *_nFullscreenMovieCount)>(0xECD150);
	static inline auto FEF_Render = PreyFunction<void(ArkBinkManager *const _this)>(0xECD0B0);
	static inline auto FMT_LoadMovie = PreyFunction<ArkBinkPlayerHandle(ArkBinkManager *const _this, const char *_szPath, int16_t _instanceId, EArkBinkMovieType _type, EArkBinkLoadFlags _flags)>(0xECD8A0);
	static inline auto FMT_ReleaseMovie = PreyFunction<void(ArkBinkManager *const _this, ArkBinkPlayerHandle _handle)>(0xECDA60);
	static inline auto FMT_StartMovie = PreyFunction<bool(ArkBinkManager *const _this, ArkBinkPlayerHandle _handle)>(0xECDB00);
	static inline auto FMT_StopMovie = PreyFunction<bool(ArkBinkManager *const _this, ArkBinkPlayerHandle _handle)>(0xECDB80);
	static inline auto FMT_PauseMovie = PreyFunction<bool(ArkBinkManager *const _this, ArkBinkPlayerHandle _handle, bool _bPaused)>(0xECD950);
	static inline auto FMT_IsMoviePlaying = PreyFunction<bool(ArkBinkManager const *const _this, ArkBinkPlayerHandle _handle)>(0xECD840);
	static inline auto FMT_GetMoviePlaybackInfo = PreyFunction<bool(ArkBinkManager const *const _this, ArkBinkPlayerHandle _handle, ArkBinkPlaybackInfo &_out_info)>(0xECD760);
	static inline auto FMT_IsFullScreenMoviePlaying = PreyFunction<bool(ArkBinkManager const *const _this)>(0xECD7D0);
	static inline auto FMT_PauseMovies = PreyFunction<void(ArkBinkManager const *const _this, const bool _bPause)>(0xECD9D0);
	static inline auto FRT_LoadMovie = PreyFunction<ArkBinkPlayer *(ArkBinkManager *const _this, const char *_szPath, int16_t _instanceId, EArkBinkMovieType _type, EArkBinkLoadFlags _flags)>(0xECDE40);
	static inline auto FRT_RenderInternal = PreyFunction<void(ArkBinkManager *const _this, ArkBinkPlayer *_pPlayer, int _frame)>(0xECDEF0);
	static inline auto FGetPlayerOv0 = PreyFunction<ArkBinkPlayer const *(ArkBinkManager const *const _this, ArkBinkPlayerHandle _handle)>(0xECD690);
	static inline auto FDoFrameAsync = PreyFunction<void(ArkBinkManager *const _this, BINK *_hBink)>(0xECD090);
	static inline auto FGetCurrentRenderer = PreyFunction<ArkBinkRenderer *(ArkBinkManager *const _this)>(0x5BFB50);
	static inline auto FOnAudioVolumeChange = PreyFunction<void(ICVar *_pCVar, bool _bDialog)>(0xECDC00);
	static inline auto FUpdateAudioVolumes = PreyFunction<void(ArkBinkManager *const _this, unsigned _trackID, unsigned _volume)>(0xECDF00);
	static inline auto FOnSystemEvent = PreyFunction<void(ArkBinkManager *const _this, ESystemEvent _event, uint64_t _wparam, uint64_t _lparam)>(0xECDC60);
	static inline auto FCreatePlayer = PreyFunction<ArkBinkPlayerHandle(ArkBinkManager *const _this, const char *_szPath, int16_t _instanceId, EArkBinkMovieType _type, EArkBinkLoadFlags _flags)>(0xECCBA0);
	static inline auto FQueuePlayerDelete = PreyFunction<void(ArkBinkManager *const _this, ArkBinkPlayer *_pPlayer)>(0xECDD50);
};

