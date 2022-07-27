// Header file automatically created from a PDB.

#pragma once

struct ArkResponseFact;

// Header: FromCpp
// Prey/GameDll/ark/dialog/ArkResponseQuery.h
class ArkResponseQuery // Id=801397E Size=24
{
public:
	std::vector<ArkResponseFact> m_facts;
	
	void Insert(ArkResponseFact const &_fact) { FInsert(this,_fact); }
	
#if 0
	void Add(const uint64_t arg0, const char *const arg1, uint64_t arg2);
	bool Contains(const uint64_t arg0) const;
	std::vector<ArkResponseFact> const &GetFacts() const;
	void Grow(unsigned arg0);
#endif
	
	static inline auto FInsert = PreyFunction<void(ArkResponseQuery *const _this, ArkResponseFact const &_fact)>(0x1495F30);
};

