// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class ArkPsiPowerCyberkinesisProperties : private ArkReflectedObject // Id=801C0F7 Size=112
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C0F8 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C0F9 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C0FA Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkSignalPackageIdProperty : public ArkProperty // Id=801C0FB Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty s_ArkSignalPackageIdProperty;
	uint64_t m_SignalPackageId;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C0FC Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetSignalPackageId(uint64_t arg0);
	const uint64_t &GetSignalPackageId() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1468140);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1466880);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class CyberkinesisPowerProperties : public ArkReflectedLibrary // Id=801C0FD Size=248
{
public:
	using LevelProperties = ArkPsiPowerCyberkinesisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=801C0FE Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CyberkinesisPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CyberkinesisPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static CyberkinesisPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkFactionProperty : public ArkProperty // Id=801C0FF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CyberkinesisPowerProperties::ArkFactionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CyberkinesisPowerProperties::ArkFactionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static CyberkinesisPowerProperties::ArkFactionProperty s_ArkFactionProperty;
	ArkPsiPowerFactionProperties m_Faction;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C100 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(CyberkinesisPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(CyberkinesisPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x14661F0);
		static inline auto FIsArray = PreyFunction<bool(CyberkinesisPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(CyberkinesisPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1466240);
	};

	static CyberkinesisPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerCyberkinesisProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~CyberkinesisPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetFaction(ArkPsiPowerFactionProperties arg0);
	ArkPsiPowerFactionProperties const &GetFaction() const;
	std::vector<ArkPsiPowerCyberkinesisProperties> &GetLevels();
	std::vector<ArkPsiPowerCyberkinesisProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x14667B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1466920);
	static inline auto FInit = PreyFunction<bool(CyberkinesisPowerProperties *const _this)>(0x1466A10);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class ArkPsiPowerHypnosisProperties : private ArkReflectedObject // Id=801C130 Size=112
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C131 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C132 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerHypnosisProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerHypnosisProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerHypnosisProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C133 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkSignalPackageIdProperty : public ArkProperty // Id=801C134 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty s_ArkSignalPackageIdProperty;
	uint64_t m_SignalPackageId;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C135 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetSignalPackageId(uint64_t arg0);
	const uint64_t &GetSignalPackageId() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1468140);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1468280);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class ArkPsiPowerRemoteManipulationLevelProperties : public ArkReflectedObject // Id=801C51C Size=112
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C51D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerRemoteManipulationLevelProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C51E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerRemoteManipulationLevelProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C51F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerRemoteManipulationLevelProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkNpcSignalPackageIdProperty : public ArkProperty // Id=801C520 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerRemoteManipulationLevelProperties::ArkNpcSignalPackageIdProperty s_ArkNpcSignalPackageIdProperty;
	uint64_t m_NpcSignalPackageId;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C521 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkPsiPowerRemoteManipulationLevelProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetNpcSignalPackageId(uint64_t arg0);
	const uint64_t &GetNpcSignalPackageId() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1468140);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A1E20);
};

