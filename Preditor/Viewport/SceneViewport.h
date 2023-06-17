#pragma once
#include "BaseViewport.h"
#include "MouseGuard.h"

namespace Viewport
{

class SceneViewport
    : public BaseViewport
    , public ISystemEventListener
{
public:
    SceneViewport();
    ~SceneViewport();

    // IViewport
    virtual bool NeedCustomRender() override { return true; }
    virtual void CustomRender() override;
    virtual bool EnableMouseEvents() override { return false; }

    // BaseViewport
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void ShowUI() override;

    // ISystemEventListener
    virtual void OnSystemEvent(ESystemEvent event, UINT_PTR wparam, UINT_PTR lparam) override;

private:
    struct CameraInfo
    {
        //! Camera has a meaningful position. Reset on level change.
        bool transformValid = false;

        Vec3 pos = Vec3(ZERO);
        Ang3 rot = Ang3(ZERO);
        float fov = 90.0f; // In degrees
        float nearPlane = DEFAULT_NEAR;
        float farPlane = DEFAULT_FAR;
    };

    MouseGuard m_InputEnabled;
    CCamera m_Cam;
    CameraInfo m_CamInfo;

    void ShowCameraMenu();

    void UpdateCamera();
    void CopyViewCameraTransform();

    void DrawAuxGeom();
    void DrawViewCameraFrustum();
};

} // namespace Viewport
