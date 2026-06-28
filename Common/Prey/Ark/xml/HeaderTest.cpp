// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/Ark/xml/
#include "arkxmlattribute.h"
static_assert(sizeof(ArkXmlAttributeReader<CryStringT<char> >) == 1);

#include "arkxmldynamicelement.h"
static_assert(sizeof(ArkXmlDynamicElementReader<ArkNpcAbility>) == 1);
static_assert(sizeof(ArkXmlDynamicElementReader<ArkNpcAbilityPrereq>) == 1);
static_assert(sizeof(ArkXmlDynamicElementReader<ArkNpcAbilityPrereqModifier>) == 1);
static_assert(sizeof(ArkXmlDynamicElementReader<ArkNpcGameEffect>) == 1);

#include "arkxmlelement.h"
static_assert(sizeof(ArkXmlElementReader<std::vector<ArkBlackListItem,std::allocator<ArkBlackListItem> > >) == 1);
static_assert(sizeof(ArkXmlElementReader<std::vector<CryStringT<char>,std::allocator<CryStringT<char> > > >) == 1);
static_assert(sizeof(ArkXmlElementReader<std::vector<`anonymous namespace'::ArkNpcAbilityContextXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityContextXmlData> > >) == 1);

#include "arkxmllibrary.h"
static_assert(sizeof(ArkXmlElementReader<ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcAbility,std::default_delete<ArkNpcAbility> > > >) == 1);
static_assert(sizeof(ArkXmlElementReader<ArkLibrary<unsigned __int64,std::unique_ptr<ArkNpcGameEffect,std::default_delete<ArkNpcGameEffect> > > >) == 1);

#include "arkxmlreflection.h"
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkCorruptedExplodeFsm_Config>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkHumanCombatFsmConfig>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkNpcEmboldenParams>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkOperatorSwipeFsm_Config>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkPhantomCombatFsmConfig>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkPoltergeistCombatFsmConfig>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkSearchFsmConfig>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkTelepathGroupCombatFsmConfig>) == 1);
static_assert(sizeof(ArkXmlReflectionElementPropertyTemplateGenerator_<ArkWeaverEscapeFsmConfig>) == 1);
static_assert(sizeof(ArkXmlReflectionTemplateGenerator_) == 8);
static_assert(sizeof(ArkXmlTemplateGenerator<std::vector<ArkBlackListItem,std::allocator<ArkBlackListItem> > >) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<std::vector<CryStringT<char>,std::allocator<CryStringT<char> > > >) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<std::vector<unsigned __int64,std::allocator<unsigned __int64> > >) == 1);
#endif // MOONCRASH
