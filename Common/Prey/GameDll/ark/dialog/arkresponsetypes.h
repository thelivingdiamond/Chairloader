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

