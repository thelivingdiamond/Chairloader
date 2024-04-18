#pragma once
#include <Prey/CrySystem/ILocalizationManager.h>

struct IChairSteamAPI;
class CPlatformOS_PC;

class LocalizationPatch
{
public:
    static void InitSystem(IChairSteamAPI* pSteamApi);

    static unsigned InitLanguageInfo_Hook(CPlatformOS_PC* const _this, unsigned _languagesWithData);

private:
    enum class ELocaleType
    {
        None,
        Epic,
        Steam,
        Windows,
    };

    static ELanguageID GetLanguageIdFromLocale(const char* locale, ELocaleType localeType);
};
