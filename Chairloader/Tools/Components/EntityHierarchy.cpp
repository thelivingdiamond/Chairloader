#include <boost/algorithm/string/find.hpp>
#include <Prey/CryAction/GameObject.h>
#include <Prey/CryGame/Game.h>
#include <Prey/GameDll/ark/ArkGame.h>
#include <Prey/GameDll/ark/ArkItemSystem.h>
#include <EntityUtils.h>
#include "EntityHierarchy.h"

void EntityHierarchy::ShowContents()
{
	// Filter by name
	if (ImGui::InputText("##NameFilter", &m_NameFilter)) {
		//RequestHierUpdate();
	}

	// Filter by type
	if (ImGui::TreeNodeEx("Filters", 0))
	{
		bool showAll = m_FilterFlags == eFF_All;
		if (ImGui::Checkbox("All", &showAll))
			m_FilterFlags = showAll ? eFF_All : eFF_None;
		ImGui::SameLine();
		ShowFilterCheckbox("GameObjects", eFF_GameObject);
		ShowFilterCheckbox("Items", eFF_Item); ImGui::SameLine();
		ShowFilterCheckbox("NPCs", eFF_Npc);
		ImGui::TreePop();
	}

	// The entity list
	UpdateHierarchy();

	ImGui::Separator();
	ImGui::BeginChild("ListScroll");
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f });
	ShowEntList(m_HierItems);
	ImGui::PopStyleVar();
	ImGui::EndChild();
}

void EntityHierarchy::ShowFilterCheckbox(const char* name, EFilterFlags mask)
{
	bool isEnabled = m_FilterFlags & mask;
	if (ImGui::Checkbox(name, &isEnabled))
	{
		if (isEnabled)
			m_FilterFlags |= mask;
		else
			m_FilterFlags &= ~mask;
	}
}

bool EntityHierarchy::DoesEntityPassFilter(IEntity* pEnt)
{
	// Must match name first
	if (!m_NameFilter.empty())
	{
		const char* entName = pEnt->GetName();
		const char* filter = m_NameFilter.c_str();
		if (!boost::ifind_first(entName, filter))
			return false;
	}

	if (m_FilterFlags == eFF_All)
		return true;

	// Check flag filters
	if ((m_FilterFlags & eFF_GameObject) && pEnt->GetProxy(ENTITY_PROXY_USER))
		return true;

	if ((m_FilterFlags & eFF_Item) && g_pGame->m_pArkGame->GetArkItemSystem().GetItem(pEnt->GetId()))
		return true;

	if ((m_FilterFlags & eFF_Npc) && gEntUtils->GetArkNpc(pEnt))
		return true;

	return false;
}

void EntityHierarchy::UpdateHierarchy()
{
	//m_NextHierUpdate = -1;
	IEntityItPtr it = gEnv->pEntitySystem->GetEntityIterator();
	m_HierItems.clear();

	IEntity* pEnt = nullptr;
	for (it->MoveFirst(); (pEnt = it->Next());)
	{
		if (pEnt->GetParent())
		{
			// Skip non-root entities
			continue;
		}

		if (!DoesEntityPassFilter(pEnt))
			continue;

		HierItem item;
		item.id = pEnt->GetId();
		bool shouldDisplay = AddChildrenToList(pEnt, item.children);

		if (shouldDisplay)
			m_HierItems.push_back(std::move(item));
	}

	//m_ScrollToSelectedEntity = true;
}

bool EntityHierarchy::AddChildrenToList(IEntity* pEnt, std::vector<HierItem>& list)
{
	int childCount = pEnt->GetChildCount();
	bool shouldDisplay = DoesEntityPassFilter(pEnt);

	for (int i = 0; i < childCount; i++)
	{
		IEntity* pChild = pEnt->GetChild(i);
		HierItem& item = list.emplace_back();
		item.id = pChild->GetId();
		shouldDisplay |= AddChildrenToList(pChild, item.children);
	}

	return shouldDisplay;
}

void EntityHierarchy::ShowEntList(std::vector<HierItem>& list)
{
	for (HierItem& item : list)
	{
		IEntity* pEnt = gEnv->pEntitySystem->GetEntity(item.id);
		ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_SpanFullWidth;

		if (m_SelectedEntity == item.id) {
			nodeFlags |= ImGuiTreeNodeFlags_Selected;
		}

		if (pEnt) {
			char buf[256];
			snprintf(buf, sizeof(buf), "%s##Entity%d", pEnt->GetName(), item.id);

			if (item.children.empty()) {
				nodeFlags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen;
				ImGui::TreeNodeEx(buf, nodeFlags);

				if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen()) {
					SelectEntity(item.id);
				}

				if (m_SelectedEntity == item.id && m_ScrollToSelectedEntity) {
					ImGui::SetScrollHereY();
					m_ScrollToSelectedEntity = false;
				}
			}
			else {
				nodeFlags |= ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;;
				bool nodeOpen = ImGui::TreeNodeEx(buf, nodeFlags);

				if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen()) {
					SelectEntity(item.id);
				}

				if (m_SelectedEntity == item.id && m_ScrollToSelectedEntity) {
					ImGui::SetScrollHereY();
					m_ScrollToSelectedEntity = false;
				}

				if (nodeOpen) {
					ShowEntList(item.children);
					ImGui::TreePop();
				}
			}
		}
	}
}

void EntityHierarchy::SelectEntity(EntityId id)
{
	m_SelectedEntity = id;
}
