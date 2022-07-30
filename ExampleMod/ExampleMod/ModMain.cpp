#include "ModMain.h"

ModMain* gMod = nullptr;

std::string ModMain::GetModName()
{
	return "ExampleMod"; // CHANGE ME
}

void ModMain::InitHooks()
{
}

void ModMain::InitSystem(ISystem* pSystem, uintptr_t moduleBase)
{
	BaseClass::InitSystem(pSystem, moduleBase);
	// Your code goes here
}

void ModMain::InitGame(IGameFramework* pFramework, IChairloader* chairloader)
{
	BaseClass::InitGame(pFramework, chairloader);
	// Your code goes here
}

void ModMain::Draw()
{
	ImGui::Begin("Example Mod");
	ImGui::Text("It works!");
	ImGui::End();
}

void ModMain::PreUpdate()
{
	// Your code goes here
}

void ModMain::PostUpdate()
{
	// Your code goes here
}

void ModMain::ShutdownGame()
{
	// Your code goes here
	BaseClass::ShutdownGame();
}

void ModMain::ShutdownSystem()
{
	// Your code goes here
	BaseClass::ShutdownSystem();
}

extern "C" DLL_EXPORT IChairloaderMod* ClMod_Initialize()
{
	CRY_ASSERT(!gMod);
	gMod = new ModMain();
	return gMod;
}

extern "C" DLL_EXPORT void ClMod_Shutdown()
{
	CRY_ASSERT(gMod);
	delete gMod;
	gMod = nullptr;
}

// Validate that declarations haven't changed
static_assert(std::is_same_v<decltype(ClMod_Initialize), IChairloaderMod::ProcInitialize>);
static_assert(std::is_same_v<decltype(ClMod_Shutdown), IChairloaderMod::ProcShutdown>);
