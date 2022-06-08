#pragma once
#include "proc.h"
#include "pch.h"
namespace mem {
	void PatchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProcess);
	void NopEx(BYTE* dst, unsigned int size, HANDLE hProcess);
	uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int>);



	void Patch(BYTE* dst, BYTE* src, unsigned int size);
	void Nop(BYTE* dst, unsigned int size);
	uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int>);

	template <typename T, typename S>
	T &OffsetInStruct(S *s, size_t offset) {
		uintptr_t ptr = reinterpret_cast<uintptr_t>(s);
		uintptr_t field = ptr + offset;
		return *reinterpret_cast<T *>(field);
	}
}
