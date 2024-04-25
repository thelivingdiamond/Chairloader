#pragma once

class EntityHierarchy
{
public:
	void ShowContents();

	EntityId GetSelectedEntity() { return m_SelectedEntity; }
	void SetSelectedEntity(EntityId id) { m_SelectedEntity = id; }
	void ScrollToSelectedEntity() { m_ScrollToSelectedEntity = true; }

private:
	enum EFilterFlags : uint32_t
	{
		eFF_None = 0,
		eFF_All = 0xFFFF'FFFF,
		eFF_GameObject = BIT(0),
		eFF_Item = BIT(1),
		eFF_Npc = BIT(2)
	};

	struct HierItem {
		EntityId id = 0;
		std::vector<HierItem> children;
	};

	std::string m_NameFilter;
	uint32_t m_FilterFlags = eFF_All;
	std::vector<HierItem> m_HierItems;

	EntityId m_SelectedEntity = 0;
	bool m_ScrollToSelectedEntity = false;

	void ShowFilterCheckbox(const char* name, EFilterFlags mask);
	bool DoesEntityPassFilter(IEntity* pEnt);

	// List population
	void UpdateHierarchy();
	bool AddChildrenToList(IEntity* pEnt, std::vector<HierItem>& list);

	// List display
	void ShowEntList(std::vector<HierItem>& list);
	void SelectEntity(EntityId id);
};
