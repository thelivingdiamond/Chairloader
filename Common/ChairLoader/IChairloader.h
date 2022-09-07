#pragma once
#include <EntityUtils.h>

#include "ChairloaderEnv.h"
#include "IChairloaderConfigManager.h"
#include "IChairloaderGui.h"

struct IGameFramework;

struct IChairloader {
    //! @returns Pointers to interfaces provided by Chairloader to be used by mods.
    virtual ChairloaderGlobalEnvironment *GetChairloaderEnvironment() = 0;

    virtual IGameFramework *GetFramework() = 0;

    //! Key Map Names for key bind purposes
    using KeyNameMap = boost::bimap<EKeyId, std::string>;
    using KeyNamePair = boost::bimap<EKeyId, std::string>::value_type;
    virtual const KeyNameMap &GetKeyNames() const = 0;
    virtual std::string getKeyBind(std::string action) = 0;

    //! @returns whether editor is currently enabled.
    virtual bool IsEditorEnabled() = 0;
};
