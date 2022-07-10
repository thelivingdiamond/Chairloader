#include "pch.h"
#include <detours/detours.h>
#include <ChairLoader/FunctionHook.h>

FunctionHookBase::FunctionHookBase()
{
}

FunctionHookBase::~FunctionHookBase()
{
	CRY_ASSERT_MESSAGE(!IsHooked(), "FunctionHook: RemoveHook wasn't called before destructor");
}

void FunctionHookBase::RemoveHook()
{
	CRY_ASSERT_MESSAGE(IsHooked(), "No hook installed");
	DetourDetach(&m_pfn, m_pfnHook);
	m_pfn = nullptr;
	m_pfnHook = nullptr;
}

void FunctionHookBase::InstallHook(void* origFunc, void* hookFunc)
{
	CRY_ASSERT_MESSAGE(!IsHooked(), "Hook already installed");
	m_pfn = origFunc;
	m_pfnHook = hookFunc;
	DetourAttach(&m_pfn, hookFunc);
}
