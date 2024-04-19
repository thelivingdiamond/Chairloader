#pragma once

class EntitySpawnList : NoCopy
{
public:
    enum class ItemType
    {
        None,
        Category,
        Entity,
        Npc,
    };

    class Item;

    //! Pointer to an item.
    using ItemPtr = std::unique_ptr<Item>;

    struct EntitySpawnInfo
    {
        std::string name;
        std::string archetypeName;
        bool isNpc = false;
    };

    //! Base list item.
    class Item
    {
    public:
        virtual ~Item() {}

        //! @returns the item type.
        ItemType GetType() const { return m_Type; }

        //! @returns the menu text.
        const std::string& GetMenuText() const { return m_MenuText; }

        //! Shows the ImGui menu item for the item.
        virtual void ShowMenuItem() const = 0;

    protected:
        Item(EntitySpawnList* pList, ItemType type, std::string_view menuText);

        //! @returns the pointer to the list.
        EntitySpawnList* GetList() const { return m_pList; }

    private:
        ItemType m_Type = ItemType::None;
        std::string m_MenuText;
        EntitySpawnList* m_pList = nullptr;
    };

    //! A list of sub-items.
    class Category : public Item
    {
    public:
        //! Creates the category from an XML node.
        Category(EntitySpawnList* pList, pugi::xml_node xmlNode);

        //! @returns the list of items.
        const std::vector<ItemPtr>& GetItems() const { return m_Items; }

        virtual void ShowMenuItem() const override;

    private:
        std::vector<ItemPtr> m_Items;
    };

    //! A generic entity.
    class EntityItem : public Item
    {
    public:
        EntityItem(EntitySpawnList* pList, pugi::xml_node xmlNode);

        //! @returns the entity archetype name.
        const std::string& GetArchetypeName() const { return m_ArchetypeName; }

        virtual void ShowMenuItem() const override;

    protected:
        EntityItem(EntitySpawnList* pList, ItemType type, pugi::xml_node xmlNode);

    private:
        std::string m_ArchetypeName;
    };

    //! An NPC that is spawned using EntityUtils::SpawnNpc.
    class NpcItem : public EntityItem
    {
    public:
        NpcItem(EntitySpawnList* pList, pugi::xml_node xmlNode);
    };

    //! The callback that spawns an item.
    using SpawnCallback = std::function<void(const EntitySpawnInfo& spawnInfo)>;

    EntitySpawnList();
    ~EntitySpawnList();

    //! Sets the callback that spawns an entity on click.
    void SetSpawnCallback(const SpawnCallback& cb);

    //! Loads the list from an XML node.
    void LoadFromXml(pugi::xml_node xmlRoot);

    //! Shows the menu items. Doesn't create its own submenu.
    void ShowMenuItems();

private:
    SpawnCallback m_fnSpawnCallback;
    std::unique_ptr<Category> m_pRoot;

    //! Creates an item from XML node.
    //! @returns item pointer.
    ItemPtr CreateItemFromXml(pugi::xml_node xmlNode);
};
