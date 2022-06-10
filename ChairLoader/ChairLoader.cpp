#include "pch.h"
#include <filesystem>
#include <Prey/CryInput/IInput.h>
#include "ChairLoader.h"
#include "EntityUtils.h"
#include "ChairloaderGui.h"
#include "Profiler.h"

ChairLoader *gCL = nullptr;
SSystemGlobalEnvironment *gEnv = nullptr;

ChairLoader::ChairLoader() {
	CreateConsole();
	std::cout << "ChairLoader Initializing...\n";
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"PreyDll.dll");
	std::cout << "Module Base: 0x" << std::hex << moduleBase << std::dec << "\n\n";

	LoadPreyPointers(moduleBase);
	HookGameUpdate(moduleBase);
	LoadConfigFile();
	m_MainThreadId = std::this_thread::get_id();
	gEntUtils = new EntityUtils();
	m_ImGui = std::make_unique<ChairLoaderImGui>();
	gui = new ChairloaderGui();
	g_pProfiler = new Profiler();
}

ChairLoader::~ChairLoader()
{
	if (m_pConsoleFile) {
		fclose(m_pConsoleFile);
		m_pConsoleFile = nullptr;
	}

	FreeConsole();
}

void ChairLoader::PreUpdate(bool haveFocus, unsigned int updateFlags) {
	m_ImGui->PreUpdate(haveFocus);
	UpdateFreeCam();
	// ImGui::ShowDemoWindow();
	gui->update();
	bool todo = true;
	gui->draw(&todo);
}

void ChairLoader::PostUpdate(bool haveFocus, unsigned int updateFlags) {
	m_ImGui->PostUpdate();
}

bool ChairLoader::HandleKeyPress(const SInputEvent &event) {
	if (event.keyId == eKI_Tilde && event.state == eIS_Pressed) {
		gui->SetDevConsoleVisible(!gui->IsDevConsoleVisible());
		return true;
	}

	return false;
}

void ChairLoader::CreateConsole() {
	AllocConsole();
	freopen_s(&m_pConsoleFile, "CONOUT$", "w", stdout);
	std::cout << "Welcome to funland sonic\n";
}

void ChairLoader::LoadPreyPointers(uintptr_t moduleBase) {
	gEnv = (SSystemGlobalEnvironment *)(moduleBase + 0x22418c0);
	gPreyFuncs = new PreyFunctions(moduleBase);
}

void ChairLoader::HookGameUpdate(uintptr_t moduleBase) {
	m_CGameUpdate = gPreyFuncs->CGameF->Update;
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(LPVOID &)m_CGameUpdate, (PBYTE)&GameUpdate);
	DetourTransactionCommit();
}

void ChairLoader::LoadConfigFile() {
	auto path = std::filesystem::current_path() / L"Binaries/Danielle/x64/Release/chairloaderconfig.xml";
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(path.c_str());
	std::cout << doc.child("config").child("filepaths").child("PreyDirectory").attribute("path").value() << std::endl;
	for (auto itr = doc.child("config").child("keybinds").children().begin(); itr != doc.child("config").child("keybinds").children().end(); ++itr) {
		std::cout << itr->attribute("name").name() << "=" << itr->attribute("name").value() << std::endl;
		std::cout << itr->attribute("key").name() << "=" << itr->attribute("key").value() << std::endl;
	}
	std::cout << std::endl << doc.child("config").child("keybinds").find_child_by_attribute("action", "name", "GUIToggle").attribute("key").value() << std::endl;

	m_GuiToggleKey = std::stoi(doc.child("config").child("keybinds").find_child_by_attribute("action", "name", "GUIToggle").attribute("key").value(), nullptr, 0);
	m_FreeCamKey = std::stoi(doc.child("config").child("keybinds").find_child_by_attribute("action", "name", "FreeCam").attribute("key").value(), nullptr, 0);
}

void ChairLoader::UpdateFreeCam() {
	if (GetAsyncKeyState(m_FreeCamKey) & 1) {
		m_FreeCamEnabled = !m_FreeCamEnabled;
		printf("Freecam state: %u\n", m_FreeCamEnabled);
		if (m_FreeCamEnabled) {
			m_DevMode = true;
			gPreyFuncs->CSystemF->setDevMode(gEnv->pSystem, m_DevMode);
			gEnv->pGame->m_pConsole->ExecuteString((char *)"FreeCamEnable", false, true);
		}
		else {
			gPreyFuncs->CSystemF->setDevMode(gEnv->pSystem, m_DevMode);
			gEnv->pGame->m_pConsole->ExecuteString((char *)"FreeCamDisable", false, true);
		}
	}
}

int ChairLoader::GameUpdate(CGame *_this, bool haveFocus, unsigned int updateFlags) {
	gCL->PreUpdate(haveFocus, updateFlags);
	int ret = gCL->m_CGameUpdate(_this, haveFocus, updateFlags);
	gCL->PostUpdate(haveFocus, updateFlags);
	return ret;
}
