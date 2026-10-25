// Header test file for path Prey/GameDll/ark/attention/

#include "ArkAttentionLevelChange.h"
static_assert(sizeof(ArkAttentionLevelChange) == 28);

#include "ArkAttentionManager.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkAttentionManager) == 1200);
#else
static_assert(sizeof(ArkAttentionManager) == 1328);
#endif
static_assert(sizeof(ArkAttentionManager::TopAttentionTarget) == 16);
static_assert(sizeof(ArkAttentionManager::AttentionLevelData) == 12);
static_assert(sizeof(ArkAttentionManager::AttentionIncrease) == 8);
#ifndef MOONCRASH
static_assert(sizeof(ArkAttentionManager::HearingData) == 64);
#else
static_assert(sizeof(ArkAttentionManager::HearingData) == 72);
#endif
static_assert(sizeof(ArkAttentionManager::VisionData) == 20);
static_assert(sizeof(ArkAttentionManager::RoomData) == 80);
static_assert(sizeof(ArkAttentionManager::ProxyData) == 4);
static_assert(sizeof(ArkAttentionManager::SurpriseData) == 12);
static_assert(sizeof(ArkAttentionManager::OnDamagedData) == 4);
static_assert(sizeof(ArkAttentionManager::SimpleAttentionModel) == 4);
#ifndef MOONCRASH
static_assert(sizeof(ArkAttentionManager::ComplexAttentionModel) == 248);
#else
static_assert(sizeof(ArkAttentionManager::ComplexAttentionModel) == 288);
#endif
static_assert(sizeof(ArkAttentionManager::AttentionTargetData) == 12);
#ifndef MOONCRASH
static_assert(sizeof(ArkAttentionManager::AttentionModel) == 272);
#else
static_assert(sizeof(ArkAttentionManager::AttentionModel) == 312);
#endif
static_assert(sizeof(ArkAttentionManager::ComplexHearingInput) == 40);
static_assert(sizeof(ArkAttentionManager::ComplexVisionInput) == 16);
static_assert(sizeof(ArkAttentionManager::ComplexRoomInput) == 16);
static_assert(sizeof(ArkAttentionManager::SimpleAttentionInfo) == 8);
#ifndef MOONCRASH
static_assert(sizeof(ArkAttentionManager::ComplexAttentionInfo) == 48);
#else
static_assert(sizeof(ArkAttentionManager::ComplexAttentionInfo) == 152);
#endif
static_assert(sizeof(ArkAttentionManager::ComplexAttentionGain) == 48);
#ifndef MOONCRASH
static_assert(sizeof(ArkAttentionManager::ComplexAttentionProxyUpdate) == 32);
#else
static_assert(sizeof(ArkAttentionManager::ComplexAttentionProxyUpdate) == 40);
#endif
static_assert(sizeof(ArkAttentionManager::ComplexAttentionProxyUpdateNotification) == 16);
static_assert(sizeof(ArkAttentionManager::ComplexAttentionProxy) == 32);
static_assert(sizeof(ArkAttentionManager::ComplexAttentionSurpriseInfo) == 8);
static_assert(sizeof(ArkAttentionManager::BestAttentionTargetInfo) == 28);
#ifdef MOONCRASH
static_assert(sizeof(ArkAttentionManager::SeismicData) == 28);
static_assert(sizeof(ArkAttentionManager::ComplexSeismicInput) == 32);
static_assert(sizeof(ArkAttentionManager::LastSeismicSourceInfo) == 16);
static_assert(sizeof(ArkAttentionManager::SeismicSourceInfo) == 32);
#endif

#include "ArkAttentionTag.h"
static_assert(sizeof(ArkAttentionTag) == 8);

#include "ArkComplexAttentionObject.h"
static_assert(sizeof(ArkSimpleAttentionObject) == 8);
static_assert(sizeof(ArkComplexAttentionObject) == 8);

#include "ArkComplexHearingInput.h"
static_assert(sizeof(ArkComplexHearingInput) == 32);

#include "ArkComplexRoomInput.h"
static_assert(sizeof(ArkComplexRoomInput) == 12);

#include "ArkEtherDuplicateAttentionObject.h"
static_assert(sizeof(ArkEtherDuplicateAttentionObject) == 24);

#include "ArkInstigationManager.h"
static_assert(sizeof(ArkInstigationManager) == 176);
static_assert(sizeof(ArkInstigationManager::EventRef) == 4);
static_assert(sizeof(ArkInstigationManager::Instigation) == 16);
static_assert(sizeof(ArkInstigationManager::InstigationEvent) == 20);
static_assert(sizeof(ArkInstigationConfig) == 24);
static_assert(sizeof(ArkInstigationConfig::ArkEntitiesProperty) == 32);

#include "ArkNoiseAttentionParams.h"
static_assert(sizeof(ArkNoiseAttentionParams) == 256);

#include "ArkNpcAttentionObject.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcAttentionObject) == 32);
#else
static_assert(sizeof(ArkNpcAttentionObject) == 40);
#endif

#include "ArkPlayerMimicRigidEntityAttentionObject.h"
static_assert(sizeof(ArkPlayerMimicRigidEntityAttentionObject) == 48);

#include "ArkSimpleHearingInput.h"
static_assert(sizeof(ArkSimpleHearingInput) == 16);

#include "ArkSimpleVisionInput.h"
static_assert(sizeof(ArkSimpleVisionInput) == 8);

#include "ArkTurretAttentiveSubject.h"
static_assert(sizeof(ArkTurretAttentiveSubject) == 56);
static_assert(sizeof(ArkTurretAttentiveSubject::VisionConeSemiangles) == 12);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkNpcAttentiveSubject.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNpcAttentiveSubject) == 56);
#else
static_assert(sizeof(ArkNpcAttentiveSubject) == 64);
#endif
#endif
