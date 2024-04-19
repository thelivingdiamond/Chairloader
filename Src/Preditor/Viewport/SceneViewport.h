#pragma once
#include <Preditor/SceneEditor/IViewportHandler.h>
#include <Preditor/MouseGuard.h>
#include "BaseViewport.h"

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

    //! @returns a ray from screen coordinates.
    ViewportRaycastInfo GetRayForMouse(Vec2 mousePos, Vec2 vpSize);

    //! @returns the camera transform matrix.
    Matrix34 GetCameraTransform();

    // IViewport
    virtual bool NeedCustomRender() override { return true; }
    virtual void CustomRender() override;
    virtual EViewportInputMode GetInputMode() override { return m_InputMode; }

    // BaseViewport
    virtual bool CanActivate() override;
    virtual void OnEnabled() override;
    virtual void OnDisabled() override;
    virtual void Update(bool isVisible) override;
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

        bool bDrawRealWorld = true;
        bool bDrawLookingGlass = true;
    };

    MouseGuard m_InputEnabled;
    EViewportInputMode m_InputMode = EViewportInputMode::None;
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

    //! LMB was clicked on the viewport.
    void OnViewportClick(Vec2 mousePos, Vec2 vpSize);

    void ShowCameraMenu();

    void ProcessInput();
    void UpdateCameraMatrix();
    void UpdateCamera();
    void CopyViewCameraTransform();

    void DrawAuxGeom();
    void DrawViewCameraFrustum();
};

} // namespace Viewport
