#include "InspectorWindow.h"
#include "EntityHierarchyWindow.h"

InspectorWindow::InspectorWindow()
{
	SetTitle("Inspector");
	SetPersistentID("Inspector");
	SetDestroyOnClose(true);
	SetCloseable(true);
}

void InspectorWindow::ShowContents()
{
	m_Inspector.ShowContents(EntityHierarchyWindow::Get()->GetSelectedEntity());
}
