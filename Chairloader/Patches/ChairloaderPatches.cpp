#include <Prey/CrySystem/System.h>
#include <Chairloader/IChairloaderDll.h>
#include "SteamAPI/ChairSteamAPI.h"
#include "ChairloaderPatches.h"

auto g_CSystem_InitSoundSystem_Hook = CSystem::FInitSoundSystem.MakeHook();

bool CSystem_InitSoundSystem_Hook(CSystem* const _this, const SSystemInitParams& _initParams)
{
	static_cast<ChairloaderPatches*>(gChair->GetPatches())->ReplaceArkSystems();
	return g_CSystem_InitSoundSystem_Hook.InvokeOrig(_this, _initParams);
}

std::unique_ptr<Internal::IChairloaderPatches> Internal::IChairloaderPatches::CreateInstance()
{
	return std::make_unique<ChairloaderPatches>();
}

void ChairloaderPatches::ReplaceArkSystems()
{
	if (m_pSteamAPI)
		m_pSteamAPI->ReplaceArkSystems();
}

void ChairloaderPatches::InitSystem()
{
	g_CSystem_InitSoundSystem_Hook.SetHookFunc(&CSystem_InitSoundSystem_Hook);
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
