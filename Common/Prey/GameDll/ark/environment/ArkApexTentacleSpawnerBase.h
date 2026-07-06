// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/environment/ArkEnvironmentalObject.h>

class ArkApexTentacle;
struct IEntity;

// ArkApexTentacleSpawnerBase
// Header:  Prey/GameDll/ark/environment/ArkApexTentacleSpawnerBase.h
class ArkApexTentacleSpawnerBase : public ArkEnvironmentalObject
{ // Size=120 (0x78)
public:
	ArkAutoResetTimer m_playerReevaluationTimer;
	int m_numToSpawn;
	bool m_bStartsEnabled;
	float m_minDistBetweenTargetsSq;
	float m_playerSpeedThresholdSq;
	float m_inFrontOfPlayerPreference;

	ArkApexTentacleSpawnerBase();
	virtual void SetEnabled(bool _bEnabled) = 0;
	bool CanTentacleTargetEntity(const ArkApexTentacle* _pTentacle, const IEntity* _pTarget) const { return FCanTentacleTargetEntity(this, _pTentacle, _pTarget); }
	virtual void TentacleKilled(const IEntity* const _pTentacle) = 0;
	void DeactivateSpawner() { FDeactivateSpawner(this); }
	bool IsActive() const { return FIsActive(this); }
	virtual unsigned GetWeaponId() const;
	virtual std::vector<unsigned int> GetTentacles() const = 0;
	virtual std::vector<unsigned int> GetTentaclesAndHeads() const = 0;
	void ReevaluatePlayerAsTarget() { FReevaluatePlayerAsTarget(this); }
	virtual void LoadProperties();
	virtual void Deactivate_Internal() = 0;

#if 0
	void DissipateAllTentacles();
#endif

	static inline auto FArkApexTentacleSpawnerBaseOv2 = PreyFunction<void(ArkApexTentacleSpawnerBase* const _this)>(0x1236DD0);
	static inline auto FCanTentacleTargetEntity = PreyFunction<bool(const ArkApexTentacleSpawnerBase* const _this, const ArkApexTentacle* _pTentacle, const IEntity* _pTarget)>(0x1236E90);
	static inline auto FDeactivateSpawner = PreyFunction<void(ArkApexTentacleSpawnerBase* const _this)>(0x1237140);
	static inline auto FIsActive = PreyFunction<bool(const ArkApexTentacleSpawnerBase* const _this)>(0x1237250);
	static inline auto FGetWeaponId = PreyFunction<unsigned(const ArkApexTentacleSpawnerBase* const _this)>(0x1CBB0B0);
	static inline auto FReevaluatePlayerAsTarget = PreyFunction<void(ArkApexTentacleSpawnerBase* const _this)>(0x1237920);
	static inline auto FLoadProperties = PreyFunction<void(ArkApexTentacleSpawnerBase* const _this)>(0x12373A0);
};
#endif // MOONCRASH
