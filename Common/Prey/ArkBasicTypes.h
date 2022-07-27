#pragma once
#include "pch.h"

typedef char undefined;


class CSharedString {
public:

};
// template<typename T> class vector {
// 	char pad[24];
// };

template<typename T, uint32_t i> class CryFixedArray {
public:
	void* ptr;
	uint32_t m_curSize;
	T arr[i];
};

class CryHashStringId {
public:
	uint32_t id;
};

class BLOCK {
public:
	BLOCK* next;
	int32_t size;
	char s[1];
};
class SStringData {
public:
	char* m_szString;
	int32_t m_nStrLen;
	char pad[4];
};
class CSimpleStringPool {
public:
	uint32_t m_blockSize;
	char pad[4];
	BLOCK* m_blocks;
	BLOCK* m_free_blocks;
	char* m_end;
	char* m_ptr;
	char* m_start;
	int32_t nUsedSpace;
	int nUsedBlocks;
	bool m_reuseStrings;
	char pad2[7];
	std::unordered_map<SStringData, char*> m_stringToExistingStringMap;
};