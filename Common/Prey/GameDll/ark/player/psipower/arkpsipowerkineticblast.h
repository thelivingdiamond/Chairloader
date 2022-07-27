// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowertargetingcomponent.h>
#include <Prey/GameDll/ark/psicommon/arkpsielectrostaticburst.h>
#include <Prey/GameDll/ark/psicommon/arkpsifearblast.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class ArkPsiPowerElectrostaticBurstProperties : public ArkReflectedObject // Id=801C117 Size=248
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C118 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C119 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C11A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkBlastTypePropertiesProperty : public ArkProperty // Id=801C11B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty s_ArkBlastTypePropertiesProperty;
	ArkPsiElectrostaticBurstProperties m_BlastTypeProperties;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C11C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1468700);
	};

	static ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
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
	void SetBlastTypeProperties(ArkPsiElectrostaticBurstProperties arg0);
	ArkPsiElectrostaticBurstProperties const &GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x14676B0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class ArkPsiPowerKineticBlastProperties : public ArkReflectedObject // Id=801C14E Size=248
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C14F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerKineticBlastProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C150 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerKineticBlastProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C151 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerKineticBlastProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkBlastTypePropertiesProperty : public ArkProperty // Id=801C152 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerKineticBlastProperties::ArkBlastTypePropertiesProperty s_ArkBlastTypePropertiesProperty;
	ArkPsiKineticBlastProperties m_BlastTypeProperties;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C153 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1468700);
	};

	static ArkPsiPowerKineticBlastProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
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
	void SetBlastTypeProperties(ArkPsiKineticBlastProperties arg0);
	ArkPsiKineticBlastProperties const &GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1468D70);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class KineticBlastPowerProperties : public ArkReflectedLibrary // Id=801C155 Size=248
{
public:
	using LevelProperties = ArkPsiPowerKineticBlastProperties;
	using UniqueProperties = bool;
	
	class ArkCommonProperty : public ArkProperty // Id=801C156 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(KineticBlastPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(KineticBlastPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static KineticBlastPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=801C157 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(KineticBlastPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(KineticBlastPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static KineticBlastPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	bool m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=801C158 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(KineticBlastPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1468730);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(KineticBlastPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1468830);
		static inline auto FIsArray = PreyFunction<bool(KineticBlastPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(KineticBlastPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1466DB0);
	};

	static KineticBlastPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerKineticBlastProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(bool arg0);
	const bool &GetUnique() const;
	std::vector<ArkPsiPowerKineticBlastProperties> &GetLevels();
	std::vector<ArkPsiPowerKineticBlastProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1468CF0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1468E10);
	static inline auto FInit = PreyFunction<bool(KineticBlastPowerProperties *const _this)>(0x1468F00);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class ArkPsiPowerThermalBlastProperties : public ArkReflectedObject // Id=801C16D Size=248
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C16E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C16F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C170 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkBlastTypePropertiesProperty : public ArkProperty // Id=801C171 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty s_ArkBlastTypePropertiesProperty;
	ArkPsiThermalBlastProperties m_BlastTypeProperties;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C172 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1468700);
	};

	static ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
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
	void SetBlastTypeProperties(ArkPsiThermalBlastProperties arg0);
	ArkPsiThermalBlastProperties const &GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x146D7C0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerkineticblast.h
class ArkPsiPowerFearProperties : public ArkReflectedObject // Id=801C885 Size=248
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801C886 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFearProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFearProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerFearProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801C887 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFearProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFearProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerFearProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801C888 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerFearProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkBlastTypePropertiesProperty : public ArkProperty // Id=801C889 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerFearProperties::ArkBlastTypePropertiesProperty s_ArkBlastTypePropertiesProperty;
	ArkPsiFearBlastProperties m_BlastTypeProperties;
	
	class ArkTargetingPropertiesProperty : public ArkProperty // Id=801C88A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1468700);
	};

	static ArkPsiPowerFearProperties::ArkTargetingPropertiesProperty s_ArkTargetingPropertiesProperty;
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
	void SetBlastTypeProperties(ArkPsiFearBlastProperties arg0);
	ArkPsiFearBlastProperties const &GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties arg0);
	ArkPsiPowerTargetingComponentProperties const &GetTargetingProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1584910);
};

