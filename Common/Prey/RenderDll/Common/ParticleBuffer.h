// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once

class CParticleBufferSet
{
	void* pad[2264 / sizeof(void*)];
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <CryEngine/renderdll/xrenderd3d9/devicemanager/d3d11/devicemanager_d3d11.inl>
#include <Prey/RenderDll/Common/DevBuffer.h>

enum class DXGI_FORMAT;
struct SParticleAxes;
struct SParticleColorST;

// CParticleSubBuffer
// Header:  CryEngine/renderdll/common/particlebuffer.h
// Include: Prey/RenderDll/Common/ParticleBuffer.h
class CParticleSubBuffer
{ // Size=128 (0x80)
public:
	CGpuBuffer m_buffer;
	uint8_t* m_pLockedData;
	unsigned m_elemCount;
	unsigned m_stride;
	unsigned m_flags;

	CParticleSubBuffer();

#if 0
	~CParticleSubBuffer();
	void Create(unsigned _arg0_, unsigned _arg1_, DXGI_FORMAT _arg2_, unsigned _arg3_);
	void Release();
	uint8_t* Lock();
	void Unlock(unsigned _arg0_);
	HRESULT BindVB(unsigned _arg0_, int _arg1_, int _arg2_);
	HRESULT BindIB(unsigned _arg0_);
	void BindSRV(CDeviceManager::SHADER_TYPE _arg0_, unsigned _arg1_);
	unsigned GetStride() const;
#endif

	static inline auto FCParticleSubBufferOv1 = PreyFunction<void(CParticleSubBuffer* const _this)>(0xE96F30);
};

// CParticleBufferSet
// Header:  CryEngine/renderdll/common/particlebuffer.h
// Include: Prey/RenderDll/Common/ParticleBuffer.h
class CParticleBufferSet
{ // Size=2264 (0x8D8)
public:
	enum EBufferTypes
	{
		EBT_Vertices = 0,
		EBT_Indices = 1,
		EBT_PositionsSRV = 2,
		EBT_AxesSRV = 3,
		EBT_ColorSTsSRV = 4,
		EBT_Total = 5,
	};

	// CParticleBufferSet::SubBuffer
	// Header:  CryEngine/renderdll/common/particlebuffer.h
	struct SubBuffer
	{ // Size=424 (0x1A8)
		std::array<CParticleSubBuffer, 3> m_buffers;
		uint8_t* m_pMemoryBase[3];
		unsigned m_offset[3];
		unsigned m_availableMemory;
	};

	// CParticleBufferSet::SAlloc
	// Header:  CryEngine/renderdll/common/particlebuffer.h
	struct SAlloc
	{ // Size=16 (0x10)
		uint8_t* m_pBase;
		unsigned m_firstElem;
		unsigned m_numElemns;
	};

	// CParticleBufferSet::SAllocStreams
	// Header:  CryEngine/renderdll/common/particlebuffer.h
	struct SAllocStreams
	{ // Size=32 (0x20)
		Vec3* m_pPositions;
		SParticleAxes* m_pAxes;
		SParticleColorST* m_pColorSTs;
		unsigned m_firstElem;
		unsigned m_numElemns;
	};

	using TDynBuffer = std::array<CParticleSubBuffer, 3>;
	using TDeviceFences = std::array<uint64_t, 3>;

	std::array<CParticleBufferSet::SubBuffer, 5> m_subBuffers;
	std::array<uint64_t, 3> m_fences;
	CGpuBuffer m_spriteIndexBuffer;
	unsigned m_maxSpriteCount;
	unsigned m_ids[2];
	bool m_valid;

	CParticleBufferSet();
	~CParticleBufferSet();
	void Create(unsigned poolSize) { FCreate(this, poolSize); }
	void Release() { FRelease(this); }
	void Lock() { FLock(this); }
	void Unlock() { FUnlock(this); }
	void SetFence() { FSetFence(this); }
	void WaitForFence() { FWaitForFence(this); }
	bool IsValid() const { return FIsValid(this); }
	unsigned GetAllocId() const { return FGetAllocId(this); }
	void Alloc(unsigned index, CParticleBufferSet::EBufferTypes type, unsigned numElems, CParticleBufferSet::SAlloc* pAllocOut) { FAllocOv1(this, index, type, numElems, pAllocOut); }
	void Alloc(unsigned index, unsigned numElems, CParticleBufferSet::SAllocStreams* pAllocOut) { FAllocOv0(this, index, numElems, pAllocOut); }
	void BindVB() { FBindVB(this); }
	void BindIB() { FBindIB(this); }
	void BindSRVs() { FBindSRVs(this); }
	void BindSpriteIB() { FBindSpriteIB(this); }
	void CreateSubBuffer(CParticleBufferSet::EBufferTypes type, unsigned elemsCount, unsigned stride, DXGI_FORMAT format, unsigned flags) { FCreateSubBuffer(this, type, elemsCount, stride, format, flags); }

#if 0
	unsigned GetMaxNumSprites() const;
	unsigned GetBindId() const;
	void CreateSpriteBuffer(unsigned _arg0_);
#endif

	static inline auto FCParticleBufferSetOv1 = PreyFunction<void(CParticleBufferSet* const _this)>(0xE96E20);
	static inline auto FBitNotCParticleBufferSet = PreyFunction<void(CParticleBufferSet* const _this)>(0xE97030);
	static inline auto FCreate = PreyFunction<void(CParticleBufferSet* const _this, unsigned poolSize)>(0xE97340);
	static inline auto FRelease = PreyFunction<void(CParticleBufferSet* const _this)>(0xE978F0);
	static inline auto FLock = PreyFunction<void(CParticleBufferSet* const _this)>(0xE97710);
	static inline auto FUnlock = PreyFunction<void(CParticleBufferSet* const _this)>(0xE97A50);
	static inline auto FSetFence = PreyFunction<void(CParticleBufferSet* const _this)>(0x1333E90);
	static inline auto FWaitForFence = PreyFunction<void(CParticleBufferSet* const _this)>(0x1333E90);
	static inline auto FIsValid = PreyFunction<bool(const CParticleBufferSet* const _this)>(0xE976C0);
	static inline auto FGetAllocId = PreyFunction<unsigned(const CParticleBufferSet* const _this)>(0xE976A0);
	static inline auto FAllocOv1 = PreyFunction<void(CParticleBufferSet* const _this, unsigned index, CParticleBufferSet::EBufferTypes type, unsigned numElems, CParticleBufferSet::SAlloc* pAllocOut)>(0xE97140);
	static inline auto FAllocOv0 = PreyFunction<void(CParticleBufferSet* const _this, unsigned index, unsigned numElems, CParticleBufferSet::SAllocStreams* pAllocOut)>(0xE97080);
	static inline auto FBindVB = PreyFunction<void(CParticleBufferSet* const _this)>(0xE972F0);
	static inline auto FBindIB = PreyFunction<void(CParticleBufferSet* const _this)>(0xE971D0);
	static inline auto FBindSRVs = PreyFunction<void(CParticleBufferSet* const _this)>(0xE97230);
	static inline auto FBindSpriteIB = PreyFunction<void(CParticleBufferSet* const _this)>(0xE972C0);
	static inline auto FCreateSubBuffer = PreyFunction<void(CParticleBufferSet* const _this, CParticleBufferSet::EBufferTypes type, unsigned elemsCount, unsigned stride, DXGI_FORMAT format, unsigned flags)>(0xE975C0);
};
#endif // !MOONCRASH
