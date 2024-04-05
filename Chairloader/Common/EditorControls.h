#pragma once

//! Contains controls for various CryEngine types with context menu.
class EditorControls
{
public:
    //! Shows a drag control for a position vector.
    //! @param  label       Label text.
    //! @param  pValue      Value.
    //! @param  v_speed     Speed un units per pixel.
    //! @param  format      Display format for each component.
    //! @param  flags       Drag flags.
    static bool DragVec3(const char* label, Vec3* pValue, float v_speed = 0.01f, const char* format = "%.2f", ImGuiSliderFlags flags = 0);

    //! Shows a drag control for a rotation quat. Displays degrees.
    //! @param  label       Label text.
    //! @param  pValue      Value.
    //! @param  v_speed     Speed in degrees per pixel.
    //! @param  format      Display format for each component.
    //! @param  flags       Drag flags.
    static bool DragQuat(const char* label, Quat* pValue, float v_speed = 1.0f, const char* format = "%.2f", ImGuiSliderFlags flags = 0);
};
