#pragma once
#include <Preditor/IntrusiveList.hpp>

namespace LevelEditor
{

//! Allows an object or its component to render aux geometry.
//! Must be inhereted from.
class AuxGeomComponent : NoCopy
{
protected:
    AuxGeomComponent();
    virtual ~AuxGeomComponent();

    //! @returns Whether aux geom rendering is enabled.
    bool IsAuxGeomEnabled() const { return m_bEnabled; }

    //! Enables/disables aux geom.
    void SetAuxGeomEnabled(bool state);

    //! Renders the aux geometry.
    virtual void RenderAuxGeom() = 0;

private:
    bool m_bEnabled = false;
    IntrusiveListItem m_ListItem;

    friend class AuxGeomManager;
};

} // namespace LevelEditor
