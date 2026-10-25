// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkgamenoise.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
class ArkGameNoiseLoudness;
class ArkGameNoiseType;
class ArkGameNoises;
class ArkInputAction;
#endif
class ArkGameNoiseLoudness : public ArkReflectedObject // Id=800200C Size=24
{
public:
	class ArkIDProperty : public ArkProperty // Id=8002075 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseLoudness::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseLoudness::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoiseLoudness::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoiseLoudness::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoiseLoudness::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkGameNoiseLoudness::ArkIDProperty>(0x25DFC10);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8002076 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseLoudness::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseLoudness::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoiseLoudness::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoiseLoudness::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoiseLoudness::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkGameNoiseLoudness::ArkNameProperty>(0x25DFC30);
#endif
	string m_Name;
	
	class ArkRadiusProperty : public ArkProperty // Id=8002077 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseLoudness::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseLoudness::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoiseLoudness::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x157DA30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoiseLoudness::ArkRadiusProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoiseLoudness::ArkRadiusProperty s_ArkRadiusProperty;
#else
	static inline auto s_ArkRadiusProperty = PreyGlobal<ArkGameNoiseLoudness::ArkRadiusProperty>(0x25DFC50);
#endif
	float m_Radius;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetRadius(float arg0);
	const float &GetRadius() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A0740);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A0920);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x2B8C20);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x2B8DD0);
#endif
};

// Header: Exact
// Prey/Ark/arkgamenoise.h
class ArkGameNoiseType : public ArkReflectedObject // Id=8004439 Size=16
{
public:
	class ArkIDProperty : public ArkProperty // Id=800443A Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseType::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseType::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoiseType::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoiseType::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoiseType::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkGameNoiseType::ArkIDProperty>(0x25DFBD0);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=800443B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseType::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseType::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoiseType::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoiseType::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoiseType::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkGameNoiseType::ArkNameProperty>(0x25DFBF0);
#endif
	string m_Name;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A0780);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A09C0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D1A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x2B8E70);
#endif
};

// Header: Exact
// Prey/Ark/arkgamenoise.h
class ArkGameNoises : public ArkReflectedObject // Id=800447C Size=48
{
public:
	class ArkTypesProperty : public ArkProperty // Id=800447D Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoises::ArkTypesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x29F730);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoises::ArkTypesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x29F790);
		static inline auto FIsArray = PreyFunction<bool(ArkGameNoises::ArkTypesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameNoises::ArkTypesProperty const *const _this, ArkReflectedObject *_pObject)>(0x29F7B0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoises::ArkTypesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x2B7B30);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoises::ArkTypesProperty* const _this, ArkReflectedObject* const _pObject)>(0x2B7B90);
		static inline auto FIsArray = PreyFunction<bool(const ArkGameNoises::ArkTypesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkGameNoises::ArkTypesProperty* const _this, ArkReflectedObject* _pObject)>(0x2B7BB0);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoises::ArkTypesProperty s_ArkTypesProperty;
#else
	static inline auto s_ArkTypesProperty = PreyGlobal<ArkGameNoises::ArkTypesProperty>(0x25DFC70);
#endif
	std::vector<ArkGameNoiseType> m_Types;
	
	class ArkLoudnessesProperty : public ArkProperty // Id=800447E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkGameNoises::ArkLoudnessesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x29F630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoises::ArkLoudnessesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x29F6A0);
		static inline auto FIsArray = PreyFunction<bool(ArkGameNoises::ArkLoudnessesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameNoises::ArkLoudnessesProperty const *const _this, ArkReflectedObject *_pObject)>(0x29F6C0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkGameNoises::ArkLoudnessesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x2B7C20);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkGameNoises::ArkLoudnessesProperty* const _this, ArkReflectedObject* const _pObject)>(0x2B7C90);
		static inline auto FIsArray = PreyFunction<bool(const ArkGameNoises::ArkLoudnessesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkGameNoises::ArkLoudnessesProperty* const _this, ArkReflectedObject* _pObject)>(0x2B7CB0);
#endif
	};

#ifndef MOONCRASH
	static ArkGameNoises::ArkLoudnessesProperty s_ArkLoudnessesProperty;
#else
	static inline auto s_ArkLoudnessesProperty = PreyGlobal<ArkGameNoises::ArkLoudnessesProperty>(0x25DFC90);
#endif
	std::vector<ArkGameNoiseLoudness> m_Loudnesses;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	bool Init() { return FInit(this); }
	ArkGameNoiseType const *FindType(const uint64_t _id) const { return FFindTypeOv1(this,_id); }
	ArkGameNoiseType const *FindType(const char *const _name) const { return FFindTypeOv0(this,_name); }
	ArkGameNoiseLoudness const *FindLoudness(const uint64_t _id) const { return FFindLoudnessOv1(this,_id); }
	ArkGameNoiseLoudness const *FindLoudness(const char *const _name) const { return FFindLoudnessOv0(this,_name); }
	
#if 0
	std::vector<ArkGameNoiseType> &GetTypes();
	std::vector<ArkGameNoiseType> const &GetTypes() const;
	std::vector<ArkGameNoiseLoudness> &GetLoudnesses();
	std::vector<ArkGameNoiseLoudness> const &GetLoudnesses() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A07B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A0A60);
	static inline auto FInit = PreyFunction<bool(ArkGameNoises *const _this)>(0x2A0D60);
	static inline auto FFindTypeOv1 = PreyFunction<ArkGameNoiseType const *(ArkGameNoises const *const _this, const uint64_t _id)>(0x2A08F0);
	static inline auto FFindTypeOv0 = PreyFunction<ArkGameNoiseType const *(ArkGameNoises const *const _this, const char *const _name)>(0x2A0890);
	static inline auto FFindLoudnessOv1 = PreyFunction<ArkGameNoiseLoudness const *(ArkGameNoises const *const _this, const uint64_t _id)>(0x2A0860);
	static inline auto FFindLoudnessOv0 = PreyFunction<ArkGameNoiseLoudness const *(ArkGameNoises const *const _this, const char *const _name)>(0x2A0800);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x2B8C60);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x2B8F10);
	static inline auto FInit = PreyFunction<bool(ArkGameNoises* const _this)>(0x2B9210);
	static inline auto FFindTypeOv1 = PreyFunction<const ArkGameNoiseType* (const ArkGameNoises* const _this, const uint64_t _id)>(0x2B8DA0);
	static inline auto FFindTypeOv0 = PreyFunction<const ArkGameNoiseType* (const ArkGameNoises* const _this, const char* const _name)>(0x2B8D40);
	static inline auto FFindLoudnessOv1 = PreyFunction<const ArkGameNoiseLoudness* (const ArkGameNoises* const _this, const uint64_t _id)>(0x2B8D10);
	static inline auto FFindLoudnessOv0 = PreyFunction<const ArkGameNoiseLoudness* (const ArkGameNoises* const _this, const char* const _name)>(0x2B8CB0);
#endif
};

// Header: Exact
// Prey/Ark/arkgamenoise.h
class ArkInputAction : public ArkReflectedObject // Id=80134A5 Size=16
{
public:
	class ArkActionProperty : public ArkProperty // Id=80134A6 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputAction::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputAction::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputAction::ArkActionProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1093030);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputAction::ArkActionProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkInputAction::ArkActionProperty s_ArkActionProperty;
#else
	static inline auto s_ArkActionProperty = PreyGlobal<ArkInputAction::ArkActionProperty>(0x2D80130);
#endif
	CCryName m_Action;
	
	class ArkActionMapProperty : public ArkProperty // Id=80134A7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkInputAction::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputAction::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkInputAction::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkInputAction::ArkActionMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkInputAction::ArkActionMapProperty s_ArkActionMapProperty;
#else
	static inline auto s_ArkActionMapProperty = PreyGlobal<ArkInputAction::ArkActionMapProperty>(0x2D80150);
#endif
	string m_ActionMap;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetAction(CCryName arg0);
	CCryName const &GetAction() const;
	void SetActionMap(string arg0);
	string const &GetActionMap() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A0780);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15FC7D0);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x171D1A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x171D2F0);
#endif
};
