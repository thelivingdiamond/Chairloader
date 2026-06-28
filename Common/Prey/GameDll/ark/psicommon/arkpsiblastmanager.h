// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

class ArkPsiElectrostaticBurstProperties;
class ArkPsiFearBlastProperties;
class ArkPsiKineticBlastProperties;
class ArkPsiPowerTargetingComponent;
class ArkPsiThermalBlastProperties;
struct IEntity;
struct SEntityEvent;

// Header: Exact
// Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
template <typename T>
class CArkPsiBlastManager : public IEntityEventListener // Id=801C18A Size=160
{
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiThermalBlastProperties>;
	
	CArkPsiBlastProperties<ArkPsiThermalBlastProperties> m_properties;
	std::vector<T> m_blasts;
	
	virtual ~CArkPsiBlastManager();
	void SpawnBlast(Vec3 const &arg0);
	void Update(const float arg0);
	void Initialize(ArkPsiThermalBlastProperties const &arg0, ArkPsiPowerTargetingComponent const &arg1);
	int GetBlastCount() const;
	CArkPsiBlastProperties<ArkPsiThermalBlastProperties> const &GetBlastProperties() const;
	void ClearBlasts();
	void Serialize(TSerialize _ser);
	void PostSerialize();
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiElectrostaticBurst.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiFearBlast.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiThermalBlast.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>
#include <_unknown/CArkPsiBlastProperties.h>

class ArkPsiElectrostaticBurstProperties;
class ArkPsiFearBlastProperties;
class ArkPsiFlareBlastProperties;
class ArkPsiKineticBlastProperties;
class ArkPsiPowerTargetingComponent;
class ArkPsiThermalBlastProperties;
struct IEntity;
struct SEntityEvent;

// CArkPsiBlastManager<CArkPsiElectrostaticBurst>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
class CArkPsiBlastManager<CArkPsiElectrostaticBurst> : public IEntityEventListener
{ // Size=160 (0xA0)
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>;

	CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties> m_properties;
	std::vector<CArkPsiElectrostaticBurst> m_blasts;

	virtual ~CArkPsiBlastManager<CArkPsiElectrostaticBurst>();
	void SpawnBlast(const Vec3& _pos) { FSpawnBlast(this, _pos); }
	void ClearBlasts() { FClearBlasts(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	void Update(const float _arg0_);
	void Initialize(const ArkPsiElectrostaticBurstProperties& _arg0_, const ArkPsiPowerTargetingComponent& _arg1_);
	int GetBlastCount() const;
	const CArkPsiBlastProperties<ArkPsiElectrostaticBurstProperties>& GetBlastProperties() const;
	void PostSerialize();
#endif

	static inline auto FBitNotCArkPsiBlastManagerLessCArkPsiElectrostaticBurstGreater = PreyFunction<void(CArkPsiBlastManager<CArkPsiElectrostaticBurst>* const _this)>(0x16AE6A0);
	static inline auto FSpawnBlast = PreyFunction<void(CArkPsiBlastManager<CArkPsiElectrostaticBurst>* const _this, const Vec3& _pos)>(0x16B42C0);
	static inline auto FClearBlasts = PreyFunction<void(CArkPsiBlastManager<CArkPsiElectrostaticBurst>* const _this)>(0x16AFB30);
	static inline auto FSerialize = PreyFunction<void(CArkPsiBlastManager<CArkPsiElectrostaticBurst>* const _this, TSerialize _ser)>(0x16B2D60);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiBlastManager<CArkPsiElectrostaticBurst>* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13B1280);
};

// CArkPsiBlastManager<CArkPsiFearBlast>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
class CArkPsiBlastManager<CArkPsiFearBlast> : public IEntityEventListener
{ // Size=160 (0xA0)
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiFearBlastProperties>;

	CArkPsiBlastProperties<ArkPsiFearBlastProperties> m_properties;
	std::vector<CArkPsiFearBlast> m_blasts;

	virtual ~CArkPsiBlastManager<CArkPsiFearBlast>();
	void SpawnBlast(const Vec3& _pos) { FSpawnBlast(this, _pos); }
	void ClearBlasts() { FClearBlasts(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	void Update(const float _arg0_);
	void Initialize(const ArkPsiFearBlastProperties& _arg0_, const ArkPsiPowerTargetingComponent& _arg1_);
	int GetBlastCount() const;
	const CArkPsiBlastProperties<ArkPsiFearBlastProperties>& GetBlastProperties() const;
	void PostSerialize();
#endif

	static inline auto FBitNotCArkPsiBlastManagerLessCArkPsiFearBlastGreater = PreyFunction<void(CArkPsiBlastManager<CArkPsiFearBlast>* const _this)>(0x16AE6A0);
	static inline auto FSpawnBlast = PreyFunction<void(CArkPsiBlastManager<CArkPsiFearBlast>* const _this, const Vec3& _pos)>(0x16B44E0);
	static inline auto FClearBlasts = PreyFunction<void(CArkPsiBlastManager<CArkPsiFearBlast>* const _this)>(0x16AFB30);
	static inline auto FSerialize = PreyFunction<void(CArkPsiBlastManager<CArkPsiFearBlast>* const _this, TSerialize _ser)>(0x16B30F0);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiBlastManager<CArkPsiFearBlast>* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13B1280);
};

// CArkPsiBlastManager<CArkPsiFlareBlast>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
class CArkPsiBlastManager<CArkPsiFlareBlast> : public IEntityEventListener
{ // Size=160 (0xA0)
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiFlareBlastProperties>;

	CArkPsiBlastProperties<ArkPsiFlareBlastProperties> m_properties;
	std::vector<CArkPsiFlareBlast> m_blasts;

	virtual ~CArkPsiBlastManager<CArkPsiFlareBlast>();
	void SpawnBlast(const Vec3& _pos) { FSpawnBlast(this, _pos); }
	void ClearBlasts() { FClearBlasts(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	void Update(const float _arg0_);
	void Initialize(const ArkPsiFlareBlastProperties& _arg0_, const ArkPsiPowerTargetingComponent& _arg1_);
	int GetBlastCount() const;
	const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>& GetBlastProperties() const;
	void PostSerialize();
#endif

	static inline auto FBitNotCArkPsiBlastManagerLessCArkPsiFlareBlastGreater = PreyFunction<void(CArkPsiBlastManager<CArkPsiFlareBlast>* const _this)>(0x13BA0E0);
	static inline auto FSpawnBlast = PreyFunction<void(CArkPsiBlastManager<CArkPsiFlareBlast>* const _this, const Vec3& _pos)>(0x13BB7C0);
	static inline auto FClearBlasts = PreyFunction<void(CArkPsiBlastManager<CArkPsiFlareBlast>* const _this)>(0x13BA760);
	static inline auto FSerialize = PreyFunction<void(CArkPsiBlastManager<CArkPsiFlareBlast>* const _this, TSerialize _ser)>(0x13BB090);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiBlastManager<CArkPsiFlareBlast>* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13B1280);
};

// CArkPsiBlastManager<CArkPsiKineticBlast>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
class CArkPsiBlastManager<CArkPsiKineticBlast> : public IEntityEventListener
{ // Size=160 (0xA0)
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiKineticBlastProperties>;

	CArkPsiBlastProperties<ArkPsiKineticBlastProperties> m_properties;
	std::vector<CArkPsiKineticBlast> m_blasts;

	virtual ~CArkPsiBlastManager<CArkPsiKineticBlast>();
	void SpawnBlast(const Vec3& _pos) { FSpawnBlast(this, _pos); }
	void ClearBlasts() { FClearBlasts(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	void Update(const float _arg0_);
	void Initialize(const ArkPsiKineticBlastProperties& _arg0_, const ArkPsiPowerTargetingComponent& _arg1_);
	int GetBlastCount() const;
	const CArkPsiBlastProperties<ArkPsiKineticBlastProperties>& GetBlastProperties() const;
	void PostSerialize();
#endif

	static inline auto FBitNotCArkPsiBlastManagerLessCArkPsiKineticBlastGreater = PreyFunction<void(CArkPsiBlastManager<CArkPsiKineticBlast>* const _this)>(0x16AE6A0);
	static inline auto FSpawnBlast = PreyFunction<void(CArkPsiBlastManager<CArkPsiKineticBlast>* const _this, const Vec3& _pos)>(0x13B1520);
	static inline auto FClearBlasts = PreyFunction<void(CArkPsiBlastManager<CArkPsiKineticBlast>* const _this)>(0x16AFB30);
	static inline auto FSerialize = PreyFunction<void(CArkPsiBlastManager<CArkPsiKineticBlast>* const _this, TSerialize _ser)>(0x16B3480);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiBlastManager<CArkPsiKineticBlast>* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x13B1280);
};

// CArkPsiBlastManager<CArkPsiThermalBlast>
// Header:  Prey/GameDll/ark/psicommon/arkpsiblastmanager.h
class CArkPsiBlastManager<CArkPsiThermalBlast> : public IEntityEventListener
{ // Size=160 (0xA0)
public:
	using BlastProperties = CArkPsiBlastProperties<ArkPsiThermalBlastProperties>;

	CArkPsiBlastProperties<ArkPsiThermalBlastProperties> m_properties;
	std::vector<CArkPsiThermalBlast> m_blasts;

	virtual ~CArkPsiBlastManager<CArkPsiThermalBlast>();
	void ClearBlasts() { FClearBlasts(this); }
	void Serialize(TSerialize _ser) { FSerialize(this, _ser); }
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);

#if 0
	void SpawnBlast(const Vec3& _arg0_);
	void Update(const float _arg0_);
	void Initialize(const ArkPsiThermalBlastProperties& _arg0_, const ArkPsiPowerTargetingComponent& _arg1_);
	int GetBlastCount() const;
	const CArkPsiBlastProperties<ArkPsiThermalBlastProperties>& GetBlastProperties() const;
	void PostSerialize();
#endif

	static inline auto FBitNotCArkPsiBlastManagerLessCArkPsiThermalBlastGreater = PreyFunction<void(CArkPsiBlastManager<CArkPsiThermalBlast>* const _this)>(0x1584EE0);
	static inline auto FClearBlasts = PreyFunction<void(CArkPsiBlastManager<CArkPsiThermalBlast>* const _this)>(0x15851F0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiBlastManager<CArkPsiThermalBlast>* const _this, TSerialize _ser)>(0x15858B0);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiBlastManager<CArkPsiThermalBlast>* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x15857C0);
};
#endif // !MOONCRASH
