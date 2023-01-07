#include "EntityHierarchyWindow.h"

static EntityHierarchyWindow* g_pEntityHierarchyWindow;

EntityHierarchyWindow* EntityHierarchyWindow::Get()
{
	return g_pEntityHierarchyWindow;
}

EntityHierarchyWindow::EntityHierarchyWindow()
{
	g_pEntityHierarchyWindow = this;
	SetTitle("Entities");
	SetPersistentID("EntityHier");
	SetDestroyOnClose(true);
	SetCloseable(true);
}

void EntityHierarchyWindow::ShowContents()
{
	m_Hier.ShowContents();
}
