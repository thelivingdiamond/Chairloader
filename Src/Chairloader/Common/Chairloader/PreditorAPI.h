#pragma once

struct IChairToPreditor;
struct IPreditorToChair;

//! The version number of Preditor <-> Chairloader API.
//! Must be incremented on every release that changes IChairToPreditor or IPreditorToChair.
//! Must be equal on both Preditor and Chairloader to successfully load.
constexpr int PREDITOR_API_VERSION = 1;

//! Name of the exported function in Chairloader DLL.
constexpr char PREDITOR_API_EXPORT_FUNC_NAME[] = "Chair_GetPreditorAPI";

//! The API getter in Chairloader.
using Chair_GetPreditorAPI_Func = IChairToPreditor* (*)(int preditorVersion, int* chairVersion);
