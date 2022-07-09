#pragma once
#include <Prey/CryRenderer/IRenderer.h>
#include <mem.h>

// This class encapsulate all renderbale information to render a camera view.
// It stores list of render items added by 3D engine
class CRenderView : public IRenderView {
public:
	static constexpr size_t OFFSET_CAMERA = 0x11A0;
	static constexpr size_t OFFSET_RENDER_CAMERA = 0x1620;

#if 0
	void SetCamera(const CCamera &cam) {
		auto &m_camera = mem::OffsetInStruct<CCamera>(this, OFFSET_CAMERA);
		auto &m_renderCamera = mem::OffsetInStruct<CRenderCamera>(this, OFFSET_CAMERA);
		m_camera = cam;

		CRenderCamera rcam;

		// Ortho-normalize camera matrix in double precision to minimize numerical errors and improve precision when inverting matrix
		Matrix34_tpl<f64> mCam34 = cam.GetMatrix();
		mCam34.OrthonormalizeFast();

		// Asymmetric frustum
		float Near = cam.GetNearPlane(), Far = cam.GetFarPlane();

		float wT = tanf(cam.GetFov() * 0.5f) * Near, wB = -wT;
		float wR = wT * cam.GetProjRatio(), wL = -wR;
		rcam.Frustum(wL + cam.GetAsymL(), wR + cam.GetAsymR(), wB + cam.GetAsymB(), wT + cam.GetAsymT(), Near, Far);

		Vec3 vEye = cam.GetPosition();
		Vec3 vAt = vEye + Vec3((f32)mCam34(0, 1), (f32)mCam34(1, 1), (f32)mCam34(2, 1));
		Vec3 vUp = Vec3((f32)mCam34(0, 2), (f32)mCam34(1, 2), (f32)mCam34(2, 2));
		rcam.LookAt(vEye, vAt, vUp);

		m_renderCamera = rcam;
	}

	virtual void   SetPreviousFrameCameras(const CCamera *pCameras, int cameraCount) final;
#endif
};