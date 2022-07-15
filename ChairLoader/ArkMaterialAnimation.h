#pragma once
#include "Prey/CryCore/StdAfx.h"
enum class ArkMaterialAnimationChannel : int8_t
{
	none = 0,
};
enum class EMaterialParamFloat : int32_t
{
	none = 0,
	other = 3,
	telescope = 2,
	worldUI = 1
};
enum class EMaterialParamVec3 : int32_t
{
	none = 0,
	other = 3,
	telescope = 2,
	worldUI = 1
};
enum class enumArkMaterialAnimationType : int32_t
{
	none = 0,
};

class EnumClassHash {
public:
	char a;
};

class ArkMaterialAnimationRgbKey {
	float m_Time;
	float m_Red;
	float m_Green;
	float m_Blue;
};

class ArkMaterialAnimationRgbKeysArray {
public:
	std::vector<ArkMaterialAnimationRgbKey> m_RgbKeys;

};
class ArkMaterialAnimationKey {
public:
	float m_Time;
	float m_Value;
};
class ArkMaterialAnimationKeysArray {
public:
	std::vector<ArkMaterialAnimationKey> m_Keys;
};
class ArkMaterialAnimationSubMaterialData {
public:
	uint32_t m_SubMaterialSlot;
	char pad1[4];
	ArkMaterialAnimationRgbKeysArray m_Diffuse;
	ArkMaterialAnimationRgbKeysArray m_Specular;
	ArkMaterialAnimationRgbKeysArray m_Emissive;
	ArkMaterialAnimationKeysArray m_Opacity;
	ArkMaterialAnimationKeysArray m_Smoothness;
	ArkMaterialAnimationKeysArray m_AlphaTest;
	ArkMaterialAnimationKeysArray m_Ambient;
	ArkMaterialAnimationKeysArray m_EmissiveIntensity;
};
class ArkMaterialAnimationKeyframe {
public:
	uint32_t m_subMaterialSlot;
	ArkMaterialAnimationChannel m_channel;
	float m_keyTime;
	float m_timeToNextKey;
	float m_floatValue;
	Vec3 m_vectorValue;
	bool m_bIsFloat;
	char pad1[3];
};
class ArkMaterialAnimation {
public:
	unsigned __int64 m_Id;
	CryStringT<char> m_Name;
	CryStringT<char> m_AttachmentName;
	uint32_t m_MeshSlot;
	CryStringT<char> m_MaterialReference;
	std::vector<ArkMaterialAnimationSubMaterialData> m_SubMaterials;
	std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
};

class MaterialParameterRamp {
public:
	IMaterial* m_PMaterial;
	EMaterialParamFloat m_paramFloat;
	EMaterialParamVec3 m_paramVec3;
	char* m_paramName;
	float m_initialFloatValue;
	float m_finalFloatValue;
	Vec3 m_initialvectorValue;
	Vec3 m_finalvectorValue;
	float m_currentTime;
	float m_finalTime;
	bool m_bIsFloat;
};

class SAttachmentMaterials {
public:
	int32_t meshSlot;
	CryStringT<char> attachmentName;
	IMaterial* pMaterial;
	IMaterial* pOriginalMaterial;
};
class ActiveAnimationData {
public:
	std::vector<ArkMaterialAnimationKeyframe> m_keyframeQueue;
};
class ArkMaterialAnimationManager
{
public:
	void* m_pEntity; //0x0000
	std::vector<SAttachmentMaterials> m_attachmentMaterials; //0x0008
	void* m_pOneOffMaterialAnimation; //0x0020
	ActiveAnimationData m_oneOffAnimationData; //0x0028
	std::unordered_map<enumArkMaterialAnimationType, const ArkMaterialAnimation*, EnumClassHash, std::equal_to<enumArkMaterialAnimationType>> m_animationsByType; //0x0040
	ActiveAnimationData m_activeAnimationsByType[18]; //0x0080
	std::vector<MaterialParameterRamp> m_materialParameterRamps; //0x0230
}; //Size: 0x0248
