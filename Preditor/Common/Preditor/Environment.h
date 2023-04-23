#pragma once

class PreditorConfig;
class PreditorPaths;

struct SPreditorEnvironment
{
	const PreditorConfig* pConfig;
	const PreditorPaths* pPaths;
};

extern SPreditorEnvironment* gPreditor;
