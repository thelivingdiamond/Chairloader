#pragma once
#include "../../CommonChairManager/Manager/ModInfo.h"

struct IChairloaderMod;

class ModApiComponent;
class ModDllComponent;

//! A single Chairloader mod.
class ChairMod : NoCopy
{
public:
    //! Constructs a mod from pre-existing mod info.
    ChairMod(const Manager::ModInfo& modInfo);
    ~ChairMod();

    //! @returns mod info.
    const Manager::ModInfo& GetModInfo() const { return m_ModInfo; }

    //! @returns the API component.
    ModApiComponent* GetApi() const { return m_pApi.get(); }

    //! @returns the DLL component.
    ModDllComponent* GetDll() const { return m_pDll.get(); }

    //! Adds a Mod API instance to the mod.
    void AddApi(IChairloaderMod* pMod);

    //! Adds a DLL to the mod. This will also load the API.
    void AddDll(const fs::path& dllPath);

private:
    Manager::ModInfo m_ModInfo;
    std::unique_ptr<ModApiComponent> m_pApi;
    std::unique_ptr<ModDllComponent> m_pDll;
};
