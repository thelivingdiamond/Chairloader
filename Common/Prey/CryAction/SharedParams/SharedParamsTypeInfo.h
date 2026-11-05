// Based on CryEngine 5.2 CryAction/SharedParams/SharedParamsTypeInfo.h; debug asserts dropped.
// The id hash is only meaningful to the game's own CSharedParamsManager.
#pragma once
#include <cstdint>
#include <cstdio>
#include <cstring>

class CSharedParamsTypeInfo
{
public:
	CSharedParamsTypeInfo(size_t size, const char* pName, const char* pFileName, uint32_t line) : m_size(size)
	{
		CopyTail(m_name, sizeof(m_name), pName);
		CopyTail(m_fileName, sizeof(m_fileName), pFileName);
		m_line = line;

		char temp[256];
		snprintf(temp, sizeof(temp), "%zu%s%s%u", size, m_name, m_fileName, m_line);
		m_uniqueId = Hash(temp);
	}

	inline size_t      GetSize() const     { return m_size; }
	inline const char* GetName() const     { return m_name; }
	inline const char* GetFileName() const { return m_fileName; }
	inline uint32_t    GetLine() const     { return m_line; }
	inline uint32_t    GetUniqueId() const { return m_uniqueId; }

	inline bool operator==(const CSharedParamsTypeInfo& right) const { return m_uniqueId == right.m_uniqueId; }
	inline bool operator!=(const CSharedParamsTypeInfo& right) const { return m_uniqueId != right.m_uniqueId; }

private:
	static void CopyTail(char* dst, size_t cap, const char* src)
	{
		if (!src) { dst[0] = '\0'; return; }
		const size_t length = strlen(src);
		const size_t pos = length > cap - 1 ? length - (cap - 1) : 0;
		strncpy(dst, src + pos, cap - 1);
		dst[cap - 1] = '\0';
	}

	static uint32_t Hash(const char* s)   // CryStringUtils::CalculateHash (sdbm-style) equivalent
	{
		uint32_t h = 5381;
		for (; *s; ++s) h = h * 33 + static_cast<unsigned char>(*s);
		return h;
	}

	size_t   m_size;
	char     m_name[64];
	char     m_fileName[64];
	uint32_t m_line;
	uint32_t m_uniqueId;
};
