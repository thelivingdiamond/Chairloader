#pragma once

// Common
class PreditorConfig;
class PreditorPaths;

// Main
struct IPreditor;
struct IProject;
struct IUserProjectSettings;

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
	IPreditor* pMain;
	IProject* pProject;
	IUserProjectSettings* pUserSettings;

	// Engine
	IPreditorEngine* pEngine;

	// Input
	IPreditorInput* pInput;

	// Viewport
	IViewportWindow* pViewportWindow;
};

extern SPreditorEnvironment* gPreditor;
