// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerPlayerProximityTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkPsiPowerTargetingComponent;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiPowerConsumeCorpse
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
class ArkPsiPowerConsumeCorpse : public CArkPsiPower<ConsumeCorpsePowerProperties>
{ // Size=528 (0x210)
public:
	ArkPsiPowerPlayerProximityTargetingComponent m_targetingComponent;

	ArkPsiPowerConsumeCorpse();
	virtual ~ArkPsiPowerConsumeCorpse();
	virtual void Cancel();
	virtual bool StartTargeting();
	virtual void UpdateTargeting(const float _frameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual EArkPsiPowers GetEnum() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual bool Start_Derived();
	virtual void SetLevel_Derived(const int _level);
	void Consume(const unsigned _targetEntityId) const { FConsume(this, _targetEntityId); }

#if 0
	bool FilterTarget(const IEntity& _arg0_) const;
#endif

	static inline auto FArkPsiPowerConsumeCorpseOv1 = PreyFunction<void(ArkPsiPowerConsumeCorpse* const _this)>(0x13B6BF0);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerConsumeCorpse* const _this)>(0x140D970);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerConsumeCorpse* const _this)>(0x13B7FC0);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerConsumeCorpse* const _this, const float _frameTime)>(0x13B8340);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerConsumeCorpse* const _this, std::vector<IEntity*>* _return_value_)>(0x13B7CE0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerConsumeCorpse* const _this, std::vector<IEntity*>* _return_value_)>(0x16B1C80);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerConsumeCorpse* const _this)>(0x13B7CD0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const ArkPsiPowerConsumeCorpse* const _this)>(0x1368F30);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerConsumeCorpse* const _this)>(0x13B7FE0);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerConsumeCorpse* const _this, const int _level)>(0x13B7F60);
	static inline auto FConsume = PreyFunction<void(const ArkPsiPowerConsumeCorpse* const _this, const unsigned _targetEntityId)>(0x13B7360);
};

// ArkPsiPowerConsumeCorpseProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
class ArkPsiPowerConsumeCorpseProperties : public ArkReflectedObject
{ // Size=136 (0x88)
public:
	// ArkPsiPowerConsumeCorpseProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1443F00);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkLerpDurationProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkLerpDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLerpDurationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkLerpDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkLerpDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E0B70);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkLerpTargetPositionOffsetProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkLerpTargetPositionOffsetProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLerpTargetPositionOffsetProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkLerpTargetPositionOffsetProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14028D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkLerpTargetPositionOffsetProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkConsumeAudioTriggerProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkConsumeAudioTriggerProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkConsumeAudioTriggerProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkConsumeAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A04B0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkConsumeAudioTriggerProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkPlayerSignalPackageIdProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkPlayerSignalPackageIdProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayerSignalPackageIdProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkPlayerSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkPlayerSignalPackageIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x12E7A60);
	};

	// ArkPsiPowerConsumeCorpseProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerConsumeCorpseProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B26C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerConsumeCorpseProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkDisplayNameProperty>(0x2D510A8);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkDescriptionProperty>(0x2D510C8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkCooldownDurationSecProperty>(0x2D510E8);
	float m_CooldownDurationSec;
	static inline auto s_ArkLerpDurationProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkLerpDurationProperty>(0x2D51108);
	float m_LerpDuration;
	static inline auto s_ArkLerpTargetPositionOffsetProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkLerpTargetPositionOffsetProperty>(0x2D51128);
	Vec3 m_LerpTargetPositionOffset;
	static inline auto s_ArkConsumeAudioTriggerProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkConsumeAudioTriggerProperty>(0x2D51148);
	string m_ConsumeAudioTrigger;
	static inline auto s_ArkPlayerSignalPackageIdProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkPlayerSignalPackageIdProperty>(0x2D51168);
	uint64_t m_PlayerSignalPackageId;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerConsumeCorpseProperties::ArkTargetingPropertiesProperty>(0x2D51188);
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
	void SetLerpDuration(float _arg0_);
	const float& GetLerpDuration() const;
	void SetLerpTargetPositionOffset(Vec3 _arg0_);
	const Vec3& GetLerpTargetPositionOffset() const;
	void SetConsumeAudioTrigger(string _arg0_);
	const string& GetConsumeAudioTrigger() const;
	void SetPlayerSignalPackageId(uint64_t _arg0_);
	const uint64_t& GetPlayerSignalPackageId() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13B78B0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13B7B40);
};

// ConsumeCorpsePowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
class ConsumeCorpsePowerProperties : public ArkReflectedLibrary
{ // Size=248 (0xF8)
public:
	// ConsumeCorpsePowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCommonProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ConsumeCorpsePowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14030A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ConsumeCorpsePowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x108CDE0);
	};

	// ConsumeCorpsePowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkUniqueProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ConsumeCorpsePowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B8620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ConsumeCorpsePowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF510);
	};

	// ConsumeCorpsePowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerConsumeCorpse.h
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

		static inline auto FSetValue = PreyFunction<void(const ConsumeCorpsePowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13B6490);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ConsumeCorpsePowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B65A0);
		static inline auto FIsArray = PreyFunction<bool(const ConsumeCorpsePowerProperties::ArkLevelsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ConsumeCorpsePowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x13B65F0);
	};

	using LevelProperties = ArkPsiPowerConsumeCorpseProperties;
	using UniqueProperties = bool;

	static inline auto s_ArkCommonProperty = PreyGlobal<ConsumeCorpsePowerProperties::ArkCommonProperty>(0x2D511A8);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<ConsumeCorpsePowerProperties::ArkUniqueProperty>(0x2D511C8);
	bool m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<ConsumeCorpsePowerProperties::ArkLevelsProperty>(0x2D511E8);
	std::vector<ArkPsiPowerConsumeCorpseProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(bool _arg0_);
	const bool& GetUnique() const;
	std::vector<ArkPsiPowerConsumeCorpseProperties>& GetLevels();
	const std::vector<ArkPsiPowerConsumeCorpseProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13B7930);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13B7BE0);
	static inline auto FInit = PreyFunction<bool(ConsumeCorpsePowerProperties* const _this)>(0x13B7D80);
};
#endif // MOONCRASH
