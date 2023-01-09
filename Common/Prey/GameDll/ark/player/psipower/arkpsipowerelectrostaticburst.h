// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiElectrostaticBurst.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerElectrostaticBurstProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
class ArkPsiPowerElectrostaticBurstProperties : public ArkReflectedObject
{ // Size=248 (0xF8)
public:
	// ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkBlastTypePropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastTypePropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14686C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466C00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1468700);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerElectrostaticBurstProperties::ArkDisplayNameProperty>(0x2BEFCB0);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerElectrostaticBurstProperties::ArkDescriptionProperty>(0x2BEFCD0);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerElectrostaticBurstProperties::ArkCooldownDurationSecProperty>(0x2BEFCF0);
	float m_CooldownDurationSec;
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerElectrostaticBurstProperties::ArkBlastTypePropertiesProperty>(0x2BEFD10);
	ArkPsiElectrostaticBurstProperties m_BlastTypeProperties;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerElectrostaticBurstProperties::ArkTargetingPropertiesProperty>(0x2BEFD30);
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
	void SetBlastTypeProperties(ArkPsiElectrostaticBurstProperties _arg0_);
	const ArkPsiElectrostaticBurstProperties& GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x146D680);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x14676B0);
};

// ElectrostaticBurstPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
class ElectrostaticBurstPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// ElectrostaticBurstPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ElectrostaticBurstPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ElectrostaticBurstPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// ElectrostaticBurstPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ElectrostaticBurstPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1468710);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ElectrostaticBurstPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// ElectrostaticBurstPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerelectrostaticburst.h
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

		static inline auto FSetValue = PreyFunction<void(const ElectrostaticBurstPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466C60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ElectrostaticBurstPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466D60);
		static inline auto FIsArray = PreyFunction<bool(const ElectrostaticBurstPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ElectrostaticBurstPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1466DB0);
	};

	using LevelProperties = ArkPsiPowerElectrostaticBurstProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<ElectrostaticBurstPowerProperties::ArkCommonProperty>(0x2BEFD50);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<ElectrostaticBurstPowerProperties::ArkUniqueProperty>(0x2BEFD70);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<ElectrostaticBurstPowerProperties::ArkLevelsProperty>(0x2BEFD90);
	std::vector<ArkPsiPowerElectrostaticBurstProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerElectrostaticBurstProperties>& GetLevels();
	const std::vector<ArkPsiPowerElectrostaticBurstProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1467630);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1467750);
	static inline auto FInit = PreyFunction<bool(ElectrostaticBurstPowerProperties* const _this)>(0x1467840);
};

