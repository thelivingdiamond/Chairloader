// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once

class CDeviceManager
{
private:
	void* pad[14664 / sizeof(void*)];

public:
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	static uint8* Map(D3DBuffer* buffer, uint32 subresource, size_t offset, size_t size, D3D11_MAP mode) { return FMap(buffer,subresource,offset,size,mode); }
	static void Unmap(D3DBuffer* buffer, uint32 subresource, size_t offset, size_t size, D3D11_MAP mode) { FUnmap(buffer, subresource, offset, size, mode); }

	// NOTE: Standard behaviour in the presence of multiple GPUs is to make the same data available to all
	// GPUs. If data should diverge per GPU, it can be uploaded by concatenating multiple divergent data-blocks
	// and passing the appropriate "numDataBlocks". Each GPU will then receive it's own version of the data.
	template<const bool bDirectAccess = false>
	static void UploadContents(D3DBuffer* buffer, uint32 subresource, size_t offset, size_t size, D3D11_MAP mode, const void* pInDataCPU, void* pOutDataGPU = nullptr, UINT numDataBlocks = 1);

	static inline auto FMap = PreyFunction<uint8* (ID3D11Buffer* buffer, unsigned subresource, uint64_t offset, uint64_t size, D3D11_MAP mode)>(0x10557F0);
	static inline auto FUnmap = PreyFunction<void(ID3D11Buffer* buffer, unsigned subresource, uint64_t offset, uint64_t size, D3D11_MAP mode)>(0x1056030);
	static inline auto FUploadContents = PreyFunction<void(D3DBuffer* buffer, uint32 subresource, size_t offset, size_t size, D3D11_MAP mode, const void* pInDataCPU, void* pOutDataGPU, UINT numDataBlocks)>(0x1053070);
};

template<bool bDirectAccess>
inline void CDeviceManager::UploadContents(D3DBuffer* buffer, uint32 subresource, size_t offset, size_t size, D3D11_MAP mode, const void* pInDataCPU, void* pOutDataGPU, UINT numDataBlocks)
{
	static_assert(!bDirectAccess, "Only bDirectAccess is supported");
	FUploadContents(buffer, subresource, offset, size, mode, pInDataCPU, pOutDataGPU, numDataBlocks);
}
#else // MOONCRASH
// Header file automatically created from a PDB.
// WARNING: Contains templates
#pragma once
#include <CryEngine/renderdll/xrenderd3d9/devbuffer.h>
#include <_unknown/CTrackedItemAllocatorBase.h>

// CTrackedItemAllocator<CGpuBuffer::STrackedGpuBuffer>
// Header:  CryEngine/renderdll/xrenderd3d9/devicemanager/devicemanager.h
class CTrackedItemAllocator<CGpuBuffer::STrackedGpuBuffer> : public CTrackedItemAllocatorBase<CGpuBuffer::STrackedGpuBuffer>
{ // Size=24 (0x18)
public:
	~CTrackedItemAllocator<CGpuBuffer::STrackedGpuBuffer>();

#if 0
	CTrackedItemAllocator<CGpuBuffer::STrackedGpuBuffer>();
	void Reset();
	CGpuBuffer::STrackedGpuBuffer* Allocate(bool* _arg0_);
#endif

	static inline auto FBitNotCTrackedItemAllocatorLessCGpuBuffer::STrackedGpuBufferGreater = PreyFunction<void(CTrackedItemAllocator<CGpuBuffer::STrackedGpuBuffer>* const _this)>(0x1066B30);
};

// SUsageTrackedItem
// Header:  CryEngine/renderdll/xrenderd3d9/devicemanager/devicemanager.h
// Include: Prey/RenderDll/XRenderD3D9/DeviceManager/DeviceManager.h
class SUsageTrackedItem
{ // Size=4 (0x4)
public:
	unsigned m_lastUseFrame;

	void MarkUsed() { FMarkUsed(this); }
	bool IsInUse() const { return FIsInUse(this); }

#if 0
	SUsageTrackedItem();
	SUsageTrackedItem(unsigned _arg0_);
#endif

	static inline auto FMarkUsed = PreyFunction<void(SUsageTrackedItem* const _this)>(0x1071EC0);
	static inline auto FIsInUse = PreyFunction<bool(const SUsageTrackedItem* const _this)>(0x1071D90);
};
#endif // !MOONCRASH
