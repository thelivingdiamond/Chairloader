#pragma once
#include <Chairloader/IChairloaderModule.h>

namespace Internal
{

struct SToolsInitParams
{
	bool bEnableEditor = false;
	bool bEnableTrainer = false;
};

struct IChairloaderTools : public IChairloaderModule, IChairService<IChairloaderTools>
{

	static const char* NameImpl() { return "IChairloaderTools"; }

	virtual ~IChairloaderTools() {}

	//! System initialization
	virtual void InitSystem(const SToolsInitParams& params) = 0;

	//! Game initialization.
	virtual void InitGame() = 0;

	//! Shows menu items in the "Chairloader" menu on the main menu bar.
	virtual void ShowMainMenuItems() = 0;
};

} // namespace Internal
