#ifdef CHAIRLOADER_MOD_SDK
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <detours/detours.h>
#include <ChairLoader/ModSDK/ChairloaderModBase.h>

ChairloaderGlobalEnvironment* gCL = nullptr;

void ChairloaderModBase::InitSystem(ISystem* pSystem, uintptr_t moduleBase)
{
	ModuleInitISystem(pSystem, GetModName().c_str());
	m_ModuleBase = moduleBase;

	// Install hooks
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	InitHooks();
	PreyFunctionSystem::Init(m_ModuleBase);
	PreyFunctionSystem::InstallHooks();
	DetourTransactionCommit();
}

void ChairloaderModBase::InitGame(IGameFramework* pFramework, IChairloader* chairloader)
{
	// TODO:
	gCL = nullptr;
}

void ChairloaderModBase::ShutdownGame()
{
}

void ChairloaderModBase::ShutdownSystem()
{
	// Remove all installed hooks
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	PreyFunctionSystem::RemoveHooks();
	DetourTransactionCommit();
}

#endif
