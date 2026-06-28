// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/Ark/ArkPlayableCharacter.h>
#include <Prey/ArkCommon/reflection/ArkProperty.h>
#include <Prey/ArkCommon/reflection/ArkReflectedObject.h>

class ArkClass;
class IArkValueBase;

// ArkDate
// Header:  Prey/Ark/ArkChallenge.h
class ArkDate : public ArkReflectedObject
{ // Size=12 (0xC)
public:
	// ArkDate::ArkMonthProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkMonthProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkMonthProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDate::ArkMonthProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A56F0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDate::ArkMonthProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkDate::ArkDayProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkDayProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkDayProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDate::ArkDayProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x13BD3C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDate::ArkDayProperty* const _this, ArkReflectedObject* const _pObject)>(0x14035E0);
	};

	// ArkDate::ArkYearProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkYearProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkYearProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkDate::ArkYearProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkDate::ArkYearProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	static inline auto s_ArkMonthProperty = PreyGlobal<ArkDate::ArkMonthProperty>(0x2D21EE0);
	int m_Month;
	static inline auto s_ArkDayProperty = PreyGlobal<ArkDate::ArkDayProperty>(0x2D21F00);
	int m_Day;
	static inline auto s_ArkYearProperty = PreyGlobal<ArkDate::ArkYearProperty>(0x2D21F20);
	int m_Year;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	void SetMonth(int _arg0_);
	const int& GetMonth() const;
	void SetDay(int _arg0_);
	const int& GetDay() const;
	void SetYear(int _arg0_);
	const int& GetYear() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107D1A0);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107D2A0);
};

// ArkChallenge
// Header:  Prey/Ark/ArkChallenge.h
class ArkChallenge : public ArkReflectedObject
{ // Size=152 (0x98)
public:
	// ArkChallenge::ArkIDProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkIDProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkIDProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkIDProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x142D5C0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkIDProperty* const _this, ArkReflectedObject* const _pObject)>(0x1088870);
	};

	// ArkChallenge::ArkSeedProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkSeedProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkSeedProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkSeedProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x140C5E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkSeedProperty* const _this, ArkReflectedObject* const _pObject)>(0x1093260);
	};

	// ArkChallenge::ArkPlayableCharacterProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkPlayableCharacterProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkPlayableCharacterProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkPlayableCharacterProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1086550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkPlayableCharacterProperty* const _this, ArkReflectedObject* const _pObject)>(0x13C06B0);
	};

	// ArkChallenge::ArkStartingMapProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingMapProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartingMapProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingMapProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B3000);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingMapProperty* const _this, ArkReflectedObject* const _pObject)>(0x1082790);
	};

	// ArkChallenge::ArkStartingCryptoProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingCryptoProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartingCryptoProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingCryptoProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1402FC0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingCryptoProperty* const _this, ArkReflectedObject* const _pObject)>(0x16C41C0);
	};

	// ArkChallenge::ArkStartingNeuromodsProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingNeuromodsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartingNeuromodsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingNeuromodsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10A3110);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingNeuromodsProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C370);
	};

	// ArkChallenge::ArkStartingFabPlansProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingFabPlansProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStartingFabPlansProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingFabPlansProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x10B78E0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingFabPlansProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C380);
		static inline auto FIsArray = PreyFunction<bool(const ArkChallenge::ArkStartingFabPlansProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChallenge::ArkStartingFabPlansProperty* const _this, ArkReflectedObject* _pObject)>(0x10B2750);
	};

	// ArkChallenge::ArkStartingItemsProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingItemsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStartingItemsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingItemsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107C3A0);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingItemsProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C410);
		static inline auto FIsArray = PreyFunction<bool(const ArkChallenge::ArkStartingItemsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChallenge::ArkStartingItemsProperty* const _this, ArkReflectedObject* _pObject)>(0x107C430);
	};

	// ArkChallenge::ArkStartingAbilitiesProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingAbilitiesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStartingAbilitiesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingAbilitiesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x1079640);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingAbilitiesProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C440);
		static inline auto FIsArray = PreyFunction<bool(const ArkChallenge::ArkStartingAbilitiesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChallenge::ArkStartingAbilitiesProperty* const _this, ArkReflectedObject* _pObject)>(0x1079660);
	};

	// ArkChallenge::ArkStartingStoreChipsetsProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartingStoreChipsetsProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkStartingStoreChipsetsProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartingStoreChipsetsProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107C460);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartingStoreChipsetsProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C4C0);
		static inline auto FIsArray = PreyFunction<bool(const ArkChallenge::ArkStartingStoreChipsetsProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChallenge::ArkStartingStoreChipsetsProperty* const _this, ArkReflectedObject* _pObject)>(0x107C4E0);
	};

	// ArkChallenge::ArkStartDateProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkStartDateProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;

	#if 0
		ArkStartDateProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallenge::ArkStartDateProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107C550);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallenge::ArkStartDateProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C570);
	};

	static inline auto s_ArkIDProperty = PreyGlobal<ArkChallenge::ArkIDProperty>(0x2D21F40);
	uint64_t m_ID;
	static inline auto s_ArkSeedProperty = PreyGlobal<ArkChallenge::ArkSeedProperty>(0x2D21F60);
	int m_Seed;
	static inline auto s_ArkPlayableCharacterProperty = PreyGlobal<ArkChallenge::ArkPlayableCharacterProperty>(0x2D21F80);
	uint64_t m_PlayableCharacter;
	static inline auto s_ArkStartingMapProperty = PreyGlobal<ArkChallenge::ArkStartingMapProperty>(0x2D21FA0);
	string m_StartingMap;
	static inline auto s_ArkStartingCryptoProperty = PreyGlobal<ArkChallenge::ArkStartingCryptoProperty>(0x2D21FC0);
	float m_StartingCrypto;
	static inline auto s_ArkStartingNeuromodsProperty = PreyGlobal<ArkChallenge::ArkStartingNeuromodsProperty>(0x2D21FE0);
	int m_StartingNeuromods;
	static inline auto s_ArkStartingFabPlansProperty = PreyGlobal<ArkChallenge::ArkStartingFabPlansProperty>(0x2D22000);
	std::vector<uint64_t> m_StartingFabPlans;
	static inline auto s_ArkStartingItemsProperty = PreyGlobal<ArkChallenge::ArkStartingItemsProperty>(0x2D22020);
	std::vector<ArkStartingItem> m_StartingItems;
	static inline auto s_ArkStartingAbilitiesProperty = PreyGlobal<ArkChallenge::ArkStartingAbilitiesProperty>(0x2D22040);
	std::vector<uint64_t> m_StartingAbilities;
	static inline auto s_ArkStartingStoreChipsetsProperty = PreyGlobal<ArkChallenge::ArkStartingStoreChipsetsProperty>(0x2D22060);
	std::vector<string> m_StartingStoreChipsets;
	static inline auto s_ArkStartDateProperty = PreyGlobal<ArkChallenge::ArkStartDateProperty>(0x2D22080);
	ArkDate m_StartDate;

	static ArkReflectedObject* Create() { return FCreate(); }
	static ArkClass* GetClass() { return FGetClass(); }

#if 0
	ArkChallenge();
	void SetID(uint64_t _arg0_);
	const uint64_t& GetID() const;
	void SetSeed(int _arg0_);
	const int& GetSeed() const;
	void SetPlayableCharacter(uint64_t _arg0_);
	const uint64_t& GetPlayableCharacter() const;
	void SetStartingMap(string _arg0_);
	const string& GetStartingMap() const;
	void SetStartingCrypto(float _arg0_);
	const float& GetStartingCrypto() const;
	void SetStartingNeuromods(int _arg0_);
	const int& GetStartingNeuromods() const;
	std::vector<uint64_t>& GetStartingFabPlans();
	const std::vector<uint64_t>& GetStartingFabPlans() const;
	std::vector<ArkStartingItem>& GetStartingItems();
	const std::vector<ArkStartingItem>& GetStartingItems() const;
	std::vector<uint64_t>& GetStartingAbilities();
	const std::vector<uint64_t>& GetStartingAbilities() const;
	std::vector<string>& GetStartingStoreChipsets();
	const std::vector<string>& GetStartingStoreChipsets() const;
	void SetStartDate(ArkDate _arg0_);
	const ArkDate& GetStartDate() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x107D130);
	static inline auto FGetClass = PreyFunction<ArkClass* ()>(0x107D200);
};

// ArkChallengeList
// Header:  Prey/Ark/ArkChallenge.h
class ArkChallengeList : public ArkReflectedObject
{ // Size=24 (0x18)
public:
	// ArkChallengeList::ArkChallengesProperty
	// Header:  Prey/Ark/ArkChallenge.h
	class ArkChallengesProperty : public ArkProperty
	{ // Size=32 (0x20)
	public:
		virtual void SetValue(ArkReflectedObject* const _pObject, const IArkValueBase* _v) const;
		virtual ArkReflectedObject* GetMemPtr(ArkReflectedObject* const _pObject) const;
		virtual bool IsArray() const;
		virtual void Reset(ArkReflectedObject* _pObject) const;

	#if 0
		ArkChallengesProperty();
	#endif

		static inline auto FSetValue = PreyFunction<void(const ArkChallengeList::ArkChallengesProperty* const _this, ArkReflectedObject* const _pObject, const IArkValueBase* _v)>(0x107C580);
		static inline auto FGetMemPtr = PreyFunction<ArkReflectedObject* (const ArkChallengeList::ArkChallengesProperty* const _this, ArkReflectedObject* const _pObject)>(0x107C600);
		static inline auto FIsArray = PreyFunction<bool(const ArkChallengeList::ArkChallengesProperty* const _this)>(0x1A302A0);
		static inline auto FReset = PreyFunction<void(const ArkChallengeList::ArkChallengesProperty* const _this, ArkReflectedObject* _pObject)>(0x107C630);
	};

	static inline auto s_ArkChallengesProperty = PreyGlobal<ArkChallengeList::ArkChallengesProperty>(0x2D220A0);
	std::vector<ArkChallenge> m_Challenges;

	static ArkReflectedObject* Create() { return FCreate(); }
	const ArkChallenge* Find(const uint64_t _id) const { return FFind(this, _id); }

#if 0
	static ArkClass* GetClass();
	std::vector<ArkChallenge>& GetChallenges();
	const std::vector<ArkChallenge>& GetChallenges() const;
#endif

	static inline auto FCreate = PreyFunction<ArkReflectedObject* ()>(0x1077160);
	static inline auto FFind = PreyFunction<const ArkChallenge* (const ArkChallengeList* const _this, const uint64_t _id)>(0x107D1D0);
};
#endif // MOONCRASH
