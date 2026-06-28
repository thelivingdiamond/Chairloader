// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once

class XmlNodeRef;

// ArkXmlAttributeReader<CryStringT<char> >
// Header:  Prey/Ark/xml/arkxmlattribute.h
struct ArkXmlAttributeReader<CryStringT<char> >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _xmlNode, const char* const _pAttributeName, string& _value) { return FRead(_xmlNode, _pAttributeName, _value); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _xmlNode, const char* const _pAttributeName, string& _value)>(0x110BAD0);
};
#endif // MOONCRASH
