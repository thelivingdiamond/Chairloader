// Header test file for path Prey/GameDll/ark/player/trauma/

#include "ArkStatusGoodDrunk.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkStatusGoodDrunk) == 304);
#else
static_assert(sizeof(ArkStatusGoodDrunk) == 336);
#endif

#include "ArkStatusWellFed.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkStatusWellFed) == 296);
#else
static_assert(sizeof(ArkStatusWellFed) == 328);
#endif

#include "ArkTraumaBase.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaBase) == 296);
#else
static_assert(sizeof(ArkTraumaBase) == 328);
#endif

#include "ArkTraumaBleeding.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaBleeding) == 600);
#else
static_assert(sizeof(ArkTraumaBleeding) == 632);
#endif

#include "ArkTraumaBurns.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaBurns) == 512);
#else
static_assert(sizeof(ArkTraumaBurns) == 544);
#endif

#include "ArkTraumaConcussion.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaConcussion) == 304);
#endif

#include "ArkTraumaDisruption.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaDisruption) == 296);
#else
static_assert(sizeof(ArkTraumaDisruption) == 328);
#endif

#include "ArkTraumaDrunk.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaDrunk) == 304);
#else
static_assert(sizeof(ArkTraumaDrunk) == 336);
#endif

#include "ArkTraumaFear.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaFear) == 312);
#else
static_assert(sizeof(ArkTraumaFear) == 344);
#endif

#include "ArkTraumaHobbled.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaHobbled) == 312);
#else
static_assert(sizeof(ArkTraumaHobbled) == 344);
#endif

#include "ArkTraumaPsychoshock.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaPsychoshock) == 296);
#else
static_assert(sizeof(ArkTraumaPsychoshock) == 328);
#endif

#include "ArkTraumaRadiation.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaRadiation) == 296);
#else
static_assert(sizeof(ArkTraumaRadiation) == 328);
#endif

#include "ArkTraumaSuitIntegrity.h"
#ifndef MOONCRASH
static_assert(sizeof(ArkTraumaSuitIntegrity) == 304);
#else
static_assert(sizeof(ArkTraumaSuitIntegrity) == 344);
#endif

#if defined(MOONCRASH) || defined(PREY_HEADERTEST_ALL)   // new header: not compiled by base builds yet
#include "ArkTraumaGlooed.h"
#ifdef MOONCRASH
static_assert(sizeof(ArkTraumaGlooed) == 464);
#endif
#endif
