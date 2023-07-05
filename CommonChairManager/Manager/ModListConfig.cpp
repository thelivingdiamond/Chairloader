#include <Manager/ModListConfig.h>
#include <Manager/ModInfo.h>

Manager::ModListConfig::ModListConfig()
{
}

Manager::ModListConfig::~ModListConfig()
{
}

void Manager::ModListConfig::Clear()
{
    mods.clear();
}

Manager::ModListConfig::Item& Manager::ModListConfig::AddMod(const ModInfo& modInfo, bool isEnabled)
{
    return InsertMod(mods.size(), modInfo, isEnabled);
}

Manager::ModListConfig::Item& Manager::ModListConfig::InsertMod(int idx, const ModInfo& modInfo, bool isEnabled)
{
    Item& item = *mods.emplace(mods.begin() + idx);
    item.modName = modInfo.modName;
    item.version = modInfo.version;
    item.dllName = modInfo.dllName;
    item.hasXML = modInfo.hasXML;
    
    item.enabled = isEnabled;

    return item;
}

void Manager::ModListConfig::LoadXml(pugi::xml_node cfgNode)
{
    std::vector<SortItem> items;

    for (pugi::xml_node node : cfgNode)
    {
        SortItem& item = items.emplace_back();
        item.modName = node.child("modName").text().as_string();
        item.version = node.child("version").text().as_string();
        item.dllName = node.child("dllName").text().as_string();
        item.hasXML = node.child("hasXML").text().as_bool();
        item.enabled = node.child("enabled").text().as_bool();
        item.deployed = node.child("deployed").text().as_bool();
        item.loadOrder = node.child("loadOrder").text().as_int(std::numeric_limits<int>::max());
    }

    // Sort by load order
    std::sort(items.begin(), items.end());

    // Copy into public vector
    mods.clear();
    mods.insert(mods.end(), items.begin(), items.end());
}

void Manager::ModListConfig::SaveXml(pugi::xml_node cfgNode) const
{
    cfgNode.remove_children();

    for (int i = 0; i < mods.size(); i++)
    {
        const Item& item = mods[i];
        pugi::xml_node node = cfgNode.append_child(item.modName.c_str());
        node.append_attribute("type").set_value("xmlnode");

        pugi::xml_node val;

        val = node.append_child("modName");
        val.append_attribute("type").set_value("string");
        val.text().set(item.modName.c_str());

        val = node.append_child("version");
        val.append_attribute("type").set_value("string");
        val.text().set(item.version.c_str());

        if (!item.dllName.empty())
        {
            val = node.append_child("dllName");
            val.append_attribute("type").set_value("string");
            val.text().set(item.dllName.c_str());
        }

        val = node.append_child("hasXML");
        val.append_attribute("type").set_value("bool");
        val.text().set(item.hasXML);

        val = node.append_child("enabled");
        val.append_attribute("type").set_value("bool");
        val.text().set(item.enabled);

        val = node.append_child("deployed");
        val.append_attribute("type").set_value("bool");
        val.text().set(item.deployed);

        val = node.append_child("loadOrder");
        val.append_attribute("type").set_value("int");
        val.text().set(i);
    }
}
