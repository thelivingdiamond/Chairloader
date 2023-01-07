#include "EntityHierarchyWindow.h"

EntityHierarchyWindow::EntityHierarchyWindow()
{
	SetTitle("Entities");
	SetPersistentID("EntityHier");
	SetDestroyOnClose(true);
	SetCloseable(true);
}

void EntityHierarchyWindow::ShowContents()
{
	m_Hier.ShowContents();
}
