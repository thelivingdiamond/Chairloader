#pragma once
#include <Preditor/IntrusiveList.hpp>

namespace LevelEditor
{

class AuxGeomComponent;

//! Provides aux geom rendering for level editor objects.
class AuxGeomManager
{
public:
    AuxGeomManager();
    ~AuxGeomManager();

    //! Renders aux geom in all enabled AuxGeomComponents.
    void RenderAuxGeom();

private:
    //! The list of components
    IntrusiveList<AuxGeomComponent> m_List;

    //! Enables aux geom for the component
    void AddComponent(AuxGeomComponent& comp);

    //! Disables aux geom for the component
    void RemoveComponent(AuxGeomComponent& comp);

    friend class AuxGeomComponent;
};

} // namespace LevelEditor
