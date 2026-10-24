// Header test file for path Prey/GameDll/ark/player/pda/

#include "ArkAudioLogComponent.h"
static_assert(sizeof(ArkAudioLogComponent) == 128);
static_assert(sizeof(ArkAudioLogComponent::UnheardAudioLog) == 16);

#include "ArkEmailComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkEmailComponent) == 184);
#else
static_assert(sizeof(ArkEmailComponent) == 232);
#endif
static_assert(sizeof(ArkEmailComponent::SEmailUIContent) == 48);

#include "ArkEquipmentModComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkEquipmentModComponent) == 64);
#endif

#include "ArkFabricationPlanComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkFabricationPlanComponent) == 24);
#else
static_assert(sizeof(ArkFabricationPlanComponent) == 40);
#endif
static_assert(sizeof(ArkFabricationPlanComponent::Data) == 40);

#include "ArkKeyCardComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkKeyCardComponent) == 24);
#else
static_assert(sizeof(ArkKeyCardComponent) == 48);
#endif

#include "ArkKeyCodeComponent.h"
static_assert(sizeof(ArkKeyCodeEntry) == 24);
static_assert(sizeof(ArkKeyCodeComponent) == 24);

#include "ArkLiveTranscribeComponent.h"

#include "ArkLocationComponent.h"
static_assert(sizeof(ArkLocationComponent) == 48);
static_assert(sizeof(ArkLocationComponent::ArkLocationCooldown) == 16);

#include "ArkLoreComponent.h"
static_assert(sizeof(ArkLoreComponent) == 24);
static_assert(sizeof(ArkLoreComponent::LoreData) == 16);

#include "ArkNoteComponent.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkNoteComponent) == 32);
#else
static_assert(sizeof(ArkNoteComponent) == 56);
#endif

#include "ArkRosterComponent.h"
static_assert(sizeof(CArkCharacterStatus) == 24);
#ifndef MOONCRASH
static_assert(sizeof(ArkRosterComponent) == 104);
#else
static_assert(sizeof(ArkRosterComponent) == 128);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkChipsetComponent.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkChipsetComponent) == 352);
static_assert(sizeof(ArkChipsetComponent::InstalledChipset) == 32);
#endif
#endif
