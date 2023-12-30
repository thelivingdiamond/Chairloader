//
// Created by theli on 8/1/2022.
//
#include <Prey/CryCore/Platform/CryWindows.h>
#include <WinShell/WinShell.h>
#include <shellapi.h>
#include <d3d11.h>
#include <cstdio>
#include <StackWalker.h>
#include "UI.h"
#include <gtest/gtest.h>
#include "CrashHandler.h"
#include <Prey/CryCore/Platform/platform_impl.inl>

// TODO 2023-08-25: Remove this
struct ChairloaderGlobalEnvironment* gCL;

#ifndef CHAIRMANAGER_TESTS
#define ERROR_TEXT "Unhandled exception on main thread:\n"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
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

	WinShell::CloseAllDialogs();
	return 0;
}

#else

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	if (argc == 1333337)
	{
		// Fake call to the rest of the program.
		// Otherwise linker strips everything.
		// Hopefully, no one passes this many arguments.
		UI::Render();
	}

	return RUN_ALL_TESTS();
}

#endif // ifndef CHAIRMANAGER_TESTS
