// Header test file for path Prey/GameDll/ark/player/pda/ArkAudioLogComponent.h
#include "ArkAudioLogComponent.h"
static_assert(sizeof(ArkAudioLogComponent) == 128);
static_assert(sizeof(ArkAudioLogComponent::UnheardAudioLog) == 16);

#include "ArkEmailComponent.h"
static_assert(sizeof(ArkEmailComponent) == 184);
static_assert(sizeof(ArkEmailComponent::SEmailUIContent) == 48);

#include "ArkEquipmentModComponent.h"
static_assert(sizeof(ArkEquipmentModComponent) == 64);

#include "ArkFabricationPlanComponent.h"
static_assert(sizeof(ArkFabricationPlanComponent) == 24);
static_assert(sizeof(ArkFabricationPlanComponent::Data) == 40);

#include "ArkKeyCardComponent.h"
static_assert(sizeof(ArkKeyCardComponent) == 24);

#include "ArkKeyCodeComponent.h"
static_assert(sizeof(ArkKeyCodeComponent) == 24);

#include "ArkLiveTranscribeComponent.h"
static_assert(sizeof(ArkLiveTranscribeComponent) == 152);

#include "ArkLocationComponent.h"
static_assert(sizeof(ArkLocationComponent) == 48);
static_assert(sizeof(ArkLocationComponent::ArkLocationCooldown) == 16);

#include "ArkLoreComponent.h"
static_assert(sizeof(ArkLoreComponent) == 24);
static_assert(sizeof(ArkLoreComponent::LoreData) == 16);

#include "ArkNoteComponent.h"
static_assert(sizeof(ArkNoteComponent) == 32);

#include "ArkRosterComponent.h"
static_assert(sizeof(ArkRosterComponent) == 104);
static_assert(sizeof(CArkCharacterStatus) == 24);
