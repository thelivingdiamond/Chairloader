// Auto-merged (both): base=PreyDll under #ifndef MOONCRASH; DLC=Mooncrash.
#ifndef MOONCRASH
#pragma once

class CLightVolumeBuffer
{
	void* pad[216 / sizeof(void*)];
};
#else // MOONCRASH
// Header file automatically created from a PDB.
#pragma once
#include <Prey/RenderDll/Common/DevBuffer.h>

// CLightVolumeBuffer
// Header:  CryEngine/renderdll/common/LightVolumeBuffer.h
// Include: Prey/RenderDll/Common/LightVolumeBuffer.h
class CLightVolumeBuffer
{ // Size=216 (0xD8)
public:
	CGpuBuffer m_lightInfosBuffer;
	CGpuBuffer m_lightRangesBuffer;
	unsigned m_numVolumes;

	CLightVolumeBuffer();
	void Create() { FCreate(this); }
	void Release() { FRelease(this); }
	void UpdateContent() { FUpdateContent(this); }
	void BindSRVs() { FBindSRVs(this); }

#if 0
	bool HasVolumes() const;
	unsigned GetNumVolumes() const;
#endif

	static inline auto FCLightVolumeBufferOv2 = PreyFunction<void(CLightVolumeBuffer* const _this)>(0xE96720);
	static inline auto FCreate = PreyFunction<void(CLightVolumeBuffer* const _this)>(0xE96850);
	static inline auto FRelease = PreyFunction<void(CLightVolumeBuffer* const _this)>(0xE968C0);
	static inline auto FUpdateContent = PreyFunction<void(CLightVolumeBuffer* const _this)>(0xE968E0);
	static inline auto FBindSRVs = PreyFunction<void(CLightVolumeBuffer* const _this)>(0xE967C0);
};
#endif // !MOONCRASH
