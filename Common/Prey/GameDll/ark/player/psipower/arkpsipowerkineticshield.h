// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/Ark/arkaudioutil.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/arkeffectutils.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
namespace ArkSignalSystem
{
class CArkSignalContext;
} // namespace ArkSignalSystem
struct IEntity;
struct SEntityEvent;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticshield.h
class ArkPsiPowerKineticShieldProperties : public ArkReflectedObject // Id=801C76C Size=168
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C76D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerKineticShieldProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C76E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerKineticShieldProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C76F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerKineticShieldProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkChargeCountProperty : public ArkProperty // Id=801C770 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiPowerKineticShieldProperties::ArkChargeCountProperty s_ArkChargeCountProperty;
	int m_ChargeCount;
	
	class ArkDurationSecProperty : public ArkProperty // Id=801C771 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerKineticShieldProperties::ArkDurationSecProperty s_ArkDurationSecProperty;
	float m_DurationSec;
	
	class ArkWarningDurationSecProperty : public ArkProperty // Id=801C772 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkPsiPowerKineticShieldProperties::ArkWarningDurationSecProperty s_ArkWarningDurationSecProperty;
	float m_WarningDurationSec;
	
	class ArkAbsorbDamageParticleEffectProperty : public ArkProperty // Id=801C773 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageParticleEffectProperty s_ArkAbsorbDamageParticleEffectProperty;
	string m_AbsorbDamageParticleEffect;
	
	class ArkReflectDamageParticleEffectProperty : public ArkProperty // Id=801C774 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15917F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088F70);
	};

	static ArkPsiPowerKineticShieldProperties::ArkReflectDamageParticleEffectProperty s_ArkReflectDamageParticleEffectProperty;
	string m_ReflectDamageParticleEffect;
	
	class ArkEnableParticleEffectProperty : public ArkProperty // Id=801C775 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086280);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1056F40);
	};

	static ArkPsiPowerKineticShieldProperties::ArkEnableParticleEffectProperty s_ArkEnableParticleEffectProperty;
	string m_EnableParticleEffect;
	
	class ArkDisableParticleEffectProperty : public ArkProperty // Id=801C776 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1085FB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkPsiPowerKineticShieldProperties::ArkDisableParticleEffectProperty s_ArkDisableParticleEffectProperty;
	string m_DisableParticleEffect;
	
	class ArkTimeoutParticleEffectProperty : public ArkProperty // Id=801C777 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086010);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591850);
	};

	static ArkPsiPowerKineticShieldProperties::ArkTimeoutParticleEffectProperty s_ArkTimeoutParticleEffectProperty;
	string m_TimeoutParticleEffect;
	
	class ArkHitImpactAudioTriggerProperty : public ArkProperty // Id=801C778 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBD70);
	};

	static ArkPsiPowerKineticShieldProperties::ArkHitImpactAudioTriggerProperty s_ArkHitImpactAudioTriggerProperty;
	string m_HitImpactAudioTrigger;
	
	class ArkAbsorbDamageAudioTriggerProperty : public ArkProperty // Id=801C779 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBD80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkPsiPowerKineticShieldProperties::ArkAbsorbDamageAudioTriggerProperty s_ArkAbsorbDamageAudioTriggerProperty;
	string m_AbsorbDamageAudioTrigger;
	
	class ArkReflectDamageAudioTriggerProperty : public ArkProperty // Id=801C77A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10860E0);
	};

	static ArkPsiPowerKineticShieldProperties::ArkReflectDamageAudioTriggerProperty s_ArkReflectDamageAudioTriggerProperty;
	string m_ReflectDamageAudioTrigger;
	
	class ArkEnableAudioTriggerProperty : public ArkProperty // Id=801C77B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12FBE00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1086170);
	};

	static ArkPsiPowerKineticShieldProperties::ArkEnableAudioTriggerProperty s_ArkEnableAudioTriggerProperty;
	string m_EnableAudioTrigger;
	
	class ArkDisableAudioTriggerProperty : public ArkProperty // Id=801C77C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4CC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkPsiPowerKineticShieldProperties::ArkDisableAudioTriggerProperty s_ArkDisableAudioTriggerProperty;
	string m_DisableAudioTrigger;
	
	class ArkFirstTimeoutWarningAudioTriggerProperty : public ArkProperty // Id=801C77D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1088FD0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1082260);
	};

	static ArkPsiPowerKineticShieldProperties::ArkFirstTimeoutWarningAudioTriggerProperty s_ArkFirstTimeoutWarningAudioTriggerProperty;
	string m_FirstTimeoutWarningAudioTrigger;
	
	class ArkSecondTimeoutWarningAudioTriggerProperty : public ArkProperty // Id=801C77E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591860);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D30);
	};

	static ArkPsiPowerKineticShieldProperties::ArkSecondTimeoutWarningAudioTriggerProperty s_ArkSecondTimeoutWarningAudioTriggerProperty;
	string m_SecondTimeoutWarningAudioTrigger;
	
	class ArkReflectedSignalPackageIdProperty : public ArkProperty // Id=801C77F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15918C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10617E0);
	};

	static ArkPsiPowerKineticShieldProperties::ArkReflectedSignalPackageIdProperty s_ArkReflectedSignalPackageIdProperty;
	uint64_t m_ReflectedSignalPackageId;
	
	class ArkReflectedDamageSignalPackageIdProperty : public ArkProperty // Id=801C780 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4DB0);
	};

	static ArkPsiPowerKineticShieldProperties::ArkReflectedDamageSignalPackageIdProperty s_ArkReflectedDamageSignalPackageIdProperty;
	uint64_t m_ReflectedDamageSignalPackageId;
	
	class ArkInstigatorMetaTagsProperty : public ArkProperty // Id=801C781 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15918D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1591900);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1591930);
	};

	static ArkPsiPowerKineticShieldProperties::ArkInstigatorMetaTagsProperty s_ArkInstigatorMetaTagsProperty;
	std::vector<unsigned __int64> m_InstigatorMetaTags;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetChargeCount(int arg0);
	const int &GetChargeCount() const;
	void SetDurationSec(float arg0);
	const float &GetDurationSec() const;
	void SetWarningDurationSec(float arg0);
	const float &GetWarningDurationSec() const;
	void SetAbsorbDamageParticleEffect(string arg0);
	string const &GetAbsorbDamageParticleEffect() const;
	void SetReflectDamageParticleEffect(string arg0);
	string const &GetReflectDamageParticleEffect() const;
	void SetEnableParticleEffect(string arg0);
	string const &GetEnableParticleEffect() const;
	void SetDisableParticleEffect(string arg0);
	string const &GetDisableParticleEffect() const;
	void SetTimeoutParticleEffect(string arg0);
	string const &GetTimeoutParticleEffect() const;
	void SetHitImpactAudioTrigger(string arg0);
	string const &GetHitImpactAudioTrigger() const;
	void SetAbsorbDamageAudioTrigger(string arg0);
	string const &GetAbsorbDamageAudioTrigger() const;
	void SetReflectDamageAudioTrigger(string arg0);
	string const &GetReflectDamageAudioTrigger() const;
	void SetEnableAudioTrigger(string arg0);
	string const &GetEnableAudioTrigger() const;
	void SetDisableAudioTrigger(string arg0);
	string const &GetDisableAudioTrigger() const;
	void SetFirstTimeoutWarningAudioTrigger(string arg0);
	string const &GetFirstTimeoutWarningAudioTrigger() const;
	void SetSecondTimeoutWarningAudioTrigger(string arg0);
	string const &GetSecondTimeoutWarningAudioTrigger() const;
	void SetReflectedSignalPackageId(uint64_t arg0);
	const uint64_t &GetReflectedSignalPackageId() const;
	void SetReflectedDamageSignalPackageId(uint64_t arg0);
	const uint64_t &GetReflectedDamageSignalPackageId() const;
	std::vector<unsigned __int64> &GetInstigatorMetaTags();
	std::vector<unsigned __int64> const &GetInstigatorMetaTags() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15929F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1592D90);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticshield.h
class KineticShieldPowerProperties : public ArkReflectedLibrary // Id=801C782 Size=248
{
public:
	using LevelProperties = ArkPsiPowerKineticShieldProperties;
	using UniqueProperties = bool;
	
	class ArkCommonProperty : public ArkProperty // Id=801C783 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(KineticShieldPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(KineticShieldPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static KineticShieldPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801C784 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(KineticShieldPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(KineticShieldPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static KineticShieldPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	bool m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C785 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(KineticShieldPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591990);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(KineticShieldPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15919E0);
		static inline auto FIsArray = PreyFunction<bool(KineticShieldPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(KineticShieldPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1591A30);
	};

	static KineticShieldPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerKineticShieldProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(bool arg0);
	const bool &GetUnique() const;
	std::vector<ArkPsiPowerKineticShieldProperties> &GetLevels();
	std::vector<ArkPsiPowerKineticShieldProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1592A70);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1592E30);
	static inline auto FInit = PreyFunction<bool(KineticShieldPowerProperties *const _this)>(0x1593200);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticshield.h
class CArkPsiPowerKineticShield : public CArkPsiPower<KineticShieldPowerProperties>, public IEntityEventListener // Id=801C794 Size=712
{
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
	std::vector<unsigned __int64> m_instigatorMetatags;
	
	CArkPsiPowerKineticShield();
	virtual bool Stop();
	virtual bool Start_Derived();
	virtual void Update(const float _fFrameTime);
	virtual bool StartTargeting();
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual void OnEntityEvent(IEntity *_pEntity, SEntityEvent &_event);
	void ClearCurrentSignalPackage() { FClearCurrentSignalPackage(this); }
	bool FilterMimicGrabAttack(IEntity const &_instigator) { return FFilterMimicGrabAttack(this,_instigator); }
	bool FilterDamage(const uint64_t _signalPackageId, ArkSignalSystem::CArkSignalContext const &_context) { return FFilterDamage(this,_signalPackageId,_context); }
	void CleanUp() { FCleanUp(this); }
	void OnDisable() { FOnDisable(this); }
	virtual void SetLevel_Derived(const int _level);
	void OnFilterDamage(IEntity const &_instigator, Vec3 const &_direction) { FOnFilterDamage(this,_instigator,_direction); }
	
#if 0
	bool IsEnabled() const;
	void OnEnable();
	bool IsWarning() const;
#endif
	
	static inline auto FStop = PreyFunction<bool(CArkPsiPowerKineticShield *const _this)>(0x15940D0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerKineticShield *const _this)>(0x1593E90);
	static inline auto FUpdate = PreyFunction<void(CArkPsiPowerKineticShield *const _this, const float _fFrameTime)>(0x15940E0);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerKineticShield *const _this)>(0x1593E70);
	static inline auto FSerialize = PreyFunction<void(CArkPsiPowerKineticShield *const _this, TSerialize _ser)>(0x1593950);
	static inline auto FPostSerialize = PreyFunction<void(CArkPsiPowerKineticShield *const _this)>(0x1593830);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(CArkPsiPowerKineticShield const *const _this)>(0x1A42CE0);
	static inline auto FOnEntityEvent = PreyFunction<void(CArkPsiPowerKineticShield *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0x15934E0);
	static inline auto FClearCurrentSignalPackage = PreyFunction<void(CArkPsiPowerKineticShield *const _this)>(0x15929E0);
	static inline auto FFilterMimicGrabAttack = PreyFunction<bool(CArkPsiPowerKineticShield *const _this, IEntity const &_instigator)>(0x1592C10);
	static inline auto FFilterDamage = PreyFunction<bool(CArkPsiPowerKineticShield *const _this, const uint64_t _signalPackageId, ArkSignalSystem::CArkSignalContext const &_context)>(0x1592B40);
	static inline auto FCleanUp = PreyFunction<void(CArkPsiPowerKineticShield *const _this)>(0x1592860);
	static inline auto FOnDisable = PreyFunction<void(CArkPsiPowerKineticShield *const _this)>(0x15933E0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerKineticShield *const _this, const int _level)>(0x1593AF0);
	static inline auto FOnFilterDamage = PreyFunction<void(CArkPsiPowerKineticShield *const _this, IEntity const &_instigator, Vec3 const &_direction)>(0x1593500);
};

