// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
//#include <Prey/GameDll/ark/npc/ArkNpc.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLift.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLiftVolumeEntity.h>

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
	ArkPsiLiftVolume& operator=(ArkPsiLiftVolume* _lift);
	bool operator==(ArkPsiLiftVolume const& arg0) const;
	bool Update(const float _frameTime);
	void Serialize(TSerialize arg0);
	void PostSerialize();
	void OnEnterArea(IEntity const& arg0);
	ArkPsiLift const& GetPsiLift() const;
	bool IsInside(unsigned arg0) const;
	void InitializeArea();
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/npc/ArkNpc.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntity.h>
#include <Prey/GameDll/ark/player/psipower/ArkPlayerLiftEntityZeroG.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiLift.h>

struct IEntity;

// ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h
class ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>
{ // Size=20 (0x14)
public:
	ArkPlayerLiftEntity m_derived;
	unsigned m_entityId;

#if 0
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>&& _arg0_);
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>(const unsigned _arg0_, ArkPlayerLiftEntity _arg1_);
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>(const ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>& _arg0_);
	~ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>& operator=(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>&& _arg0_);
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>& operator=(const ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>& _arg0_);
	void Update(const ArkPsiLift& _arg0_, const float _arg1_) const;
	void PostSerialize() const;
	unsigned GetEntityId() const;
#endif
};

// ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h
class ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>
{ // Size=112 (0x70)
public:
	using LiftEntity = ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>;

	ArkPsiLift m_psiLift;
	ArkSimpleTimer m_aliveTimer;
	ArkSimpleTimer m_queryTimer;
	ArkNpc::LiftEntitySpawner m_entitySpawner;
	std::vector<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>> m_containedEntities;
	float m_gravity;

	ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>();
	ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>(ArkPsiLift&& _lift, float _gravity, float _durationSec);
	ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>&& _liftVolume);
	ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& operator=(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>&& _lift) { return FoperatorEqOv1(this, _lift); }
	bool operator==(const ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& _lift) const { return FoperatorEqEq(this, _lift); }
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnEnterArea(const IEntity& _entity) { FOnEnterArea(this, _entity); }
	bool IsInside(unsigned _entityId) const { return FIsInside(this, _entityId); }
	void InitializeArea() { FInitializeArea(this); }

#if 0
	ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>(const ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& _arg0_);
	ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& operator=(const ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& _arg0_);
	const ArkPsiLift& GetPsiLift() const;
#endif

	static inline auto FArkPsiLiftVolumeLessArkNpc::LiftEntitySpawnerGreaterOv3 = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this)>(0x13ABDB0);
	static inline auto FArkPsiLiftVolumeLessArkNpc::LiftEntitySpawnerGreaterOv2 = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, ArkPsiLift&& _lift, float _gravity, float _durationSec)>(0x13ABFA0);
	static inline auto FArkPsiLiftVolumeLessArkNpc::LiftEntitySpawnerGreaterOv1 = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>&& _liftVolume)>(0x13ABD30);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& (ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>&& _lift)>(0x13AC080);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, const ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>& _lift)>(0x13AC130);
	static inline auto FUpdate = PreyFunction<bool(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, float _frameTime)>(0x13AD9D0);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, TSerialize _ser)>(0x13ACE50);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this)>(0x13ACD80);
	static inline auto FOnEnterArea = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, const IEntity& _entity)>(0x13ACC20);
	static inline auto FIsInside = PreyFunction<bool(const ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this, unsigned _entityId)>(0x13AC930);
	static inline auto FInitializeArea = PreyFunction<void(ArkPsiLiftVolume<ArkNpc::LiftEntitySpawner>* const _this)>(0x13AC140);
};

// ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h
class ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>
{ // Size=112 (0x70)
public:
	using LiftEntity = ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>;

	ArkPsiLift m_psiLift;
	ArkSimpleTimer m_aliveTimer;
	ArkSimpleTimer m_queryTimer;
	ArkPlayerLiftEntitySpawner m_entitySpawner;
	std::vector<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntity>> m_containedEntities;
	float m_gravity;

	ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>();
	ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>(ArkPsiLift&& _lift, float _gravity, float _durationSec);
	ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>&& _liftVolume);
	ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& operator=(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>&& _lift) { return FoperatorEqOv1(this, _lift); }
	bool operator==(const ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& _lift) const { return FoperatorEqEq(this, _lift); }
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnEnterArea(const IEntity& _entity) { FOnEnterArea(this, _entity); }
	void InitializeArea() { FInitializeArea(this); }

#if 0
	ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>(const ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& _arg0_);
	ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& operator=(const ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& _arg0_);
	const ArkPsiLift& GetPsiLift() const;
	bool IsInside(unsigned _arg0_) const;
#endif

	static inline auto FArkPsiLiftVolumeLessArkPlayerLiftEntitySpawnerGreaterOv3 = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this)>(0x13ABDB0);
	static inline auto FArkPsiLiftVolumeLessArkPlayerLiftEntitySpawnerGreaterOv2 = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, ArkPsiLift&& _lift, float _gravity, float _durationSec)>(0x13ABFA0);
	static inline auto FArkPsiLiftVolumeLessArkPlayerLiftEntitySpawnerGreaterOv1 = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>&& _liftVolume)>(0x13ABD30);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& (ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>&& _lift)>(0x13AC080);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, const ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>& _lift)>(0x13AC130);
	static inline auto FUpdate = PreyFunction<bool(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, float _frameTime)>(0x13ACF50);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, TSerialize _ser)>(0x13ACE50);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this)>(0x13ACD80);
	static inline auto FOnEnterArea = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this, const IEntity& _entity)>(0x13AC960);
	static inline auto FInitializeArea = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntitySpawner>* const _this)>(0x13AC140);
};

// ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h
class ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>
{ // Size=16 (0x10)
public:
	ArkPlayerLiftEntityZeroG m_derived;
	unsigned m_entityId;

#if 0
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>&& _arg0_);
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>(const unsigned _arg0_, ArkPlayerLiftEntityZeroG _arg1_);
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>(const ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>& _arg0_);
	~ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>();
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>& operator=(ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>&& _arg0_);
	ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>& operator=(const ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>& _arg0_);
	void Update(const ArkPsiLift& _arg0_, const float _arg1_) const;
	void PostSerialize() const;
	unsigned GetEntityId() const;
#endif
};

// ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiLiftVolume.h
class ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>
{ // Size=112 (0x70)
public:
	using LiftEntity = ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>;

	ArkPsiLift m_psiLift;
	ArkSimpleTimer m_aliveTimer;
	ArkSimpleTimer m_queryTimer;
	ArkPlayerLiftEntityZeroGSpawner m_entitySpawner;
	std::vector<ArkPsiLiftVolumeEntity<ArkPlayerLiftEntityZeroG>> m_containedEntities;
	float m_gravity;

	ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>();
	ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>(ArkPsiLift&& _lift, float _gravity, float _durationSec);
	ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>&& _liftVolume);
	ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& operator=(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>&& _lift) { return FoperatorEqOv1(this, _lift); }
	bool operator==(const ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& _lift) const { return FoperatorEqEq(this, _lift); }
	bool Update(float _frameTime) { return FUpdate(this, _frameTime); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	void PostSerialize() { FPostSerialize(this); }
	void OnEnterArea(const IEntity& _entity) { FOnEnterArea(this, _entity); }
	void InitializeArea() { FInitializeArea(this); }

#if 0
	ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>(const ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& _arg0_);
	ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& operator=(const ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& _arg0_);
	const ArkPsiLift& GetPsiLift() const;
	bool IsInside(unsigned _arg0_) const;
#endif

	static inline auto FArkPsiLiftVolumeLessArkPlayerLiftEntityZeroGSpawnerGreaterOv3 = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this)>(0x13ABF50);
	static inline auto FArkPsiLiftVolumeLessArkPlayerLiftEntityZeroGSpawnerGreaterOv2 = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, ArkPsiLift&& _lift, float _gravity, float _durationSec)>(0x13ABE80);
	static inline auto FArkPsiLiftVolumeLessArkPlayerLiftEntityZeroGSpawnerGreaterOv1 = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>&& _liftVolume)>(0x13ABE00);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& (ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>&& _lift)>(0x13AC080);
	static inline auto FoperatorEqEq = PreyFunction<bool(const ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, const ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>& _lift)>(0x13AC130);
	static inline auto FUpdate = PreyFunction<bool(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, float _frameTime)>(0x13AD490);
	static inline auto FSerialize = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, TSerialize _ser)>(0x13ACE50);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this)>(0x13ACDF0);
	static inline auto FOnEnterArea = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this, const IEntity& _entity)>(0x13ACAC0);
	static inline auto FInitializeArea = PreyFunction<void(ArkPsiLiftVolume<ArkPlayerLiftEntityZeroGSpawner>* const _this)>(0x13AC140);
};
#endif // !MOONCRASH
