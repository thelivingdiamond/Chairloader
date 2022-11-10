#include <Prey/CryInput/IInput.h>
#include <Chairloader/IChairloaderCryRender.h>
#include <Chairloader/IChairloaderDll.h>
#include "ChairloaderCore.h"
#include "ChairloaderConfigManager.h"
#include "ChairloaderGui.h"
#include "ChairLoaderImGui.h"
#include "ModDllManager.h"

constexpr char CONFIG_NAME[] = "Chairloader";

std::unique_ptr<Internal::IChairloaderCore> Internal::IChairloaderCore::CreateInstance()
{
	return std::make_unique<ChairloaderCore>();
}

ChairloaderCore* ChairloaderCore::Get()
{
	return static_cast<ChairloaderCore*>(gChair->GetCore());
}

void ChairloaderCore::InitSystem()
{
	m_pConfigManager = std::make_unique<ChairloaderConfigManager>();
	gCL->conf = m_pConfigManager.get();
	CryLog("Chairloader config loaded: %u", gCL->conf->loadModConfigFile(CONFIG_NAME));
	LoadConfig();
	ChairLoaderImGui::InitHooks();
}

void ChairloaderCore::ShutdownSystem()
{
	gCL->conf = nullptr;
	m_pConfigManager = nullptr;
}

void ChairloaderCore::RegisterMods()
{
    m_pModDllManager = std::make_unique<ModDllManager>();
    m_pModDllManager->SetHotReloadEnabled(gChair->IsEditorEnabled());

	auto cfgValue = gCL->conf->getConfigValue(CONFIG_NAME, "ModList");

	if (cfgValue.type() != typeid(pugi::xml_node))
	{
		CryWarning("ModList is not a node in the config.");
		return;
	}

	auto node = boost::get<pugi::xml_node>(cfgValue);
	for (pugi::xml_node& mod : node) {
		auto modName = boost::get<std::string>(gCL->conf->getNodeConfigValue(mod, "modName"));
		if (mod.child("enabled").text().as_bool()) {
			if (mod.child("dllName"))
			{
				CryLog("Found DLL mod: %s", modName.c_str());
				m_pModDllManager->RegisterModFromXML(mod);
			}

			fs::path modDirPath = fs::current_path() / "Mods" / fs::u8path(modName);
			fs::path shadersPath = modDirPath / "Shaders";
			if (fs::exists(shadersPath))
			{
				CryLog("Found Shader mod: %s", modName.c_str());
				gChair->GetCryRender()->AddShadersDir(shadersPath);
			}
		}
	}

	gChair->GetCryRender()->RefreshShaderFileList();
}

void ChairloaderCore::InitGame()
{
	m_pImGui = std::make_unique<ChairLoaderImGui>();
	m_pGui = std::make_unique<ChairloaderGui>();
	g_pProfiler = new Profiler();
}

void ChairloaderCore::ShutdownGame()
{
	m_pGui = nullptr;
	m_pImGui = nullptr;
}

void ChairloaderCore::PreUpdate()
{
	if (gCL->conf->getConfigDirty(CONFIG_NAME))
		LoadConfig();

	m_pImGui->PreUpdate(true);
	m_pGui->update();
	m_pConfigManager->Update();

	m_pGui->draw(&m_bShowGui);
	m_pModDllManager->CallDraw();
}

void ChairloaderCore::PostUpdate()
{
	m_pImGui->PostUpdate();
}

bool ChairloaderCore::HandleKeyPress(const SInputEvent& event)
{
	if (event.keyId == m_KeyHideGui && event.state == eIS_Pressed) {
		m_bShowGui = !m_bShowGui;
		return true;
	}

	if (event.keyId == m_KeyToggleFreecam && event.state == eIS_Pressed) {
		// TODO:
		/*m_FreeCamEnabled = !m_FreeCamEnabled;
		CryLog("Freecam state: %u\n", m_FreeCamEnabled);
		if (m_FreeCamEnabled) {
			m_DevMode = true;
			((CSystem*)gEnv->pSystem)->SetDevMode(m_DevMode);
			gEnv->pConsole->ExecuteString("FreeCamEnable", true, false);
		}
		else {
			((CSystem*)gEnv->pSystem)->SetDevMode(m_DevMode);
			gEnv->pConsole->ExecuteString("FreeCamDisable", true, false);
		}*/
		return true;
	}

	return false;
}

Internal::IModDllManager* ChairloaderCore::GetDllManager()
{
	return m_pModDllManager.get();
}

void ChairloaderCore::LoadConfig()
{
    m_KeyHideGui = LoadConfigKey("HideGUIKey", eKI_F1);
    m_KeyToggleFreecam = LoadConfigKey("ToggleFreecamKey", eKI_F2);
}

EKeyId ChairloaderCore::LoadConfigKey(const std::string& paramName, EKeyId defaultKey)
{
    auto key = gCL->conf->getConfigValue(CONFIG_NAME, paramName);
    const IChairloader::KeyNameMap& keyNames = gChair->GetKeyNames();

    if (key.type() == typeid(std::string)) {
        auto keyName = boost::get<std::string>(key);
        std::transform(keyName.begin(), keyName.end(), keyName.begin(), ::tolower);
        auto it = keyNames.right.find(keyName);

        if (it != keyNames.right.end())
            return it->second;
        else
            CryError("Chairloader: Invalid key name '%s' for '%s', setting to default", keyName.c_str(), paramName.c_str());
    }

    // Failed to get from config, restore default
	gCL->conf->setConfigValue(CONFIG_NAME, paramName, keyNames.left.at(defaultKey), IChairloaderConfigManager::parameterType::String);
    return defaultKey;
}
