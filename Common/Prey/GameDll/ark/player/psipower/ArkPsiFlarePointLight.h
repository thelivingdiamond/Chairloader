// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryAnimation/IAttachment.h>

class ArkClass;
class ArkPsiFlarePointLightProperties;
class IArkValueBase;

// ArkPsiFlarePointLight
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
class ArkPsiFlarePointLight : public CLightAttachment
{ // Size=24 (0x18)
public:
	const ArkPsiFlarePointLightProperties& m_properties;

	ArkPsiFlarePointLight(const ArkPsiFlarePointLightProperties& _properties, const Matrix34& _worldTransform);
	virtual ~ArkPsiFlarePointLight();

	static inline auto FArkPsiFlarePointLightOv1 = PreyFunction<void(ArkPsiFlarePointLight* const _this, const ArkPsiFlarePointLightProperties& _properties, const Matrix34& _worldTransform)>(0x13AA0E0);
};

// ArkPsiFlarePointLightProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
class ArkPsiFlarePointLightProperties : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkPsiFlarePointLightProperties::ArkRadiusProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
	class ArkRadiusProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkRadiusProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlarePointLightProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlarePointLightProperties::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiFlarePointLightProperties::ArkDiffuseCoeffProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
	class ArkDiffuseCoeffProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDiffuseCoeffProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlarePointLightProperties::ArkDiffuseCoeffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlarePointLightProperties::ArkDiffuseCoeffProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkPsiFlarePointLightProperties::ArkSpecularCoeffProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
	class ArkSpecularCoeffProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSpecularCoeffProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlarePointLightProperties::ArkSpecularCoeffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlarePointLightProperties::ArkSpecularCoeffProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiFlarePointLightProperties::ArkLensFlareNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
	class ArkLensFlareNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLensFlareNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlarePointLightProperties::ArkLensFlareNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13AA040);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlarePointLightProperties::ArkLensFlareNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiFlarePointLightProperties::ArkColorProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlarePointLight.h
	class ArkColorProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkColorProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlarePointLightProperties::ArkColorProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x14028D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlarePointLightProperties::ArkColorProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkPsiFlarePointLightProperties::ArkRadiusProperty>(0x2D50810);
	float m_Radius;
	static inline auto s_ArkDiffuseCoeffProperty = PreyGlobal<ArkPsiFlarePointLightProperties::ArkDiffuseCoeffProperty>(0x2D50830);
	float m_DiffuseCoeff;
	static inline auto s_ArkSpecularCoeffProperty = PreyGlobal<ArkPsiFlarePointLightProperties::ArkSpecularCoeffProperty>(0x2D50850);
	float m_SpecularCoeff;
	static inline auto s_ArkLensFlareNameProperty = PreyGlobal<ArkPsiFlarePointLightProperties::ArkLensFlareNameProperty>(0x2D50870);
	string m_LensFlareName;
	static inline auto s_ArkColorProperty = PreyGlobal<ArkPsiFlarePointLightProperties::ArkColorProperty>(0x2D50890);
	Vec3 m_Color;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetRadius(float _arg0_);
	const float& GetRadius() const;
	void SetDiffuseCoeff(float _arg0_);
	const float& GetDiffuseCoeff() const;
	void SetSpecularCoeff(float _arg0_);
	const float& GetSpecularCoeff() const;
	void SetLensFlareName(string _arg0_);
	const string& GetLensFlareName() const;
	void SetColor(Vec3 _arg0_);
	const Vec3& GetColor() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13AA4D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13AA510);
};
#endif // MOONCRASH
