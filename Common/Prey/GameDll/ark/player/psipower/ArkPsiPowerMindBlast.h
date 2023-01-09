// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkPsiPowerTargetingComponent;
class CCryName;
enum class EArkPsiPowerError;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiPowerMindBlastProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
class ArkPsiPowerMindBlastProperties : public ArkReflectedObject
{ // Size=120 (0x78)
public:
	// ArkPsiPowerMindBlastProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMindBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMindBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerMindBlastProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMindBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMindBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerMindBlastProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMindBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMindBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerMindBlastProperties::ArkSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMindBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMindBlastProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerMindBlastProperties::ArkExecuteOnTargetParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkExecuteOnTargetParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkExecuteOnTargetParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMindBlastProperties::ArkExecuteOnTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMindBlastProperties::ArkExecuteOnTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	// ArkPsiPowerMindBlastProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerMindBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x159F110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerMindBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088F70);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerMindBlastProperties::ArkDisplayNameProperty>(0x2C03B98);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerMindBlastProperties::ArkDescriptionProperty>(0x2C03BB8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerMindBlastProperties::ArkCooldownDurationSecProperty>(0x2C03BD8);
	float m_CooldownDurationSec;
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiPowerMindBlastProperties::ArkSignalPackageIdProperty>(0x2C03BF8);
	uint64_t m_SignalPackageId;
	static inline auto s_ArkExecuteOnTargetParticleEffectProperty = PreyGlobal<ArkPsiPowerMindBlastProperties::ArkExecuteOnTargetParticleEffectProperty>(0x2C03C18);
	string m_ExecuteOnTargetParticleEffect;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerMindBlastProperties::ArkTargetingPropertiesProperty>(0x2C03C38);
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetSignalPackageId() const;
	void SetExecuteOnTargetParticleEffect(string _arg0_);
	const string& GetExecuteOnTargetParticleEffect() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x159FA00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x159FCE0);
};

// MindBlastPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
class MindBlastPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// MindBlastPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const MindBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const MindBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// MindBlastPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const MindBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const MindBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// MindBlastPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
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

		static inline auto FSetValue = PreyFunction<void(const MindBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x159F150);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const MindBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x159F260);
		static inline auto FIsArray = PreyFunction<bool(const MindBlastPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const MindBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x159F2B0);
	};

	using LevelProperties = ArkPsiPowerMindBlastProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<MindBlastPowerProperties::ArkCommonProperty>(0x2C03C58);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<MindBlastPowerProperties::ArkUniqueProperty>(0x2C03C78);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<MindBlastPowerProperties::ArkLevelsProperty>(0x2C03C98);
	std::vector<ArkPsiPowerMindBlastProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerMindBlastProperties>& GetLevels();
	const std::vector<ArkPsiPowerMindBlastProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x159FA70);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x159FD80);
	static inline auto FInit = PreyFunction<bool(MindBlastPowerProperties* const _this)>(0x159FEE0);
};

// CArkPsiPowerMindBlast
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerMindBlast.h
class CArkPsiPowerMindBlast : public CArkPsiPower<MindBlastPowerProperties>
{ // Size=680 (0x2A8)
public:
	ArkPsiPowerIndividualTargetingComponent m_targetingComponent;

	virtual ~CArkPsiPowerMindBlast();
	virtual void ProcessInputForTargeting(const CCryName& _rActionId, int _activationMode, float _value);
	virtual void RefreshTargets();
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual void Cancel();
	virtual bool StartTargeting();
	virtual void OnReset();
	virtual void UpdateTargeting(const float _fFrameTime);
	virtual EArkPsiPowers GetEnum() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void SetLevel_Derived(const int _level);
	virtual bool Start_Derived();
	virtual EArkPsiPowerError GetExecutionError() const;
	bool FilterTarget(const IEntity& _entity) const { return FFilterTarget(this, _entity); }

#if 0
	CArkPsiPowerMindBlast();
	void Cleanup();
#endif

	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerMindBlast* const _this, const CCryName& _rActionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FRefreshTargets = PreyFunction<void(CArkPsiPowerMindBlast* const _this)>(0x15A00D0);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>* (const CArkPsiPowerMindBlast* const _this, std::vector<IEntity*>* _return_value_)>(0x159FEA0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>* (const CArkPsiPowerMindBlast* const _this, std::vector<IEntity*>* _return_value_)>(0x159FEC0);
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerMindBlast* const _this)>(0xB44E10);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerMindBlast* const _this)>(0x15A01A0);
	static inline auto FOnReset = PreyFunction<void(CArkPsiPowerMindBlast* const _this)>(0x15A00C0);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerMindBlast* const _this, const float _fFrameTime)>(0x15A0570);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerMindBlast* const _this)>(0x159FE70);
	static inline auto FGetTargetPosition = PreyFunction<Vec3* (const CArkPsiPowerMindBlast* const _this, Vec3* _return_value_)>(0x13327A0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerMindBlast* const _this)>(0x12BDA90);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerMindBlast* const _this, const int _level)>(0x15A0140);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerMindBlast* const _this)>(0x15A01B0);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(const CArkPsiPowerMindBlast* const _this)>(0x159FE80);
	static inline auto FFilterTarget = PreyFunction<bool(const CArkPsiPowerMindBlast* const _this, const IEntity& _entity)>(0x159FAF0);
};

