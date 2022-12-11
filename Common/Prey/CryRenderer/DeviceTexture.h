#pragma once
#include <functional>
#include <ChairLoader/PreyFunction.h>
#include "ITexture.h"
#include "CryDX.h"

class CDeviceTextureBase
{
protected:
	friend class CDeviceManager;

	D3DBaseTexture *m_pD3DTexture = nullptr;
	// for native hand-made textures
	size_t          m_nBaseAllocatedSize = 0;
	D3DResource *m_pStagingResource[2];
	void *m_pStagingMemory[2];
	void *m_handleMGPU = nullptr;
	bool            m_bNoDelete = false;
	bool            m_bCube = false;

public:
	inline ID3D11Resource *GetBaseTexture() {
		return m_pD3DTexture;
	}
	D3DLookupTexture *GetLookupTexture() {
		return (D3DLookupTexture *)GetBaseTexture();
	}
	D3DTexture *Get2DTexture() {
		return (D3DTexture *)GetBaseTexture();
	}
	D3DCubeTexture *GetCubeTexture() {
		return (D3DCubeTexture *)GetBaseTexture();
	}
	D3DVolumeTexture *GetVolumeTexture() {
		return (D3DVolumeTexture *)GetBaseTexture();
	}

	bool IsCube() const {
		return m_bCube;
	}

	void Unbind();

	void DisableMgpuSync();
	void MgpuResourceUpdate(bool bUpdating = true);

	CDeviceTextureBase() : m_pD3DTexture(NULL), m_nBaseAllocatedSize(0), m_bNoDelete(false), m_bCube(false)
		, m_handleMGPU(NULL)
	{
		m_pStagingResource[0] = m_pStagingResource[1] = nullptr;
		m_pStagingMemory[0] = m_pStagingMemory[1] = nullptr;
	}

	CDeviceTextureBase(D3DBaseTexture *pBaseTexture) : m_pD3DTexture(pBaseTexture), m_nBaseAllocatedSize(0), m_bNoDelete(false), m_bCube(false)
		, m_handleMGPU(NULL)
	{
		m_pStagingResource[0] = m_pStagingResource[1] = nullptr;
		m_pStagingMemory[0] = m_pStagingMemory[1] = nullptr;
	}

	CDeviceTextureBase(D3DCubeTexture *pBaseTexture) : m_pD3DTexture(pBaseTexture), m_nBaseAllocatedSize(0), m_bNoDelete(false), m_bCube(true)
		, m_handleMGPU(NULL)
	{
		m_pStagingResource[0] = m_pStagingResource[1] = nullptr;
		m_pStagingMemory[0] = m_pStagingMemory[1] = nullptr;
	}

	typedef std::function<bool(void *, uint32, uint32)> StagingHook;

	void   DownloadToStagingResource(uint32 nSubRes, StagingHook cbTransfer);
	void   DownloadToStagingResource(uint32 nSubRes);
	void   UploadFromStagingResource(uint32 nSubRes, StagingHook cbTransfer);
	void   UploadFromStagingResource(uint32 nSubRes);
	void   AccessCurrStagingResource(uint32 nSubRes, bool forUpload, StagingHook cbTransfer);

	size_t GetDeviceSize() const {
		return m_nBaseAllocatedSize;
	}

	//void GetMemoryUsage(ICrySizer *pSizer) const {
	//	pSizer->AddObject(this, sizeof(*this));
	//}

	void  SetNoDelete(bool noDelete) {
		m_bNoDelete = noDelete;
	}

protected:
	~CDeviceTextureBase() { Cleanup(); }

private:
	CDeviceTextureBase(const CDeviceTextureBase &);
	CDeviceTextureBase &operator=(const CDeviceTextureBase &);

private:
	int Cleanup();
};

class CDeviceTexture : public CDeviceTextureBase
{
public:
	static inline auto FCleanup = PreyFunction<int(CDeviceTextureBase* _this)>(0x1054080);
	using CDeviceTextureBase::CDeviceTextureBase;
	~CDeviceTexture();

	CDeviceTexture()
	{
		m_pStagingResource[0] = m_pStagingResource[1] = nullptr;
		m_pStagingMemory[0] = m_pStagingMemory[1] = nullptr;
	}

	CDeviceTexture(D3DCubeTexture* pBaseTexture)
	{
		m_pD3DTexture = pBaseTexture;
		m_pStagingResource[0] = m_pStagingResource[1] = nullptr;
		m_pStagingMemory[0] = m_pStagingMemory[1] = nullptr;
	}

	int32 Release();
	static uint32 TextureDataSize(D3DBaseView *pView);
	static uint32 TextureDataSize(D3DBaseView *pView, const uint numRects, const RECT *pRects);
	static uint32 TextureDataSize(uint32 nWidth, uint32 nHeight, uint32 nDepth, uint32 nMips, uint32 nSlices, const ETEX_Format eTF);
private:
	int Cleanup();
};
