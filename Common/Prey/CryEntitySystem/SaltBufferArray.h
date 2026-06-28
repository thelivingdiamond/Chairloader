// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once

template <typename A, typename B, int size> class CSaltBufferArray {
    struct SSaltBufferElement// Size=0x4 (Id=1944476)
    {
        A m_Salt;// Offset=0x0 Size=0x2
        B m_NextIndex;// Offset=0x2 Size=0x2
    };
    SSaltBufferElement m_Buffer[size];// Offset=0x0 Size=0x3fff4
private:
    A m_FreeListStartIndex;// Offset=0x3fff4 Size=0x2
    B m_maxUsed;// Offset=0x3fff6 Size=0x2
};
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <_unknown/CSaltHandle.h>

// CSaltBufferArray<unsigned short,unsigned short,65533>
// Header:  CryEngine/cryentitysystem/saltbufferarray.h
class CSaltBufferArray<unsigned short,unsigned short,65533>
{ // Size=262136 (0x3FFF8)
public:
	// CSaltBufferArray<unsigned short,unsigned short,65533>::SSaltBufferElement
	// Header:  CryEngine/cryentitysystem/saltbufferarray.h
	struct SSaltBufferElement
	{ // Size=4 (0x4)
		uint16_t m_Salt;
		uint16_t m_NextIndex;
	};

	CSaltBufferArray<unsigned short,unsigned short,65533>::SSaltBufferElement m_Buffer[65533];
	uint16_t m_FreeListStartIndex;
	uint16_t m_maxUsed;

	void InsertKnownHandle(const CSaltHandle<unsigned short,unsigned short> Handle) { FInsertKnownHandle(this, Handle); }

#if 0
	CSaltBufferArray<unsigned short,unsigned short,65533>();
	void Reset();
	static uint16_t GetTSize();
	bool IsFull() const;
	CSaltHandle<unsigned short,unsigned short> InsertDynamic();
	CSaltHandle<unsigned short,unsigned short> InsertStatic();
	void Remove(const CSaltHandle<unsigned short,unsigned short> _arg0_);
	void Debug();
	bool IsValid(const CSaltHandle<unsigned short,unsigned short> _arg0_) const;
	bool IsUsed(const uint16_t _arg0_) const;
	uint16_t GetMaxUsed() const;
	void RemoveFromFreeList(const uint16_t _arg0_);
#endif

	static inline auto FInsertKnownHandle = PreyFunction<void(CSaltBufferArray<unsigned short,unsigned short,65533>* const _this, const CSaltHandle<unsigned short,unsigned short> Handle)>(0x940350);
};
#endif // !MOONCRASH
