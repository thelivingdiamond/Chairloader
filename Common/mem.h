#pragma once
namespace mem {
	void PatchEx(uint8_t* dst, uint8_t* src, unsigned int size, void* hProcess);
	void NopEx(uint8_t* dst, unsigned int size, void* hProcess);
	uintptr_t FindDMAAddy(void* hProc, uintptr_t ptr, std::vector<unsigned int>);



	void Patch(uint8_t* dst, uint8_t* src, unsigned int size);
	void Nop(uint8_t* dst, unsigned int size);
	uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int>);

	template <typename T, typename S>
	T &OffsetInStruct(S *s, size_t offset) {
		uintptr_t ptr = reinterpret_cast<uintptr_t>(s);
		uintptr_t field = ptr + offset;
		return *reinterpret_cast<T *>(field);
	}
}
