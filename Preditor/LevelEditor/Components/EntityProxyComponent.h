#pragma once
#include "Components/EntityComponent.h"

namespace LevelEditor
{

class EntityProxyComponent : public EntityComponent
{
public:
    //! @returns The entity proxy pointer, if it exists.
    IEntityProxy* GetProxy() const { return m_pProxy.get(); }

    //! Creates the proxy for the owning entity object.
    bool CreateProxy();

    //! Releases the proxy instance.
    void ReleaseProxy();

    //! Loads the proxy data from entity XML node.
    virtual void LoadFromXml(const XmlNodeRef& entityNode);

protected:
    EntityProxyComponent(EEntityProxy proxyType);

    //! Called after the proxy is created.
    virtual void OnProxyCreated() {}

    //! Called before the proxy is released.
    virtual void OnProxyReleased() {}

    // Component
    virtual void ShowInspector() override;

private:
    EEntityProxy m_nProxyType = ENTITY_PROXY_LAST;
    IEntityProxyPtr m_pProxy;
};

} // namespace LevelEditor
