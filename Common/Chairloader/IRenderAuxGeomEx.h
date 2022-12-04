#pragma once
#include <Prey/CryRenderer/IRenderAuxGeom.h>

struct CTexture;

//! Chairloader extensions for IRenderAuxGeom
struct IRenderAuxGeomEx
{
	virtual ~IRenderAuxGeomEx() {}

	//! @returns whether IRenderAuxGeom->Flush calls have any effect.
	virtual bool IsFlushAllowed() = 0;

	//! Sets whether IRenderAuxGeom->Flush calls have any effect.
	//! Multiple calls stack. To actually reenable Flush SetFlushAllowed(true) must be called
	//! same number of times that SetFlushAllowed(false) was called.
	virtual void SetFlushAllowed(bool state) = 0;

	//! Sets current render targets for stereo rendering.
	//! Must be called from the render thread.
	virtual void SetStereoTargets(CTexture* pTargets[2], SDepthTexture* pDepthTargets[2]) = 0;

	//! Sets transformation matrices for stereo rendering.
	//! Must be called from the render thread.
	virtual void SetStereoTransform(int eyeIdx, const Matrix44& matView, const Matrix44& matProj) = 0;
};
