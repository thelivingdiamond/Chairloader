// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkEmotion.h
class ArkEmotion : public ArkReflectedObject // Id=800D7AE Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=800D7AF Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkEmotion::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=800D7B0 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkEmotion::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkAnimationProperty : public ArkProperty // Id=800D7B1 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkAnimationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkAnimationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkEmotion::ArkAnimationProperty s_ArkAnimationProperty;
	string m_Animation;
	
	class ArkBlendInProperty : public ArkProperty // Id=800D7B2 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkBlendInProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkBlendInProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkEmotion::ArkBlendInProperty s_ArkBlendInProperty;
	float m_BlendIn;
	
	class ArkBlendOutProperty : public ArkProperty // Id=800D7B3 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkEmotion::ArkBlendOutProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D560);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotion::ArkBlendOutProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D570);
	};

	static ArkEmotion::ArkBlendOutProperty s_ArkBlendOutProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x1063160);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x1063230);
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
		
		static inline auto FSetValue = PreyFunction<void(ArkEmotions::ArkEmotionsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10629D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkEmotions::ArkEmotionsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1062A90);
		static inline auto FIsArray = PreyFunction<bool(ArkEmotions::ArkEmotionsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkEmotions::ArkEmotionsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1062AD0);
	};

	static ArkEmotions::ArkEmotionsProperty s_ArkEmotionsProperty;
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
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x10631A0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x10632D0);
	static inline auto FInit = PreyFunction<bool(ArkEmotions *const _this)>(0x10633C0);
	static inline auto FFind = PreyFunction<ArkEmotion const *(ArkEmotions const *const _this, const uint64_t _id)>(0x1063200);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkEmotion
// Header:  Prey/Ark/ArkEmotion.h
class ArkEmotion : public ArkReflectedObject
{ // Size=32 (0x20)
public:
	// ArkEmotion::ArkIDProperty
	// Header:  Prey/Ark/ArkEmotion.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkEmotion::ArkNameProperty
	// Header:  Prey/Ark/ArkEmotion.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkEmotion::ArkAnimationProperty
	// Header:  Prey/Ark/ArkEmotion.h
	class ArkAnimationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkAnimationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkAnimationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkAnimationProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkEmotion::ArkBlendInProperty
	// Header:  Prey/Ark/ArkEmotion.h
	class ArkBlendInProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlendInProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkBlendInProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x16B7EF0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkBlendInProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkEmotion::ArkBlendOutProperty
	// Header:  Prey/Ark/ArkEmotion.h
	class ArkBlendOutProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkBlendOutProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkEmotion::ArkBlendOutProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotion::ArkBlendOutProperty* const _this, ArkReflectedObject* const _pObject)>(0x13B26B0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkEmotion::ArkIDProperty>(0x2D23500);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkEmotion::ArkNameProperty>(0x2D23520);
	string m_Name;
	static inline auto s_ArkAnimationProperty = PreyGlobal<ArkEmotion::ArkAnimationProperty>(0x2D23540);
	string m_Animation;
	static inline auto s_ArkBlendInProperty = PreyGlobal<ArkEmotion::ArkBlendInProperty>(0x2D23560);
	float m_BlendIn;
	static inline auto s_ArkBlendOutProperty = PreyGlobal<ArkEmotion::ArkBlendOutProperty>(0x2D23580);
	float m_BlendOut;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetAnimation(string _arg0_);
	const string& GetAnimation() const;
	void SetBlendIn(float _arg0_);
	const float& GetBlendIn() const;
	void SetBlendOut(float _arg0_);
	const float& GetBlendOut() const;
	ArkEmotion();
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1086060);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1086130);
};

// ArkEmotions
// Header:  Prey/Ark/ArkEmotion.h
class ArkEmotions : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkEmotions::ArkEmotionsProperty
	// Header:  Prey/Ark/ArkEmotion.h
	class ArkEmotionsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkEmotionsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkEmotionsPropertyOv2 = PreyFunction<void(ArkEmotions::ArkEmotionsProperty* const _this)>(0x1085DA0);
		static inline auto FSetValue = PreyFunction<void(const ArkEmotions::ArkEmotionsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1085880);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkEmotions::ArkEmotionsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1085940);
		static inline auto FIsArray = PreyFunction<bool(const ArkEmotions::ArkEmotionsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkEmotions::ArkEmotionsProperty* const _this, ArkReflectedObject* _pObject)>(0x1085980);
	};

	static inline auto s_ArkEmotionsProperty = PreyGlobal<ArkEmotions::ArkEmotionsProperty>(0x2D235A0);
	std::vector<ArkEmotion> m_Emotions;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();
	const ArkEmotion* Find(const uint64_t _id) const { return FFind(this, _id); }

#if 0
	std::vector<ArkEmotion>& GetEmotions();
	const std::vector<ArkEmotion>& GetEmotions() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10860A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x10861D0);
	static inline auto FInit = PreyFunction<bool(ArkEmotions* const _this)>(0x10862C0);
	static inline auto FFind = PreyFunction<const ArkEmotion* (const ArkEmotions* const _this, const uint64_t _id)>(0x1086100);
};
#endif // !MOONCRASH
