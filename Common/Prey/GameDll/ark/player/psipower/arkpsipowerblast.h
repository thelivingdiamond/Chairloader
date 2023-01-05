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

