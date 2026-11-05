// Header file automatically created from a PDB.
#pragma once

// FragEdge
// Header:  _unknown/FragEdge.h
struct FragEdge
{ // Size=8 (0x8)
	unsigned neighbor : 8;
	unsigned count : 8;
	unsigned reversed : 1;
	uint16_t indexa;
	uint16_t indexb;

#if 0
	FragEdge();
	FragEdge(uint16_t _arg0_, uint16_t _arg1_, unsigned _arg2_);
	uint16_t StartIndex() const;
	uint16_t EndIndex() const;
	unsigned Neighbor() const;
	bool IsUnique() const;
	void Increment();
	void MarkUnused();
	void MarkUnique();
	bool operator==(const FragEdge& _arg0_) const;
#endif
};

