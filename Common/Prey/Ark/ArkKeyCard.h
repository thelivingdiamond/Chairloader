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

