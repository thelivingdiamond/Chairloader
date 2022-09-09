#ifdef CHAIRLOADER_MOD_SDK
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Prey/CryCore/Platform/CryWindows.h>
#include <detours/detours.h>
#include <ChairLoader/IChairloaderImGui.h>
#include <ChairLoader/ModSDK/ChairloaderModBase.h>

ChairloaderGlobalEnvironment* gCL = nullptr;

void ChairloaderModBase::InitSystem(const ModInitInfo& initInfo, ModDllInfo& dllInfo)
{
	FillModInfo(dllInfo);

	// Validate dllInfo
	CRY_ASSERT(dllInfo.thisStructSize == sizeof(ModDllInfo));
	CRY_ASSERT(dllInfo.modName != nullptr);

	// Init the DLL
	ModuleInitISystem(initInfo.pSystem, dllInfo.modName);
	gCL = initInfo.pChair->GetChairloaderEnvironment();
	m_ModuleBase = gCL->cl->GetPreyDllBase();

	// Install hooks
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	InitHooks();
	PreyFunctionSystem::Init(m_ModuleBase);
	PreyFunctionSystem::InstallHooks();
	DetourTransactionCommit();
}

void ChairloaderModBase::InitGame(bool isHotReloading)
{
	InitImGui();
}

void ChairloaderModBase::ShutdownGame(bool isHotUnloading)
{
	ShutdownImGui();
}

void ChairloaderModBase::ShutdownSystem(bool isHotUnloading)
{
	// Remove all installed hooks
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	PreyFunctionSystem::RemoveHooks();
	DetourTransactionCommit();
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
