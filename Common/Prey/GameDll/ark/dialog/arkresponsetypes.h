// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// Header: Exact
// Prey/GameDll/ark/dialog/arkresponsetypes.h
struct ArkResponseValue // Id=8013637 Size=16
{
	union ArkNumberValue // Id=8013638 Size=8
	{
	public:
		uint64_t integer;
		double fp;
	};

	ArkResponseValue::ArkNumberValue num;
	string str;
	
	void operator=(const char *const _value) { FoperatorEqOv3(this,_value); }
	
#if 0
	void operator+=(const double arg0);
	void operator-=(const double arg0);
	void Serialize(TSerialize arg0);
#endif
	
	static inline auto FoperatorEqOv3 = PreyFunction<void(ArkResponseValue *const _this, const char *const _value)>(0x1498130);
};

// Header: Exact
// Prey/GameDll/ark/dialog/arkresponsetypes.h
struct ArkResponseFact // Id=8013639 Size=24
{
	using List = std::vector<ArkResponseFact>;
	
	uint64_t key;
	ArkResponseValue value;
	
	static bool InsertPredicate(ArkResponseFact const &_fact, const uint64_t &_key) { return FInsertPredicate(_fact,_key); }
	
#if 0
	void Serialize(TSerialize arg0);
	static void Sort(std::vector<ArkResponseFact> &arg0);
#endif
	
	static inline auto FInsertPredicate = PreyFunction<bool(ArkResponseFact const &_fact, const uint64_t &_key)>(0x1488A30);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryNetwork/ISerialize.h>

// ArkResponseValue
// Header:  Prey/GameDll/ark/dialog/arkresponsetypes.h
struct ArkResponseValue
{ // Size=16 (0x10)
	// ArkResponseValue::ArkNumberValue
	// Header:  Prey/GameDll/ark/dialog/arkresponsetypes.h
	union ArkNumberValue
	{ // Size=8 (0x8)
		uint64_t integer;
		double fp;
	};

	ArkResponseValue::ArkNumberValue num;
	string str;

	void operator=(const char* const _value) { FoperatorEqOv3(this, _value); }

#if 0
	ArkResponseValue();
	ArkResponseValue(const uint64_t _arg0_);
	ArkResponseValue(const float _arg0_);
	ArkResponseValue(const char* const _arg0_);
	void operator=(const float _arg0_);
	void operator=(const string& _arg0_);
	void operator=(const uint64_t _arg0_);
	void operator+=(const double _arg0_);
	void operator-=(const double _arg0_);
	void Serialize(TSerialize _arg0_);
#endif

	static inline auto FoperatorEqOv3 = PreyFunction<void(ArkResponseValue* const _this, const char* const _value)>(0x15AFC00);
};

// ArkResponseFact
// Header:  Prey/GameDll/ark/dialog/arkresponsetypes.h
struct ArkResponseFact
{ // Size=24 (0x18)
	using List = std::vector<ArkResponseFact>;

	uint64_t key;
	ArkResponseValue value;

	static bool InsertPredicate(const ArkResponseFact& _fact, const uint64_t& _key) { return FInsertPredicate(_fact, _key); }

#if 0
	ArkResponseFact();
	ArkResponseFact(const uint64_t _arg0_);
	ArkResponseFact(const uint64_t _arg0_, const ArkResponseValue& _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const float _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const int _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const uint64_t _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const bool _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const char* const _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const string& _arg1_);
	ArkResponseFact(const uint64_t _arg0_, const char* const _arg1_, const uint64_t _arg2_);
	void Serialize(TSerialize _arg0_);
	static void Sort(std::vector<ArkResponseFact>& _arg0_);
#endif

	static inline auto FInsertPredicate = PreyFunction<bool(const ArkResponseFact& _fact, const uint64_t& _key)>(0x15A0B20);
};
#endif // !MOONCRASH
