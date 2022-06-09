#include "pch.h"
#include <cstdlib>
#include <cstring>
#include "VTableHook.h"

void VTableHook::HookObject(uintptr_t obj) {
	uintptr_t *vtable = *((uintptr_t **)obj);
	m_pMemory = new uintptr_t[DATA_BEFORE_START + VTABLE_SIZE];
	memcpy(m_pMemory, vtable - DATA_BEFORE_START, DATA_BEFORE_START + VTABLE_SIZE);
	*((uintptr_t **)obj) = m_pMemory + DATA_BEFORE_START;
}

uintptr_t VTableHook::HookMethod(size_t idx, uintptr_t newMethod)
{
	size_t memidx = DATA_BEFORE_START + idx;
	uintptr_t old = m_pMemory[memidx];
	void (*debug)() = (void (*)())old;
	(void)debug;
	m_pMemory[memidx] = newMethod;
	return old;
}

