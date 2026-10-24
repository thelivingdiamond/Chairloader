// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkEmotion.h
#ifdef MOONCRASH
#include <Prey/ArkCommon/reflection/ArkProperty.h>
class IArkValueBase;
#endif
class ArkEmotion : public ArkReflectedObject // Id=800D7AE Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=800D7AF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
#endif
	};

#ifndef MOONCRASH
	static ArkEmotion::ArkIDProperty s_ArkIDProperty;
#else
	static inline auto s_ArkIDProperty = PreyGlobal<ArkEmotion::ArkIDProperty>(0x2D23500);
#endif
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=800D7B0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
#endif
	};

#ifndef MOONCRASH
	static ArkEmotion::ArkNameProperty s_ArkNameProperty;
#else
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEmotion::ArkNameProperty>(0x2D23520);
#endif
	string m_Name;
	
	class ArkAnimationProperty : public ArkProperty // Id=800D7B1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkAnimationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkAnimationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkAnimationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkAnimationProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
#endif
	};

#ifndef MOONCRASH
	static ArkEmotion::ArkAnimationProperty s_ArkAnimationProperty;
#else
	static inline auto s_ArkAnimationProperty = PreyGlobal<ArkEmotion::ArkAnimationProperty>(0x2D23540);
#endif
	string m_Animation;
	
	class ArkBlendInProperty : public ArkProperty // Id=800D7B2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkBlendInProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkBlendInProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkBlendInProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkBlendInProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
#endif
	};

#ifndef MOONCRASH
	static ArkEmotion::ArkBlendInProperty s_ArkBlendInProperty;
#else
	static inline auto s_ArkBlendInProperty = PreyGlobal<ArkEmotion::ArkBlendInProperty>(0x2D23560);
#endif
	float m_BlendIn;
	
	class ArkBlendOutProperty : public ArkProperty // Id=800D7B3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkBlendOutProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkBlendOutProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
#else
		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkBlendOutProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkBlendOutProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
#endif
	};

#ifndef MOONCRASH
	static ArkEmotion::ArkBlendOutProperty s_ArkBlendOutProperty;
#else
	static inline auto s_ArkBlendOutProperty = PreyGlobal<ArkEmotion::ArkBlendOutProperty>(0x2D23580);
#endif
	float m_BlendOut;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetAnimation(string arg0);
	string const &GetAnimation() const;
	void SetBlendIn(float arg0);
	const float &GetBlendIn() const;
	void SetBlendOut(float arg0);
	const float &GetBlendOut() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1063160);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1063230);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1086060);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1086130);
#endif
};

// Header: Exact
// Prey/Ark/arkemotion.h
class ArkEmotions : public ArkReflectedLibrary // Id=800D7C1 Size=32
{
public:
	class ArkEmotionsProperty : public ArkProperty // Id=800D7C2 Size=32
	{
	public:
		ArkEmotionsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
#ifndef MOONCRASH
		static inline auto FSetValue = PreyFunction<void(ArkEmotions::ArkEmotionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotions::ArkEmotionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1062A90);
		static inline auto FIsArray = PreyFunction<bool(ArkEmotions::ArkEmotionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEmotions::ArkEmotionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1062AD0);
#else
		static inline auto FArkEmotionsPropertyOv2 = PreyFunction<void(ArkEmotions::ArkEmotionsProperty* const _this)>(0x1085DA0);
		static inline auto FSetValue = PreyFunction<void(const ArkEmotions::ArkEmotionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085880);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotions::ArkEmotionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1085940);
		static inline auto FIsArray = PreyFunction<bool(const ArkEmotions::ArkEmotionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEmotions::ArkEmotionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1085980);
#endif
	};

#ifndef MOONCRASH
	static ArkEmotions::ArkEmotionsProperty s_ArkEmotionsProperty;
#else
	static inline auto s_ArkEmotionsProperty = PreyGlobal<ArkEmotions::ArkEmotionsProperty>(0x2D235A0);
#endif
	std::vector<ArkEmotion> m_Emotions;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	ArkEmotion const *Find(const uint64_t _id) const { return FFind(this,_id); }
	virtual ~ArkEmotions();
	
#if 0
	std::vector<ArkEmotion> &GetEmotions();
	std::vector<ArkEmotion> const &GetEmotions() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10631A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10632D0);
	static inline auto FInit = PreyFunction<bool(ArkEmotions *const _this)>(0x10633C0);
	static inline auto FFind = PreyFunction<ArkEmotion const *(ArkEmotions const *const _this, const uint64_t _id)>(0x1063200);
#else
	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10860A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10861D0);
	static inline auto FInit = PreyFunction<bool(ArkEmotions* const _this)>(0x10862C0);
	static inline auto FFind = PreyFunction<const ArkEmotion* (const ArkEmotions* const _this, const uint64_t _id)>(0x1086100);
#endif
};
