// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/environment/ArkApexTentacleSpawnerBase.h>

class ICrySizer;
struct IEntity;
struct IGameObject;
struct SEntityEvent;
struct SEntityUpdateContext;

// ArkApexTentaclePinholeSpawner
// Header:  Prey/GameDll/ark/environment/ArkApexTentaclePinholeSpawner.h
class ArkApexTentaclePinholeSpawner : public ArkApexTentacleSpawnerBase
{ // Size=736 (0x2E0)
public:
	enum class ForceType
	{
		none = 0,
		init = 1,
		serialize = 2,
	};

	std::vector<unsigned int> m_tentacles;
	EArkTentaclePinholeSpawnerState m_state;
	ArkTimeRemaining m_stateTimer;
	int m_activeTentacles;
	bool m_bFromPlayerWeapon;
	uint64_t m_tentacleArchetype;
	float m_destructionTime;
	float m_creationTime;
	float m_targetAcquisitionRange;
	float m_idealAngleSeparationCos;
	float m_idealTargetDepth;
	ArkEntityEffect m_inactiveVfx;
	ArkEntityEffect m_creationVfx;
	ArkEntityEffect m_activeVfx;
	ArkEntityEffect m_destructionVfx;

	ArkApexTentaclePinholeSpawner();
	virtual void PostInit(IGameObject* _pGameObject);
	virtual void FullSerialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual void ProcessEvent(SEntityEvent& _event);
	virtual void GetMemoryUsage(ICrySizer* _pSizer) const;
	virtual void Update(SEntityUpdateContext& _ctx, int _updateSlot);
	virtual void TentacleKilled(const IEntity* const _pTentacle);
	virtual void SetEnabled(const bool _bEnabled);
	virtual unsigned GetWeaponId() const;
	virtual std::vector<unsigned int> GetTentaclesAndHeads() const;
	virtual void OnReset(bool _bEnteringGameMode);
	virtual void LoadProperties();
	virtual std::vector<unsigned int> GetTentacles() const;
	void SpawnTentacles() { FSpawnTentacles(this); }
	std::vector<std::pair<unsigned int, Vec3>> GatherTargets() const { alignas(std::vector<std::pair<unsigned int, Vec3>>) std::byte _return_buf_[sizeof(std::vector<std::pair<unsigned int, Vec3>>)]; return *FGatherTargets(this, reinterpret_cast<std::vector<std::pair<unsigned int, Vec3>>*>(_return_buf_)); }
	Vec3 PickAttackDir(const std::vector<Vec3>& _prevAttackDirections) const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FPickAttackDir(this, reinterpret_cast<Vec3*>(_return_buf_), _prevAttackDirections); }
	virtual void Deactivate_Internal();
	void SetState(EArkTentaclePinholeSpawnerState _state, ArkApexTentaclePinholeSpawner::ForceType _forceType) { FSetState(this, _state, _forceType); }
	void CleanupTentacles() { FCleanupTentacles(this); }

	static inline auto FArkApexTentaclePinholeSpawnerOv2 = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this)>(0x12344B0);
	static inline auto FPostInit = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, IGameObject* _pGameObject)>(0x1235E80);
	static inline auto FFullSerialize = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, TSerialize _ser)>(0x12347A0);
	static inline auto FPostSerialize = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this)>(0x1235EE0);
	static inline auto FProcessEvent = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, SEntityEvent& _event)>(0x1236020);
	static inline auto FGetMemoryUsage = PreyFunction<void(const ArkApexTentaclePinholeSpawner* const _this, ICrySizer* _pSizer)>(0x1234E70);
	static inline auto FUpdate = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, SEntityUpdateContext& _ctx, int _updateSlot)>(0x1236A60);
	static inline auto FTentacleKilled = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, const IEntity* const _pTentacle)>(0x1236920);
	static inline auto FSetEnabled = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, const bool _bEnabled)>(0x1236030);
	static inline auto FGetWeaponId = PreyFunction<unsigned(const ArkApexTentaclePinholeSpawner* const _this)>(0x1234F80);
	static inline auto FGetTentaclesAndHeads = PreyFunction<std::vector<unsigned int>*(const ArkApexTentaclePinholeSpawner* const _this, std::vector<unsigned int>* _return_value_)>(0x1234EF0);
	static inline auto FOnReset = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, bool _bEnteringGameMode)>(0x1235730);
	static inline auto FLoadProperties = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this)>(0x1235120);
	static inline auto FGetTentacles = PreyFunction<std::vector<unsigned int>*(const ArkApexTentaclePinholeSpawner* const _this, std::vector<unsigned int>* _return_value_)>(0x1234ED0);
	static inline auto FSpawnTentacles = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this)>(0x12361D0);
	static inline auto FGatherTargets = PreyFunction<std::vector<std::pair<unsigned int, Vec3>>*(const ArkApexTentaclePinholeSpawner* const _this, std::vector<std::pair<unsigned int, Vec3>>* _return_value_)>(0x1234AB0);
	static inline auto FPickAttackDir = PreyFunction<Vec3*(const ArkApexTentaclePinholeSpawner* const _this, Vec3* _return_value_, const std::vector<Vec3>& _prevAttackDirections)>(0x1235770);
	static inline auto FDeactivate_Internal = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this)>(0x12346E0);
	static inline auto FSetState = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this, EArkTentaclePinholeSpawnerState _state, ArkApexTentaclePinholeSpawner::ForceType _forceType)>(0x1236050);
	static inline auto FCleanupTentacles = PreyFunction<void(ArkApexTentaclePinholeSpawner* const _this)>(0x1234640);
};
#endif // MOONCRASH
