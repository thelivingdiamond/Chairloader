#include <boost/algorithm/string.hpp>
#include <Prey/CryInput/IInput.h>
#include <Prey/CrySystem/ICmdLine.h>
#include <Chairloader/Private/ModPrefix.h>
#include <Chairloader/IChairloaderCryRender.h>
#include <Chairloader/IChairloaderTools.h>
#include <Chairloader/IChairloaderDll.h>
#include <Manager/ModInfo.h>
#include "Lua/LuaModManager.h"
#include "ChairloaderCore.h"
#include "ChairloaderConfigManager.h"
#include "ChairloaderGui.h"
#include "ChairImGui.h"
#include "ChairLogger.h"
#include "LogManager.h"
#include "ModDllManager.h"
#include "ChairVarManager.h"

constexpr char CONFIG_NAME[] = "Chairloader";
static PreyGlobal<bool> s_freeCamActive(0x2C09352);

class CBetterCVarsWhitelist : public ICVarsWhitelist {
public:
	~CBetterCVarsWhitelist() {}

	bool IsWhiteListed(const string&, bool)  override {
		return true;
	}
};

CBetterCVarsWhitelist g_CVarsWhitelist;

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
	// Unlock console commands
	auto pSystem = reinterpret_cast<CSystem*>(gEnv->pSystem);
	pSystem->m_pCVarsWhitelist = &g_CVarsWhitelist;

	LogManager::Get().InitSystem();
	m_pConfigManager = std::make_unique<ChairloaderConfigManager>();
    m_pCVarManager = std::make_unique<ChairVarManager>();
    m_pCVarManager->InitSystem();
	gCL->conf = m_pConfigManager.get();
	CryLog("Chairloader config loaded: {}", gCL->conf->loadModConfigFile(CONFIG_NAME));
	LoadConfig();
	ChairImGui::Get().InitSystem();
	m_pLuaModManager = std::make_unique<LuaModManager>();
	SkipIntroMovies();
}

void ChairloaderCore::ShutdownSystem()
{
	ChairImGui::Get().ShutdownSystem();
	gCL->conf = nullptr;
	m_pConfigManager = nullptr;
}

void ChairloaderCore::RegisterMods()
{
    m_pModDllManager = std::make_unique<ModDllManager>();
    m_pModDllManager->SetHotReloadEnabled(gChair->IsEditorEnabled() || gChair->GetPreditorAPI());

	auto cfgValue = gCL->conf->getConfigValue(CONFIG_NAME, "ModList");

	if (cfgValue.type() != typeid(pugi::xml_node))
	{
		CryWarning("ModList is not a node in the config.");
		return;
	}

	auto node = boost::get<pugi::xml_node>(cfgValue);
	for (pugi::xml_node& mod : node) {
		std::string modName = boost::get<std::string>(gCL->conf->getNodeConfigValue(mod, "modName"));

		if (mod.child("enabled").text().as_bool()) {
			try
			{
				if (boost::starts_with(modName, LEGACY_MOD_PREFIX))
				{
					// Don't load legacy mods
					CryLog("Found legacy mod: {}", modName);
					continue;
				}

				if (m_InstalledMods.find(modName) != m_InstalledMods.end())
					CryFatalError("Duplicate mod: {}", modName);

				m_InstalledMods.insert(modName);

				// Get mod path
				fs::path fullPath;
				auto fullPathParam = gCL->conf->getNodeConfigValue(mod, "fullPath");

				if (boost::get<std::string>(&fullPathParam))
				{
					// Preditor's main mod is outside of Mods dir.
					fullPath = fs::u8path(boost::get<std::string>(fullPathParam));
				}
				else
				{
					fullPath = gChair->GetModsPath() / fs::u8path(modName);
				}

				// Read ModInfo.xml instead of whatever is in Chairloader config
				Manager::ModInfo modInfo;
				modInfo.LoadFile(fullPath / Manager::ModInfo::XML_FILE_NAME);

				int loadOrder = boost::get<int>(gCL->conf->getNodeConfigValue(mod, "loadOrder"));

				if (!modInfo.dllName.empty())
				{
					CryLog("Found DLL mod: {}", modName);
					m_pModDllManager->RegisterModFromXML(modInfo, loadOrder, fullPath);
				}

				if (m_pLuaModManager->RegisterModFromXML(modInfo, loadOrder))
				{
					CryLog("Found Lua mod: {}", modName);
				}

				if (modInfo.enableShaderCompiler)
				{
					CryLog("Found Shader mod: {}", modName);
					gChair->GetCryRender()->AddShadersMod(modName);
				}
			}
			catch (const std::exception& e)
			{
				CryFatalError("Failed to load mod {}:\n{}", modName, e.what());
			}
		}
	}
}

void ChairloaderCore::PreInitGame()
{
	m_pLuaModManager->PreGameInit();
}

void ChairloaderCore::InitGame()
{
	ChairImGui::Get().InitGame();
	m_pGui = std::make_unique<ChairloaderGui>();
	g_pProfiler = new Profiler();
	m_pLuaModManager->PostGameInit();
}

void ChairloaderCore::PreShutdown()
{
	// Save cvars before any of them are unregistered
	m_pCVarManager->ShutdownGame();
}

void ChairloaderCore::ShutdownGame()
{
	m_pLuaModManager = nullptr;
	m_pGui = nullptr;
	ChairImGui::Get().ShutdownGame();
}

void ChairloaderCore::UpdateBeforeSystem(unsigned updateFlags)
{
	LogManager::Get().Update();

	if (gCL->conf->getConfigDirty(CONFIG_NAME))
		LoadConfig();

	ChairImGui::Get().UpdateBeforeSystem();
	m_pGui->update();
	m_pConfigManager->Update();
    m_pCVarManager->UpdateSystem();

	m_pGui->draw();
}

bool ChairloaderCore::HandleKeyPress(const SInputEvent& event)
{
	if (event.keyId == m_KeyHideGui && event.state == eIS_Pressed) {
		m_pGui->SetEnabled(!m_pGui->IsEnabled());
		return true;
	}

	if (event.keyId == m_KeyToggleFreecam && event.state == eIS_Pressed) {
		ToggleFreecam();
		return true;
	}

	return false;
}

Internal::ILogManager* ChairloaderCore::GetLogManager()
{
	return &LogManager::Get();
}

Internal::IModDllManager* ChairloaderCore::GetDllManager()
{
	return m_pModDllManager.get();
}

bool ChairloaderCore::IsModInstalled(const std::string& modName)
{
	return m_InstalledMods.find(modName) != m_InstalledMods.end();
}

std::unique_ptr<IChairLogger> ChairloaderCore::CreateLogger()
{
	return std::make_unique<ChairLogger>();
}

const std::string& ChairloaderCore::GetKeyStrHideGui()
{
	return gChair->GetKeyNames().left.at(m_KeyHideGui);
}

const std::string& ChairloaderCore::GetKeyStrToggleFreecam()
{
	return gChair->GetKeyNames().left.at(m_KeyToggleFreecam);
}

void ChairloaderCore::ToggleFreecam()
{
	if (!gEnv->pSystem->IsDevMode())
		CryError("FreeCam requires dev mode to be enabled");
	else if (*s_freeCamActive)
		gEnv->pConsole->ExecuteString("FreeCamDisable", true, false);
	else
		gEnv->pConsole->ExecuteString("FreeCamEnable", true, false);
}

bool ChairloaderCore::IsFreecamEnabled()
{
	return *s_freeCamActive;
}

void ChairloaderCore::LoadConfig()
{
    m_KeyHideGui = LoadConfigKey("HideGUIKey", eKI_F1);
    m_KeyToggleFreecam = LoadConfigKey("ToggleFreecamKey", eKI_F2);
}

void ChairloaderCore::SkipIntroMovies()
{
	if (!gChair->GetPreditorAPI() && !gEnv->pSystem->GetICmdLine()->FindArg(eCLAT_Pre, "novid"))
		return;

	gEnv->pConsole->GetCVar("sys_intromoviesduringinit")->Set(0);
	gEnv->pConsole->GetCVar("sys_rendersplashscreen")->Set(0);
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
            CryError("Chairloader: Invalid key name '{}' for '{}', setting to default", keyName, paramName);
    }

    // Failed to get from config, restore default
	gCL->conf->setConfigValue(CONFIG_NAME, paramName, keyNames.left.at(defaultKey), IChairloaderConfigManager::parameterType::String);
    return defaultKey;
}

IChairVarManager *ChairloaderCore::GetCVarManager() {
    return m_pCVarManager.get();
}
