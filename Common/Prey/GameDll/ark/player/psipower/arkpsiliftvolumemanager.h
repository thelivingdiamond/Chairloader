// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/arkpsiliftvolume.h>

struct IEntity;
struct SEntityEvent;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h
template <typename T>
class ArkPsiLiftVolumeManager : public IEntityEventListener // Id=80141C4 Size=32
{
public:
	std::vector<T> m_liftVolumes;
	
#if 0
	void Reset();
	bool Update(const float arg0);
	unsigned SpawnLiftVolume(T *arg0);
	std::vector<T> const &GetLiftVolumes() const;
	void Serialize(TSerialize _ser);
	void PostSerialize();
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	bool HasLiftVolumes() const;
#endif
};

