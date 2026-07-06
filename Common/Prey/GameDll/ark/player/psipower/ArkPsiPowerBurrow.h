// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerGroundTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>
#include <Prey/GameDll/ark/psicommon/ArkPsiKineticBlast.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblastmanager.h>
#include <_unknown/ArkPsiPowerBurrowUnqiueProperties.h>

class ArkClass;
enum class EArkPsiPowers;
class IArkValueBase;

// ArkPsiPowerBurrow
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
class ArkPsiPowerBurrow : public CArkPsiPower<BurrowPowerProperties>
{ // Size=736 (0x2E0)
public:
	ArkPsiPowerGroundTargetingComponent m_targetingComponent;
	CArkPsiBlastManager<CArkPsiKineticBlast> m_blastManager;
	Vec3 m_startPosition;
	Vec3 m_targetPosition;
	bool m_bMorphingOut;

	ArkPsiPowerBurrow();
	virtual ~ArkPsiPowerBurrow();
	virtual bool Stop();
	virtual void Cancel();
	virtual void Serialize(TSerialize _ser);
	virtual void PostSerialize();
	virtual bool StartTargeting();
	virtual void Update(const float _frameTime);
	virtual bool CanEnterFocusMode(const EArkPsiPowers& _equippedPower) const;
	virtual EArkPsiPowers GetEnum() const;
	virtual const char* GetTargetingErrorString() const;
	virtual const char* GetErrorString() const;
	void FinishMorphIn() { FFinishMorphIn(this); }
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	virtual void UpdateTargeting(const float _frameTime);
	void MorphOut() { FMorphOut(this); }
	Vec3 GetBurrowStartPosition() const { alignas(Vec3) std::byte _return_buf_[sizeof(Vec3)]; return *FGetBurrowStartPosition(this, reinterpret_cast<Vec3*>(_return_buf_)); }

#if 0
	bool IsMorphingOut() const;
	void Reset();
	bool QueueMorphIn();
	bool IsActive() const;
#endif

	static inline auto FArkPsiPowerBurrowOv1 = PreyFunction<void(ArkPsiPowerBurrow* const _this)>(0x13AF640);
	static inline auto FStop = PreyFunction<bool(ArkPsiPowerBurrow* const _this)>(0x13B18F0);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerBurrow* const _this)>(0x140D970);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerBurrow* const _this, TSerialize _ser)>(0x13B1310);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiPowerBurrow* const _this)>(0x13B12A0);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerBurrow* const _this)>(0x13B1740);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerBurrow* const _this, const float _frameTime)>(0x13B21A0);
	static inline auto FCanEnterFocusMode = PreyFunction<bool(const ArkPsiPowerBurrow* const _this, const EArkPsiPowers& _equippedPower)>(0x13B06A0);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerBurrow* const _this)>(0x1F1960);
	static inline auto FGetTargetingErrorString = PreyFunction<const char* (const ArkPsiPowerBurrow* const _this)>(0x13B0BE0);
	static inline auto FGetErrorString = PreyFunction<const char* (const ArkPsiPowerBurrow* const _this)>(0x13B0AB0);
	static inline auto FFinishMorphIn = PreyFunction<void(ArkPsiPowerBurrow* const _this)>(0x13B07B0);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerBurrow* const _this)>(0x13B17A0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerBurrow* const _this, const int _level)>(0x13B1400);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerBurrow* const _this, const float _frameTime)>(0x13B4760);
	static inline auto FMorphOut = PreyFunction<void(ArkPsiPowerBurrow* const _this)>(0x13B0E30);
	static inline auto FGetBurrowStartPosition = PreyFunction<Vec3*(const ArkPsiPowerBurrow* const _this, Vec3* _return_value_)>(0x13B07F0);
};

// ArkPsiPowerBurrowProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
class ArkPsiPowerBurrowProperties : public ArkReflectedObject
{ // Size=248 (0xF8)
public:
	// ArkPsiPowerBurrowProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBurrowProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerBurrowProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerBurrowProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBurrowProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerBurrowProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerBurrowProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBurrowProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerBurrowProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerBurrowProperties::ArkBlastTypePropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkBlastTypePropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastTypePropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBurrowProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157E5D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerBurrowProperties::ArkBlastTypePropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerBurrowProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerBurrowProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157E610);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerBurrowProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerBurrowProperties::ArkDisplayNameProperty>(0x2D50998);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerBurrowProperties::ArkDescriptionProperty>(0x2D509B8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerBurrowProperties::ArkCooldownDurationSecProperty>(0x2D509D8);
	float m_CooldownDurationSec;
	static inline auto s_ArkBlastTypePropertiesProperty = PreyGlobal<ArkPsiPowerBurrowProperties::ArkBlastTypePropertiesProperty>(0x2D509F8);
	ArkPsiKineticBlastProperties m_BlastTypeProperties;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerBurrowProperties::ArkTargetingPropertiesProperty>(0x2D50A18);
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
	void SetBlastTypeProperties(ArkPsiKineticBlastProperties _arg0_);
	const ArkPsiKineticBlastProperties& GetBlastTypeProperties() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16AB9E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13B0910);
};

// BurrowPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
class BurrowPowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// BurrowPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const BurrowPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const BurrowPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// BurrowPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const BurrowPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13AE230);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const BurrowPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// BurrowPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerBurrow.h
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

		static inline auto FSetValue = PreyFunction<void(const BurrowPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13AE250);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const BurrowPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13AE350);
		static inline auto FIsArray = PreyFunction<bool(const BurrowPowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const BurrowPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x157E7A0);
	};

	using LevelProperties = ArkPsiPowerBurrowProperties;
	using UniqueProperties = ArkPsiPowerBurrowUnqiueProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<BurrowPowerProperties::ArkCommonProperty>(0x2D50A38);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<BurrowPowerProperties::ArkUniqueProperty>(0x2D50A58);
	ArkPsiPowerBurrowUnqiueProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<BurrowPowerProperties::ArkLevelsProperty>(0x2D50A78);
	std::vector<ArkPsiPowerBurrowProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerBurrowUnqiueProperties _arg0_);
	const ArkPsiPowerBurrowUnqiueProperties& GetUnique() const;
	std::vector<ArkPsiPowerBurrowProperties>& GetLevels();
	const std::vector<ArkPsiPowerBurrowProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13B06E0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13B09B0);
	static inline auto FInit = PreyFunction<bool(BurrowPowerProperties* const _this)>(0x13B0C40);
};
#endif // MOONCRASH
