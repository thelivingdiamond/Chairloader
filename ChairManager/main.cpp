//
// Created by theli on 8/1/2022.
//
#include <d3d11.h>
#include <windows.h>
#include <cstdio>
#include "UI.h"
#include <gtest/gtest.h>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
//    AllocConsole();
//    FILE *pFileCon = NULL;
//    pFileCon = freopen("CONOUT$", "w", stdout);
    fs::path cmdLine = lpCmdLine;
    cmdLine.wstring().resize(MAX_PATH*100);
    int argc;
    auto argv = CommandLineToArgvW(cmdLine.wstring().data(), &argc);
    if(strstr(lpCmdLine, "--gtest") != nullptr){
        testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    }
	try
	{
		UI::Render();
	}
	catch (const std::exception& e)
	{
		MessageBoxA(nullptr, e.what(), "Fatal Error", MB_OK | MB_ICONERROR);
	}
}
