//
// Created by theli on 8/1/2022.
//
#include <d3d11.h>
#include <windows.h>
#include <cstdio>
#include <StackWalker.h>
#include "UI.h"
#include "CrashHandler.h"

#define ERROR_TEXT "Unhandled exception on main thread:\n"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
//    AllocConsole();
//    FILE *pFileCon = NULL;
//    pFileCon = freopen("CONOUT$", "w", stdout);
	CrashHandler::Get().AddExceptionHandler();

	try
	{
		UI::Render();
	}
	catch (const std::exception& e)
	{
		ChairStackWalker sw;
		sw.ShowCallstack(GetCurrentThread(), sw.GetCurrentExceptionContext());
		std::string errorText = std::string(ERROR_TEXT) + e.what();
		CrashHandler::Get().HandleFatalError(sw, errorText.c_str(), nullptr);
		return -1;
	}
	catch (...)
	{
		ChairStackWalker sw(StackWalker::AfterCatch);
		sw.ShowCallstack();
		CrashHandler::Get().HandleFatalError(sw, ERROR_TEXT "Unknown Exception Type", nullptr);
		return -1;
	}
}
