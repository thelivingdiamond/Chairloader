// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/attention/ArkAttentionTag.h>
#include <Prey/GameDll/ark/attention/ArkAttentionLevelChange.h>
#include <Prey/ArkCommon/ArkInterval.h>

class ArkAttentionLevelsChangedListener;
class ArkAttentiveSubject;
class ArkComplexAttentionObject;
struct ArkNoiseAttentionParams;
class ArkSimpleAttentionObject;
class XmlNodeRef;

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkAttentionManager.h
class ArkAttentionManager // Id=8014DAD Size=1200
{
public:
	struct TopAttentionTarget // Id=8014E0B Size=16
	{
		unsigned m_entityId;
		EArkAttentionLevel m_attentionLevel;
		EArkDisposition m_disposition;
		float m_distanceSquared;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct AttentionLevelData // Id=8014E0C Size=12
	{
		ArkInterval<float> m_interval;
		float m_drainRate;
	};

	using LevelDataArray = std::array<ArkAttentionManager::AttentionLevelData,5>;
	
	struct AttentionIncrease // Id=8014E0D Size=8
	{
		float m_gain;
		EArkAttentionLevel m_minimumAttentionLevel;
	};

	struct HearingData // Id=8014E0E Size=64
	{
		using AttentionIncreaseMap = std::unordered_map<unsigned __int64,ArkAttentionManager::AttentionIncrease>;
		
		std::unordered_map<unsigned __int64,ArkAttentionManager::AttentionIncrease> m_attentionIncreases;
	};

	struct VisionData // Id=8014E0F Size=20
	{
		using FloatArray = std::array<float,5>;
		
		std::array<float,5> m_accumulationRates;
	};

	struct RoomData // Id=8014E10 Size=80
	{
		using FloatArray = std::array<float,5>;
		
		std::array<float,5> m_startRoomGains;
		std::array<float,5> m_startContainerGains;
		std::array<float,5> m_continueRoomAccumulationRates;
		std::array<float,5> m_continueContainerAccumulationRates;
	};

	struct ProxyData // Id=8014E11 Size=4
	{
		float m_followTime;
	};

	struct SurpriseData // Id=8014E12 Size=12
	{
		EArkAttentionLevel m_fromLevel;
		EArkAttentionLevel m_toLevel;
		float m_time_s;
	};

	struct OnDamagedData // Id=8014E13 Size=4
	{
		EArkAttentionLevel m_minimumAttentionLevel;
	};

	struct SimpleAttentionModel // Id=8014E14 Size=4
	{
		float m_timeout;
	};

	struct ComplexAttentionModel // Id=8014E15 Size=248
	{
		std::array<ArkAttentionManager::AttentionLevelData,5> m_levels;
		ArkAttentionManager::HearingData m_hearingData;
		ArkAttentionManager::VisionData m_visionData;
		ArkAttentionManager::RoomData m_roomData;
		ArkAttentionManager::ProxyData m_proxyData;
		ArkAttentionManager::OnDamagedData m_onDamagedData;
		ArkAttentionManager::SurpriseData m_surpriseData;
	};

	struct AttentionTargetData // Id=8014E16 Size=12
	{
		float m_relativeClosenessToSwitchTopTargetSqrd;
		float m_simpleDamageTimer;
		float m_complexDamageTimer;
	};

	struct AttentionModel // Id=8014E17 Size=272
	{
		ArkAttentionManager::SimpleAttentionModel m_simple;
		ArkAttentionManager::ComplexAttentionModel m_complex;
		ArkAttentionManager::AttentionTargetData m_attentionTargetData;
		
		ArkAttentionManager::AttentionModel &operator=(ArkAttentionManager::AttentionModel *_other) { return FoperatorEq(this,_other); }
		
		static inline auto FoperatorEq = PreyFunction<ArkAttentionManager::AttentionModel &(ArkAttentionManager::AttentionModel *const _this, ArkAttentionManager::AttentionModel *_other)>(0x13E4180);
	};

	struct ComplexHearingInput // Id=8014E18 Size=40
	{
		ArkAttentionTag m_attentionTag;
		float m_gain;
		boost::optional<enum EArkAttentionLevel> m_optMinimumAttentionLevel;
		Vec3 m_attentionPosition;
		bool m_bIsDangerNoise;
		
		ComplexHearingInput(ArkAttentionTag _attentionTag, float _gain, boost::optional<enum EArkAttentionLevel> _optMinimumAttentionLevel, Vec3 const &_attentionPosition, bool _bIsDangerNoise);
		bool operator>(ArkAttentionManager::ComplexHearingInput const &_other) const { return FoperatorGreater(this,_other); }
		
#if 0
		void Serialize(TSerialize arg0);
#endif
		
		static inline auto FoperatorGreater = PreyFunction<bool(ArkAttentionManager::ComplexHearingInput const *const _this, ArkAttentionManager::ComplexHearingInput const &_other)>(0x13E43C0);
	};

	struct ComplexVisionInput // Id=8014E1D Size=16
	{
		ArkAttentionTag m_attentionTag;
		float m_magnitude;
		
		ComplexVisionInput(ArkAttentionTag _attentionTag, float _magnitude);
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct ComplexRoomInput // Id=8014E1E Size=16
	{
		ArkAttentionTag m_attentionTag;
		float m_magnitude;
		bool m_bStart;
		bool m_bSameAreaContainer;
		
		ComplexRoomInput(ArkAttentionTag _attentionTag, float _magnitude, bool _bStart, bool _bSameAreaContainer);
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct SimpleAttentionInfo // Id=8014E1F Size=8
	{
		float m_timer;
		float m_lastDamageTimeStamp;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct ComplexAttentionInfo // Id=8014E20 Size=48
	{
		ArkAttentionTag m_attentionTag;
		EArkAttentionChangeReason m_lastChangeReason;
		EArkAttentionChangeReason m_pendingChangeReason;
		EArkAttentionLevel m_level;
		float m_value;
		EArkAttentionLevel m_minimumLevel;
		EArkAttentionLevel m_maximumLevel;
		uint64_t m_drainLockCount;
		float m_lastDamageTimeStamp;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct ComplexAttentionGain // Id=8014E21 Size=48
	{
		ArkAttentionTag m_attentionTag;
		float m_value;
		boost::optional<enum EArkAttentionLevel> m_optMinLevel;
		EArkAttentionLevel m_maxLevel;
		boost::optional<Vec3> m_optAttentionPos;
		EArkAttentionChangeReason m_reason;
	};

	struct ComplexAttentionProxyUpdate // Id=8014E22 Size=32
	{
		uint64_t m_attentiveSubjectIndex;
		uint64_t m_complexAttentionObjectIndex;
		boost::optional<Vec3> m_optAttentionPosition;
	};

	struct ComplexAttentionProxyUpdateNotification // Id=8014E23 Size=16
	{
		uint64_t m_attentiveSubjectIndex;
		uint64_t m_complexAttentionObjectIndex;
	};

	struct ComplexAttentionProxy // Id=8014E24 Size=32
	{
		Vec3 m_position;
		boost::optional<Vec3> m_optVerifiedPosition;
		float m_followTimer;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct ComplexAttentionSurpriseInfo // Id=8014E25 Size=8
	{
		float m_timer;
		bool m_bSurprising;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	struct BestAttentionTargetInfo // Id=8014E26 Size=28
	{
		ArkAttentionManager::TopAttentionTarget m_topAttentionTarget;
		EArkAttentionChangeReason m_lastChangeReason;
		bool m_bIsSuprising;
		bool m_bEncounteredEtherDuplicate;
		float m_lastDamageTimestamp;
	};

	using AttentionLevelChangeVector = std::vector<ArkAttentionLevelChange>;
	using AttentionLevelsChangedListenerMap = std::unordered_multimap<unsigned int,ArkAttentionLevelsChangedListener *,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,ArkAttentionLevelsChangedListener *> > >;
	using AttentionModelVector = std::vector<ArkAttentionManager::AttentionModel>;
	using AttentiveSubjectVector = std::vector<ArkAttentiveSubject *>;
	using BestAttentionTargetInfoVector = std::vector<ArkAttentionManager::BestAttentionTargetInfo>;
	using BoolVector = std::vector<bool>;
	using ComplexAttentionGainVector = std::vector<ArkAttentionManager::ComplexAttentionGain>;
	using ComplexAttentionInfoVector = std::vector<ArkAttentionManager::ComplexAttentionInfo>;
	using ComplexAttentionObjectVector = std::vector<ArkComplexAttentionObject *>;
	using ComplexAttentionProxyUpdateNotificationVector = std::vector<ArkAttentionManager::ComplexAttentionProxyUpdateNotification>;
	using ComplexAttentionProxyUpdateVector = std::vector<ArkAttentionManager::ComplexAttentionProxyUpdate>;
	using ComplexAttentionProxyVector = std::vector<ArkAttentionManager::ComplexAttentionProxy>;
	using ComplexAttentionSurpriseInfoVector = std::vector<ArkAttentionManager::ComplexAttentionSurpriseInfo>;
	using ComplexHearingInputVector = std::vector<ArkAttentionManager::ComplexHearingInput>;
	using ComplexRoomInputVector = std::vector<ArkAttentionManager::ComplexRoomInput>;
	using ComplexVisionInputVector = std::vector<ArkAttentionManager::ComplexVisionInput>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int,unsigned __int64>;
	using EntityIdVector = std::vector<unsigned int>;
	using FloatVector = std::vector<float>;
	using IndexVector = std::vector<unsigned __int64>;
	using SimpleAttentionInfoVector = std::vector<ArkAttentionManager::SimpleAttentionInfo>;
	using SimpleAttentionObjectVector = std::vector<ArkSimpleAttentionObject *>;
	using TopAttentionTargetVector = std::vector<ArkAttentionManager::TopAttentionTarget>;
	using UniqueIdToIndexMap = std::unordered_map<unsigned __int64,unsigned __int64>;
	using Vec3Vector = std::vector<Vec3>;
	
	std::unordered_map<unsigned int,unsigned __int64> m_attentiveSubjectIndexMap;
	std::unordered_map<unsigned int,unsigned __int64> m_simpleAttentionObjectIndexMap;
	std::unordered_map<unsigned int,unsigned __int64> m_complexAttentionObjectIndexMap;
	std::unordered_map<unsigned __int64,unsigned __int64> m_attentionModelIdMap;
	std::vector<ArkAttentionManager::AttentionModel> m_attentionModels;
	std::vector<unsigned __int64> m_freeAttentiveSubjectIndexes;
	std::vector<ArkAttentiveSubject *> m_attentiveSubjects;
	std::vector<unsigned int> m_attentiveSubjectEntityIds;
	std::vector<unsigned __int64> m_attentiveSubjectAttentionModelIndexes;
	std::vector<bool> m_attentiveSubjectUpdateFlags;
	std::vector<Vec3> m_attentiveSubjectPositions;
	std::vector<unsigned __int64> m_freeSimpleAttentionObjectIndexes;
	std::vector<ArkSimpleAttentionObject *> m_simpleAttentionObjects;
	std::vector<unsigned int> m_simpleAttentionObjectEntityIds;
	std::vector<Vec3> m_simpleAttentionObjectPositions;
	std::vector<unsigned __int64> m_freeComplexAttentionObjectIndexes;
	std::vector<ArkComplexAttentionObject *> m_complexAttentionObjects;
	std::vector<unsigned int> m_complexAttentionObjectEntityIds;
	std::vector<bool> m_simpleHearingInputs;
	std::vector<ArkAttentionManager::ComplexHearingInput> m_complexHearingInputs;
	std::vector<bool> m_simpleVisionInputs;
	std::vector<ArkAttentionManager::ComplexVisionInput> m_complexVisionInputs;
	std::vector<ArkAttentionManager::ComplexRoomInput> m_complexRoomInputs;
	std::vector<ArkAttentionManager::SimpleAttentionInfo> m_simpleAttentionInfo;
	std::vector<ArkAttentionManager::ComplexAttentionInfo> m_complexAttentionInfo;
	std::vector<ArkAttentionManager::ComplexAttentionProxy> m_complexAttentionProxies;
	std::vector<ArkAttentionManager::ComplexAttentionSurpriseInfo> m_complexAttentionSurpriseInfo;
	std::vector<unsigned __int64> m_simpleTopAttentionTargetStream;
	std::vector<unsigned __int64> m_complexTopAttentionTargetStream;
	std::vector<ArkAttentionManager::BestAttentionTargetInfo> m_bestAttentionTargets;
	std::vector<ArkAttentionManager::TopAttentionTarget> m_topAttentionTargets;
	std::vector<ArkAttentionManager::ComplexAttentionGain> m_complexAttentionGainBuffer;
	std::vector<ArkAttentionManager::ComplexAttentionProxyUpdate> m_complexAttentionProxyUpdates;
	std::vector<ArkAttentionManager::ComplexAttentionProxyUpdateNotification> m_complexAttentionProxyUpdateNotifications;
	std::vector<unsigned int> m_complexAttentionProxyUpdateBuffer;
	std::vector<ArkAttentionLevelChange> m_notifications;
	std::vector<ArkAttentionLevelChange> m_notificationBuffer;
	std::unordered_multimap<unsigned int,ArkAttentionLevelsChangedListener *,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,ArkAttentionLevelsChangedListener *> > > m_attentionLevelsChangedListenerMap;
	uint64_t m_nextAttentionTagValue;
	float m_masterComplexVisionGain;
	std::vector<float> m_complexVisionGains;
	std::vector<float> m_complexHearingGains;
	
	ArkAttentionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this,_bEnteringGameMode); }
	void RegisterAttentiveSubject(unsigned _entityId, ArkAttentiveSubject &_attentiveSubject) { FRegisterAttentiveSubject(this,_entityId,_attentiveSubject); }
	bool IsAttentiveSubjectRegistered(unsigned _entityId) const { return FIsAttentiveSubjectRegistered(this,_entityId); }
	void UnregisterAttentiveSubject(unsigned _entityId) { FUnregisterAttentiveSubject(this,_entityId); }
	void RegisterSimpleAttentionObject(unsigned _entityId, ArkSimpleAttentionObject &_simpleAttentionObject) { FRegisterSimpleAttentionObject(this,_entityId,_simpleAttentionObject); }
	bool IsSimpleAttentionObjectRegistered(unsigned _entityId) const { return FIsSimpleAttentionObjectRegistered(this,_entityId); }
	void UnregisterSimpleAttentionObject(unsigned _entityId) { FUnregisterSimpleAttentionObject(this,_entityId); }
	void RegisterComplexAttentionObject(unsigned _entityId, ArkComplexAttentionObject &_complexAttentionObject) { FRegisterComplexAttentionObject(this,_entityId,_complexAttentionObject); }
	bool IsComplexAttentionObjectRegistered(unsigned _entityId) const { return FIsComplexAttentionObjectRegistered(this,_entityId); }
	void UnregisterComplexAttentionObject(unsigned _entityId) { FUnregisterComplexAttentionObject(this,_entityId); }
	bool IsSubjectTrackingSimpleObject(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) const { return FIsSubjectTrackingSimpleObject(this,_attentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	bool IsSubjectTrackingComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FIsSubjectTrackingComplexObject(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	void ClearHearingInputs(unsigned _attentiveSubjectEntityId) { FClearHearingInputs(this,_attentiveSubjectEntityId); }
	void ClearVisionInputs(unsigned _attentiveSubjectEntityId) { FClearVisionInputs(this,_attentiveSubjectEntityId); }
	void ClearRoomInputs(unsigned _attentiveSubjectEntityId) { FClearRoomInputs(this,_attentiveSubjectEntityId); }
	void OnSubjectDamagedBySimpleObject(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FOnSubjectDamagedBySimpleObject(this,_attentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	void OnSubjectDamagedByComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FOnSubjectDamagedByComplexObject(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	void ClearAttention(unsigned _attentiveSubjectEntityId) { FClearAttention(this,_attentiveSubjectEntityId); }
	void ClearSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FClearSimpleAttentionOv1(this,_attentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	void ClearComplexAttention(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FClearComplexAttentionOv1(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	void IncreaseSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FIncreaseSimpleAttention(this,_attentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	void CopySimpleAttention(unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FCopySimpleAttention(this,_fromAttentiveSubjectEntityId,_toAttentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	void CopyComplexAttention(unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FCopyComplexAttention(this,_fromAttentiveSubjectEntityId,_toAttentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	void CopyComplexAttentionTowardsObject(unsigned _fromAttentionObjectEntityId, unsigned _toAttentionObjectEntityId) { FCopyComplexAttentionTowardsObject(this,_fromAttentionObjectEntityId,_toAttentionObjectEntityId); }
	void DecreaseSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FDecreaseSimpleAttentionOv0(this,_attentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	bool HasSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) const { return FHasSimpleAttention(this,_attentiveSubjectEntityId,_simpleAttentionObjectEntityId); }
	ArkAttentionTag GetComplexAttentionTag(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionTag(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	EArkAttentionLevel GetComplexAttentionLevel(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionLevel(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	bool HasComplexVisualAttention(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FHasComplexVisualAttention(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	Vec3 GetComplexAttentionProxyPosition(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionProxyPosition(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	boost::optional<Vec3> GetComplexAttentionProxyVerifiedPosition(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionProxyVerifiedPosition(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	bool GetComplexAttentionProxyIsFollowing(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionProxyIsFollowing(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	bool HasFullAttentionTypeOnTarget(unsigned _attentiveSubjectEntityId, unsigned _attentionObjectEntityId) const { return FHasFullAttentionTypeOnTarget(this,_attentiveSubjectEntityId,_attentionObjectEntityId); }
	void RegisterAttentionLevelsChangedListener(unsigned _attentiveEntityId, ArkAttentionLevelsChangedListener *_pListener) { FRegisterAttentionLevelsChangedListener(this,_attentiveEntityId,_pListener); }
	void UnregisterAttentionLevelsChangedListener(unsigned _attentiveEntityId, ArkAttentionLevelsChangedListener const *_pListener) { FUnregisterAttentionLevelsChangedListener(this,_attentiveEntityId,_pListener); }
	void PushDrainLockedOnComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FPushDrainLockedOnComplexObject(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	void PopDrainLockedOnComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FPopDrainLockedOnComplexObject(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	bool IsDrainLocked(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FIsDrainLocked(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	int GetDrainLockCount(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetDrainLockCount(this,_attentiveSubjectEntityId,_complexAttentionObjectEntityId); }
	ArkAttentionTag MakeNewAttentionTag() { return FMakeNewAttentionTag(this); }
	void Update(float _elapsedTime) { FUpdate(this,_elapsedTime); }
	void SetMasterComplexVisionGain(float _gain) { FSetMasterComplexVisionGain(this,_gain); }
	void SetComplexHearingGain(unsigned _attentiveSubjectEntityId, float _gain) { FSetComplexHearingGain(this,_attentiveSubjectEntityId,_gain); }
	void SetComplexVisionGain(unsigned _attentiveSubjectEntityId, float _gain) { FSetComplexVisionGain(this,_attentiveSubjectEntityId,_gain); }
	void OnPlayerDuplicateCreated(unsigned _doppelgangerEntityId) { FOnPlayerDuplicateCreated(this,_doppelgangerEntityId); }
	void Serialize(TSerialize _serializer) { FSerialize(this,_serializer); }
	static ArkNoiseAttentionParams const &GetNoiseAttentionParams() { return FGetNoiseAttentionParams(); }
	void UpdateAttentionLevels(float _elapsedTime) { FUpdateAttentionLevels(this,_elapsedTime); }
	void UpdateTopAttentionTargets() { FUpdateTopAttentionTargets(this); }
	void SendAttentionLevelChangedNotifications() { FSendAttentionLevelChangedNotifications(this); }
	void SendComplexAttentionProxyUpdatedNotifications() { FSendComplexAttentionProxyUpdatedNotifications(this); }
	void UpdateComplexAttentionProxy(uint64_t _attentiveSubjectIndex, uint64_t _complexAttentionObjectIndex, boost::optional<Vec3> _optAttentionPos) { FUpdateComplexAttentionProxy(this,_attentiveSubjectIndex,_complexAttentionObjectIndex,_optAttentionPos); }
	static uint64_t AttentionPairIndex(uint64_t _attentiveSubjectIndex, uint64_t _attentionObjectIndex, uint64_t _attentionObjectCount) { return FAttentionPairIndex(_attentiveSubjectIndex,_attentionObjectIndex,_attentionObjectCount); }
	static void Load(XmlNodeRef const &_node, ArkAttentionManager::RoomData &_roomData) { FLoadOv7(_node,_roomData); }
	static void Load(XmlNodeRef const &_node, ArkAttentionManager::ComplexAttentionModel &_complexAttentionModel) { FLoadOv2(_node,_complexAttentionModel); }
	static void Load(XmlNodeRef const &_node, ArkAttentionManager::AttentionModel &_attentionModel) { FLoadOv0(_node,_attentionModel); }
	void LoadAttentionModels() { FLoadAttentionModels(this); }
	void AssignAttentionModel(uint64_t _attentiveSubjectIndex, ArkAttentiveSubject const &_attentiveSubject) { FAssignAttentionModel(this,_attentiveSubjectIndex,_attentiveSubject); }
	ArkAttentionManager::AttentionModel const &GetAttentionModel(uint64_t _attentiveSubjectIndex) const { return FGetAttentionModel(this,_attentiveSubjectIndex); }
	
#if 0
	void ClearSimpleAttention(unsigned arg0);
	void ClearSimpleAttention(ArkAttentionManager::SimpleAttentionModel const &arg0, uint64_t arg1, uint64_t arg2);
	void ClearComplexAttention(unsigned arg0);
	void ClearComplexAttention(ArkAttentionManager::ComplexAttentionModel const &arg0, uint64_t arg1, uint64_t arg2);
	void IncreaseComplexAttention(unsigned arg0, unsigned arg1, ArkAttentionTag arg2, EArkAttentionLevel arg3, EArkAttentionChangeReason arg4, Vec3 const &arg5, const bool arg6);
	void DecreaseSimpleAttention(unsigned arg0);
	void DecreaseComplexAttention(unsigned arg0, unsigned arg1, ArkAttentionTag arg2, EArkAttentionLevel arg3, EArkAttentionChangeReason arg4, Vec3 const &arg5);
	void SetMinimumComplexAttentionLevel(unsigned arg0, unsigned arg1, EArkAttentionLevel arg2);
	void SetMaximumComplexAttentionLevel(unsigned arg0, unsigned arg1, EArkAttentionLevel arg2);
	float GetComplexAttentionRawValue(unsigned arg0, unsigned arg1) const;
	bool HasSimpleVisualAttention(unsigned arg0, unsigned arg1) const;
	float GetComplexAttentionProxyFollowingTimer(unsigned arg0, unsigned arg1) const;
	bool IsListenerRegisteredToAttentionLevelsChanged(const unsigned arg0, ArkAttentionLevelsChangedListener const *const arg1) const;
	bool HasNormalAttentionLimits(unsigned arg0, unsigned arg1) const;
	float GetMasterComplexVisionGain() const;
	float GetComplexHearingGain(unsigned arg0) const;
	float GetComplexVisionGain(unsigned arg0) const;
	void UpdateAttentiveSubjects();
	void UpdateSimpleAttentionObjects();
	void UpdateAttentionProxies(float arg0);
	void UpdateSurprise(float arg0);
	void SetTopAttentionTarget(unsigned arg0, uint64_t arg1, ArkAttentionManager::TopAttentionTarget const &arg2, EArkAttentionChangeReason arg3, bool arg4);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::AttentionLevelData &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::AttentionIncrease &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::HearingData &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::VisionData &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::ProxyData &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::SurpriseData &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::OnDamagedData &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::SimpleAttentionModel &arg1);
	static void Load(XmlNodeRef const &arg0, ArkAttentionManager::AttentionTargetData &arg1);
	static float GetPreviousAttentionLevelMaxValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static float GetNextAttentionLevelMinValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static float GetAttentionLevelMinGainValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static float GetAttentionLevelMaxGainValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static float GetAttentionLevelMinDrainValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static float GetAttentionLevelMaxDrainValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static float GetAttentionLevelMedianValue(EArkAttentionLevel arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1);
	static void IncreaseAttention(ArkAttentionManager::ComplexAttentionInfo &arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1, EArkAttentionLevel arg2, EArkAttentionChangeReason arg3, bool arg4);
	static void DecreaseAttention(ArkAttentionManager::ComplexAttentionInfo &arg0, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg1, EArkAttentionLevel arg2, EArkAttentionChangeReason arg3);
	static void SetMinimumAttentionLevel(ArkAttentionManager::ComplexAttentionInfo &arg0, EArkAttentionLevel arg1, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg2);
	static void SetMaximumAttentionLevel(ArkAttentionManager::ComplexAttentionInfo &arg0, EArkAttentionLevel arg1, std::array<ArkAttentionManager::AttentionLevelData,5> const &arg2);
	static EArkAttentionLevel ClampAttentionLevel(EArkAttentionLevel arg0, ArkAttentionManager::ComplexAttentionInfo const &arg1);
	void CheckAddNotificationForSimpleAttentionPairRemoved(uint64_t arg0, uint64_t arg1);
	void CheckAddNotificationForComplexAttentionPairRemoved(uint64_t arg0, uint64_t arg1);
	static void WriteEntityIds(TSerialize arg0, const char *arg1, std::unordered_map<unsigned int,unsigned __int64> &arg2);
	static std::vector<unsigned int> ReadEntityIds(TSerialize arg0, const char *arg1);
#endif
	
	static inline auto FInitialize = PreyFunction<void(ArkAttentionManager *const _this)>(0x13E7D00);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkAttentionManager *const _this)>(0x13E8F50);
	static inline auto FReset = PreyFunction<void(ArkAttentionManager *const _this, bool _bEnteringGameMode)>(0x13E9F40);
	static inline auto FRegisterAttentiveSubject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _entityId, ArkAttentiveSubject &_attentiveSubject)>(0x13E9C70);
	static inline auto FIsAttentiveSubjectRegistered = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _entityId)>(0x1533450);
	static inline auto FUnregisterAttentiveSubject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _entityId)>(0x13EBE40);
	static inline auto FRegisterSimpleAttentionObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _entityId, ArkSimpleAttentionObject &_simpleAttentionObject)>(0x13E9E60);
	static inline auto FIsSimpleAttentionObjectRegistered = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _entityId)>(0x1533500);
	static inline auto FUnregisterSimpleAttentionObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _entityId)>(0x13EC990);
	static inline auto FRegisterComplexAttentionObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _entityId, ArkComplexAttentionObject &_complexAttentionObject)>(0x13E9D80);
	static inline auto FIsComplexAttentionObjectRegistered = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _entityId)>(0x13E7D10);
	static inline auto FUnregisterComplexAttentionObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _entityId)>(0x13EC560);
	static inline auto FIsSubjectTrackingSimpleObject = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E7E40);
	static inline auto FIsSubjectTrackingComplexObject = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E7DF0);
	static inline auto FClearHearingInputs = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId)>(0x13E5890);
	static inline auto FClearVisionInputs = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId)>(0x13E5C40);
	static inline auto FClearRoomInputs = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId)>(0x13E5B00);
	static inline auto FOnSubjectDamagedBySimpleObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E95D0);
	static inline auto FOnSubjectDamagedByComplexObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E9340);
	static inline auto FClearAttention = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId)>(0x13E54D0);
	static inline auto FClearSimpleAttentionOv1 = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E6850);
	static inline auto FClearComplexAttentionOv1 = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E56B0);
	static inline auto FIncreaseSimpleAttention = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E7B50);
	static inline auto FCopySimpleAttention = PreyFunction<void(ArkAttentionManager *const _this, unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E6360);
	static inline auto FCopyComplexAttention = PreyFunction<void(ArkAttentionManager *const _this, unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E5E80);
	static inline auto FCopyComplexAttentionTowardsObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _fromAttentionObjectEntityId, unsigned _toAttentionObjectEntityId)>(0x13E6190);
	static inline auto FDecreaseSimpleAttentionOv0 = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E6850);
	static inline auto FHasSimpleAttention = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x13E76B0);
	static inline auto FGetComplexAttentionTag = PreyFunction<ArkAttentionTag(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E70F0);
	static inline auto FGetComplexAttentionLevel = PreyFunction<EArkAttentionLevel(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E6A10);
	static inline auto FHasComplexVisualAttention = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E7470);
	static inline auto FGetComplexAttentionProxyPosition = PreyFunction<Vec3(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E6D70);
	static inline auto FGetComplexAttentionProxyVerifiedPosition = PreyFunction<boost::optional<Vec3>(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E6F20);
	static inline auto FGetComplexAttentionProxyIsFollowing = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E6BC0);
	static inline auto FHasFullAttentionTypeOnTarget = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _attentionObjectEntityId)>(0x13E7620);
	static inline auto FRegisterAttentionLevelsChangedListener = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveEntityId, ArkAttentionLevelsChangedListener *_pListener)>(0x13E9AF0);
	static inline auto FUnregisterAttentionLevelsChangedListener = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveEntityId, ArkAttentionLevelsChangedListener const *_pListener)>(0x13EBDC0);
	static inline auto FPushDrainLockedOnComplexObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E9940);
	static inline auto FPopDrainLockedOnComplexObject = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E9790);
	static inline auto FIsDrainLocked = PreyFunction<bool(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E7DD0);
	static inline auto FGetDrainLockCount = PreyFunction<int(ArkAttentionManager const *const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x13E72A0);
	static inline auto FMakeNewAttentionTag = PreyFunction<ArkAttentionTag(ArkAttentionManager *const _this)>(0x13E8F20);
	static inline auto FUpdate = PreyFunction<void(ArkAttentionManager *const _this, float _elapsedTime)>(0x13ECDD0);
	static inline auto FSetMasterComplexVisionGain = PreyFunction<void(ArkAttentionManager *const _this, float _gain)>(0x13EB7B0);
	static inline auto FSetComplexHearingGain = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, float _gain)>(0x13EB630);
	static inline auto FSetComplexVisionGain = PreyFunction<void(ArkAttentionManager *const _this, unsigned _attentiveSubjectEntityId, float _gain)>(0x13EB6F0);
	static inline auto FOnPlayerDuplicateCreated = PreyFunction<void(ArkAttentionManager *const _this, unsigned _doppelgangerEntityId)>(0x13E91F0);
	static inline auto FSerialize = PreyFunction<void(ArkAttentionManager *const _this, TSerialize _serializer)>(0x13EA6C0);
	static inline auto FGetNoiseAttentionParams = PreyFunction<ArkNoiseAttentionParams const &()>(0x13E7450);
	static inline auto FUpdateAttentionLevels = PreyFunction<void(ArkAttentionManager *const _this, float _elapsedTime)>(0x13ED200);
	static inline auto FUpdateTopAttentionTargets = PreyFunction<void(ArkAttentionManager *const _this)>(0x13ED6F0);
	static inline auto FSendAttentionLevelChangedNotifications = PreyFunction<void(ArkAttentionManager *const _this)>(0x13E9F80);
	static inline auto FSendComplexAttentionProxyUpdatedNotifications = PreyFunction<void(ArkAttentionManager *const _this)>(0x13EA590);
	static inline auto FUpdateComplexAttentionProxy = PreyFunction<void(ArkAttentionManager *const _this, uint64_t _attentiveSubjectIndex, uint64_t _complexAttentionObjectIndex, boost::optional<Vec3> _optAttentionPos)>(0x13ED5E0);
	static inline auto FAttentionPairIndex = PreyFunction<uint64_t(uint64_t _attentiveSubjectIndex, uint64_t _attentionObjectIndex, uint64_t _attentionObjectCount)>(0x13E54C0);
	static inline auto FLoadOv7 = PreyFunction<void(XmlNodeRef const &_node, ArkAttentionManager::RoomData &_roomData)>(0x13E86F0);
	static inline auto FLoadOv2 = PreyFunction<void(XmlNodeRef const &_node, ArkAttentionManager::ComplexAttentionModel &_complexAttentionModel)>(0x13E8070);
	static inline auto FLoadOv0 = PreyFunction<void(XmlNodeRef const &_node, ArkAttentionManager::AttentionModel &_attentionModel)>(0x13E7E90);
	static inline auto FLoadAttentionModels = PreyFunction<void(ArkAttentionManager *const _this)>(0x13E8AB0);
	static inline auto FAssignAttentionModel = PreyFunction<void(ArkAttentionManager *const _this, uint64_t _attentiveSubjectIndex, ArkAttentiveSubject const &_attentiveSubject)>(0x13E5380);
	static inline auto FGetAttentionModel = PreyFunction<ArkAttentionManager::AttentionModel const &(ArkAttentionManager const *const _this, uint64_t _attentiveSubjectIndex)>(0x13E69F0);
};

