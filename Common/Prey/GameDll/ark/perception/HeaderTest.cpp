// Header test file for path Prey/GameDll/ark/perception/ArkAttentiveSubject.h
#include "ArkAttentiveSubject.h"
static_assert(sizeof(ArkAttentiveSubject) == 8);

#include "ArkAuralPerceivable.h"
static_assert(sizeof(ArkAuralPerceivable) == 8);

#include "ArkAuralPerceptionManager.h"
static_assert(sizeof(ArkAuralPerceptionManager) == 392);
static_assert(sizeof(ArkAuralPerceptionManager::Noise) == 56);
static_assert(sizeof(ArkAuralPerceptionManager::RepeatingNoise) == 72);
static_assert(sizeof(ArkAuralPerceptionManager::PerceiverInfo) == 16);
static_assert(sizeof(ArkAuralPerceptionManager::PerceivableInfo) == 2);
static_assert(sizeof(ArkAuralPerceptionManager::PerceivedNoise) == 24);

#include "ArkComplexAuralPerceptionInfo.h"
static_assert(sizeof(ArkComplexAuralPerceptionInfo) == 48);

#include "ArkComplexRoomPerceivable.h"
static_assert(sizeof(ArkComplexRoomPerceivable) == 8);

#include "ArkComplexRoomPerceptionInfo.h"
static_assert(sizeof(ArkComplexRoomPerceptionInfo) == 12);

#include "ArkComplexVisualPerceivable.h"
static_assert(sizeof(ArkComplexVisualPerceivable) == 8);

#include "ArkComplexVisualPerceptionInfo.h"
static_assert(sizeof(ArkComplexVisualPerceptionInfo) == 8);

#include "ArkGameNoise.h"
static_assert(sizeof(ArkGameNoise::Params) == 16);

#include "ArkGameNoiseInfo.h"
static_assert(sizeof(ArkGameNoiseInfo) == 24);

#include "ArkRoomPerceptionManager.h"
static_assert(sizeof(ArkRoomPerceptionManager) == 408);
static_assert(sizeof(ArkRoomPerceptionManager::RoomPerceptionModel) == 16);
static_assert(sizeof(ArkRoomPerceptionManager::PerceiverData) == 80);

#include "ArkSimpleAuralPerceptionInfo.h"
static_assert(sizeof(ArkSimpleAuralPerceptionInfo) == 32);

#include "ArkSimpleVisualPerceivable.h"
static_assert(sizeof(ArkSimpleVisualPerceivable) == 8);

#include "ArkVisualPerceivable.h"
static_assert(sizeof(ArkVisualPerceivable) == 8);

#include "arkvisualperceiver.h"
static_assert(sizeof(ArkVisualPerceiverVisionParams) == 60);

#include "ArkVisualPerceptionManager.h"
static_assert(sizeof(ArkVisualPerceptionManager) == 1800);
static_assert(sizeof(ArkVisualPerceptionManager::VisionConeDefinition) == 44);
static_assert(sizeof(ArkVisualPerceptionManager::VisionConeProperties) == 100);
static_assert(sizeof(ArkVisualPerceptionManager::VisionConeAabb) == 12);
static_assert(sizeof(ArkVisualPerceptionManager::BoundsEndpoint) == 8);
static_assert(sizeof(ArkVisualPerceptionManager::PerceiverPerceivableIndexPair) == 16);
static_assert(sizeof(ArkVisualPerceptionManager::RemovedPerceivable) == 16);
static_assert(sizeof(ArkVisualPerceptionManager::PerceiverPerceivableIndexPairHash) == 1);
static_assert(sizeof(ArkVisualPerceptionManager::SimplePerceivableWorldPoints) == 12);
static_assert(sizeof(ArkVisualPerceptionManager::ComplexPerceivableWorldPoints) == 60);
static_assert(sizeof(ArkVisualPerceptionManager::SimpleLineOfSightCheckImpl) == 1);
static_assert(sizeof(ArkVisualPerceptionManager::?$LineOfSightCheckImpl@VSimpleLineOfSightCheckImpl@ArkVisualPerceptionManager@@) == 16);
static_assert(sizeof(ArkVisualPerceptionManager::ComplexLineOfSightCheckImplBase) == 1);
static_assert(sizeof(ArkVisualPerceptionManager::ComplexAnyLineOfSightCheckImpl) == 1);
static_assert(sizeof(ArkVisualPerceptionManager::?$LineOfSightCheckImpl@VComplexAnyLineOfSightCheckImpl@ArkVisualPerceptionManager@@) == 16);
static_assert(sizeof(ArkVisualPerceptionManager::ComplexAcuteLineOfSightCheckImpl) == 1);
static_assert(sizeof(ArkVisualPerceptionManager::?$LineOfSightCheckImpl@VComplexAcuteLineOfSightCheckImpl@ArkVisualPerceptionManager@@) == 16);
static_assert(sizeof(ArkVisualPerceptionManager::ComplexAllLineOfSightCheckImpl) == 1);
static_assert(sizeof(ArkVisualPerceptionManager::?$LineOfSightCheckImpl@VComplexAllLineOfSightCheckImpl@ArkVisualPerceptionManager@@) == 16);
static_assert(sizeof(ArkVisualPerceptionManager::ComplexLineOfSightChecks) == 1832);
