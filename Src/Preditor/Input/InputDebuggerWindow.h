#pragma once
#include <Preditor/Input/Common.h>
#include <WindowManager/ManagedWindow.h>

namespace Input
{

class InputDebuggerWindow : public ManagedWindow
{
public:
    InputDebuggerWindow();

protected:
    virtual void ShowContents() override;

private:
    static constexpr char LAYOUT_PATH[] = "Preditor/KeyDbgLayout.xml";

    struct KeyPos
    {
        Vec2 pos;
        Vec2 size;
        const KeyInfo* key = nullptr;
    };

    std::vector<KeyPos> m_Layout;
    float m_KeyScale = 1.0f;
    bool m_IsLoaded = false;

    void LoadLayout();
};

} // namespace Input
