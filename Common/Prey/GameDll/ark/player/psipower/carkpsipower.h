// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CryMath/Cry_Color.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/IArkPsiPower.h>

class ArkInputLegend;
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
struct IParticleEffect;
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

// CArkPsiPower<BurrowPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<BurrowPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = BurrowPowerProperties;
	using BaseType = CArkPsiPower<BurrowPowerProperties>;
	using LevelProperties = ArkPsiPowerBurrowProperties;
	using UniqueProperties = ArkPsiPowerBurrowUnqiueProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const BurrowPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<BurrowPowerProperties>();
	virtual ~CArkPsiPower<BurrowPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const BurrowPowerProperties& GetProperties() const;
	const ArkPsiPowerBurrowUnqiueProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerBurrowProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessBurrowPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13AF1B0);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13B0BA0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x16B1840);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x16B1680);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<BurrowPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<BurrowPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<BurrowPowerProperties>* const _this, const int _level)>(0x16B3FB0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<BurrowPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<BurrowPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<BurrowPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<BurrowPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<BurrowPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<CastMatterPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<CastMatterPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = CastMatterPowerProperties;
	using BaseType = CArkPsiPower<CastMatterPowerProperties>;
	using LevelProperties = ArkPsiPowerCastMatterProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const CastMatterPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<CastMatterPowerProperties>();
	virtual ~CArkPsiPower<CastMatterPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const CastMatterPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerCastMatterProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessCastMatterPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13B2CF0);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13B3840);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13B3750);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13B3670);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<CastMatterPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<CastMatterPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<CastMatterPowerProperties>* const _this, const int _level)>(0x13B3CD0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<CastMatterPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<CastMatterPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<CastMatterPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<CombatFocusPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<CombatFocusPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = CombatFocusPowerProperties;
	using BaseType = CArkPsiPower<CombatFocusPowerProperties>;
	using LevelProperties = ArkPsiPowerCombatFocusProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const CombatFocusPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<CombatFocusPowerProperties>();
	virtual ~CArkPsiPower<CombatFocusPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const CombatFocusPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerCombatFocusProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessCombatFocusPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13B4E90);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13B5BD0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13B5AE0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13B5A00);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<CombatFocusPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<CombatFocusPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<CombatFocusPowerProperties>* const _this, const int _level)>(0x13B6110);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<CombatFocusPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<CombatFocusPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<CombatFocusPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<ConsumeCorpsePowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<ConsumeCorpsePowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = ConsumeCorpsePowerProperties;
	using BaseType = CArkPsiPower<ConsumeCorpsePowerProperties>;
	using LevelProperties = ArkPsiPowerConsumeCorpseProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const ConsumeCorpsePowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<ConsumeCorpsePowerProperties>();
	virtual ~CArkPsiPower<ConsumeCorpsePowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const ConsumeCorpsePowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerConsumeCorpseProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessConsumeCorpsePowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13B6A20);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13B3840);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13B3750);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13B3670);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this, const int _level)>(0x13B3CD0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<ConsumeCorpsePowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<CreatePhantomPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<CreatePhantomPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = CreatePhantomPowerProperties;
	using BaseType = CArkPsiPower<CreatePhantomPowerProperties>;
	using LevelProperties = ArkPsiPowerCreatePhantomProperties;
	using UniqueProperties = ArkPsiPowerCreatePhantomCommonProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const CreatePhantomPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<CreatePhantomPowerProperties>();
	virtual ~CArkPsiPower<CreatePhantomPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const CreatePhantomPowerProperties& GetProperties() const;
	const ArkPsiPowerCreatePhantomCommonProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerCreatePhantomProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessCreatePhantomPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x140D290);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x140DF70);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x140DEB0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x140DDF0);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<CreatePhantomPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<CreatePhantomPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<CreatePhantomPowerProperties>* const _this, const int _level)>(0x140E840);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<CreatePhantomPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<CreatePhantomPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<CreatePhantomPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<CyberkinesisPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<CyberkinesisPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = CyberkinesisPowerProperties;
	using BaseType = CArkPsiPower<CyberkinesisPowerProperties>;
	using LevelProperties = ArkPsiPowerCyberkinesisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const CyberkinesisPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<CyberkinesisPowerProperties>();
	virtual ~CArkPsiPower<CyberkinesisPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const CyberkinesisPowerProperties& GetProperties() const;
	const ArkPsiPowerFactionProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerCyberkinesisProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessCyberkinesisPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16AA650);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16AAF20);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16AAE10);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16AAD30);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<CyberkinesisPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<CyberkinesisPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<CyberkinesisPowerProperties>* const _this, const int _level)>(0x16AB040);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<CyberkinesisPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<CyberkinesisPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<CyberkinesisPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<ElectrostaticBurstPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<ElectrostaticBurstPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = ElectrostaticBurstPowerProperties;
	using BaseType = CArkPsiPower<ElectrostaticBurstPowerProperties>;
	using LevelProperties = ArkPsiPowerElectrostaticBurstProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const ElectrostaticBurstPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<ElectrostaticBurstPowerProperties>();
	virtual ~CArkPsiPower<ElectrostaticBurstPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const ElectrostaticBurstPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerElectrostaticBurstProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessElectrostaticBurstPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16AD920);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x13B0BA0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16B1840);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16B1680);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this, const int _level)>(0x16B3FB0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<ElectrostaticBurstPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<FearPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<FearPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = FearPowerProperties;
	using BaseType = CArkPsiPower<FearPowerProperties>;
	using LevelProperties = ArkPsiPowerFearProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const FearPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<FearPowerProperties>();
	virtual ~CArkPsiPower<FearPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const FearPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerFearProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessFearPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<FearPowerProperties>* const _this)>(0x16ADAF0);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<FearPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<FearPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<FearPowerProperties>* const _this)>(0x13B0BA0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<FearPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<FearPowerProperties>* const _this)>(0x16B1840);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<FearPowerProperties>* const _this)>(0x16B1680);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<FearPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<FearPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<FearPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<FearPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<FearPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<FearPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<FearPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<FearPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<FearPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<FearPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<FearPowerProperties>* const _this, const int _level)>(0x16B3FB0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<FearPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<FearPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<FearPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<FearPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<FearPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<FlarePowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<FlarePowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = FlarePowerProperties;
	using BaseType = CArkPsiPower<FlarePowerProperties>;
	using LevelProperties = ArkPsiPowerFlareProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const FlarePowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<FlarePowerProperties>();
	virtual ~CArkPsiPower<FlarePowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const FlarePowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerFlareProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessFlarePowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<FlarePowerProperties>* const _this)>(0x13B9970);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13BACB0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13BABD0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13BAAF0);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<FlarePowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<FlarePowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<FlarePowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<FlarePowerProperties>* const _this, const int _level)>(0x13BB680);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<FlarePowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<FlarePowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<FlarePowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<FlarePowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<FlarePowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<HypnosisPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<HypnosisPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = HypnosisPowerProperties;
	using BaseType = CArkPsiPower<HypnosisPowerProperties>;
	using LevelProperties = ArkPsiPowerHypnosisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const HypnosisPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<HypnosisPowerProperties>();
	virtual ~CArkPsiPower<HypnosisPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const HypnosisPowerProperties& GetProperties() const;
	const ArkPsiPowerFactionProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerHypnosisProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessHypnosisPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16AA820);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16AAF20);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16AAE10);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16AAD30);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<HypnosisPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<HypnosisPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<HypnosisPowerProperties>* const _this, const int _level)>(0x16AB040);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<HypnosisPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<HypnosisPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<HypnosisPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<KineticBlastPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<KineticBlastPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = KineticBlastPowerProperties;
	using BaseType = CArkPsiPower<KineticBlastPowerProperties>;
	using LevelProperties = ArkPsiPowerKineticBlastProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const KineticBlastPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<KineticBlastPowerProperties>();
	virtual ~CArkPsiPower<KineticBlastPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const KineticBlastPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerKineticBlastProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessKineticBlastPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16ADCC0);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x13B0BA0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16B1840);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16B1680);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<KineticBlastPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<KineticBlastPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<KineticBlastPowerProperties>* const _this, const int _level)>(0x16B3FB0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<KineticBlastPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<KineticBlastPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<KineticBlastPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<KineticShieldPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<KineticShieldPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = KineticShieldPowerProperties;
	using BaseType = CArkPsiPower<KineticShieldPowerProperties>;
	using LevelProperties = ArkPsiPowerKineticShieldProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const KineticShieldPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<KineticShieldPowerProperties>();
	virtual ~CArkPsiPower<KineticShieldPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const KineticShieldPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerKineticShieldProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessKineticShieldPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16B8460);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x13C4AB0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16B95B0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16B94D0);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<KineticShieldPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<KineticShieldPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<KineticShieldPowerProperties>* const _this, const int _level)>(0x16B9EC0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<KineticShieldPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<KineticShieldPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<KineticShieldPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<LiftPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<LiftPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = LiftPowerProperties;
	using BaseType = CArkPsiPower<LiftPowerProperties>;
	using LevelProperties = ArkPsiPowerLiftLevelProperties;
	using UniqueProperties = ArkPsiPowerLiftUniqueProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const LiftPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<LiftPowerProperties>();
	virtual ~CArkPsiPower<LiftPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const LiftPowerProperties& GetProperties() const;
	const ArkPsiPowerLiftUniqueProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerLiftLevelProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessLiftPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<LiftPowerProperties>* const _this)>(0x16BB160);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16BBDD0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16BBD10);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16BBC50);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<LiftPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<LiftPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<LiftPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<LiftPowerProperties>* const _this, const int _level)>(0x16BCC80);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<LiftPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<LiftPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<LiftPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<LiftPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<LiftPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<MimicPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<MimicPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = MimicPowerProperties;
	using BaseType = CArkPsiPower<MimicPowerProperties>;
	using LevelProperties = ArkPsiPowerMimicLevelProperties;
	using UniqueProperties = ArkPsiPowerMimicUniqueProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const MimicPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<MimicPowerProperties>();
	virtual ~CArkPsiPower<MimicPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const MimicPowerProperties& GetProperties() const;
	const ArkPsiPowerMimicUniqueProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerMimicLevelProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessMimicPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<MimicPowerProperties>* const _this)>(0x16BE520);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16BF8C0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16BF7E0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16BF700);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<MimicPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<MimicPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<MimicPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<MimicPowerProperties>* const _this, const int _level)>(0x16C0ED0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<MimicPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<MimicPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<MimicPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<MimicPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<MimicPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<MindBlastPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<MindBlastPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = MindBlastPowerProperties;
	using BaseType = CArkPsiPower<MindBlastPowerProperties>;
	using LevelProperties = ArkPsiPowerMindBlastProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const MindBlastPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<MindBlastPowerProperties>();
	virtual ~CArkPsiPower<MindBlastPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const MindBlastPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerMindBlastProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessMindBlastPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16ADE90);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16B1B30);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16B1920);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16B1760);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<MindBlastPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<MindBlastPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<MindBlastPowerProperties>* const _this, const int _level)>(0x16B4050);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<MindBlastPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<MindBlastPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<MindBlastPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<RemoteManipulationPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<RemoteManipulationPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = RemoteManipulationPowerProperties;
	using BaseType = CArkPsiPower<RemoteManipulationPowerProperties>;
	using LevelProperties = ArkPsiPowerRemoteManipulationLevelProperties;
	using UniqueProperties = ArkPsiPowerRemoteManipulationUniqueProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const RemoteManipulationPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<RemoteManipulationPowerProperties>();
	virtual ~CArkPsiPower<RemoteManipulationPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const RemoteManipulationPowerProperties& GetProperties() const;
	const ArkPsiPowerRemoteManipulationUniqueProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerRemoteManipulationLevelProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessRemoteManipulationPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C50A0);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C6180);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C5CF0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C5C10);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<RemoteManipulationPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<RemoteManipulationPowerProperties>* const _this, const int _level)>(0x16C6920);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<RemoteManipulationPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<RemoteManipulationPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<RemoteManipulationPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<ShiftPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<ShiftPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = ShiftPowerProperties;
	using BaseType = CArkPsiPower<ShiftPowerProperties>;
	using LevelProperties = ArkPsiPowerShiftLevelProperties;
	using UniqueProperties = ArkPsiPowerShiftUniqueProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const ShiftPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<ShiftPowerProperties>();
	virtual ~CArkPsiPower<ShiftPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const ShiftPowerProperties& GetProperties() const;
	const ArkPsiPowerShiftUniqueProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerShiftLevelProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessShiftPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<ShiftPowerProperties>* const _this)>(0x13FFC40);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x14012F0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x14011F0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x1401110);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<ShiftPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<ShiftPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<ShiftPowerProperties>* const _this, const int _level)>(0x1401A20);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<ShiftPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<ShiftPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<ShiftPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<ShiftPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<ShiftPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<SmokeFormPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<SmokeFormPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = SmokeFormPowerProperties;
	using BaseType = CArkPsiPower<SmokeFormPowerProperties>;
	using LevelProperties = ArkPsiPowerSmokeFormLevelProperties;
	using UniqueProperties = ArkPsiPowerSmokeFormUniqueProperties;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const SmokeFormPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<SmokeFormPowerProperties>();
	virtual ~CArkPsiPower<SmokeFormPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const SmokeFormPowerProperties& GetProperties() const;
	const ArkPsiPowerSmokeFormUniqueProperties& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerSmokeFormLevelProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessSmokeFormPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C8030);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C8BB0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C8AF0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C8A30);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<SmokeFormPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<SmokeFormPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<SmokeFormPowerProperties>* const _this, const int _level)>(0x16C9280);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<SmokeFormPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<SmokeFormPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<SmokeFormPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<SummonPetMimicPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<SummonPetMimicPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = SummonPetMimicPowerProperties;
	using BaseType = CArkPsiPower<SummonPetMimicPowerProperties>;
	using LevelProperties = ArkPsiPowerSummonPetMimicProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const SummonPetMimicPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<SummonPetMimicPowerProperties>();
	virtual ~CArkPsiPower<SummonPetMimicPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const SummonPetMimicPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerSummonPetMimicProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessSummonPetMimicPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13C2580);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13C4AF0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13C48B0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13C47D0);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<SummonPetMimicPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<SummonPetMimicPowerProperties>* const _this, const int _level)>(0x13C6030);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<SummonPetMimicPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<SummonPetMimicPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<SummonPetMimicPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<SummonPetOperatorPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<SummonPetOperatorPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = SummonPetOperatorPowerProperties;
	using BaseType = CArkPsiPower<SummonPetOperatorPowerProperties>;
	using LevelProperties = ArkPsiPowerSummonPetOperatorProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const SummonPetOperatorPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<SummonPetOperatorPowerProperties>();
	virtual ~CArkPsiPower<SummonPetOperatorPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const SummonPetOperatorPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerSummonPetOperatorProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessSummonPetOperatorPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x13C2750);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x13C4AB0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16B95B0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16B94D0);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this, const int _level)>(0x16B9EC0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<SummonPetOperatorPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<SummonPetTurretPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<SummonPetTurretPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = SummonPetTurretPowerProperties;
	using BaseType = CArkPsiPower<SummonPetTurretPowerProperties>;
	using LevelProperties = ArkPsiPowerSummonPetTurretProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const SummonPetTurretPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<SummonPetTurretPowerProperties>();
	virtual ~CArkPsiPower<SummonPetTurretPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const SummonPetTurretPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerSummonPetTurretProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessSummonPetTurretPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13C2920);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13C4AF0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13C48B0);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13C47D0);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<SummonPetTurretPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<SummonPetTurretPowerProperties>* const _this, const int _level)>(0x13C6030);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<SummonPetTurretPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x16B1280);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<SummonPetTurretPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<SummonPetTurretPowerProperties>* const _this, const int _level)>(0x1333E90);
};

// CArkPsiPower<ThermalBlastPowerProperties>
// Header:  Prey/GameDll/ark/player/psipower/carkpsipower.h
class CArkPsiPower<ThermalBlastPowerProperties> : public IArkPsiPower
{ // Size=64 (0x40)
public:
	using Properties = ThermalBlastPowerProperties;
	using BaseType = CArkPsiPower<ThermalBlastPowerProperties>;
	using LevelProperties = ArkPsiPowerThermalBlastProperties;
	using UniqueProperties = bool;

	ArkSimpleTimer m_cooldownTimer;
	std::vector<enum::EArkPsiPowers> m_blacklist;
	int m_level;
	const ThermalBlastPowerProperties& m_properties;
	IParticleEffect* m_pExecutionPlayerEffect;

	CArkPsiPower<ThermalBlastPowerProperties>();
	virtual ~CArkPsiPower<ThermalBlastPowerProperties>();
	virtual int GetCost() const;
	virtual int GetLevel() const;
	virtual int GetMaxLevel() const;
	virtual const char* GetHelpText() const;
	virtual const char* GetDisplayName() const;
	virtual const char* GetDescription() const;
	virtual float GetZoomDuration() const;
	virtual const char* GetErrorString() const;
	virtual const ArkInputLegend& GetTargetingLegend() const;
	virtual const ArkInputLegend& GetModalLegend() const;
	virtual const std::vector<enum::EArkPsiPowers>& GetBlacklistedPowers() const;
	virtual uint64_t GetPersistentPostEffectId() const;
	virtual ColorF GetTargetHighlightColor() const;
	virtual float UpdateCooldownTimer(const float _deltaTime);
	virtual const ArkSimpleTimer& GetCooldownTimer() const;
	virtual bool InterruptsMimicGrabSequence() const;
	virtual int SetLevel(const int _level);
	virtual void Serialize(TSerialize _ser);
	virtual void EmitNoise() const;
	virtual bool Start();
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);

#if 0
	const ThermalBlastPowerProperties& GetProperties() const;
	const bool& GetUniqueProperties() const;
	boost::optional<ArkPsiPowerThermalBlastProperties const &> GetLevelProperties() const;
#endif

	static inline auto FCArkPsiPowerLessThermalBlastPowerPropertiesGreaterOv1 = PreyFunction<void(CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x1584C60);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x13BAAB0);
	static inline auto FGetLevel = PreyFunction<int(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x13BEF60);
	static inline auto FGetMaxLevel = PreyFunction<int(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x13B0BA0);
	static inline auto FGetHelpText = PreyFunction<const char* (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x16C5DF0);
	static inline auto FGetDisplayName = PreyFunction<const char* (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x16B1840);
	static inline auto FGetDescription = PreyFunction<const char* (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x16B1680);
	static inline auto FGetZoomDuration = PreyFunction<float(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x13C4B40);
	static inline auto FGetErrorString = PreyFunction<const char* (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x16B1A00);
	static inline auto FGetTargetingLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x1401320);
	static inline auto FGetModalLegend = PreyFunction<const ArkInputLegend& (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x16C8BD0);
	static inline auto FGetBlacklistedPowers = PreyFunction<const std::vector<enum::EArkPsiPowers>& (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x10ED260);
	static inline auto FGetPersistentPostEffectId = PreyFunction<uint64_t(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x1585500);
	static inline auto FGetTargetHighlightColor = PreyFunction<ColorF*(const CArkPsiPower<ThermalBlastPowerProperties>* const _this, ColorF* _return_value_)>(0x16C6580);
	static inline auto FUpdateCooldownTimer = PreyFunction<float(CArkPsiPower<ThermalBlastPowerProperties>* const _this, const float _deltaTime)>(0x13C7050);
	static inline auto FGetCooldownTimer = PreyFunction<const ArkSimpleTimer& (const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x133BA60);
	static inline auto FInterruptsMimicGrabSequence = PreyFunction<bool(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x13B0E20);
	static inline auto FSetLevel = PreyFunction<int(CArkPsiPower<ThermalBlastPowerProperties>* const _this, const int _level)>(0x16B3FB0);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPower<ThermalBlastPowerProperties>* const _this, TSerialize _ser)>(0x16C0C10);
	static inline auto FEmitNoise = PreyFunction<void(const CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x13B7A00);
	static inline auto FStart = PreyFunction<bool(CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x16C6A10);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPower<ThermalBlastPowerProperties>* const _this)>(0x1A302A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPower<ThermalBlastPowerProperties>* const _this, const int _level)>(0x1333E90);
};
#endif // !MOONCRASH
