// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
struct IEntity;
struct SDialogParams;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkDialogPlayerPA.h
class ArkDialogPlayerPA : public ArkDialogPlayer // Id=8015D36 Size=304
{
public:
	std::array<unsigned int,8> m_activeSpeakers;
	uint64_t m_dialogId;
	uint8_t m_channelId;
	
	ArkDialogPlayerPA(ArkSpeakerBase *const _pSpeaker);
	bool Play(SDialogParams const &_params) { return FPlay(this,_params); }
	void Stop(bool _bInvalidate) { FStop(this,_bInvalidate); }
	void OnGamePause(bool _bPause) { FOnGamePause(this,_bPause); }
	void SetDuckAudio(bool _bEnable) { FSetDuckAudio(this,_bEnable); }
	virtual EArkDialogPlayerType GetType() const;
	virtual std::vector<SSubtitleAudioData> GetSubtitleAudioData() const;
	bool IsPlayingSpeaker(unsigned _entityId) const { return FIsPlayingSpeaker(this,_entityId); }
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger &_trigger);
	virtual void OnDialogComplete(ArkDialogAudioTrigger const *_pTrigger, const bool _bAudioComplete);
	void UpdateAudioLevels(IEntity &_entity, unsigned _nEnvironmentId, unsigned _proxyId) { FUpdateAudioLevels(this,_entity,_nEnvironmentId,_proxyId); }
	
#if 0
	void SetChannel(const uint8_t arg0);
#endif
	
	static inline auto FPlay = PreyFunction<bool(ArkDialogPlayerPA *const _this, SDialogParams const &_params)>(0x14864B0);
	static inline auto FStop = PreyFunction<void(ArkDialogPlayerPA *const _this, bool _bInvalidate)>(0x14867A0);
	static inline auto FOnGamePause = PreyFunction<void(ArkDialogPlayerPA *const _this, bool _bPause)>(0x14863D0);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkDialogPlayerPA *const _this, bool _bEnable)>(0x14866C0);
	static inline auto FGetSubtitleAudioData = PreyFunction<std::vector<SSubtitleAudioData>(ArkDialogPlayerPA const *const _this)>(0x1486040);
	static inline auto FIsPlayingSpeaker = PreyFunction<bool(ArkDialogPlayerPA const *const _this, unsigned _entityId)>(0x1486340);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayerPA *const _this, ArkDialogAudioTrigger &_trigger)>(0x1486510);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkDialogPlayerPA *const _this, ArkDialogAudioTrigger const *_pTrigger, const bool _bAudioComplete)>(0x1486370);
	static inline auto FUpdateAudioLevels = PreyFunction<void(ArkDialogPlayerPA *const _this, IEntity &_entity, unsigned _nEnvironmentId, unsigned _proxyId)>(0x14868D0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/dialog/ArkDialogPlayer.h>
#include <Prey/GameDll/ark/dialog/SSubtitleAudioData.h>

class ArkDialogAudioTrigger;
class ArkSpeakerBase;
enum class EArkDialogPlayerType;
struct IEntity;
struct SDialogParams;

// ArkDialogPlayerPA
// Header:  Prey/GameDll/ark/dialog/ArkDialogPlayerPA.h
class ArkDialogPlayerPA : public ArkDialogPlayer
{ // Size=304 (0x130)
public:
	std::array<unsigned int, 8> m_activeSpeakers;
	uint64_t m_dialogId;
	uint8_t m_channelId;

	ArkDialogPlayerPA(ArkSpeakerBase* const _pSpeaker);
	bool Play(const SDialogParams& _params) { return FPlay(this, _params); }
	void Stop(bool _bInvalidate) { FStop(this, _bInvalidate); }
	void OnGamePause(bool _bPause) { FOnGamePause(this, _bPause); }
	void SetDuckAudio(bool _bEnable) { FSetDuckAudio(this, _bEnable); }
	virtual EArkDialogPlayerType GetType() const;
	virtual std::vector<SSubtitleAudioData> GetSubtitleAudioData() const;
	bool IsPlayingSpeaker(unsigned _entityId) const { return FIsPlayingSpeaker(this, _entityId); }
	virtual bool PlayTriggerInternal(ArkDialogAudioTrigger& _trigger);
	virtual void OnDialogComplete(const ArkDialogAudioTrigger* _pTrigger, const bool _bAudioComplete);
	void UpdateAudioLevels(IEntity& _entity, unsigned _nEnvironmentId, unsigned _proxyId) { FUpdateAudioLevels(this, _entity, _nEnvironmentId, _proxyId); }

#if 0
	void SetChannel(const uint8_t _arg0_);
#endif

	static inline auto FArkDialogPlayerPAOv2 = PreyFunction<void(ArkDialogPlayerPA* const _this, ArkSpeakerBase* const _pSpeaker)>(0x159D830);
	static inline auto FPlay = PreyFunction<bool(ArkDialogPlayerPA* const _this, const SDialogParams& _params)>(0x159DD30);
	static inline auto FStop = PreyFunction<void(ArkDialogPlayerPA* const _this, bool _bInvalidate)>(0x159E020);
	static inline auto FOnGamePause = PreyFunction<void(ArkDialogPlayerPA* const _this, bool _bPause)>(0x159DC50);
	static inline auto FSetDuckAudio = PreyFunction<void(ArkDialogPlayerPA* const _this, bool _bEnable)>(0x159DF40);
	static inline auto FGetSubtitleAudioData = PreyFunction<std::vector<SSubtitleAudioData>*(const ArkDialogPlayerPA* const _this, std::vector<SSubtitleAudioData>* _return_value_)>(0x159D8C0);
	static inline auto FIsPlayingSpeaker = PreyFunction<bool(const ArkDialogPlayerPA* const _this, unsigned _entityId)>(0x159DBC0);
	static inline auto FPlayTriggerInternal = PreyFunction<bool(ArkDialogPlayerPA* const _this, ArkDialogAudioTrigger& _trigger)>(0x159DD90);
	static inline auto FOnDialogComplete = PreyFunction<void(ArkDialogPlayerPA* const _this, const ArkDialogAudioTrigger* _pTrigger, const bool _bAudioComplete)>(0x159DBF0);
	static inline auto FUpdateAudioLevels = PreyFunction<void(ArkDialogPlayerPA* const _this, IEntity& _entity, unsigned _nEnvironmentId, unsigned _proxyId)>(0x159E150);
};
#endif // !MOONCRASH
