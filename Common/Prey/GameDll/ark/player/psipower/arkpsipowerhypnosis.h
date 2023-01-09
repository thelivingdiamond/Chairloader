// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowerfaction.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerHypnosisProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
class ArkPsiPowerHypnosisProperties : private ArkReflectedObject
{ // Size=112 (0x70)
public:
	// ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerHypnosisProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerHypnosisProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerHypnosisProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerHypnosisProperties::ArkDisplayNameProperty>(0x2BEFE78);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerHypnosisProperties::ArkDescriptionProperty>(0x2BEFE98);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerHypnosisProperties::ArkCooldownDurationSecProperty>(0x2BEFEB8);
	float m_CooldownDurationSec;
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiPowerHypnosisProperties::ArkSignalPackageIdProperty>(0x2BEFED8);
	uint64_t m_SignalPackageId;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerHypnosisProperties::ArkTargetingPropertiesProperty>(0x2BEFEF8);
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
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1468140);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1468280);
};

// HypnosisPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
class HypnosisPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// HypnosisPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const HypnosisPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const HypnosisPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// HypnosisPowerProperties::ArkFactionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
	class ArkFactionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFactionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const HypnosisPowerProperties::ArkFactionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const HypnosisPowerProperties::ArkFactionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// HypnosisPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowerhypnosis.h
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

		static inline auto FSetValue = PreyFunction<void(const HypnosisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B70);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const HypnosisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1467C40);
		static inline auto FIsArray = PreyFunction<bool(const HypnosisPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const HypnosisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1466240);
	};

	using LevelProperties = ArkPsiPowerHypnosisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<HypnosisPowerProperties::ArkCommonProperty>(0x2BEFF18);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkFactionProperty = PreyGlobal<HypnosisPowerProperties::ArkFactionProperty>(0x2BEFF38);
	ArkPsiPowerFactionProperties m_Faction;
	static inline auto s_ArkLevelsProperty = PreyGlobal<HypnosisPowerProperties::ArkLevelsProperty>(0x2BEFF58);
	std::vector<ArkPsiPowerHypnosisProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetFaction(ArkPsiPowerFactionProperties _arg0_);
	const ArkPsiPowerFactionProperties& GetFaction() const;
	std::vector<ArkPsiPowerHypnosisProperties>& GetLevels();
	const std::vector<ArkPsiPowerHypnosisProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14681B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1468320);
	static inline auto FInit = PreyFunction<bool(HypnosisPowerProperties* const _this)>(0x1468410);
};

