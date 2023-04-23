#pragma once
#include <WindowManager/ManagedWindow.h>

// I still hate myself
#include "../../Chairloader/Tools/Components/EntityInspector.h"

class InspectorWindow : public ManagedWindow
{
public:
	InspectorWindow();

protected:
	void ShowContents() override;

private:
	EntityInspector m_Inspector;
};
