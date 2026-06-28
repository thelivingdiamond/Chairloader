// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/gameeffect/
#include "ArkNpcGameEffect.h"
static_assert(sizeof(ArkNpcGameEffect) == 8);

#include "ArkNpcGameEffectManager.h"
static_assert(sizeof(ArkNpcGameEffectManager) == 136);
static_assert(sizeof(ArkNpcGameEffectManager::AttachedGameEffect) == 40);

#include "ArkNpcNullGameEffect.h"
static_assert(sizeof(ArkNpcNullGameEffect) == 8);

#include "arknpcgameeffectreflections.h"
static_assert(sizeof(ArkXmlTemplateDecorator<ArkNpcGameEffect_Corrupted>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_Armored>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_Frenzy>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_Gloo>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_Interference>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_MindControl>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_OnFire>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_PlayerProximityPackage>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_Stun>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_ThermalAura>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcGameEffect_WeakPoint>) == 1);

#include "arknpcgameeffecttemplate.h"
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Armored,ArkNpcGameEffectInstance_Armored>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Blind,ArkNpcGameEffectInstance_Blind>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlCorruptedNpcs,ArkNpcGameEffectInstance_ControlCorruptedNpcs>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_ControlTurrets,ArkNpcGameEffectInstance_ControlTurrets>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_CorpseHunger,ArkNpcGameEffectInstance_CorpseHunger>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Corrupted,ArkNpcGameEffectInstance_Corrupted>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Disintegration,ArkNpcGameEffectInstance_Disintegration>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_DoppelgangerLink,ArkNpcGameEffectInstance_DoppelgangerLink>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_EnergizeAura,ArkNpcGameEffectInstance_EnergizeAura>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Energized,ArkNpcGameEffectInstance_Energized>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_EthericFog,ArkNpcGameEffectInstance_EthericFog>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_ExcreteCystoids,ArkNpcGameEffectInstance_ExcreteCystoids>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_FastTurnOnDamage,ArkNpcGameEffectInstance_FastTurnOnDamage>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Feared,ArkNpcGameEffectInstance_Feared>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Frenzy,ArkNpcGameEffectInstance_Frenzy>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Gloo,ArkNpcGameEffectInstance_Gloo>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Hacked,ArkNpcGameEffectInstance_Hacked>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_HitReactionMaterialAnimation,ArkNpcGameEffectInstance_HitReactionMaterialAnimation>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_HostileToDamage,ArkNpcGameEffectInstance_HostileToDamage>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Interference,ArkNpcGameEffectInstance_Interference>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_MindControl,ArkNpcGameEffectInstance_MindControl>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_NightmareEtherFormDamageAura,ArkNpcGameEffectInstance_NightmareEtherFormDamageAura>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_OnFire,ArkNpcGameEffectInstance_OnFire>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_OperatorArmsRetracted,ArkNpcGameEffectInstance_OperatorArmsRetracted>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Pet,ArkNpcGameEffectInstance_Pet>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerControlled,ArkNpcGameEffectInstance_PlayerControlled>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_PlayerProximityPackage,ArkNpcGameEffectInstance_PlayerProximityPackage>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistForceAura,ArkNpcGameEffectInstance_PoltergeistForceAura>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_PoltergeistInvisibility,ArkNpcGameEffectInstance_PoltergeistInvisibility>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_PsiSuppression,ArkNpcGameEffectInstance_PsiSuppression>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_RaiseFromCorpse,ArkNpcGameEffectInstance_RaiseFromCorpse>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_SimplePackageAura,ArkNpcGameEffectInstance_SimplePackageAura>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Stun,ArkNpcGameEffectInstance_Stun>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_TelepathShield,ArkNpcGameEffectInstance_TelepathShield>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_ThermalAura,ArkNpcGameEffectInstance_ThermalAura>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_Underground,ArkNpcGameEffectInstance_Underground>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeakPoint,ArkNpcGameEffectInstance_WeakPoint>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcGameEffect_WeaverShield,ArkNpcGameEffectInstance_WeaverShield>) == 8);
static_assert(sizeof(ArkNpcGameEffectTemplate<ArkNpcNullGameEffect,ArkNpcGameEffectInstance>) == 8);
#endif // MOONCRASH
