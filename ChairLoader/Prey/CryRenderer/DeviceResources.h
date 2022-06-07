#pragma once
#include <d3d11.h>

struct __declspec(align(8)) CDeviceTextureBase
{
	ID3D11Resource *m_pD3DTexture;
	unsigned __int64 m_nBaseAllocatedSize;
	ID3D11Resource *m_pStagingResource[2];
	void *m_pStagingMemory[2];
	void *m_handleMGPU;
	bool m_bNoDelete;
	bool m_bCube;
};

struct CDeviceTexture : CDeviceTextureBase
{
};
