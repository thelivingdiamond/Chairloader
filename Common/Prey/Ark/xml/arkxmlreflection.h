// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <Prey/CrySystem/XML/IXml.h>

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkCorruptedExplodeFsm_Config>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkCorruptedExplodeFsm_Config>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x13806E0);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkHumanCombatFsmConfig>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkHumanCombatFsmConfig>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x1104B20);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkNpcEmboldenParams>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkNpcEmboldenParams>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x1104D40);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkOperatorSwipeFsm_Config>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkOperatorSwipeFsm_Config>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x13808D0);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkPhantomCombatFsmConfig>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkPhantomCombatFsmConfig>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x1104FD0);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkPoltergeistCombatFsmConfig>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkPoltergeistCombatFsmConfig>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x11051D0);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkSearchFsmConfig>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkSearchFsmConfig>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x11054A0);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkTelepathGroupCombatFsmConfig>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkTelepathGroupCombatFsmConfig>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x11056C0);
};

// ArkXmlReflectionElementPropertyTemplateGenerator_<ArkWeaverEscapeFsmConfig>
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlReflectionElementPropertyTemplateGenerator_<ArkWeaverEscapeFsmConfig>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode, const char* const _pPropertyName) { return FGenerateTemplate(_templateNode, _pPropertyName); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode, const char* const _pPropertyName)>(0x1105940);
};

// ArkXmlReflectionTemplateGenerator_
// Header:  Prey/Ark/xml/arkxmlreflection.h
class ArkXmlReflectionTemplateGenerator_
{ // Size=8 (0x8)
public:
	XmlNodeRef m_parentTemplateNode;

	ArkXmlReflectionTemplateGenerator_(XmlNodeRef node, const char* name);

#if 0
	XmlNodeRef GetTemplate();
#endif

	static inline auto FArkXmlReflectionTemplateGenerator_Ov2 = PreyFunction<void(ArkXmlReflectionTemplateGenerator_* const _this, XmlNodeRef node, const char* name)>(0x1101600);
};

// ArkXmlTemplateGenerator<std::vector<ArkBlackListItem,std::allocator<ArkBlackListItem> > >
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlTemplateGenerator<std::vector<ArkBlackListItem,std::allocator<ArkBlackListItem> > >
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode) { return FGenerateTemplate(_templateNode); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode)>(0x1344F90);
};

// ArkXmlTemplateGenerator<std::vector<CryStringT<char>,std::allocator<CryStringT<char> > > >
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlTemplateGenerator<std::vector<CryStringT<char>,std::allocator<CryStringT<char> > > >
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode) { return FGenerateTemplate(_templateNode); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode)>(0x1106720);
};

// ArkXmlTemplateGenerator<std::vector<unsigned __int64,std::allocator<unsigned __int64> > >
// Header:  Prey/Ark/xml/arkxmlreflection.h
struct ArkXmlTemplateGenerator<std::vector<unsigned __int64,std::allocator<unsigned __int64> > >
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _templateNode) { return FGenerateTemplate(_templateNode); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode)>(0x1106B00);
};
#endif // MOONCRASH
