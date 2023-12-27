#pragma once
#include <Prey/CryRenderer/IRenderAuxGeom.h>

struct CTexture;

//! Chairloader extensions for IRenderAuxGeom
struct IRenderAuxGeomEx
{
	virtual ~IRenderAuxGeomEx() {}

	//! Deprecated. Causes a fatal error on call.
	//! Use IChairRender::SetAuxGeomFactory.
	//! @{
	virtual bool DEPRECATED_IsFlushAllowed() = 0;
	virtual void DEPRECATED_SetFlushAllowed(bool state) = 0;
	virtual void DEPRECATED_SetStereoTargets(CTexture* pTargets[2], SDepthTexture* pDepthTargets[2]) = 0;
	virtual void DEPRECATED_SetStereoTransform(int eyeIdx, const Matrix44& matView, const Matrix44& matProj) = 0;
	//! @}
};
