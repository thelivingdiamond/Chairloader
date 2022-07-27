// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/Ark/arktutorial.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkMaterialAnimationKey : public ArkReflectedObject // Id=801426D Size=8
{
public:
	class ArkTimeProperty : public ArkProperty // Id=801426E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationKey::ArkTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationKey::ArkTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMaterialAnimationKey::ArkTimeProperty s_ArkTimeProperty;
	float m_Time;
	
	class ArkValueProperty : public ArkProperty // Id=801426F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationKey::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationKey::ArkValueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkMaterialAnimationKey::ArkValueProperty s_ArkValueProperty;
	float m_Value;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetTime(float arg0);
	const float &GetTime() const;
	void SetValue(float arg0);
	const float &GetValue() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10773C0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiLiftProperties : public ArkReflectedObject // Id=8017558 Size=8
{
public:
	class ArkMaxHeightProperty : public ArkProperty // Id=8017559 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiLiftProperties::ArkMaxHeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiLiftProperties::ArkMaxHeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiLiftProperties::ArkMaxHeightProperty s_ArkMaxHeightProperty;
	float m_MaxHeight;
	
	class ArkDurationSecProperty : public ArkProperty // Id=801755A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiLiftProperties::ArkDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiLiftProperties::ArkDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkPsiLiftProperties::ArkDurationSecProperty s_ArkDurationSecProperty;
	float m_DurationSec;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetMaxHeight(float arg0);
	const float &GetMaxHeight() const;
	void SetDurationSec(float arg0);
	const float &GetDurationSec() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12F65E0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiPowerLiftLevelProperties : public ArkReflectedObject // Id=801755B Size=32
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801755C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerLiftLevelProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801755D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerLiftLevelProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801755E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerLiftLevelProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkLiftPropertiesProperty : public ArkProperty // Id=801755F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12F5C80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiPowerLiftLevelProperties::ArkLiftPropertiesProperty s_ArkLiftPropertiesProperty;
	ArkPsiLiftProperties m_LiftProperties;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetLiftProperties(ArkPsiLiftProperties arg0);
	ArkPsiLiftProperties const &GetLiftProperties() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F6460);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12F6680);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class LiftPowerProperties : public ArkReflectedLibrary // Id=8017561 Size=344
{
public:
	using LevelProperties = ArkPsiPowerLiftLevelProperties;
	using UniqueProperties = ArkPsiPowerLiftUniqueProperties;
	
	class ArkCommonProperty : public ArkProperty // Id=8017562 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(LiftPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(LiftPowerProperties::ArkCommonProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10660A0);
	};

	static LiftPowerProperties::ArkCommonProperty s_ArkCommonProperty;
	ArkPsiPowerCommonProperties m_Common;
	
	class ArkUniqueProperty : public ArkProperty // Id=8017563 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(LiftPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12F5C90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(LiftPowerProperties::ArkUniqueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466C40);
	};

	static LiftPowerProperties::ArkUniqueProperty s_ArkUniqueProperty;
	ArkPsiPowerLiftUniqueProperties m_Unique;
	
	class ArkLevelsProperty : public ArkProperty // Id=8017564 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(LiftPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x12F5EA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(LiftPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F5F50);
		static inline auto FIsArray = PreyFunction<bool(LiftPowerProperties::ArkLevelsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(LiftPowerProperties::ArkLevelsProperty const *const _this, ArkReflectedObject *_pObject)>(0x12F5FA0);
	};

	static LiftPowerProperties::ArkLevelsProperty s_ArkLevelsProperty;
	std::vector<ArkPsiPowerLiftLevelProperties> m_Levels;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~LiftPowerProperties();
	
#if 0
	void SetCommon(ArkPsiPowerCommonProperties arg0);
	ArkPsiPowerCommonProperties const &GetCommon() const;
	void SetUnique(ArkPsiPowerLiftUniqueProperties arg0);
	ArkPsiPowerLiftUniqueProperties const &GetUnique() const;
	std::vector<ArkPsiPowerLiftLevelProperties> &GetLevels();
	std::vector<ArkPsiPowerLiftLevelProperties> const &GetLevels() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F64F0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x12F67C0);
	static inline auto FInit = PreyFunction<bool(LiftPowerProperties *const _this)>(0x12F68B0);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkPsiPowerSmokeFormLevelProperties : public ArkReflectedObject // Id=801951A Size=32
{
public:
	class ArkDisplayNameProperty : public ArkProperty // Id=801951B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkPsiPowerSmokeFormLevelProperties::ArkDisplayNameProperty s_ArkDisplayNameProperty;
	string m_DisplayName;
	
	class ArkDescriptionProperty : public ArkProperty // Id=801951C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkPsiPowerSmokeFormLevelProperties::ArkDescriptionProperty s_ArkDescriptionProperty;
	string m_Description;
	
	class ArkCooldownDurationSecProperty : public ArkProperty // Id=801951D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkPsiPowerSmokeFormLevelProperties::ArkCooldownDurationSecProperty s_ArkCooldownDurationSecProperty;
	float m_CooldownDurationSec;
	
	class ArkPsiCostPerSecProperty : public ArkProperty // Id=801951E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x107A830);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty const *const _this, ArkReflectedObject *const _pObject)>(0x15A4070);
	};

	static ArkPsiPowerSmokeFormLevelProperties::ArkPsiCostPerSecProperty s_ArkPsiCostPerSecProperty;
	float m_PsiCostPerSec;
	
	class ArkMaxHeightProperty : public ArkProperty // Id=801951F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkPsiPowerSmokeFormLevelProperties::ArkMaxHeightProperty s_ArkMaxHeightProperty;
	float m_MaxHeight;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetDisplayName(string arg0);
	string const &GetDisplayName() const;
	void SetDescription(string arg0);
	string const &GetDescription() const;
	void SetCooldownDurationSec(float arg0);
	const float &GetCooldownDurationSec() const;
	void SetPsiCostPerSec(float arg0);
	const float &GetPsiCostPerSec() const;
	void SetMaxHeight(float arg0);
	const float &GetMaxHeight() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F6460);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15A4C10);
};

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
class ArkFreeAimTargetingComponentProperties : public ArkReflectedObject // Id=801C6D2 Size=8
{
public:
	class ArkAimAngleDegProperty : public ArkProperty // Id=801C6D3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkFreeAimTargetingComponentProperties::ArkAimAngleDegProperty s_ArkAimAngleDegProperty;
	float m_AimAngleDeg;
	
	class ArkMaxTargetDistanceProperty : public ArkProperty // Id=801C6D4 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkFreeAimTargetingComponentProperties::ArkMaxTargetDistanceProperty s_ArkMaxTargetDistanceProperty;
	float m_MaxTargetDistance;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetAimAngleDeg(float arg0);
	const float &GetAimAngleDeg() const;
	void SetMaxTargetDistance(float arg0);
	const float &GetMaxTargetDistance() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x153CB80);
};

