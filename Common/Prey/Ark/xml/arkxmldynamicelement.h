// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once

class ArkNpcAbility;
class ArkNpcAbilityPrereq;
class ArkNpcAbilityPrereqModifier;
class ArkNpcGameEffect;
class XmlNodeRef;

// ArkXmlDynamicElementReader<ArkNpcAbility>
// Header:  Prey/Ark/xml/arkxmldynamicelement.h
struct ArkXmlDynamicElementReader<ArkNpcAbility>
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcAbility>& _pObject) { return FRead(_elementXmlNode, _pObject); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcAbility>& _pObject)>(0x138D830);
};

// ArkXmlDynamicElementReader<ArkNpcAbilityPrereq>
// Header:  Prey/Ark/xml/arkxmldynamicelement.h
struct ArkXmlDynamicElementReader<ArkNpcAbilityPrereq>
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcAbilityPrereq>& _pObject) { return FRead(_elementXmlNode, _pObject); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcAbilityPrereq>& _pObject)>(0x138D9F0);
};

// ArkXmlDynamicElementReader<ArkNpcAbilityPrereqModifier>
// Header:  Prey/Ark/xml/arkxmldynamicelement.h
struct ArkXmlDynamicElementReader<ArkNpcAbilityPrereqModifier>
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcAbilityPrereqModifier>& _pObject) { return FRead(_elementXmlNode, _pObject); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcAbilityPrereqModifier>& _pObject)>(0x138DBB0);
};

// ArkXmlDynamicElementReader<ArkNpcGameEffect>
// Header:  Prey/Ark/xml/arkxmldynamicelement.h
struct ArkXmlDynamicElementReader<ArkNpcGameEffect>
{ // Size=1 (0x1)
	static bool Read(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcGameEffect>& _pObject) { return FRead(_elementXmlNode, _pObject); }

	static inline auto FRead = PreyFunction<bool(const XmlNodeRef& _elementXmlNode, std::unique_ptr<ArkNpcGameEffect>& _pObject)>(0x13493A0);
};
#endif // MOONCRASH
