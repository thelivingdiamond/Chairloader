#include <Prey/CryCore/Platform/CryWindows.h>
#include "ModDllManager.h"
#include "ChairloaderConfigManager.h"
#include "ChairLoader.h"

void ModDllManager::RegisterModFromXML(pugi::xml_node xmlNode)
{
	ModuleInfo info;
	info.modName = boost::get<std::string>(gConf->getNodeConfigValue(xmlNode, "modName"));
	info.loadOrder = boost::get<int>(gConf->getNodeConfigValue(xmlNode, "loadOrder"));
	info.modDirPath = fs::current_path() / "Mods" / fs::u8path(info.modName);

	fs::path dllName = fs::u8path(boost::get<std::string>(gConf->getNodeConfigValue(xmlNode, "dllName")));
	info.sourceDllPath = info.modDirPath / dllName;

	gConf->loadModConfigFile(info.modName);
	m_RegisteredMods[info.loadOrder].push_back(std::move(info));
}

void ModDllManager::LoadModules()
{
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

void ModDllManager::CallInitSystem()
{
	IChairloaderMod::ModInitInfo initInfo;
	initInfo.pSystem = gEnv->pSystem;
	initInfo.pChair = gCL;

	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
	{
		initInfo.modDirPath = it->modDirPath;
		initInfo.modDllPath = it->sourceDllPath;

		it->dllInfo = IChairloaderMod::ModDllInfo();
		it->pModIface->InitSystem(initInfo, it->dllInfo);

		if (it->dllInfo.thisStructSize == 0)
			CryFatalError("[ModDllManager] %s: dllInfo is not initialized", it->modName.c_str());

		if (it->modName != it->dllInfo.modName)
			CryWarning("[ModDllManager] %s: Name mismatch. DLL says \"%s\"", it->modName.c_str(), it->dllInfo.modName);
	}
}

void ModDllManager::CallInitGame()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->InitGame();
}

void ModDllManager::CallPreUpdate()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->PreUpdate();
}

void ModDllManager::CallDraw()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->Draw();
}

void ModDllManager::CallPostUpdate()
{
	for (auto it = m_Modules.begin(); it != m_Modules.end(); ++it)
		it->pModIface->PostUpdate();
}

void ModDllManager::CallShutdownGame()
{
	for (auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it)
		it->pModIface->ShutdownGame();
}

void ModDllManager::CallShutdownSystem()
{
	for (auto it = m_Modules.rbegin(); it != m_Modules.rend(); ++it)
		it->pModIface->ShutdownSystem();
}

void ModDllManager::LoadModule(Module& mod)
{
	CRY_ASSERT(!mod.hModule);
	
	CryLog("[ModDllManager] Loading %s", mod.sourceDllPath.u8string().c_str());
	mod.hModule = ::LoadLibraryW(mod.sourceDllPath.c_str());
	if (!mod.hModule)
		CryFatalError("%s\nFailed to load the DLL.\n%s", mod.modName.c_str(), mod.sourceDllPath.u8string().c_str());

	mod.pfnInit = (IChairloaderMod::ProcInitialize*)GetProcAddress(mod.hModule, IChairloaderMod::PROC_INITIALIZE);
	mod.pfnShutdown = (IChairloaderMod::ProcShutdown*)GetProcAddress(mod.hModule, IChairloaderMod::PROC_SHUTDOWN);

	if (!mod.pfnInit || !mod.pfnShutdown)
		CryFatalError("%s\nMissing function exports", mod.modName.c_str());

	mod.pModIface = mod.pfnInit();

	if (!mod.pModIface)
		CryFatalError("%s\nInitialize returned nullptr", mod.modName.c_str());
}

void ModDllManager::UnloadModule(Module& mod)
{
	CRY_ASSERT(mod.hModule);
	mod.pfnShutdown();
	FreeLibrary(mod.hModule);

	mod.hModule = nullptr;
	mod.pfnInit = nullptr;
	mod.pfnShutdown = nullptr;
	mod.pModIface = nullptr;
}
