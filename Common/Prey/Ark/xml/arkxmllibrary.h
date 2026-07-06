// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/ArkCommon/arklibrary.h>

class XmlNodeRef;

// ArkXmlElementReader<ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > > >
// Header:  Prey/Ark/xml/arkxmllibrary.h
struct ArkXmlElementReader<ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > > >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >& _library) { return FRead(_elementXmlNode, _library); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > >& _library)>(0x138DF30);
};

// ArkXmlElementReader<ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > > >
// Header:  Prey/Ark/xml/arkxmllibrary.h
struct ArkXmlElementReader<ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > > >
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >& _library) { return FRead(_elementXmlNode, _library); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > >& _library)>(0x1349560);
};
#endif // MOONCRASH
