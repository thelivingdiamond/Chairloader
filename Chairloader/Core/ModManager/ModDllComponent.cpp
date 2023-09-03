#include <Prey/CryCore/Platform/CryWindows.h>
#include "ModManager/ModDllComponent.h"

ModDllComponent::ModDllComponent(ChairMod* pMod, const fs::path& dllPath)
    : ModComponent(pMod)
{
    LoadDll(dllPath);
}

ModDllComponent::~ModDllComponent()
{
    UnloadDll();
}

void* ModDllComponent::GetVoidSymbol(const char* symName) const
{
    return (void*)GetProcAddress((HMODULE)m_hModule.get(), symName);
}

void ModDllComponent::UnloadDll()
{
    if (m_pfnShutdown)
        m_pfnShutdown();

    m_pModApi = nullptr;
    m_pfnShutdown = nullptr;
    m_hModule.reset();
}
