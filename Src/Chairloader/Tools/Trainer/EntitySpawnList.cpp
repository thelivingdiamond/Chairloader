#include "Trainer/EntitySpawnList.h"

EntitySpawnList::Item::Item(EntitySpawnList* pList, ItemType type, std::string_view menuText)
{
    m_pList = pList;
    m_Type = type;
    m_MenuText = menuText;
}

EntitySpawnList::Category::Category(EntitySpawnList* pList, pugi::xml_node xmlNode)
    : Item(pList, ItemType::Category, xmlNode.attribute("Header").as_string())
{
    for (pugi::xml_node child : xmlNode)
    {
        ItemPtr subItem = pList->CreateItemFromXml(child);

        if (subItem)
            m_Items.emplace_back(std::move(subItem));
    }
}

void EntitySpawnList::Category::ShowMenuItem() const
{
    if (ImGui::BeginMenu(GetMenuText().c_str()))
    {
        for (int i = 0; i < m_Items.size(); i++)
        {
            ImGui::PushID(i);
            m_Items[i]->ShowMenuItem();
            ImGui::PopID();
        }

        ImGui::EndMenu();
    }
}

void EntitySpawnList::EntityItem::ShowMenuItem() const
{
    if (ImGui::MenuItem(GetMenuText().c_str()))
    {
        EntitySpawnInfo spawnInfo;
        spawnInfo.name = GetMenuText();
        spawnInfo.archetypeName = GetArchetypeName();
        spawnInfo.isNpc = GetType() == ItemType::Npc;
        GetList()->m_fnSpawnCallback(spawnInfo);
    }
}

EntitySpawnList::EntityItem::EntityItem(EntitySpawnList* pList, ItemType type, pugi::xml_node xmlNode)
    : Item(pList, type, xmlNode.text().as_string())
{
    m_ArchetypeName = xmlNode.attribute("Name").as_string();
    if (m_ArchetypeName.empty())
        CryError("[EntitySpawnList] Empty archetype name in '{}'", GetMenuText());
}

EntitySpawnList::EntityItem::EntityItem(EntitySpawnList* pList, pugi::xml_node xmlNode)
    : EntityItem(pList, ItemType::Entity, xmlNode)
{
}

EntitySpawnList::NpcItem::NpcItem(EntitySpawnList* pList, pugi::xml_node xmlNode)
    : EntityItem(pList, ItemType::Npc, xmlNode)
{
}

EntitySpawnList::EntitySpawnList()
{
}

EntitySpawnList::~EntitySpawnList()
{
}

void EntitySpawnList::SetSpawnCallback(const SpawnCallback& cb)
{
    m_fnSpawnCallback = cb;
}

void EntitySpawnList::LoadFromXml(pugi::xml_node xmlRoot)
{
    m_pRoot = nullptr;
    m_pRoot = std::make_unique<Category>(this, xmlRoot.first_child());
}

void EntitySpawnList::ShowMenuItems()
{
    if (m_pRoot)
    {
        for (auto& i : m_pRoot->GetItems())
        {
            i->ShowMenuItem();
        }
    }
    else
    {
        ImGui::TextDisabled("Entity spawn list not loaded.");
    }
}

EntitySpawnList::ItemPtr EntitySpawnList::CreateItemFromXml(pugi::xml_node xmlNode)
{
    std::string_view nodeName = xmlNode.name();

    if (nodeName == "Category")
        return std::make_unique<Category>(this, xmlNode);
    else if (nodeName == "Entity")
        return std::make_unique<EntityItem>(this, xmlNode);
    else if (nodeName == "Npc")
        return std::make_unique<NpcItem>(this, xmlNode);

    CryError("[EntitySpawnList] Unknown element '{}'", nodeName);
    return nullptr;
}
