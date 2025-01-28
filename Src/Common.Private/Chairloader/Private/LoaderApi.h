#pragma once

using FnChairloaderInit = bool(void* hGameDll);

constexpr char FN_CHAIRLOADER_INIT[] = "Chair_Init";

constexpr char LOADER_ORIG_GAME_DLL_NAME[] = "PreyDll.dll";
constexpr char LOADER_CHAIR_GAME_DLL_NAME[] = "PreyDll.Chairloader.dll";
constexpr char LOADER_CHAIRLOADER_DLL_NAME[] = "Chairloader.dll";
