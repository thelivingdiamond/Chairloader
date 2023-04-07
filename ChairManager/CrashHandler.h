#pragma once
#define NOMINMAX
#include <Windows.h>
#include <StackWalker.h>

class ChairStackWalker : public StackWalker
{
public:
	using StackWalker::StackWalker;

	const std::string& GetTextBuf() { return m_TextBuf; }

protected:
	virtual void OnOutput(LPCSTR szText)
	{
		m_TextBuf += szText;
		StackWalker::OnOutput(szText);
	}

	virtual void OnLoadModule(LPCSTR img,
		LPCSTR mod,
		DWORD64 baseAddr,
		DWORD size,
		DWORD result,
		LPCSTR symType,
		LPCSTR pdbName,
		ULONGLONG fileVersion) override
	{
		// Don't print
	}

	virtual void OnSymInit(LPCSTR szSearchPath, DWORD symOptions, LPCSTR szUserName) override
	{
		// Don't print
	}

private:
	std::string m_TextBuf;
};

class CrashHandler
{
public:
	//! @returns the crash handler instance.
	static CrashHandler& Get();

	//! Adds the vectored exception handler.
	void AddExceptionHandler();

	//! Creates crash log and dump.
	//! @param	sw			The stack walker
	//! @param	errorText	The fatal error text.
	void HandleFatalError(ChairStackWalker& sw, const char* errorText, PEXCEPTION_POINTERS pExceptionInfo);

private:
	PVOID m_hHandler = nullptr;
	tm m_CrashTime;
	char m_szCrashFileName[MAX_PATH]; // Name of crash log and dump without extention

	void CreateCrashReport(ChairStackWalker& sw, const char* errorText) noexcept;
	void PrintSystemInfo(FILE* file);
	void PrintStackTrace(FILE* file, ChairStackWalker& sw);
	void PrintModuleList(FILE* file);
	void ValidateHeap(FILE* file);

	void CreateMiniDump(PEXCEPTION_POINTERS pExceptionInfo);
	void ShowCrashDialog(const char* errorText);

	LONG VectoredExceptionsHandler(PEXCEPTION_POINTERS pExceptionInfo) noexcept;

	static const char* ExceptionCodeString(DWORD exceptionCode);
	static const char* GetModuleNameForAddress(UINT_PTR address);
};
