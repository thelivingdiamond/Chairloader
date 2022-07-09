#include "pch.h"
#include <ChairLoader/PreyFunction.h>

namespace {
bool s_bFuncsInited = false;
PreyFunctionBase* s_pFirstFunc = nullptr;

bool s_bHooksInited = false;
PreyFunctionHookBase* s_pFirstHook = nullptr;
}

//------------------------------------------------------------
// PreyFunctionBase
//------------------------------------------------------------
PreyFunctionBase::PreyFunctionBase(uintptr_t offset)
{
	CRY_ASSERT_MESSAGE(!s_bFuncsInited, "PreyFunction must be created before DLL initialization");
	m_Ptr = offset;
	m_pNext = s_pFirstFunc;
	s_pFirstFunc = this;
}

void PreyFunctionBase::Init(uintptr_t moduleBase)
{
	// Before Init m_Ptr holds the offset
	m_Ptr = moduleBase + m_Ptr;
}

//------------------------------------------------------------
// PreyFunctionHookBase
//------------------------------------------------------------
PreyFunctionHookBase::PreyFunctionHookBase(PreyFunctionBase* origFunc)
{
	CRY_ASSERT_MESSAGE(!s_bHooksInited, "PreyFunctionHook must be created before DLL initialization");
	// Do not dereference origFunc - may not be initialized yet.
	m_pOrigFunc = origFunc;
	m_pNext = s_pFirstHook;
	s_pFirstHook = this;
}

void PreyFunctionHookBase::InstallHook()
{
	m_Hook.InstallHook(m_pOrigFunc->GetVoidPtr(), m_pHookFunc);
}

void PreyFunctionHookBase::RemoveHook()
{
	m_Hook.RemoveHook();
}

//------------------------------------------------------------
// PreyFunctionSystem
//------------------------------------------------------------
void PreyFunctionSystem::Init(uintptr_t moduleBase)
{
	CRY_ASSERT(!s_bFuncsInited);
	s_bFuncsInited = true;

	for (PreyFunctionBase* p = s_pFirstFunc; p; p = p->m_pNext) {
		p->Init(moduleBase);
	}
}

void PreyFunctionSystem::InstallHooks()
{
	CRY_ASSERT(!s_bHooksInited);
	s_bHooksInited = true;

	for (PreyFunctionHookBase* p = s_pFirstHook; p; p = p->m_pNext) {
		if (p->IsHookFuncSet())
			p->InstallHook();
	}
}

void PreyFunctionSystem::RemoveHooks()
{
	CRY_ASSERT(s_bHooksInited);
	s_bHooksInited = false;

	for (PreyFunctionHookBase* p = s_pFirstHook; p; p = p->m_pNext) {
		if (p->IsHooked())
			p->RemoveHook();
	}
}
