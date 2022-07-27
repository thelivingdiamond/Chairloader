// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryEntitySystem/IEntitySystem.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/ArkInteractionInfo.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkPsiPowerTargetingComponent;
class CCryName;
struct IEntity;
struct SEntityEvent;
struct SEntitySpawnParams;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerremotemanipulation.h
class ArkPsiPowerRemoteManipulationCostOverride : public ArkReflectedObject // Id=801C507 Size=16
{
public:
	class ArkOverrideClassProperty : public ArkProperty // Id=801C508 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerRemoteManipulationCostOverride::ArkOverrideClassProperty s_ArkOverrideClassProperty;
	string m_OverrideClass;
	
	class ArkPsiCostProperty : public ArkProperty // Id=801C509 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerRemoteManipulationCostOverride::ArkPsiCostProperty s_ArkPsiCostProperty;
	float m_PsiCost;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetOverrideClass(string arg0);
	string const &GetOverrideClass() const;
	void SetPsiCost(float arg0);
	const float &GetPsiCost() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15A1BD0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A1D80);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerremotemanipulation.h
class ArkPsiPowerRemoteManipulationUniqueProperties : public ArkReflectedObject // Id=801C517 Size=40
{
public:
	class ArkCostOverridesProperty : public ArkProperty // Id=801C518 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A0900);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A0970);
		static inline auto FIsArray = PreyFunction<bool(ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty const *const _this, ArkReflectedObject *_pObject)>(0x15A0990);
	};

	static ArkPsiPowerRemoteManipulationUniqueProperties::ArkCostOverridesProperty s_ArkCostOverridesProperty;
	std::vector<ArkPsiPowerRemoteManipulationCostOverride> m_CostOverrides;
	
	class ArkUsePowerAudioTriggerProperty : public ArkProperty // Id=801C519 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerRemoteManipulationUniqueProperties::ArkUsePowerAudioTriggerProperty s_ArkUsePowerAudioTriggerProperty;
	string m_UsePowerAudioTrigger;
	
	class ArkWorldUIPostProcessVFXProperty : public ArkProperty // Id=801C51A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1086E60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerRemoteManipulationUniqueProperties::ArkWorldUIPostProcessVFXProperty s_ArkWorldUIPostProcessVFXProperty;
	uint64_t m_WorldUIPostProcessVFX;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	std::vector<ArkPsiPowerRemoteManipulationCostOverride> &GetCostOverrides();
	std::vector<ArkPsiPowerRemoteManipulationCostOverride> const &GetCostOverrides() const;
	void SetUsePowerAudioTrigger(string arg0);
	string const &GetUsePowerAudioTrigger() const;
	void SetWorldUIPostProcessVFX(uint64_t arg0);
	const uint64_t &GetWorldUIPostProcessVFX() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15A1C00);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A1EC0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerremotemanipulation.h
class RemoteManipulationPowerProperties : public ArkReflectedLibrary // Id=801C522 Size=280
{
public:
	using LevelProperties = ArkPsiPowerRemoteManipulationLevelProperties;
	using UniqueProperties = ArkPsiPowerRemoteManipulationUniqueProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=801C523 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(RemoteManipulationPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(RemoteManipulationPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static RemoteManipulationPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801C524 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(RemoteManipulationPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A06D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(RemoteManipulationPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static RemoteManipulationPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerRemoteManipulationUniqueProperties m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C525 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(RemoteManipulationPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A07A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(RemoteManipulationPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A0870);
		static inline auto FIsArray = PreyFunction<bool(RemoteManipulationPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(RemoteManipulationPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x15A08C0);
	};

	static RemoteManipulationPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerRemoteManipulationLevelProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(ArkPsiPowerRemoteManipulationUniqueProperties arg0);
	ArkPsiPowerRemoteManipulationUniqueProperties const &GetUnique() const;
	std::vector<ArkPsiPowerRemoteManipulationLevelProperties> &GetLevels();
	std::vector<ArkPsiPowerRemoteManipulationLevelProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x15A1C40);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A1F60);
	static inline auto FInit = PreyFunction<bool(RemoteManipulationPowerProperties *const _this)>(0x15A2AA0);
};

// Header: FromCpp
// Prey/GameDll/ark/player/psipower/arkpsipowerremotemanipulation.h
class CArkPsiPowerRemoteManipulation : public CArkPsiPower<RemoteManipulationPowerProperties>, public IEntitySystemSink // Id=801C539 Size=752
{
public:
	ArkPsiPowerIndividualTargetingComponent m_targetingComponent;
	std::unordered_map<unsigned int,ArkInteractionInfo> m_scriptInteractions;
	
	CArkPsiPowerRemoteManipulation();
	virtual void Cancel();
	virtual void OnReset();
	virtual void UpdateTargeting(const float _frameTime);
	virtual bool StartTargeting();
	virtual void RefreshTargets();
	virtual std::vector<IEntity *> GetSelectedTargets() const;
	virtual std::vector<IEntity *> GetUnselectedTargets() const;
	virtual void ProcessInputForTargeting(CCryName const &_actionId, int _activationMode, float _value);
	virtual EArkPsiPowers GetEnum() const;
	virtual Vec3 GetTargetPosition() const;
	virtual ArkPsiPowerTargetingComponent const *GetTargetingComponent() const;
	virtual bool ShowTextWhileTargeting() const;
	EArkInteractionType GetInteractionTypeForCurrentSelection() const { return FGetInteractionTypeForCurrentSelection(this); }
	static ArkInteractionInfo GetInteractionInfoForEntity(IEntity const *const _pEntity) { return FGetInteractionInfoForEntity(_pEntity); }
	virtual bool OnBeforeSpawn(SEntitySpawnParams &_params);
	virtual void OnSpawn(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual bool OnRemove(IEntity *_pEntity);
	virtual void OnReused(IEntity *_pEntity, SEntitySpawnParams &_params);
	virtual void OnEvent(IEntity *_pEntity, SEntityEvent &_event);
	static EArkInteractionType GetInteractionTypeForEntity(IEntity const *const _pEntity) { return FGetInteractionTypeForEntity(_pEntity); }
	static ArkInteractionInfo GetScriptInteractionInfoForEntity(IEntity const *const _pEntity, bool &_bCouldChange) { return FGetScriptInteractionInfoForEntity(_pEntity,_bCouldChange); }
	void UpdateScriptCacheForEntity(IEntity const *_pEntity) { FUpdateScriptCacheForEntity(this,_pEntity); }
	virtual bool Start_Derived();
	virtual EArkPsiPowerError GetExecutionError() const;
	virtual void SetLevel_Derived(const int _level);
	virtual int GetCost() const;
	void OnSelectionChanged() { FOnSelectionChanged(this); }
	bool FilterTarget(IEntity const &_entity) const { return FFilterTarget(this,_entity); }
	
#if 0
	static bool FindCachedScriptInteraction(const unsigned arg0, ArkInteractionInfo &arg1);
	float GetRange() const;
#endif
	
	static inline auto FCancel = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this)>(0x15A1BA0);
	static inline auto FOnReset = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this)>(0x1332A30);
	static inline auto FUpdateTargeting = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, const float _frameTime)>(0x159E610);
	static inline auto FStartTargeting = PreyFunction<bool(CArkPsiPowerRemoteManipulation *const _this)>(0x15A2E90);
	static inline auto FRefreshTargets = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this)>(0x15A2D40);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity *>(CArkPsiPowerRemoteManipulation const *const _this)>(0x15A2A60);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity *>(CArkPsiPowerRemoteManipulation const *const _this)>(0x15A2A80);
	static inline auto FProcessInputForTargeting = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, CCryName const &_actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(CArkPsiPowerRemoteManipulation const *const _this)>(0x133DF50);
	static inline auto FGetTargetPosition = PreyFunction<Vec3(CArkPsiPowerRemoteManipulation const *const _this)>(0x159BFC0);
	static inline auto FGetTargetingComponent = PreyFunction<ArkPsiPowerTargetingComponent const *(CArkPsiPowerRemoteManipulation const *const _this)>(0x222910);
	static inline auto FShowTextWhileTargeting = PreyFunction<bool(CArkPsiPowerRemoteManipulation const *const _this)>(0x1B933B0);
	static inline auto FGetInteractionTypeForCurrentSelection = PreyFunction<EArkInteractionType(CArkPsiPowerRemoteManipulation const *const _this)>(0x15A24F0);
	static inline auto FGetInteractionInfoForEntity = PreyFunction<ArkInteractionInfo(IEntity const *const _pEntity)>(0x15A2300);
	static inline auto FOnBeforeSpawn = PreyFunction<bool(CArkPsiPowerRemoteManipulation *const _this, SEntitySpawnParams &_params)>(0x1B933B0);
	static inline auto FOnSpawn = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0x15A2D30);
	static inline auto FOnRemove = PreyFunction<bool(CArkPsiPowerRemoteManipulation *const _this, IEntity *_pEntity)>(0x15A2C80);
	static inline auto FOnReused = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, IEntity *_pEntity, SEntitySpawnParams &_params)>(0xA13080);
	static inline auto FOnEvent = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, IEntity *_pEntity, SEntityEvent &_event)>(0xA13080);
	static inline auto FGetInteractionTypeForEntity = PreyFunction<EArkInteractionType(IEntity const *const _pEntity)>(0x15A2520);
	static inline auto FGetScriptInteractionInfoForEntity = PreyFunction<ArkInteractionInfo(IEntity const *const _pEntity, bool &_bCouldChange)>(0x15A26B0);
	static inline auto FUpdateScriptCacheForEntity = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, IEntity const *_pEntity)>(0x15A32E0);
	static inline auto FStart_Derived = PreyFunction<bool(CArkPsiPowerRemoteManipulation *const _this)>(0x15A2EA0);
	static inline auto FGetExecutionError = PreyFunction<EArkPsiPowerError(CArkPsiPowerRemoteManipulation const *const _this)>(0x15A22E0);
	static inline auto FSetLevel_Derived = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this, const int _level)>(0x15A2E30);
	static inline auto FGetCost = PreyFunction<int(CArkPsiPowerRemoteManipulation const *const _this)>(0x15A2050);
	static inline auto FOnSelectionChanged = PreyFunction<void(CArkPsiPowerRemoteManipulation *const _this)>(0x15A2CB0);
	static inline auto FFilterTarget = PreyFunction<bool(CArkPsiPowerRemoteManipulation const *const _this, IEntity const &_entity)>(0x15A1CE0);
};

