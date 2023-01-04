// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkPsiPowerTargetingComponent;
class CCryName;
enum class EArkInteractionType;
enum class EArkPsiPowerError;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;

// ArkPsiPowerRemoteManipulationCostOverride
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
class ArkPsiPowerRemoteManipulationCostOverride : public ArkReflectedObject
{ // Size=16 (0x10)
public:
	// ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkOverrideClassProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkOverrideClassProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkPsiCostProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPsiCostProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	static inline auto s_ArkOverrideClassProperty = PreyGlobal<ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty>(0x2C03DB0);
	string m_OverrideClass;
	static inline auto s_ArkPsiCostProperty = PreyGlobal<ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty>(0x2C03DD0);
	float m_PsiCost;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetOverrideClass(string _arg0_);
	const string& GetOverrideClass() const;
	void SetPsiCost(float _arg0_);
	const float& GetPsiCost() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15A1BD0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A1D80);
};

// ArkPsiPowerRemoteManipulationLevelProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
class ArkPsiPowerRemoteManipulationLevelProperties : public ArkReflectedObject
{ // Size=112 (0x70)
public:
	// ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkNpcSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNpcSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty>(0x2C03E50);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty>(0x2C03E70);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty>(0x2C03E90);
	float m_CooldownDurationSec;
	static inline auto s_ArkNpcSignalPackageIdProperty = PreyGlobal<ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty>(0x2C03EB0);
	uint64_t m_NpcSignalPackageId;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty>(0x2C03ED0);
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
	void SetNpcSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetNpcSignalPackageId() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1468140);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A1E20);
};

// ArkPsiPowerRemoteManipulationUniqueProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
class ArkPsiPowerRemoteManipulationUniqueProperties : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkCostOverridesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkCostOverridesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A0900);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A0970);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty* const _this, ArkReflectedObject* _pObject)>(0x15A0990);
	};

	// ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkUsePowerAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUsePowerAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkWorldUIPostProcessVFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkWorldUIPostProcessVFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkCostOverridesProperty = PreyGlobal<ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty>(0x2C03DF0);
	std::vector<ArkPsiPowerRemoteManipulationCostOverride> m_CostOverrides;
	static inline auto s_ArkUsePowerAudioTriggerProperty = PreyGlobal<ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty>(0x2C03E10);
	string m_UsePowerAudioTrigger;
	static inline auto s_ArkWorldUIPostProcessVFXProperty = PreyGlobal<ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty>(0x2C03E30);
	uint64_t m_WorldUIPostProcessVFX;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	std::vector<ArkPsiPowerRemoteManipulationCostOverride>& GetCostOverrides();
	const std::vector<ArkPsiPowerRemoteManipulationCostOverride>& GetCostOverrides() const;
	void SetUsePowerAudioTrigger(string _arg0_);
	const string& GetUsePowerAudioTrigger() const;
	void SetWorldUIPostProcessVFX(uint64_t _arg0_);
	const uint64_t& GetWorldUIPostProcessVFX() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15A1C00);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A1EC0);
};

// RemoteManipulationPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
class RemoteManipulationPowerProperties : public ArkReflectedLibrary
{ // Size=280 (0x118)
public:
	// RemoteManipulationPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const RemoteManipulationPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const RemoteManipulationPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// RemoteManipulationPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const RemoteManipulationPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A06D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const RemoteManipulationPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// RemoteManipulationPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
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

		static inline auto FSetValue = PreyFunction<void(const RemoteManipulationPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15A07A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const RemoteManipulationPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x15A0870);
		static inline auto FIsArray = PreyFunction<bool(const RemoteManipulationPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const RemoteManipulationPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x15A08C0);
	};

	using LevelProperties = ArkPsiPowerRemoteManipulationLevelProperties;
	using UniqueProperties = ArkPsiPowerRemoteManipulationUniqueProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<RemoteManipulationPowerProperties::ArkCommonProperty>(0x2C03EF0);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<RemoteManipulationPowerProperties::ArkUniqueProperty>(0x2C03F10);
	ArkPsiPowerRemoteManipulationUniqueProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<RemoteManipulationPowerProperties::ArkLevelsProperty>(0x2C03F30);
	std::vector<ArkPsiPowerRemoteManipulationLevelProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerRemoteManipulationUniqueProperties _arg0_);
	const ArkPsiPowerRemoteManipulationUniqueProperties& GetUnique() const;
	std::vector<ArkPsiPowerRemoteManipulationLevelProperties>& GetLevels();
	const std::vector<ArkPsiPowerRemoteManipulationLevelProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x15A1C40);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x15A1F60);
	static inline auto FInit = PreyFunction<bool(RemoteManipulationPowerProperties* const _this)>(0x15A2AA0);
};


// CArkPsiPowerRemoteManipulation
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerRemoteManipulation.h
class CArkPsiPowerRemoteManipulation : public CArkPsiPower<RemoteManipulationPowerProperties>, public IEntitySystemSink
{ // Size=752 (0x2F0)
public:
	ArkPsiPowerIndividualTargetingComponent m_targetingComponent;
	std::unordered_map<unsigned int, ArkInteractionInfo> m_scriptInteractions;

	CArkPsiPowerRemoteManipulation();
	virtual ~CArkPsiPowerRemoteManipulation();
	virtual void Cancel();
	virtual void OnReset();
	virtual void UpdateTargeting(const float _frameTime);
	virtual bool StartTargeting();
	virtual void RefreshTargets();
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual EArkPsiPowers GetEnum() const;
	virtual Vec3 GetTargetPosition() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual bool ShowTextWhileTargeting() const;
	EArkInteractionType GetInteractionTypeForCurrentSelection() const { return FGetInteractionTypeForCurrentSelection(this); }
	static ArkInteractionInfo GetInteractionInfoForEntity(const IEntity* const _pEntity) { return FGetInteractionInfoForEntity(_pEntity); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams& _params);
	virtual void OnSpawn(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual bool OnRemove(IEntity* _pEntity);
	virtual void OnReused(IEntity* _pEntity, SEntitySpawnParams& _params);
	virtual void OnEvent(IEntity* _pEntity, SEntityEvent& _event);
	static EArkInteractionType GetInteractionTypeForEntity(const IEntity* const _pEntity) { return FGetInteractionTypeForEntity(_pEntity); }
	static ArkInteractionInfo GetScriptInteractionInfoForEntity(const IEntity* const _pEntity, bool& _bCouldChange) { return FGetScriptInteractionInfoForEntity(_pEntity, _bCouldChange); }
	void UpdateScriptCacheForEntity(const IEntity* _pEntity) { FUpdateScriptCacheForEntity(this, _pEntity); }
	virtual bool Start_Derived();
	virtual EArkPsiPowerError GetExecutionError() const;
	virtual void SetLevel_Derived(const int _level);
	virtual int GetCost() const;
	void OnSelectionChanged() { FOnSelectionChanged(this); }
	bool FilterTarget(const IEntity& _entity) const { return FFilterTarget(this, _entity); }

#if 0
	static bool FindCachedScriptInteraction(const unsigned _arg0_, ArkInteractionInfo& _arg1_);
	float GetRange() const;
#endif

	static inline auto FCArkPsiPowerRemoteManipulationOv1 = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this)>(0x15A1880);
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this)>(0x15A1BA0);
	static inline auto FOnReset = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this)>(0x1332A30);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this, const float _frameTime)>(0x159E610);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerRemoteManipulation* const _this)>(0x15A2E90);
	static inline auto FRefreshTargets = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this)>(0x15A2D40);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>* (const CArkPsiPowerRemoteManipulation* const _this, std::vector<IEntity*>* _return_value_)>(0x15A2A60);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>* (const CArkPsiPowerRemoteManipulation* const _this, std::vector<IEntity*>* _return_value_)>(0x15A2A80);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const CArkPsiPowerRemoteManipulation* const _this)>(0x133DF50);
	static inline auto FGetTargetPosition = PreyFunction<Vec3* (const CArkPsiPowerRemoteManipulation* const _this, Vec3* _return_value_)>(0x159BFC0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const CArkPsiPowerRemoteManipulation* const _this)>(0x222910);
	static inline auto FShowTextWhileTargeting = PreyFunction<bool(const CArkPsiPowerRemoteManipulation* const _this)>(0x1B933B0);
	static inline auto FGetInteractionTypeForCurrentSelection = PreyFunction<EArkInteractionType(const CArkPsiPowerRemoteManipulation* const _this)>(0x15A24F0);
	static inline auto FGetInteractionInfoForEntity = PreyFunction<ArkInteractionInfo(const IEntity* const _pEntity)>(0x15A2300);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(IEntitySystemSink* const _this, SEntitySpawnParams& _params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0x15A2D30);
	static inline auto FOnRemove = PreyFunction<bool(IEntitySystemSink* const _this, IEntity* _pEntity)>(0x15A2C80);
	static inline auto FOnReused = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntitySpawnParams& _params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(IEntitySystemSink* const _this, IEntity* _pEntity, SEntityEvent& _event)>(0xA13080);
	static inline auto FGetInteractionTypeForEntity = PreyFunction<EArkInteractionType(const IEntity* const _pEntity)>(0x15A2520);
	static inline auto FGetScriptInteractionInfoForEntity = PreyFunction<ArkInteractionInfo(const IEntity* const _pEntity, bool& _bCouldChange)>(0x15A26B0);
	static inline auto FUpdateScriptCacheForEntity = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this, const IEntity* _pEntity)>(0x15A32E0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerRemoteManipulation* const _this)>(0x15A2EA0);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(const CArkPsiPowerRemoteManipulation* const _this)>(0x15A22E0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this, const int _level)>(0x15A2E30);
	static inline auto FGetCost = PreyFunction<int(const CArkPsiPowerRemoteManipulation* const _this)>(0x15A2050);
	static inline auto FOnSelectionChanged = PreyFunction<void(CArkPsiPowerRemoteManipulation* const _this)>(0x15A2CB0);
	static inline auto FFilterTarget = PreyFunction<bool(const CArkPsiPowerRemoteManipulation* const _this, const IEntity& _entity)>(0x15A1CE0);
};
