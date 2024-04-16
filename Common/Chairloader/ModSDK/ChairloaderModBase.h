#pragma once
#ifdef CHAIRLOADER_MOD_SDK
#include <Chairloader/IChairloader.h>
#include <Chairloader/IChairloaderMod.h>
#include <Chairloader/ChairloaderEnv.h>

class ChairloaderModBase : public IChairloaderMod
{
public:
    struct ModDllInfoEx : ModDllInfo
    {
        //! Name of the mod without author for the logger.
        const char* logTag = nullptr;
    };

    //! @returns base address of PreyDll.dll
    uintptr_t GetModuleBase() const { return m_ModuleBase; }

    //! @returns the path to the directory in "Mods"
    const fs::path& GetModDirectory() const { return m_ModDirPath; }

    //! @returns the path to the mod's DLL. It may be located ouside of the mod directory when hot-reloading.
    const fs::path& GetModDllPath() const { return m_ModDllPath; }

    //! Fills in the DLL info during initialization.
    virtual void FillModInfo(ModDllInfoEx& info) = 0;

    //! Initializes function hooks before they are installed.
    virtual void InitHooks() = 0;

    // IChairloaderMod overrides
    virtual void GetModSdkVersion(SemanticVersion &version) override;
    virtual void InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo) override;
    virtual void InitGame(bool isHotReloading) override;
    virtual void ShutdownGame(bool isHotUnloading) override;
    virtual void ShutdownSystem(bool isHotUnloading) override;
    virtual void* QueryInterface(const char* ifaceName) override;
    virtual void Connect(const std::vector<IChairloaderMod*>& mods) override; 

protected:
    //! Finds an interface in other mods.
    //! @param	mods		Mod list.
    //! @param	ifaceName	Interface mod.
    //! @param	modName		Mod display name. Used in logs.
    //! @param	minVersion	Minimum interface version.
    //! @param	required	If true, causes a fatal error if interface wasn't found.
    //! @returns Interface of nullptr.
    //! @{
    template <typename T>
    T* GetInterfaceFromModList(
        const std::vector<IChairloaderMod*>& mods,
        const char* ifaceName,
        const char* modName,
        bool required);

    template <typename T>
    T* GetInterfaceFromModList(
        const std::vector<IChairloaderMod*>& mods,
        const char* ifaceName,
        const char* modName,
        int minVersion,
        bool required);
    //! @}

    //! Gets an optional interface from a mod list.
    //! Interface name and version are read from T.
    //! @param	mods		Mod list.
    //! @param	modName		Mod display name. Used in logs.
    //! @return Interface or nullptr.
    template <typename T>
    T* GetInterfaceFromModList(
        const std::vector<IChairloaderMod*>& mods,
        const char* modName)
    {
        return GetInterfaceFromModList<T>(mods, T::IFACE_NAME, modName, T::VERSION, false);
    }

    //! Gets a required interface from a mod list. If not found, causes a fatal error.
    //! Interface name and version are read from T.
    //! @param	mods		Mod list.
    //! @param	modName		Mod display name. Used in logs.
    //! @return Interface pointer.
    template <typename T>
    T* GetRequiredInterfaceFromModList(
        const std::vector<IChairloaderMod*>& mods,
        const char* modName)
    {
        return GetInterfaceFromModList<T>(mods, T::IFACE_NAME, modName, T::VERSION, true);
    }

private:
    uintptr_t m_ModuleBase = 0;
    fs::path m_ModDirPath;
    fs::path m_ModDllPath;

    void InitImGui();
    void ShutdownImGui();
};

template <typename T>
T* ChairloaderModBase::GetInterfaceFromModList(
    const std::vector<IChairloaderMod*>& mods,
    const char* ifaceName,
    const char* modName,
    bool required)
{
    for (IChairloaderMod* pMod : mods)
    {
        // Multiple mods may implement the interface. This will choose the first one.
        T* pIface = static_cast<T*>(pMod->QueryInterface(ifaceName));

        if (pIface)
        {
#ifdef DEBUG_BUILD
            CryLog("Found interface {} at {:p}", ifaceName, (void*)pIface);
#endif
            return pIface;
        }
    }

    if (required)
        CryFatalError("Interface {} was not found in any mods.\nInstall {}.", ifaceName, modName);
    else
        CryLog("Interface {} (mod {}) was not found", ifaceName, modName);

    return nullptr;
}

template <typename T>
T* ChairloaderModBase::GetInterfaceFromModList(
    const std::vector<IChairloaderMod*>& mods,
    const char* ifaceName,
    const char* modName,
    int minVersion,
    bool required)
{
    T* pIface = GetInterfaceFromModList<T>(mods, ifaceName, modName, required);

    if (!pIface)
        return nullptr;

    int version = pIface->GetInterfaceVersion();
    if (version < minVersion)
    {
        if (required)
        {
            CryFatalError(
                "Mod {} is out of date.\nInterface: {} v{}\nRequired: {}",
                modName, ifaceName, version, minVersion);
        }
        else
        {
            CryError(
                "Mod {} is out of date.\nInterface: {} v{}\nRequired: {}",
                modName, ifaceName, version, minVersion);
        }

        return nullptr;
    }

    return pIface;
}

#endif
