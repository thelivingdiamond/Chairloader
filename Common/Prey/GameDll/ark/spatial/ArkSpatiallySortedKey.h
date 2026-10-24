// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatiallySortedKey.h
class ArkSpatiallySortedKey // Id=801430A Size=8
{
public:
	uint64_t m_index;
	
	ArkSpatiallySortedKey();
#ifndef MOONCRASH
	ArkSpatiallySortedKey(ArkSpatiallySortedKey *_other);
#else
	// move constructor (the key is move-only; the return-buffer wrappers of the spatial entries need it)
	ArkSpatiallySortedKey(ArkSpatiallySortedKey&& _other) { FArkSpatiallySortedKeyOv1(this, std::move(_other)); }
#endif
	ArkSpatiallySortedKey(uint64_t _index);
#ifndef MOONCRASH
	ArkSpatiallySortedKey &operator=(ArkSpatiallySortedKey *_other) { return FoperatorEq(this,_other); }
#else
	ArkSpatiallySortedKey& operator=(ArkSpatiallySortedKey&& _other) { return FoperatorEq(this, std::move(_other)); }
#endif
	
#if 0
	int *operator int ArkSafeBool<class ArkSpatiallySortedKey>::*() const;
#endif
	
#ifndef MOONCRASH
	static inline auto FoperatorEq = PreyFunction<ArkSpatiallySortedKey &(ArkSpatiallySortedKey *const _this, ArkSpatiallySortedKey *_other)>(0x1336940);
#else
	static inline auto FArkSpatiallySortedKeyOv2 = PreyFunction<void(ArkSpatiallySortedKey* const _this)>(0x14124B0);
	static inline auto FArkSpatiallySortedKeyOv1 = PreyFunction<void(ArkSpatiallySortedKey* const _this, ArkSpatiallySortedKey&& _other)>(0x14124C0);
	static inline auto FArkSpatiallySortedKeyOv0 = PreyFunction<void(ArkSpatiallySortedKey* const _this, uint64_t _index)>(0x14124F0);
	static inline auto FoperatorEq = PreyFunction<ArkSpatiallySortedKey& (ArkSpatiallySortedKey* const _this, ArkSpatiallySortedKey&& _other)>(0x14124C0);
#endif
};
