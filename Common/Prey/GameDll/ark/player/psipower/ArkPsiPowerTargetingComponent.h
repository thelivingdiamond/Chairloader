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

#ifndef MOONCRASH
	static inline auto FGetPsiTargetingPosition = PreyFunction<Vec3(const IEntity* const _pEntity)>(0x1469650);
	static inline auto FGetRedirectedPsiTarget = PreyFunction<IEntity* (IEntity* const _pEntity)>(0x1469780);
	static inline auto FIsLineClear = PreyFunction<bool(const Vec3& _origin, const IEntity& _entity)>(0x1469A40);
	static inline auto FArkPsiPowerTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x14693F0);
	static inline auto FBitNotArkPsiPowerTargetingComponent = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this)>(0x1469450);
	static inline auto FInitialize = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this, const ArkPsiPowerTargetingComponentProperties& _properties)>(0x14697C0);
	static inline auto FStart = PreyFunction<bool(ArkPsiPowerTargetingComponent* const _this)>(0x1B933B0);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this)>(0xA13080);
	static inline auto FGetRange = PreyFunction<float(const ArkPsiPowerTargetingComponent* const _this)>(0x1469770);
#else
	static inline auto FGetPsiTargetingPosition = PreyFunction<Vec3(const IEntity* const _pEntity)>(0x1580F40);
	static inline auto FGetRedirectedPsiTarget = PreyFunction<IEntity* (IEntity* const _pEntity)>(0x1581070);
	static inline auto FIsLineClear = PreyFunction<bool(const Vec3& _origin, const IEntity& _entity)>(0x1581330);
	static inline auto FArkPsiPowerTargetingComponentOv1 = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this, const IArkPsiPower* _pPower)>(0x1580CE0);
	static inline auto FBitNotArkPsiPowerTargetingComponent = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this)>(0x1580D40);
	static inline auto FInitialize = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this, const ArkPsiPowerTargetingComponentProperties& _properties)>(0x15810B0);
	static inline auto FStart = PreyFunction<bool(ArkPsiPowerTargetingComponent* const _this)>(0x1A302A0);
	static inline auto FStop = PreyFunction<void(ArkPsiPowerTargetingComponent* const _this)>(0x1333E90);
	static inline auto FGetRange = PreyFunction<float(const ArkPsiPowerTargetingComponent* const _this)>(0x1581060);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13D4F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14690E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1469140);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* _pObject)>(0x1469160);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1580A10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1580A70);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty* const _this, ArkReflectedObject* _pObject)>(0x1580A90);
#endif
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

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14691D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x14691F0);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x1059650);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A5800);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1073740);
		static inline auto FIsArray = PreyFunction<bool(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty* const _this, ArkReflectedObject* _pObject)>(0x1077BE0);
#endif
	};

#ifndef MOONCRASH
	static inline auto s_ArkMinRangeProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty>(0x2BF0238);
#else
	static inline auto s_ArkMinRangeProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkMinRangeProperty>(0x2D6ADC8);
#endif
	float m_MinRange;
#ifndef MOONCRASH
	static inline auto s_ArkMaxRangeProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty>(0x2BF0258);
#else
	static inline auto s_ArkMaxRangeProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkMaxRangeProperty>(0x2D6ADE8);
#endif
	float m_MaxRange;
#ifndef MOONCRASH
	static inline auto s_ArkTargetParticleEffectProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty>(0x2BF0278);
#else
	static inline auto s_ArkTargetParticleEffectProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectProperty>(0x2D6AE08);
#endif
	string m_TargetParticleEffect;
#ifndef MOONCRASH
	static inline auto s_ArkTargetParticleEffectAttachmentProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty>(0x2BF0298);
#else
	static inline auto s_ArkTargetParticleEffectAttachmentProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleEffectAttachmentProperty>(0x2D6AE28);
#endif
	string m_TargetParticleEffectAttachment;
#ifndef MOONCRASH
	static inline auto s_ArkTargetParticleLightEffectProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty>(0x2BF02B8);
#else
	static inline auto s_ArkTargetParticleLightEffectProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkTargetParticleLightEffectProperty>(0x2D6AE48);
#endif
	string m_TargetParticleLightEffect;
#ifndef MOONCRASH
	static inline auto s_ArkValidTargetClassesProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty>(0x2BF02D8);
#else
	static inline auto s_ArkValidTargetClassesProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkValidTargetClassesProperty>(0x2D6AE68);
#endif
	std::vector<string> m_ValidTargetClasses;
#ifndef MOONCRASH
	static inline auto s_ArkValidTargetMetaTagsProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty>(0x2BF02F8);
#else
	static inline auto s_ArkValidTargetMetaTagsProperty = PreyGlobal<ArkPsiPowerTargetingComponentProperties::ArkValidTargetMetaTagsProperty>(0x2D6AE88);
#endif
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

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x14694F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1469560);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1580DE0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1580E50);
#endif
};
