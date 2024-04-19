#pragma once
#include <Chairloader/IChairloaderMod.h>
#include "ModManager/ModComponent.h"

class ModDllComponent : public ModComponent
{
public:
    ModDllComponent(ChairMod* pMod, const fs::path& dllPath);
    ~ModDllComponent();

    //! @returns whether the DLL is currently loaded.
    bool IsLoaded() const { return m_hModule != nullptr; }

    //! @returns the DLL handle.
    void* GetHandle() const { return m_hModule.get(); }

    //! Gets a symbol (function or variable) from the DLL.
    //! @returns the symbol ptr or nullptr.
    //! @{
    void* GetVoidSymbol(const char* symName) const;

    template <typename T>
    T* GetSymbol(const char* symName) const
    {
        return reinterpret_cast<T*>(GetVoidSymbol(symName));
    }
    //! @}

    //! Unloads the currently loaded DLL, if any.
    void UnloadDll();

protected:
    //! Loads a mod DLL. Existing DLL will be unloaded.
    void LoadDll(const fs::path& dllPath);

private:
    //! Smart pointer deleter that unloads a DLL.
    struct ModuleDeleter
    {
        void operator()(void* hModule) { UnloadModule(hModule); }
    };

    //! Smart pointer for DLL.
    using ModulePtr = std::unique_ptr<void, ModuleDeleter>;

    //! DLL module handle.
    ModulePtr m_hModule = nullptr;

    //! DLL callbacks
    //! @{
    IChairloaderMod::ProcShutdown* m_pfnShutdown = nullptr;
    //! @}

    //! The Mod API.
    IChairloaderMod* m_pModApi = nullptr;

    //! Unloads a DLL.
    static void UnloadModule(void* hModule);
};
