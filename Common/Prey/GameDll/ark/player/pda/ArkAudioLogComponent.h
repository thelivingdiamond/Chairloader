// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/dialog/IArkConversationListener.h>

class ArkAudioLog;
class ArkConversation;

// Header: FromCpp
// Prey/GameDll/ark/player/pda/ArkAudioLogComponent.h
class ArkAudioLogComponent : public IArkConversationListener // Id=8016EF4 Size=128
{
public:
	std::vector<unsigned __int64> m_Collected;
	std::vector<unsigned __int64> m_PlayedAudioLogs;
	
	class UnheardAudioLog // Id=8016EF5 Size=16
	{
	public:
		uint64_t m_audioLogId;
		bool m_bAutoPlay;
		
#if 0
		void Serialize(TSerialize arg0);
		bool operator==(const uint64_t arg0) const;
#endif
	};

	std::vector<ArkAudioLogComponent::UnheardAudioLog> m_UnheardAudioLogs;
	ArkSimpleTimer m_loadingTimer;
	ArkConversation *m_pCurrentlyPlayingAudioLog;
	uint64_t m_currentlyPlayingConversationId;
	uint64_t m_currentlyPlayingAudioLogId;
	bool m_currentlyPlayingAudioLogAutoPlay;
	ArkAudioTrigger m_loadingTrigger;
	ArkAudioTrigger m_loadedTrigger;
	
	ArkAudioLogComponent();
	virtual ~ArkAudioLogComponent();
	void LoadConfig(XmlNodeRef _config) { FLoadConfig(this,_config); }
	void Update(float _frameTime) { FUpdate(this,_frameTime); }
	void Collect(const uint64_t _collectionId, bool _bAutoplay) { FCollect(this,_collectionId,_bAutoplay); }
	bool HasPlayedAudioLog(const uint64_t _id) const { return FHasPlayedAudioLog(this,_id); }
	uint64_t GetCurrentlyPlayingAudioLog() const { return FGetCurrentlyPlayingAudioLog(this); }
	void StopPlayingOrLoading() { FStopPlayingOrLoading(this); }
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	void PlayAudioLog(const uint64_t _audioLogId) { FPlayAudioLog(this,_audioLogId); }
	void PlayLastAudioLog() { FPlayLastAudioLog(this); }
	virtual void OnConversationComplete(const bool _bComplete);
	void PumpUnheardAudioLogQueue() { FPumpUnheardAudioLogQueue(this); }
	void ClearQueuedAutoPlayAudioLogs() { FClearQueuedAutoPlayAudioLogs(this); }
	void OnGameEnded() { FOnGameEnded(this); }
	bool PlayAudioLog_Internal(ArkAudioLog const &_audioLog) { return FPlayAudioLog_InternalOv0(this,_audioLog); }
	void PlayLoadingAudioLogSequence(uint64_t _audioLogId, bool _bResetTimer, bool _bAutoPlayed) { FPlayLoadingAudioLogSequence(this,_audioLogId,_bResetTimer,_bAutoPlayed); }
	void StopLoadingAudioLogSequence() { FStopLoadingAudioLogSequence(this); }
	
#if 0
	void CollectAll();
	bool HasAudioLog(const uint64_t arg0) const;
	std::vector<unsigned __int64> const &GetCollected() const;
	bool IsLoading();
	bool PlayAudioLog_Internal(const uint64_t arg0);
	void SendAudioLogPlaybackCompleteEvent(const bool arg0);
#endif
	
	static inline auto FLoadConfig = PreyFunction<void(ArkAudioLogComponent *const _this, XmlNodeRef _config)>(0x15B22D0);
	static inline auto FUpdate = PreyFunction<void(ArkAudioLogComponent *const _this, float _frameTime)>(0x15B2F90);
	static inline auto FCollect = PreyFunction<void(ArkAudioLogComponent *const _this, const uint64_t _collectionId, bool _bAutoplay)>(0x15B1F50);
	static inline auto FHasPlayedAudioLog = PreyFunction<bool(ArkAudioLogComponent const *const _this, const uint64_t _id)>(0x15B37D0);
	static inline auto FGetCurrentlyPlayingAudioLog = PreyFunction<uint64_t(ArkAudioLogComponent const *const _this)>(0x155AD50);
	static inline auto FStopPlayingOrLoading = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B2F00);
	static inline auto FReset = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B2BF0);
	static inline auto FSerialize = PreyFunction<void(ArkAudioLogComponent *const _this, TSerialize _ser)>(0x15B2C50);
	static inline auto FPostSerialize = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B2960);
	static inline auto FPlayAudioLog = PreyFunction<void(ArkAudioLogComponent *const _this, const uint64_t _audioLogId)>(0x15B24F0);
	static inline auto FPlayLastAudioLog = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B2710);
	static inline auto FOnConversationComplete = PreyFunction<void(ArkAudioLogComponent *const _this, const bool _bComplete)>(0x15B23B0);
	static inline auto FPumpUnheardAudioLogQueue = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B2A00);
	static inline auto FClearQueuedAutoPlayAudioLogs = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B1EA0);
	static inline auto FOnGameEnded = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B24E0);
	static inline auto FPlayAudioLog_InternalOv0 = PreyFunction<bool(ArkAudioLogComponent *const _this, ArkAudioLog const &_audioLog)>(0x15B2500);
	static inline auto FPlayLoadingAudioLogSequence = PreyFunction<void(ArkAudioLogComponent *const _this, uint64_t _audioLogId, bool _bResetTimer, bool _bAutoPlayed)>(0x15B2770);
	static inline auto FStopLoadingAudioLogSequence = PreyFunction<void(ArkAudioLogComponent *const _this)>(0x15B2D80);
};

