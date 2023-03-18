#include <Chairloader/Hooks/HookTransaction.h>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryCore/Platform/WindowsUtils.h>
#include <detours/detours.h>

//! The current transaction pointer.
//! Detours only allows one transaction at a time so it doesn't need to be thread_local.
static HookTransaction* g_pCurrentTransaction = nullptr;

HookTransaction::HookTransaction()
{
	LONG result = DetourTransactionBegin();

	if (result != NO_ERROR)
	{
		throw std::runtime_error(fmt::format("DetourTransactionBegin - {}: {}",
			result, WindowsErrorToString(result)));
	}

	assert(!g_pCurrentTransaction);
	g_pCurrentTransaction = this;
	m_bInTransaction = true;
}

HookTransaction::~HookTransaction()
{
	if (m_bInTransaction)
		Abort();

	assert(g_pCurrentTransaction == this);
	g_pCurrentTransaction = nullptr;
}

void HookTransaction::Commit()
{
	if (m_bInTransaction)
	{
		LONG result = DetourTransactionCommit();

		// Transaction is automatically aborted if commit fails.
		m_bInTransaction = false;

		if (result != NO_ERROR)
		{
			std::string firstError;
			if (m_pFirstErrorFunc)
			{
				firstError = fmt::format(
					"First error:\n"
					"{:p}: Code {}: {}\n",
					m_pFirstErrorFunc, m_FirstErrorValue, WindowsErrorToString(m_FirstErrorValue)
				);
			}
			else
			{
				firstError = "No errors occured in DetourAttach.\n";
			}

			std::string message = fmt::format(
				"Failed to commit a Detours transaction:\n"
				" - Code {}: {}\n"
				"\n"
				"{}",
				result, WindowsErrorToString(result), firstError
			);

			throw std::runtime_error(message);
		}
	}
}

void HookTransaction::CommitOrDie()
{
	try
	{
		Commit();
	}
	catch (const std::exception& e)
	{
		if (gEnv && gEnv->pSystem)
			gEnv->pSystem->FatalError("%s", e.what());
		else
			MessageBoxA(nullptr, e.what(), "HookTransaction fatal error", MB_OK | MB_ICONERROR);

		std::exit(-1);
	}
}

void HookTransaction::Abort()
{
	if (m_bInTransaction)
	{
		LONG result = DetourTransactionAbort();

		// DetourTransactionAbort ideally shouldn't fail.
		// Can't throw because may be called from a destructor.
		CRY_ASSERT_MESSAGE(result == NO_ERROR, "DetourTransactionAbort failed");

		m_bInTransaction = false;
	}
}

HookTransaction* HookTransaction::GetCurrent()
{
	return g_pCurrentTransaction;
}

void HookTransaction::SaveDetoursError(void* hook, long error)
{
	assert(m_bInTransaction);
	if (error != NO_ERROR && !m_pFirstErrorFunc)
	{
		m_pFirstErrorFunc = hook;
		m_FirstErrorValue = error;
	}
}
