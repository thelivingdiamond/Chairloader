// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>
#include <Prey/CryString/CryName.h>

class ArkClass;

// Header: Exact
// Prey/Ark/arkgamenoise.h
class ArkGameNoiseLoudness : public ArkReflectedObject // Id=800200C Size=24
{
public:
	class ArkIDProperty : public ArkProperty // Id=8002075 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseLoudness::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseLoudness::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkGameNoiseLoudness::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8002076 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseLoudness::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseLoudness::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkGameNoiseLoudness::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkRadiusProperty : public ArkProperty // Id=8002077 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseLoudness::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1064FA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseLoudness::ArkRadiusProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkGameNoiseLoudness::ArkRadiusProperty s_ArkRadiusProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A0740);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A0920);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseType::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseType::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkGameNoiseType::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=800443B Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoiseType::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoiseType::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkGameNoiseType::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A0780);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A09C0);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoises::ArkTypesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x29F730);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoises::ArkTypesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x29F790);
		static inline auto FIsArray = PreyFunction<bool(ArkGameNoises::ArkTypesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameNoises::ArkTypesProperty const *const _this, ArkReflectedObject *_pObject)>(0x29F7B0);
	};

	static ArkGameNoises::ArkTypesProperty s_ArkTypesProperty;
	std::vector<ArkGameNoiseType> m_Types;
	
	class ArkLoudnessesProperty : public ArkProperty // Id=800447E Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkGameNoises::ArkLoudnessesProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x29F630);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkGameNoises::ArkLoudnessesProperty const *const _this, ArkReflectedObject *const _pObject)>(0x29F6A0);
		static inline auto FIsArray = PreyFunction<bool(ArkGameNoises::ArkLoudnessesProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkGameNoises::ArkLoudnessesProperty const *const _this, ArkReflectedObject *_pObject)>(0x29F6C0);
	};

	static ArkGameNoises::ArkLoudnessesProperty s_ArkLoudnessesProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A07B0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x2A0A60);
	static inline auto FInit = PreyFunction<bool(ArkGameNoises *const _this)>(0x2A0D60);
	static inline auto FFindTypeOv1 = PreyFunction<ArkGameNoiseType const *(ArkGameNoises const *const _this, const uint64_t _id)>(0x2A08F0);
	static inline auto FFindTypeOv0 = PreyFunction<ArkGameNoiseType const *(ArkGameNoises const *const _this, const char *const _name)>(0x2A0890);
	static inline auto FFindLoudnessOv1 = PreyFunction<ArkGameNoiseLoudness const *(ArkGameNoises const *const _this, const uint64_t _id)>(0x2A0860);
	static inline auto FFindLoudnessOv0 = PreyFunction<ArkGameNoiseLoudness const *(ArkGameNoises const *const _this, const char *const _name)>(0x2A0800);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkInputAction::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106EF60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputAction::ArkActionProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkInputAction::ArkActionProperty s_ArkActionProperty;
	CCryName m_Action;
	
	class ArkActionMapProperty : public ArkProperty // Id=80134A7 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkInputAction::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkInputAction::ArkActionMapProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkInputAction::ArkActionMapProperty s_ArkActionMapProperty;
	string m_ActionMap;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetAction(CCryName arg0);
	CCryName const &GetAction() const;
	void SetActionMap(string arg0);
	string const &GetActionMap() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x2A0780);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x15FC7D0);
};

