#pragma once
#include <cstdint>

//! Class for changing virtual functions on per-object basis.
//! Makes a copy of the object's vtable. Objects that have multiple
//! vtables will need multiple VTableHook instances.
class VTableHook {
public:
	//! Initializes the hook for specified object.
	void HookObject(uintptr_t obj);

	//! Replaces and object's method in vtable with a different one. 
	uintptr_t HookMethod(size_t idx, uintptr_t newMethod);

	template <typename T>
	void HookObject(T *obj) {
		HookObject(reinterpret_cast<uintptr_t>(obj));
	}

	template <typename T>
	T *HookMethod(size_t idx, T *newMethod) {
		uintptr_t oldNethod = HookMethod(idx, reinterpret_cast<uintptr_t>(newMethod));
		return reinterpret_cast<T *>(oldNethod);
	}

private:
	static constexpr size_t DATA_BEFORE_START = 32;
	static constexpr size_t VTABLE_SIZE = 512;

	uintptr_t *m_pMemory = nullptr;
};
