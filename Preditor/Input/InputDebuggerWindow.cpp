#include <Preditor/Input/IPreditorInput.h>
#include <Preditor/Input/IKeyboardInputSystem.h>
#include <Preditor/Input/IKeyMap.h>
#include "InputDebuggerWindow.h"

Input::InputDebuggerWindow::InputDebuggerWindow()
{
    SetTitle("Input Debugger");
    SetPersistentID("InputDebugger");
}

void Input::InputDebuggerWindow::ShowContents()
{
    if (!m_IsLoaded)
    {
        LoadLayout();
        m_IsLoaded = true;
    }

    if (ImGui::Button("Reload Layout"))
        LoadLayout();
    ImGui::SameLine();

    if (ImGui::Button("Reload Binds"))
        gPreditor->pInput->GetKeyboard()->ReloadKeybinds();
    ImGui::SameLine();

    ImGui::DragFloat("Scale", &m_KeyScale, 0.1f, 0.1f, 5.0f);

    ImVec2 cursorBegin = ImGui::GetCursorPos();

    // Draw buttons
    for (const KeyPos& kp : m_Layout)
    {
        constexpr float PADDING = 3;
        const char* text = kp.key ? kp.key->displayName.c_str() : "<?>";
        Vec2 pos = (kp.pos * m_KeyScale) + Vec2(PADDING / 2, PADDING / 2);
        Vec2 size = (kp.size * m_KeyScale) - Vec2(PADDING, PADDING);

        ImGui::SetCursorPos(ImVec2(cursorBegin.x + pos.x, cursorBegin.y + pos.y));
        bool isPressed = ImGui::Button(text, ImVec2(size.x, size.y));
    }
}

void Input::InputDebuggerWindow::LoadLayout()
{
    m_Layout.clear();

    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file((gPreditor->pConfig->GetPreditorRoot() / LAYOUT_PATH).c_str());

    if (!result)
    {
        CryError("InputDebuggerWindow: Failed to load {}: {}", LAYOUT_PATH, result.description());
        return;
    }

    IKeyMap* pKeyMap = gPreditor->pInput->GetKeyboard()->GetKeyMap();

    for (pugi::xml_node node : doc.first_child())
    {
        KeyPos kp;
        kp.pos.x = node.attribute("pos_x").as_float();
        kp.pos.y = node.attribute("pos_y").as_float();
        kp.size.x = node.attribute("size_x").as_float();
        kp.size.y = node.attribute("size_y").as_float();

        const char* keyName = node.attribute("key").as_string();
        kp.key = pKeyMap->FindKeyByName(keyName);

        if (!kp.key)
            CryError("InputDebuggerWindow: key '{}' not found", keyName);

        m_Layout.push_back(kp);
    }
}
