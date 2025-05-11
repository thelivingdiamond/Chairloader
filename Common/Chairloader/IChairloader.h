#pragma once
#include <Prey/CryInput/IInput.h>
#include <EntityUtils.h>

#include "ChairloaderEnv.h"
#include "IChairloaderConfigManager.h"
#include "IChairloaderGui.h"
#include "IChairService.h"

struct IGameFramework;
struct IChairLogger;
struct ICVar;
class CGame;

struct IChairloader : public IChairService<IChairloader> {

    static const char* NameImpl() { return "IChairloader"; }

    //! Gets the Mod SDK version used in Chairloader.
    virtual void GetModSdkVersion(int& major, int& minor, int& patch) = 0;

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
    //virtual std::string getKeyBind(std::string action) = 0;

    //! @returns whether editor is currently enabled.
    virtual bool IsEditorEnabled() = 0;

    //! @returns the CGame instance. Modders can use g_pGame (set in ChairloaderModBase).
    virtual CGame* GetCGame() = 0;

    //! @returns the pointer to cl_assert cvar.
    virtual int* GetAssertFlagAddress() = 0;

    virtual void RegisterCVar(ICVar* pCVar, std::string& modName) = 0;

    //! @returns the path to the Mods directory.
    virtual const fs::path& GetModsPath() = 0;
};
