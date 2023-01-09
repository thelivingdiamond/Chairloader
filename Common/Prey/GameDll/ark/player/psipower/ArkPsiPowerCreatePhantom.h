// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiPowerCommonProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryNetwork/ISerialize.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiCorpsePhantom.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerIndividualTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h>
#include <Prey/GameDll/ark/player/psipower/carkpsipower.h>

class ArkClass;
class ArkPsiPowerTargetingComponent;
class ArkPsiPowerCreatePhantomProperties;
class ArkPsiPowerCreatePhantomCommonProperties;
class CCryName;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiPowerCreatePhantomCommonProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
class ArkPsiPowerCreatePhantomCommonProperties : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkRaiseHeightProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkRaiseHeightProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkRaiseSpeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkRaiseSpeedProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkRaiseDurationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkRaiseDurationProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkCorpseDampingProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkCorpseDampingProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
	};

	// ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkCorpseGravityProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkCorpseGravityProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkCorpseParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkCorpseParticleEffectProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkCorpseParticleEffectAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkCorpseParticleEffectAttachmentProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
	};

	static inline auto s_ArkRaiseHeightProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseHeightProperty>(0x2BDBAA8);
	float m_RaiseHeight;
	static inline auto s_ArkRaiseSpeedProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseSpeedProperty>(0x2BDBAC8);
	float m_RaiseSpeed;
	static inline auto s_ArkRaiseDurationProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkRaiseDurationProperty>(0x2BDBAE8);
	float m_RaiseDuration;
	static inline auto s_ArkCorpseDampingProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseDampingProperty>(0x2BDBB08);
	float m_CorpseDamping;
	static inline auto s_ArkCorpseGravityProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseGravityProperty>(0x2BDBB28);
	float m_CorpseGravity;
	static inline auto s_ArkCorpseParticleEffectProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectProperty>(0x2BDBB48);
	string m_CorpseParticleEffect;
	static inline auto s_ArkCorpseParticleEffectAttachmentProperty = PreyGlobal<ArkPsiPowerCreatePhantomCommonProperties::ArkCorpseParticleEffectAttachmentProperty>(0x2BDBB68);
	string m_CorpseParticleEffectAttachment;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetRaiseHeight(float _arg0_);
	const float& GetRaiseHeight() const;
	void SetRaiseSpeed(float _arg0_);
	const float& GetRaiseSpeed() const;
	void SetRaiseDuration(float _arg0_);
	const float& GetRaiseDuration() const;
	void SetCorpseDamping(float _arg0_);
	const float& GetCorpseDamping() const;
	void SetCorpseGravity(float _arg0_);
	const float& GetCorpseGravity() const;
	void SetCorpseParticleEffect(string _arg0_);
	const string& GetCorpseParticleEffect() const;
	void SetCorpseParticleEffectAttachment(string _arg0_);
	const string& GetCorpseParticleEffectAttachment() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1332190);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13323C0);
};

// CreatePhantomPowerProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
class CreatePhantomPowerProperties : public ArkReflectedLibrary
{ // Size=280 (0x118)
public:
	// CreatePhantomPowerProperties::ArkCommonProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkCommonProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkCommonProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const CreatePhantomPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1591940);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CreatePhantomPowerProperties::ArkCommonProperty* const _this, ArkReflectedObject* const _pObject)>(0x10660A0);
	};

	// CreatePhantomPowerProperties::ArkUniqueProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkUniqueProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#if 0
		ArkUniqueProperty();
#endif

		static inline auto FSetValue = PreyFunction<void(const CreatePhantomPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1330D80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CreatePhantomPowerProperties::ArkUniqueProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466C40);
	};

	// CreatePhantomPowerProperties::ArkLevelsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
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

		static inline auto FSetValue = PreyFunction<void(const CreatePhantomPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1330E90);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const CreatePhantomPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1330F90);
		static inline auto FIsArray = PreyFunction<bool(const CreatePhantomPowerProperties::ArkLevelsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const CreatePhantomPowerProperties::ArkLevelsProperty* const _this, ArkReflectedObject* _pObject)>(0x1330FE0);
	};

	using LevelProperties = ArkPsiPowerCreatePhantomProperties;
	using UniqueProperties = ArkPsiPowerCreatePhantomCommonProperties;

	static inline auto s_ArkCommonProperty = PreyGlobal<CreatePhantomPowerProperties::ArkCommonProperty>(0x2BDBC28);
	ArkPsiPowerCommonProperties m_Common;
	static inline auto s_ArkUniqueProperty = PreyGlobal<CreatePhantomPowerProperties::ArkUniqueProperty>(0x2BDBC48);
	ArkPsiPowerCreatePhantomCommonProperties m_Unique;
	static inline auto s_ArkLevelsProperty = PreyGlobal<CreatePhantomPowerProperties::ArkLevelsProperty>(0x2BDBC68);
	std::vector<ArkPsiPowerCreatePhantomProperties> m_Levels;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	void SetCommon(ArkPsiPowerCommonProperties _arg0_);
	const ArkPsiPowerCommonProperties& GetCommon() const;
	void SetUnique(ArkPsiPowerCreatePhantomCommonProperties _arg0_);
	const ArkPsiPowerCreatePhantomCommonProperties& GetUnique() const;
	std::vector<ArkPsiPowerCreatePhantomProperties>& GetLevels();
	const std::vector<ArkPsiPowerCreatePhantomProperties>& GetLevels() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1332250);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1332500);
	static inline auto FInit = PreyFunction<bool(CreatePhantomPowerProperties* const _this)>(0x13327E0);
};


// ArkPsiPowerCreatePhantom
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
class ArkPsiPowerCreatePhantom : public CArkPsiPower<CreatePhantomPowerProperties>
{ // Size=800 (0x320)
public:
	ArkPsiPowerIndividualTargetingComponent m_targetingComponent;
	ArkPsiCorpsePhantom m_currentCorpsePhantom;
	std::vector<ArkPsiCorpsePhantom> m_corpsePhantoms;
	std::vector<int> m_spawnFrequencies;

	ArkPsiPowerCreatePhantom();
	virtual ~ArkPsiPowerCreatePhantom();
	virtual bool Stop();
	virtual void Cancel();
	virtual void OnReset();
	virtual bool Start_Derived();
	virtual bool StartTargeting();
	virtual Vec3 GetTargetPosition() const;
	virtual void RefreshTargets();
	virtual void UpdateTargeting(const float _frameTime);
	virtual std::vector<IEntity*> GetSelectedTargets() const;
	virtual std::vector<IEntity*> GetUnselectedTargets() const;
	virtual const ArkPsiPowerTargetingComponent* GetTargetingComponent() const;
	virtual void ProcessInputForTargeting(const CCryName& _actionId, int _activationMode, float _value);
	virtual void Serialize(TSerialize _serializer);
	virtual void PostSerialize();
	virtual EArkPsiPowers GetEnum() const;
	virtual const char* GetTargetingErrorString() const;
	bool IsCreatedPhantom(const unsigned _entityId) const { return FIsCreatedPhantom(this, _entityId); }
	unsigned GetCreatedPhantomId() const { return FGetCreatedPhantomId(this); }
	void OnNpcKilled(const IEntity& _entity) { FOnNpcKilled(this, _entity); }
	virtual void Update(const float _frameTime);
	virtual void SetLevel_Derived(const int _level);
	bool FilterTarget(const IEntity& _entity) const { return FFilterTarget(this, _entity); }

	static inline auto FArkPsiPowerCreatePhantom = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this)>(0x1331AC0);
	static inline auto FStop = PreyFunction<bool(ArkPsiPowerCreatePhantom* const _this)>(0x1333340);
	static inline auto FCancel = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this)>(0xB44E10);
	static inline auto FOnReset = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this)>(0x1332A30);
	static inline auto FStart_Derived = PreyFunction<bool(ArkPsiPowerCreatePhantom* const _this)>(0x1333130);
	static inline auto FStartTargeting = PreyFunction<bool(ArkPsiPowerCreatePhantom* const _this)>(0x15A01A0);
	static inline auto FGetTargetPosition = PreyFunction<Vec3*(const ArkPsiPowerCreatePhantom* const _this, Vec3* _return_value_)>(0x13327A0);
	static inline auto FRefreshTargets = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this)>(0x1332A80);
	static inline auto FUpdateTargeting = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this, const float _frameTime)>(0x15A0570);
	static inline auto FGetSelectedTargets = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerCreatePhantom* const _this, std::vector<IEntity*>* _return_value_)>(0x159FEA0);
	static inline auto FGetUnselectedTargets = PreyFunction<std::vector<IEntity*>*(const ArkPsiPowerCreatePhantom* const _this, std::vector<IEntity*>* _return_value_)>(0x159FEC0);
	static inline auto FGetTargetingComponent = PreyFunction<const ArkPsiPowerTargetingComponent* (const ArkPsiPowerCreatePhantom* const _this)>(0x12BDA90);
	static inline auto FProcessInputForTargeting = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this, const CCryName& _actionId, int _activationMode, float _value)>(0xA13080);
	static inline auto FSerialize = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this, TSerialize _serializer)>(0x1332AF0);
	static inline auto FPostSerialize = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this)>(0x1332A40);
	static inline auto FGetEnum = PreyFunction<EArkPsiPowers(const ArkPsiPowerCreatePhantom* const _this)>(0x1A337B0);
	static inline auto FGetTargetingErrorString = PreyFunction<const char* (const ArkPsiPowerCreatePhantom* const _this)>(0x158AEF0);
	static inline auto FIsCreatedPhantom = PreyFunction<bool(const ArkPsiPowerCreatePhantom* const _this, const unsigned _entityId)>(0x13329C0);
	static inline auto FGetCreatedPhantomId = PreyFunction<unsigned(const ArkPsiPowerCreatePhantom* const _this)>(0x13325F0);
	static inline auto FOnNpcKilled = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this, const IEntity& _entity)>(0x13329D0);
	static inline auto FUpdate = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this, const float _frameTime)>(0x1333380);
	static inline auto FSetLevel_Derived = PreyFunction<void(ArkPsiPowerCreatePhantom* const _this, const int _level)>(0x1333090);
	static inline auto FFilterTarget = PreyFunction<bool(const ArkPsiPowerCreatePhantom* const _this, const IEntity& _entity)>(0x1332320);
};

// ArkPsiPowerCreatePhantomProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
class ArkPsiPowerCreatePhantomProperties : public ArkReflectedObject
{ // Size=128 (0x80)
public:
	// ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkDisplayNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDisplayNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x135FC80);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkDescriptionProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDescriptionProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkCooldownDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkCooldownDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkTargetingPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetingPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1330CB0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerCreatePhantom.h
	class ArkArchetypesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkArchetypesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1330CF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1330D50);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty* const _this, ArkReflectedObject* _pObject)>(0x1330D70);
	};

	static inline auto s_ArkDisplayNameProperty = PreyGlobal<ArkPsiPowerCreatePhantomProperties::ArkDisplayNameProperty>(0x2BDBB88);
	string m_DisplayName;
	static inline auto s_ArkDescriptionProperty = PreyGlobal<ArkPsiPowerCreatePhantomProperties::ArkDescriptionProperty>(0x2BDBBA8);
	string m_Description;
	static inline auto s_ArkCooldownDurationSecProperty = PreyGlobal<ArkPsiPowerCreatePhantomProperties::ArkCooldownDurationSecProperty>(0x2BDBBC8);
	float m_CooldownDurationSec;
	static inline auto s_ArkTargetingPropertiesProperty = PreyGlobal<ArkPsiPowerCreatePhantomProperties::ArkTargetingPropertiesProperty>(0x2BDBBE8);
	ArkPsiPowerTargetingComponentProperties m_TargetingProperties;
	static inline auto s_ArkArchetypesProperty = PreyGlobal<ArkPsiPowerCreatePhantomProperties::ArkArchetypesProperty>(0x2BDBC08);
	std::vector<string> m_Archetypes;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDisplayName(string _arg0_);
	const string& GetDisplayName() const;
	void SetDescription(string _arg0_);
	const string& GetDescription() const;
	void SetCooldownDurationSec(float _arg0_);
	const float& GetCooldownDurationSec() const;
	void SetTargetingProperties(ArkPsiPowerTargetingComponentProperties _arg0_);
	const ArkPsiPowerTargetingComponentProperties& GetTargetingProperties() const;
	std::vector<string>& GetArchetypes();
	const std::vector<string>& GetArchetypes() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13321D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1332460);
};
