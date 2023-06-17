#pragma once

class PreditorConfig;
class PreditorPaths;

struct IPreditor;
struct IPreditorEngine;

struct SPreditorEnvironment
{
	const PreditorConfig* pConfig;
	const PreditorPaths* pPaths;
	IPreditor* pMain;
	IPreditorEngine* pEngine;
};

extern SPreditorEnvironment* gPreditor;
