#pragma once
#include <Chairloader/IChairloaderPatches.h>

class ChairSteamAPI;

class ChairloaderPatches : public Internal::IChairloaderPatches
{
public:
	// Internal::IChairloaderPatches
	virtual void InitSystem() override;
	virtual void InitGame() override;
	virtual void MainUpdate(unsigned updateFlags) override;

private:
	std::unique_ptr<ChairSteamAPI> m_pSteamAPI;
};
