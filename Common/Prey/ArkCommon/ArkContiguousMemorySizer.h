// Header file automatically created from a PDB.

#pragma once

// Header: FromCpp
// Prey/ArkCommon/ArkContiguousMemorySizer.h
class ArkContiguousMemorySizer // Id=801346C Size=8
{
public:
	uint64_t m_byteCount;
	
	ArkContiguousMemorySizer();
	void AddAlignedBytes(uint64_t _byteCount, uint64_t _alignment) { FAddAlignedBytes(this,_byteCount,_alignment); }
	uint64_t GetByteCount() const { return FGetByteCount(this); }
	
#if 0
	void AddBytes(uint64_t arg0);
#endif
	
	static inline auto FAddAlignedBytes = PreyFunction<void(ArkContiguousMemorySizer *const _this, uint64_t _byteCount, uint64_t _alignment)>(0x10565A0);
	static inline auto FGetByteCount = PreyFunction<uint64_t(ArkContiguousMemorySizer const *const _this)>(0x12E5E70);
};

