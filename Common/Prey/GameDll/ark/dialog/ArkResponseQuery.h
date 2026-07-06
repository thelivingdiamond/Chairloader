// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
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
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/dialog/arkresponsetypes.h>

// ArkResponseQuery
// Header:  Prey/GameDll/ark/dialog/ArkResponseQuery.h
class ArkResponseQuery
{ // Size=24 (0x18)
public:
	std::vector<ArkResponseFact> m_facts;

	void Insert(const ArkResponseFact& _fact) { FInsert(this, _fact); }

#if 0
	void Add(const uint64_t _arg0_, const char* const _arg1_, uint64_t _arg2_);
	bool Contains(const uint64_t _arg0_) const;
	const std::vector<ArkResponseFact>& GetFacts() const;
	void Grow(unsigned _arg0_);
#endif

	static inline auto FInsert = PreyFunction<void(ArkResponseQuery* const _this, const ArkResponseFact& _fact)>(0x15ADA00);
};
#endif // !MOONCRASH
