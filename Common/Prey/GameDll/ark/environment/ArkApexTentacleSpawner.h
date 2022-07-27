// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arksimpletimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>

class ArkApexTentacle;
class ICrySizer;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// Header: FromCpp
// Prey/GameDll/ark/environment/ArkApexTentacleSpawner.h
class ArkApexTentacleSpawner : public ArkEnvironmentalObject // Id=801A908 Size=240
{
public:
	struct TentaclesToPlace // Id=801A909 Size=16
	{
		IEntityArchetype *m_pArchetype;
		int m_count;
		float m_radius;
		
#if 0
		bool operator==(IEntityArchetype *arg0) const;
		bool operator<(ArkApexTentacleSpawner::TentaclesToPlace const &arg0) const;
#endif
	};

	struct SpawnedTentacle // Id=801A91E Size=20
	{
		unsigned m_tentacleId;
		unsigned m_linkedTarget;
		Vec2 m_placementPos;
		float m_radius;
		
#if 0
		bool operator==(const unsigned arg0) const;
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkApexTentacleSpawner::SpawnedTentacle> m_spawnedTentacles;
	
	struct RespawnData // Id=801A933 Size=16
	{
		uint64_t m_archetypeId;
		ArkTimeRemaining m_timer;
		
#if 0
		void Serialize(TSerialize arg0);
#endif
	};

	std::vector<ArkApexTentacleSpawner::RespawnData> m_tentaclesToRespawn;
	std::vector<unsigned int> m_availableLinkedTargets;
	ArkAutoResetTimer m_playerReevaluationTimer;
	bool m_bNeedsInitialSpawn;
	float m_height;
	float m_width;
	float m_minDistBetweenSpawns;
	float m_respawnDuration;
	float m_minDistBetweenTargetsSq;
	float m_playerSpeedThresholdSq;
	float m_inFrontOfPlayerPreference;
	int m_numToSpawn;
	
	struct SpawnProbability // Id=801A948 Size=16
	{
		uint64_t m_archetypeId;
		float m_probability;
		
#if 0
		bool operator==(const uint64_t arg0) const;
#endif
	};

	std::vector<ArkApexTentacleSpawner::SpawnProbability> m_spawnProbabilities;
	bool m_bStartsEnabled;
	
	ArkApexTentacleSpawner();
	virtual void PostInit(IGameObject *_pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void ProcessEvent(SEntityEvent &_event);
	virtual void GetMemoryUsage(ICrySizer *_pSizer) const;
	virtual void Update(SEntityUpdateContext &_ctx, int _updateSlot);
	void SetEnabled(bool _bEnabled) { FSetEnabled(this,_bEnabled); }
	bool CanTentacleTargetEntity(ArkApexTentacle const *_pTentacle, IEntity const *_pTarget) const { return FCanTentacleTargetEntity(this,_pTentacle,_pTarget); }
	void TentacleKilled(IEntity const *const _pTentacle) { FTentacleKilled(this,_pTentacle); }
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	void SpawnTentacles() { FSpawnTentacles(this); }
	void SetLinkTargets() { FSetLinkTargets(this); }
	void ReevaluatePlayerAsTarget() { FReevaluatePlayerAsTarget(this); }
	void AddTentacleToPlace(uint64_t _archetypeId, const int _count, std::vector<ArkApexTentacleSpawner::TentaclesToPlace> &_tentaclesToPlace) const { FAddTentacleToPlace(this,_archetypeId,_count,_tentaclesToPlace); }
	bool SpawnTentaclesToPlace(std::vector<ArkApexTentacleSpawner::TentaclesToPlace> &_tentaclesToPlace) { return FSpawnTentaclesToPlace(this,_tentaclesToPlace); }
	
#if 0
	bool PopulateTentaclesToPlace(std::vector<ArkApexTentacleSpawner::TentaclesToPlace> &arg0) const;
#endif
	
	static inline auto FPostInit = PreyFunction<void(ArkApexTentacleSpawner *const _this, IGameObject *_pGameObject)>(0x126DA10);
	static inline auto FFullSerialize = PreyFunction<void(ArkApexTentacleSpawner *const _this, TSerialize _ser)>(0x126CEC0);
	static inline auto FProcessEvent = PreyFunction<void(ArkApexTentacleSpawner *const _this, SEntityEvent &_event)>(0x126DAB0);
	static inline auto FGetMemoryUsage = PreyFunction<void(ArkApexTentacleSpawner const *const _this, ICrySizer *_pSizer)>(0x126D040);
	static inline auto FUpdate = PreyFunction<void(ArkApexTentacleSpawner *const _this, SEntityUpdateContext &_ctx, int _updateSlot)>(0x126FA40);
	static inline auto FSetEnabled = PreyFunction<void(ArkApexTentacleSpawner *const _this, bool _bEnabled)>(0x126E180);
	static inline auto FCanTentacleTargetEntity = PreyFunction<bool(ArkApexTentacleSpawner const *const _this, ArkApexTentacle const *_pTentacle, IEntity const *_pTarget)>(0x126CD10);
	static inline auto FTentacleKilled = PreyFunction<void(ArkApexTentacleSpawner *const _this, IEntity const *const _pTentacle)>(0x126F940);
	static inline auto FOnReset = PreyFunction<void(ArkApexTentacleSpawner *const _this, bool _bEnteringGameMode)>(0x126D960);
	static inline auto FLoadProperties = PreyFunction<void(ArkApexTentacleSpawner *const _this)>(0x126D140);
	static inline auto FSpawnTentacles = PreyFunction<void(ArkApexTentacleSpawner *const _this)>(0x126EA60);
	static inline auto FSetLinkTargets = PreyFunction<void(ArkApexTentacleSpawner *const _this)>(0x126E220);
	static inline auto FReevaluatePlayerAsTarget = PreyFunction<void(ArkApexTentacleSpawner *const _this)>(0x126DBF0);
	static inline auto FAddTentacleToPlace = PreyFunction<void(ArkApexTentacleSpawner const *const _this, uint64_t _archetypeId, const int _count, std::vector<ArkApexTentacleSpawner::TentaclesToPlace> &_tentaclesToPlace)>(0x126CBB0);
	static inline auto FSpawnTentaclesToPlace = PreyFunction<bool(ArkApexTentacleSpawner *const _this, std::vector<ArkApexTentacleSpawner::TentaclesToPlace> &_tentaclesToPlace)>(0x126ECE0);
};

