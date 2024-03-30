#pragma once

struct GameModuleInfo
{
    HMODULE hModule = nullptr;
    uintptr_t baseAddress = 0;
    uintptr_t size = 0;

    operator bool() { return hModule != nullptr; }

    //! Sets the handle.
    void SetHandle(HMODULE hNewHandle);

    //! Checks if the test string is in the module.
    bool CompareTestString(std::string_view testString, uintptr_t offset) const;
};
