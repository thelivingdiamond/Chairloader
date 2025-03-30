#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CrySystem/PlatformOS/PlatformOS_PC.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Chairloader/SteamAPI/IChairSteamAPI.h>
#include "LocalizationPatch.h"

namespace
{

struct SLanguageIdFromSystem
{
    ELanguageID id;
    const char* epic;
    const char* steam;
    const char* windows;
};

LocalizationPatch g_Patch;
IChairSteamAPI* g_pSteamApi;

auto g_CPlatformOS_PC_InitLanguageInfo_Hook = CPlatformOS_PC::FInitLanguageInfo.MakeHook();

SLanguageIdFromSystem g_LangIDs[] = {
    { eLID_English,                 "en-US",    "english",      "en-US" },
    { eLID_French,                  "fr",       "french",       "fr-FR" },
    { eLID_Italian,                 "it",       "italian",      "it-IT" },
    { eLID_German,                  "de",       "german",       "de-DE" },
    { eLID_Spanish,                 "es-ES",    "spanish",      "es-ES" },
    { eLID_Spanish,                 "es",       nullptr,        nullptr },
    { eLID_Latin_American_Spanish,  "es-MX",    nullptr,        "es-MX" },
    { eLID_Brazilian_Portuguese,    "pt-BR",    "brazilian",    "pt-BR" },
    { eLID_Russian,                 "ru",       "russian",      "ru-RU" },
    { eLID_Polish,                  "pl",       "polish",       "pl-PL" },
    { eLID_Japanese,                "ja",       "japanese",     "ja-JP" },
    { eLID_Traditional_Chinese,     "zh-Hant",  "tchinese",     "zh-TW" },
    { eLID_Simplified_Chinese,      "zh-Hans",  "schinese",     "zh-CN" },
};

unsigned CPlatformOS_PC_InitLanguageInfo_Hook(CPlatformOS_PC* const _this, unsigned _languagesWithData)
{
    return g_Patch.InitLanguageInfo_Hook(_this, _languagesWithData);
}

} // namespace

void LocalizationPatch::InitSystem(IChairSteamAPI* pSteamApi)
{
    g_pSteamApi = pSteamApi;
    g_CPlatformOS_PC_InitLanguageInfo_Hook.SetHookFunc(&CPlatformOS_PC_InitLanguageInfo_Hook);
}

unsigned LocalizationPatch::InitLanguageInfo_Hook(CPlatformOS_PC* const _this, unsigned _languagesWithData)
{
    // Default _languagesWithData contains all languages.
    // Custom FindInstalledLanguages will actually check which ones are installed
    unsigned installedLangs = FindInstalledLanguages();

    const char* cmdLine = gEnv->pSystem->GetICmdLine()->GetCommandLine();
    ELocaleType localeType = ELocaleType::None;

    // Figure out which locale source to use
    if (strstr(cmdLine, "-epiclocale="))
    {
        // EGS locale - use original handler
        return g_CPlatformOS_PC_InitLanguageInfo_Hook.InvokeOrig(_this, _languagesWithData);
    }
    
    if (g_pSteamApi)
    {
        // Steam/Galaxy API is available. Use it.
        const char* gameLang = g_pSteamApi->GetContext().SteamApps()->GetCurrentGameLanguage();

        if (gameLang)
        {
            CryLog("Steam game language: {}", gameLang);
            _this->m_systemLanguage = gameLang;
            localeType = ELocaleType::Steam;
        }
        else
        {
            CryError("Failed to get game language from Steam");
        }
    }
    else
    {
        // Use Windows language (like in MS Store version)
        wchar_t buf[LOCALE_NAME_MAX_LENGTH];

        if (GetUserDefaultLocaleName(buf, std::size(buf)) > 0)
        {
            Unicode::Convert(_this->m_systemLanguage, buf);
            CryLog("Windows system language: {}", _this->m_systemLanguage);
            localeType = ELocaleType::Windows;
        }
        else
        {
            CryError("Failed to get system language from Windows");
        }
    }

    // Convert locale to Language ID
    if (localeType != ELocaleType::None)
    {
        _this->m_languageId = GetLanguageIdFromLocale(_this->m_systemLanguage, localeType);

        if (_this->m_languageId == ePILID_MAX_OR_INVALID)
        {
            CryLog("Unknown locale name {}. Using English", _this->m_systemLanguage);
            _this->m_languageId = eLID_English;
            _this->m_systemLanguage = "en";
        }
    }
    else
    {
        CryWarning("Defaulting game language to English");
        _this->m_languageId = eLID_English;
        _this->m_systemLanguage = "en";
    }

    // See if the language is supported
    if ((installedLangs & (1 << _this->m_languageId)) == 0)
    {
        CryWarning("Language {} ({}) is not installed. Defaulting to English", _this->m_systemLanguage, (int)_this->m_languageId);
        _this->m_languageId = eLID_English;
        _this->m_systemLanguage = "en";
    }

    _this->m_supportedLanguages = installedLangs;
    return installedLangs;
}

unsigned LocalizationPatch::FindInstalledLanguages()
{
    ILocalizationManager* pLocMan = gEnv->pSystem->GetLocalizationManager();
    unsigned installedLangs = 1 << eLID_English; // Assume English is always available
    fs::path locPath = fs::u8path(gEnv->pCryPak->GetLocalizationFolder());

    for (int i = 0; i < ePILID_MAX_OR_INVALID; i++)
    {
        // List of files to check
        const char* langName = pLocMan->LanguageNameFromID((ELanguageID)i);
        std::string filesToCheck[] = {
            // Not checking for audio since not all localizations have it
            // fmt::format("{}.pak", langName),        // Audio
            fmt::format("{}_xml.pak", langName),    // Text
        };

        // Check that all files exist
        bool allExists = true;

        for (const std::string& pakName : filesToCheck)
        {
            fs::path path = locPath / fs::u8path(pakName);
            if (!fs::exists(path))
            {
                allExists = false;
                break;
            }
        }

        if (allExists)
        {
            installedLangs |= 1 << i;
        }
    }

    return installedLangs;
}

ELanguageID LocalizationPatch::GetLanguageIdFromLocale(const char* locale, ELocaleType localeType)
{
    for (const SLanguageIdFromSystem& i : g_LangIDs)
    {
        const char* currentLocale = nullptr;

        switch (localeType)
        {
        case ELocaleType::Epic: currentLocale = i.epic; break;
        case ELocaleType::Steam: currentLocale = i.steam; break;
        case ELocaleType::Windows: currentLocale = i.windows; break;
        }

        if (!currentLocale)
            continue;

        if (!strcmp(locale, currentLocale))
            return i.id;
    }

    return ePILID_MAX_OR_INVALID;
}
