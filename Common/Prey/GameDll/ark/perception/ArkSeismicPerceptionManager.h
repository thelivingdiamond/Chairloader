// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/perception/ArkComplexSeismicPerceptionInfo.h>
#include <Prey/GameDll/ark/perception/ArkSeismicBounds.h>
#include <Prey/GameDll/ark/perception/ArkSimpleSeismicPerceptionInfo.h>
#include <_unknown/TNavigationID.h>

class ArkSeismicPerceivable;
class ArkSeismicPerceiver;

// ArkSeismicPerceptionManager
// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
class ArkSeismicPerceptionManager
{ // Size=632 (0x278)
public:
	// ArkSeismicPerceptionManager::SimpleSeismicEvent
	// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
	struct SimpleSeismicEvent
	{ // Size=16 (0x10)
		unsigned m_instigatorEntityId;
		Vec3 m_position;

	#if 0
		SimpleSeismicEvent(unsigned _arg0_, const Vec3& _arg1_);
	#endif
	};

	// ArkSeismicPerceptionManager::ComplexSeismicEvent
	// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
	struct ComplexSeismicEvent
	{ // Size=24 (0x18)
		unsigned m_instigatorEntityId;
		unsigned m_eventSourceEntityId;
		Vec3 m_position;
		float m_magnitude;

	#if 0
		ComplexSeismicEvent(unsigned _arg0_, unsigned _arg1_, const Vec3& _arg2_, float _arg3_);
	#endif
	};

	// ArkSeismicPerceptionManager::SimpleTremor
	// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
	struct SimpleTremor
	{ // Size=20 (0x14)
		TNavigationID<0> m_meshId;
		unsigned m_instigatorEntityId;
		Vec3 m_position;

	#if 0
		SimpleTremor(TNavigationID<0> _arg0_, unsigned _arg1_, const Vec3& _arg2_);
	#endif
	};

	// ArkSeismicPerceptionManager::ComplexTremor
	// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
	struct ComplexTremor
	{ // Size=28 (0x1C)
		TNavigationID<0> m_meshId;
		unsigned m_instigatorEntityId;
		unsigned m_eventSourceEntityId;
		Vec3 m_position;
		float m_magnitude;

	#if 0
		ComplexTremor(TNavigationID<0> _arg0_, unsigned _arg1_, unsigned _arg2_, const Vec3& _arg3_, float _arg4_);
	#endif
	};

	// ArkSeismicPerceptionManager::MeshPerceiver
	// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
	struct MeshPerceiver
	{ // Size=16 (0x10)
		TNavigationID<0> m_meshId;
		uint64_t m_perceiverIndex;

	#if 0
		MeshPerceiver(TNavigationID<0> _arg0_, uint64_t _arg1_);
	#endif
	};

	// ArkSeismicPerceptionManager::MeshNotificationIndexes
	// Header:  Prey/GameDll/ark/perception/ArkSeismicPerceptionManager.h
	struct MeshNotificationIndexes
	{ // Size=24 (0x18)
		TNavigationID<0> m_meshId;
		uint64_t m_firstNotificationIndex;
		uint64_t m_lastNotificationIndex;

	#if 0
		MeshNotificationIndexes(TNavigationID<0> _arg0_, uint64_t _arg1_, uint64_t _arg2_);
	#endif
	};

	using ComplexSeismicEventVector = std::vector<ArkSeismicPerceptionManager::ComplexSeismicEvent>;
	using ComplexSeismicPerceptionInfoVector = std::vector<ArkComplexSeismicPerceptionInfo>;
	using ComplexTremorVector = std::vector<ArkSeismicPerceptionManager::ComplexTremor>;
	using EntityIdToIndexMap = std::unordered_map<unsigned int, uint64_t>;
	using IndexVector = std::vector<uint64_t>;
	using MeshNotificationIndexesVector = std::vector<ArkSeismicPerceptionManager::MeshNotificationIndexes>;
	using NavigationMeshIdVector = std::vector<TNavigationID<0>>;
	using PerceivableVector = std::vector<const ArkSeismicPerceivable*>;
	using MeshPerceiverVector = std::vector<ArkSeismicPerceptionManager::MeshPerceiver>;
	using PerceiverVector = std::vector<ArkSeismicPerceiver*>;
	using SeismicBoundsVector = std::vector<ArkSeismicBounds>;
	using SimpleSeismicEventVector = std::vector<ArkSeismicPerceptionManager::SimpleSeismicEvent>;
	using SimpleSeismicPerceptionInfoVector = std::vector<ArkSimpleSeismicPerceptionInfo>;
	using SimpleTremorVector = std::vector<ArkSeismicPerceptionManager::SimpleTremor>;

	TNavigationID<1> m_navigationAgentTypeId;
	std::unordered_map<unsigned int, uint64_t> m_perceiverIndexMap;
	std::unordered_map<unsigned int, uint64_t> m_simplePerceivableIndexMap;
	std::unordered_map<unsigned int, uint64_t> m_complexPerceivableIndexMap;
	std::vector<uint64_t> m_freePerceiverIndexes;
	std::vector<ArkSeismicPerceiver*> m_perceivers;
	std::vector<uint64_t> m_freeSimplePerceivableIndexes;
	std::vector<const ArkSeismicPerceivable*> m_simplePerceivables;
	std::vector<ArkSeismicBounds> m_simplePerceivableBounds;
	std::vector<uint64_t> m_freeComplexPerceivableIndexes;
	std::vector<const ArkSeismicPerceivable*> m_complexPerceivables;
	std::vector<ArkSeismicBounds> m_complexPerceivableBounds;
	std::vector<ArkSeismicPerceptionManager::SimpleSeismicEvent> m_simpleSeismicEvents;
	std::vector<ArkSeismicPerceptionManager::ComplexSeismicEvent> m_complexSeismicEvents;
	std::vector<ArkSeismicPerceptionManager::SimpleTremor> m_simpleTremors;
	std::vector<ArkSeismicPerceptionManager::ComplexTremor> m_complexTremors;
	std::vector<TNavigationID<0>> m_perceivedMeshIds;
	std::vector<ArkSeismicPerceptionManager::MeshPerceiver> m_meshPerceivers;
	std::vector<ArkSeismicPerceptionManager::MeshNotificationIndexes> m_simpleMeshNotificationIndexes;
	std::vector<ArkSeismicPerceptionManager::MeshNotificationIndexes> m_complexMeshNotificationIndexes;
	std::vector<ArkSimpleSeismicPerceptionInfo> m_simpleNotificationBuffer;
	std::vector<ArkComplexSeismicPerceptionInfo> m_complexNotificationBuffer;

	ArkSeismicPerceptionManager();
	void Initialize() { FInitialize(this); }
	void OnLevelLoadStart() { FOnLevelLoadStart(this); }
	void OnLevelLoadEnd() { FOnLevelLoadEnd(this); }
	void Reset(bool _bEnteringGameMode) { FReset(this, _bEnteringGameMode); }
	void RegisterPerceiver(unsigned _perceiverEntityId, ArkSeismicPerceiver& _perceiver) { FRegisterPerceiver(this, _perceiverEntityId, _perceiver); }
	bool IsPerceiverRegistered(unsigned _perceiverEntityId) { return FIsPerceiverRegistered(this, _perceiverEntityId); }
	void UnregisterPerceiver(unsigned _perceiverEntityId) { FUnregisterPerceiver(this, _perceiverEntityId); }
	void RegisterSimplePerceivable(unsigned _perceivableEntityId, const ArkSeismicPerceivable& _perceivable) { FRegisterSimplePerceivable(this, _perceivableEntityId, _perceivable); }
	bool IsSimplePerceivableRegistered(unsigned _perceivableEntityId) const { return FIsSimplePerceivableRegistered(this, _perceivableEntityId); }
	void UnregisterSimplePerceivable(unsigned _perceivableEntityId) { FUnregisterSimplePerceivable(this, _perceivableEntityId); }
	void RegisterComplexPerceivable(unsigned _perceivableEntityId, const ArkSeismicPerceivable& _perceivable) { FRegisterComplexPerceivable(this, _perceivableEntityId, _perceivable); }
	bool IsComplexPerceivableRegistered(unsigned _perceivableEntityId) const { return FIsComplexPerceivableRegistered(this, _perceivableEntityId); }
	void UnregisterComplexPerceivable(unsigned _perceivableEntityId) { FUnregisterComplexPerceivable(this, _perceivableEntityId); }
	void AddSimpleSeismicEvent(unsigned _sourceEntityId, const Vec3& _position) { FAddSimpleSeismicEvent(this, _sourceEntityId, _position); }
	void AddComplexSeismicEvent(unsigned _instigatorEntityId, unsigned _eventSourceEntityId, const Vec3& _position, float _magnitude) { FAddComplexSeismicEvent(this, _instigatorEntityId, _eventSourceEntityId, _position, _magnitude); }
	void Update(float _elapsedTime) { FUpdate(this, _elapsedTime); }
	void LoadSettings() { FLoadSettings(this); }
	void RegisterPerceivable(unsigned _perceivableEntityId, const ArkSeismicPerceivable& _perceivable, std::unordered_map<unsigned int, uint64_t>& _perceivableIndexMap, std::vector<uint64_t>& _freePerceivableIndexes, std::vector<const ArkSeismicPerceivable*>& _perceivables, std::vector<ArkSeismicBounds>& _perceivableBounds) const { FRegisterPerceivable(this, _perceivableEntityId, _perceivable, _perceivableIndexMap, _freePerceivableIndexes, _perceivables, _perceivableBounds); }
	bool IsPerceivableRegistered(unsigned _perceivableEntityId, const std::unordered_map<unsigned int, uint64_t>& _perceivableIndexMap) const { return FIsPerceivableRegistered(this, _perceivableEntityId, _perceivableIndexMap); }
	void UnregisterPerceivable(unsigned _perceivableEntityId, std::unordered_map<unsigned int, uint64_t>& _perceivableIndexMap, std::vector<uint64_t>& _freePerceivableIndexes, std::vector<const ArkSeismicPerceivable*>& _perceivables, std::vector<ArkSeismicBounds>& _perceivableBounds) const { FUnregisterPerceivable(this, _perceivableEntityId, _perceivableIndexMap, _freePerceivableIndexes, _perceivables, _perceivableBounds); }
	void RemoveOrphanSeismicEvents() { FRemoveOrphanSeismicEvents(this); }
	void GenerateTremors() { FGenerateTremors(this); }
	void RemoveUnperceivedTremors() { FRemoveUnperceivedTremors(this); }

#if 0
	ArkSeismicPerceptionManager(const ArkSeismicPerceptionManager& _arg0_);
	ArkSeismicPerceptionManager& operator=(const ArkSeismicPerceptionManager& _arg0_);
	uint64_t GetActivePerceiverCount() const;
	uint64_t GetActiveSimplePerceivableCount() const;
	uint64_t GetActiveComplexPerceivableCount() const;
	void GatherMeshPerceivers();
	void SortTremorsAndPerceiversByMeshId();
	void GatherNotifications();
	void GatherPerceivedMeshIds();
	void ProcessNotifications() const;
#endif

	static inline auto FArkSeismicPerceptionManagerOv1 = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12B9CE0);
	static inline auto FInitialize = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x1333E90);
	static inline auto FOnLevelLoadStart = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12BA5E0);
	static inline auto FOnLevelLoadEnd = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12BA5D0);
	static inline auto FReset = PreyFunction<void(ArkSeismicPerceptionManager* const _this, bool _bEnteringGameMode)>(0x12BAE90);
	static inline auto FRegisterPerceiver = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _perceiverEntityId, ArkSeismicPerceiver& _perceiver)>(0x12BA8D0);
	static inline auto FIsPerceiverRegistered = PreyFunction<bool(ArkSeismicPerceptionManager* const _this, unsigned _perceiverEntityId)>(0x12BA340);
	static inline auto FUnregisterPerceiver = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _perceiverEntityId)>(0x12BB020);
	static inline auto FRegisterSimplePerceivable = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId, const ArkSeismicPerceivable& _perceivable)>(0x12BA9D0);
	static inline auto FIsSimplePerceivableRegistered = PreyFunction<bool(const ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId)>(0x12BA3F0);
	static inline auto FUnregisterSimplePerceivable = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId)>(0x12BB130);
	static inline auto FRegisterComplexPerceivable = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId, const ArkSeismicPerceivable& _perceivable)>(0x12BA740);
	static inline auto FIsComplexPerceivableRegistered = PreyFunction<bool(const ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId)>(0x12BA280);
	static inline auto FUnregisterComplexPerceivable = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId)>(0x12BAEA0);
	static inline auto FAddSimpleSeismicEvent = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _sourceEntityId, const Vec3& _position)>(0x12B9EE0);
	static inline auto FAddComplexSeismicEvent = PreyFunction<void(ArkSeismicPerceptionManager* const _this, unsigned _instigatorEntityId, unsigned _eventSourceEntityId, const Vec3& _position, float _magnitude)>(0x12B9EA0);
	static inline auto FUpdate = PreyFunction<void(ArkSeismicPerceptionManager* const _this, float _elapsedTime)>(0x12BB170);
	static inline auto FLoadSettings = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12BA400);
	static inline auto FRegisterPerceivable = PreyFunction<void(const ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId, const ArkSeismicPerceivable& _perceivable, std::unordered_map<unsigned int, uint64_t>& _perceivableIndexMap, std::vector<uint64_t>& _freePerceivableIndexes, std::vector<const ArkSeismicPerceivable*>& _perceivables, std::vector<ArkSeismicBounds>& _perceivableBounds)>(0x12BA780);
	static inline auto FIsPerceivableRegistered = PreyFunction<bool(const ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId, const std::unordered_map<unsigned int, uint64_t>& _perceivableIndexMap)>(0x12BA290);
	static inline auto FUnregisterPerceivable = PreyFunction<void(const ArkSeismicPerceptionManager* const _this, unsigned _perceivableEntityId, std::unordered_map<unsigned int, uint64_t>& _perceivableIndexMap, std::vector<uint64_t>& _freePerceivableIndexes, std::vector<const ArkSeismicPerceivable*>& _perceivables, std::vector<ArkSeismicBounds>& _perceivableBounds)>(0x12BAEE0);
	static inline auto FRemoveOrphanSeismicEvents = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12BAA10);
	static inline auto FGenerateTremors = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12B9F00);
	static inline auto FRemoveUnperceivedTremors = PreyFunction<void(ArkSeismicPerceptionManager* const _this)>(0x12BABA0);
};
#endif // MOONCRASH
