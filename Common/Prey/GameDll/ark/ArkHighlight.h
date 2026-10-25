// Mooncrash only. Strings are plain `const char*` in the game.
#pragma once
#ifdef MOONCRASH
#include <Prey/ArkEnums.h>
#include <vector>

struct ArkHighlightLocalizedPair // Size=16
{
	const char* localeCode;
	const char* localizedString;
};

struct ArkHighlight // Size=40
{
	const char* highlightId;
	bool userInterest;
	EArkHighlightType highlightType;
	EArkHighlightSignificance significance;
	std::vector<ArkHighlightLocalizedPair> nameTable;
};

struct ArkHighlightGroup // Size=32
{
	const char* groupId;
	std::vector<ArkHighlightLocalizedPair> nameTable;
};

struct ArkHighlightScreenshotInfo // Size=16
{
	const char* groupId;
	const char* highlightId;
};

struct ArkHighlightVideoInfo // Size=24
{
	const char* groupId;
	const char* highlightId;
	int startDelta;
	int endDelta;
};

struct ArkHighlightGroupView // Size=16
{
	const char* groupId;
	EArkHighlightType tagsFilter;
	EArkHighlightSignificance significanceFilter;
};

static_assert(sizeof(ArkHighlightLocalizedPair) == 16);
static_assert(sizeof(ArkHighlight) == 40);
static_assert(sizeof(ArkHighlightGroup) == 32);
static_assert(sizeof(ArkHighlightScreenshotInfo) == 16);
static_assert(sizeof(ArkHighlightVideoInfo) == 24);
static_assert(sizeof(ArkHighlightGroupView) == 16);
#endif
