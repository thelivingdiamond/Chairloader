// Header file automatically created from a PDB.
#pragma once

struct SColorChartLayer;

// IColorGradingController
// Header:  _unknown/IColorGradingController.h
// Include: Prey/CryRenderer/IColorGradingController.h
struct IColorGradingController
{ // Size=8 (0x8)
	virtual ~IColorGradingController();
	virtual int LoadColorChart(const char* pChartFilePath) const = 0;
	virtual int LoadDefaultColorChart() const = 0;
	virtual void SetLevelColorChart(const char* _chartFilePath) = 0;
	virtual void UnloadColorChart(int texID) const = 0;
	virtual void SetLayers(const SColorChartLayer* pLayers, unsigned numLayers) = 0;
};

