#include <psapi.h>
#include "GameModuleInfo.h"

void GameModuleInfo::SetHandle(HMODULE hNewHandle)
{
    hModule = hNewHandle;

    if (hModule)
    {
        HANDLE hProcess = GetCurrentProcess();
        MODULEINFO moduleInfo;
        GetModuleInformation(hProcess, hNewHandle, &moduleInfo, sizeof(moduleInfo));
        baseAddress = (uintptr_t)moduleInfo.lpBaseOfDll;
        size = (uintptr_t)moduleInfo.SizeOfImage;
    }
    else
    {
        baseAddress = 0;
        size = 0;
    }
}

bool GameModuleInfo::CompareTestString(std::string_view testString, uintptr_t offset) const
{
    if (!hModule)
        return false;

    uintptr_t moduleEnd = baseAddress + size;
    uintptr_t strBegin = baseAddress + offset;
    uintptr_t strEnd = strBegin + testString.size();

    if (strBegin < baseAddress || strEnd < baseAddress ||
        strBegin >= moduleEnd || strEnd >= moduleEnd)
        return false;

    return !memcmp(testString.data(), (char*)strBegin, testString.size());
}
