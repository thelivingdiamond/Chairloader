// Header test file for path Prey/GameDll/ark/npc/anim/

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkAnimActionAIBlink.h"
static_assert(sizeof(CArkAnimActionAIBlink) == 136);
static_assert(sizeof(CArkAnimActionAIEyeSaccade) == 128);
static_assert(sizeof(SMannequinAiBlinkUserParams) == 16);
static_assert(sizeof(SMannequinAiBlinkUserParams::FragmentIDs) == 4);
static_assert(sizeof(SMannequinAiEyeSaccadeUserParams) == 16);
static_assert(sizeof(SMannequinAiEyeSaccadeUserParams::FragmentIDs) == 4);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arkfadeclipevent.h"
static_assert(sizeof(CArkFadeProceduralClipEvent) == 72);
static_assert(sizeof(SArkFadeClipEventParams) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcanimactionblendfromragdoll.h"
static_assert(sizeof(ArkNpcAnimActionRagdollAndStandUp) == 200);
static_assert(sizeof(ArkNpcAnimActionStandUp) == 288);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcanimactions.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkNpcAnimAction) == 184);
static_assert(sizeof(ArkNpcAnimAction_ArmsRetracted) == 192);
static_assert(sizeof(ArkNpcAnimAction_Burrow) == 192);
static_assert(sizeof(ArkNpcAnimAction_DeathHitReaction) == 192);
static_assert(sizeof(ArkNpcAnimAction_DodgeWrench) == 192);
static_assert(sizeof(ArkNpcAnimAction_MeleeAttack) == 192);
static_assert(sizeof(ArkNpcAnimAction_MimicRebound) == 192);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcanimcoopactions.h"
static_assert(sizeof(CArkNpcAnimCoopAction) == 208);
static_assert(sizeof(CMimicGrabPlayerAnimAction) == 240);
static_assert(sizeof(CMimicGrabPlayerJumpAnimAction) == 200);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcbreakglassclipevent.h"
static_assert(sizeof(CArkNpcBreakGlassProceduralClipEvent) == 80);
static_assert(sizeof(SArkNpcBreakGlassClipEventParams) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcconeattackclipevent.h"
static_assert(sizeof(CArkNpcConeAttackProceduralClipEvent) == 192);
static_assert(sizeof(SArkNpcConeAttackClipEventParams) == 48);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcLookAroundClip.h"
static_assert(sizeof(CArkNpcLookAroundClip) == 464);
static_assert(sizeof(SArkNpcLookAroundParams) == 88);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcmeleeattackclipevent.h"
static_assert(sizeof(CArkNpcMeleeAttackProceduralClipEvent) == 176);
static_assert(sizeof(SArkNpcMeleeAttackClipEventParams) == 40);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcMeleeFacingClipEvent.h"
static_assert(sizeof(CArkNpcMeleeFacingClipEvent) == 328);
static_assert(sizeof(SArkNpcMeleeFacingClipEventParams) == 24);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcmultistageanimactions.h"
static_assert(sizeof(CNpcMultiStageAction) == 192);
static_assert(sizeof(CNpcMultiStageDurationAction) == 200);
static_assert(sizeof(CNpcMultiStageHitDeathReactionAction) == 208);
static_assert(sizeof(CNpcMultiStageHypnotizedAction) == 200);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcpsiattackclipevent.h"
static_assert(sizeof(CArkNpcPsiAttackProceduralClipEvent) == 56);
static_assert(sizeof(SArkNpcPsiAttackClipEventParams) == 16);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcpushobstaclesclipevent.h"
static_assert(sizeof(CArkNpcPushObstaclesProceduralClipEvent) == 96);
static_assert(sizeof(SArkNpcPushObstaclesClipEventParams) == 40);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arknpcspawnrockclipevent.h"
#ifdef MOONCRASH
static_assert(sizeof(CArkNpcSpawnRockProceduralClipEvent) == 56);
static_assert(sizeof(SArkNpcSpawnRockClipEventParams) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProcClipCorpsePose.h"
static_assert(sizeof(ArkProcClipCorpsePose) == 56);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkProceduralClip_MeleeAttack.h"
static_assert(sizeof(ArkProceduralClipParams_MeleeAttack) == 24);
static_assert(sizeof(ArkProceduralClip_MeleeAttack) == 64);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arkragdollclipevent.h"
static_assert(sizeof(CArkRagdollProceduralClipEvent) == 80);
static_assert(sizeof(SArkRagdollClipEventParams) == 24);
#endif
