// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkPADialogManager.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>
//#include <Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h>

class ArkConversation;
struct ICVar;
struct IEntity;
struct SAudioRequestInfo;
struct SDialogParams;

class ArkPADialogTrigger;

// Prey/GameDll/ark/dialog/arkpadialogmanager.h
struct SSpeakerEntity // Id=8015D29 Size=8
{
	unsigned entityId;
	float scale;

#if 0
	bool operator==(const unsigned arg0) const;
#endif
};

// Header: FromCpp
// Prey/GameDll/ark/dialog/arkpadialogmanager.h
class CArkPADialogManager : public IArkPADialogManager // Id=8015D23 Size=2432
{
public:
	enum class EArkPAChannels
	{
		global = 0,
		total = 4,
	};

	std::array<ArkSpeaker<ArkDialogPlayerPA>,4> m_speakers;
	std::array<std::vector<SSpeakerEntity>,4> m_entities;
	
	using TQueuedTrigger = std::pair<unsigned __int64,ArkFlowNodeDialogTrigger<ArkPADialogTrigger> *>;
	
	std::array<TQueuedTrigger,4> m_queuedTriggers;
	unsigned m_nEnvironmentId;
	unsigned m_nChimeId;
	unsigned m_nInterferenceId;
	unsigned m_nInterruptId;
	ICVar *m_pChannelDebug;
	static int pa_drawDebug;
	
	CArkPADialogManager();
	void Update(const float _frameTime) { FUpdate(this,_frameTime); }
	void Reset() { FReset(this); }
	virtual void PlayDialog(uint8_t _channelId, SDialogParams &_params);
	bool PlayPAAnnouncement(ArkFlowNodeDialogTrigger<ArkPADialogTrigger> &_PATrigger, uint64_t _ruleId, uint8_t _channelId, EArkChimeType _chimeType) { return FPlayPAAnnouncement(this,_PATrigger,_ruleId,_channelId,_chimeType); }
	void Stop(uint8_t _channelId, bool _bInterrupt) { FStop(this,_channelId,_bInterrupt); }
	void Pause(uint8_t _channelId, bool _bPaused) { FPause(this,_channelId,_bPaused); }
	void SetDuckAudio(uint8_t _channelId, bool _bEnable) { FSetDuckAudio(this,_channelId,_bEnable); }
	void RegisterEntity(uint8_t _channelId, unsigned _entityId, float _scale) { FRegisterEntity(this,_channelId,_entityId,_scale); }
	void UnregisterEntity(uint8_t _channelId, unsigned _entityId) { FUnregisterEntity(this,_channelId,_entityId); }
	bool IsChannelEmpty(uint8_t _channelId) const { return FIsChannelEmpty(this,_channelId); }
	std::vector<IEntity *> GetClosestSpeakers(const uint8_t _channelId, const unsigned _count) const { return FGetClosestSpeakers(this,_channelId,_count); }
	void ClearQueuedAnnouncement(ArkFlowNodeDialogTrigger<ArkPADialogTrigger> const *_pPATrigger, uint8_t _channelId) { FClearQueuedAnnouncement(this,_pPATrigger,_channelId); }
	static bool ShouldApplySpeakerAudioEffect(IEntity const *_pEntity) { return FShouldApplySpeakerAudioEffect(_pEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this,_ser); }
	void PostSerialize() { FPostSerialize(this); }
	static void OnChimeComplete(SAudioRequestInfo const *const pAudioRequestInfo) { FOnChimeComplete(pAudioRequestInfo); }
	
#if 0
	ArkConversation *TriggerRule(uint64_t arg0, uint8_t arg1);
	std::vector<SSpeakerEntity> const &GetSpeakerEntities(uint8_t arg0) const;
	unsigned GetEnvironmentId() const;
	void PlayQueuedAnnouncement(uint8_t arg0);
#endif
	
	static inline auto FUpdate = PreyFunction<void(CArkPADialogManager *const _this, const float _frameTime)>(0x148C5E0);
	static inline auto FReset = PreyFunction<void(CArkPADialogManager *const _this)>(0x148C0C0);
	static inline auto FPlayDialog = PreyFunction<void(CArkPADialogManager *const _this, uint8_t _channelId, SDialogParams &_params)>(0x148BCB0);
	static inline auto FPlayPAAnnouncement = PreyFunction<bool(CArkPADialogManager *const _this, ArkFlowNodeDialogTrigger<ArkPADialogTrigger> &_PATrigger, uint64_t _ruleId, uint8_t _channelId, EArkChimeType _chimeType)>(0x148BCD0);
	static inline auto FStop = PreyFunction<void(CArkPADialogManager *const _this, uint8_t _channelId, bool _bInterrupt)>(0x148C360);
	static inline auto FPause = PreyFunction<void(CArkPADialogManager *const _this, uint8_t _channelId, bool _bPaused)>(0x148BC40);
	static inline auto FSetDuckAudio = PreyFunction<void(CArkPADialogManager *const _this, uint8_t _channelId, bool _bEnable)>(0x148C180);
	static inline auto FRegisterEntity = PreyFunction<void(CArkPADialogManager *const _this, uint8_t _channelId, unsigned _entityId, float _scale)>(0x148C060);
	static inline auto FUnregisterEntity = PreyFunction<void(CArkPADialogManager *const _this, uint8_t _channelId, unsigned _entityId)>(0x148C580);
	static inline auto FIsChannelEmpty = PreyFunction<bool(CArkPADialogManager const *const _this, uint8_t _channelId)>(0x148BA70);
	static inline auto FGetClosestSpeakers = PreyFunction<std::vector<IEntity *>(CArkPADialogManager const *const _this, const uint8_t _channelId, const unsigned _count)>(0x148B870);
	static inline auto FClearQueuedAnnouncement = PreyFunction<void(CArkPADialogManager *const _this, ArkFlowNodeDialogTrigger<ArkPADialogTrigger> const *_pPATrigger, uint8_t _channelId)>(0x148B840);
	static inline auto FShouldApplySpeakerAudioEffect = PreyFunction<bool(IEntity const *_pEntity)>(0x148C1A0);
	static inline auto FSerialize = PreyFunction<void(CArkPADialogManager *const _this, TSerialize _ser)>(0x148C130);
	static inline auto FPostSerialize = PreyFunction<void(CArkPADialogManager *const _this)>(0x148C020);
	static inline auto FOnChimeComplete = PreyFunction<void(SAudioRequestInfo const *const pAudioRequestInfo)>(0x148BA90);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/dialog/IArkPADialogManager.h>
#include <Prey/GameDll/ark/dialog/arkflownodedialogtrigger.h>
#include <Prey/GameDll/ark/dialog/arkspeaker.h>

class ArkConversation;
enum class EArkChimeType;
struct ICVar;
struct IEntity;
struct SAudioRequestInfo;
struct SDialogParams;

// SSpeakerEntity
// Header:  Prey/GameDll/ark/dialog/ArkPADialogManager.h
struct SSpeakerEntity
{ // Size=8 (0x8)
	unsigned entityId;
	float scale;

#if 0
	SSpeakerEntity(unsigned _arg0_, float _arg1_);
	bool operator==(const unsigned _arg0_) const;
#endif
};

// CArkPADialogManager
// Header:  Prey/GameDll/ark/dialog/ArkPADialogManager.h
class CArkPADialogManager : public IArkPADialogManager
{ // Size=2432 (0x980)
public:
	enum class EArkPAChannels
	{
		global = 0,
		total = 4,
	};

	using TQueuedTrigger = std::pair<uint64_t, ArkFlowNodeDialogTrigger<ArkPADialogTrigger>*>;

	std::array<ArkSpeaker<ArkDialogPlayerPA>, 4> m_speakers;
	std::array<std::vector<SSpeakerEntity>, 4> m_entities;
	std::array<std::pair<uint64_t, ArkFlowNodeDialogTrigger<ArkPADialogTrigger>*>, 4> m_queuedTriggers;
	unsigned m_nEnvironmentId;
	unsigned m_nChimeId;
	unsigned m_nInterferenceId;
	unsigned m_nInterruptId;
	ICVar* m_pChannelDebug;
	static inline auto pa_drawDebug = PreyGlobal<int>(0x2D6D1A0);

	CArkPADialogManager();
	virtual ~CArkPADialogManager();
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void Reset() { FReset(this); }
	virtual void PlayDialog(uint8_t _channelId, SDialogParams& _params);
	bool PlayPAAnnouncement(ArkFlowNodeDialogTrigger<ArkPADialogTrigger>& _PATrigger, uint64_t _ruleId, uint8_t _channelId, EArkChimeType _chimeType) { return FPlayPAAnnouncement(this, _PATrigger, _ruleId, _channelId, _chimeType); }
	void Stop(uint8_t _channelId, bool _bInterrupt) { FStop(this, _channelId, _bInterrupt); }
	void Pause(uint8_t _channelId, bool _bPaused) { FPause(this, _channelId, _bPaused); }
	void SetDuckAudio(uint8_t _channelId, bool _bEnable) { FSetDuckAudio(this, _channelId, _bEnable); }
	void RegisterEntity(uint8_t _channelId, unsigned _entityId, float _scale) { FRegisterEntity(this, _channelId, _entityId, _scale); }
	void UnregisterEntity(uint8_t _channelId, unsigned _entityId) { FUnregisterEntity(this, _channelId, _entityId); }
	bool IsChannelEmpty(uint8_t _channelId) const { return FIsChannelEmpty(this, _channelId); }
	std::vector<IEntity*> GetClosestSpeakers(const uint8_t _channelId, const unsigned _count) const { alignas(std::vector<IEntity*>) std::byte _return_buf_[sizeof(std::vector<IEntity*>)]; return *FGetClosestSpeakers(this, reinterpret_cast<std::vector<IEntity*>*>(_return_buf_), _channelId, _count); }
	void ClearQueuedAnnouncement(const ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* _pPATrigger, uint8_t _channelId) { FClearQueuedAnnouncement(this, _pPATrigger, _channelId); }
	static bool ShouldApplySpeakerAudioEffect(const IEntity* _pEntity) { return FShouldApplySpeakerAudioEffect(_pEntity); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	static void OnChimeComplete(const SAudioRequestInfo* const pAudioRequestInfo) { FOnChimeComplete(pAudioRequestInfo); }

#if 0
	ArkConversation* TriggerRule(uint64_t _arg0_, uint8_t _arg1_);
	const std::vector<SSpeakerEntity>& GetSpeakerEntities(uint8_t _arg0_) const;
	unsigned GetEnvironmentId() const;
	void PlayQueuedAnnouncement(uint8_t _arg0_);
#endif

	static inline auto FCArkPADialogManagerOv1 = PreyFunction<void(CArkPADialogManager* const _this)>(0x15A2F80);
	static inline auto FUpdate = PreyFunction<void(CArkPADialogManager* const _this, const float _frameTime)>(0x15A4290);
	static inline auto FReset = PreyFunction<void(CArkPADialogManager* const _this)>(0x15A3D40);
	static inline auto FPlayDialog = PreyFunction<void(CArkPADialogManager* const _this, uint8_t _channelId, SDialogParams& _params)>(0x15A3950);
	static inline auto FPlayPAAnnouncement = PreyFunction<bool(CArkPADialogManager* const _this, ArkFlowNodeDialogTrigger<ArkPADialogTrigger>& _PATrigger, uint64_t _ruleId, uint8_t _channelId, EArkChimeType _chimeType)>(0x15A3970);
	static inline auto FStop = PreyFunction<void(CArkPADialogManager* const _this, uint8_t _channelId, bool _bInterrupt)>(0x15A3FE0);
	static inline auto FPause = PreyFunction<void(CArkPADialogManager* const _this, uint8_t _channelId, bool _bPaused)>(0x15A38E0);
	static inline auto FSetDuckAudio = PreyFunction<void(CArkPADialogManager* const _this, uint8_t _channelId, bool _bEnable)>(0x15A3E00);
	static inline auto FRegisterEntity = PreyFunction<void(CArkPADialogManager* const _this, uint8_t _channelId, unsigned _entityId, float _scale)>(0x15A3CE0);
	static inline auto FUnregisterEntity = PreyFunction<void(CArkPADialogManager* const _this, uint8_t _channelId, unsigned _entityId)>(0x15A4200);
	static inline auto FIsChannelEmpty = PreyFunction<bool(const CArkPADialogManager* const _this, uint8_t _channelId)>(0x15A3710);
	static inline auto FGetClosestSpeakers = PreyFunction<std::vector<IEntity*>*(const CArkPADialogManager* const _this, std::vector<IEntity*>* _return_value_, const uint8_t _channelId, const unsigned _count)>(0x15A3500);
	static inline auto FClearQueuedAnnouncement = PreyFunction<void(CArkPADialogManager* const _this, const ArkFlowNodeDialogTrigger<ArkPADialogTrigger>* _pPATrigger, uint8_t _channelId)>(0x15A34D0);
	static inline auto FShouldApplySpeakerAudioEffect = PreyFunction<bool(const IEntity* _pEntity)>(0x15A3E20);
	static inline auto FSerialize = PreyFunction<void(CArkPADialogManager* const _this, TSerialize _ser)>(0x15A3DB0);
	static inline auto FPostSerialize = PreyFunction<void(CArkPADialogManager* const _this)>(0x15A3CA0);
	static inline auto FOnChimeComplete = PreyFunction<void(const SAudioRequestInfo* const pAudioRequestInfo)>(0x15A3730);
};
#endif // !MOONCRASH
