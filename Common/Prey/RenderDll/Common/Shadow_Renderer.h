// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once

struct ShadowMapFrustum : public CMultiThreadRefCount
{
	char pad[4048 - sizeof(CMultiThreadRefCount)];
};

static_assert(sizeof(ShadowMapFrustum) == 4048);

typedef _smart_ptr<ShadowMapFrustum> ShadowMapFrustumPtr;

struct ShadowFrustumMGPUCache : public ISyncMainWithRenderListener
{
	StaticArray<ShadowMapFrustumPtr, MAX_GSM_LODS_NUM> m_staticShadowMapFrustums;

	uint32 nUpdateMaskMT;
	uint32 nUpdateMaskRT;

	ShadowFrustumMGPUCache()
		: nUpdateMaskMT(0), nUpdateMaskRT(0)
	{
		m_staticShadowMapFrustums.fill(NULL);
	};

	virtual void SyncMainWithRender()
	{
		/** What we need here is the renderer telling the main thread to update the shadow frustum cache when all GPUs are done
		 * with the current frustum.
		 *
		 * So in case the main thread has done a full update (nUpdateMaskMT has bits for all GPUs set) we need to copy
		 * the update mask to the renderer. Note that we reset the main thread update mask in the same spot to avoid doing it in
		 * the next frame again.
		 *
		 * Otherwise just copy the renderer's progress back to the main thread. The main thread will automatically do a full update
		 * when nUpdateMaskMT reaches 0																																													*/
		const int nFullUpdateMask = (1 << gEnv->pRenderer->GetActiveGPUCount()) - 1;
		if (nUpdateMaskMT == nFullUpdateMask)
		{
			nUpdateMaskRT = nUpdateMaskMT;
			nUpdateMaskMT = 0xFFFFFFFF;
		}
		else
			nUpdateMaskMT = nUpdateMaskRT;
	}
};

static_assert(sizeof(ShadowFrustumMGPUCache) == 144);

struct SShadowFrustumToRender
{
	ShadowMapFrustumPtr     pFrustum;
	SRenderLight* pLight;
	int                     nLightID;
	_smart_ptr<IRenderView> pShadowsView;
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/CryCore/smartptr.h>
#include <Prey/CryMath/Cry_Camera.h>
#include <Prey/CryMath/Cry_Geo.h>
#include <Prey/CryRenderer/IRenderer.h>
#include <_unknown/StaticArray.h>
#include <_unknown/VectorSet.h>

class CRenderView;
class CTexture;
class ICrySizer;
struct IRenderNode;
struct IRenderView;
struct IShadowCaster;
struct SRendItem;
struct SRenderingPassInfo;
struct ShadowCasterList;
struct Sphere;

// SShadowRenderer
// Header:  CryEngine/renderdll/common/shadow_renderer.h
// Include: Prey/RenderDll/Common/Shadow_Renderer.h
struct SShadowRenderer
{ // Size=1 (0x1)
	static void RenderFrustumsToView(CRenderView* pRenderView) { FRenderFrustumsToView(pRenderView); }

	static inline auto FRenderFrustumsToView = PreyFunction<void(CRenderView* pRenderView)>(0xEDEDE0);
};

// ShadowFrustumMGPUCache
// Header:  CryEngine/renderdll/common/shadow_renderer.h
// Include: Prey/RenderDll/Common/Shadow_Renderer.h
struct ShadowFrustumMGPUCache : public ISyncMainWithRenderListener
{ // Size=144 (0x90)
	StaticArray<_smart_ptr<ShadowMapFrustum>,16,int> m_staticShadowMapFrustums;
	unsigned nUpdateMaskMT;
	unsigned nUpdateMaskRT;

	void Init() { FInit(this); }
	virtual void SyncMainWithRender();

#if 0
	ShadowFrustumMGPUCache();
	void Release();
	void DeleteFromCache(IShadowCaster* _arg0_);
#endif

	static inline auto FInit = PreyFunction<void(ShadowFrustumMGPUCache* const _this)>(0xFD55B0);
	static inline auto FSyncMainWithRender = PreyFunction<void(ShadowFrustumMGPUCache* const _this)>(0xFD75F0);
};

// ShadowMapFrustum
// Header:  CryEngine/renderdll/common/shadow_renderer.h
// Include: Prey/RenderDll/Common/Shadow_Renderer.h
struct ShadowMapFrustum : public CMultiThreadRefCount
{ // Size=4048 (0xFD0)
	enum eFrustumType
	{
		e_GsmDynamic = 0,
		e_GsmDynamicDistance = 1,
		e_GsmCached = 2,
		e_Nearest = 4,
		e_NumTypes = 5,
	};

	// ShadowMapFrustum::ShadowCacheData
	// Header:  CryEngine/renderdll/common/shadow_renderer.h
	struct ShadowCacheData
	{ // Size=112 (0x70)
		enum eUpdateStrategy
		{
			eFullUpdate = 0,
			eFullUpdateTimesliced = 1,
			eIncrementalUpdate = 2,
		};

		static constexpr const int MAX_TRAVERSAL_PATH_LENGTH = 32;
		uint8_t mOctreePath[32];
		uint8_t mOctreePathNodeProcessed[32];
		VectorSet<IShadowCaster *,std::less<IShadowCaster *>,std::allocator<IShadowCaster *> > mProcessedCasters;
		VectorSet<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64> > mProcessedTerrainCasters;

	#if 0
		ShadowCacheData();
		void Reset();
	#endif
	};

	ShadowMapFrustum::eFrustumType m_eFrustumType;
	Matrix44 mLightProjMatrix;
	Matrix44 mLightViewMatrix;
	Vec4 vFrustInfo;
	bool bUseAdditiveBlending;
	bool bIncrementalUpdate;
	bool bOmniDirectionalShadow;
	uint8_t nOmniFrustumMask;
	uint8_t nInvalidatedFrustMask[4];
	bool bBlendFrustum;
	float fBlendVal;
	unsigned nShadowGenMask;
	bool bIsMGPUCopy;
	bool bHWPCFCompare;
	bool bUseHWShadowMap;
	bool bNormalizedDepth;
	uint8_t nShadowPoolUpdateRate;
	float fWidthS;
	float fWidthT;
	float fBlurS;
	float fBlurT;
	float fShadowFadingDist;
	ETEX_Format m_eReqTF;
	ETEX_Type m_eReqTT;
	bool bUseShadowsPool;
	ShadowMapFrustum* pPrevFrustum;
	ShadowMapFrustum* pFrustumOwner;
	CTexture* pDepthTex;
	float fFOV;
	float fNearDist;
	float fFarDist;
	float fRendNear;
	int nTexSize;
	int nTextureWidth;
	int nTextureHeight;
	bool bUnwrapedOmniDirectional;
	int nShadowMapSize;
	int packX[6];
	int packY[6];
	int packWidth[6];
	int packHeight[6];
	int nResetID;
	float fFrustrumSize;
	float fProjRatio;
	float fDepthTestBias;
	float fDepthConstBias;
	float fDepthSlopeBias;
	ShadowCasterList* pCastersList;
	CCamera FrustumPlanes[6];
	unsigned nShadowGenID[2][6];
	AABB aabbCasters;
	Vec3 vLightSrcRelPos;
	Vec3 vProjTranslation;
	float fRadius;
	int nDLightId;
	int nUpdateFrameId;
	IRenderNode* pLightOwner;
	unsigned uCastersListCheckSum;
	int nShadowMapLod;
	unsigned m_Flags;
	std::array<_smart_ptr<IRenderView>, 2> m_pShadowsView;
	std::shared_ptr<ShadowMapFrustum::ShadowCacheData> pShadowCacheData;

	ShadowMapFrustum();
	virtual ~ShadowMapFrustum();
	ShadowMapFrustum& operator=(const ShadowMapFrustum& rOther) { return FoperatorEq(this, rOther); }
	void UpdateOmniFrustums() { FUpdateOmniFrustums(this); }
	void SortRenderItemsForFrustumAsync(int side, SRendItem* pFirst, uint64_t nNumRendItems) { FSortRenderItemsForFrustumAsync(this, side, pFirst, nNumRendItems); }
	void RenderShadowFrustum(CRenderView* pRenderView, CRenderView* pShadowsView, int side, bool bJobCasters) { FRenderShadowFrustum(this, pRenderView, pShadowsView, side, bJobCasters); }
	void Job_RenderShadowCastersToView(const SRenderingPassInfo& passInfo, bool bJobCasters) { FJob_RenderShadowCastersToView(this, passInfo, bJobCasters); }
	CRenderView* GetNextAvailableShadowsView(CRenderView* pMainRenderView, ShadowMapFrustum* pOwnerFrustum) { return FGetNextAvailableShadowsView(this, pMainRenderView, pOwnerFrustum); }
	_smart_ptr<ShadowMapFrustum> Clone() { alignas(_smart_ptr<ShadowMapFrustum>) std::byte _return_buf_[sizeof(_smart_ptr<ShadowMapFrustum>)]; return *FClone(this, reinterpret_cast<_smart_ptr<ShadowMapFrustum>*>(_return_buf_)); }

#if 0
	void GetSideViewport(int _arg0_, int* _arg1_) const;
	void GetTexOffset(int _arg0_, float* _arg1_, float* _arg2_, int _arg3_, int _arg4_) const;
	void RequestUpdate();
	bool isUpdateRequested(int _arg0_);
	bool IsCached() const;
	bool IntersectAABB(const AABB& _arg0_, bool* _arg1_) const;
	bool IntersectSphere(const Sphere& _arg0_, bool* _arg1_);
	void ResetCasterLists(bool _arg0_);
	void GetMemoryUsage(ICrySizer* _arg0_) const;
	int GetNumSides() const;
	CCamera GetCamera(int _arg0_) const;
#endif

	static inline auto FShadowMapFrustumOv1 = PreyFunction<void(ShadowMapFrustum* const _this)>(0x13F070);
	static inline auto FoperatorEq = PreyFunction<ShadowMapFrustum& (ShadowMapFrustum* const _this, const ShadowMapFrustum& rOther)>(0x29C030);
	static inline auto FUpdateOmniFrustums = PreyFunction<void(ShadowMapFrustum* const _this)>(0x2A55C0);
	static inline auto FSortRenderItemsForFrustumAsync = PreyFunction<void(ShadowMapFrustum* const _this, int side, SRendItem* pFirst, uint64_t nNumRendItems)>(0xEDF2E0);
	static inline auto FRenderShadowFrustum = PreyFunction<void(ShadowMapFrustum* const _this, CRenderView* pRenderView, CRenderView* pShadowsView, int side, bool bJobCasters)>(0xEDF000);
	static inline auto FJob_RenderShadowCastersToView = PreyFunction<void(ShadowMapFrustum* const _this, const SRenderingPassInfo& passInfo, bool bJobCasters)>(0xEDEB20);
	static inline auto FGetNextAvailableShadowsView = PreyFunction<CRenderView* (ShadowMapFrustum* const _this, CRenderView* pMainRenderView, ShadowMapFrustum* pOwnerFrustum)>(0xEDE940);
	static inline auto FClone = PreyFunction<_smart_ptr<ShadowMapFrustum>*(ShadowMapFrustum* const _this, _smart_ptr<ShadowMapFrustum>* _return_value_)>(0xEDE880);
};
#endif // !MOONCRASH
