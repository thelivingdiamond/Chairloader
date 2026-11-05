#ifdef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ICrySizer;

// SEquipmentItem
// Header:  _unknown/SEquipmentItem.h
// Include: Prey/CryAction/EquipmentManager.h
struct SEquipmentItem
{ // Size=32 (0x20)
	string sName;
	string sType;
	string sArchetype;
	int m_count;

#if 0
	SEquipmentItem();
	SEquipmentItem(const char* _arg0_, const char* _arg1_, const char* _arg2_, const int _arg3_);
	bool operator==(const SEquipmentItem& _arg0_) const;
	bool operator<(const SEquipmentItem& _arg0_) const;
	void GetMemoryUsage(ICrySizer* _arg0_) const;
	string GetDisplayName() const;
#endif
};

#endif // MOONCRASH
