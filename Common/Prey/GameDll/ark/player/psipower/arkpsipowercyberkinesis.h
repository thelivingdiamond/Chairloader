// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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

// ArkPsiPowerCyberkinesisProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class ArkPsiPowerCyberkinesisProperties : private ArkReflectedObject
{ // Size=112 (0x70)
public:
	// ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466070);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty>(0x2BEFAC0);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty>(0x2BEFAE0);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty>(0x2BEFB00);
	float m_CooldownDurationSec;
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty>(0x2BEFB20);
	uint64_t m_SignalPackageId;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty>(0x2BEFB40);
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
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1466880);
};

// CyberkinesisPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class CyberkinesisPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// CyberkinesisPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const CyberkinesisPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CyberkinesisPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// CyberkinesisPowerProperties::ArkFactionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkFactionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFactionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const CyberkinesisPowerProperties::ArkFactionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14660B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CyberkinesisPowerProperties::ArkFactionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// CyberkinesisPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
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

		static inline auto FSetValue = PreyFunction<void(const CyberkinesisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1466120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CyberkinesisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x14661F0);
		static inline auto FIsArray = PreyFunction<bool(const CyberkinesisPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const CyberkinesisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1466240);
	};

	using LevelProperties = ArkPsiPowerCyberkinesisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<CyberkinesisPowerProperties::ArkCommonProperty>(0x2BEFB60);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkFactionProperty = PreyGlobal<CyberkinesisPowerProperties::ArkFactionProperty>(0x2BEFB80);
	ArkPsiPowerFactionProperties m_Faction;
	static inline auto s_ArkLevelsProperty = PreyGlobal<CyberkinesisPowerProperties::ArkLevelsProperty>(0x2BEFBA0);
	std::vector<ArkPsiPowerCyberkinesisProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetFaction(ArkPsiPowerFactionProperties _arg0_);
	const ArkPsiPowerFactionProperties& GetFaction() const;
	std::vector<ArkPsiPowerCyberkinesisProperties>& GetLevels();
	const std::vector<ArkPsiPowerCyberkinesisProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14667B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1466920);
	static inline auto FInit = PreyFunction<bool(CyberkinesisPowerProperties* const _this)>(0x1466A10);
};
#else // MOONCRASH
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

// ArkPsiPowerCyberkinesisProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class ArkPsiPowerCyberkinesisProperties : private ArkReflectedObject
{ // Size=112 (0x70)
public:
	// ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkDisplayNameProperty>(0x2D6A688);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkDescriptionProperty>(0x2D6A6A8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkCooldownDurationSecProperty>(0x2D6A6C8);
	float m_CooldownDurationSec;
	static inline auto s_ArkSignalPackageIdProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkSignalPackageIdProperty>(0x2D6A6E8);
	uint64_t m_SignalPackageId;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerCyberkinesisProperties::ArkTargetingPropertiesProperty>(0x2D6A708);
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

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x157E120);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x157E260);
};

// CyberkinesisPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
class CyberkinesisPowerProperties : public ArkReflectedLibrary
{ // Size=256 (0x100)
public:
	// CyberkinesisPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const CyberkinesisPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CyberkinesisPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// CyberkinesisPowerProperties::ArkFactionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
	class ArkFactionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkFactionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const CyberkinesisPowerProperties::ArkFactionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CyberkinesisPowerProperties::ArkFactionProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// CyberkinesisPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowercyberkinesis.h
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

		static inline auto FSetValue = PreyFunction<void(const CyberkinesisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DB00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CyberkinesisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x157DBD0);
		static inline auto FIsArray = PreyFunction<bool(const CyberkinesisPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const CyberkinesisPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x157DC20);
	};

	using LevelProperties = ArkPsiPowerCyberkinesisProperties;
	using UniqueProperties = ArkPsiPowerFactionProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<CyberkinesisPowerProperties::ArkCommonProperty>(0x2D6A728);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkFactionProperty = PreyGlobal<CyberkinesisPowerProperties::ArkFactionProperty>(0x2D6A748);
	ArkPsiPowerFactionProperties m_Faction;
	static inline auto s_ArkLevelsProperty = PreyGlobal<CyberkinesisPowerProperties::ArkLevelsProperty>(0x2D6A768);
	std::vector<ArkPsiPowerCyberkinesisProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetFaction(ArkPsiPowerFactionProperties _arg0_);
	const ArkPsiPowerFactionProperties& GetFaction() const;
	std::vector<ArkPsiPowerCyberkinesisProperties>& GetLevels();
	const std::vector<ArkPsiPowerCyberkinesisProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x157E190);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x157E300);
	static inline auto FInit = PreyFunction<bool(CyberkinesisPowerProperties* const _this)>(0x157E3F0);
};
#endif // !MOONCRASH
