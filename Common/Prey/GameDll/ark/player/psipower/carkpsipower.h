// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/IArkPsiPower.h>
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkInputLegend;
struct IParticleEffect;

// Header: Exact
// Prey/GameDll/ark/player/psipower/carkpsipower.h
#ifdef MOONCRASH
class ArkPsiPowerBurrowProperties;
class ArkPsiPowerBurrowUnqiueProperties;
class ArkPsiPowerCastMatterProperties;
class ArkPsiPowerCombatFocusProperties;
class ArkPsiPowerConsumeCorpseProperties;
class ArkPsiPowerCreatePhantomCommonProperties;
class ArkPsiPowerCreatePhantomProperties;
class ArkPsiPowerCyberkinesisProperties;
class ArkPsiPowerElectrostaticBurstProperties;
class ArkPsiPowerFactionProperties;
class ArkPsiPowerFearProperties;
class ArkPsiPowerFlareProperties;
class ArkPsiPowerHypnosisProperties;
class ArkPsiPowerKineticBlastProperties;
class ArkPsiPowerKineticShieldProperties;
class ArkPsiPowerLiftLevelProperties;
class ArkPsiPowerLiftUniqueProperties;
class ArkPsiPowerMimicLevelProperties;
class ArkPsiPowerMimicUniqueProperties;
class ArkPsiPowerMindBlastProperties;
class ArkPsiPowerRemoteManipulationLevelProperties;
class ArkPsiPowerRemoteManipulationUniqueProperties;
class ArkPsiPowerShiftLevelProperties;
class ArkPsiPowerShiftUniqueProperties;
class ArkPsiPowerSmokeFormLevelProperties;
class ArkPsiPowerSmokeFormUniqueProperties;
class ArkPsiPowerSummonPetMimicProperties;
class ArkPsiPowerSummonPetOperatorProperties;
class ArkPsiPowerSummonPetTurretProperties;
class ArkPsiPowerThermalBlastProperties;
class BurrowPowerProperties;
class CastMatterPowerProperties;
class CombatFocusPowerProperties;
class ConsumeCorpsePowerProperties;
class CreatePhantomPowerProperties;
class CyberkinesisPowerProperties;
class ElectrostaticBurstPowerProperties;
class FearPowerProperties;
class FlarePowerProperties;
class HypnosisPowerProperties;
class KineticBlastPowerProperties;
class KineticShieldPowerProperties;
class LiftPowerProperties;
class MimicPowerProperties;
class MindBlastPowerProperties;
class RemoteManipulationPowerProperties;
class ShiftPowerProperties;
class SmokeFormPowerProperties;
class SummonPetMimicPowerProperties;
class SummonPetOperatorPowerProperties;
class SummonPetTurretPowerProperties;
class ThermalBlastPowerProperties;
#endif
template <typename T>
class CArkPsiPower : public IArkPsiPower // Id=80192FB Size=64
{
public:
	using Properties = T;
	using BaseType = CArkPsiPower<T>;
	using LevelProperties = typename T::LevelProperties;
	using UniqueProperties = typename T::LevelProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum EArkPsiPowers> m_blacklist;
	int m_level;
	Properties const &m_properties;
	IParticleEffect *m_pExecutionPlayerEffect;

    CArkPsiPower();

	// New virtuals introduced by CArkPsiPower, after IArkPsiPower's slots
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char *GetHelpText() const;
	virtual const char *GetDisplayName() const;
	virtual const char *GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char *GetErrorString() const;
	virtual ArkInputLegend const &GetTargetingLegend() const;
	virtual ArkInputLegend const &GetModalLegend() const;
	virtual std::vector<enum EArkPsiPowers> const &GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual Color_tpl<float> GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual ArkSimpleTimer const &GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	Properties const &GetProperties() const;
	UniqueProperties const &GetUniqueProperties() const;
	boost::optional<LevelProperties const &> GetLevelProperties() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
#endif
};
