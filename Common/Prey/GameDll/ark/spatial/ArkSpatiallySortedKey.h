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

