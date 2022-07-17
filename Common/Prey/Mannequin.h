#pragma once
#include <Prey/CryCore/StdAfx.h>
class SMannParameter {
	unsigned int crc;
	QuatT_tpl<float> value;
};
class CMannequinParams {
	std::vector<SMannParameter> m_paramList;
};
template<typename T, T val> class TMannequinAutoInit {
public:
	T val;
};
class FragmentIDs {
public:
	TMannequinAutoInit<int32_t, -1> LookBlink;
};