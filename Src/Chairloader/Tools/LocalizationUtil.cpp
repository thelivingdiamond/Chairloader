//
// Created by theli on 12/26/2022.
//

#include <Prey/CryCore/Platform/IPlatformOS.h>
#include <Prey/CrySystem/ILocalizationManager.h>
#include <Prey/CrySystem/LocalizedStringManager.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include "LocalizationUtil.h"

LocalizationUtil::LocalizationUtil() {
    m_InstalledAudioLangs = FindInstalledAudioLanguages();
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

            auto locman = static_cast<CLocalizedStringsManager*>(gEnv->pSystem->GetLocalizationManager());
            ShowLanguageComboBox("Language", "g_language", &m_CurrentTextItem, locman->m_availableLocalizations);

            // yellow text
            ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.9f, 0.3f, 1.0f));
            ImGui::Text("Changing the audio language while in game may have unintended consequences. \nIt is recommended to set the audio language before loading into a level.");
            ImGui::PopStyleColor();

            ShowLanguageComboBox("Audio Language", "g_languageAudio", &m_CurrentAudioItem, m_InstalledAudioLangs);
        }
        ImGui::End();
    }
}

void LocalizationUtil::SetLangCVar(const char* cvarName, int selectedItemIdx)
{
    selectedItemIdx = std::clamp(selectedItemIdx, 0, (int)(std::size(items_internal) - 1));
    ELanguageID newLangId;

    if (selectedItemIdx == DEFAULT_LANG_IDX) {
        newLangId = gEnv->pSystem->GetPlatformOS()->GetSystemLanguageID();
    }
    else {
        newLangId = (ELanguageID)(selectedItemIdx - 1);
    }

    const char* language = gEnv->pSystem->GetLocalizationManager()->LanguageNameFromID(newLangId);
    gEnv->pConsole->GetCVar(cvarName)->Set(language);
}

void LocalizationUtil::ShowLanguageComboBox(const char* label, const char* cvarName, int* pSelectedItemIdx, unsigned availLangs)
{
    // Clamp the value
    *pSelectedItemIdx = std::clamp(*pSelectedItemIdx, 0, (int)(std::size(items_internal) - 1));

    ELanguageID systemLangId = gEnv->pSystem->GetPlatformOS()->GetSystemLanguageID();
    std::string defaultLangString = fmt::format("System Language ({})", items[(int)systemLangId + 1]);
    items[0] = defaultLangString.c_str();

    if (ImGui::BeginCombo(label, items[*pSelectedItemIdx]))
    {
        for (int i = 0; i < (int)std::size(items_internal); i++)
        {
            ImGui::PushID(i);
            bool isAvailable = i == DEFAULT_LANG_IDX
                ? true
                : availLangs & (1 << (i - 1));

            if (ImGui::Selectable(items[i], i == *pSelectedItemIdx, isAvailable ? 0 : ImGuiSelectableFlags_Disabled))
            {
                *pSelectedItemIdx = i;
                SetLangCVar(cvarName, i);
            }

            ImGui::PopID();
        }

        ImGui::EndCombo();
    }

    // Points to temporary defaultLangString. Reset to nullptr to avoid dangling.
    items[0] = nullptr;
}

unsigned LocalizationUtil::FindInstalledAudioLanguages()
{
    ILocalizationManager* pLocMan = gEnv->pSystem->GetLocalizationManager();
    unsigned installedLangs = 0;
    fs::path locPath = fs::u8path(gEnv->pCryPak->GetLocalizationFolder());

    for (int i = 0; i < ePILID_MAX_OR_INVALID; i++)
    {
        const char* langName = pLocMan->LanguageNameFromID((ELanguageID)i);
        fs::path pakPath = locPath / fmt::format("{}.pak", langName);

        if (fs::exists(pakPath))
        {
            installedLangs |= 1 << i;
        }
    }

    return installedLangs;
}

void LocalizationUtil::InitGame() {
    REGISTER_CVAR2("ch_textLanguage", &m_CurrentTextItem, 0, VF_DUMPTOCHAIR, "Storing the text language for the localization utility, do not change this value!");
    REGISTER_CVAR2("ch_audioLanguage", &m_CurrentAudioItem, 0, VF_DUMPTOCHAIR, "Storing the audio language for the localization utility, do not change this value!");
    
    // set the language
    // But if the user didn't set one explicitly, don't set it at all
    if (m_CurrentTextItem != DEFAULT_LANG_IDX)
        SetLangCVar("g_language", m_CurrentTextItem);
    
    if (m_CurrentTextItem != DEFAULT_LANG_IDX)
        SetLangCVar("g_languageAudio", m_CurrentAudioItem);
}
