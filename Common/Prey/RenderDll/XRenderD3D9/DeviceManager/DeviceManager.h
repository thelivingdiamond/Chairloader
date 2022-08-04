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
