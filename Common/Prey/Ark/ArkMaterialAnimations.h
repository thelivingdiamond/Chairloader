// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/GameDll/ark/player/psipower/arkpsipowerliftproperties.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkStubs.h>
class IArkValueBase;
#endif
class ArkMaterialAnimationKey : public ArkReflectedObject // Id=801426D Size=8
{
public:
	class ArkTimeProperty : public ArkProperty // Id=801426E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationKey::ArkTimeProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationKey::ArkTimeProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationKey::ArkTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationKey::ArkTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationKey::ArkTimeProperty s_ArkTimeProperty;
#else
	static inline auto s_ArkTimeProperty = PreyGlobal<ArkMaterialAnimationKey::ArkTimeProperty>(0x2D263D0);
#endif
	float m_Time;

	class ArkValueProperty : public ArkProperty // Id=801426F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationKey::ArkValueProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationKey::ArkValueProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationKey::ArkValueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationKey::ArkValueProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationKey::ArkValueProperty s_ArkValueProperty;
#else
	static inline auto s_ArkValueProperty = PreyGlobal<ArkMaterialAnimationKey::ArkValueProperty>(0x2D263F0);
#endif
	float m_Value;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetTime(float arg0);
	const float& GetTime() const;
	void SetValue(float arg0);
	const float& GetValue() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x12F6430);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10773C0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x165E150);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109D110);
#endif
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationKeysArray : public ArkReflectedObject // Id=8014268 Size=24
{
public:
	class ArkKeysProperty : public ArkProperty // Id=8014269 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationKeysArray::ArkKeysProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1073740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationKeysArray::ArkKeysProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1073760);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimationKeysArray::ArkKeysProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimationKeysArray::ArkKeysProperty const* const _this, ArkReflectedObject* _pObject)>(0x1073510);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationKeysArray::ArkKeysProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10990E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationKeysArray::ArkKeysProperty* const _this, ArkReflectedObject* const _pObject)>(0x1099100);
		static inline auto FIsArray = PreyFunction<bool(const ArkMaterialAnimationKeysArray::ArkKeysProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkMaterialAnimationKeysArray::ArkKeysProperty* const _this, ArkReflectedObject* _pObject)>(0x1075A70);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationKeysArray::ArkKeysProperty s_ArkKeysProperty;
#else
	static inline auto s_ArkKeysProperty = PreyGlobal<ArkMaterialAnimationKeysArray::ArkKeysProperty>(0x2D26490);
#endif
	std::vector<ArkMaterialAnimationKey> m_Keys;

	static ArkReflectedObject* Create() { return FCreate(); }

#if 0
	static ArkClass* GetClass();
	std::vector<ArkMaterialAnimationKey>& GetKeys();
	std::vector<ArkMaterialAnimationKey> const& GetKeys() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16140D0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
#endif
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationRgbKey : public ArkReflectedObject // Id=8014256 Size=16
{
public:
	class ArkTimeProperty : public ArkProperty // Id=8014257 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkTimeProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationRgbKey::ArkTimeProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationRgbKey::ArkTimeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationRgbKey::ArkTimeProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationRgbKey::ArkTimeProperty s_ArkTimeProperty;
#else
	static inline auto s_ArkTimeProperty = PreyGlobal<ArkMaterialAnimationRgbKey::ArkTimeProperty>(0x2D26410);
#endif
	float m_Time;

	class ArkRedProperty : public ArkProperty // Id=8014258 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkRedProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1328E10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationRgbKey::ArkRedProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328410);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationRgbKey::ArkRedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationRgbKey::ArkRedProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationRgbKey::ArkRedProperty s_ArkRedProperty;
#else
	static inline auto s_ArkRedProperty = PreyGlobal<ArkMaterialAnimationRgbKey::ArkRedProperty>(0x2D26430);
#endif
	float m_Red;

	class ArkGreenProperty : public ArkProperty // Id=8014259 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkGreenProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1328E20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationRgbKey::ArkGreenProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationRgbKey::ArkGreenProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationRgbKey::ArkGreenProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationRgbKey::ArkGreenProperty s_ArkGreenProperty;
#else
	static inline auto s_ArkGreenProperty = PreyGlobal<ArkMaterialAnimationRgbKey::ArkGreenProperty>(0x2D26450);
#endif
	float m_Green;

	class ArkBlueProperty : public ArkProperty // Id=801425A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKey::ArkBlueProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1328670);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationRgbKey::ArkBlueProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1064F90);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationRgbKey::ArkBlueProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationRgbKey::ArkBlueProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035F0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationRgbKey::ArkBlueProperty s_ArkBlueProperty;
#else
	static inline auto s_ArkBlueProperty = PreyGlobal<ArkMaterialAnimationRgbKey::ArkBlueProperty>(0x2D26470);
#endif
	float m_Blue;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetTime(float arg0);
	const float& GetTime() const;
	void SetRed(float arg0);
	const float& GetRed() const;
	void SetGreen(float arg0);
	const float& GetGreen() const;
	void SetBlue(float arg0);
	const float& GetBlue() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10771D0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1077460);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109CF20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109D1B0);
#endif
};

// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationRgbKeysArray : public ArkReflectedObject // Id=8014251 Size=24
{
public:
	class ArkRgbKeysProperty : public ArkProperty // Id=8014252 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10734D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10734F0);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const* const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty const* const _this, ArkReflectedObject* _pObject)>(0x1073510);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1099480);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty* const _this, ArkReflectedObject* const _pObject)>(0x10994A0);
		static inline auto FIsArray = PreyFunction<bool(const ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty* const _this, ArkReflectedObject* _pObject)>(0x1075A70);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty s_ArkRgbKeysProperty;
#else
	static inline auto s_ArkRgbKeysProperty = PreyGlobal<ArkMaterialAnimationRgbKeysArray::ArkRgbKeysProperty>(0x2D264B0);
#endif
	std::vector<ArkMaterialAnimationRgbKey> m_RgbKeys;

	static ArkReflectedObject* Create() { return FCreate(); }
#ifndef MOONCRASH
	ArkMaterialAnimationRgbKeysArray& operator=(ArkMaterialAnimationRgbKeysArray const& __that) { return FoperatorEqOv1(this, __that); }
#endif

#if 0
	static ArkClass* GetClass();
	std::vector<ArkMaterialAnimationRgbKey>& GetRgbKeys();
	std::vector<ArkMaterialAnimationRgbKey> const& GetRgbKeys() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x16140D0);
	static inline auto FoperatorEqOv1 = PreyFunction<ArkMaterialAnimationRgbKeysArray& (ArkMaterialAnimationRgbKeysArray* const _this, ArkMaterialAnimationRgbKeysArray const& __that)>(0x39DB00);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
#endif
};


// Header: Exact
// Prey/Ark/arkmaterialanimations.h
class ArkMaterialAnimationSubMaterialData : public ArkReflectedObject // Id=801424E Size=200
{
public:
	class ArkSubMaterialSlotProperty : public ArkProperty // Id=801424F Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x13D4DC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty const* const _this, ArkReflectedObject* const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty s_ArkSubMaterialSlotProperty;
#else
	static inline auto s_ArkSubMaterialSlotProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkSubMaterialSlotProperty>(0x2D264D0);
#endif
	int m_SubMaterialSlot;

	class ArkDiffuseProperty : public ArkProperty // Id=8014250 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1073520);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1098EE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty s_ArkDiffuseProperty;
#else
	static inline auto s_ArkDiffuseProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkDiffuseProperty>(0x2D264F0);
#endif
	ArkMaterialAnimationRgbKeysArray m_Diffuse;

	class ArkSpecularProperty : public ArkProperty // Id=8014265 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkSpecularProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1073560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkSpecularProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkSpecularProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1098F20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkSpecularProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkSpecularProperty s_ArkSpecularProperty;
#else
	static inline auto s_ArkSpecularProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkSpecularProperty>(0x2D26510);
#endif
	ArkMaterialAnimationRgbKeysArray m_Specular;

	class ArkEmissiveProperty : public ArkProperty // Id=8014266 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10735A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty const* const _this, ArkReflectedObject* const _pObject)>(0x12F3810);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1098F60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty* const _this, ArkReflectedObject* const _pObject)>(0x10980B0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty s_ArkEmissiveProperty;
#else
	static inline auto s_ArkEmissiveProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkEmissiveProperty>(0x2D26530);
#endif
	ArkMaterialAnimationRgbKeysArray m_Emissive;

	class ArkOpacityProperty : public ArkProperty // Id=8014267 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkOpacityProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10735E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkOpacityProperty const* const _this, ArkReflectedObject* const _pObject)>(0x12FBDE0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkOpacityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1098FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkOpacityProperty* const _this, ArkReflectedObject* const _pObject)>(0x10A06D0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkOpacityProperty s_ArkOpacityProperty;
#else
	static inline auto s_ArkOpacityProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkOpacityProperty>(0x2D26550);
#endif
	ArkMaterialAnimationKeysArray m_Opacity;

	class ArkSmoothnessProperty : public ArkProperty // Id=801427A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1073620);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty const* const _this, ArkReflectedObject* const _pObject)>(0x13D4D20);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1098FE0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty* const _this, ArkReflectedObject* const _pObject)>(0x10B7840);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty s_ArkSmoothnessProperty;
#else
	static inline auto s_ArkSmoothnessProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkSmoothnessProperty>(0x2D26570);
#endif
	ArkMaterialAnimationKeysArray m_Smoothness;

	class ArkAlphaTestProperty : public ArkProperty // Id=801427B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x1073660);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10617E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1099020);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty* const _this, ArkReflectedObject* const _pObject)>(0x16B7F00);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty s_ArkAlphaTestProperty;
#else
	static inline auto s_ArkAlphaTestProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkAlphaTestProperty>(0x2D26590);
#endif
	ArkMaterialAnimationKeysArray m_AlphaTest;

	class ArkAmbientProperty : public ArkProperty // Id=801427C Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkAmbientProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10736A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkAmbientProperty const* const _this, ArkReflectedObject* const _pObject)>(0x10736E0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkAmbientProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1099060);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkAmbientProperty* const _this, ArkReflectedObject* const _pObject)>(0x13BF6B0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkAmbientProperty s_ArkAmbientProperty;
#else
	static inline auto s_ArkAmbientProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkAmbientProperty>(0x2D265B0);
#endif
	ArkMaterialAnimationKeysArray m_Ambient;

	class ArkEmissiveIntensityProperty : public ArkProperty // Id=801427D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, IArkValueBase const* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty const* const _this, ArkReflectedObject* const _pObject, IArkValueBase const* _v)>(0x10736F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty const* const _this, ArkReflectedObject* const _pObject)>(0x1073730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10990A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty* const _this, ArkReflectedObject* const _pObject)>(0x14E1000);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty s_ArkEmissiveIntensityProperty;
#else
	static inline auto s_ArkEmissiveIntensityProperty = PreyGlobal<ArkMaterialAnimationSubMaterialData::ArkEmissiveIntensityProperty>(0x2D265D0);
#endif
	ArkMaterialAnimationKeysArray m_EmissiveIntensity;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetSubMaterialSlot(int arg0);
	const int& GetSubMaterialSlot() const;
	void SetDiffuse(ArkMaterialAnimationRgbKeysArray arg0);
	ArkMaterialAnimationRgbKeysArray const& GetDiffuse() const;
	void SetSpecular(ArkMaterialAnimationRgbKeysArray arg0);
	ArkMaterialAnimationRgbKeysArray const& GetSpecular() const;
	void SetEmissive(ArkMaterialAnimationRgbKeysArray arg0);
	ArkMaterialAnimationRgbKeysArray const& GetEmissive() const;
	void SetOpacity(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const& GetOpacity() const;
	void SetSmoothness(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const& GetSmoothness() const;
	void SetAlphaTest(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const& GetAlphaTest() const;
	void SetAmbient(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const& GetAmbient() const;
	void SetEmissiveIntensity(ArkMaterialAnimationKeysArray arg0);
	ArkMaterialAnimationKeysArray const& GetEmissiveIntensity() const;
#endif

#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077200);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1077500);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109CF50);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109D250);
#endif
};

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
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkIdProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkIdProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimation::ArkIdProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimation::ArkIdProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimation::ArkIdProperty s_ArkIdProperty;
#else
	static inline auto s_ArkIdProperty = PreyGlobal<ArkMaterialAnimation::ArkIdProperty>(0x2D265F0);
#endif
	uint64_t m_Id;
	
	class ArkNameProperty : public ArkProperty // Id=8014246 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimation::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimation::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkMaterialAnimation::ArkNameProperty>(0x2D26610);
#endif
	string m_Name;
	
	class ArkAttachmentNameProperty : public ArkProperty // Id=8014247 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkAttachmentNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkAttachmentNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimation::ArkAttachmentNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimation::ArkAttachmentNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimation::ArkAttachmentNameProperty s_ArkAttachmentNameProperty;
#else
	static inline auto s_ArkAttachmentNameProperty = PreyGlobal<ArkMaterialAnimation::ArkAttachmentNameProperty>(0x2D26630);
#endif
	string m_AttachmentName;
	
	class ArkMeshSlotProperty : public ArkProperty // Id=8014248 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkMeshSlotProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkMeshSlotProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimation::ArkMeshSlotProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimation::ArkMeshSlotProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimation::ArkMeshSlotProperty s_ArkMeshSlotProperty;
#else
	static inline auto s_ArkMeshSlotProperty = PreyGlobal<ArkMaterialAnimation::ArkMeshSlotProperty>(0x2D26650);
#endif
	int m_MeshSlot;
	
	class ArkMaterialReferenceProperty : public ArkProperty // Id=8014249 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkMaterialReferenceProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x15AE4C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkMaterialReferenceProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1088980);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimation::ArkMaterialReferenceProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C600);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimation::ArkMaterialReferenceProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimation::ArkMaterialReferenceProperty s_ArkMaterialReferenceProperty;
#else
	static inline auto s_ArkMaterialReferenceProperty = PreyGlobal<ArkMaterialAnimation::ArkMaterialReferenceProperty>(0x2D26670);
#endif
	string m_MaterialReference;
	
	class ArkSubMaterialsProperty : public ArkProperty // Id=801424A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073350);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073470);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimation::ArkSubMaterialsProperty const *const _this, ArkReflectedObject *_pObject)>(0x10734A0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimation::ArkSubMaterialsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1099300);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimation::ArkSubMaterialsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1099420);
		static inline auto FIsArray = PreyFunction<bool(const ArkMaterialAnimation::ArkSubMaterialsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkMaterialAnimation::ArkSubMaterialsProperty* const _this, ArkReflectedObject* _pObject)>(0x1099450);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimation::ArkSubMaterialsProperty s_ArkSubMaterialsProperty;
#else
	static inline auto s_ArkSubMaterialsProperty = PreyGlobal<ArkMaterialAnimation::ArkSubMaterialsProperty>(0x2D26690);
#endif
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
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1077160);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1077320);
	static inline auto FAddRgbKeyframesToQueue = PreyFunction<void(ArkMaterialAnimation *const _this, ArkMaterialAnimationRgbKeysArray const &_keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel)>(0x1076EE0);
	static inline auto FAddKeyframesToQueue = PreyFunction<void(ArkMaterialAnimation *const _this, ArkMaterialAnimationKeysArray const &_keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel)>(0x1076CA0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109CEB0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109D070);
	static inline auto FAddRgbKeyframesToQueue = PreyFunction<void(ArkMaterialAnimation* const _this, const ArkMaterialAnimationRgbKeysArray& _keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel)>(0x109CC30);
	static inline auto FAddKeyframesToQueue = PreyFunction<void(ArkMaterialAnimation* const _this, const ArkMaterialAnimationKeysArray& _keysArray, int _subMaterialSlot, ArkMaterialAnimationChannel _channel)>(0x109C9F0);
#endif
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
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkMaterialAnimations::ArkAnimationsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1073110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkMaterialAnimations::ArkAnimationsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1073240);
		static inline auto FIsArray = PreyFunction<bool(ArkMaterialAnimations::ArkAnimationsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkMaterialAnimations::ArkAnimationsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1073280);
#else
		static inline auto FArkAnimationsPropertyOv2 = PreyFunction<void(ArkMaterialAnimations::ArkAnimationsProperty* const _this)>(0x109C1D0);
		static inline auto FSetValue = PreyFunction<void(const ArkMaterialAnimations::ArkAnimationsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1099120);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkMaterialAnimations::ArkAnimationsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1099250);
		static inline auto FIsArray = PreyFunction<bool(const ArkMaterialAnimations::ArkAnimationsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkMaterialAnimations::ArkAnimationsProperty* const _this, ArkReflectedObject* _pObject)>(0x1099290);
#endif
	};

#ifndef MOONCRASH
	static ArkMaterialAnimations::ArkAnimationsProperty s_ArkAnimationsProperty;
#else
	static inline auto s_ArkAnimationsProperty = PreyGlobal<ArkMaterialAnimations::ArkAnimationsProperty>(0x2D266B0);
#endif
	std::vector<ArkMaterialAnimation> m_Animations;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkMaterialAnimation const *GetMaterialAnimationById(const uint64_t _materialAnimationID) const { return FGetMaterialAnimationById(this,_materialAnimationID); }
	virtual ~ArkMaterialAnimations();
	
#if 0
	std::vector<ArkMaterialAnimation> &GetAnimations();
	std::vector<ArkMaterialAnimation> const &GetAnimations() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10772C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10775A0);
	static inline auto FInit = PreyFunction<bool(ArkMaterialAnimations *const _this)>(0x10776C0);
	static inline auto FGetMaterialAnimationById = PreyFunction<ArkMaterialAnimation const *(ArkMaterialAnimations const *const _this, const uint64_t _materialAnimationID)>(0x1077690);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x109D010);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x109D2F0);
	static inline auto FInit = PreyFunction<bool(ArkMaterialAnimations* const _this)>(0x109D410);
	static inline auto FGetMaterialAnimationById = PreyFunction<const ArkMaterialAnimation* (const ArkMaterialAnimations* const _this, const uint64_t _materialAnimationID)>(0x109D3E0);
#endif
};
