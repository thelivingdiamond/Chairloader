// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/ability/
#include "ArkNpcAbility.h"
static_assert(sizeof(ArkNpcAbility) == 8);

#include "ArkNpcAbilityManager.h"
static_assert(sizeof(ArkNpcAbilityManager) == 512);
static_assert(sizeof(ArkXmlElementReader<`anonymous namespace'::ArkNpcAbilityContextProfileXmlData>) == 1);
static_assert(sizeof(ArkXmlElementReader<std::vector<`anonymous namespace'::ArkNpcAbilityPrereqXmlData,std::allocator<`anonymous namespace'::ArkNpcAbilityPrereqXmlData> > >) == 1);

#include "arknpcabilityreflections.h"
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcAbility_CombatIdle>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcAbility_CorruptedEngineerFlame>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcAbility_EMPBlast>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcAbility_Fear>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcAbility_JumpAttack>) == 1);
static_assert(sizeof(ArkXmlTemplateGenerator<ArkNpcAbility_OperatorStrafeAttack>) == 1);

#include "arknpcabilitytemplate.h"
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_CallAndActivateEffectOnNpcs,ArkNpcAbilityInstance_CallAndActivateEffectOnNpcs>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_CombatIdle,ArkNpcAbilityInstance_CombatIdle>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_CorruptNpc,ArkNpcAbilityInstance_CorruptNpc>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedEngineerFlame,ArkNpcAbilityInstance_CorruptedEngineerFlame>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_CorruptedExplode,ArkNpcAbilityInstance_CorruptedExplode>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_EMPBlast,ArkNpcAbilityInstance_EMPBlast>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_Earthquake,ArkNpcAbilityInstance_Earthquake>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_EthericDoppelganger,ArkNpcAbilityInstance_EthericDoppelganger>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_Fear,ArkNpcAbilityInstance_Fear>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_Frenzy,ArkNpcAbilityInstance_Frenzy>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_GroundSlam,ArkNpcAbilityInstance_GroundSlam>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_HitReactShift,ArkNpcAbilityInstance_HitReactShift>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_JumpAttack,ArkNpcAbilityInstance_JumpAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_LaunchCystoids,ArkNpcAbilityInstance_LaunchCystoids>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_MeleeAttack,ArkNpcAbilityInstance_MeleeAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_MimicGrabAttack,ArkNpcAbilityInstance_MimicGrabAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_OperatorRamAttack,ArkNpcAbilityInstance_OperatorRamAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_OperatorScienceZap,ArkNpcAbilityInstance_OperatorScienceZap>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_OperatorStrafeAttack,ArkNpcAbilityInstance_OperatorStrafeAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_OperatorSwipeAttack,ArkNpcAbilityInstance_OperatorSwipeAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistDisarm,ArkNpcAbilityInstance_PoltergeistDisarm>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistLift,ArkNpcAbilityInstance_PoltergeistLift>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_PoltergeistThrowAttack,ArkNpcAbilityInstance_PoltergeistThrowAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_PsiAttack,ArkNpcAbilityInstance_PsiAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_Psychoshock,ArkNpcAbilityInstance_Psychoshock>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_RaisePhantomFromCorpse,ArkNpcAbilityInstance_RaisePhantomFromCorpse>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_RecycleAttack,ArkNpcAbilityInstance_RecycleAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_ReloadPistol,ArkNpcAbilityInstance_ReloadPistol>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_RepelBlast,ArkNpcAbilityInstance_RepelBlast>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_RockThrow,ArkNpcAbilityInstance_RockThrow>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_ShiftChargeAttack,ArkNpcAbilityInstance_ShiftChargeAttack>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_ShootPistol,ArkNpcAbilityInstance_ShootPistol>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_Sidestep,ArkNpcAbilityInstance_Sidestep>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_SolarFlare,ArkNpcAbilityInstance_SolarFlare>) == 8);
static_assert(sizeof(ArkNpcAbilityTemplate<ArkNpcAbility_Thermogenesis,ArkNpcAbilityInstance_Thermogenesis>) == 8);

#include "arkoperatorlaserhelper.h"
static_assert(sizeof(ArkLaserHelper) == 624);
#endif // MOONCRASH
