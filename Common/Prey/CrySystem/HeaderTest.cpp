// Header test file for path Prey/CrySystem/
// The CCryPak layout differs between the two games (968 vs 1536).
#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)
#include "CryPak.h"
#ifndef MOONCRASH
static_assert(sizeof(CCryPak) == 968);
#else
static_assert(sizeof(CCryPak) == 1536);
static_assert(sizeof(CCryPak::PackDesc) == 32);
static_assert(sizeof(CCryPak::SModInfo) == 16);
#endif
#endif

#include "FrameProfileSystem.h"
static_assert(sizeof(IFrameProfileSystem) == 8);

#include "PlatformOS/PlatformOS_PC.h"
#include "HardwareMouse.h"
#include "LocalizedStringManager.h"
#include "Ark/ArkRewardSystem.h"
