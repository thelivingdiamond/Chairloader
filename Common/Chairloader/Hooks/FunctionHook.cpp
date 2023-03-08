#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryCore/Platform/WindowsUtils.h>
#include <detours/detours.h>
#include <ChairLoader/Hooks/FunctionHook.h>
#include <ChairLoader/Hooks/HookTransaction.h>

FunctionHookBase::FunctionHookBase()
{
}

FunctionHookBase::~FunctionHookBase()
{
#ifdef DEBUG_BUILD
	// If the game crashed, destructors may still be called, even though shutdown code didn't run.
	CRY_ASSERT_MESSAGE(!IsHooked(), "FunctionHook: RemoveHook wasn't called before destructor. Ignore if the game crashed.");
#endif
}

void FunctionHookBase::RemoveHook()
{
	if (!HookTransaction::GetCurrent())
		throw std::logic_error("RemoveHook must be called in a transaction.");

	if (!IsHooked())
	{
		CRY_ASSERT_MESSAGE(IsHooked(), "No hook installed.");
		throw std::logic_error("No hook installed.");
	}
	
	LONG result = DetourDetach(&m_pfn, m_pfnHook);
	HookTransaction::GetCurrent()->SaveDetoursError(m_pfnHook, result);

	m_pfn = nullptr;
	m_pfnHook = nullptr;
}

void FunctionHookBase::InstallHook(void* origFunc, void* hookFunc)
{
	if (!HookTransaction::GetCurrent())
		throw std::logic_error("InstallHook must be called in a transaction.");

	if (IsHooked())
	{
		CRY_ASSERT_MESSAGE(IsHooked(), "Hook already installed.");
		throw std::logic_error("Hook already installed.");
	}

	m_pfn = origFunc;
	m_pfnHook = hookFunc;
	LONG result = DetourAttach(&m_pfn, hookFunc);

#ifdef DEBUG_BUILD
	if (result != NO_ERROR)
	{
		// Error 9 (ERROR_INVALID_BLOCK): The function referenced is too small to be detoured
		// Make sure you don't have a breakpoint set in the function.
		// This prevents Detours from hooking it because the debugger silently
		// adds "int 3" instruction to the function.

		std::string errorText = WindowsErrorToString(result);
		if (IsDebuggerPresent())
			__debugbreak();
	}
#endif

	HookTransaction::GetCurrent()->SaveDetoursError(m_pfnHook, result);
}
