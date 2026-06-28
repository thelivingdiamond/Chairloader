// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/arkpsipowersummonpet.h>

class ArkClass;
class ArkNpc;
enum class EArkPsiPowers;
class IArkValueBase;
class SummonPetMimicPowerProperties;

// ArkPsiPowerSummonPetMimic
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
class ArkPsiPowerSummonPetMimic : public ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>
{ // Size=712 (0x2C8)
public:
	using BaseType = ArkPsiPowerSummonPet<ArkPsiPowerSummonPetMimic,SummonPetMimicPowerProperties>;
	using Properties = SummonPetMimicPowerProperties;

	ArkSimpleTimer m_searchTimer;
	ArkSimpleTimer m_mimicPlayerTimer;

	ArkPsiPowerSummonPetMimic();
	virtual void SetLevel_Derived(const int _level);
	void ResetSearchCooldown() { FResetSearchCooldown(this); }
	void KillCurrentPet_Derived() { FKillCurrentPet_Derived(this); }
	void Update_Derived(const float _frameTime, ArkNpc& _npc) { FUpdate_Derived(this, _frameTime, _npc); }

#if 0
	static EArkPsiPowers GetEnum_Derived();
#endif

	static inline auto FArkPsiPowerSummonPetMimicOv2 = PreyFunction<void(ArkPsiPowerSummonPetMimic* const _this)>(0x13BE660);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerSummonPetMimic* const _this, const int _level)>(0x13BF1B0);
	static inline auto FResetSearchCooldown = PreyFunction<void(ArkPsiPowerSummonPetMimic* const _this)>(0x13BF160);
	static inline auto FKillCurrentPet_Derived = PreyFunction<void(ArkPsiPowerSummonPetMimic* const _this)>(0x13BF150);
	static inline auto FUpdate_Derived = PreyFunction<void(ArkPsiPowerSummonPetMimic* const _this, const float _frameTime, ArkNpc& _npc)>(0x13BF240);
};

// ArkPsiPowerSummonPetMimicProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
class ArkPsiPowerSummonPetMimicProperties : public ArkReflectedObject
{ // Size=176 (0xB0)
public:
	// ArkPsiPowerSummonPetMimicProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkArchetypeProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkArchetypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkSearchCooldownSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkSearchCooldownSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSearchCooldownSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkSearchCooldownSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkSearchCooldownSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16C2C40);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkIconProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkIconProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIconProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkIconProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14E0C50);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkIconProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE110);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkMinBoundsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkMinBoundsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinBoundsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkMinBoundsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkMinBoundsProperty* const _this, ArkReflectedObject* const _pObject)>(0x16B7F00);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkMaxBoundsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkMaxBoundsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxBoundsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkMaxBoundsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE160);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkMaxBoundsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE1A0);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkSummonFXAttachmentProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkSummonFXAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummonFXAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkSummonFXAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE1B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkSummonFXAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkSummonFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkSummonFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSummonFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkSummonFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE210);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkSummonFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C0760);
	};

	// ArkPsiPowerSummonPetMimicProperties::ArkUnsummonFXProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkUnsummonFXProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUnsummonFXProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerSummonPetMimicProperties::ArkUnsummonFXProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10845C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerSummonPetMimicProperties::ArkUnsummonFXProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkDisplayNameProperty>(0x2D519C0);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkDescriptionProperty>(0x2D519E0);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkCooldownDurationSecProperty>(0x2D51A00);
	float m_CooldownDurationSec;
	static inline auto s_ArkArchetypeProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkArchetypeProperty>(0x2D51A20);
	string m_Archetype;
	static inline auto s_ArkSearchCooldownSecProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkSearchCooldownSecProperty>(0x2D51A40);
	float m_SearchCooldownSec;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkTargetingPropertiesProperty>(0x2D51A60);
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	static inline auto s_ArkIconProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkIconProperty>(0x2D51A80);
	string m_Icon;
	static inline auto s_ArkMinBoundsProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkMinBoundsProperty>(0x2D51AA0);
	Vec3 m_MinBounds;
	static inline auto s_ArkMaxBoundsProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkMaxBoundsProperty>(0x2D51AC0);
	Vec3 m_MaxBounds;
	static inline auto s_ArkSummonFXAttachmentProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkSummonFXAttachmentProperty>(0x2D51AE0);
	string m_SummonFXAttachment;
	static inline auto s_ArkSummonFXProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkSummonFXProperty>(0x2D51B00);
	string m_SummonFX;
	static inline auto s_ArkUnsummonFXProperty = PreyGlobal<ArkPsiPowerSummonPetMimicProperties::ArkUnsummonFXProperty>(0x2D51B20);
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
	void SetSearchCooldownSec(float _arg0_);
	const float& GetSearchCooldownSec() const;
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

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13BEC60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13BEDC0);
};

// SummonPetMimicPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
class SummonPetMimicPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// SummonPetMimicPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SummonPetMimicPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetMimicPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// SummonPetMimicPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const SummonPetMimicPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetMimicPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// SummonPetMimicPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerSummonPetMimic.h
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

		static inline auto FSetValue = PreyFunction<void(const SummonPetMimicPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BE000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const SummonPetMimicPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BE050);
		static inline auto FIsArray = PreyFunction<bool(const SummonPetMimicPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const SummonPetMimicPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x13BE0A0);
	};

	using LevelProperties = ArkPsiPowerSummonPetMimicProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<SummonPetMimicPowerProperties::ArkCommonProperty>(0x2D51B40);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<SummonPetMimicPowerProperties::ArkUniqueProperty>(0x2D51B60);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<SummonPetMimicPowerProperties::ArkLevelsProperty>(0x2D51B80);
	std::vector<ArkPsiPowerSummonPetMimicProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerSummonPetMimicProperties>& GetLevels();
	const std::vector<ArkPsiPowerSummonPetMimicProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13BECF0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13BEE60);
	static inline auto FInit = PreyFunction<bool(SummonPetMimicPowerProperties* const _this)>(0x13BEF70);
};
#endif // MOONCRASH
