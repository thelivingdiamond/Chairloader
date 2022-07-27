// Header file automatically created from a PDB.

#pragma once
#include <Prey/Ark/arkmaterialanimations.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryMemory/StlDbgAlloc.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimation : public ArkReflectedObject // Id=8014244 Size=88
{
public:
	class ArkIdProperty : public ArkProperty // Id=8014245 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMaterialAnimation::ArkIdProperty s_ArkIdProperty;
	uint64_t m_Id;
	
	class ArkNameProperty : public ArkProperty // Id=8014246 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkMaterialAnimation::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkAttachmentNameProperty : public ArkProperty // Id=8014247 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkAttachmentNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkAttachmentNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkMaterialAnimation::ArkAttachmentNameProperty s_ArkAttachmentNameProperty;
	string m_AttachmentName;
	
	class ArkMeshSlotProperty : public ArkProperty // Id=8014248 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkMeshSlotProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkMeshSlotProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkMaterialAnimation::ArkMeshSlotProperty s_ArkMeshSlotProperty;
	int m_MeshSlot;
	
	class ArkMaterialReferenceProperty : public ArkProperty // Id=8014249 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkMaterialReferenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkMaterialReferenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkMaterialAnimation::ArkMaterialReferenceProperty s_ArkMaterialReferenceProperty;
	string m_MaterialReference;
	
	class ArkSubMaterialsProperty : public ArkProperty // Id=801424A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073350);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073470);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this, ArkReflectedObject *_pObject)>(0x10734A0);
	};

	static ArkMaterialAnimation::ArkSubMaterialsProperty s_ArkSubMaterialsProperty;
	std::vector<ArkMaterialAnimationSubMaterialData> m_SubMaterials;
	std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	void AddRgbKeyframesToQueue(ArkMaterialAnimationRgbKeysArray const &_keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel) { FAddRgbKeyframesToQueue(this,_keysArray,_subMaterialSlot,_channel); }
	void AddKeyframesToQueue(ArkMaterialAnimationKeysArray const &_keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel) { FAddKeyframesToQueue(this,_keysArray,_subMaterialSlot,_channel); }
	
#if 0
	void SetId(uint64_t arg0);
	const uint64_t &GetId() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetAttachmentName(string arg0);
	string const &GetAttachmentName() const;
	void SetMeshSlot(int arg0);
	const int &GetMeshSlot() const;
	void SetMaterialReference(string arg0);
	string const &GetMaterialReference() const;
	std::vector<ArkMaterialAnimationSubMaterialData> &GetSubMaterials();
	std::vector<ArkMaterialAnimationSubMaterialData> const &GetSubMaterials() const;
	void GenerateKeyframeQueue();
	std::vector<ArkMaterialAnimationKeyframe> const &GetKeyframeQueue() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1077160);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1077320);
	static inline auto FAddRgbKeyframesToQueue = PreyFunction<void(ArkMaterialAnimation *const _this, ArkMaterialAnimationRgbKeysArray const &_keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel)>(0x1076EE0);
	static inline auto FAddKeyframesToQueue = PreyFunction<void(ArkMaterialAnimation *const _this, ArkMaterialAnimationKeysArray const &_keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel)>(0x1076CA0);
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationRgbKeysArray : public ArkReflectedObject // Id=8014251 Size=24
{
public:
	class ArkRgbKeysProperty : public ArkProperty // Id=8014252 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10734D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10734F0);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const *const _this, ArkReflectedObject *_pObject)>(0x1073510);
	};

	static ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty s_ArkRgbKeysProperty;
	std::vector<ArkMaterialAnimationRgbKey> m_RgbKeys;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	ArkMaterialAnimationRgbKeysArray &operator=(ArkMaterialAnimationRgbKeysArray const &__that) { return FoperatorEqOv1(this,__that); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkMaterialAnimationRgbKey> &GetRgbKeys();
	std::vector<ArkMaterialAnimationRgbKey> const &GetRgbKeys() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkMaterialAnimationRgbKeysArray &(ArkMaterialAnimationRgbKeysArray *const _this, ArkMaterialAnimationRgbKeysArray const &__that)>(0x39DB00);
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationRgbKey : public ArkReflectedObject // Id=8014256 Size=16
{
public:
	class ArkTimeProperty : public ArkProperty // Id=8014257 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkTimeProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationRgbKey::ArkTimeProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMaterialAnimationRgbKey::ArkTimeProperty s_ArkTimeProperty;
	float m_Time;
	
	class ArkRedProperty : public ArkProperty // Id=8014258 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkRedProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationRgbKey::ArkRedProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328410);
	};

	static ArkMaterialAnimationRgbKey::ArkRedProperty s_ArkRedProperty;
	float m_Red;
	
	class ArkGreenProperty : public ArkProperty // Id=8014259 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkGreenProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationRgbKey::ArkGreenProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkMaterialAnimationRgbKey::ArkGreenProperty s_ArkGreenProperty;
	float m_Green;
	
	class ArkBlueProperty : public ArkProperty // Id=801425A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkBlueProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationRgbKey::ArkBlueProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1064F90);
	};

	static ArkMaterialAnimationRgbKey::ArkBlueProperty s_ArkBlueProperty;
	float m_Blue;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetTime(float arg0);
	const float &GetTime() const;
	void SetRed(float arg0);
	const float &GetRed() const;
	void SetGreen(float arg0);
	const float &GetGreen() const;
	void SetBlue(float arg0);
	const float &GetBlue() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10771D0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1077460);
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationKeysArray : public ArkReflectedObject // Id=8014268 Size=24
{
public:
	class ArkKeysProperty : public ArkProperty // Id=8014269 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationKeysArray::ArkKeysProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationKeysArray::ArkKeysProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073760);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimationKeysArray::ArkKeysProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimationKeysArray::ArkKeysProperty const *const _this, ArkReflectedObject *_pObject)>(0x1073510);
	};

	static ArkMaterialAnimationKeysArray::ArkKeysProperty s_ArkKeysProperty;
	std::vector<ArkMaterialAnimationKey> m_Keys;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<ArkMaterialAnimationKey> &GetKeys();
	std::vector<ArkMaterialAnimationKey> const &GetKeys() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationSubMaterialData : public ArkReflectedObject // Id=801424E Size=200
{
public:
	class ArkSubMaterialSlotProperty : public ArkProperty // Id=801424F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty s_ArkSubMaterialSlotProperty;
	int m_SubMaterialSlot;
	
	class ArkDiffuseProperty : public ArkProperty // Id=8014250 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty s_ArkDiffuseProperty;
	ArkMaterialAnimationRgbKeysArray m_Diffuse;
	
	class ArkSpecularProperty : public ArkProperty // Id=8014265 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkSpecularProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkSpecularProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
	};

	static ArkMaterialAnimationSubMaterialData::ArkSpecularProperty s_ArkSpecularProperty;
	ArkMaterialAnimationRgbKeysArray m_Specular;
	
	class ArkEmissiveProperty : public ArkProperty // Id=8014266 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10735A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12F3810);
	};

	static ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty s_ArkEmissiveProperty;
	ArkMaterialAnimationRgbKeysArray m_Emissive;
	
	class ArkOpacityProperty : public ArkProperty // Id=8014267 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkOpacityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10735E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkOpacityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x12FBDE0);
	};

	static ArkMaterialAnimationSubMaterialData::ArkOpacityProperty s_ArkOpacityProperty;
	ArkMaterialAnimationKeysArray m_Opacity;
	
	class ArkSmoothnessProperty : public ArkProperty // Id=801427A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty const *const _this, ArkReflectedObject *const _pObject)>(0x13D4D20);
	};

	static ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty s_ArkSmoothnessProperty;
	ArkMaterialAnimationKeysArray m_Smoothness;
	
	class ArkAlphaTestProperty : public ArkProperty // Id=801427B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10617E0);
	};

	static ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty s_ArkAlphaTestProperty;
	ArkMaterialAnimationKeysArray m_AlphaTest;
	
	class ArkAmbientProperty : public ArkProperty // Id=801427C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkAmbientProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10736A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkAmbientProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10736E0);
	};

	static ArkMaterialAnimationSubMaterialData::ArkAmbientProperty s_ArkAmbientProperty;
	ArkMaterialAnimationKeysArray m_Ambient;
	
	class ArkEmissiveIntensityProperty : public ArkProperty // Id=801427D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10736F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073730);
	};

	static ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty s_ArkEmissiveIntensityProperty;
	ArkMaterialAnimationKeysArray m_EmissiveIntensity;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetSubMaterialSlot(int arg0);
	const int &GetSubMaterialSlot() const;
	void SetDiffuse(ArkMaterialAnimationRgbKeysArray arg0);
	ArkMaterialAnimationRgbKeysArray const &GetDiffuse() const;
	void SetSpecular(ArkMaterialAnimationRgbKeysArray arg0);
	ArkMaterialAnimationRgbKeysArray const &GetSpecular() const;
	void SetEmissive(ArkMaterialAnimationRgbKeysArray arg0);
	ArkMaterialAnimationRgbKeysArray const &GetEmissive() const;
	void SetOpacity(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const &GetOpacity() const;
	void SetSmoothness(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const &GetSmoothness() const;
	void SetAlphaTest(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const &GetAlphaTest() const;
	void SetAmbient(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const &GetAmbient() const;
	void SetEmissiveIntensity(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const &GetEmissiveIntensity() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1077200);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1077500);
};

// Header: Exact
// Prey/Ark/ArkMaterialAnimations.h
class ArkMaterialAnimations : public ArkReflectedLibrary // Id=8016AB4 Size=32
{
public:
	class ArkAnimationsProperty : public ArkProperty // Id=8016AB5 Size=32
	{
	public:
		ArkAnimationsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimations::ArkAnimationsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimations::ArkAnimationsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073240);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimations::ArkAnimationsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimations::ArkAnimationsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1073280);
	};

	static ArkMaterialAnimations::ArkAnimationsProperty s_ArkAnimationsProperty;
	std::vector<ArkMaterialAnimation> m_Animations;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkMaterialAnimation const *GetMaterialAnimationById(const uint64_t _materialAnimationID) const { return FGetMaterialAnimationById(this,_materialAnimationID); }
	
#if 0
	std::vector<ArkMaterialAnimation> &GetAnimations();
	std::vector<ArkMaterialAnimation> const &GetAnimations() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10772C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10775A0);
	static inline auto FInit = PreyFunction<bool(ArkMaterialAnimations *const _this)>(0x10776C0);
	static inline auto FGetMaterialAnimationById = PreyFunction<ArkMaterialAnimation const *(ArkMaterialAnimations const *const _this, const uint64_t _materialAnimationID)>(0x1077690);
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkAbilityRow : public ArkReflectedObject // Id=80193B4 Size=24
{
public:
	class ArkAbilitiesProperty : public ArkProperty // Id=80193B5 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkAbilityRow::ArkAbilitiesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15A4050);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkAbilityRow::ArkAbilitiesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1610DD0);
		static inline auto FIsArray = PreyFunction<bool(ArkAbilityRow::ArkAbilitiesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkAbilityRow::ArkAbilitiesProperty const *const _this, ArkReflectedObject *_pObject)>(0x1073510);
	};

	static ArkAbilityRow::ArkAbilitiesProperty s_ArkAbilitiesProperty;
	std::vector<unsigned __int64> m_Abilities;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	
#if 0
	static ArkClass *GetClass();
	std::vector<unsigned __int64> &GetAbilities();
	std::vector<unsigned __int64> const &GetAbilities() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x16140D0);
};

