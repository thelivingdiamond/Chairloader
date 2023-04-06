//
// Created by theli on 8/1/2022.
//
#include <d3d11.h>
#include <windows.h>
#include <cstdio>
#include <StackWalker.h>
#include "UI.h"

#define EXCEPTION_LOG_FILE_NAME "ChairManagerError.log"

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

void ShowFatalErrorAndDie(ChairStackWalker& sw, const std::string& text)
{
	std::string messageText;
	messageText += "An unhandled exception has occured on the main thread.\n";
	messageText += "This message is duplicated in " EXCEPTION_LOG_FILE_NAME ".\n\n";
	messageText += "Exception message:\n";
	messageText += text + "\n\n";
	messageText += "Call stack:\n";
	messageText += sw.GetTextBuf();
	MessageBoxA(nullptr, messageText.c_str(), "Fatal Error", MB_OK | MB_ICONERROR);

	std::ofstream logFile(EXCEPTION_LOG_FILE_NAME);
	logFile << messageText;
	logFile.close(); // Must close because std::exit doesn't return

	std::exit(-1);
}

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
//    AllocConsole();
//    FILE *pFileCon = NULL;
//    pFileCon = freopen("CONOUT$", "w", stdout);
	try
	{
		UI::Render();
	}
	catch (const std::exception& e)
	{
		ChairStackWalker sw;
		sw.ShowCallstack(GetCurrentThread(), sw.GetCurrentExceptionContext());
		ShowFatalErrorAndDie(sw, e.what());
	}
	catch (...)
	{
		ChairStackWalker sw(StackWalker::AfterCatch);
		sw.ShowCallstack();
		ShowFatalErrorAndDie(sw, "Unknown Exception Type");
	}
}
