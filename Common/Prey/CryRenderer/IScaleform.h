// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryMath/Cry_Color.h>

// SSF_GlobalDrawParams
// Header:  CryEngine/crycommon/cryrenderer/iscaleform.h
// Include: Prey/RenderDll/Scaleform/ScaleformPlayback.h
struct SSF_GlobalDrawParams
{ // Size=360 (0x168)
	enum class EFillType
	{
		None = 0,
		SolidColor = 1,
		Texture = 2,
		GlyphTexture = 3,
		GlyphAlphaTexture = 4,
		GlyphTextureMat = 5,
		GlyphTextureMatMul = 6,
		GlyphTextureYUV = 7,
		GlyphTextureYUVA = 8,
		GColor = 9,
		GColorNoAddAlpha = 10,
		G1Texture = 11,
		G1TextureColor = 12,
		G2Texture = 13,
		G2TextureColor = 14,
		G3Texture = 15,
		FillCount = 16,
	};

	enum class EVertexFmt
	{
		Vertex_None = 0,
		Vertex_XY16i = 1,
		Vertex_XY32f = 2,
		Vertex_XY16iC32 = 3,
		Vertex_XY16iCF32 = 4,
		Vertex_Glyph = 5,
		Vertex_Num = 6,
	};

	enum class EIndexFmt
	{
		Index_None = 0,
		Index_16 = 1,
		Index_32 = 2,
	};

	enum class ETexState
	{
		TS_Clamp = 1,
		TS_FilterLin = 2,
		TS_FilterTriLin = 4,
	};

	enum class EAlphaBlendOp
	{
		Add = 0,
		Substract = 1,
		RevSubstract = 2,
		Min = 3,
		Max = 4,
	};

	enum class EBlurType
	{
		BlurNone = 0,
		start_shadows = 1,
		Box2InnerShadow = 1,
		Box2InnerShadowHighlight = 2,
		Box2InnerShadowMul = 3,
		Box2InnerShadowMulHighlight = 4,
		Box2InnerShadowKnockout = 5,
		Box2InnerShadowHighlightKnockout = 6,
		Box2InnerShadowMulKnockout = 7,
		Box2InnerShadowMulHighlightKnockout = 8,
		Box2Shadow = 9,
		Box2ShadowHighlight = 10,
		Box2ShadowMul = 11,
		Box2ShadowMulHighlight = 12,
		Box2ShadowKnockout = 13,
		Box2ShadowHighlightKnockout = 14,
		Box2ShadowMulKnockout = 15,
		Box2ShadowMulHighlightKnockout = 16,
		Box2Shadowonly = 17,
		Box2ShadowonlyHighlight = 18,
		Box2ShadowonlyMul = 19,
		Box2ShadowonlyMulHighlight = 20,
		end_shadows = 20,
		start_blurs = 21,
		Box1Blur = 21,
		Box2Blur = 22,
		Box1BlurMul = 23,
		Box2BlurMul = 24,
		end_blurs = 24,
		BlurCount = 25,
		shadows_Highlight = 1,
		shadows_Mul = 2,
		shadows_Knockout = 4,
		blurs_Box2 = 1,
		blurs_Mul = 2,
	};

	// SSF_GlobalDrawParams::STextureInfo
	// Header:  CryEngine/crycommon/cryrenderer/iscaleform.h
	struct STextureInfo
	{ // Size=56 (0x38)
		int texID;
		unsigned texState;
		Matrix34 texGenMat;
	};

	// SSF_GlobalDrawParams::BlurFilterParams
	// Header:  CryEngine/crycommon/cryrenderer/iscaleform.h
	struct BlurFilterParams
	{ // Size=68 (0x44)
		SSF_GlobalDrawParams::EBlurType blurType;
		Vec4 blurFilterSize;
		Vec2 blurFilterScale;
		Vec2 blurFilterOffset;
		ColorF blurFilterColor1;
		ColorF blurFilterColor2;
	};

	SSF_GlobalDrawParams::EFillType fillType;
	SSF_GlobalDrawParams::EVertexFmt vertexFmt;
	const void* pVertexPtr;
	unsigned numVertices;
	SSF_GlobalDrawParams::EIndexFmt indexFmt;
	const void* pIndexPtr;
	unsigned numIndices;
	const Matrix44* pTransMat;
	SSF_GlobalDrawParams::STextureInfo texture[2];
	int texID_YUVA[4];
	ColorF colTransform1st;
	ColorF colTransform2nd;
	ColorF colTransformMat[4];
	unsigned blendModeStates;
	unsigned renderMaskedStates;
	bool isMultiplyDarkBlendMode;
	bool premultipliedAlpha;
	SSF_GlobalDrawParams::EAlphaBlendOp blendOp;
	SSF_GlobalDrawParams::BlurFilterParams blurParams;

	void Reset() { FReset(this); }

#if 0
	SSF_GlobalDrawParams();
#endif

#ifndef MOONCRASH
	static inline auto FReset = PreyFunction<void(SSF_GlobalDrawParams* const _this)>(0xD90B00);
#else
	static inline auto FReset = PreyFunction<void(SSF_GlobalDrawParams* const _this)>(0xDAE950);
#endif
};

