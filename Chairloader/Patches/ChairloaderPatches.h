#pragma once
#include <Chairloader/IChairloaderPatches.h>

class ChairSteamAPI;

class ChairloaderPatches : public Internal::IChairloaderPatches
{
public:
	//! Called before CSystem::InitSoundSystem to replace pArkRewardSystem and pArkDlcSystem.
	void ReplaceArkSystems();

	// Internal::IChairloaderPatches
	virtual void InitSystem() override;
	virtual void InitGame() override;
	virtual void MainUpdate(unsigned updateFlags) override;

private:
	std::unique_ptr<ChairSteamAPI> m_pSteamAPI;
};
