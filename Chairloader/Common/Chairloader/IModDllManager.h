#pragma once

namespace Internal
{

struct IModDllManager
{
	virtual ~IModDllManager() {}

	//! Loads the mod DLLs.
	virtual void LoadModules() = 0;

	//! Unloads all mod DLLs.
	virtual void UnloadModules() = 0;

	//! Reloads DLLs that support hot-reloading. It must be called after PostUpdate but before PreUpdate of the mods.
	virtual void ReloadModules() = 0;

	//! Checks if any DLLs have been modified since last loading.
	//! @returns true if changes were detected.
	virtual bool CheckModulesForChanges() = 0;

	//! Calls a function for each mod in the load order or reverse order.
	//! @{
	virtual void CallInitSystem() = 0;
	virtual void CallInitGame() = 0;
	virtual void CallShutdownGame() = 0;
	virtual void CallShutdownSystem() = 0;
	virtual void CallDraw() = 0;
	virtual void CallUpdateBeforeSystem(unsigned updateFlags) = 0;
	virtual void CallUpdateBeforePhysics(unsigned updateFlags) = 0;
	virtual void CallMainUpdate(unsigned updateFlags) = 0;
	virtual void CallLateUpdate(unsigned updateFlags) = 0;
	//! @}
};

} // namespace Internal
