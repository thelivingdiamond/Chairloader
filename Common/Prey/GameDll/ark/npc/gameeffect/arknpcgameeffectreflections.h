// Header file automatically created from a PDB.
#pragma once
#include <Prey/CrySystem/XML/IXml.h>

class ArkNpcGameEffect_Armored;
class ArkNpcGameEffect_Corrupted;
class ArkNpcGameEffect_Energized;
class ArkNpcGameEffect_Frenzy;
class ArkNpcGameEffect_Gloo;
class ArkNpcGameEffect_Interference;
class ArkNpcGameEffect_MindControl;
class ArkNpcGameEffect_OnFire;
class ArkNpcGameEffect_PlayerProximityPackage;
class ArkNpcGameEffect_Stun;
class ArkNpcGameEffect_ThermalAura;
class ArkNpcGameEffect_WeakPoint;

// Primary templates (Prey/Ark/xml/arkxmlreflection.h); only explicit specializations are dumped.
template<typename T> struct ArkXmlTemplateDecorator;
template<typename T> struct ArkXmlTemplateGenerator;

// ArkXmlTemplateDecorator<ArkNpcGameEffect_Corrupted>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateDecorator<ArkNpcGameEffect_Corrupted>
{ // Size=1 (0x1)
	static XmlNodeRef DecorateTemplate(const XmlNodeRef& _templateNode) { return FDecorateTemplate(_templateNode); }

#ifndef MOONCRASH
	static inline auto FDecorateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode)>(0x129D990);
#else
	static inline auto FDecorateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _templateNode)>(0x13445F0);
#endif
};

#ifdef MOONCRASH
// ArkXmlTemplateGenerator<ArkNpcGameEffect_Armored>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_Armored>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1345260);
};
#endif

#ifndef MOONCRASH
// ArkXmlTemplateGenerator<ArkNpcGameEffect_Energized>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_Energized>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129E5C0);
};
#endif

#ifdef MOONCRASH
// ArkXmlTemplateGenerator<ArkNpcGameEffect_Frenzy>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_Frenzy>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1345450);
};
#endif

// ArkXmlTemplateGenerator<ArkNpcGameEffect_Gloo>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_Gloo>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

#ifndef MOONCRASH
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129E8F0);
#else
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1345730);
#endif
};

// ArkXmlTemplateGenerator<ArkNpcGameEffect_Interference>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_Interference>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

#ifndef MOONCRASH
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129EC90);
#else
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1345B10);
#endif
};

// ArkXmlTemplateGenerator<ArkNpcGameEffect_MindControl>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_MindControl>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

#ifndef MOONCRASH
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129EEB0);
#else
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1345D30);
#endif
};

// ArkXmlTemplateGenerator<ArkNpcGameEffect_OnFire>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_OnFire>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

#ifndef MOONCRASH
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129F170);
#else
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1345FF0);
#endif
};

// ArkXmlTemplateGenerator<ArkNpcGameEffect_PlayerProximityPackage>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_PlayerProximityPackage>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

#ifndef MOONCRASH
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129F530);
#else
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x13463B0);
#endif
};

// ArkXmlTemplateGenerator<ArkNpcGameEffect_Stun>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_Stun>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

#ifndef MOONCRASH
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x129F740);
#else
	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x13465C0);
#endif
};

#ifdef MOONCRASH
// ArkXmlTemplateGenerator<ArkNpcGameEffect_ThermalAura>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_ThermalAura>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1346950);
};
#endif

#ifdef MOONCRASH
// ArkXmlTemplateGenerator<ArkNpcGameEffect_WeakPoint>
// Header:  Prey/GameDll/ark/npc/gameeffect/arknpcgameeffectreflections.h
template<>
struct ArkXmlTemplateGenerator<ArkNpcGameEffect_WeakPoint>
{ // Size=1 (0x1)
	static XmlNodeRef GenerateTemplate(const XmlNodeRef& _parentTemplate) { return FGenerateTemplate(_parentTemplate); }

	static inline auto FGenerateTemplate = PreyFunction<XmlNodeRef(const XmlNodeRef& _parentTemplate)>(0x1346C60);
};
#endif
