// Most of the code was stolen from
// https://github.com/tmp64/BugfixedHL-Rebased/blob/master/src/game/client/engine_patches_windows.cpp
// Licensed under GPL v3
#define NOMINMAX
#include <Windows.h>
#include <DbgHelp.h>
#include <psapi.h>
#include "CrashHandler.h"

#define CRASHED_APP_NAME "ChairManager"
#define GITHUB_URL "https://github.com/thelivingdiamond/Chairloader"

constexpr DWORD CPP_EXCEPTION_CODE = 0xE06D7363u;
static CrashHandler s_CrashHandler;

CrashHandler& CrashHandler::Get()
{
	return s_CrashHandler;
}

void CrashHandler::AddExceptionHandler()
{
	if (!m_hHandler)
	{
		m_hHandler = AddVectoredExceptionHandler(TRUE, [](PEXCEPTION_POINTERS pExceptionInfo)
			{
				return s_CrashHandler.VectoredExceptionsHandler(pExceptionInfo);
			});
	}
}

void CrashHandler::HandleFatalError(ChairStackWalker& sw, const char* errorText, PEXCEPTION_POINTERS pExceptionInfo)
{
	time_t timestamp = time(nullptr);
	localtime_s(&m_CrashTime, &timestamp);
	strftime(m_szCrashFileName, sizeof(m_szCrashFileName), CRASHED_APP_NAME "-Crash-%Y-%m-%d-%H-%M-%S", &m_CrashTime);

	CreateCrashReport(sw, errorText);
	CreateMiniDump(pExceptionInfo);
	ShowCrashDialog(errorText);

	// Application will die anyway, so futher exceptions are not interesting to us
	RemoveVectoredExceptionHandler(m_hHandler);
	m_hHandler = nullptr;
}

void CrashHandler::CreateCrashReport(ChairStackWalker& sw, const char* errorText) noexcept
{
	char filename[MAX_PATH];
	snprintf(filename, sizeof(filename), "%s.txt", m_szCrashFileName);

	FILE* file = fopen(filename, "w");

	if (file)
	{
		fprintf(file, CRASHED_APP_NAME " Crash Log\n\n");
		fprintf(file, "%s\n", errorText);
		fprintf(file, "\n");

		fprintf(file, "Please post the contents of this log file and file %s.dmp on\n", m_szCrashFileName);
		fprintf(file, GITHUB_URL "/issues\n");
		fprintf(file, "\n\n\n\n\n");
		fprintf(file, "-------------------------------------------------------------------------\n");
		fprintf(file, "Technical information\n");
		fprintf(file, "\n");

		PrintSystemInfo(file);
		PrintStackTrace(file, sw);
		PrintModuleList(file);
		ValidateHeap(file);

		fclose(file);

		char buf[512];
		snprintf(buf, sizeof(buf), "notepad %s", filename);

		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(si));
		si.cb = sizeof(si);
		ZeroMemory(&pi, sizeof(pi));

		CreateProcess(NULL, // No module name (use command line)
			buf, // Command line
			NULL, // Process handle not inheritable
			NULL, // Thread handle not inheritable
			FALSE, // Set handle inheritance to FALSE
			0, // No creation flags
			NULL, // Use parent's environment block
			NULL, // Use parent's starting directory
			&si, // Pointer to STARTUPINFO structure
			&pi); // Pointer to PROCESS_INFORMATION structure

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

void CrashHandler::PrintSystemInfo(FILE* file)
{
	const char* debugBuild = "";
#ifdef DEBUG_BUILD
	debugBuild = " [Debug Build]";
#endif

	char buffer[128];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &m_CrashTime);
	fprintf(file, "Local time: %s\n", buffer);

	// OS version
	// This is so ugly...
	fprintf(file, "OS version: ");
	{
		DWORD handle;
		DWORD size = GetFileVersionInfoSizeA("kernel32.dll", &handle);

		if (size != 0)
		{
			char* verBuf = (char*)malloc(size);

			if (verBuf)
			{
				if (GetFileVersionInfoA("kernel32.dll", 0, size, verBuf))
				{
					VS_FIXEDFILEINFO* info = nullptr;
					UINT infoSize;

					if (VerQueryValueA(verBuf, "\\", (LPVOID*)&info, &infoSize))
					{

						if (infoSize != 0)
						{
							fprintf(file, "%u.%u.%u.%u\n",
								HIWORD(info->dwFileVersionMS),
								LOWORD(info->dwFileVersionMS),
								HIWORD(info->dwFileVersionLS),
								LOWORD(info->dwFileVersionLS));
						}
						else
						{
							fprintf(file, "infoSize = 0\n");
						}
					}
					else
					{
						fprintf(file, "VerQueryValueA failed\n");
					}
				}
				else
				{
					fprintf(file, "GetFileVersionInfoA failed\n");
				}
			}
			else
			{
				fprintf(file, "malloc(%u) failed\n", size);
			}
		}
		else
		{
			fprintf(file, "GetFileVersionInfoSizeA failed\n");
		}
	}

	fprintf(file, "\n");
}

void CrashHandler::PrintStackTrace(FILE* file, ChairStackWalker& sw)
{
	fprintf(file, "Stack trace:\n");
	fwrite(sw.GetTextBuf().c_str(), 1, sw.GetTextBuf().size(), file);
	fprintf(file, "\n");
}

void CrashHandler::PrintModuleList(FILE* file)
{
	// Get modules info
	HMODULE hMods[1024];
	HANDLE hProcess = GetCurrentProcess();
	MODULEINFO moduleInfo;
	DWORD cbNeeded;
	EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded);
	int count = cbNeeded / sizeof(HMODULE);

	fprintf(file, "Modules:\n");
	fprintf(file, "  Base     Size     Path (Exception Offset)\n");
	for (int i = 0; i < count; i++)
	{
		GetModuleInformation(hProcess, hMods[i], &moduleInfo, sizeof(moduleInfo));
		DWORD moduleBase = (DWORD)moduleInfo.lpBaseOfDll;
		DWORD moduleSize = (DWORD)moduleInfo.SizeOfImage;

		// Get the full path to the module's file.
		TCHAR szModName[MAX_PATH];
		if (GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
		{
			fprintf(file, "  %08X %08X %s\n", moduleBase, moduleSize, szModName);
		}
		else
		{
			fprintf(file, "  %08X %08X\n", moduleBase, moduleSize);
		}
	}

	fprintf(file, "\n");
}

void CrashHandler::ValidateHeap(FILE* file)
{
	fprintf(file, "Validating heap\n");
	fflush(file); // Flush in case heap validation causes a crash
	
#ifdef _DEBUG // Must use _DEBUG, not DEBUG_BUILD, because _CrtCheckMemory only works with Debug CRT
	fprintf(file, "Debug heap: ");
	if (!_CrtCheckMemory())
	{
		fprintf(file, "HEAP CORRUPTED\n");
	}
	else
	{
		fprintf(file, "validated successfully\n");
	}
#endif

	fprintf(file, "Process heap: ");
	if (!HeapValidate(GetProcessHeap(), 0, nullptr))
	{
		fprintf(file, "HEAP CORRUPTED\n");
	}
	else
	{
		fprintf(file, "validated successfully\n");
	}
}

void CrashHandler::CreateMiniDump(PEXCEPTION_POINTERS pExceptionInfo)
{
	char filename[MAX_PATH];
	snprintf(filename, sizeof(filename), "%s.dmp", m_szCrashFileName);
	HANDLE hProcess = GetCurrentProcess();
	HANDLE hMiniDumpFile = CreateFile(filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH, NULL);

	if (hMiniDumpFile != INVALID_HANDLE_VALUE)
	{
		MINIDUMP_EXCEPTION_INFORMATION eInfo;
		eInfo.ThreadId = GetCurrentThreadId();
		eInfo.ExceptionPointers = pExceptionInfo;
		eInfo.ClientPointers = FALSE;
		MiniDumpWriteDump(
			hProcess,							// hProcess
			GetCurrentProcessId(),				// ProcessId
			hMiniDumpFile,						// hFile
			MiniDumpNormal,						// DumpType
			pExceptionInfo ? &eInfo : nullptr,	// ExceptionParam
			nullptr,							// UserStreamParam
			nullptr								// CallbackParam
		);
		CloseHandle(hMiniDumpFile);
	}
}

void CrashHandler::ShowCrashDialog(const char* errorText)
{
	char buf[1024];
	snprintf(buf, sizeof(buf),
		CRASHED_APP_NAME " has crashed.\n"
		"%s\n"
		"\n"
		"A crash log file was opened in Notepad.\n"
		"Please report its contents as well as file named %s.dmp on GitHub.\n"
		"\n"
		GITHUB_URL "/issues",
		errorText,
		m_szCrashFileName);

	MessageBoxA(GetActiveWindow(), buf, "Error!", MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND | MB_TOPMOST);
}

LONG CrashHandler::VectoredExceptionsHandler(PEXCEPTION_POINTERS pExceptionInfo) noexcept
{
	DWORD exceptionCode = pExceptionInfo->ExceptionRecord->ExceptionCode;
	DWORD exceptionAddress = (long)pExceptionInfo->ExceptionRecord->ExceptionAddress;

	// Ignore C++ exceptions
	if (exceptionCode == CPP_EXCEPTION_CODE)
		return EXCEPTION_CONTINUE_SEARCH;

	// We will handle all fatal unexpected exceptions, like STATUS_ACCESS_VIOLATION
	if ((exceptionCode & 0xF0000000L) == 0xC0000000L)
	{
		char errorText[256];
		snprintf(errorText, sizeof(errorText),
			"Exception %s (0x%08X) at address 0x%08X (%s)",
			ExceptionCodeString(exceptionCode),
			exceptionCode,
			exceptionAddress,
			GetModuleNameForAddress(exceptionAddress)
		);

		ChairStackWalker sw(StackWalker::OptionsAll, nullptr, GetCurrentProcessId(), GetCurrentProcess());
		sw.ShowCallstack(GetCurrentThread(), pExceptionInfo->ContextRecord);
		HandleFatalError(sw, errorText, pExceptionInfo);

		// Die
		ExitProcess(-1);
	}

	return EXCEPTION_CONTINUE_SEARCH;
}

const char* CrashHandler::ExceptionCodeString(DWORD exceptionCode)
{
	switch (exceptionCode)
	{
	case STATUS_ACCESS_VIOLATION:
		return "EXCEPTION_ACCESS_VIOLATION";
	case STATUS_ARRAY_BOUNDS_EXCEEDED:
		return "EXCEPTION_ARRAY_BOUNDS_EXCEEDED";
	case STATUS_BREAKPOINT:
		return "EXCEPTION_BREAKPOINT";
	case STATUS_DATATYPE_MISALIGNMENT:
		return "EXCEPTION_DATATYPE_MISALIGNMENT";
	case STATUS_FLOAT_DENORMAL_OPERAND:
		return "EXCEPTION_FLT_DENORMAL_OPERAND";
	case STATUS_FLOAT_DIVIDE_BY_ZERO:
		return "EXCEPTION_FLT_DIVIDE_BY_ZERO";
	case STATUS_FLOAT_INEXACT_RESULT:
		return "EXCEPTION_FLT_INEXACT_RESULT";
	case STATUS_FLOAT_INVALID_OPERATION:
		return "EXCEPTION_FLT_INVALID_OPERATION";
	case STATUS_FLOAT_OVERFLOW:
		return "EXCEPTION_FLT_OVERFLOW";
	case STATUS_FLOAT_STACK_CHECK:
		return "EXCEPTION_FLT_STACK_CHECK";
	case STATUS_FLOAT_UNDERFLOW:
		return "EXCEPTION_FLT_UNDERFLOW";
	case EXCEPTION_ILLEGAL_INSTRUCTION:
		return "STATUS_ILLEGAL_INSTRUCTION";
	case STATUS_IN_PAGE_ERROR:
		return "EXCEPTION_IN_PAGE_ERROR";
	case STATUS_INTEGER_DIVIDE_BY_ZERO:
		return "EXCEPTION_INT_DIVIDE_BY_ZERO";
	case STATUS_INTEGER_OVERFLOW:
		return "EXCEPTION_INT_OVERFLOW";
	case STATUS_INVALID_DISPOSITION:
		return "EXCEPTION_INVALID_DISPOSITION";
	case STATUS_INVALID_HANDLE:
		return "EXCEPTION_INVALID_HANDLE";
	case STATUS_NONCONTINUABLE_EXCEPTION:
		return "EXCEPTION_NONCONTINUABLE_EXCEPTION";
	case STATUS_PRIVILEGED_INSTRUCTION:
		return "EXCEPTION_PRIV_INSTRUCTION";
	case STATUS_SINGLE_STEP:
		return "EXCEPTION_SINGLE_STEP";
	case STATUS_STACK_OVERFLOW:
		return "EXCEPTION_STACK_OVERFLOW";
	case STATUS_UNWIND_CONSOLIDATE:
		return "STATUS_UNWIND_CONSOLIDATE";
	default:
		return "< unknown >";
	}
}

const char* CrashHandler::GetModuleNameForAddress(DWORD address)
{
	// Get modules info
	HMODULE hMods[1024];
	HANDLE hProcess = GetCurrentProcess();
	MODULEINFO moduleInfo;
	DWORD cbNeeded;
	EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded);
	int count = cbNeeded / sizeof(HMODULE);

	static char outbuf[MAX_PATH];

	for (int i = 0; i < count; i++)
	{
		GetModuleInformation(hProcess, hMods[i], &moduleInfo, sizeof(moduleInfo));
		DWORD moduleBase = (DWORD)moduleInfo.lpBaseOfDll;
		DWORD moduleSize = (DWORD)moduleInfo.SizeOfImage;

		if (moduleBase <= address && address < (moduleBase + moduleSize))
		{
			// Get the full path to the module's file.
			if (GetModuleFileNameEx(hProcess, hMods[i], outbuf, sizeof(outbuf)))
			{
				const char* slash = strrchr(outbuf, '\\');
				return slash + 1;
			}
			else
			{
				return "< unknown module name >";
			}
		}
	}

	return "< module not found >";
}
