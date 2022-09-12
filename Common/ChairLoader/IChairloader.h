#pragma once
#include <EntityUtils.h>

#include "ChairloaderEnv.h"
#include "IChairloaderConfigManager.h"
#include "IChairloaderGui.h"

struct IGameFramework;

struct IChairloader {
    //! @returns Pointers to interfaces provided by Chairloader to be used by mods.
    virtual ChairloaderGlobalEnvironment *GetChairloaderEnvironment() = 0;

    //! @returns the pointer to IGameFramework (implemented in CCryAction). Same as g_pGame->GetIGameFramework().
    virtual IGameFramework *GetFramework() = 0;

    //! @returns the base address of PreyDll.dll.
    virtual uintptr_t GetPreyDllBase() = 0;

    //! Key Map Names for key bind purposes
    using KeyNameMap = boost::bimap<EKeyId, std::string>;
    using KeyNamePair = boost::bimap<EKeyId, std::string>::value_type;
    virtual const KeyNameMap &GetKeyNames() const = 0;
    virtual std::string getKeyBind(std::string action) = 0;

    //! @returns whether editor is currently enabled.
    virtual bool IsEditorEnabled() = 0;

    //! Reloads all mod DLLs that support hot-reloading.
    //! Can only be called with specific conditions in mind.
    //! It's here only for the editor (which is in ChairloaderModules library).
    virtual void ReloadModDLLs() = 0;

    //! Checks if there are any changes to mod DLLs.
    //! Another editor method that's leaking into the public interface...
    virtual bool CheckDLLsForChanges() = 0;
};
