#include <Chairloader/IChairloaderDll.h>
#include "SteamAPI/ChairSteamAPI.h"
#include "ChairloaderPatches.h"

std::unique_ptr<Internal::IChairloaderPatches> Internal::IChairloaderPatches::CreateInstance()
{
	return std::make_unique<ChairloaderPatches>();
}

void ChairloaderPatches::InitSystem()
{
	m_pSteamAPI = ChairSteamAPI::CreateInstance();
}

void ChairloaderPatches::InitGame()
{
    
}

void ChairloaderPatches::MainUpdate(unsigned updateFlags)
{
	if (m_pSteamAPI)
		m_pSteamAPI->Update();
}
