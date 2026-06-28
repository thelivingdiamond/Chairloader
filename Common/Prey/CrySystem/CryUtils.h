// Auto-merged (base-only, address-free): shared in both builds; no MOONCRASH guard.
// Copyright 2001-2016 Crytek GmbH / Crytek Group. All rights reserved.

#pragma once

#include <cstddef> // size_t

namespace Detail
{
template<typename T, size_t size>
char (&ArrayCountHelper(T(&)[size]))[size];
}

#define CRY_ARRAY_COUNT(arr) sizeof(::Detail::ArrayCountHelper(arr))
