#include "Components/EntityProxyComponent.h"

bool LevelEditor::EntityProxyComponent::CreateProxy()
{
    if (m_pProxy)
    {
        CryError("[{}] Proxy already exists", GetObject()->GetName());
        return false;
    }

    IEntity* pEntity = GetObject()->GetEntity();
    CRY_ASSERT(pEntity);
    m_pProxy = pEntity->CreateProxy(m_nProxyType);

    if (!m_pProxy)
    {
        CryError("[{}] Failed to create entity proxy {}", GetObject()->GetName(), (int)m_nProxyType);
        return false;
    }

    OnProxyCreated();
    return true;
}

void LevelEditor::EntityProxyComponent::ReleaseProxy()
{
    if (!m_pProxy)
        return;

    OnProxyReleased();
    m_pProxy.reset();
}

void LevelEditor::EntityProxyComponent::LoadFromXml(const XmlNodeRef& entityNode)
{
}

LevelEditor::EntityProxyComponent::EntityProxyComponent(EEntityProxy proxyType)
{
    m_nProxyType = proxyType;
}

void LevelEditor::EntityProxyComponent::ShowInspector()
{
    ImGui::Text("Proxy: %d", m_nProxyType);
}
