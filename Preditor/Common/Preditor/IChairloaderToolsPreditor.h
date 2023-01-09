#pragma once

struct IChairToPreditor;

struct IChairloaderToolsPreditor
{
	static std::unique_ptr<IChairloaderToolsPreditor> CreateInstance(IChairToPreditor* pChair);
	virtual ~IChairloaderToolsPreditor() {}

	//! Called during stage ShowUI.
	virtual void Update() = 0;

	//! Shows the "Window" menu on the menu bar.
	virtual void ShowWindowMenu() = 0;

	//! ModReloading interface.
	//! @see ModReloading
	//! @{
	virtual void CheckModulesForChanges() = 0;
	virtual void ReloadMods() = 0;
	virtual bool ReloadLevel() = 0;
	//! @}
};
