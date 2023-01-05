#include <boost/algorithm/string.hpp>
#include <Chairloader/IChairloaderDll.h>
#include <Prey/CryCore/Platform/CryWindows.h>
#include "ModDllManager.h"
#include "ChairloaderConfigManager.h"

void ModDllManager::SetHotReloadEnabled(bool state)
{
	CRY_ASSERT(m_RegisteredMods.empty() && m_Modules.empty());
	m_bHotReload = state;
}

void ModDllManager::RegisterModFromXML(pugi::xml_node xmlNode)
{
	ModuleInfo info;
	info.modName = boost::get<std::string>(gCL->conf->getNodeConfigValue(xmlNode, "modName"));
	info.loadOrder = boost::get<int>(gCL->conf->getNodeConfigValue(xmlNode, "loadOrder"));
	info.modDirPath = fs::current_path() / "Mods" / fs::u8path(info.modName);

	fs::path dllName = fs::u8path(boost::get<std::string>(gCL->conf->getNodeConfigValue(xmlNode, "dllName")));
	info.sourceDllPath = info.modDirPath / dllName;

	gCL->conf->loadModConfigFile(info.modName);
	m_RegisteredMods[info.loadOrder].push_back(std::move(info));
}

void ModDllManager::RegisterRawMod(const char* name, IChairloaderMod* pMod, bool asFirst)
{
	Module* mod;
	if (asFirst)
		mod = &(*m_Modules.emplace(m_Modules.begin()));
	else
		mod = &m_Modules.emplace_back();

	mod->modName = name;
	mod->bIsRawMod = true;
	mod->pModIface = pMod;
	CheckModSdkVersion(*mod);
	CryLog("[ModDllManager] Added raw mod {}", name);
}

void ModDllManager::LoadModules()
{
	if (m_bHotReload)
	{
		try
		{
			m_TempDirPath = fs::current_path() / "Mods/.temp";
			fs::create_directory(m_TempDirPath);

			// Remove old DLLs from the temp dir
			for (const fs::directory_entry& entry : std::filesystem::directory_iterator(m_TempDirPath))
			{
				std::string ext = entry.path().extension().u8string();
				boost::algorithm::to_lower(ext);

				if (entry.is_regular_file() && ext == ".dll")
				{
					fs::remove(entry.path());
				}
			}
		}
		catch (const std::exception& e)
		{
			CryFatalError("Error while creating/clearing mod temp directory:\n%s", e.what());
		}
	}

	for (const auto& [loadOrder, infoList] : m_RegisteredMods)
	{
		for (const ModuleInfo& info : infoList)
		{
			Module& mod = m_Modules.emplace_back(info);
			LoadModule(mod);
		}
	}

	// Registered list is not needed any more.
	m_RegisteredMods.clear();
}

void ModDllManager::UnloadModules()
{
	for (auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it)
		UnloadModule(*it);
}

void ModDllManager::ReloadModules()
{
	if (!m_bHotReload)
		CryFatalError("ModDllManager::ReloadModules: hot-reloading not enabled");

	// Collect mods that support hot-reloading
	std::vector<Module*> modsToReload;
	for (Module& i : m_Modules)
	{
		CRY_ASSERT(i.hModule);
		if (i.dllInfo.supportsHotReload)
			modsToReload.push_back(&i);
	}

	// Unload mods in reverse order
	CryWarning("[ModDllManager] Hot-unloading mods");
	for (auto it = modsToReload.rbegin(); it != modsToReload.rend(); ++it)
	{
		Module& mod = **it;
		mod.pModIface->ShutdownGame(true);
		mod.pModIface->ShutdownSystem(true);
		UnloadModule(mod);
	}

	// Reload mods
	CryWarning("[ModDllManager] Hot-reloading mods");
	for (auto it = modsToReload.begin(); it != modsToReload.end(); ++it)
	{
		Module& mod = **it;
		LoadModule(mod);
		InitModule(mod, true);
		mod.pModIface->InitGame(true);

		if (!mod.dllInfo.supportsHotReload)
			CryFatalError("Mod %s no longer supports hot-reloading after a hot-reload.", mod.modName.c_str());
	}
}

bool ModDllManager::CheckModulesForChanges()
{
	bool foundChanges = false;

	for (Module& mod : m_Modules)
	{
		if (!mod.bSourceFileModified && mod.dllInfo.supportsHotReload)
		{
			fs::file_time_type modTime = fs::last_write_time(mod.sourceDllPath);
			if (modTime != mod.sourceModificationTime)
			{
				foundChanges = true;
				mod.bSourceFileModified = true;
				CryLog("[ModDllManager] Mod {} was changed", mod.modName);
			}
		}
	}

	return foundChanges;
}

void ModDllManager::CallInitSystem()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
	{
		InitModule(*it, false);
	}
}

void ModDllManager::CallConnect() {
    std::vector<IChairloaderMod*> mods;
    mods.reserve(m_Modules.size());
    for(auto& mod : m_Modules) {
        mods.push_back(mod.pModIface);
    }
    for (auto& mod : m_Modules) {
        if (mod.pModIface) {
            mod.pModIface->Connect(mods);
        }
    }
}

void ModDllManager::CallInitGame()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->InitGame(false);
}

void ModDllManager::CallShutdownGame()
{
	for (auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it)
		it->pModIface->ShutdownGame(false);
}

void ModDllManager::CallShutdownSystem()
{
	for (auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it)
		it->pModIface->ShutdownSystem(false);
}

void ModDllManager::CallDraw()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->Draw();
}

void ModDllManager::CallUpdateBeforeSystem(unsigned updateFlags)
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->UpdateBeforeSystem(updateFlags);
}

void ModDllManager::CallUpdateBeforePhysics(unsigned updateFlags)
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->UpdateBeforePhysics(updateFlags);
}

void ModDllManager::CallMainUpdate(unsigned updateFlags)
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->MainUpdate(updateFlags);
}

void ModDllManager::CallLateUpdate(unsigned updateFlags)
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->LateUpdate(updateFlags);
}

void ModDllManager::LoadModule(Module& mod)
{
	CRY_ASSERT(!mod.hModule);
	
	if (m_bHotReload)
	{
		mod.bSourceFileModified = false;
		mod.sourceModificationTime = fs::last_write_time(mod.sourceDllPath);

		// Make a temp copy not to lock the source file.
		// Allows the compiler to overwrite it.
		fs::path copyName = fs::u8path(mod.modName + "." + mod.sourceDllPath.filename().u8string());
		mod.realDllPath = m_TempDirPath / copyName;

		std::error_code copyError;
		fs::copy(mod.sourceDllPath, mod.realDllPath, fs::copy_options::overwrite_existing, copyError);

		if (copyError.value() != 0)
		{
			CryFatalError("%s: Failed to make the DLL copy for hot-reloading.\n"
				"%s\n"
				"Source: %s\n"
				"Destination: %s", mod.modName.c_str(), copyError.message().c_str(),
				mod.sourceDllPath.u8string().c_str(), mod.realDllPath.u8string().c_str());
		}
	}
	else
	{
		// Use the file directly
		mod.realDllPath = mod.sourceDllPath;
	}

	CryLog("[ModDllManager] Loading {} ({})", mod.modName, mod.realDllPath.u8string());
	mod.hModule = ::LoadLibraryW(mod.realDllPath.c_str());
	if (!mod.hModule)
		CryFatalError("%s\nFailed to load the DLL.\n%s", mod.modName.c_str(), mod.realDllPath.u8string().c_str());

	mod.pfnInit = (IChairloaderMod::ProcInitialize*)GetProcAddress(mod.hModule, IChairloaderMod::PROC_INITIALIZE);
	mod.pfnShutdown = (IChairloaderMod::ProcShutdown*)GetProcAddress(mod.hModule, IChairloaderMod::PROC_SHUTDOWN);

	if (!mod.pfnInit || !mod.pfnShutdown)
		CryFatalError("%s\nMissing function exports", mod.modName.c_str());

	mod.pModIface = mod.pfnInit();

	if (!mod.pModIface)
		CryFatalError("%s\nInitialize returned nullptr", mod.modName.c_str());

	CheckModSdkVersion(mod);
}

void ModDllManager::UnloadModule(Module& mod)
{
	CRY_ASSERT(mod.hModule);
	CryLog("[ModDllManager] Unloading {} ({})", mod.modName, mod.realDllPath.u8string());
	mod.pfnShutdown();
	FreeLibrary(mod.hModule);

	mod.hModule = nullptr;
	mod.pfnInit = nullptr;
	mod.pfnShutdown = nullptr;
	mod.pModIface = nullptr;
}

void ModDllManager::InitModule(Module& mod, bool isHotReloading)
{
	IChairloaderMod::ModInitInfo initInfo;
	initInfo.pSystem = gEnv->pSystem;
	initInfo.pChair = gChair;
	initInfo.modDirPath = mod.modDirPath;
	initInfo.modDllPath = mod.realDllPath;
	initInfo.isHotReloading = isHotReloading;

	mod.dllInfo = IChairloaderMod::ModDllInfo();
	mod.pModIface->InitSystem(initInfo, mod.dllInfo);

	if (mod.dllInfo.thisStructSize == 0)
		CryFatalError("[ModDllManager] %s: dllInfo is not initialized", mod.modName.c_str());

	if (mod.modName != mod.dllInfo.modName)
		CryWarning("[ModDllManager] {}: Name mismatch. DLL says \"{}\"", mod.modName.c_str(), mod.dllInfo.modName);

	if (mod.bIsRawMod && mod.dllInfo.supportsHotReload)
		mod.dllInfo.supportsHotReload = false;
}

void ModDllManager::CheckModSdkVersion(Module& mod)
{
	bool isValid = false;
	int major = -1, minor = -1, patch = -1;
	mod.pModIface->GetModSdkVersion(major, minor, patch);

	if (major >= 0 && minor >= 0 && patch >= 0)
	{
		if (MOD_SDK_VERSION_MAJOR == 0)
		{
			// Everything must match 1:1
			isValid = major == MOD_SDK_VERSION_MAJOR && minor == MOD_SDK_VERSION_MINOR && patch == MOD_SDK_VERSION_PATCH;
		}
		else
		{
			if (MOD_SDK_VERSION_MAJOR == major)
			{
				if (MOD_SDK_VERSION_MINOR > minor)
				{
					// e.g. 1.2.0 > 1.1.5
					isValid = true;
				}
				else if (MOD_SDK_VERSION_MINOR == minor)
				{
					isValid = MOD_SDK_VERSION_PATCH > patch;
				}
			}
		}
	}

	if (!isValid)
	{
		CryFatalError("Mod {} uses a version of Mod SDK that isn't supported by this version of Chairloader\n\n"
			"Chairloader: {}.{}.{}\n"
			"Mod: {}.{}.{}", mod.modName, MOD_SDK_VERSION_MAJOR, MOD_SDK_VERSION_MINOR, MOD_SDK_VERSION_PATCH,
			major, minor, patch);
	}
}

