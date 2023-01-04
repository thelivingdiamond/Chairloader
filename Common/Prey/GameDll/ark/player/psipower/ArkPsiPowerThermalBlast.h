// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerblast.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiThermalBlast.h>

class ArkClass;
class IArkValueBase;
struct IEntity;

// ArkPsiPowerThermalBlastProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
class ArkPsiPowerThermalBlastProperties : public ArkReflectedObject
{ // Size=248 (0xF8)
public:
	// ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkBlastTypePropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastTypePropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1468700);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerThermalBlastProperties::ArkDisplayNameProperty>(0x2BF03B0);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerThermalBlastProperties::ArkDescriptionProperty>(0x2BF03D0);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerThermalBlastProperties::ArkCooldownDurationSecProperty>(0x2BF03F0);
	float m_CooldownDurationSec;
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerThermalBlastProperties::ArkBlastTypePropertiesProperty>(0x2BF0410);
	ArkPsiThermalBlastProperties m_BlastTypeProperties;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerThermalBlastProperties::ArkTargetingPropertiesProperty>(0x2BF0430);
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
	void SetBlastTypeProperties(ArkPsiThermalBlastProperties _arg0_);
	const ArkPsiThermalBlastProperties& GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x146D7C0);
};

// ThermalBlastPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
class ThermalBlastPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// ThermalBlastPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ThermalBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ThermalBlastPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// ThermalBlastPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ThermalBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ThermalBlastPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// ThermalBlastPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
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

		static inline auto FSetValue = PreyFunction<void(const ThermalBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x146C180);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ThermalBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x146C280);
		static inline auto FIsArray = PreyFunction<bool(const ThermalBlastPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ThermalBlastPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1466DB0);
	};

	using LevelProperties = ArkPsiPowerThermalBlastProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<ThermalBlastPowerProperties::ArkCommonProperty>(0x2BF0450);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<ThermalBlastPowerProperties::ArkUniqueProperty>(0x2BF0470);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<ThermalBlastPowerProperties::ArkLevelsProperty>(0x2BF0490);
	std::vector<ArkPsiPowerThermalBlastProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerThermalBlastProperties>& GetLevels();
	const std::vector<ArkPsiPowerThermalBlastProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x146D740);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x146D860);
	static inline auto FInit = PreyFunction<bool(ThermalBlastPowerProperties* const _this)>(0x146DAF0);
};

// CArkPsiPowerThermalBlast
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerThermalBlast.h
class CArkPsiPowerThermalBlast : public CArkPsiPowerBlast<CArkPsiPower3DTargetingComponent, CArkPsiThermalBlast, ThermalBlastPowerProperties, 1>
{ // Size=696 (0x2B8)
public:
	CArkPsiPowerThermalBlast();
	virtual ~CArkPsiPowerThermalBlast();
	virtual std::vector<IEntity*> GetSelectedTargets() const;

	static inline auto FCArkPsiPowerThermalBlastOv1 = PreyFunction<void(CArkPsiPowerThermalBlast* const _this)>(0x146D1C0);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>* (const CArkPsiPowerThermalBlast* const _this, std::vector<IEntity*>* _return_value_)>(0x146DA30);
};
