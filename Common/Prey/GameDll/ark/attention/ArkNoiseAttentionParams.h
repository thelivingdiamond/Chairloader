// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/attention/ArkNoiseAttentionParams.h
struct ArkNoiseAttentionParams // Id=8014DE8 Size=256
{
	std::unordered_set<unsigned __int64> m_footfallNoiseSet;
	std::unordered_set<unsigned __int64> m_callForHelpNoiseSet;
	std::unordered_set<unsigned __int64> m_dangerNoiseSet;
	std::unordered_set<unsigned __int64> m_frightfulNoiseSet;
	
	void LoadParams() { FLoadParams(this); }
	
	static inline auto FLoadParams = PreyFunction<void(ArkNoiseAttentionParams *const _this)>(0x1259690);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkNoiseAttentionParams
// Header:  Prey/GameDll/ark/attention/ArkNoiseAttentionParams.h
struct ArkNoiseAttentionParams
{ // Size=256 (0x100)
	std::unordered_set<uint64_t> m_footfallNoiseSet;
	std::unordered_set<uint64_t> m_callForHelpNoiseSet;
	std::unordered_set<uint64_t> m_dangerNoiseSet;
	std::unordered_set<uint64_t> m_frightfulNoiseSet;

	void LoadParams() { FLoadParams(this); }

	static inline auto FLoadParams = PreyFunction<void(ArkNoiseAttentionParams* const _this)>(0x12FD480);
};
#endif // !MOONCRASH
