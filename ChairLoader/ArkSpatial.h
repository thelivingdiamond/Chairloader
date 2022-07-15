#pragma once
#include "Prey/CryCore/StdAfx.h"
class ArkSpatiallySortedKey {
public:
	uint64_t m_index;
};

template<typename t> class ArkSpatialManagerKey {
public:
	ArkSpatiallySortedKey m_key;
};

class ArkSpatialManagerEntryImpl_Npc {
public:
	unsigned char a;
};

template<typename t> class ArkSpatialManagerEntry {
public:
	t m_impl;
	ArkSpatialManagerKey<t> m_key;
};
class ArkSpatialManager {};