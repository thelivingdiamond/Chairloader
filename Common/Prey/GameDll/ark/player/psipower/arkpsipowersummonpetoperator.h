// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>

class ArkClass;
class IArkValueBase;

// ArkPsiPowerSummonPetOperatorProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
class ArkPsiPowerSummonPetOperatorProperties : public ArkReflectedObject
{ // Size=168 (0xA8)
public:
	// ArkPsiPowerSummonPetOperatorProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkArchetypeProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkIconProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x1403090);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkMinBoundsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkMinBoundsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinBoundsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkMinBoundsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C06C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkMinBoundsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkMaxBoundsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkMaxBoundsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxBoundsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkMaxBoundsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C0700);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkMaxBoundsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0740);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXAttachmentProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkSummonFXAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummonFXAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BF640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6A0);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkSummonFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummonFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE1B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	// ArkPsiPowerSummonPetOperatorProperties::ArkUnsummonFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkUnsummonFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUnsummonFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetOperatorProperties::ArkUnsummonFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetOperatorProperties::ArkUnsummonFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0760);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkDisplayNameProperty>(0x2D51C68);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkDescriptionProperty>(0x2D51C88);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkCooldownDurationSecProperty>(0x2D51CA8);
	float m_CooldownDurationSec;
	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkArchetypeProperty>(0x2D51CC8);
	string m_Archetype;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkTargetingPropertiesProperty>(0x2D51CE8);
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkIconProperty>(0x2D51D08);
	string m_Icon;
	static inline auto s_ArkMinBoundsProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkMinBoundsProperty>(0x2D51D28);
	Vec3 m_MinBounds;
	static inline auto s_ArkMaxBoundsProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkMaxBoundsProperty>(0x2D51D48);
	Vec3 m_MaxBounds;
	static inline auto s_ArkSummonFXAttachmentProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXAttachmentProperty>(0x2D51D68);
	string m_SummonFXAttachment;
	static inline auto s_ArkSummonFXProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkSummonFXProperty>(0x2D51D88);
	string m_SummonFX;
	static inline auto s_ArkUnsummonFXProperty = PreyGlobal<ArkPsiPowerSummonPetOperatorProperties::ArkUnsummonFXProperty>(0x2D51DA8);
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
	void SetSummonFXAttachment(string _arg0_);
	const string& GetSummonFXAttachment() const;
	void SetSummonFX(string _arg0_);
	const string& GetSummonFX() const;
	void SetUnsummonFX(string _arg0_);
	const string& GetUnsummonFX() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13BFFD0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13C0130);
};

// SummonPetOperatorPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
class SummonPetOperatorPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// SummonPetOperatorPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SummonPetOperatorPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetOperatorPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// SummonPetOperatorPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SummonPetOperatorPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetOperatorPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// SummonPetOperatorPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/arkpsipowersummonpetoperator.h
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

		static inline auto FSetValue = PreyFunction<void(const SummonPetOperatorPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BF530);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetOperatorPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF580);
		static inline auto FIsArray = PreyFunction<bool(const SummonPetOperatorPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const SummonPetOperatorPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x13BF5D0);
	};

	using LevelProperties = ArkPsiPowerSummonPetOperatorProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<SummonPetOperatorPowerProperties::ArkCommonProperty>(0x2D51DC8);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<SummonPetOperatorPowerProperties::ArkUniqueProperty>(0x2D51DE8);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<SummonPetOperatorPowerProperties::ArkLevelsProperty>(0x2D51E08);
	std::vector<ArkPsiPowerSummonPetOperatorProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerSummonPetOperatorProperties>& GetLevels();
	const std::vector<ArkPsiPowerSummonPetOperatorProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13C0060);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13C01D0);
	static inline auto FInit = PreyFunction<bool(SummonPetOperatorPowerProperties* const _this)>(0x13C02C0);
};
#endif // MOONCRASH
