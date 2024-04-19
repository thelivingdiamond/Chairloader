#pragma once
#include <WindowManager/ManagedWindow.h>

// I hate myself
#include "../../Chairloader/Tools/Components/EntityHierarchy.h"

class EntityHierarchyWindow : public ManagedWindow
{
public:
	static EntityHierarchyWindow* Get();
	EntityHierarchyWindow();

	EntityId GetSelectedEntity() { return m_Hier.GetSelectedEntity(); }
	void SetSelectedEntity(EntityId id) { m_Hier.SetSelectedEntity(id); }
	void ScrollToSelectedEntity() { m_Hier.ScrollToSelectedEntity(); }

protected:
	void ShowContents() override;

private:
	EntityHierarchy m_Hier;
};
