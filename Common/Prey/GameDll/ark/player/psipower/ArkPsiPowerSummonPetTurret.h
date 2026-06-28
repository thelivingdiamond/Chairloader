// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowersummonpet.h>

class ArkClass;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;
class SummonPetTurretPowerProperties;

// ArkPsiPowerSummonPetTurret
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
class ArkPsiPowerSummonPetTurret : public ArkPsiPowerSummonPet<ArkPsiPowerSummonPetTurret,SummonPetTurretPowerProperties>
{ // Size=696 (0x2B8)
public:
	using Properties = SummonPetTurretPowerProperties;

	virtual void InitializePet_Derived(IEntity* _pPetEntity);

#if 0
	static EArkPsiPowers GetEnum_Derived();
#endif

	static inline auto FInitializePet_Derived = PreyFunction<void(ArkPsiPowerSummonPetTurret* const _this, IEntity* _pPetEntity)>(0x13C1570);
};

// ArkPsiPowerSummonPetTurretProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
class ArkPsiPowerSummonPetTurretProperties : public ArkReflectedObject
{ // Size=176 (0xB0)
public:
	// ArkPsiPowerSummonPetTurretProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkArchetypeProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkIconProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkMinBoundsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkMinBoundsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinBoundsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkMinBoundsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C06C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkMinBoundsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkMaxBoundsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkMaxBoundsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxBoundsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkMaxBoundsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C0700);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkMaxBoundsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0740);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkRandomNameStringCollectionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkRandomNameStringCollectionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRandomNameStringCollectionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkRandomNameStringCollectionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C0750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkRandomNameStringCollectionProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6A0);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkSummonFXAttachmentProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkSummonFXAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummonFXAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkSummonFXAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE1B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkSummonFXAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkSummonFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkSummonFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummonFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkSummonFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkSummonFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0760);
	};

	// ArkPsiPowerSummonPetTurretProperties::ArkUnsummonFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkUnsummonFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUnsummonFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetTurretProperties::ArkUnsummonFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10845C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetTurretProperties::ArkUnsummonFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkDisplayNameProperty>(0x2D51EF8);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkDescriptionProperty>(0x2D51F18);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkCooldownDurationSecProperty>(0x2D51F38);
	float m_CooldownDurationSec;
	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkArchetypeProperty>(0x2D51F58);
	string m_Archetype;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkTargetingPropertiesProperty>(0x2D51F78);
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkIconProperty>(0x2D51F98);
	string m_Icon;
	static inline auto s_ArkMinBoundsProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkMinBoundsProperty>(0x2D51FB8);
	Vec3 m_MinBounds;
	static inline auto s_ArkMaxBoundsProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkMaxBoundsProperty>(0x2D51FD8);
	Vec3 m_MaxBounds;
	static inline auto s_ArkRandomNameStringCollectionProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkRandomNameStringCollectionProperty>(0x2D51FF8);
	uint64_t m_RandomNameStringCollection;
	static inline auto s_ArkSummonFXAttachmentProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkSummonFXAttachmentProperty>(0x2D52018);
	string m_SummonFXAttachment;
	static inline auto s_ArkSummonFXProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkSummonFXProperty>(0x2D52038);
	string m_SummonFX;
	static inline auto s_ArkUnsummonFXProperty = PreyGlobal<ArkPsiPowerSummonPetTurretProperties::ArkUnsummonFXProperty>(0x2D52058);
	string m_UnsummonFX;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetArchetype(string _arg0_);
	const string& GetArchetype() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
	void SetIcon(string _arg0_);
	const string& GetIcon() const;
	void SetMinBounds(Vec3 _arg0_);
	const Vec3& GetMinBounds() const;
	void SetMaxBounds(Vec3 _arg0_);
	const Vec3& GetMaxBounds() const;
	void SetRandomNameStringCollection(uint64_t _arg0_);
	const uint64_t& GetRandomNameStringCollection() const;
	void SetSummonFXAttachment(string _arg0_);
	const string& GetSummonFXAttachment() const;
	void SetSummonFX(string _arg0_);
	const string& GetSummonFX() const;
	void SetUnsummonFX(string _arg0_);
	const string& GetUnsummonFX() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13C10A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13C1200);
};

// SummonPetTurretPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
class SummonPetTurretPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// SummonPetTurretPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SummonPetTurretPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetTurretPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// SummonPetTurretPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SummonPetTurretPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetTurretPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// SummonPetTurretPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetTurret.h
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

		static inline auto FSetValue = PreyFunction<void(const SummonPetTurretPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C05A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetTurretPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C05F0);
		static inline auto FIsArray = PreyFunction<bool(const SummonPetTurretPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const SummonPetTurretPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x13C0640);
	};

	using LevelProperties = ArkPsiPowerSummonPetTurretProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<SummonPetTurretPowerProperties::ArkCommonProperty>(0x2D52078);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<SummonPetTurretPowerProperties::ArkUniqueProperty>(0x2D52098);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<SummonPetTurretPowerProperties::ArkLevelsProperty>(0x2D520B8);
	std::vector<ArkPsiPowerSummonPetTurretProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerSummonPetTurretProperties>& GetLevels();
	const std::vector<ArkPsiPowerSummonPetTurretProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13C1130);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13C12A0);
	static inline auto FInit = PreyFunction<bool(SummonPetTurretPowerProperties* const _this)>(0x13C1390);
};
#endif // MOONCRASH
