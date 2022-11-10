#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct SToolsInitParams
{
	bool bEnableEditor = false;
	bool bEnableTrainer = false;
};

struct IChairloaderTools : public IChairloaderModule
{
	static std::unique_ptr<IChairloaderTools> CreateInstance();
	virtual ~IChairloaderTools() {}

	//! System initialization
	virtual void InitSystem(const SToolsInitParams& params) = 0;

	//! Game initialization.
	virtual void InitGame() = 0;

	//! @returns whether the dev console is visible.
	virtual bool IsDevConsoleVisible() = 0;
	virtual void SetDevConsoleVisible(bool state) = 0;

	//! Shows menu items in the "Chairloader" menu on the main menu bar.
	virtual void ShowMainMenuItems() = 0;
};

} // namespace Internal
