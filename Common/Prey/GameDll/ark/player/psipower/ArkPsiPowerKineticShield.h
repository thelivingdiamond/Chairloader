// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkAudioUtil.h>
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
namespace ArkSignalSystem
{
class CArkSignalContext;
} // namespace ArkSignalSystem
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
struct SEntityEvent;

// ArkPsiPowerKineticShieldProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
class ArkPsiPowerKineticShieldProperties : public ArkReflectedObject
{ // Size=168 (0xA8)
public:
	// ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkChargeCountProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkChargeCountProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A4070);
	};

	// ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkWarningDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkWarningDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D570);
	};

	// ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkAbsorbDamageParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbsorbDamageParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkReflectDamageParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReflectDamageParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	// ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkEnableParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnableParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1056F40);
	};

	// ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkDisableParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisableParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
	};

	// ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkTimeoutParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTimeoutParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591850);
	};

	// ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkHitImpactAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkHitImpactAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBD70);
	};

	// ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkAbsorbDamageAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAbsorbDamageAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
	};

	// ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkReflectDamageAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReflectDamageAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10860E0);
	};

	// ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkEnableAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkEnableAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1086170);
	};

	// ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkDisableAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisableAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4D20);
	};

	// ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkFirstTimeoutWarningAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFirstTimeoutWarningAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1088FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082260);
	};

	// ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkSecondTimeoutWarningAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSecondTimeoutWarningAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591860);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4D30);
	};

	// ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkReflectedSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReflectedSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15918C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10617E0);
	};

	// ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkReflectedDamageSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkReflectedDamageSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x13D4DB0);
	};

	// ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkInstigatorMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkInstigatorMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15918D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1591900);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x1591930);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty>(0x2C03720);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty>(0x2C03740);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty>(0x2C03760);
	float m_CooldownDurationSec;
	static inline auto s_ArkChargeCountProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty>(0x2C03780);
	int m_ChargeCount;
	static inline auto s_ArkDurationSecProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty>(0x2C037A0);
	float m_DurationSec;
	static inline auto s_ArkWarningDurationSecProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty>(0x2C037C0);
	float m_WarningDurationSec;
	static inline auto s_ArkAbsorbDamageParticleEffectProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty>(0x2C037E0);
	string m_AbsorbDamageParticleEffect;
	static inline auto s_ArkReflectDamageParticleEffectProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty>(0x2C03800);
	string m_ReflectDamageParticleEffect;
	static inline auto s_ArkEnableParticleEffectProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty>(0x2C03820);
	string m_EnableParticleEffect;
	static inline auto s_ArkDisableParticleEffectProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty>(0x2C03840);
	string m_DisableParticleEffect;
	static inline auto s_ArkTimeoutParticleEffectProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty>(0x2C03860);
	string m_TimeoutParticleEffect;
	static inline auto s_ArkHitImpactAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty>(0x2C03880);
	string m_HitImpactAudioTrigger;
	static inline auto s_ArkAbsorbDamageAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty>(0x2C038A0);
	string m_AbsorbDamageAudioTrigger;
	static inline auto s_ArkReflectDamageAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty>(0x2C038C0);
	string m_ReflectDamageAudioTrigger;
	static inline auto s_ArkEnableAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty>(0x2C038E0);
	string m_EnableAudioTrigger;
	static inline auto s_ArkDisableAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty>(0x2C03900);
	string m_DisableAudioTrigger;
	static inline auto s_ArkFirstTimeoutWarningAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty>(0x2C03920);
	string m_FirstTimeoutWarningAudioTrigger;
	static inline auto s_ArkSecondTimeoutWarningAudioTriggerProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty>(0x2C03940);
	string m_SecondTimeoutWarningAudioTrigger;
	static inline auto s_ArkReflectedSignalPackageIdProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty>(0x2C03960);
	uint64_t m_ReflectedSignalPackageId;
	static inline auto s_ArkReflectedDamageSignalPackageIdProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty>(0x2C03980);
	uint64_t m_ReflectedDamageSignalPackageId;
	static inline auto s_ArkInstigatorMetaTagsProperty = PreyGlobal<ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty>(0x2C039A0);
	std::vector<uint64_t> m_InstigatorMetaTags;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetChargeCount(int _arg0_);
	const int& GetChargeCount() const;
	void SetDurationSec(float _arg0_);
	const float& GetDurationSec() const;
	void SetWarningDurationSec(float _arg0_);
	const float& GetWarningDurationSec() const;
	void SetAbsorbDamageParticleEffect(string _arg0_);
	const string& GetAbsorbDamageParticleEffect() const;
	void SetReflectDamageParticleEffect(string _arg0_);
	const string& GetReflectDamageParticleEffect() const;
	void SetEnableParticleEffect(string _arg0_);
	const string& GetEnableParticleEffect() const;
	void SetDisableParticleEffect(string _arg0_);
	const string& GetDisableParticleEffect() const;
	void SetTimeoutParticleEffect(string _arg0_);
	const string& GetTimeoutParticleEffect() const;
	void SetHitImpactAudioTrigger(string _arg0_);
	const string& GetHitImpactAudioTrigger() const;
	void SetAbsorbDamageAudioTrigger(string _arg0_);
	const string& GetAbsorbDamageAudioTrigger() const;
	void SetReflectDamageAudioTrigger(string _arg0_);
	const string& GetReflectDamageAudioTrigger() const;
	void SetEnableAudioTrigger(string _arg0_);
	const string& GetEnableAudioTrigger() const;
	void SetDisableAudioTrigger(string _arg0_);
	const string& GetDisableAudioTrigger() const;
	void SetFirstTimeoutWarningAudioTrigger(string _arg0_);
	const string& GetFirstTimeoutWarningAudioTrigger() const;
	void SetSecondTimeoutWarningAudioTrigger(string _arg0_);
	const string& GetSecondTimeoutWarningAudioTrigger() const;
	void SetReflectedSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetReflectedSignalPackageId() const;
	void SetReflectedDamageSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetReflectedDamageSignalPackageId() const;
	std::vector<uint64_t>& GetInstigatorMetaTags();
	const std::vector<uint64_t>& GetInstigatorMetaTags() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15929F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1592D90);
};

// KineticShieldPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
class KineticShieldPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// KineticShieldPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticShieldPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticShieldPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// KineticShieldPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticShieldPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticShieldPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// KineticShieldPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
	class ArkLevelsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkLevelsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const KineticShieldPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591990);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const KineticShieldPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x15919E0);
		static inline auto FIsArray = PreyFunction<bool(const KineticShieldPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const KineticShieldPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1591A30);
	};

	using LevelProperties = ArkPsiPowerKineticShieldProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<KineticShieldPowerProperties::ArkCommonProperty>(0x2C039C0);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<KineticShieldPowerProperties::ArkUniqueProperty>(0x2C039E0);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<KineticShieldPowerProperties::ArkLevelsProperty>(0x2C03A00);
	std::vector<ArkPsiPowerKineticShieldProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerKineticShieldProperties>& GetLevels();
	const std::vector<ArkPsiPowerKineticShieldProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1592A70);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1592E30);
	static inline auto FInit = PreyFunction<bool(KineticShieldPowerProperties* const _this)>(0x1593200);
};

// CArkPsiPowerKineticShield
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerKineticShield.h
class CArkPsiPowerKineticShield : public CArkPsiPower<KineticShieldPowerProperties>, public IEntityEventListener
{ // Size=712 (0x2C8)
public:
	ArkLooseEffect m_enabledParticleEmitter;
	ArkLooseEffect m_disableParticleEmitter;
	ArkLooseEffect m_warningParticleEmitter;
	ArkLooseEffect m_absorbDamageParticleEmitter;
	ArkLooseEffect m_reflectDamageParticleEmitter;
	int m_numCharges;
	float m_elapsedSec;
	float m_durationSec;
	float m_warningDurationSec;
	uint64_t m_currentSignalPackageId;
	ArkAudioTrigger m_hitAudioTrigger;
	ArkAudioTrigger m_absorbDamageAudioTrigger;
	ArkAudioTrigger m_reflectDamageAudioTrigger;
	ArkAudioTrigger m_enableAudioTrigger;
	ArkAudioTrigger m_disableAudioTrigger;
	ArkAudioTrigger m_firstWarningAudioTrigger;
	ArkAudioTrigger m_secondWarningAudioTrigger;
	std::vector<uint64_t> m_instigatorMetatags;

	CArkPsiPowerKineticShield();
	virtual ~CArkPsiPowerKineticShield();
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual void OnEntityEvent(IEntity* _pEntity, SEntityEvent& _event);
	void ClearCurrentSignalPackage() { FClearCurrentSignalPackage(this); }
	bool FilterMimicGrabAttack(const IEntity& _instigator) { return FFilterMimicGrabAttack(this, _instigator); }
	bool FilterDamage(const uint64_t _signalPackageId, const ArkSignalSystem::CArkSignalContext& _context) { return FFilterDamage(this, _signalPackageId, _context); }
	void CleanUp() { FCleanUp(this); }
	void OnDisable() { FOnDisable(this); }
	virtual void SetLevel_Derived(const int _level);
	void OnFilterDamage(const IEntity& _instigator, const Vec3& _direction) { FOnFilterDamage(this, _instigator, _direction); }

#if 0
	bool IsEnabled() const;
	void OnEnable();
	bool IsWarning() const;
#endif

	static inline auto FCArkPsiPowerKineticShieldOv1 = PreyFunction<void(CArkPsiPowerKineticShield* const _this)>(0x15923C0);
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerKineticShield* const _this)>(0x15940D0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerKineticShield* const _this)>(0x1593E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerKineticShield* const _this, const float _fFrameTime)>(0x15940E0);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerKineticShield* const _this)>(0x1593E70);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerKineticShield* const _this, TSerialize _ser)>(0x1593950);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerKineticShield* const _this)>(0x1593830);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerKineticShield* const _this)>(0x1A42CE0);
	static inline auto FOnEntityEvent = PreyFunction<void(IEntityEventListener* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0x15934E0);
	static inline auto FClearCurrentSignalPackage = PreyFunction<void(CArkPsiPowerKineticShield* const _this)>(0x15929E0);
	static inline auto FFilterMimicGrabAttack = PreyFunction<bool(CArkPsiPowerKineticShield* const _this, const IEntity& _instigator)>(0x1592C10);
	static inline auto FFilterDamage = PreyFunction<bool(CArkPsiPowerKineticShield* const _this, const uint64_t _signalPackageId, const ArkSignalSystem::CArkSignalContext& _context)>(0x1592B40);
	static inline auto FCleanUp = PreyFunction<void(CArkPsiPowerKineticShield* const _this)>(0x1592860);
	static inline auto FOnDisable = PreyFunction<void(CArkPsiPowerKineticShield* const _this)>(0x15933E0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerKineticShield* const _this, const int _level)>(0x1593AF0);
	static inline auto FOnFilterDamage = PreyFunction<void(CArkPsiPowerKineticShield* const _this, const IEntity& _instigator, const Vec3& _direction)>(0x1593500);
};

