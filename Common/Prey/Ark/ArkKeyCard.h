// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;

// Header: Exact
// Prey/Ark/ArkKeyCard.h
class ArkKeyCard : public ArkReflectedObject // Id=8013C62 Size=32
{
public:
	class ArkIDProperty : public ArkProperty // Id=8013C63 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCard::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106D720);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCard::ArkIDProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106D730);
	};

	static ArkKeyCard::ArkIDProperty s_ArkIDProperty;
	uint64_t m_ID;
	
	class ArkNameProperty : public ArkProperty // Id=8013C64 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCard::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10637A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCard::ArkNameProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1328480);
	};

	static ArkKeyCard::ArkNameProperty s_ArkNameProperty;
	string m_Name;
	
	class ArkLabelProperty : public ArkProperty // Id=8013C65 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCard::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x10732F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCard::ArkLabelProperty const *const _this, ArkReflectedObject *const _pObject)>(0x1466BF0);
	};

	static ArkKeyCard::ArkLabelProperty s_ArkLabelProperty;
	string m_Label;
	
	class ArkLocationProperty : public ArkProperty // Id=8013C66 Size=32
	{
	public:
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCard::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x1467B60);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCard::ArkLocationProperty const *const _this, ArkReflectedObject *const _pObject)>(0x10821F0);
	};

	static ArkKeyCard::ArkLocationProperty s_ArkLocationProperty;
	uint64_t m_Location;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	
#if 0
	void SetID(uint64_t arg0);
	const uint64_t &GetID() const;
	void SetName(string arg0);
	string const &GetName() const;
	void SetLabel(string arg0);
	string const &GetLabel() const;
	void SetLocation(uint64_t arg0);
	const uint64_t &GetLocation() const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106D080);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106D120);
};

// Header: Exact
// Prey/Ark/arkkeycard.h
class ArkKeyCards : public ArkReflectedLibrary // Id=8013C74 Size=32
{
public:
	class ArkKeyCardsProperty : public ArkProperty // Id=8013C75 Size=32
	{
	public:
		ArkKeyCardsProperty();
		virtual void SetValue(ArkReflectedObject *const _pObject, IArkValueBase const *_v) const;
		virtual ArkReflectedObject *GetMemPtr(ArkReflectedObject *const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject *_pObject) const;
		
		static inline auto FSetValue = PreyFunction<void(ArkKeyCards::ArkKeyCardsProperty const *const _this, ArkReflectedObject *const _pObject, IArkValueBase const *_v)>(0x106CA10);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject *(ArkKeyCards::ArkKeyCardsProperty const *const _this, ArkReflectedObject *const _pObject)>(0x106CAC0);
		static inline auto FIsArray = PreyFunction<bool(ArkKeyCards::ArkKeyCardsProperty const *const _this)>(0x1B933B0);
		static inline auto FReset = PreyFunction<void(ArkKeyCards::ArkKeyCardsProperty const *const _this, ArkReflectedObject *_pObject)>(0x1062AD0);
	};

	static ArkKeyCards::ArkKeyCardsProperty s_ArkKeyCardsProperty;
	std::vector<ArkKeyCard> m_KeyCards;
	
	static ArkReflectedObject *Create() { return FCreate(); }
	static ArkClass *GetClass() { return FGetClass(); }
	virtual bool Init();
	virtual ~ArkKeyCards();
	
#if 0
	std::vector<ArkKeyCard> &GetKeyCards();
	std::vector<ArkKeyCard> const &GetKeyCards() const;
	ArkKeyCard const *FindKeyCard(const uint64_t arg0) const;
#endif
	
	static inline auto FCreate = PreyFunction<ArkReflectedObject *()>(0x106D0C0);
	static inline auto FGetClass = PreyFunction<ArkClass *()>(0x106D1C0);
	static inline auto FInit = PreyFunction<bool(ArkKeyCards *const _this)>(0x106D2B0);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedLibrary.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkKeyCard
// Header:  Prey/Ark/ArkKeyCard.h
class ArkKeyCard : public ArkReflectedObject
{ // Size=40 (0x28)
public:
	// ArkKeyCard::ArkIDProperty
	// Header:  Prey/Ark/ArkKeyCard.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCard::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCard::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkKeyCard::ArkNameProperty
	// Header:  Prey/Ark/ArkKeyCard.h
	class ArkNameProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkNameProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCard::ArkNameProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B19D0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCard::ArkNameProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkKeyCard::ArkLabelProperty
	// Header:  Prey/Ark/ArkKeyCard.h
	class ArkLabelProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLabelProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCard::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x119CEA0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCard::ArkLabelProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkKeyCard::ArkLocationProperty
	// Header:  Prey/Ark/ArkKeyCard.h
	class ArkLocationProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkLocationProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCard::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084740);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCard::ArkLocationProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkKeyCard::ArkResetWithCharacterChangeProperty
	// Header:  Prey/Ark/ArkKeyCard.h
	class ArkResetWithCharacterChangeProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkResetWithCharacterChangeProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkKeyCard::ArkResetWithCharacterChangeProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1084750);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCard::ArkResetWithCharacterChangeProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkKeyCard::ArkIDProperty>(0x2D25890);
	uint64_t m_ID;
	static inline auto s_ArkNameProperty = PreyGlobal<ArkKeyCard::ArkNameProperty>(0x2D258B0);
	string m_Name;
	static inline auto s_ArkLabelProperty = PreyGlobal<ArkKeyCard::ArkLabelProperty>(0x2D258D0);
	string m_Label;
	static inline auto s_ArkLocationProperty = PreyGlobal<ArkKeyCard::ArkLocationProperty>(0x2D258F0);
	uint64_t m_Location;
	static inline auto s_ArkResetWithCharacterChangeProperty = PreyGlobal<ArkKeyCard::ArkResetWithCharacterChangeProperty>(0x2D25910);
	bool m_ResetWithCharacterChange;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetName(string _arg0_);
	const string& GetName() const;
	void SetLabel(string _arg0_);
	const string& GetLabel() const;
	void SetLocation(uint64_t _arg0_);
	const uint64_t& GetLocation() const;
	void SetResetWithCharacterChange(bool _arg0_);
	const bool& GetResetWithCharacterChange() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x10910F0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1091190);
};

// ArkKeyCards
// Header:  Prey/Ark/ArkKeyCard.h
class ArkKeyCards : public ArkReflectedLibrary
{ // Size=32 (0x20)
public:
	// ArkKeyCards::ArkKeyCardsProperty
	// Header:  Prey/Ark/ArkKeyCard.h
	class ArkKeyCardsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		ArkKeyCardsProperty();
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

		static inline auto FArkKeyCardsPropertyOv2 = PreyFunction<void(ArkKeyCards::ArkKeyCardsProperty* const _this)>(0x1090E10);
		static inline auto FSetValue = PreyFunction<void(const ArkKeyCards::ArkKeyCardsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10908A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkKeyCards::ArkKeyCardsProperty* const _this, ArkReflectedObject* const _pObject)>(0x1090960);
		static inline auto FIsArray = PreyFunction<bool(const ArkKeyCards::ArkKeyCardsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkKeyCards::ArkKeyCardsProperty* const _this, ArkReflectedObject* _pObject)>(0x10909A0);
	};

	static inline auto s_ArkKeyCardsProperty = PreyGlobal<ArkKeyCards::ArkKeyCardsProperty>(0x2D25930);
	std::vector<ArkKeyCard> m_KeyCards;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }
	virtual bool Init();

#if 0
	std::vector<ArkKeyCard>& GetKeyCards();
	const std::vector<ArkKeyCard>& GetKeyCards() const;
	const ArkKeyCard* FindKeyCard(const uint64_t _arg0_) const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1091130);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x1091230);
	static inline auto FInit = PreyFunction<bool(ArkKeyCards* const _this)>(0x1091320);
};
#endif // !MOONCRASH
