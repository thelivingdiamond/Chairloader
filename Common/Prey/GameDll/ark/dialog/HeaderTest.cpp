// Header test file for path Prey/GameDll/ark/dialog/

#include "ArkConversation.h"
static_assert(sizeof(ArkConversation) == 96);

#include "ArkDialogAudioManager.h"
static_assert(sizeof(ArkDialogLoader) == 56);
static_assert(sizeof(ArkDialogAudioManager) == 936);

#include "ArkDialogPlayer.h"
static_assert(sizeof(ArkDialogPlayer) == 256);

#include "ArkDialogPlayerNPC.h"
static_assert(sizeof(ArkDialogPlayerNPC) == 280);

#include "ArkDialogPlayerPA.h"
static_assert(sizeof(ArkDialogPlayerPA) == 304);

#include "ArkDialogPlayerRobotLightExtension.h"
static_assert(sizeof(ArkDialogPlayerRobotLightExtension) == 48);

#include "ArkDialogPlayerTranscribe.h"
static_assert(sizeof(ArkDialogPlayerTranscribe) == 272);

#include "ArkDialogSubtitleManager.h"
static_assert(sizeof(ArkDialogSubtitleManager) == 168);

#include "ArkGlobalFacts.h"
static_assert(sizeof(ArkGlobalFacts) == 72);

#include "arkpadialogmanager.h"
static_assert(sizeof(SSpeakerEntity) == 8);
static_assert(sizeof(CArkPADialogManager) == 2432);

#include "ArkResponse.h"
static_assert(sizeof(ArkResponse) == 72);
static_assert(sizeof(ArkResponseSet) == 24);

#include "ArkResponseManager.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkResponseManager) == 2072);
#else
static_assert(sizeof(ArkResponseManager) == 2104);
#endif
static_assert(sizeof(ArkResponseManager::QueryIterSet) == 16);

#include "ArkResponseQuery.h"
static_assert(sizeof(ArkResponseQuery) == 24);

#include "ArkResponseRule.h"
static_assert(sizeof(ArkWritebackFact) == 32);
static_assert(sizeof(ArkResponseCriterion) == 40);
static_assert(sizeof(ArkResponseRule) == 96);

#include "arkresponsetypes.h"
static_assert(sizeof(ArkResponseValue) == 16);
static_assert(sizeof(ArkResponseValue::ArkNumberValue) == 8);
static_assert(sizeof(ArkResponseFact) == 24);

#include "IArkConversation.h"
static_assert(sizeof(IArkConversation) == 8);

#include "IArkConversationListener.h"
static_assert(sizeof(IArkConversationListener) == 8);

#include "IArkDialogAudioManager.h"
static_assert(sizeof(IArkDialogAudioManager) == 8);

#include "IArkDialogAudioTriggerOwner.h"
static_assert(sizeof(IArkDialogAudioTriggerOwner) == 8);

#include "IArkDialogPlayerExtension.h"
static_assert(sizeof(IArkDialogPlayerExtension) == 8);

#include "IArkPADialogManager.h"
static_assert(sizeof(IArkPADialogManager) == 8);

#include "IArkResponseManager.h"
static_assert(sizeof(IArkResponseManager) == 8);

#include "IArkSpeaker.h"
static_assert(sizeof(IArkSpeaker) == 8);

#include "SArkRuleQuery.h"
static_assert(sizeof(SArkRuleQuery) == 40);

#include "SSubtitleAudioData.h"
static_assert(sizeof(SSubtitleAudioData) == 16);

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDialogPlayerNull.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkDialogPlayerNull) == 8);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkDialogPlayerPlayer.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkDialogPlayerPlayer) == 264);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "arkflownodedialogtrigger.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkPADialogTrigger) == 24);
static_assert(sizeof(ArkTelepathDialogTrigger) == 8);
static_assert(sizeof(ArkTranscribeDialogTrigger) == 16);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkPlayerDeathSummarizer.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkPlayerDeathSummarizer) == 264);
#endif
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkSpeakerBase.h"
static_assert(sizeof(ArkSpeakerBase) == 240);
#endif
