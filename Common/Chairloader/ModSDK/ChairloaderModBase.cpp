#ifdef CHAIRLOADER_MOD_SDK
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <Prey/CryGame/Game.h>
#include <detours/detours.h>
#include <Chairloader/IChairloaderImGui.h>
#include <Chairloader/ModSDK/ChairloaderModBase.h>
#include <Chairloader/Hooks/HookTransaction.h>

ChairloaderGlobalEnvironment* gCL = nullptr;

void ChairloaderModBase::GetModSdkVersion(SemanticVersion& version)
{
	version.m_Major = MOD_SDK_VERSION_MAJOR;
	version.m_Minor = MOD_SDK_VERSION_MINOR;
	version.m_Patch = MOD_SDK_VERSION_PATCH;
    version.m_ReleaseType = MOD_SDK_VERSION_RELEASE_TYPE;
}

void ChairloaderModBase::InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo)
{
	// Fill dllInfo
	ModDllInfoEx dllInfoEx;
	dllInfoEx.thisStructSize = sizeof(ModDllInfo);
	FillModInfo(dllInfoEx);

	CRY_ASSERT(dllInfoEx.thisStructSize == sizeof(ModDllInfo));
	CRY_ASSERT(dllInfoEx.modName != nullptr);
	CRY_ASSERT(dllInfoEx.logTag != nullptr);

	dllInfo = (ModDllInfo)dllInfoEx;

	// Init the DLL
	ModuleInitISystem(initInfo.pSystem, dllInfoEx.modName);
	gCL = initInfo.pChair->GetChairloaderEnvironment();
	CryAssertSetGlobalFlagAddress(gCL->cl->GetAssertFlagAddress());
	ModuleInitIChairLogger(dllInfoEx.logTag);
	m_ModuleBase = gCL->cl->GetPreyDllBase();

	// Install hooks
	try
	{
		HookTransaction hookTr;
		InitHooks();
		PreyFunctionSystem::Init(m_ModuleBase);
		PreyFunctionSystem::InstallHooks();
		hookTr.Commit();
	}
	catch (const std::exception& e)
	{
		CryFatalError("Failed to install hooks:\n{}", e.what());
	}
}

void ChairloaderModBase::InitGame(bool isHotReloading)
{
	g_pGame = gCL->cl->GetCGame();
	InitImGui();
}

void ChairloaderModBase::ShutdownGame(bool isHotUnloading)
{
	ShutdownImGui();
}

void ChairloaderModBase::ShutdownSystem(bool isHotUnloading)
{
	// Remove all installed hooks
	HookTransaction hookTr;
	PreyFunctionSystem::RemoveHooks();
	hookTr.Commit(); // No use dying when shutting down
}

void ChairloaderModBase::InitImGui()
{
	// Check ImGui version
	bool isCompat = gCL->pImGui->CheckVersionAndDataLayout(IMGUI_VERSION, sizeof(ImGuiIO),
		sizeof(ImGuiStyle), sizeof(ImVec2), sizeof(ImVec4), sizeof(ImDrawVert), sizeof(ImDrawIdx));

	if (!isCompat)
		CryFatalError("Mod's ImGui is incompatible with Chairloader's");

	// Set pointers
	ImGuiMemAllocFunc pAllocFunc = nullptr;
	ImGuiMemFreeFunc pFreeFunc = nullptr;
	void* pUserData = nullptr;
	gCL->pImGui->GetAllocatorFuncs(&pAllocFunc, &pFreeFunc, &pUserData);
	ImGui::SetAllocatorFunctions(pAllocFunc, pFreeFunc, pUserData);
	ImGui::SetCurrentContext(gCL->pImGui->GetContext());
}

void ChairloaderModBase::ShutdownImGui()
{
	ImGui::SetCurrentContext(nullptr);
	ImGui::SetAllocatorFunctions(nullptr, nullptr, nullptr);
}

#endif
