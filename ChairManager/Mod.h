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
    pugi::xml_node infoFile;
    pugi::xml_node configFile;
    std::vector<std::string> dependencies;
    // installed = Mod loader remembers
    // enabled = Mod loader will load
    // deployed = files are ready
    bool installed = false,
            enabled = false,
            deployed = false,
            hasXML = false,
            hasLevelXML = false;
    bool operator<( Mod& b ) const {
        return this->loadOrder < b.loadOrder;
    }
    bool operator ==(const std::string& rhs) const{
        return this->modName == rhs;
    }
};
#endif //CHAIRLOADER_MOD_H
