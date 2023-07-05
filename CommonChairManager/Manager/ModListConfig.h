#pragma once

namespace Manager
{

class ModInfo;

class ModListConfig
{
public:
    struct Item
    {
        std::string modName;
        std::string version;
        std::string dllName;
        bool hasXML = false;
        bool enabled = false;
        bool deployed = false;
    };

    //! Mods sorted by load order.
    std::vector<Item> mods;

    ModListConfig();
    ~ModListConfig();

    //! Removes all mods from the list.
    void Clear();

    //! Adds a new mod to the end of the list.
    //! @param  modInfo     Mod info.
    //! @param  isEnabled   Whether the mod is enabled.
    Item& AddMod(const ModInfo& modInfo, bool isEnabled);

    //! Inserts a new mod at the specified index.
    //! @param  idx         Target index.
    //! @param  modInfo     Mod info.
    //! @param  isEnabled   Whether the mod is enabled.
    Item& InsertMod(int idx, const ModInfo& modInfo, bool isEnabled);

    //! Loads mod list from Chairloader config <ModList type="xmlnode"> node.
    void LoadXml(pugi::xml_node cfgNode);

    //! Saves mod list into Chairloader config <ModList type="xmlnode"> node.
    void SaveXml(pugi::xml_node cfgNode) const;

private:
    struct SortItem : public Item
    {
        int loadOrder = 0;

        bool operator<(const SortItem& rhs)
        {
            return loadOrder < rhs.loadOrder;
        }
    };
};

} // namespace Manager
