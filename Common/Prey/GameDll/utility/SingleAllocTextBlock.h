// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

// CSingleAllocTextBlock
// Header:  Prey/GameDll/utility/SingleAllocTextBlock.h
class CSingleAllocTextBlock
{ // Size=48 (0x30)
public:
	// CSingleAllocTextBlock::SReuseDuplicatedStrings
	// Header:  Prey/GameDll/utility/SingleAllocTextBlock.h
	struct SReuseDuplicatedStrings
	{ // Size=8 (0x8)
		const char* m_charPtr;
	};

	char* m_mem;
	uint64_t m_sizeNeeded;
	uint64_t m_sizeNeededWithoutUsingDuplicates;
	uint64_t m_numBytesUsed;
	CSingleAllocTextBlock::SReuseDuplicatedStrings* m_reuseDuplicatedStringsArray;
	int m_reuseDuplicatedStringsArraySize;
	int m_reuseDuplicatedStringsNumUsed;

	CSingleAllocTextBlock();
	~CSingleAllocTextBlock();
	void EmptyWithoutFreeing() { FEmptyWithoutFreeing(this); }
	void IncreaseSizeNeeded(uint64_t theSize) { FIncreaseSizeNeededOv1(this, theSize); }
	const char* StoreText(const char* textIn, bool doDuplicateCheck) { return FStoreText(this, textIn, doDuplicateCheck); }
	void Allocate() { FAllocate(this); }
	const char* FindDuplicate(const char* textIn) { return FFindDuplicate(this, textIn); }

#if 0
	void Reset();
	void IncreaseSizeNeeded(const char* _arg0_, bool _arg1_);
	void Lock();
	uint64_t GetSizeNeeded() const;
	const char* GetMem() const;
	uint64_t GetNumBytesUsed() const;
	void SetDuplicatedStringWorkspace(CSingleAllocTextBlock::SReuseDuplicatedStrings* _arg0_, int _arg1_);
	void RememberPossibleDuplicate(const char* _arg0_);
#endif

	static inline auto FCSingleAllocTextBlock = PreyFunction<void(CSingleAllocTextBlock* const _this)>(0xD48F00);
	static inline auto FBitNotCSingleAllocTextBlock = PreyFunction<void(CSingleAllocTextBlock* const _this)>(0x19289F0);
	static inline auto FEmptyWithoutFreeing = PreyFunction<void(CSingleAllocTextBlock* const _this)>(0x1928A60);
	static inline auto FIncreaseSizeNeededOv1 = PreyFunction<void(CSingleAllocTextBlock* const _this, uint64_t theSize)>(0x1928B00);
	static inline auto FStoreText = PreyFunction<const char* (CSingleAllocTextBlock* const _this, const char* textIn, bool doDuplicateCheck)>(0x1928B10);
	static inline auto FAllocate = PreyFunction<void(CSingleAllocTextBlock* const _this)>(0x1928A30);
	static inline auto FFindDuplicate = PreyFunction<const char* (CSingleAllocTextBlock* const _this, const char* textIn)>(0x1928A70);
};
#endif // MOONCRASH
