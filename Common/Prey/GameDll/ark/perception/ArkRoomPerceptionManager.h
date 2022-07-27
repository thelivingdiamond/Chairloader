// Header file automatically created from a PDB.

#pragma once

class ArkComplexRoomPerceivable;
class ArkRoomPerceiver;

// Header: FromCpp
// Prey/GameDll/ark/perception/ArkRoomPerceptionManager.h
class ArkRoomPerceptionManager // Id=8015056 Size=408
{
public:
	struct RoomPerceptionModel // Id=8015058 Size=16
	{
		int m_id;
		float m_dropoffStartTime;
		float m_dropoffEndTime;
		float m_dropoffEndMagnitude;
	};

	using UniqueIdToIndexMap = std::unordered_map<unsigned __int64,unsigned __int64>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int,unsigned __int64>;
	using RoomPerceiverVector = std::vector<ArkRoomPerceiver *>;
	using ComplexPerceivableVector = std::vector<ArkComplexRoomPerceivable const *>;
	using EntityIdVector = std::vector<unsigned int>;
	using IndexVector = std::vector<unsigned __int64>;
	using ComplexRoomPerceptionInfoVector = std::vector<ArkComplexRoomPerceptionInfo>;
	using RoomPerceptionModelVector = std::vector<ArkRoomPerceptionManager::RoomPerceptionModel>;
	
	struct PerceiverData // Id=8015092 Size=80
	{
		using EntityIdToTimeMap = std::unordered_map<unsigned int,float>;
		
		uint64_t m_perceptionModelIndex;
		unsigned m_perceiverRoomEntityid;
		std::unordered_map<unsigned int,float> m_perceivableEntityTimes;
		
#if 0
		void Reset();
#endif
	};

	using PerceiverDataVector = std::vector<ArkRoomPerceptionManager::PerceiverData>;
	
	std::vector<ArkRoomPerceptionManager::RoomPerceptionModel> m_models;
	std::unordered_map<unsigned __int64,unsigned __int64> m_modelIdMap;
	std::unordered_map<unsigned int,unsigned __int64> m_perceiverIndexMap;
	std::unordered_map<unsigned int,unsigned __int64> m_complexPerceivableIndexMap;
	std::vector<unsigned __int64> m_freePerceiverIndexes;
	std::vector<ArkRoomPerceiver *> m_perceivers;
	std::vector<ArkRoomPerceptionManager::PerceiverData> m_perceiversData;
	std::vector<unsigned __int64> m_freeComplexPerceivableIndexes;
	std::vector<ArkComplexRoomPerceivable const *> m_complexPerceivables;
	std::vector<ArkComplexRoomPerceptionInfo> m_complexStartNotificationBuffer;
	std::vector<ArkComplexRoomPerceptionInfo> m_complexContinueNotificationBuffer;
	std::vector<unsigned int> m_complexStopNotificationBuffer;
	
	ArkRoomPerceptionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void RegisterPerceiver(unsigned _perceiverEntityId, ArkRoomPerceiver &_perceiver) { FRegisterPerceiver(this,_perceiverEntityId,_perceiver); }
	bool IsPerceiverRegistered(unsigned _perceiverEntityId) { return FIsPerceiverRegistered(this,_perceiverEntityId); }
	void UnregisterPerceiver(unsigned _perceiverEntityId) { FUnregisterPerceiver(this,_perceiverEntityId); }
	void RegisterComplexPerceivable(unsigned _complexPerceivableEntityId, ArkComplexRoomPerceivable const &_complexPerceivable) { FRegisterComplexPerceivable(this,_complexPerceivableEntityId,_complexPerceivable); }
	bool IsComplexPerceivableRegistered(unsigned _complexPerceivableEntityId) const { return FIsComplexPerceivableRegistered(this,_complexPerceivableEntityId); }
	void UnregisterComplexPerceivable(unsigned _complexPerceivableEntityId) { FUnregisterComplexPerceivable(this,_complexPerceivableEntityId); }
	void Update(float _elapsedTime) { FUpdate(this,_elapsedTime); }
	
	static inline auto FInitialize = PreyFunction<void(ArkRoomPerceptionManager *const _this)>(0x12B0290);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkRoomPerceptionManager *const _this)>(0x12B0860);
	static inline auto FRegisterPerceiver = PreyFunction<void(ArkRoomPerceptionManager *const _this, unsigned _perceiverEntityId, ArkRoomPerceiver &_perceiver)>(0x12B0A70);
	static inline auto FIsPerceiverRegistered = PreyFunction<bool(ArkRoomPerceptionManager *const _this, unsigned _perceiverEntityId)>(0x12B07A0);
	static inline auto FUnregisterPerceiver = PreyFunction<void(ArkRoomPerceptionManager *const _this, unsigned _perceiverEntityId)>(0x12B0EA0);
	static inline auto FRegisterComplexPerceivable = PreyFunction<void(ArkRoomPerceptionManager *const _this, unsigned _complexPerceivableEntityId, ArkComplexRoomPerceivable const &_complexPerceivable)>(0x12B0970);
	static inline auto FIsComplexPerceivableRegistered = PreyFunction<bool(ArkRoomPerceptionManager const *const _this, unsigned _complexPerceivableEntityId)>(0x12B06E0);
	static inline auto FUnregisterComplexPerceivable = PreyFunction<void(ArkRoomPerceptionManager *const _this, unsigned _complexPerceivableEntityId)>(0x12B0D80);
	static inline auto FUpdate = PreyFunction<void(ArkRoomPerceptionManager *const _this, float _elapsedTime)>(0x12B1010);
};

