#include <Prey/CrySystem/File/ICryPak.h>
#include <mem.h>
#include "LuaDbgFix.h"

class CFileTree;
using HTREEITEM = void*;

constexpr size_t OFFSET_m_vFileNameTbl = 40;
constexpr size_t OFFSET_m_isDir = 64;

namespace
{

static inline auto CFileTree_AddItemToTree = PreyFunction<HTREEITEM(CFileTree* const _this, char* lpszItem, int64_t ud, HTREEITEM hParent, unsigned iImage)>(0xD4C240);
static inline auto CFileTree_EnumerateScripts = PreyFunction<int(CFileTree* const _this, HTREEITEM hRoot, char* pszEnumPath)>(0xD4D2A0);
static inline auto CFileTree_RemoveItemFromTree = PreyFunction<void(CFileTree* const _this, HTREEITEM itm)>(0xD542C0);
auto g_CFileTree_EnumerateScripts_Hook = CFileTree_EnumerateScripts.MakeHook();

int CFileTree_EnumerateScripts_Hook(CFileTree* _this, HTREEITEM hRoot, char* pszEnumPath)
{
	int num_added = 0;
	_finddata_t c_file;
	char szPath[_MAX_PATH];
	char szFullFilePath[_MAX_PATH];
	HTREEITEM hItem = NULL;

	intptr_t hFile;

	auto& m_vFileNameTbl = mem::OffsetInStruct<std::vector<string>>(_this, OFFSET_m_vFileNameTbl);
	auto& m_isDir = mem::OffsetInStruct<std::vector<bool>>(_this, OFFSET_m_isDir);

	if ((hFile = gEnv->pCryPak->FindFirst((string(pszEnumPath) + "/*.*").c_str(), &c_file)) == -1L)
		return 0;

	do
	{
		if (_stricmp(c_file.name, "..") == 0)
			continue;
		if (_stricmp(c_file.name, ".") == 0)
			continue;

		cry_sprintf(szFullFilePath, "%s%s", pszEnumPath, c_file.name);
		m_vFileNameTbl.push_back(szFullFilePath);
		m_isDir.push_back((c_file.attrib & _A_SUBDIR) != 0);

		if (c_file.attrib & _A_SUBDIR)
		{
			HTREEITEM hItem = CFileTree_AddItemToTree(_this, c_file.name, (int64_t)m_vFileNameTbl.size() - 1, hRoot, 0);
			cry_sprintf(szPath, "%s%s/", pszEnumPath, c_file.name);
			if (CFileTree_EnumerateScripts_Hook(_this, hItem, szPath))
			{
				++num_added;
			}
			else
			{
				CFileTree_RemoveItemFromTree(_this, hItem);
			}
		}
		else
		{
			char fname[_MAX_PATH];
			cry_strcpy(fname, c_file.name);
			_strlwr(fname);
			if (!strchr(fname, '.'))
				continue;
			if (strcmp(strchr(fname, '.'), ".lua") == 0)
			{
				hItem = CFileTree_AddItemToTree(_this, c_file.name, (int64_t)m_vFileNameTbl.size() - 1, hRoot, 1);
				++num_added;
			}
		}
	}
	while (gEnv->pCryPak->FindNext(hFile, &c_file) == 0);

	return num_added;
}

}

void LuaDbgFix::InitSystem()
{
	g_CFileTree_EnumerateScripts_Hook.SetHookFunc(&CFileTree_EnumerateScripts_Hook);
}
