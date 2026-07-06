// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/GameDll/ark/ArkSimpleTimer.h>

class ArkClass;
class ArkPsiFlareLightProperties;
class IArkValueBase;
struct IEntity;

// ArkPsiFlareLight
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
class ArkPsiFlareLight
{ // Size=48 (0x30)
public:
	Quat m_localRotationOffset;
	ArkSimpleTimer m_attractTimer;
	unsigned m_blastEntityId;
	unsigned m_targetEntityId;
	int m_slot;
	const ArkPsiFlareLightProperties& m_properties;

	ArkPsiFlareLight(IEntity& _blastEntity, const ArkPsiFlareLightProperties& _properties, const float _attractDuration);
	ArkPsiFlareLight(ArkPsiFlareLight&& _cmp);
	~ArkPsiFlareLight();
	void Update(const float _frameTime) { FUpdate(this, _frameTime); }
	void SetTargetEntityId(const unsigned _entityId) { FSetTargetEntityId(this, _entityId); }

#if 0
	ArkPsiFlareLight(ArkPsiFlareLight& _arg0_);
	ArkPsiFlareLight& operator=(ArkPsiFlareLight&& _arg0_);
	ArkPsiFlareLight& operator=(const ArkPsiFlareLight& _arg0_);
	unsigned GetTargetEntityId() const;
	void DrawDebug();
#endif

	static inline auto FArkPsiFlareLightOv2 = PreyFunction<void(ArkPsiFlareLight* const _this, IEntity& _blastEntity, const ArkPsiFlareLightProperties& _properties, const float _attractDuration)>(0x13A8C80);
	static inline auto FArkPsiFlareLightOv1 = PreyFunction<void(ArkPsiFlareLight* const _this, ArkPsiFlareLight&& _cmp)>(0x13A8C20);
	static inline auto FBitNotArkPsiFlareLight = PreyFunction<void(ArkPsiFlareLight* const _this)>(0x13A8F40);
	static inline auto FUpdate = PreyFunction<void(ArkPsiFlareLight* const _this, const float _frameTime)>(0x13A90E0);
	static inline auto FSetTargetEntityId = PreyFunction<void(ArkPsiFlareLight* const _this, const unsigned _entityId)>(0x13A90C0);
};

// ArkPsiFlareLightProperties
// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
class ArkPsiFlareLightProperties : public ArkReflectedObject
{ // Size=56 (0x38)
public:
	// ArkPsiFlareLightProperties::ArkDiffuseCoeffProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkDiffuseCoeffProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDiffuseCoeffProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkDiffuseCoeffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkDiffuseCoeffProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkPsiFlareLightProperties::ArkSpecularCoeffProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkSpecularCoeffProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSpecularCoeffProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkSpecularCoeffProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkSpecularCoeffProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkPsiFlareLightProperties::ArkMinFrustumAngleDegProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkMinFrustumAngleDegProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMinFrustumAngleDegProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkMinFrustumAngleDegProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkMinFrustumAngleDegProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkPsiFlareLightProperties::ArkMaxFrustumAngleDegProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkMaxFrustumAngleDegProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaxFrustumAngleDegProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkMaxFrustumAngleDegProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkMaxFrustumAngleDegProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
	};

	// ArkPsiFlareLightProperties::ArkTargetAttachmentNameProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkTargetAttachmentNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkTargetAttachmentNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkTargetAttachmentNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkTargetAttachmentNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkPsiFlareLightProperties::ArkMaterialPathProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkMaterialPathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMaterialPathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkMaterialPathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkMaterialPathProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkPsiFlareLightProperties::ArkLightTexturePathProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkLightTexturePathProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLightTexturePathProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkLightTexturePathProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkLightTexturePathProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkPsiFlareLightProperties::ArkColorProperty
	// Header:  Prey/GameDll/ark/player/psipower/ArkPsiFlareLight.h
	class ArkColorProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkColorProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkPsiFlareLightProperties::ArkColorProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13A8BF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkPsiFlareLightProperties::ArkColorProperty* const _this, ArkReflectedObject* const _pObject)>(0x1080CB0);
	};

	static inline auto s_ArkDiffuseCoeffProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkDiffuseCoeffProperty>(0x2D506A8);
	float m_DiffuseCoeff;
	static inline auto s_ArkSpecularCoeffProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkSpecularCoeffProperty>(0x2D506C8);
	float m_SpecularCoeff;
	static inline auto s_ArkMinFrustumAngleDegProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkMinFrustumAngleDegProperty>(0x2D506E8);
	float m_MinFrustumAngleDeg;
	static inline auto s_ArkMaxFrustumAngleDegProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkMaxFrustumAngleDegProperty>(0x2D50708);
	float m_MaxFrustumAngleDeg;
	static inline auto s_ArkTargetAttachmentNameProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkTargetAttachmentNameProperty>(0x2D50728);
	string m_TargetAttachmentName;
	static inline auto s_ArkMaterialPathProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkMaterialPathProperty>(0x2D50748);
	string m_MaterialPath;
	static inline auto s_ArkLightTexturePathProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkLightTexturePathProperty>(0x2D50768);
	string m_LightTexturePath;
	static inline auto s_ArkColorProperty = PreyGlobal<ArkPsiFlareLightProperties::ArkColorProperty>(0x2D50788);
	Vec3 m_Color;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetDiffuseCoeff(float _arg0_);
	const float& GetDiffuseCoeff() const;
	void SetSpecularCoeff(float _arg0_);
	const float& GetSpecularCoeff() const;
	void SetMinFrustumAngleDeg(float _arg0_);
	const float& GetMinFrustumAngleDeg() const;
	void SetMaxFrustumAngleDeg(float _arg0_);
	const float& GetMaxFrustumAngleDeg() const;
	void SetTargetAttachmentName(string _arg0_);
	const string& GetTargetAttachmentName() const;
	void SetMaterialPath(string _arg0_);
	const string& GetMaterialPath() const;
	void SetLightTexturePath(string _arg0_);
	const string& GetLightTexturePath() const;
	void SetColor(Vec3 _arg0_);
	const Vec3& GetColor() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x13A8F80);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x13A8FD0);
};
#endif // MOONCRASH
