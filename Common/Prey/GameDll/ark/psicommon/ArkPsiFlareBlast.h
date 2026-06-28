// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPsiBlastProperties.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h>
#include <Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h>
#include <Prey/GameDll/ark/psicommon/arkpsiblast.h>

class ArkClass;
class ArkPsiFlarePointLight;
enum class EArkPsiPowers;
class IArkValueBase;
struct IEntity;

// ArkPsiFlareBlastProperties
// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
class ArkPsiFlareBlastProperties : public ArkReflectedObject
{ // Size=264 (0x108)
public:
	// ArkPsiFlareBlastProperties::ArkMaxLightsProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkMaxLightsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxLightsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkMaxLightsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkMaxLightsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiFlareBlastProperties::ArkMaxAttractRadiusProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkMaxAttractRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxAttractRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkMaxAttractRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkMaxAttractRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkPsiFlareBlastProperties::ArkAttractDurationSecProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkAttractDurationSecProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAttractDurationSecProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkAttractDurationSecProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkAttractDurationSecProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiFlareBlastProperties::ArkMaxBlindingViewAngleDegProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkMaxBlindingViewAngleDegProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxBlindingViewAngleDegProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkMaxBlindingViewAngleDegProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkMaxBlindingViewAngleDegProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	// ArkPsiFlareBlastProperties::ArkMaxPlayerBlindingDistanceProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkMaxPlayerBlindingDistanceProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxPlayerBlindingDistanceProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkMaxPlayerBlindingDistanceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkMaxPlayerBlindingDistanceProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiFlareBlastProperties::ArkBlastPropertiesProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkBlastPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlastPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C7080);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkBlastPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiFlareBlastProperties::ArkLightPropertiesProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkLightPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLightPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkLightPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C72E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkLightPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x1084620);
	};

	// ArkPsiFlareBlastProperties::ArkPointLightPropertiesProperty
	// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
	class ArkPointLightPropertiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPointLightPropertiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareBlastProperties::ArkPointLightPropertiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13C7430);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareBlastProperties::ArkPointLightPropertiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A0810);
	};

	static inline auto s_ArkMaxLightsProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkMaxLightsProperty>(0x2D52218);
	int m_MaxLights;
	static inline auto s_ArkMaxAttractRadiusProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkMaxAttractRadiusProperty>(0x2D52238);
	float m_MaxAttractRadius;
	static inline auto s_ArkAttractDurationSecProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkAttractDurationSecProperty>(0x2D52258);
	float m_AttractDurationSec;
	static inline auto s_ArkMaxBlindingViewAngleDegProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkMaxBlindingViewAngleDegProperty>(0x2D52278);
	float m_MaxBlindingViewAngleDeg;
	static inline auto s_ArkMaxPlayerBlindingDistanceProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkMaxPlayerBlindingDistanceProperty>(0x2D52298);
	float m_MaxPlayerBlindingDistance;
	static inline auto s_ArkBlastPropertiesProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkBlastPropertiesProperty>(0x2D522B8);
	ArkPsiBlastProperties m_BlastProperties;
	static inline auto s_ArkLightPropertiesProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkLightPropertiesProperty>(0x2D522D8);
	ArkPsiFlareLightProperties m_LightProperties;
	static inline auto s_ArkPointLightPropertiesProperty = PreyGlobal<ArkPsiFlareBlastProperties::ArkPointLightPropertiesProperty>(0x2D522F8);
	ArkPsiFlarePointLightProperties m_PointLightProperties;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMaxLights(int _arg0_);
	const int& GetMaxLights() const;
	void SetMaxAttractRadius(float _arg0_);
	const float& GetMaxAttractRadius() const;
	void SetAttractDurationSec(float _arg0_);
	const float& GetAttractDurationSec() const;
	void SetMaxBlindingViewAngleDeg(float _arg0_);
	const float& GetMaxBlindingViewAngleDeg() const;
	void SetMaxPlayerBlindingDistance(float _arg0_);
	const float& GetMaxPlayerBlindingDistance() const;
	void SetBlastProperties(ArkPsiBlastProperties _arg0_);
	const ArkPsiBlastProperties& GetBlastProperties() const;
	void SetLightProperties(ArkPsiFlareLightProperties _arg0_);
	const ArkPsiFlareLightProperties& GetLightProperties() const;
	void SetPointLightProperties(ArkPsiFlarePointLightProperties _arg0_);
	const ArkPsiFlarePointLightProperties& GetPointLightProperties() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13C93A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13C94F0);
};

// CArkPsiFlareBlast
// Header:  Prey/GameDll/ark/psicommon/ArkPsiFlareBlast.h
class CArkPsiFlareBlast : public CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >
{ // Size=120 (0x78)
public:
	using BaseType = CArkPsiBlast<CArkPsiFlareBlast,CArkPsiBlastProperties<ArkPsiFlareBlastProperties> >;
	using BlastProperties = CArkPsiBlastProperties<ArkPsiFlareBlastProperties>;

	std::unique_ptr<ArkPsiFlarePointLight> m_pPointLight;
	std::vector<ArkPsiFlareLight> m_lights;
	int m_currentLightIndex;

	CArkPsiFlareBlast();
	CArkPsiFlareBlast(CArkPsiFlareBlast&& _blast);
	CArkPsiFlareBlast(const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* _pProperties);
	CArkPsiFlareBlast& operator=(CArkPsiFlareBlast&& _blast) { return FoperatorEq(this, _blast); }
	void UpdateDelay(const std::vector<IEntity*>& _entities) { FUpdateDelay(this, _entities); }
	void UpdateEffect(const std::vector<IEntity*>& _entities) { FUpdateEffect(this, _entities); }
	void UpdateFrame(const float _frameTime) { FUpdateFrame(this, _frameTime); }

#if 0
	float GetRadius() const;
	EArkPsiPowers GetPower() const;
#endif

	static inline auto FCArkPsiFlareBlastOv2 = PreyFunction<void(CArkPsiFlareBlast* const _this)>(0x13C8D60);
	static inline auto FCArkPsiFlareBlastOv1 = PreyFunction<void(CArkPsiFlareBlast* const _this, CArkPsiFlareBlast&& _blast)>(0x13C8B90);
	static inline auto FCArkPsiFlareBlastOv0 = PreyFunction<void(CArkPsiFlareBlast* const _this, const Vec3& _pos, const CArkPsiBlastProperties<ArkPsiFlareBlastProperties>* _pProperties)>(0x13C8BF0);
	static inline auto FoperatorEq = PreyFunction<CArkPsiFlareBlast& (CArkPsiFlareBlast* const _this, CArkPsiFlareBlast&& _blast)>(0x13C8DB0);
	static inline auto FUpdateDelay = PreyFunction<void(CArkPsiFlareBlast* const _this, const std::vector<IEntity*>& _entities)>(0x13C95E0);
	static inline auto FUpdateEffect = PreyFunction<void(CArkPsiFlareBlast* const _this, const std::vector<IEntity*>& _entities)>(0x13C9980);
	static inline auto FUpdateFrame = PreyFunction<void(CArkPsiFlareBlast* const _this, const float _frameTime)>(0x13C9A30);
};
#endif // MOONCRASH
