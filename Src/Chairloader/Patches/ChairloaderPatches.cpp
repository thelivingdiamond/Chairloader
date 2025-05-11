#include <Prey/CrySystem/System.h>
#include <Prey/CryInput/dxinput.h>
#include <Chairloader/IChairloaderDll.h>
#include <Chairloader/Hooks/HookTransaction.h>
#include "Lua/LuaDbgFix.h"
#include "Lua/LuaDbgRes.h"
#include "Lua/LuaWarnPatch.h"
#include "SteamAPI/ChairSteamAPI.h"
#include "ChairloaderPatches.h"
#include "ConsoleEventPatch.h"
#include "ArkPlayerCheats.h"
#include "LocalizationPatch.h"

auto g_CleanupVibrationAtExit = PreyFunction<void()>(0x9D85C0);
FunctionHook<void()> g_CleanupVibrationAtExit_Hook;

auto g_CSystem_InitSoundSystem_Hook = CSystem::FInitSoundSystem.MakeHook();
auto g_CDXInput_ShutDown_Hook = CDXInput::FShutDown.MakeHook();

void CleanupVibrationAtExit_Hook()
{
	// Do nothing. See CDXInput_ShutDown_Hook.
}

bool CSystem_InitSoundSystem_Hook(CSystem* const _this, const SSystemInitParams& _initParams)
{
	static_cast<ChairloaderPatches*>(gChair->GetPatches())->ReplaceArkSystems();
	return g_CSystem_InitSoundSystem_Hook.InvokeOrig(_this, _initParams);
}

void CDXInput_ShutDown_Hook(CDXInput* const _this)
{
	g_CDXInput_ShutDown_Hook.InvokeOrig(_this);

	// Clean up vibration after DXInput is shut down instead of in std::atexit.
	// 
	// This patch was made because XInputSetState call in std::atexit causes
	// Steam Overlay Renderer to crash when exiting the game.
	// That crash happens even in Steam version of the game.
	// 
	// The patch is here and not in ChairSteamAPI because I think it's a bad idea to
	// call into external libraries during std::atexit as they may have already been shut down.
	// The crash may also occur with other game overlays (not confirmed).
	// 
	// Crash callstack:
	// - GameOverlayRenderer64.dll!???
	// - GameOverlayRenderer64.dll!XInputSetState_Hook
	// - PreyDll.dll!CleanupVibrationAtExit
	g_CleanupVibrationAtExit_Hook.InvokeOrig();
}


ChairloaderPatches::ChairloaderPatches(std::shared_ptr<IChairSteamAPI> pChairSteamAPI) : m_pSteamAPI(std::static_pointer_cast<ChairSteamAPI>(pChairSteamAPI)) {
}

void ChairloaderPatches::ReplaceArkSystems()
{
	if (m_pSteamAPI)
		m_pSteamAPI->ReplaceArkSystems();
}

void ChairloaderPatches::InitSystem()
{
	g_CSystem_InitSoundSystem_Hook.SetHookFunc(&CSystem_InitSoundSystem_Hook);
	g_CDXInput_ShutDown_Hook.SetHookFunc(&CDXInput_ShutDown_Hook);

	LuaDbgFix::InitSystem();
	LuaDbgRes::InitSystem();
	LuaWarnPatch::InitSystem();
	if (m_pSteamAPI) {
		m_pSteamAPI->InitSystem();
	}
	LocalizationPatch::InitSystem(m_pSteamAPI.get());

	{
		// CleanupVibrationAtExit_Hook is called after Chairloader is shut down and
		// all automatic hooks are removed. So it must use manual hook.
		HookTransaction tr;
		g_CleanupVibrationAtExit_Hook.MarkKeepAfterDestroy();
		g_CleanupVibrationAtExit_Hook.InstallHook(g_CleanupVibrationAtExit.Get(), &CleanupVibrationAtExit_Hook);
		tr.CommitOrDie();
	}

	if (gEnv->pSystem->IsDevMode())
	{
		ArkPlayerCheats::InitHooks();
		ConsoleEventPatch::InitHooks();
	}
}

void ChairloaderPatches::InitGame()
{
	if (gEnv->pSystem->IsDevMode())
	{
		ArkPlayerCheats::InitGame();
	}
}

void ChairloaderPatches::MainUpdate(unsigned updateFlags)
{
	if (m_pSteamAPI)
		m_pSteamAPI->Update();
}
