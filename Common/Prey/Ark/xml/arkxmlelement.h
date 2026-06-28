// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/GameDll/ark/ArkBlackListItem.h>

class XmlNodeRef;

// ArkXmlElementReader<std::vector<ArkBlackListItem,std::allocator<ArkBlackListItem> > >
// Header:  Prey/Ark/xml/arkxmlelement.h
struct ArkXmlElementReader<std::vector<ArkBlackListItem,std::allocator<ArkBlackListItem> > >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _vectorXmlNode, std::vector<ArkBlackListItem>& _value) { return FRead(_vectorXmlNode, _value); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _vectorXmlNode, std::vector<ArkBlackListItem>& _value)>(0x1349830);
};

// ArkXmlElementReader<std::vector<CryStringT<char>,std::allocator<CryStringT<char> > > >
// Header:  Prey/Ark/xml/arkxmlelement.h
struct ArkXmlElementReader<std::vector<CryStringT<char>,std::allocator<CryStringT<char> > > >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _vectorXmlNode, std::vector<string>& _value) { return FRead(_vectorXmlNode, _value); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _vectorXmlNode, std::vector<string>& _value)>(0x110BB90);
};

// ArkXmlElementReader<std::vector<`anonymous namespace'::ArkNpcAbilityContextXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityContextXmlData> > >
// Header:  Prey/Ark/xml/arkxmlelement.h
struct ArkXmlElementReader<std::vector<`anonymous namespace'::ArkNpcAbilityContextXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityContextXmlData> > >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _vectorXmlNode, std::vector<`anonymous namespace'::ArkNpcAbilityContextXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityContextXmlData> >& _value) { return FRead(_vectorXmlNode, _value); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _vectorXmlNode, std::vector<`anonymous namespace'::ArkNpcAbilityContextXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityContextXmlData> >& _value)>(0x138E200);
};
#endif // MOONCRASH
