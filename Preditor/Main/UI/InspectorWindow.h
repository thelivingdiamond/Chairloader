#pragma once
#include <Preditor/SceneEditor/Common.h>
#include <WindowManager/ManagedWindow.h>

namespace Main
{

class InspectorWindow : public ManagedWindow
{
public:
	InspectorWindow();

protected:
	void ShowContents() override;
};

} // namespace Main
