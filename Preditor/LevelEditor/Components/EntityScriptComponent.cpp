#include "Components/EntityScriptComponent.h"
#include "Utils/ScriptTableEditor.h"

LevelEditor::EntityScriptComponent::EntityScriptComponent()
{
}

LevelEditor::EntityScriptComponent::~EntityScriptComponent()
{
    SetEntityClass(nullptr);
}

void LevelEditor::EntityScriptComponent::SetEntityClass(IEntityClass* pClass)
{
    if (m_pClass == pClass)
        return;

    IScriptSystem* pScriptSystem = gEnv->pScriptSystem;

    m_bInitialized = false;
    m_pClass = pClass;
    m_pProperties.reset();
    m_pProperties2.reset();

    if (m_hOnPropertyChangedFunc)
        pScriptSystem->ReleaseFunc(m_hOnPropertyChangedFunc);

    if (!pClass)
        return;

    SmartScriptTable pClassTable(pScriptSystem, true);

    if (!pScriptSystem->GetGlobalValue(pClass->GetName(), pClassTable))
    {
        CryError("[{}] Lua table missing for class {}", GetObject()->GetName(), pClass->GetName());
        return;
    }

    pClassTable->GetValue("OnPropertyChange", m_hOnPropertyChangedFunc);

    SmartScriptTable pPropTable(pScriptSystem, true);

    if (pClassTable->GetValue(PROPERTIES_TABLE, pPropTable))
    {
        m_pProperties = std::make_unique<ScriptTableEditor>();
        m_pProperties->SetTable(pPropTable, true);
    }

    if (pClassTable->GetValue(PROPERTIES2_TABLE, pPropTable))
    {
        m_pProperties2 = std::make_unique<ScriptTableEditor>();
        m_pProperties2->SetTable(pPropTable, true);
    }

    m_bInitialized = true;
}

void LevelEditor::EntityScriptComponent::LoadFromXml(const XmlNodeRef& entityNode)
{
    auto fnLoad = [&](const char* nodeName, ScriptTableEditor* pTable)
        {
            XmlNodeRef pPropNode = entityNode->findChild(nodeName);
            
            if (pPropNode && pTable)
            {
                pTable->LoadFromXml(pPropNode);
            }
            else if (pPropNode && !pTable)
            {
                CryError("[{}] Entity has {} in XML but not in Lua class", GetObject()->GetName(), nodeName);
            }
        };

    fnLoad("Properties", m_pProperties.get());
    fnLoad("Properties2", m_pProperties2.get());
}

void LevelEditor::EntityScriptComponent::LoadEntityProperties()
{
    IScriptTable* pScriptTable = GetObject()->GetEntity()->GetScriptTable();

    if (!pScriptTable)
        return;

    IScriptSystem* pScriptSystem = gEnv->pScriptSystem;
    SmartScriptTable pPropTable(pScriptSystem, true);

    if (m_pProperties && pScriptTable->GetValue(PROPERTIES_TABLE, pPropTable))
    {
        m_pProperties->SetTable(pPropTable, false);
    }

    if (m_pProperties2 && pScriptTable->GetValue(PROPERTIES2_TABLE, pPropTable))
    {
        m_pProperties2->SetTable(pPropTable, false);
    }
}

void LevelEditor::EntityScriptComponent::ApplyEntityProperties(bool notifyEntity)
{
    IEntity* pEntity = GetObject()->GetEntity();
    IScriptTable* pScriptTable = pEntity->GetScriptTable();

    if (!pScriptTable)
        return;

    IScriptSystem* pScriptSystem = gEnv->pScriptSystem;

    auto fnSetProperties = [&](ScriptTableEditor* pProps, const char* name)
    {
        if (pProps)
        {
            SmartScriptTable pPropTable(pScriptSystem);
            pProps->GetTable(pPropTable);
            pScriptTable->SetValue(name, pPropTable);
        }
    };

    fnSetProperties(m_pProperties.get(), PROPERTIES_TABLE);
    fnSetProperties(m_pProperties2.get(), PROPERTIES2_TABLE);

    if (notifyEntity)
    {
        if (m_hOnPropertyChangedFunc)
        {
            if (IScriptTable* pScriptTable = pEntity->GetScriptTable())
            {
                Script::CallMethod(pScriptTable, m_hOnPropertyChangedFunc);
            }
        }

        SEntityEvent entityEvent(ENTITY_EVENT_EDITOR_PROPERTY_CHANGED);
        pEntity->SendEvent(entityEvent);
    }
}

void LevelEditor::EntityScriptComponent::ShowInspector()
{
    if (!m_bInitialized)
        return;

    if (Inspector::Begin(m_pClass->GetName()))
    {
        bool changed = false;

        if (m_pProperties)
            changed |= m_pProperties->ShowUI("Properties");

        if (m_pProperties2)
            changed |= m_pProperties2->ShowUI("Instance Properties");

        if (changed)
            OnPropertyChanged();

        if (ImGui::Button("Debug Reload"))
        {
            IEntityClass* temp = m_pClass;
            SetEntityClass(nullptr);
            SetEntityClass(temp);
        }

        Inspector::End();
    }
}

void LevelEditor::EntityScriptComponent::OnPropertyChanged()
{
    IEntity* pEntity = GetObject()->GetEntity();

    if (!pEntity)
        return;

    ApplyEntityProperties(true);
}
