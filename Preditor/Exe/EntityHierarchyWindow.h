#pragma once
#include <WindowManager/ManagedWindow.h>

// I hate myself
#include "../../Chairloader/Tools/Components/EntityHierarchy.h"

class EntityHierarchyWindow : public ManagedWindow
{
public:
	EntityHierarchyWindow();

protected:
	void ShowContents() override;

private:
	EntityHierarchy m_Hier;
};
