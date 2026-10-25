// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/XML/IXml.h>
#include <Prey/GameDll/itemstring.h>

class ICrySizer;
struct IEntityClass;

// SAccessoryParams
// Header:  _unknown/SAccessoryParams.h
struct SAccessoryParams
{ // Size=152 (0x98)
	IEntityClass* pAccessoryClass;
	SharedString::CSharedString attach_helper;
	SharedString::CSharedString show_helper;
	SharedString::CSharedString switchToFireMode;
	SharedString::CSharedString secondaryFireMode;
	SharedString::CSharedString zoommode;
	SharedString::CSharedString zoommodeSecondary;
	SharedString::CSharedString select;
	SharedString::CSharedString select_empty;
	SharedString::CSharedString category;
	std::vector<SharedString::CSharedString> firemodes;
	std::vector<SharedString::CSharedString> disableFiremodes;
	XmlNodeRef tempAccessoryParams;
	float reloadSpeedMultiplier;
	bool exclusive;
	bool selectable;
	bool defaultAccessory;
	bool client_only;
	bool attachToOwner;
	bool enableBaseModifier;
	bool alsoAttachDefault;
	bool extendsMagazine;
	bool beginsDetached;

#if 0
	void GetMemoryUsage(ICrySizer* _arg0_) const;
#endif
};

