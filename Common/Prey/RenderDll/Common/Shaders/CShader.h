#pragma once

class CShaderMan
{
private:
	void* pad[3768 / sizeof(void*)];

public:
	CShader* mfForName(const char* nameSh, int flags, CShaderResources const* Res = nullptr, uint64_t nMaskGen = 0) { return FmfForName(this, nameSh, flags, Res, nMaskGen); }

	static inline auto FmfForName = PreyFunction<CShader* (CShaderMan* const _this, const char* nameSh, int flags, CShaderResources const* Res, uint64_t nMaskGen)>(0x10397B0);
};
