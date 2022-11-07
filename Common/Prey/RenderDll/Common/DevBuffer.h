#pragma once
#include <Prey/CryRenderer/CryDX.h>

typedef uintptr_t buffer_handle_t;
typedef uint32    item_handle_t;

////////////////////////////////////////////////////////////////////////////////////////
// Constant buffer wrapper class
class CConstantBuffer
{
public:
	D3DBuffer* m_buffer;
	void* m_base_ptr;
	item_handle_t m_handle;
	uint32        m_offset;
	uint32        m_size;
	int32         m_nRefCount;
	union
	{
		struct
		{
			uint8 m_used : 1;
			uint8 m_lock : 1;
			uint8 m_dynamic : 1;
			uint8 m_intentionallyNull : 1;
		};

		uint8 m_clearFlags;
	};

	CConstantBuffer(uint32 handle);
	~CConstantBuffer();

	inline void AddRef()
	{
		CryInterlockedIncrement(&m_nRefCount);
	}

	inline void Release()
	{
		if (CryInterlockedDecrement(&m_nRefCount) == 0)
			ReturnToPool();
	}

	inline D3DBuffer* GetD3D(size_t* offset, size_t* size) const
	{
		*offset = m_offset;
		*size = m_size;
		return m_buffer;
	}

	inline uint64 GetCode() const
	{
#if CONSTANT_BUFFER_ENABLE_DIRECT_ACCESS || defined(OPENGL)
		uint64 code = reinterpret_cast<uintptr_t>(m_buffer) | ((uint64)m_offset << 40);//|(((uint64)m_size>>4)<<60); Size will follow buffer address, so we just need offset
		return code;
#else
		return reinterpret_cast<uint64>(m_buffer);
#endif
	}

	void* BeginWrite();
	void  EndWrite(bool requires_flush = false);
	void  UpdateBuffer(const void*, size_t, uint32 numDataBlocks = 1); // See CDeviceManager::UploadContents for details on numDataBlocks

private:
	void  ReturnToPool();
};
typedef _smart_ptr<CConstantBuffer> CConstantBufferPtr;

class CDeviceBufferManager
{
	// No fields
};
