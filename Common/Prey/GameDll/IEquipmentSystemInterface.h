#ifndef MOONCRASH
// Header file automatically created from a PDB.
#pragma once

class ICrySizer;
class XmlNodeRef;

// IEquipmentSystemInterface
// Header:  _unknown/IEquipmentSystemInterface.h
// Include: Prey/CrySandbox/IEditorGame.h
struct IEquipmentSystemInterface
{ // Size=8 (0x8)
	// IEquipmentSystemInterface::SEquipmentItem
	// Header:  _unknown/IEquipmentSystemInterface.h
	struct SEquipmentItem
	{ // Size=32 (0x20)
		string sName;
		string sType;
		string sArchetype;
		int m_count;

	#if 0
		SEquipmentItem();
		SEquipmentItem(const char* _arg0_, const char* _arg1_, const char* _arg2_, const int _arg3_);
		bool operator==(const IEquipmentSystemInterface::SEquipmentItem& _arg0_) const;
		bool operator<(const IEquipmentSystemInterface::SEquipmentItem& _arg0_) const;
		void GetMemoryUsage(ICrySizer* _arg0_) const;
		string GetDisplayName() const;
	#endif
	};

	virtual ~IEquipmentSystemInterface();
	virtual std::vector<IEquipmentSystemInterface::SEquipmentItem> GetAvailableItems() const = 0;
	virtual void DeleteAllEquipmentPacks() = 0;
	virtual bool LoadEquipmentPack(const XmlNodeRef& _arg0_) = 0;
};

#endif // !MOONCRASH
