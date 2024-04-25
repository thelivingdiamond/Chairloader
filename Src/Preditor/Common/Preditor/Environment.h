#pragma once
#include <Preditor/PreditorFonts.h>
#include <Preditor/PreditorTime.h>

// Common
class PreditorConfig;
class PreditorPaths;

// Main
struct IPreditor;
struct IProject;
struct IUserProjectSettings;
struct ISceneEditorManager;

// Assets
struct IAssetSystem;

// Engine
struct IPreditorEngine;

// Input
struct IPreditorInput;

// Viewport
struct IViewportWindow;

struct SPreditorEnvironment
{
	// Common
	const PreditorConfig* pConfig;
	const PreditorPaths* pPaths;

	// Main
	const PreditorTime* pTime;
	IPreditor* pMain;
	IProject* pProject;
	IUserProjectSettings* pUserSettings;
	ISceneEditorManager* pSceneEditorManager;

	// Assets
	IAssetSystem* pAssetSystem;

	// Engine
	IPreditorEngine* pEngine;
	PreditorFonts* pFonts;

	// Input
	IPreditorInput* pInput;

	// Viewport
	IViewportWindow* pViewportWindow;
};

extern SPreditorEnvironment* gPreditor;
