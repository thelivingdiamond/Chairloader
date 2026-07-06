// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerAlienTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblastmanager.h>

class ArkPsiPowerTargetingComponent;
class CCryName;
enum class EArkPsiPowers;
class ElectrostaticBurstPowerProperties;
class FearPowerProperties;
struct IEntity;
class KineticBlastPowerProperties;
class ThermalBlastPowerProperties;

// CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerblast.h
template <typename TTargetComponent, typename TBlast, typename TProperties, int SOMETHING>
class CArkPsiPowerBlast : public CArkPsiPower<TProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = TProperties;
	using BaseType = CArkPsiPower<TProperties>;

	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	TTargetComponent m_targetingComponent;
	CArkPsiBlastManager<TBlast> m_blastManager;

	virtual ~CArkPsiPowerBlast();
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>();
#endif

#if 0
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x159AF80);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const float _fFrameTime)>(0x158F3A0);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x158DAB0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const float _fFrameTime)>(0x146ECF0);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, std::vector<IEntity*>* _return_value_)>(0x158B050);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, std::vector<IEntity*>* _return_value_)>(0x146DAD0);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, Vec3* _return_value_)>(0x158B0E0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x222910);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, TSerialize _ser)>(0x158CB50);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x158B8B0);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x158AEF0);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x158E0D0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x158DD40);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const int _level)>(0x158D340);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPower3DTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerAlienTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblastmanager.h>

class ArkPsiPowerTargetingComponent;
class CCryName;
enum class EArkPsiPowers;
class ElectrostaticBurstPowerProperties;
class FearPowerProperties;
class FlarePowerProperties;
struct IEntity;
struct IParticleEffect;
class KineticBlastPowerProperties;
class ThermalBlastPowerProperties;

// CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerblast.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0> : public CArkPsiPower<ElectrostaticBurstPowerProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = ElectrostaticBurstPowerProperties;
	using BaseType = CArkPsiPower<ElectrostaticBurstPowerProperties>;

	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiElectrostaticBurst> m_blastManager;

	virtual ~CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>();
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>();
#endif

	static inline auto FCancel = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x13BA750);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const float _fFrameTime)>(0x16B5BA0);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x1585DF0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const float _fFrameTime)>(0x1586840);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, std::vector<IEntity*>* _return_value_)>(0x1585510);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, Vec3* _return_value_)>(0x16B1BE0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x10ED490);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, TSerialize _ser)>(0x16B3810);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x16B2610);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x1CBB0B0);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x16B4D00);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this)>(0x16B4970);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiElectrostaticBurst,ElectrostaticBurstPowerProperties,0>* const _this, const int _level)>(0x16B40F0);
};

// CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerblast.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1> : public CArkPsiPower<FlarePowerProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = FlarePowerProperties;
	using BaseType = CArkPsiPower<FlarePowerProperties>;

	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiFlareBlast> m_blastManager;

	virtual ~CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>();
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>();
#endif

	static inline auto FCancel = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x13BA750);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, const float _fFrameTime)>(0x13BC0D0);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x1585DF0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, const float _fFrameTime)>(0x1586840);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, std::vector<IEntity*>* _return_value_)>(0x13BACF0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, Vec3* _return_value_)>(0x16B1BE0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x10ED490);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, TSerialize _ser)>(0x13BB470);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x13BAFA0);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x1948930);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x13BBB30);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this)>(0x13BB980);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiFlareBlast,FlarePowerProperties,1>* const _this, const int _level)>(0x13BB720);
};

// CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerblast.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4> : public CArkPsiPower<KineticBlastPowerProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = KineticBlastPowerProperties;
	using BaseType = CArkPsiPower<KineticBlastPowerProperties>;

	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiKineticBlast> m_blastManager;

	virtual ~CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>();
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>();
#endif

	static inline auto FCancel = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x13BA750);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, const float _fFrameTime)>(0x16B5D50);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x1585DF0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, const float _fFrameTime)>(0x1586840);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, std::vector<IEntity*>* _return_value_)>(0x1585510);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, Vec3* _return_value_)>(0x16B1BE0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x10ED490);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, TSerialize _ser)>(0x16B38E0);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x16B2610);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x1A2FA50);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x16B4D00);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this)>(0x16B4AA0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiKineticBlast,KineticBlastPowerProperties,4>* const _this, const int _level)>(0x16B40F0);
};

// CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerblast.h
class CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2> : public CArkPsiPower<ThermalBlastPowerProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = ThermalBlastPowerProperties;
	using BaseType = CArkPsiPower<ThermalBlastPowerProperties>;

	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPower3DTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiThermalBlast> m_blastManager;

	virtual ~CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>();
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>();
#endif

	static inline auto FCancel = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x13BA750);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, const float _fFrameTime)>(0x15866E0);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x1585DF0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, const float _fFrameTime)>(0x1586840);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, std::vector<IEntity*>* _return_value_)>(0x1585510);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, Vec3* _return_value_)>(0x16B1BE0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x10ED490);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, TSerialize _ser)>(0x1585C80);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x1585830);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x4FD7F0);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x1586110);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this)>(0x1585E10);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent,CArkPsiThermalBlast,ThermalBlastPowerProperties,2>* const _this, const int _level)>(0x1585D50);
};

// CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerblast.h
class CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9> : public CArkPsiPower<FearPowerProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = FearPowerProperties;
	using BaseType = CArkPsiPower<FearPowerProperties>;

	_smart_ptr<IParticleEffect> m_pTargetingEffect;
	CArkPsiPowerAlienTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiFearBlast> m_blastManager;

	virtual ~CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>();
	virtual void Cancel();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>();
#endif

	static inline auto FCancel = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x13BA750);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, const float _fFrameTime)>(0x16B5F00);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x1585DF0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, const float _fFrameTime)>(0x1586840);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1BB0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, Vec3* _return_value_)>(0x16B1BE0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x10ED490);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0x1333E90);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, TSerialize _ser)>(0x16B39B0);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x16B2610);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x206090);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x16B4D00);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this)>(0x16B4BD0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerBlast<CArkPsiPowerAlienTargetingComponent,CArkPsiFearBlast,FearPowerProperties,9>* const _this, const int _level)>(0x16B40F0);
};
#endif // !MOONCRASH
