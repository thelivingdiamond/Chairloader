#pragma once
#include <Preditor/SceneEditor/Common.h>
#include <WindowManager/ManagedWindow.h>

struct IKeyAction;

namespace Main
{

class SelectionWindow : public ManagedWindow
{
public:
	SelectionWindow();

protected:
	void ShowContents() override;
};

} // namespace Main
