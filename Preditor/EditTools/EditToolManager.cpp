#include <Preditor/Input/IPreditorInput.h>
#include <Preditor/SceneEditor/ISceneEditor.h>
#include <Preditor/SceneEditor/ISceneEditorManager.h>
#include "EditTool.h"
#include "EditToolManager.h"
#include "SelectTool.h"
#include "ImGuizmoTool.h"

static EditTools::EditToolManager* GetToolManager()
{
    ISceneEditor* pSceneEditor = gPreditor->pSceneEditorManager->GetEditor();
    if (!pSceneEditor)
        return nullptr;

    IEditToolManager* pIEditToolMgr = pSceneEditor->GetToolManager();
    if (!pIEditToolMgr)
        return nullptr;

    auto pEditToolMgr = static_cast<EditTools::EditToolManager*>(pIEditToolMgr);
    CRY_ASSERT(pEditToolMgr->IsActive());
    return pEditToolMgr;
}

std::unique_ptr<IEditToolManager> IEditToolManager::CreateInstance(ISceneEditor* pEditor)
{
    return std::make_unique<EditTools::EditToolManager>(pEditor);
}

EditTools::EditToolManager::EditToolManager(ISceneEditor* pEditor)
{
    m_pEditor = pEditor;

    m_pSelectTool = std::make_unique<SelectTool>(this);
    m_pMoveTool = std::make_unique<ImGuizmoTool>(this, ImGuizmo::OPERATION::TRANSLATE, Vec3(0.25f));
    m_pRotateTool = std::make_unique<ImGuizmoTool>(this, ImGuizmo::OPERATION::ROTATE, Vec3(5));
    m_pScaleTool = std::make_unique<ImGuizmoTool>(this, ImGuizmo::OPERATION::SCALE, Vec3(0.25f));

    // Start with select tool
    SetCurrentTool(m_pSelectTool.get());

    static bool bActionListenersRegistered = false;

    RegisterToolSelectKey("select", m_pSelectTool.get(), !bActionListenersRegistered);
    RegisterToolSelectKey("move", m_pMoveTool.get(), !bActionListenersRegistered);
    RegisterToolSelectKey("rotate", m_pRotateTool.get(), !bActionListenersRegistered);
    RegisterToolSelectKey("scale", m_pScaleTool.get(), !bActionListenersRegistered);

    if (!bActionListenersRegistered)
    {
        gPreditor->pInput->FindAction("transform_tools.toggle_pivot")->AddListener([](const KeyActionEventArgs& e)
            {
                EditToolManager* pToolMgr = GetToolManager();

                if (e.isPressed && pToolMgr)
                {
                    pToolMgr->m_bPivotCenter ^= 1;
                }
            });

        gPreditor->pInput->FindAction("transform_tools.toggle_tool_space")->AddListener([](const KeyActionEventArgs& e)
            {
                EditToolManager* pToolMgr = GetToolManager();

                if (e.isPressed && pToolMgr)
                {
                    pToolMgr->m_bWorldTransform ^= 1;
                }
            });

        bActionListenersRegistered = true;
    }
}

EditTools::EditToolManager::~EditToolManager()
{
}

void EditTools::EditToolManager::ShowSelectionUI()
{
    if (ImGui::Button(m_bPivotCenter ? ICON_MD_CENTER_FOCUS_WEAK : ICON_MD_TRIP_ORIGIN))
        m_bPivotCenter ^= 1;
    ImGui::SameLine();

    if (ImGui::Button(m_bWorldTransform ? ICON_MD_LANGUAGE : ICON_MD_VIEW_IN_AR))
        m_bWorldTransform ^= 1;
    ImGui::SameLine();

    EditTool* tools[] = { m_pSelectTool.get(), m_pMoveTool.get(), m_pRotateTool.get(), m_pScaleTool.get() };
    const char* names[] = { "Select", "Move", "Rotate", "Scale" };

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

void EditTools::EditToolManager::RegisterToolSelectKey(std::string_view action, EditTool* pTool, bool bAddListener)
{
    // Save to the map
    m_KeyActionToTool[std::string(action)] = pTool;

    if (bAddListener)
    {
        IKeyActionSet* pActionSet = gPreditor->pInput->GetKeyboard()->FindActionSet("tool_select");
        IKeyAction* pAction = pActionSet->FindAction(action);
        ListenerId listenerId = pAction->AddListener([actionName = std::string(action)](const KeyActionEventArgs& e)
            {
                EditToolManager* pToolMgr = GetToolManager();
                if (e.isPressed)
                {
                    auto it = pToolMgr->m_KeyActionToTool.find(actionName);
                    pToolMgr->SetCurrentTool(it->second);
                }
            });
    }
}
