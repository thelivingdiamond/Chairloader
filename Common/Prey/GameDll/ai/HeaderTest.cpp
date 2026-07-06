// Auto-merged (DLC-only): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifdef MOONCRASH
// Header test file for path Prey/GameDll/ai/
#include "AICorpse.h"
static_assert(sizeof(CAICorpse) == 136);
static_assert(sizeof(CAICorpse::AttachedItem) == 24);
static_assert(sizeof(CAICorpseManager) == 32);
static_assert(sizeof(CAICorpseManager::CorpseInfo) == 8);
static_assert(sizeof(CAICorpseManager::SCorpseParameters) == 4);

#include "AdvantagePointOccupancyControl.h"
static_assert(sizeof(CAdvantagePointOccupancyControl) == 16);

#include "DeathManager.h"
static_assert(sizeof(GameAI::DeathManager) == 64);

#include "GameAISystem.h"
static_assert(sizeof(CGameAISystem) == 64);

#include "RangeModule.h"
static_assert(sizeof(RangeContainer) == 32);
static_assert(sizeof(RangeContainer::Range) == 32);
static_assert(sizeof(RangeModule) == 56);

#include "ScriptBind_GameAI.h"
static_assert(sizeof(CScriptBind_GameAI) == 120);

#include "StalkerModule.h"
static_assert(sizeof(StalkerModule) == 56);

#include "TacticalPointLanguageExtender.h"
static_assert(sizeof(CTacticalPointLanguageExtender) == 16);

#include "gameaihelpers.h"
static_assert(sizeof(AIModule<HazardSystem::HazardModule,HazardSystem::HazardModuleInstance,16,8>) == 56);
static_assert(sizeof(AIModule<RadioChatterModule,RadioChatterInstance,12,1>) == 56);
static_assert(sizeof(AIModule<RangeModule,RangeContainer,16,8>) == 56);
static_assert(sizeof(AIModule<StalkerModule,StalkerInstance,4,4>) == 56);
static_assert(sizeof(AIModuleWithInstanceUpdate<RangeModule,RangeContainer,16,8>) == 56);
static_assert(sizeof(AIModuleWithInstanceUpdate<StalkerModule,StalkerInstance,4,4>) == 56);
#endif // MOONCRASH
