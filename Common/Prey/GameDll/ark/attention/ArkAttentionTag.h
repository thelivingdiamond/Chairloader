// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Prey/GameDll/ark/attention/ArkAttentionTag.h
struct ArkAttentionTag // Id=8014DE6 Size=8
{
	uint64_t m_value;
	
	ArkAttentionTag();
	ArkAttentionTag(uint64_t _value);
	
#if 0
	int *operator int ArkSafeBool<struct ArkAttentionTag>::*() const;
#endif
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkAttentionTag
// Header:  Prey/GameDll/ark/attention/ArkAttentionTag.h
struct ArkAttentionTag
{ // Size=8 (0x8)
	uint64_t m_value;

	ArkAttentionTag();
	ArkAttentionTag(uint64_t _value);

#if 0
	int* (*)() const;
#endif

	static inline auto FArkAttentionTagOv1 = PreyFunction<void(ArkAttentionTag* const _this)>(0x12A2F50);
	static inline auto FArkAttentionTagOv0 = PreyFunction<void(ArkAttentionTag* const _this, uint64_t _value)>(0x14124F0);
};
#endif // !MOONCRASH
