//
// Created by theli on 1/14/2023.
//

#ifndef CHAIRLOADER_MOD_H
#define CHAIRLOADER_MOD_H
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
    bool operator ==(std::string rhs){
        return this->modName == rhs;
    }
};
#endif //CHAIRLOADER_MOD_H
