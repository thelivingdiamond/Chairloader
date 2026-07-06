// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerGroundTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiPowerCastMatter
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
class ArkPsiPowerCastMatter : public CArkPsiPower<CastMatterPowerProperties>
{ // Size=568 (0x238)
public:
	ArkPsiPowerGroundTargetingComponent m_targetingComponent;
	Vec3 m_targetAreaCenter;
	ArkSimpleTimer m_projectileSpawnTimer;
	int m_numSpawnedProjectiles;

	ArkPsiPowerCastMatter();
	virtual ~ArkPsiPowerCastMatter();
	virtual void Cancel();
	virtual bool StartTargeting();
	virtual void Update(const float _frameTime);
	virtual void UpdateTargeting(const float _frameTime);
	virtual void Serialize(TSerialize _ser);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual EArkPsiPowers GetEnum() const;
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	void SpawnProjectile() { FSpawnProjectile(this); }

#if 0
	void DrawDebug() const;
#endif

	static inline auto FArkPsiPowerCastMatterOv1 = PreyFunction<void(ArkPsiPowerCastMatter* const _this)>(0x13B2EC0);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerCastMatter* const _this)>(0x140D970);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerCastMatter* const _this)>(0x13B44C0);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerCastMatter* const _this, const float _frameTime)>(0x13B4640);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerCastMatter* const _this, const float _frameTime)>(0x13B4760);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerCastMatter* const _this, TSerialize _ser)>(0x13B3BC0);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerCastMatter* const _this, std::vector<IEntity*>* _return_value_)>(0x13B3950);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerCastMatter* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerCastMatter* const _this)>(0x13B3830);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerCastMatter* const _this)>(0x13B45A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerCastMatter* const _this, const int _level)>(0x13B7F60);
	static inline auto FSpawnProjectile = PreyFunction<void(ArkPsiPowerCastMatter* const _this)>(0x13B3D70);
};

// ArkPsiPowerCastMatterProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
class ArkPsiPowerCastMatterProperties : public ArkReflectedObject
{ // Size=136 (0x88)
public:
	// ArkPsiPowerCastMatterProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerCastMatterProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerCastMatterProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerCastMatterProperties::ArkMaxProjectilesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkMaxProjectilesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxProjectilesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkMaxProjectilesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkMaxProjectilesProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkPsiPowerCastMatterProperties::ArkTargetAreaRadiusProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkTargetAreaRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetAreaRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkTargetAreaRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkTargetAreaRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerCastMatterProperties::ArkProjectileMinSpawnDelayProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkProjectileMinSpawnDelayProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkProjectileMinSpawnDelayProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkProjectileMinSpawnDelayProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkProjectileMinSpawnDelayProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	// ArkPsiPowerCastMatterProperties::ArkProjectileMaxSpawnDelayProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkProjectileMaxSpawnDelayProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkProjectileMaxSpawnDelayProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkProjectileMaxSpawnDelayProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkProjectileMaxSpawnDelayProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiPowerCastMatterProperties::ArkProjectileArchetypeProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkProjectileArchetypeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkProjectileArchetypeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkProjectileArchetypeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkProjectileArchetypeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPsiPowerCastMatterProperties::ArkGroundParticlEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkGroundParticlEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkGroundParticlEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkGroundParticlEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A0510);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkGroundParticlEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkPsiPowerCastMatterProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCastMatterProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B26C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCastMatterProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkDisplayNameProperty>(0x2D50BC8);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkDescriptionProperty>(0x2D50BE8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkCooldownDurationSecProperty>(0x2D50C08);
	float m_CooldownDurationSec;
	static inline auto s_ArkMaxProjectilesProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkMaxProjectilesProperty>(0x2D50C28);
	int m_MaxProjectiles;
	static inline auto s_ArkTargetAreaRadiusProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkTargetAreaRadiusProperty>(0x2D50C48);
	float m_TargetAreaRadius;
	static inline auto s_ArkProjectileMinSpawnDelayProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkProjectileMinSpawnDelayProperty>(0x2D50C68);
	float m_ProjectileMinSpawnDelay;
	static inline auto s_ArkProjectileMaxSpawnDelayProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkProjectileMaxSpawnDelayProperty>(0x2D50C88);
	float m_ProjectileMaxSpawnDelay;
	static inline auto s_ArkProjectileArchetypeProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkProjectileArchetypeProperty>(0x2D50CA8);
	string m_ProjectileArchetype;
	static inline auto s_ArkGroundParticlEffectProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkGroundParticlEffectProperty>(0x2D50CC8);
	string m_GroundParticlEffect;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerCastMatterProperties::ArkTargetingPropertiesProperty>(0x2D50CE8);
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
	void SetMaxProjectiles(int _arg0_);
	const int& GetMaxProjectiles() const;
	void SetTargetAreaRadius(float _arg0_);
	const float& GetTargetAreaRadius() const;
	void SetProjectileMinSpawnDelay(float _arg0_);
	const float& GetProjectileMinSpawnDelay() const;
	void SetProjectileMaxSpawnDelay(float _arg0_);
	const float& GetProjectileMaxSpawnDelay() const;
	void SetProjectileArchetype(string _arg0_);
	const string& GetProjectileArchetype() const;
	void SetGroundParticlEffect(string _arg0_);
	const string& GetGroundParticlEffect() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13B3390);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13B34E0);
};

// CastMatterPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
class CastMatterPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// CastMatterPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const CastMatterPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CastMatterPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// CastMatterPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const CastMatterPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CastMatterPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// CastMatterPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCastMatter.h
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

		static inline auto FSetValue = PreyFunction<void(const CastMatterPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B2700);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CastMatterPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B2860);
		static inline auto FIsArray = PreyFunction<bool(const CastMatterPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const CastMatterPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x13B28B0);
	};

	using LevelProperties = ArkPsiPowerCastMatterProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<CastMatterPowerProperties::ArkCommonProperty>(0x2D50D08);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<CastMatterPowerProperties::ArkUniqueProperty>(0x2D50D28);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<CastMatterPowerProperties::ArkLevelsProperty>(0x2D50D48);
	std::vector<ArkPsiPowerCastMatterProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerCastMatterProperties>& GetLevels();
	const std::vector<ArkPsiPowerCastMatterProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13B3410);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13B3580);
	static inline auto FInit = PreyFunction<bool(CastMatterPowerProperties* const _this)>(0x13B39E0);
};
#endif // MOONCRASH
