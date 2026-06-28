// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ark/npc/anim/
#include "ArkAnimActionAIBlink.h"
static_assert(sizeof(CArkAnimActionAIBlink) == 136);
static_assert(sizeof(CArkAnimActionAIEyeSaccade) == 128);
static_assert(sizeof(SMannequinAiBlinkUserParams) == 16);
static_assert(sizeof(SMannequinAiBlinkUserParams::FragmentIDs) == 4);
static_assert(sizeof(SMannequinAiEyeSaccadeUserParams) == 16);
static_assert(sizeof(SMannequinAiEyeSaccadeUserParams::FragmentIDs) == 4);

#include "ArkNpcLookAroundClip.h"
static_assert(sizeof(CArkNpcLookAroundClip) == 464);
static_assert(sizeof(SArkNpcLookAroundParams) == 88);

#include "ArkNpcMeleeFacingClipEvent.h"
static_assert(sizeof(CArkNpcMeleeFacingClipEvent) == 328);
static_assert(sizeof(SArkNpcMeleeFacingClipEventParams) == 24);

#include "ArkProcClipCorpsePose.h"
static_assert(sizeof(ArkProcClipCorpsePose) == 56);

#include "ArkProceduralClip_MeleeAttack.h"
static_assert(sizeof(ArkProceduralClipParams_MeleeAttack) == 24);
static_assert(sizeof(ArkProceduralClip_MeleeAttack) == 64);

#include "arkfadeclipevent.h"
static_assert(sizeof(CArkFadeProceduralClipEvent) == 72);
static_assert(sizeof(SArkFadeClipEventParams) == 24);

#include "arknpcanimactionblendfromragdoll.h"
static_assert(sizeof(ArkNpcAnimActionRagdollAndStandUp) == 200);
static_assert(sizeof(ArkNpcAnimActionStandUp) == 288);

#include "arknpcanimactions.h"
static_assert(sizeof(ArkNpcAnimAction) == 184);
static_assert(sizeof(ArkNpcAnimAction_ArmsRetracted) == 192);
static_assert(sizeof(ArkNpcAnimAction_Burrow) == 192);
static_assert(sizeof(ArkNpcAnimAction_DeathHitReaction) == 192);
static_assert(sizeof(ArkNpcAnimAction_DodgeWrench) == 192);
static_assert(sizeof(ArkNpcAnimAction_MeleeAttack) == 192);
static_assert(sizeof(ArkNpcAnimAction_MimicRebound) == 192);

#include "arknpcanimcoopactions.h"
static_assert(sizeof(CArkNpcAnimCoopAction) == 208);
static_assert(sizeof(CMimicGrabPlayerAnimAction) == 240);
static_assert(sizeof(CMimicGrabPlayerJumpAnimAction) == 200);

#include "arknpcbreakglassclipevent.h"
static_assert(sizeof(CArkNpcBreakGlassProceduralClipEvent) == 80);
static_assert(sizeof(SArkNpcBreakGlassClipEventParams) == 24);

#include "arknpcconeattackclipevent.h"
static_assert(sizeof(CArkNpcConeAttackProceduralClipEvent) == 192);
static_assert(sizeof(SArkNpcConeAttackClipEventParams) == 48);

#include "arknpcmeleeattackclipevent.h"
static_assert(sizeof(CArkNpcMeleeAttackProceduralClipEvent) == 176);
static_assert(sizeof(SArkNpcMeleeAttackClipEventParams) == 40);

#include "arknpcmultistageanimactions.h"
static_assert(sizeof(CNpcMultiStageAction) == 192);
static_assert(sizeof(CNpcMultiStageDurationAction) == 200);
static_assert(sizeof(CNpcMultiStageHitDeathReactionAction) == 208);
static_assert(sizeof(CNpcMultiStageHypnotizedAction) == 200);

#include "arknpcpsiattackclipevent.h"
static_assert(sizeof(CArkNpcPsiAttackProceduralClipEvent) == 56);
static_assert(sizeof(SArkNpcPsiAttackClipEventParams) == 16);

#include "arknpcpushobstaclesclipevent.h"
static_assert(sizeof(CArkNpcPushObstaclesProceduralClipEvent) == 96);
static_assert(sizeof(SArkNpcPushObstaclesClipEventParams) == 40);

#include "arknpcspawnrockclipevent.h"
static_assert(sizeof(CArkNpcSpawnRockProceduralClipEvent) == 56);
static_assert(sizeof(SArkNpcSpawnRockClipEventParams) == 16);

#include "arkragdollclipevent.h"
static_assert(sizeof(CArkRagdollProceduralClipEvent) == 80);
static_assert(sizeof(SArkRagdollClipEventParams) == 24);
#endif // MOONCRASH
