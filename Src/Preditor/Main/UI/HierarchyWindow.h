#pragma once
#include <Preditor/SceneEditor/Common.h>
#include <WindowManager/ManagedWindow.h>

namespace Main
{

class HierarchyWindow : public ManagedWindow
{
public:
	HierarchyWindow();

protected:
	void ShowContents() override;
};

} // namespace Main
