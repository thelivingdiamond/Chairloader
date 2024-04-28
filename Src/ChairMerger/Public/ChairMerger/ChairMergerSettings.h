#pragma once
#include <stdbool.h>

struct ChairMergerSettings
{
    // force all level packs and localization packs to be repacked
    bool m_bForceLevelPack = false;
    bool m_bForceLocalizationPack = false;
    bool m_bForceMainPatchPack = false;

    bool m_bForceVanillaPack = false;
};
