#include "pch.h"
#include <ChairLoader/PreyFunction.h>

namespace {
bool s_bInitialized = false;
PreyFunctionBase* s_pFirstFunc = nullptr;
}

PreyFunctionBase::PreyFunctionBase(uintptr_t offset)
{
	CRY_ASSERT_MESSAGE(!s_bInitialized, "PreyFunction must be created before DLL initialization");
	m_Ptr = offset;
	m_pNext = s_pFirstFunc;
	s_pFirstFunc = this;
}

void PreyFunctionBase::Init(uintptr_t moduleBase)
{
	// Before Init m_Ptr holds the offset
	m_Ptr = moduleBase + m_Ptr;
}

void PreyFunctionSystem::Init(uintptr_t moduleBase)
{
	CRY_ASSERT(!s_bInitialized);
	s_bInitialized = true;

	for (PreyFunctionBase* p = s_pFirstFunc; p; p = p->m_pNext) {
		p->Init(moduleBase);
	}
}
