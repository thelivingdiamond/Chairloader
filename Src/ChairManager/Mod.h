//
// Created by theli on 1/14/2023.
//

#ifndef CHAIRLOADER_MOD_H
#define CHAIRLOADER_MOD_H

//TODO: refactor my variables to match the naming convention of the rest of the codebase
// TODO 2023-06-24: Replace with ChairManager::ModInfo
struct Mod{
    std::string modName;
    std::string displayName;
    std::string version;
    std::string author;
    std::string dllName;
    int loadOrder = -1;
    std::vector<std::string> dependencies;

    //! Path to the mod directory (where ModInfo.xml is).
    fs::path path;

    // enabled = Mod loader will load
    // deployed = files are ready
    bool enabled = false;
    bool deployed = false;
    bool hasXML = false;
    bool hasLevelXML = false;
    bool isNew = false; // Mod didn't exist in the mod list.

    //! The mod is a Preditor project outside of Mods directory.
    bool isPreditorProject = false;

    //! The mod is a legacy mod (without ModInfo.xml).
    bool isLegacyMod = false;

    bool operator<( Mod& b ) const {
        return this->loadOrder < b.loadOrder;
    }
    bool operator ==(const std::string& rhs) const{
        return this->modName == rhs;
    }
};
#endif //CHAIRLOADER_MOD_H
