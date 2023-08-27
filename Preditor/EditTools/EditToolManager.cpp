#include <Prey/CryRenderer/IRenderer.h>
#include "EditTool.h"
#include "EditToolManager.h"
#include "SelectTool.h"
#include "MoveTool.h"

std::unique_ptr<IEditToolManager> IEditToolManager::CreateInstance(ISceneEditor* pEditor)
{
    return std::make_unique<EditTools::EditToolManager>(pEditor);
}

EditTools::EditToolManager::EditToolManager(ISceneEditor* pEditor)
{
    m_pEditor = pEditor;

    m_pSelectTool = std::make_unique<SelectTool>(this);
    m_pMoveTool = std::make_unique<MoveTool>(this);

    // Start with select tool
    SetCurrentTool(m_pSelectTool.get());
}

EditTools::EditToolManager::~EditToolManager()
{
}

void EditTools::EditToolManager::ShowSelectionUI()
{
    EditTool* tools[] = { m_pSelectTool.get(), m_pMoveTool.get() };
    const char* names[] = { "Select", "Move" };

    for (size_t i = 0; i < std::size(tools); i++)
    {
        if (ImGui::RadioButton(names[i], tools[i] == m_pCurTool))
            SetCurrentTool(tools[i]);
        ImGui::SameLine();
    }

    ImGui::NewLine();
}

void EditTools::EditToolManager::SetEnabled(bool state)
{
    if (m_bIsActive == state)
        return;

    m_bIsActive = state;

    if (m_pCurTool)
        m_pCurTool->SetActive(state);
}

EEditToolResult EditTools::EditToolManager::OnLeftMouseClick(Vec2 clickPos, Vec2 vpSize)
{
    if (!m_bIsActive)
        return EEditToolResult::Passthrough;

    EEditToolResult result = EEditToolResult::Passthrough;
    
    if (m_pCurTool)
        result = m_pCurTool->OnLeftMouseClick(clickPos, vpSize);

    if (result == EEditToolResult::Passthrough)
    {
        // Pass to the select tool
        if (m_pCurTool != m_pSelectTool.get())
            result = m_pSelectTool->OnLeftMouseClick(clickPos, vpSize);
    }

    return result;
}

void EditTools::EditToolManager::DrawViewport(const Vec4& bounds, const CCamera& camera)
{
    if (!m_bIsActive)
        return;

    if (m_pCurTool)
    {
        m_pCurTool->DrawViewport(bounds, camera);
    }
}

void EditTools::EditToolManager::SetCurrentTool(EditTool* pTool)
{
    // If nullptr, default to select tool
    if (!pTool)
        pTool = m_pSelectTool.get();

    if (m_pCurTool == pTool)
        return;

    if (m_pCurTool)
    {
        m_pCurTool->SetActive(false);
        m_pCurTool = nullptr;
    }

    if (pTool)
    {
        m_pCurTool = pTool;
        m_pCurTool->SetActive(m_bIsActive);
    }
}
