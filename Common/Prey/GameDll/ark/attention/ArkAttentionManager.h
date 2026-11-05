#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/ArkInterval.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/CrySystem/TimeValue.h>
#include <Prey/GameDll/ark/attention/ArkAttentionLevelChange.h>
#include <Prey/GameDll/ark/attention/ArkAttentionTag.h>

class ArkAttentionLevelsChangedListener;
class ArkAttentiveSubject;
class ArkComplexAttentionObject;
struct ArkNoiseAttentionParams;
class ArkSimpleAttentionObject;
class XmlNodeRef;

// ArkAttentionManager
// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
class ArkAttentionManager
{ // Size=1328 (0x530)
public:
	// ArkAttentionManager::TopAttentionTarget
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct TopAttentionTarget
	{ // Size=16 (0x10)
		unsigned m_entityId;
		EArkAttentionLevel m_attentionLevel;
		EArkDisposition m_disposition;
		float m_distanceSquared;

	#if 0
		TopAttentionTarget();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// ArkAttentionManager::AttentionLevelData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct AttentionLevelData
	{ // Size=12 (0xC)
		ArkInterval<float> m_interval;
		float m_drainRate;

	#if 0
		AttentionLevelData();
	#endif
	};

	// ArkAttentionManager::AttentionIncrease
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct AttentionIncrease
	{ // Size=8 (0x8)
		float m_gain;
		EArkAttentionLevel m_minimumAttentionLevel;

	#if 0
		AttentionIncrease();
	#endif
	};

	// ArkAttentionManager::HearingData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct HearingData
	{ // Size=72 (0x48)
		using AttentionIncreaseMap = std::unordered_map<uint64_t, ArkAttentionManager::AttentionIncrease>;

		std::unordered_map<uint64_t, ArkAttentionManager::AttentionIncrease> m_attentionIncreases;
		float m_allowKnownMaxLevelRadiusSq;
	};

	// ArkAttentionManager::VisionData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct VisionData
	{ // Size=20 (0x14)
		using FloatArray = std::array<float, 5>;

		std::array<float, 5> m_accumulationRates;

	#if 0
		VisionData();
	#endif
	};

	// ArkAttentionManager::RoomData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct RoomData
	{ // Size=80 (0x50)
		using FloatArray = std::array<float, 5>;

		std::array<float, 5> m_startRoomGains;
		std::array<float, 5> m_startContainerGains;
		std::array<float, 5> m_continueRoomAccumulationRates;
		std::array<float, 5> m_continueContainerAccumulationRates;

	#if 0
		RoomData();
	#endif
	};

	// ArkAttentionManager::SeismicData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct SeismicData
	{ // Size=28 (0x1C)
		ArkAttentionManager::AttentionIncrease m_attentionIncrease;
		bool m_bUseSeismicIgnoreList;
		float m_allowKnownMaxLevelRadiusSq;
		float m_seismicIgnoreTimeSeconds;
		float m_nonDangerNoiseIgnoreTimeSeconds;
		float m_seismicIgnoreAfterDamageTime;
	};

	// ArkAttentionManager::ProxyData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ProxyData
	{ // Size=4 (0x4)
		float m_followTime;

	#if 0
		ProxyData();
	#endif
	};

	// ArkAttentionManager::SurpriseData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct SurpriseData
	{ // Size=12 (0xC)
		EArkAttentionLevel m_fromLevel;
		EArkAttentionLevel m_toLevel;
		float m_time_s;

	#if 0
		SurpriseData();
	#endif
	};

	// ArkAttentionManager::OnDamagedData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct OnDamagedData
	{ // Size=4 (0x4)
		EArkAttentionLevel m_minimumAttentionLevel;

	#if 0
		OnDamagedData();
	#endif
	};

	// ArkAttentionManager::SimpleAttentionModel
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct SimpleAttentionModel
	{ // Size=4 (0x4)
		float m_timeout;

	#if 0
		SimpleAttentionModel();
	#endif
	};

	// ArkAttentionManager::ComplexAttentionModel
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionModel
	{ // Size=288 (0x120)
		std::array<ArkAttentionManager::AttentionLevelData, 5> m_levels;
		ArkAttentionManager::HearingData m_hearingData;
		ArkAttentionManager::VisionData m_visionData;
		ArkAttentionManager::RoomData m_roomData;
		ArkAttentionManager::SeismicData m_seismicData;
		ArkAttentionManager::ProxyData m_proxyData;
		ArkAttentionManager::OnDamagedData m_onDamagedData;
		ArkAttentionManager::SurpriseData m_surpriseData;
	};

	// ArkAttentionManager::AttentionTargetData
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct AttentionTargetData
	{ // Size=12 (0xC)
		float m_relativeClosenessToSwitchTopTargetSqrd;
		float m_simpleDamageTimer;
		float m_complexDamageTimer;

	#if 0
		AttentionTargetData();
	#endif
	};

	// ArkAttentionManager::AttentionModel
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct AttentionModel
	{ // Size=312 (0x138)
		ArkAttentionManager::SimpleAttentionModel m_simple;
		ArkAttentionManager::ComplexAttentionModel m_complex;
		ArkAttentionManager::AttentionTargetData m_attentionTargetData;

		ArkAttentionManager::AttentionModel& operator=(ArkAttentionManager::AttentionModel* _other) { return FoperatorEq(this, _other); }

	#if 0
		AttentionModel();
		AttentionModel(ArkAttentionManager::AttentionModel&& _arg0_);
		AttentionModel(ArkAttentionManager::AttentionModel& _arg0_);
	#endif

		static inline auto FoperatorEq = PreyFunction<ArkAttentionManager::AttentionModel& (ArkAttentionManager::AttentionModel* const _this, ArkAttentionManager::AttentionModel* _other)>(0x14F30A0);
	};

	// ArkAttentionManager::ComplexHearingInput
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexHearingInput
	{ // Size=40 (0x28)
		ArkAttentionTag m_attentionTag;
		float m_gain;
		boost::optional<enum EArkAttentionLevel> m_optMinimumAttentionLevel;
		Vec3 m_attentionPosition;
		bool m_bIsDangerNoise;
		unsigned m_noiseEmitterEntityId;

		ComplexHearingInput(ArkAttentionTag _attentionTag, float _gain, const boost::optional<enum EArkAttentionLevel> _optMinimumAttentionLevel, const Vec3& _attentionPosition, bool _bIsDangerNoise, const unsigned _noiseEmitterEntityId);
		bool operator>(const ArkAttentionManager::ComplexHearingInput& _other) const { return FoperatorGreater(this, _other); }

	#if 0
		ComplexHearingInput();
		void Serialize(TSerialize _arg0_);
	#endif

		static inline auto FComplexHearingInputOv2 = PreyFunction<void(ArkAttentionManager::ComplexHearingInput* const _this, ArkAttentionTag _attentionTag, float _gain, const boost::optional<enum EArkAttentionLevel> _optMinimumAttentionLevel, const Vec3& _attentionPosition, bool _bIsDangerNoise, const unsigned _noiseEmitterEntityId)>(0x14F2F30);
		static inline auto FoperatorGreater = PreyFunction<bool(const ArkAttentionManager::ComplexHearingInput* const _this, const ArkAttentionManager::ComplexHearingInput& _other)>(0x14F35F0);
	};

	// ArkAttentionManager::ComplexVisionInput
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexVisionInput
	{ // Size=16 (0x10)
		ArkAttentionTag m_attentionTag;
		float m_magnitude;

		ComplexVisionInput(ArkAttentionTag _attentionTag, float _magnitude);

	#if 0
		ComplexVisionInput();
		void Serialize(TSerialize _arg0_);
	#endif

		static inline auto FComplexVisionInputOv0 = PreyFunction<void(ArkAttentionManager::ComplexVisionInput* const _this, ArkAttentionTag _attentionTag, float _magnitude)>(0x14F2FE0);
	};

	// ArkAttentionManager::ComplexRoomInput
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexRoomInput
	{ // Size=16 (0x10)
		ArkAttentionTag m_attentionTag;
		float m_magnitude;
		bool m_bStart;
		bool m_bSameAreaContainer;

		ComplexRoomInput(ArkAttentionTag _attentionTag, float _magnitude, bool _bStart, bool _bSameAreaContainer);

	#if 0
		ComplexRoomInput();
		void Serialize(TSerialize _arg0_);
	#endif

		static inline auto FComplexRoomInputOv0 = PreyFunction<void(ArkAttentionManager::ComplexRoomInput* const _this, ArkAttentionTag _attentionTag, float _magnitude, bool _bStart, bool _bSameAreaContainer)>(0x14F2F90);
	};

	// ArkAttentionManager::ComplexSeismicInput
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexSeismicInput
	{ // Size=32 (0x20)
		ArkAttentionTag m_attentionTag;
		unsigned m_eventSourceEntityId;
		float m_gain;
		EArkAttentionLevel m_minimumAttentionLevel;
		Vec3 m_attentionPosition;

		ComplexSeismicInput(ArkAttentionTag _attentionTag, unsigned _eventSourceEntityId, float _gain, EArkAttentionLevel _minimumAttentionLevel, const Vec3& _attentionPosition);
		bool operator>(const ArkAttentionManager::ComplexSeismicInput& _other) const { return FoperatorGreater(this, _other); }

	#if 0
		ComplexSeismicInput();
		void Serialize(TSerialize _arg0_);
	#endif

		static inline auto FComplexSeismicInputOv2 = PreyFunction<void(ArkAttentionManager::ComplexSeismicInput* const _this, ArkAttentionTag _attentionTag, unsigned _eventSourceEntityId, float _gain, EArkAttentionLevel _minimumAttentionLevel, const Vec3& _attentionPosition)>(0x14F2FB0);
		static inline auto FoperatorGreater = PreyFunction<bool(const ArkAttentionManager::ComplexSeismicInput* const _this, const ArkAttentionManager::ComplexSeismicInput& _other)>(0x14F3670);
	};

	// ArkAttentionManager::LastSeismicSourceInfo
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct LastSeismicSourceInfo
	{ // Size=16 (0x10)
		unsigned m_lastSeismicSourceId;
		ArkAttentionTag m_lastAttentionTag;

	#if 0
		LastSeismicSourceInfo();
		ArkAttentionManager::LastSeismicSourceInfo& operator=(const ArkAttentionManager::LastSeismicSourceInfo& _arg0_);
	#endif
	};

	// ArkAttentionManager::SeismicSourceInfo
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct SeismicSourceInfo
	{ // Size=32 (0x20)
		unsigned m_instigatorEntityId;
		ArkAttentionTag m_lastAttentionTag;
		bool m_bIsIgnored;
		CTimeValue m_ignoreStartTime;

	#if 0
		SeismicSourceInfo();
	#endif
	};

	// ArkAttentionManager::SimpleAttentionInfo
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct SimpleAttentionInfo
	{ // Size=8 (0x8)
		float m_timer;
		float m_lastDamageTimeStamp;

	#if 0
		SimpleAttentionInfo();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// ArkAttentionManager::ComplexAttentionInfo
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionInfo
	{ // Size=152 (0x98)
		ArkAttentionTag m_attentionTag;
		EArkAttentionChangeReason m_lastChangeReason;
		EArkAttentionChangeReason m_pendingChangeReason;
		EArkAttentionLevel m_level;
		float m_value;
		EArkAttentionLevel m_minimumLevel;
		EArkAttentionLevel m_maximumLevel;
		uint64_t m_drainLockCount;
		float m_lastDamageTimeStamp;
		EArkAttentionChangeReason m_lastGainType;
		ArkAttentionManager::LastSeismicSourceInfo m_lastSeismicSourceInfo;
		std::unordered_map<unsigned int, ArkAttentionManager::SeismicSourceInfo> m_complexSeismicSourceToInfo;
		CTimeValue m_lastDangerNoiseTimeStamp;
		ArkAttentionTag m_lastDangerNoiseTag;
		unsigned m_ignoringEntityId;

		ComplexAttentionInfo();

	#if 0
		void Serialize(TSerialize _arg0_);
	#endif

		static inline auto FComplexAttentionInfoOv2 = PreyFunction<void(ArkAttentionManager::ComplexAttentionInfo* const _this)>(0x14F2D20);
	};

	// ArkAttentionManager::ComplexAttentionGain
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionGain
	{ // Size=48 (0x30)
		ArkAttentionTag m_attentionTag;
		float m_value;
		boost::optional<enum EArkAttentionLevel> m_optMinLevel;
		EArkAttentionLevel m_maxLevel;
		boost::optional<Vec3_tpl<float> > m_optAttentionPos;
		EArkAttentionChangeReason m_reason;

	#if 0
		ComplexAttentionGain(ArkAttentionTag _arg0_, float _arg1_, EArkAttentionLevel _arg2_, EArkAttentionChangeReason _arg3_);
	#endif
	};

	// ArkAttentionManager::ComplexAttentionProxyUpdate
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionProxyUpdate
	{ // Size=40 (0x28)
		uint64_t m_attentiveSubjectIndex;
		uint64_t m_complexAttentionObjectIndex;
		boost::optional<Vec3_tpl<float> > m_optAttentionPosition;
		unsigned m_updateSourceEntityId;

	#if 0
		ComplexAttentionProxyUpdate(uint64_t _arg0_, uint64_t _arg1_, const boost::optional<Vec3_tpl<float> >& _arg2_, unsigned _arg3_);
	#endif
	};

	// ArkAttentionManager::ComplexAttentionProxyUpdateNotification
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionProxyUpdateNotification
	{ // Size=16 (0x10)
		uint64_t m_attentiveSubjectIndex;
		uint64_t m_complexAttentionObjectIndex;

	#if 0
		ComplexAttentionProxyUpdateNotification(uint64_t _arg0_, uint64_t _arg1_);
	#endif
	};

	// ArkAttentionManager::ComplexAttentionProxy
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionProxy
	{ // Size=32 (0x20)
		Vec3 m_position;
		boost::optional<Vec3_tpl<float> > m_optVerifiedPosition;
		float m_followTimer;

	#if 0
		ComplexAttentionProxy();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// ArkAttentionManager::ComplexAttentionSurpriseInfo
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct ComplexAttentionSurpriseInfo
	{ // Size=8 (0x8)
		float m_timer;
		bool m_bSurprising;

	#if 0
		ComplexAttentionSurpriseInfo();
		void Serialize(TSerialize _arg0_);
	#endif
	};

	// ArkAttentionManager::BestAttentionTargetInfo
	// Header:  Prey/GameDll/ark/attention/ArkAttentionManager.h
	struct BestAttentionTargetInfo
	{ // Size=28 (0x1C)
		ArkAttentionManager::TopAttentionTarget m_topAttentionTarget;
		EArkAttentionChangeReason m_lastChangeReason;
		bool m_bIsSuprising;
		bool m_bEncounteredEtherDuplicate;
		float m_lastDamageTimestamp;

	#if 0
		BestAttentionTargetInfo();
	#endif
	};

	using LevelDataArray = std::array<ArkAttentionManager::AttentionLevelData, 5>;
	using AttentionLevelChangeVector = std::vector<ArkAttentionLevelChange>;
	using AttentionLevelsChangedListenerMap = std::unordered_multimap<unsigned int,ArkAttentionLevelsChangedListener *,std::hash<unsigned int>,std::equal_to<unsigned int>,std::allocator<std::pair<unsigned int const ,ArkAttentionLevelsChangedListener *> > >;
	using AttentionModelVector = std::vector<ArkAttentionManager::AttentionModel>;
	using AttentiveSubjectVector = std::vector<ArkAttentiveSubject*>;
	using BestAttentionTargetInfoVector = std::vector<ArkAttentionManager::BestAttentionTargetInfo>;
	using BoolVector = std::vector<bool>;
	using ComplexAttentionGainVector = std::vector<ArkAttentionManager::ComplexAttentionGain>;
	using ComplexAttentionInfoVector = std::vector<ArkAttentionManager::ComplexAttentionInfo>;
	using ComplexAttentionObjectVector = std::vector<ArkComplexAttentionObject*>;
	using ComplexAttentionProxyUpdateNotificationVector = std::vector<ArkAttentionManager::ComplexAttentionProxyUpdateNotification>;
	using ComplexAttentionProxyUpdateVector = std::vector<ArkAttentionManager::ComplexAttentionProxyUpdate>;
	using ComplexAttentionProxyVector = std::vector<ArkAttentionManager::ComplexAttentionProxy>;
	using ComplexAttentionSurpriseInfoVector = std::vector<ArkAttentionManager::ComplexAttentionSurpriseInfo>;
	using ComplexHearingInputVector = std::vector<ArkAttentionManager::ComplexHearingInput>;
	using ComplexRoomInputVector = std::vector<ArkAttentionManager::ComplexRoomInput>;
	using ComplexSeismicInputVector = std::vector<ArkAttentionManager::ComplexSeismicInput>;
	using ComplexVisionInputVector = std::vector<ArkAttentionManager::ComplexVisionInput>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int, uint64_t>;
	using EntityIdVector = std::vector<unsigned int>;
	using FloatVector = std::vector<float>;
	using IndexVector = std::vector<uint64_t>;
	using SimpleAttentionInfoVector = std::vector<ArkAttentionManager::SimpleAttentionInfo>;
	using SimpleAttentionObjectVector = std::vector<ArkSimpleAttentionObject*>;
	using TopAttentionTargetVector = std::vector<ArkAttentionManager::TopAttentionTarget>;
	using UniqueIdToIndexMap = std::unordered_map<uint64_t, uint64_t>;
	using Vec3Vector = std::vector<Vec3>;
	using SeismicSourceToInfoMap = std::unordered_map<unsigned int, ArkAttentionManager::SeismicSourceInfo>;
	using LastSeismicEventSourceVector = std::vector<ArkAttentionManager::LastSeismicSourceInfo>;
	using LastGainTypeVector = std::vector<enum::EArkAttentionChangeReason>;

	std::unordered_map<unsigned int, uint64_t> m_attentiveSubjectIndexMap;
	std::unordered_map<unsigned int, uint64_t> m_simpleAttentionObjectIndexMap;
	std::unordered_map<unsigned int, uint64_t> m_complexAttentionObjectIndexMap;
	std::unordered_map<uint64_t, uint64_t> m_attentionModelIdMap;
	std::vector<ArkAttentionManager::AttentionModel> m_attentionModels;
	std::vector<uint64_t> m_freeAttentiveSubjectIndexes;
	std::vector<ArkAttentiveSubject*> m_attentiveSubjects;
	std::vector<unsigned int> m_attentiveSubjectEntityIds;
	std::vector<uint64_t> m_attentiveSubjectAttentionModelIndexes;
	std::vector<bool> m_attentiveSubjectUpdateFlags;
	std::vector<Vec3> m_attentiveSubjectPositions;
	std::vector<uint64_t> m_freeSimpleAttentionObjectIndexes;
	std::vector<ArkSimpleAttentionObject*> m_simpleAttentionObjects;
	std::vector<unsigned int> m_simpleAttentionObjectEntityIds;
	std::vector<Vec3> m_simpleAttentionObjectPositions;
	std::vector<uint64_t> m_freeComplexAttentionObjectIndexes;
	std::vector<ArkComplexAttentionObject*> m_complexAttentionObjects;
	std::vector<unsigned int> m_complexAttentionObjectEntityIds;
	std::vector<bool> m_simpleHearingInputs;
	std::vector<ArkAttentionManager::ComplexHearingInput> m_complexHearingInputs;
	std::vector<bool> m_simpleVisionInputs;
	std::vector<ArkAttentionManager::ComplexVisionInput> m_complexVisionInputs;
	std::vector<ArkAttentionManager::ComplexRoomInput> m_complexRoomInputs;
	std::vector<bool> m_simpleSeismicInputs;
	std::vector<ArkAttentionManager::ComplexSeismicInput> m_complexSeismicInputs;
	std::vector<ArkAttentionManager::SimpleAttentionInfo> m_simpleAttentionInfo;
	std::vector<ArkAttentionManager::ComplexAttentionInfo> m_complexAttentionInfo;
	std::vector<ArkAttentionManager::ComplexAttentionProxy> m_complexAttentionProxies;
	std::vector<ArkAttentionManager::ComplexAttentionSurpriseInfo> m_complexAttentionSurpriseInfo;
	std::vector<uint64_t> m_simpleTopAttentionTargetStream;
	std::vector<uint64_t> m_complexTopAttentionTargetStream;
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
	float m_masterComplexSeismicGain;
	std::vector<float> m_complexVisionGains;
	std::vector<float> m_complexHearingGains;
	std::vector<float> m_complexSeismicGains;
	std::vector<ArkAttentionManager::LastSeismicSourceInfo> m_lastSeismicEventSources;
	std::vector<enum::EArkAttentionChangeReason> m_lastGainTypes;

	ArkAttentionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void RegisterAttentiveSubject(unsigned _entityId, ArkAttentiveSubject& _attentiveSubject) { FRegisterAttentiveSubject(this, _entityId, _attentiveSubject); }
	bool IsAttentiveSubjectRegistered(unsigned _entityId) const { return FIsAttentiveSubjectRegistered(this, _entityId); }
	void UnregisterAttentiveSubject(unsigned _entityId) { FUnregisterAttentiveSubject(this, _entityId); }
	void RegisterSimpleAttentionObject(unsigned _entityId, ArkSimpleAttentionObject& _simpleAttentionObject) { FRegisterSimpleAttentionObject(this, _entityId, _simpleAttentionObject); }
	bool IsSimpleAttentionObjectRegistered(unsigned _entityId) const { return FIsSimpleAttentionObjectRegistered(this, _entityId); }
	void UnregisterSimpleAttentionObject(unsigned _entityId) { FUnregisterSimpleAttentionObject(this, _entityId); }
	void RegisterComplexAttentionObject(unsigned _entityId, ArkComplexAttentionObject& _complexAttentionObject) { FRegisterComplexAttentionObject(this, _entityId, _complexAttentionObject); }
	bool IsComplexAttentionObjectRegistered(unsigned _entityId) const { return FIsComplexAttentionObjectRegistered(this, _entityId); }
	void UnregisterComplexAttentionObject(unsigned _entityId) { FUnregisterComplexAttentionObject(this, _entityId); }
	bool IsSubjectTrackingSimpleObject(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) const { return FIsSubjectTrackingSimpleObject(this, _attentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	bool IsSubjectTrackingComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FIsSubjectTrackingComplexObject(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	void RemoveSeismicCooldown(unsigned _subjectId, unsigned _complexObjectId, unsigned _seismicSourceId) { FRemoveSeismicCooldown(this, _subjectId, _complexObjectId, _seismicSourceId); }
	void SetTagIfSeismicIgnored(unsigned _subjectId, unsigned _complexObjectId, unsigned _seismicSourceId, ArkAttentionTag& out_tag) { FSetTagIfSeismicIgnored(this, _subjectId, _complexObjectId, _seismicSourceId, out_tag); }
	void SetTagIfHearingIgnored(unsigned _subjectId, unsigned _complexObjectId, unsigned _noiseEmitterId, bool _bIsDangerNoise, ArkAttentionTag& out_tag) { FSetTagIfHearingIgnored(this, _subjectId, _complexObjectId, _noiseEmitterId, _bIsDangerNoise, out_tag); }
	bool UpdateSeismicIgnoreOnComplexDamage(unsigned _subjectId, unsigned _complexObjectId) { return FUpdateSeismicIgnoreOnComplexDamage(this, _subjectId, _complexObjectId); }
	void ClearHearingInputs(unsigned _attentiveSubjectEntityId) { FClearHearingInputs(this, _attentiveSubjectEntityId); }
	void ClearVisionInputs(unsigned _attentiveSubjectEntityId) { FClearVisionInputs(this, _attentiveSubjectEntityId); }
	void ClearRoomInputs(unsigned _attentiveSubjectEntityId) { FClearRoomInputs(this, _attentiveSubjectEntityId); }
	void ClearSeismicInputs(unsigned _attentiveSubjectEntityId) { FClearSeismicInputs(this, _attentiveSubjectEntityId); }
	void OnSubjectDamagedBySimpleObject(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FOnSubjectDamagedBySimpleObject(this, _attentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	void OnSubjectDamagedByComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FOnSubjectDamagedByComplexObject(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	void ClearAttention(unsigned _attentiveSubjectEntityId) { FClearAttention(this, _attentiveSubjectEntityId); }
	void ClearSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FClearSimpleAttentionOv1(this, _attentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	void ClearComplexAttention(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FClearComplexAttentionOv1(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	void IncreaseSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FIncreaseSimpleAttention(this, _attentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	void IncreaseComplexAttention(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId, ArkAttentionTag _attentionTag, EArkAttentionLevel _toLevel, EArkAttentionChangeReason _reason, const Vec3& _attentionPos, const bool _bGainMaxValue) { FIncreaseComplexAttention(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId, _attentionTag, _toLevel, _reason, _attentionPos, _bGainMaxValue); }
	void CopySimpleAttention(unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FCopySimpleAttention(this, _fromAttentiveSubjectEntityId, _toAttentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	void CopyComplexAttention(unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FCopyComplexAttention(this, _fromAttentiveSubjectEntityId, _toAttentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	void CopyComplexAttentionTowardsObject(unsigned _fromAttentionObjectEntityId, unsigned _toAttentionObjectEntityId) { FCopyComplexAttentionTowardsObject(this, _fromAttentionObjectEntityId, _toAttentionObjectEntityId); }
	void DecreaseSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) { FDecreaseSimpleAttentionOv0(this, _attentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	void DecreaseComplexAttention(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId, ArkAttentionTag _attentionTag, EArkAttentionLevel _toLevel, EArkAttentionChangeReason _reason, const Vec3& _attentionPos) { FDecreaseComplexAttention(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId, _attentionTag, _toLevel, _reason, _attentionPos); }
	bool HasSimpleAttention(unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId) const { return FHasSimpleAttention(this, _attentiveSubjectEntityId, _simpleAttentionObjectEntityId); }
	ArkAttentionTag GetComplexAttentionTag(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { alignas(ArkAttentionTag) std::byte _return_buf_[sizeof(ArkAttentionTag)]; return *FGetComplexAttentionTag(this, reinterpret_cast<ArkAttentionTag*>(_return_buf_), _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	EArkAttentionLevel GetComplexAttentionLevel(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionLevel(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	bool HasComplexVisualAttention(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FHasComplexVisualAttention(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	Vec3 GetComplexAttentionProxyPosition(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetComplexAttentionProxyPosition(this, reinterpret_cast<Vec3*>(_return_buf_), _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	boost::optional<Vec3_tpl<float> > GetComplexAttentionProxyVerifiedPosition(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { alignas(boost::optional<Vec3_tpl<float> >) std::byte _return_buf_[sizeof(boost::optional<Vec3_tpl<float> >)]; return *FGetComplexAttentionProxyVerifiedPosition(this, reinterpret_cast<boost::optional<Vec3_tpl<float> >*>(_return_buf_), _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	bool GetComplexAttentionProxyIsFollowing(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetComplexAttentionProxyIsFollowing(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	bool HasFullAttentionTypeOnTarget(unsigned _attentiveSubjectEntityId, unsigned _attentionObjectEntityId) const { return FHasFullAttentionTypeOnTarget(this, _attentiveSubjectEntityId, _attentionObjectEntityId); }
	void RegisterAttentionLevelsChangedListener(unsigned _attentiveEntityId, ArkAttentionLevelsChangedListener* _pListener) { FRegisterAttentionLevelsChangedListener(this, _attentiveEntityId, _pListener); }
	void UnregisterAttentionLevelsChangedListener(unsigned _attentiveEntityId, const ArkAttentionLevelsChangedListener* _pListener) { FUnregisterAttentionLevelsChangedListener(this, _attentiveEntityId, _pListener); }
	void PushDrainLockedOnComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FPushDrainLockedOnComplexObject(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	void PopDrainLockedOnComplexObject(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) { FPopDrainLockedOnComplexObject(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	bool IsDrainLocked(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FIsDrainLocked(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	int GetDrainLockCount(unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId) const { return FGetDrainLockCount(this, _attentiveSubjectEntityId, _complexAttentionObjectEntityId); }
	ArkAttentionTag MakeNewAttentionTag() { alignas(ArkAttentionTag) std::byte _return_buf_[sizeof(ArkAttentionTag)]; return *FMakeNewAttentionTag(this, reinterpret_cast<ArkAttentionTag*>(_return_buf_)); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void SetMasterComplexVisionGain(float _gain) { FSetMasterComplexVisionGain(this, _gain); }
	void SetComplexHearingGain(unsigned _attentiveSubjectEntityId, float _gain) { FSetComplexHearingGain(this, _attentiveSubjectEntityId, _gain); }
	void SetComplexVisionGain(unsigned _attentiveSubjectEntityId, float _gain) { FSetComplexVisionGain(this, _attentiveSubjectEntityId, _gain); }
	void OnPlayerDuplicateCreated(unsigned _doppelgangerEntityId) { FOnPlayerDuplicateCreated(this, _doppelgangerEntityId); }
	void Serialize(TSerialize _serializer) { FSerialize(this, _serializer); }
	static const ArkNoiseAttentionParams& GetNoiseAttentionParams() { return FGetNoiseAttentionParams(); }
	void UpdateAttentionLevels(float _elapsedTime) { FUpdateAttentionLevels(this, _elapsedTime); }
	void UpdateTopAttentionTargets() { FUpdateTopAttentionTargets(this); }
	void SendAttentionLevelChangedNotifications() { FSendAttentionLevelChangedNotifications(this); }
	void SendComplexAttentionProxyUpdatedNotifications() { FSendComplexAttentionProxyUpdatedNotifications(this); }
	void UpdateComplexAttentionProxy(uint64_t _attentiveSubjectIndex, uint64_t _complexAttentionObjectIndex, boost::optional<Vec3_tpl<float> > _optAttentionPos) { FUpdateComplexAttentionProxy(this, _attentiveSubjectIndex, _complexAttentionObjectIndex, _optAttentionPos); }
	static uint64_t AttentionPairIndex(uint64_t _attentiveSubjectIndex, uint64_t _attentionObjectIndex, uint64_t _attentionObjectCount) { return FAttentionPairIndex(_attentiveSubjectIndex, _attentionObjectIndex, _attentionObjectCount); }
	static void Load(const XmlNodeRef& _node, ArkAttentionManager::HearingData& _hearingData) { FLoadOv10(_node, _hearingData); }
	static void Load(const XmlNodeRef& _node, ArkAttentionManager::RoomData& _roomData) { FLoadOv8(_node, _roomData); }
	static void Load(const XmlNodeRef& _node, ArkAttentionManager::ComplexAttentionModel& _complexAttentionModel) { FLoadOv2(_node, _complexAttentionModel); }
	static void Load(const XmlNodeRef& _node, ArkAttentionManager::AttentionModel& _attentionModel) { FLoadOv0(_node, _attentionModel); }
	static void IncreaseAttention(ArkAttentionManager::ComplexAttentionInfo& _attentionInfo, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _levels, EArkAttentionLevel _level, EArkAttentionChangeReason _reason, bool _bGainMaxValue) { FIncreaseAttention(_attentionInfo, _levels, _level, _reason, _bGainMaxValue); }
	void SetEntityOnComplexSeismicCooldown(ArkAttentionManager::ComplexAttentionInfo& _complexAttentionInfo, unsigned _perceiverId, unsigned _seismicSourceId, ArkAttentionTag _lastTag) { FSetEntityOnComplexSeismicCooldown(this, _complexAttentionInfo, _perceiverId, _seismicSourceId, _lastTag); }
	void LoadAttentionModels() { FLoadAttentionModels(this); }
	void AssignAttentionModel(uint64_t _attentiveSubjectIndex, const ArkAttentiveSubject& _attentiveSubject) { FAssignAttentionModel(this, _attentiveSubjectIndex, _attentiveSubject); }
	const ArkAttentionManager::AttentionModel& GetAttentionModel(uint64_t _attentiveSubjectIndex) const { return FGetAttentionModel(this, _attentiveSubjectIndex); }

#if 0
	ArkAttentionManager(const ArkAttentionManager& _arg0_);
	void UpdateSeismicIgnoreList();
	void ClearSimpleAttention(unsigned _arg0_);
	void ClearSimpleAttention(const ArkAttentionManager::SimpleAttentionModel& _arg0_, uint64_t _arg1_, uint64_t _arg2_);
	void ClearComplexAttention(unsigned _arg0_);
	void ClearComplexAttention(const ArkAttentionManager::ComplexAttentionModel& _arg0_, uint64_t _arg1_, uint64_t _arg2_);
	void DecreaseSimpleAttention(unsigned _arg0_);
	void SetMinimumComplexAttentionLevel(unsigned _arg0_, unsigned _arg1_, EArkAttentionLevel _arg2_);
	void SetMaximumComplexAttentionLevel(unsigned _arg0_, unsigned _arg1_, EArkAttentionLevel _arg2_);
	float GetComplexAttentionRawValue(unsigned _arg0_, unsigned _arg1_) const;
	bool HasSimpleVisualAttention(unsigned _arg0_, unsigned _arg1_) const;
	float GetComplexAttentionProxyFollowingTimer(unsigned _arg0_, unsigned _arg1_) const;
	bool IsListenerRegisteredToAttentionLevelsChanged(const unsigned _arg0_, const ArkAttentionLevelsChangedListener* const _arg1_) const;
	bool HasNormalAttentionLimits(unsigned _arg0_, unsigned _arg1_) const;
	float GetMasterComplexVisionGain() const;
	void SetMasterComplexSeismicGain(float _arg0_);
	float GetMasterComplexSeismicGain() const;
	float GetComplexHearingGain(unsigned _arg0_) const;
	float GetComplexVisionGain(unsigned _arg0_) const;
	void SetComplexSeismicGain(unsigned _arg0_, float _arg1_);
	float GetComplexSeismicGain(unsigned _arg0_) const;
	void RefreshProxyFollowTimer(unsigned _arg0_, unsigned _arg1_);
	void UpdateAttentiveSubjects();
	void UpdateSimpleAttentionObjects();
	void UpdateAttentionProxies(float _arg0_);
	void UpdateSurprise(float _arg0_);
	void SetTopAttentionTarget(unsigned _arg0_, uint64_t _arg1_, const ArkAttentionManager::TopAttentionTarget& _arg2_, const EArkAttentionChangeReason _arg3_, bool _arg4_);
	ArkAttentionManager& operator=(const ArkAttentionManager& _arg0_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::AttentionLevelData& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::AttentionIncrease& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::VisionData& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::SeismicData& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::ProxyData& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::SurpriseData& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::OnDamagedData& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::SimpleAttentionModel& _arg1_);
	static void Load(const XmlNodeRef& _arg0_, ArkAttentionManager::AttentionTargetData& _arg1_);
	static float GetPreviousAttentionLevelMaxValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static float GetNextAttentionLevelMinValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static float GetAttentionLevelMinGainValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static float GetAttentionLevelMaxGainValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static float GetAttentionLevelMinDrainValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static float GetAttentionLevelMaxDrainValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static float GetAttentionLevelMedianValue(EArkAttentionLevel _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_);
	static void DecreaseAttention(ArkAttentionManager::ComplexAttentionInfo& _arg0_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg1_, EArkAttentionLevel _arg2_, EArkAttentionChangeReason _arg3_);
	static void SetMinimumAttentionLevel(ArkAttentionManager::ComplexAttentionInfo& _arg0_, EArkAttentionLevel _arg1_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg2_);
	static void SetMaximumAttentionLevel(ArkAttentionManager::ComplexAttentionInfo& _arg0_, EArkAttentionLevel _arg1_, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _arg2_);
	static EArkAttentionLevel ClampAttentionLevel(EArkAttentionLevel _arg0_, const ArkAttentionManager::ComplexAttentionInfo& _arg1_);
	void CheckAddNotificationForSimpleAttentionPairRemoved(uint64_t _arg0_, uint64_t _arg1_);
	void CheckAddNotificationForComplexAttentionPairRemoved(uint64_t _arg0_, uint64_t _arg1_);
	static void WriteEntityIds(TSerialize _arg0_, const char* _arg1_, std::unordered_map<unsigned int, uint64_t>& _arg2_);
	static std::vector<unsigned int> ReadEntityIds(TSerialize _arg0_, const char* _arg1_);
#endif

	static inline auto FArkAttentionManagerOv1 = PreyFunction<void(ArkAttentionManager* const _this)>(0x14F2730);
	static inline auto FInitialize = PreyFunction<void(ArkAttentionManager* const _this)>(0x14F75E0);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkAttentionManager* const _this)>(0x14F8A50);
	static inline auto FReset = PreyFunction<void(ArkAttentionManager* const _this, bool _bEnteringGameMode)>(0x14F9C70);
	static inline auto FRegisterAttentiveSubject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _entityId, ArkAttentiveSubject& _attentiveSubject)>(0x14F97E0);
	static inline auto FIsAttentiveSubjectRegistered = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _entityId)>(0x16532C0);
	static inline auto FUnregisterAttentiveSubject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _entityId)>(0x14FC4A0);
	static inline auto FRegisterSimpleAttentionObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _entityId, ArkSimpleAttentionObject& _simpleAttentionObject)>(0x14F99E0);
	static inline auto FIsSimpleAttentionObjectRegistered = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _entityId)>(0x1653370);
	static inline auto FUnregisterSimpleAttentionObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _entityId)>(0x14FD650);
	static inline auto FRegisterComplexAttentionObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _entityId, ArkComplexAttentionObject& _complexAttentionObject)>(0x14F9900);
	static inline auto FIsComplexAttentionObjectRegistered = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _entityId)>(0x14F75F0);
	static inline auto FUnregisterComplexAttentionObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _entityId)>(0x14FCF50);
	static inline auto FIsSubjectTrackingSimpleObject = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F7720);
	static inline auto FIsSubjectTrackingComplexObject = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F76D0);
	static inline auto FRemoveSeismicCooldown = PreyFunction<void(ArkAttentionManager* const _this, unsigned _subjectId, unsigned _complexObjectId, unsigned _seismicSourceId)>(0x14F9AC0);
	static inline auto FSetTagIfSeismicIgnored = PreyFunction<void(ArkAttentionManager* const _this, unsigned _subjectId, unsigned _complexObjectId, unsigned _seismicSourceId, ArkAttentionTag& out_tag)>(0x14FBFA0);
	static inline auto FSetTagIfHearingIgnored = PreyFunction<void(ArkAttentionManager* const _this, unsigned _subjectId, unsigned _complexObjectId, unsigned _noiseEmitterId, bool _bIsDangerNoise, ArkAttentionTag& out_tag)>(0x14FBD00);
	static inline auto FUpdateSeismicIgnoreOnComplexDamage = PreyFunction<bool(ArkAttentionManager* const _this, unsigned _subjectId, unsigned _complexObjectId)>(0x14FE470);
	static inline auto FClearHearingInputs = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId)>(0x14F4F10);
	static inline auto FClearVisionInputs = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId)>(0x14F5520);
	static inline auto FClearRoomInputs = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId)>(0x14F5180);
	static inline auto FClearSeismicInputs = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId)>(0x14F52C0);
	static inline auto FOnSubjectDamagedBySimpleObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F9140);
	static inline auto FOnSubjectDamagedByComplexObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F8EA0);
	static inline auto FClearAttention = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId)>(0x14F4B60);
	static inline auto FClearSimpleAttentionOv1 = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F6130);
	static inline auto FClearComplexAttentionOv1 = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F4D40);
	static inline auto FIncreaseSimpleAttention = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F7430);
	static inline auto FIncreaseComplexAttention = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId, ArkAttentionTag _attentionTag, EArkAttentionLevel _toLevel, EArkAttentionChangeReason _reason, const Vec3& _attentionPos, const bool _bGainMaxValue)>(0x14F71E0);
	static inline auto FCopySimpleAttention = PreyFunction<void(ArkAttentionManager* const _this, unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F5C40);
	static inline auto FCopyComplexAttention = PreyFunction<void(ArkAttentionManager* const _this, unsigned _fromAttentiveSubjectEntityId, unsigned _toAttentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F5760);
	static inline auto FCopyComplexAttentionTowardsObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _fromAttentionObjectEntityId, unsigned _toAttentionObjectEntityId)>(0x14F5A70);
	static inline auto FDecreaseSimpleAttentionOv0 = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F6130);
	static inline auto FDecreaseComplexAttention = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId, ArkAttentionTag _attentionTag, EArkAttentionLevel _toLevel, EArkAttentionChangeReason _reason, const Vec3& _attentionPos)>(0x14F5E90);
	static inline auto FHasSimpleAttention = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _simpleAttentionObjectEntityId)>(0x14F6F90);
	static inline auto FGetComplexAttentionTag = PreyFunction<ArkAttentionTag*(const ArkAttentionManager* const _this, ArkAttentionTag* _return_value_, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F69D0);
	static inline auto FGetComplexAttentionLevel = PreyFunction<EArkAttentionLevel(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F62F0);
	static inline auto FHasComplexVisualAttention = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F6D50);
	static inline auto FGetComplexAttentionProxyPosition = PreyFunction<Vec3*(const ArkAttentionManager* const _this, Vec3* _return_value_, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F6650);
	static inline auto FGetComplexAttentionProxyVerifiedPosition = PreyFunction<boost::optional<Vec3_tpl<float> >*(const ArkAttentionManager* const _this, boost::optional<Vec3_tpl<float> >* _return_value_, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F6800);
	static inline auto FGetComplexAttentionProxyIsFollowing = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F64A0);
	static inline auto FHasFullAttentionTypeOnTarget = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _attentionObjectEntityId)>(0x14F6F00);
	static inline auto FRegisterAttentionLevelsChangedListener = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveEntityId, ArkAttentionLevelsChangedListener* _pListener)>(0x14F9660);
	static inline auto FUnregisterAttentionLevelsChangedListener = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveEntityId, const ArkAttentionLevelsChangedListener* _pListener)>(0x14FC420);
	static inline auto FPushDrainLockedOnComplexObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F94B0);
	static inline auto FPopDrainLockedOnComplexObject = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F9300);
	static inline auto FIsDrainLocked = PreyFunction<bool(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F76B0);
	static inline auto FGetDrainLockCount = PreyFunction<int(const ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, unsigned _complexAttentionObjectEntityId)>(0x14F6B80);
	static inline auto FMakeNewAttentionTag = PreyFunction<ArkAttentionTag*(ArkAttentionManager* const _this, ArkAttentionTag* _return_value_)>(0x14F8A20);
	static inline auto FUpdate = PreyFunction<void(ArkAttentionManager* const _this, float _elapsedTime)>(0x14FDAE0);
	static inline auto FSetMasterComplexVisionGain = PreyFunction<void(ArkAttentionManager* const _this, float _gain)>(0x14FB8A0);
	static inline auto FSetComplexHearingGain = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, float _gain)>(0x14FB510);
	static inline auto FSetComplexVisionGain = PreyFunction<void(ArkAttentionManager* const _this, unsigned _attentiveSubjectEntityId, float _gain)>(0x14FB5D0);
	static inline auto FOnPlayerDuplicateCreated = PreyFunction<void(ArkAttentionManager* const _this, unsigned _doppelgangerEntityId)>(0x14F8D50);
	static inline auto FSerialize = PreyFunction<void(ArkAttentionManager* const _this, TSerialize _serializer)>(0x14FA400);
	static inline auto FGetNoiseAttentionParams = PreyFunction<const ArkNoiseAttentionParams& ()>(0x14F6D30);
	static inline auto FUpdateAttentionLevels = PreyFunction<void(ArkAttentionManager* const _this, float _elapsedTime)>(0x14FE050);
	static inline auto FUpdateTopAttentionTargets = PreyFunction<void(ArkAttentionManager* const _this)>(0x14FE680);
	static inline auto FSendAttentionLevelChangedNotifications = PreyFunction<void(ArkAttentionManager* const _this)>(0x14F9CC0);
	static inline auto FSendComplexAttentionProxyUpdatedNotifications = PreyFunction<void(ArkAttentionManager* const _this)>(0x14FA2D0);
	static inline auto FUpdateComplexAttentionProxy = PreyFunction<void(ArkAttentionManager* const _this, uint64_t _attentiveSubjectIndex, uint64_t _complexAttentionObjectIndex, boost::optional<Vec3_tpl<float> > _optAttentionPos)>(0x14FE340);
	static inline auto FAttentionPairIndex = PreyFunction<uint64_t(uint64_t _attentiveSubjectIndex, uint64_t _attentionObjectIndex, uint64_t _attentionObjectCount)>(0x14F4B50);
	static inline auto FLoadOv10 = PreyFunction<void(const XmlNodeRef& _node, ArkAttentionManager::HearingData& _hearingData)>(0x14F7FC0);
	static inline auto FLoadOv8 = PreyFunction<void(const XmlNodeRef& _node, ArkAttentionManager::RoomData& _roomData)>(0x14F81F0);
	static inline auto FLoadOv2 = PreyFunction<void(const XmlNodeRef& _node, ArkAttentionManager::ComplexAttentionModel& _complexAttentionModel)>(0x14F7950);
	static inline auto FLoadOv0 = PreyFunction<void(const XmlNodeRef& _node, ArkAttentionManager::AttentionModel& _attentionModel)>(0x14F7770);
	static inline auto FIncreaseAttention = PreyFunction<void(ArkAttentionManager::ComplexAttentionInfo& _attentionInfo, const std::array<ArkAttentionManager::AttentionLevelData, 5>& _levels, EArkAttentionLevel _level, EArkAttentionChangeReason _reason, bool _bGainMaxValue)>(0x14F7130);
	static inline auto FSetEntityOnComplexSeismicCooldown = PreyFunction<void(ArkAttentionManager* const _this, ArkAttentionManager::ComplexAttentionInfo& _complexAttentionInfo, unsigned _perceiverId, unsigned _seismicSourceId, ArkAttentionTag _lastTag)>(0x14FB690);
	static inline auto FLoadAttentionModels = PreyFunction<void(ArkAttentionManager* const _this)>(0x14F85B0);
	static inline auto FAssignAttentionModel = PreyFunction<void(ArkAttentionManager* const _this, uint64_t _attentiveSubjectIndex, const ArkAttentiveSubject& _attentiveSubject)>(0x14F4A10);
	static inline auto FGetAttentionModel = PreyFunction<const ArkAttentionManager::AttentionModel& (const ArkAttentionManager* const _this, uint64_t _attentiveSubjectIndex)>(0x14F62D0);
};
#endif // !MOONCRASH
