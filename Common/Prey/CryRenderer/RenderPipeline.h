#pragma once
#include <Prey/CryMath/Cry_Color.h>

class CRenderView;

struct SViewport
{
	int   nX, nY, nWidth, nHeight;
	float fMinZ, fMaxZ;
	SViewport()
		: nX(0)
		, nY(0)
		, nWidth(0)
		, nHeight(0)
		, fMinZ(0.0f)
		, fMaxZ(0.0f) {
	}

	SViewport(int nNewX, int nNewY, int nNewWidth, int nNewHeight)
		: nX(nNewX)
		, nY(nNewY)
		, nWidth(nNewWidth)
		, nHeight(nNewHeight)
		, fMinZ(0.0f)
		, fMaxZ(0.0f) {
	}
	inline friend bool operator!=(const SViewport &m1, const SViewport &m2) {
		if (m1.nX != m2.nX || m1.nY != m2.nY || m1.nWidth != m2.nWidth || m1.nHeight != m2.nHeight || m1.fMinZ != m2.fMinZ || m1.fMaxZ != m2.fMaxZ)
			return true;
		return false;
	}
};

struct SFogState
{
	bool   m_bEnable;
	ColorF m_FogColor;
	ColorF m_CurColor;

	//bool operator!=(const SFogState &fs) const {
	//	return m_FogColor != fs.m_FogColor;
	//}
};

#define MAX_PREDICTION_ZONES 2

struct SThreadInfo
{
	uint32              m_PersFlags;                             // Never reset
	float               m_RealTime;
	float               m_timers[4];
	class CMatrixStack *m_matView;
	class CMatrixStack *m_matProj;
	Matrix44            m_matCameraZero;
	CCamera             m_cam;                                   // current camera
	CRenderCamera       m_rcam;                                  // current camera
	int                 m_nFrameID;                              // with recursive calls, access through GetFrameID(true)
	uint32              m_nFrameUpdateID;                        // without recursive calls, access through GetFrameID(false)
	int                 m_arrZonesRoundId[MAX_PREDICTION_ZONES]; // rounds ID from 3D engine, useful for texture streaming
	SFogState           m_FS;
	byte                m_eCurColorOp;
	byte                m_eCurAlphaOp;
	byte                m_eCurColorArg;
	byte                m_eCurAlphaArg;
};

struct SRenderPipeline {
	static constexpr size_t OFFSET_TI = 672;
	static constexpr size_t OFFSET_PSUNLIGHT = 10328;
};