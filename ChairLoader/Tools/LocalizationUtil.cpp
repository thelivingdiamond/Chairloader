//
// Created by theli on 12/26/2022.
//

#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/CrySystem/LocalizedStringManager.h>
#include "LocalizationUtil.h"

LocalizationUtil::LocalizationUtil() {
    auto locman = (CLocalizedStringsManager*)gEnv->pSystem->GetLocalizationManager();
    // Set all localizations to be available
    //TODO: check for available languages first
    locman->m_availableLocalizations |=
            ( (1 << eLID_English)
              | (1 << eLID_French)
              | (1 << eLID_Italian)
              | (1 << eLID_German)
              | (1 << eLID_Spanish)
              | (1 << eLID_Latin_American_Spanish)
              | (1 << eLID_Brazilian_Portuguese)
              | (1 << eLID_Russian)
              | (1 << eLID_Polish)
              | (1 << eLID_Japanese)
              | (1 << eLID_Traditional_Chinese)
              | (1 << eLID_Simplified_Chinese));
}

void LocalizationUtil::drawMenu() {
    ImGui::MenuItem("Localization", nullptr, &m_bDraw);
}

void LocalizationUtil::draw() {
    //  eLID_English = 0x0,
    //	eLID_French = 0x1,
    //	eLID_Italian = 0x2,
    //	eLID_German = 0x3,
    //	eLID_Spanish = 0x4,
    //	eLID_Latin_American_Spanish = 0x5,
    //	eLID_Brazilian_Portuguese = 0x6,
    //	eLID_Russian = 0x7,
    //	eLID_Polish = 0x8,
    //	eLID_Japanese = 0x9,
    //	eLID_Traditional_Chinese = 0xA,
    //	eLID_Simplified_Chinese = 0xB,
    if(m_bDraw) {
        auto locman = (CLocalizedStringsManager *) gEnv->pSystem->GetLocalizationManager();
        // create an ImGui combo box to set the language
        if (ImGui::Begin("Localization Utility", &m_bDraw, ImGuiWindowFlags_AlwaysAutoResize)) {
            ImGui::Text("Current Language: %s", gEnv->pConsole->GetCVar("g_language")->GetString());
            ImGui::Text("Current Audio Language: %s", gEnv->pConsole->GetCVar("g_languageAudio")->GetString());
            const char *items[] = {"English", "French", "Italian", "German", "Spanish", "Latin American Spanish", "Brazilian Portuguese", "Russian", "Polish", "Japanese", "Traditional Chinese", "Simplified Chinese"};
            const char *items_internal[] = {"english", "french", "italian", "german", "spanish", "latin_american_spanish", "brazilian_portuguese", "russian", "polish", "japanese", "chineset", "chineses"};
            static int current_text_item = 0;
            if (ImGui::Combo("Language", &current_text_item, items, IM_ARRAYSIZE(items))) {
                const char* language = locman->LanguageNameFromID((ELanguageID) current_text_item);
                gEnv->pConsole->GetCVar("g_language")->Set(items_internal[current_text_item]);
            }
            static int current_audio_item = 0;
            // yellow text
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.9f, 0.3f, 1.0f));
            ImGui::Text("Changing the audio language while in game may have unintended consequences. \nIt is recommended to set the audio language before loading into a level.");
            ImGui::PopStyleColor();
            if (ImGui::Combo("Audio Language", &current_audio_item, items, IM_ARRAYSIZE(items))) {
                const char* language = locman->LanguageNameFromID((ELanguageID) current_audio_item);
                gEnv->pConsole->GetCVar("g_languageAudio")->Set(items_internal[current_audio_item]);
            }
        }
        ImGui::End();
    }
}
