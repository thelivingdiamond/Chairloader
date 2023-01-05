// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/ArkPlayerLight.h>

class ArkClass;
class ArkPsiPowerTargetingComponentProperties;
class IArkPsiPower;
class IArkValueBase;
struct IEntity;
struct IEntityClass;
struct IParticleEffect;

// ArkPsiPowerTargetingComponent
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
class ArkPsiPowerTargetingComponent
{ // Size=216 (0xD8)
public:
	using Properties = ArkPsiPowerTargetingComponentProperties;

	const IArkPsiPower* m_pPower;
	ArkPlayerLightVFX m_playerLight;
	IParticleEffect* m_pTargetParticleEffect;
	std::vector<const IEntityClass*> m_validClasses;
	std::vector<uint64_t> m_validMetaTags;
	const ArkPsiPowerTargetingComponentProperties* m_pProperties;

	static Vec3 GetPsiTargetingPosition(const IEntity* const _pEntity) { return FGetPsiTargetingPosition(_pEntity); }
	static IEntity* GetRedirectedPsiTarget(IEntity* const _pEntity) { return FGetRedirectedPsiTarget(_pEntity); }
	static bool IsLineClear(const Vec3& _origin, const IEntity& _entity) { return FIsLineClear(_origin, _entity); }
	ArkPsiPowerTargetingComponent(const IArkPsiPower* _pPower);
	virtual ~ArkPsiPowerTargetingComponent();
	void Initialize(const ArkPsiPowerTargetingComponentProperties& _properties) { FInitialize(this, _properties); }
	virtual bool Start();
	virtual void Stop();
	float GetRange() const { return FGetRange(this); }

#if 0
	const ArkPsiPowerTargetingComponentProperties& GetProperties() const;
	float GetMinRange() const;
	const IArkPsiPower* GetPower() const;
	IParticleEffect* GetTargetParticleEffect() const;
#endif

	static inline auto FGetPsiTargetingPosition = PreyFunction<Vec3(const IEntity* const _pEntity)>(0x1469650);
	static inline auto FGetRedirectedPsiTarget = PreyFunction<IEntity* (IEntity* const _pEntity)>(0x1469780);
	static inline auto FIsLineClear = PreyFunction<bool(const Vec3& _origin, const IEntity& _entity)>(0x1469A40);
	static inline auto FArkPsiPowerTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x14693F0);
	static inline auto FBitNotArkPsiPowerTargetingComponent = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this)>(0x1469450);
	static inline auto FInitialize = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this, const ArkPsiPowerTargetingComponentProperties& _properties)>(0x14697C0);
	static inline auto FStart = PreyFunction<bool(ArkPsiPowerTargetingComponent* const _this)>(0x1B933B0);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this)>(0xA13080);
	static inline auto FGetRange = PreyFunction<float(const ArkPsiPowerTargetingComponent* const _this)>(0x1469770);
};

// ArkPsiPowerTargetingComponentProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
class ArkPsiPowerTargetingComponentProperties : public ArkReflectedObject
{ // Size=80 (0x50)
public:
	// ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkMinRangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinRangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
	};

	// ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkMaxRangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxRangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
	};

	// ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkTargetParticleEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetParticleEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
	};

	// ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkTargetParticleEffectAttachmentProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetParticleEffectAttachmentProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
	};

	// ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkTargetParticleLightEffectProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetParticleLightEffectProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
	};

	// ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkValidTargetClassesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkValidTargetClassesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14690E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1469140);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* _pObject)>(0x1469160);
	};

	// ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiPowerTargetingComponent.h
	class ArkValidTargetMetaTagsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkValidTargetMetaTagsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x1059650);
	};

	static inline auto s_ArkMinRangeProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty>(0x2BF0238);
	float m_MinRange;
	static inline auto s_ArkMaxRangeProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty>(0x2BF0258);
	float m_MaxRange;
	static inline auto s_ArkTargetParticleEffectProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty>(0x2BF0278);
	string m_TargetParticleEffect;
	static inline auto s_ArkTargetParticleEffectAttachmentProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty>(0x2BF0298);
	string m_TargetParticleEffectAttachment;
	static inline auto s_ArkTargetParticleLightEffectProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty>(0x2BF02B8);
	string m_TargetParticleLightEffect;
	static inline auto s_ArkValidTargetClassesProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty>(0x2BF02D8);
	std::vector<string> m_ValidTargetClasses;
	static inline auto s_ArkValidTargetMetaTagsProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty>(0x2BF02F8);
	std::vector<uint64_t> m_ValidTargetMetaTags;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMinRange(float _arg0_);
	const float& GetMinRange() const;
	void SetMaxRange(float _arg0_);
	const float& GetMaxRange() const;
	void SetTargetParticleEffect(string _arg0_);
	const string& GetTargetParticleEffect() const;
	void SetTargetParticleEffectAttachment(string _arg0_);
	const string& GetTargetParticleEffectAttachment() const;
	void SetTargetParticleLightEffect(string _arg0_);
	const string& GetTargetParticleLightEffect() const;
	std::vector<string>& GetValidTargetClasses();
	const std::vector<string>& GetValidTargetClasses() const;
	std::vector<uint64_t>& GetValidTargetMetaTags();
	const std::vector<uint64_t>& GetValidTargetMetaTags() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14694F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1469560);
};

