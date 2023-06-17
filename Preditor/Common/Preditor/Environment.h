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
};

extern SPreditorEnvironment* gPreditor;
