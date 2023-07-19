#include <Prey/Cry3DEngine/I3DEngine.h>
#include <Preditor/EditTools/IEditToolManager.h>
#include "Objects/Object.h"
#include "ObjectSelectionManager.h"
#include "LevelEditMode.h"
#include "LevelViewportHandler.h"
#include "ObjectManager.h"

LevelEditor::GlobalLevel* LevelEditor::gLevel;

std::unique_ptr<ISceneEditor> ISceneEditor::CreateLevelEditor()
{
    return std::make_unique<LevelEditor::LevelEditMode>();
}

LevelEditor::LevelEditMode::LevelEditMode()
{
    assert(!gLevel);
    gLevel = &m_Global;
    m_Global.pEditor = this;

    m_pSelection = std::make_unique<ObjectSelectionManager>(this);
    m_pViewportHandler = std::make_unique<LevelViewportHandler>(this);
    m_pEditToolManager = IEditToolManager::CreateInstance(this);
    m_pObjectManager = std::make_unique<ObjectManager>();

    // Disable save/load
    m_pCanSaveLoad = gEnv->pConsole->GetCVar("g_EnableLoadSave");
    m_pCanSaveLoad->Set(false);

    LoadLevel();
}

LevelEditor::LevelEditMode::~LevelEditMode()
{
    // Allow save/load
    m_pCanSaveLoad->Set(true);

    assert(gLevel == &m_Global);
    gLevel = nullptr;
}

SelectionManager* LevelEditor::LevelEditMode::GetSelection()
{
    return m_pSelection.get();
}

IViewportHandler* LevelEditor::LevelEditMode::GetViewport()
{
    return m_pViewportHandler.get();
}

const char* LevelEditor::LevelEditMode::GetObjectName(SceneObjectId id)
{
    if (id == INVALID_SCENE_OBJECT)
        return nullptr;

    IEntity* pEnt = gEnv->pEntitySystem->GetEntity((EntityId)id);
    return pEnt ? pEnt->GetName() : nullptr;
}

void LevelEditor::LevelEditMode::OnEnabled()
{
    m_pEditToolManager->SetEnabled(true);
}

void LevelEditor::LevelEditMode::OnDisabled()
{
    m_pEditToolManager->SetEnabled(false);
}

void LevelEditor::LevelEditMode::ShowHierarchy()
{
    // TODO 2023-07-15
    auto& objs = m_pObjectManager->GetObjects();
    for (int i = 0; i < objs.size(); i++)
    {
        ImGui::PushID(i);
        Object* pObj = objs[i].get();
        
        if (ImGui::Selectable(pObj->GetName().c_str()))
        {
            m_pSelection->ClearSelection();
            m_pSelection->AddToSelection(i);
        }

        ImGui::PopID();
    }
}

void LevelEditor::LevelEditMode::ShowInspector()
{
    // TODO 2023-07-15
    SceneObjectId objId = m_pSelection->GetActiveObject();

    if (objId == INVALID_SCENE_OBJECT)
    {
        ImGui::TextDisabled("No object selected");
    }
    else
    {
        Object* pObj = m_pObjectManager->GetObject(objId);

        if (pObj)
        {
            pObj->ShowInspector();
        }
        else
        {
            ImGui::TextDisabled("Invalid object selected??");
        }
    }
}

void LevelEditor::LevelEditMode::LoadLevel()
{
    std::string missionXmlPath = gEnv->p3DEngine->GetLevelFilePath("mission_mission0.xml");
    XmlNodeRef missionXml = gEnv->pSystem->LoadXmlFromFile(missionXmlPath.c_str());
    m_pObjectManager->CreateLevelObjects(missionXml->findChild("Objects"));
}
