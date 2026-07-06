// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h>

struct IEntity;
struct SEntityEvent;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h
template <typename T>
class ArkPsiLiftVolumeManager : public IEntityEventListener // Id=80141C4 Size=32
{
public:
	std::vector<T> m_liftVolumes;
	
	void Reset();
	bool Update(const float arg0);
	unsigned SpawnLiftVolume(T *arg0);
	std::vector<T> const &GetLiftVolumes() const;
	void Serialize(TSerialize _ser);
	void PostSerialize();
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	bool HasLiftVolumes() const;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h>

struct IEntity;
struct SEntityEvent;

// ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >
// Header:  Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h
class ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> > : public IEntityEventListener
{ // Size=32 (0x20)
public:
	std::vector<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>> m_liftVolumes;

	virtual ~ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >();
	void Reset() { FReset(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >();
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >(const ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >& _arg0_);
	bool Update(const float _arg0_);
	unsigned SpawnLiftVolume(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>&& _arg0_);
	const std::vector<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>>& GetLiftVolumes() const;
	void PostSerialize();
	bool HasLiftVolumes() const;
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >& operator=(const ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >& _arg0_);
#endif

	static inline auto FReset = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >* const _this)>(0x125D550);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >* const _this, TSerialize _ser)>(0x16200E0);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner> >* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x1617B40);
};

// ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >
// Header:  Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h
class ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> > : public IEntityEventListener
{ // Size=32 (0x20)
public:
	std::vector<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>> m_liftVolumes;

	virtual ~ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >();
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >(const ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >& _arg0_);
	void Reset();
	bool Update(const float _arg0_);
	unsigned SpawnLiftVolume(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>&& _arg0_);
	const std::vector<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>>& GetLiftVolumes() const;
	void PostSerialize();
	bool HasLiftVolumes() const;
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >& operator=(const ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >& _arg0_);
#endif

	static inline auto FBitNotArkPsiLiftVolumeManagerLessArkPsiLiftVolumeLessArkPlayerLiftEntitySpawnerGreater Greater = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >* const _this)>(0x16BB4A0);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >* const _this, TSerialize _ser)>(0x16BC300);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner> >* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x16BBFF0);
};

// ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >
// Header:  Prey/GameDll/ark/player/psipower/arkpsiliftvolumemanager.h
class ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> > : public IEntityEventListener
{ // Size=32 (0x20)
public:
	std::vector<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>> m_liftVolumes;

	virtual ~ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >();
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >();
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >(const ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >& _arg0_);
	void Reset();
	bool Update(const float _arg0_);
	unsigned SpawnLiftVolume(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>&& _arg0_);
	const std::vector<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>>& GetLiftVolumes() const;
	void PostSerialize();
	bool HasLiftVolumes() const;
	ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >& operator=(const ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >& _arg0_);
#endif

	static inline auto FBitNotArkPsiLiftVolumeManagerLessArkPsiLiftVolumeLessArkPlayerLiftEntityZeroGSpawnerGreater Greater = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >* const _this)>(0x16BB5D0);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >* const _this, TSerialize _ser)>(0x16BC760);
	static inline auto FOnEntityEvent = PreyFunction<void(ArkPsiLiftVolumeManager<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner> >* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x16BC060);
};
#endif // !MOONCRASH
