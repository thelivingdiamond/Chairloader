// Header file automatically created from a PDB.

#pragma once

class ArkInputLegend;

// Header: FromCpp
// Prey/GameDll/ark/ui/ArkInputLegendHandler.h
class ArkInputLegendHandler // Id=8013535 Size=4
{
public:
	unsigned m_handle;
	
	ArkInputLegendHandler();
	~ArkInputLegendHandler();
	bool IsVisible() const { return FIsVisible(this); }
	void ShowLegend(ArkInputLegend const &_legend) { FShowLegend(this,_legend); }
	void HideLegend() { FHideLegend(this); }
	
	static inline auto FBitNotArkInputLegendHandler = PreyFunction<void(ArkInputLegendHandler *const _this)>(0x15FCAA0);
	static inline auto FIsVisible = PreyFunction<bool(ArkInputLegendHandler const *const _this)>(0x15FCAF0);
	static inline auto FShowLegend = PreyFunction<void(ArkInputLegendHandler *const _this, ArkInputLegend const &_legend)>(0x15FCB50);
	static inline auto FHideLegend = PreyFunction<void(ArkInputLegendHandler *const _this)>(0x15FCAA0);
};

