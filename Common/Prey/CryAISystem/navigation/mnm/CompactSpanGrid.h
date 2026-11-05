// Header file automatically created from a PDB.
#pragma once

namespace MNM
{
class DynamicSpanGrid;
} // namespace MNM

namespace MNM
{

// MNM::CompactSpanGrid
// Header:  CryEngine/cryaisystem/navigation/mnm/CompactSpanGrid.h
class CompactSpanGrid
{ // Size=64 (0x40)
public:
	// MNM::CompactSpanGrid::Cell
	// Header:  CryEngine/cryaisystem/navigation/mnm/CompactSpanGrid.h
	struct Cell
	{ // Size=4 (0x4)
		enum
		{
			MaxSpanCount = 255,
		};

		unsigned index : 24;
		unsigned count : 8;

	#if 0
		Cell();
		Cell(unsigned _arg0_, unsigned _arg1_);
		bool operator bool() const;
	#endif
	};

	// MNM::CompactSpanGrid::Span
	// Header:  CryEngine/cryaisystem/navigation/mnm/CompactSpanGrid.h
	struct Span
	{ // Size=4 (0x4)
		unsigned backface : 1;
		unsigned flags : 3;
		unsigned bottom : 9;
		unsigned height : 9;
		unsigned depth : 10;

	#if 0
		Span();
		Span(uint16_t _arg0_, uint16_t _arg1_, uint16_t _arg2_, bool _arg3_);
	#endif
	};

	using Cells = std::vector<MNM::CompactSpanGrid::Cell>;
	using Spans = std::vector<MNM::CompactSpanGrid::Span>;

	uint64_t m_width;
	uint64_t m_height;
	std::vector<MNM::CompactSpanGrid::Cell> m_cells;
	std::vector<MNM::CompactSpanGrid::Span> m_spans;

	bool GetSpanAt(uint64_t x, uint64_t y, uint64_t top, uint64_t tolerance, uint64_t& outSpan) const { return FGetSpanAtOv1(this, x, y, top, tolerance, outSpan); }
	void Swap(MNM::CompactSpanGrid& other) { FSwap(this, other); }
	void BuildFrom(const MNM::DynamicSpanGrid& dynGrid) { FBuildFrom(this, dynGrid); }
	void CompactExcluding(const MNM::CompactSpanGrid& spanGrid, uint64_t flags, uint64_t newSpanCount) { FCompactExcluding(this, spanGrid, flags, newSpanCount); }
	void Clear() { FClear(this); }

#if 0
	CompactSpanGrid();
	uint64_t GetCellCount() const;
	uint64_t GetSpanCount() const;
	uint64_t GetWidth() const;
	uint64_t GetHeight() const;
	uint64_t GetMemoryUsage() const;
	const MNM::CompactSpanGrid::Cell operator[](uint64_t _arg0_) const;
	const MNM::CompactSpanGrid::Cell GetCell(uint64_t _arg0_, uint64_t _arg1_) const;
	MNM::CompactSpanGrid::Span& GetSpan(uint64_t _arg0_);
	const MNM::CompactSpanGrid::Span& GetSpan(uint64_t _arg0_) const;
	bool GetSpanAt(uint64_t _arg0_, uint64_t _arg1_, uint64_t _arg2_, uint64_t& _arg3_) const;
#endif

#ifndef MOONCRASH
	static inline auto FGetSpanAtOv1 = PreyFunction<bool(const MNM::CompactSpanGrid* const _this, uint64_t x, uint64_t y, uint64_t top, uint64_t tolerance, uint64_t& outSpan)>(0x655470);
	static inline auto FSwap = PreyFunction<void(MNM::CompactSpanGrid* const _this, MNM::CompactSpanGrid& other)>(0x638700);
	static inline auto FBuildFrom = PreyFunction<void(MNM::CompactSpanGrid* const _this, const MNM::DynamicSpanGrid& dynGrid)>(0x638420);
	static inline auto FCompactExcluding = PreyFunction<void(MNM::CompactSpanGrid* const _this, const MNM::CompactSpanGrid& spanGrid, uint64_t flags, uint64_t newSpanCount)>(0x6385E0);
	static inline auto FClear = PreyFunction<void(MNM::CompactSpanGrid* const _this)>(0x6385C0);
#else
	static inline auto FGetSpanAtOv1 = PreyFunction<bool(const MNM::CompactSpanGrid* const _this, uint64_t x, uint64_t y, uint64_t top, uint64_t tolerance, uint64_t& outSpan)>(0x671040);
	static inline auto FSwap = PreyFunction<void(MNM::CompactSpanGrid* const _this, MNM::CompactSpanGrid& other)>(0x654260);
	static inline auto FBuildFrom = PreyFunction<void(MNM::CompactSpanGrid* const _this, const MNM::DynamicSpanGrid& dynGrid)>(0x653F80);
	static inline auto FCompactExcluding = PreyFunction<void(MNM::CompactSpanGrid* const _this, const MNM::CompactSpanGrid& spanGrid, uint64_t flags, uint64_t newSpanCount)>(0x654140);
	static inline auto FClear = PreyFunction<void(MNM::CompactSpanGrid* const _this)>(0x654120);
#endif
};


} // namespace MNM

