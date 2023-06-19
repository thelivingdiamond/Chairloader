#pragma once
#include "BaseViewport.h"
#include "MouseGuard.h"

struct IKeyAction;
struct IKeyActionSet;

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

    // Camera controls
    IKeyActionSet* m_pCameraActionSet = nullptr;
    IKeyAction* m_pFwd = nullptr;
    IKeyAction* m_pBkwd = nullptr;
    IKeyAction* m_pLeft = nullptr;
    IKeyAction* m_pRight = nullptr;
    IKeyAction* m_pUp = nullptr;
    IKeyAction* m_pDown = nullptr;
    IKeyAction* m_pSpeedUp = nullptr;
    float m_MoveSpeed = 0;
    bool m_IsInCameraMode = false;

    //! Sets whether currently controlling the camera.
    void SetCameraMode(bool state);

    void ShowCameraMenu();

    void UpdateCamera();
    void CopyViewCameraTransform();

    void DrawAuxGeom();
    void DrawViewCameraFrustum();
};

} // namespace Viewport
