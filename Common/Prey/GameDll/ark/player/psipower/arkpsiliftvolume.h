// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/npc/ArkNpc.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLift.h>
#include <Prey/GameDll/ark/player/psipower/arkplayerliftentity.h>
#include <Prey/GameDll/ark/player/psipower/arkplayerliftentityzerog.h>
#include <Prey/ArkCommon/reflect/arkreflectionaccessors.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolume.h>

struct IEntity;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsiliftvolume.h
template <typename T>
class ArkPsiLiftVolume // Id=80141B6 Size=112
{
public:
	using LiftEntity = ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>;
	
	ArkPsiLift m_psiLift;
	ArkSimpleTimer m_aliveTimer;
	ArkSimpleTimer m_queryTimer;
	T m_entitySpawner;
	std::vector<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>> m_containedEntities;
	float m_gravity;
	
#if 0
	ArkPsiLiftVolume &operator=(ArkPsiLiftVolume *_lift);
	bool operator==(ArkPsiLiftVolume const &arg0) const;
	bool Update(const float _frameTime);
	void Serialize(TSerialize arg0);
	void PostSerialize();
	void OnEnterArea(IEntity const &arg0);
	ArkPsiLift const &GetPsiLift() const;
	bool IsInside(unsigned arg0) const;
	void InitializeArea();
#endif
};

