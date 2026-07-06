// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/GameDll/ark/spatial/ArkSpatiallySortedKey.h
class ArkSpatiallySortedKey // Id=801430A Size=8
{
public:
	uint64_t m_index;
	
	ArkSpatiallySortedKey();
	ArkSpatiallySortedKey(ArkSpatiallySortedKey *_other);
	ArkSpatiallySortedKey(uint64_t _index);
	ArkSpatiallySortedKey &operator=(ArkSpatiallySortedKey *_other) { return FoperatorEq(this,_other); }
	
#if 0
	int *operator int ArkSafeBool<class ArkSpatiallySortedKey>::*() const;
#endif
	
	static inline auto FoperatorEq = PreyFunction<ArkSpatiallySortedKey &(ArkSpatiallySortedKey *const _this, ArkSpatiallySortedKey *_other)>(0x1336940);
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// ArkSpatiallySortedKey
// Header:  Prey/GameDll/ark/spatial/ArkSpatiallySortedKey.h
class ArkSpatiallySortedKey
{ // Size=8 (0x8)
public:
	uint64_t m_index;

	ArkSpatiallySortedKey();
	ArkSpatiallySortedKey(ArkSpatiallySortedKey&& _other);
	ArkSpatiallySortedKey(uint64_t _index);
	ArkSpatiallySortedKey& operator=(ArkSpatiallySortedKey&& _other) { return FoperatorEq(this, _other); }

#if 0
	int* (*)() const;
#endif

	static inline auto FArkSpatiallySortedKeyOv2 = PreyFunction<void(ArkSpatiallySortedKey* const _this)>(0x14124B0);
	static inline auto FArkSpatiallySortedKeyOv1 = PreyFunction<void(ArkSpatiallySortedKey* const _this, ArkSpatiallySortedKey&& _other)>(0x14124C0);
	static inline auto FArkSpatiallySortedKeyOv0 = PreyFunction<void(ArkSpatiallySortedKey* const _this, uint64_t _index)>(0x14124F0);
	static inline auto FoperatorEq = PreyFunction<ArkSpatiallySortedKey& (ArkSpatiallySortedKey* const _this, ArkSpatiallySortedKey&& _other)>(0x14124C0);
};
#endif // !MOONCRASH
