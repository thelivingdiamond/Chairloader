#pragma once

struct I3DCursor
{
    ~I3DCursor() {}

    //! @returns The cursor position.
    virtual const Vec3& GetPos() const = 0;

    //! Sets the cursor position.
    virtual void SetPos(const Vec3& newPos) = 0;

    //! Shows the menu for the menu bar.
    virtual void ShowMenu() = 0;

    //! Draws the cursor using aux geom.
    virtual void DrawAuxGeom() = 0;
};
