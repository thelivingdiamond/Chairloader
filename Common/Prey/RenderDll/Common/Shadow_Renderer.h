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
