// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once
#include "arkresponsetypes.h"

// Prey/GameDll/ark/dialog/SArkRuleQuery.h
struct SArkRuleQuery // Id=801397F Size=40
{
	std::array<const std::vector<ArkResponseFact> *,3> queryData;
	std::vector<size_t> const &voices;
	float currentTime;
	bool bIgnoreVoice;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/GameDll/ark/dialog/arkresponsetypes.h>

// SArkRuleQuery
// Header:  Prey/GameDll/ark/dialog/SArkRuleQuery.h
struct SArkRuleQuery
{ // Size=40 (0x28)
	std::array<const std::vector<ArkResponseFact, std::allocator<ArkResponseFact>>*, 3> queryData;
	const std::vector<uint64_t>& voices;
	float currentTime;
	bool bIgnoreVoice;

#if 0
	SArkRuleQuery(const std::vector<ArkResponseFact>& _arg0_, const std::vector<ArkResponseFact>& _arg1_, const std::vector<ArkResponseFact>& _arg2_, const std::vector<uint64_t>& _arg3_, const bool _arg4_);
#endif
};
#endif // !MOONCRASH
