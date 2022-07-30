#include "ModMain.h"
#include <imgui/imgui_internal.h>

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

void ModMain::Draw(ImGuiContext*ctx)
{
	// TODO:
	GImGui = ctx;

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

extern "C" DLL_EXPORT IChairloaderMod* ClMod_Instantiate()
{
	CRY_ASSERT(!gMod);
	gMod = new ModMain();
	return gMod;
}
