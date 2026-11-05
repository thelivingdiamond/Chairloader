// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMemory/FixedAllocator.h>

namespace MNM
{

// MNM::DynamicSpanGrid
// Header:  CryEngine/cryaisystem/navigation/mnm/DynamicSpanGrid.h
class DynamicSpanGrid
{ // Size=88 (0x58)
public:
	// MNM::DynamicSpanGrid::Element
	// Header:  CryEngine/cryaisystem/navigation/mnm/DynamicSpanGrid.h
	struct Element
	{ // Size=16 (0x10)
		enum
		{
			MaxWaterDepth = 1023,
		};

		unsigned backface : 1;
		unsigned flags : 3;
		unsigned bottom : 9;
		unsigned top : 9;
		unsigned depth : 10;
		MNM::DynamicSpanGrid::Element* next;

	#if 0
		Element();
		Element(uint16_t _arg0_, uint16_t _arg1_, bool _arg2_);
	#endif
	};

	using Grid = std::vector<MNM::DynamicSpanGrid::Element*>;
	using Allocator = TypeFixedAllocator<MNM::DynamicSpanGrid::Element,262144,8>;

	uint64_t m_width;
	uint64_t m_height;
	uint64_t m_count;
	std::vector<MNM::DynamicSpanGrid::Element*> m_grid;
	TypeFixedAllocator<MNM::DynamicSpanGrid::Element,262144,8> m_alloc;

	DynamicSpanGrid();
	DynamicSpanGrid(const MNM::DynamicSpanGrid& other);
	void Reset(uint64_t width, uint64_t height) { FReset(this, width, height); }
	MNM::DynamicSpanGrid::Element* operator[](uint64_t i) { return FoperatorSBLSBROv1(this, i); }
	const MNM::DynamicSpanGrid::Element* operator[](uint64_t i) const { return FoperatorSBLSBROv0(this, i); }
	uint64_t GetWidth() const { return FGetWidth(this); }
	uint64_t GetHeight() const { return FGetHeight(this); }
	uint64_t GetCount() const { return FGetCount(this); }
	uint64_t GetMemoryUsage() const { return FGetMemoryUsage(this); }
	void AddVoxel(uint64_t x, uint64_t y, uint64_t z, bool backface) { FAddVoxel(this, x, y, z, backface); }
	void MergeGrid(MNM::DynamicSpanGrid* _other) { FMergeGrid(this, _other); }
	void TryMergeNext(MNM::DynamicSpanGrid::Element* span, uint16_t top, bool backface) { FTryMergeNext(this, span, top, backface); }
	void TryMergePrev(MNM::DynamicSpanGrid::Element* span, MNM::DynamicSpanGrid::Element* prev, uint16_t bottom, bool backface) { FTryMergePrev(this, span, prev, bottom, backface); }
	void Destruct(MNM::DynamicSpanGrid::Element* span) { FDestruct(this, span); }

#if 0
	DynamicSpanGrid(uint64_t _arg0_, uint64_t _arg1_);
	void Swap(MNM::DynamicSpanGrid& _arg0_);
	MNM::DynamicSpanGrid::Element* GetSpan(uint64_t _arg0_, uint64_t _arg1_);
	const MNM::DynamicSpanGrid::Element* GetSpan(uint64_t _arg0_, uint64_t _arg1_) const;
	MNM::DynamicSpanGrid::Element* Construct(const MNM::DynamicSpanGrid::Element& _arg0_);
#endif

#ifndef MOONCRASH
	static inline auto FDynamicSpanGridOv2 = PreyFunction<void(MNM::DynamicSpanGrid* const _this)>(0x638CF0);
	static inline auto FDynamicSpanGridOv0 = PreyFunction<void(MNM::DynamicSpanGrid* const _this, const MNM::DynamicSpanGrid& other)>(0x638BD0);
	static inline auto FReset = PreyFunction<void(MNM::DynamicSpanGrid* const _this, uint64_t width, uint64_t height)>(0x639580);
	static inline auto FoperatorSBLSBROv1 = PreyFunction<MNM::DynamicSpanGrid::Element* (MNM::DynamicSpanGrid* const _this, uint64_t i)>(0x1143FE0);
	static inline auto FoperatorSBLSBROv0 = PreyFunction<const MNM::DynamicSpanGrid::Element* (const MNM::DynamicSpanGrid* const _this, uint64_t i)>(0x1143FE0);
	static inline auto FGetWidth = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x12E5E70);
	static inline auto FGetHeight = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x12AAC70);
	static inline auto FGetCount = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x5BFB50);
	static inline auto FGetMemoryUsage = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x639410);
	static inline auto FAddVoxel = PreyFunction<void(MNM::DynamicSpanGrid* const _this, uint64_t x, uint64_t y, uint64_t z, bool backface)>(0x638DF0);
	static inline auto FMergeGrid = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid* _other)>(0x639440);
	static inline auto FTryMergeNext = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid::Element* span, uint16_t top, bool backface)>(0x6396F0);
	static inline auto FTryMergePrev = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid::Element* span, MNM::DynamicSpanGrid::Element* prev, uint16_t bottom, bool backface)>(0x639760);
	static inline auto FDestruct = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid::Element* span)>(0x6392B0);
#else
	static inline auto FDynamicSpanGridOv2 = PreyFunction<void(MNM::DynamicSpanGrid* const _this)>(0x654850);
	static inline auto FDynamicSpanGridOv0 = PreyFunction<void(MNM::DynamicSpanGrid* const _this, const MNM::DynamicSpanGrid& other)>(0x654730);
	static inline auto FReset = PreyFunction<void(MNM::DynamicSpanGrid* const _this, uint64_t width, uint64_t height)>(0x6550F0);
	static inline auto FoperatorSBLSBROv1 = PreyFunction<MNM::DynamicSpanGrid::Element* (MNM::DynamicSpanGrid* const _this, uint64_t i)>(0x654950);
	static inline auto FoperatorSBLSBROv0 = PreyFunction<const MNM::DynamicSpanGrid::Element* (const MNM::DynamicSpanGrid* const _this, uint64_t i)>(0x654950);
	static inline auto FGetWidth = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x1112EA0);
	static inline auto FGetHeight = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x12DC700);
	static inline auto FGetCount = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x547450);
	static inline auto FGetMemoryUsage = PreyFunction<uint64_t(const MNM::DynamicSpanGrid* const _this)>(0x654F80);
	static inline auto FAddVoxel = PreyFunction<void(MNM::DynamicSpanGrid* const _this, uint64_t x, uint64_t y, uint64_t z, bool backface)>(0x654960);
	static inline auto FMergeGrid = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid* _other)>(0x654FB0);
	static inline auto FTryMergeNext = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid::Element* span, uint16_t top, bool backface)>(0x655260);
	static inline auto FTryMergePrev = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid::Element* span, MNM::DynamicSpanGrid::Element* prev, uint16_t bottom, bool backface)>(0x6552D0);
	static inline auto FDestruct = PreyFunction<void(MNM::DynamicSpanGrid* const _this, MNM::DynamicSpanGrid::Element* span)>(0x654E20);
#endif
};


} // namespace MNM

