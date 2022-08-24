//
// Created by theli on 8/1/2022.
//
#include <d3d11.h>
#include <windows.h>
#include <cstdio>
#include "UI.h"

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
//    AllocConsole();
//    FILE *pFileCon = NULL;
//    pFileCon = freopen("CONOUT$", "w", stdout);
	UI::Render();

}