// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLift.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolumeEntity.h>

struct IEntity;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsiliftvolume.h
// Instantiations (all Size=112): ArkNpc::LiftEntitySpawner,
// ArkPlayerLiftEntitySpawner, ArkPlayerLiftEntityZeroGSpawner.
// No addresses: they differ per instantiation.
template <typename T>
class ArkPsiLiftVolume // Id=80141B6 Size=112
{ // Size=112 (0x70)
public:
	// ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity> for the NPC/player spawners,
	// ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG> for ArkPlayerLiftEntityZeroGSpawner.
	using LiftEntity = decltype(std::declval<const T&>().Spawn(0u));

	ArkPsiLift m_psiLift;
	ArkSimpleTimer m_aliveTimer;
	ArkSimpleTimer m_queryTimer;
	T m_entitySpawner;
	std::vector<LiftEntity> m_containedEntities;
	float m_gravity;

	ArkPsiLiftVolume();
	ArkPsiLiftVolume(ArkPsiLift&& _lift, float _gravity, float _durationSec);
	ArkPsiLiftVolume(ArkPsiLiftVolume&& _liftVolume);
	ArkPsiLiftVolume& operator=(ArkPsiLiftVolume&& _lift);
	bool operator==(const ArkPsiLiftVolume& _lift) const;
	bool Update(float _frameTime);
	void Serialize(TSerialize _ser);
	void PostSerialize();
	void OnEnterArea(const IEntity& _entity);
	bool IsInside(unsigned _entityId) const;
	void InitializeArea();

#if 0
	ArkPsiLiftVolume(const ArkPsiLiftVolume& _arg0_);
	ArkPsiLiftVolume& operator=(const ArkPsiLiftVolume& _arg0_);
	const ArkPsiLift& GetPsiLift() const;
#endif
};
