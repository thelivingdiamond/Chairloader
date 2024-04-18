//
// Created by theli on 12/26/2022.
//

#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/CrySystem/LocalizedStringManager.h>
#include "LocalizationUtil.h"

LocalizationUtil::LocalizationUtil() {
    InitGame();
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
            ImGui::Text("This is for in-game localization only.\nWhile we would love to offer multiple languages for chairloader, we don't have the people needed to translate it.");
            ImGui::Text("Current Language: %s", gEnv->pConsole->GetCVar("g_language")->GetString());
            ImGui::Text("Current Audio Language: %s", gEnv->pConsole->GetCVar("g_languageAudio")->GetString());
            // check that the index is within bounds
            if(m_CurrentTextItem < 0 || m_CurrentTextItem >= items.size()) {
                m_CurrentTextItem = 0;
                CryError("Invalid language index");
            }
            if (ImGui::Combo("Language", &m_CurrentTextItem, items.data(), items.size())) {
                const char* language = locman->LanguageNameFromID((ELanguageID) m_CurrentTextItem);
                gEnv->pConsole->GetCVar("g_language")->Set(items_internal[m_CurrentTextItem]);
            }
            // check that the index is within bounds
            if(m_CurrentAudioItem < 0 || m_CurrentAudioItem >= items.size()) {
                m_CurrentAudioItem = 0;
                CryError("Invalid audio language index");
            }
            // yellow text
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.9f, 0.3f, 1.0f));
            ImGui::Text("Changing the audio language while in game may have unintended consequences. \nIt is recommended to set the audio language before loading into a level.");
            ImGui::PopStyleColor();
            if (ImGui::Combo("Audio Language", &m_CurrentAudioItem, items.data(), items.size())) {
                const char* language = locman->LanguageNameFromID((ELanguageID) m_CurrentAudioItem);
                gEnv->pConsole->GetCVar("g_languageAudio")->Set(items_internal[m_CurrentAudioItem]);
            }
        }
        ImGui::End();
    }
}

void LocalizationUtil::InitGame() {
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

    REGISTER_CVAR2("ch_textLanguage", &m_CurrentTextItem, 0, VF_DUMPTOCHAIR, "Storing the text language for the localization utility, do not change this value!");
    REGISTER_CVAR2("ch_audioLanguage", &m_CurrentAudioItem, 0, VF_DUMPTOCHAIR, "Storing the audio language for the localization utility, do not change this value!");
    // set the language
    // DISABLED 2024-04-18: Interferes with new LocalizationPatch that uses language from Steam
    // gEnv->pConsole->GetCVar("g_language")->Set(items_internal[m_CurrentTextItem]);
    // gEnv->pConsole->GetCVar("g_languageAudio")->Set(items_internal[m_CurrentAudioItem]);
}
