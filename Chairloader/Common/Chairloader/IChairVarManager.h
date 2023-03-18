//
// Created by theli on 1/6/2023.
//

struct ICVar;

struct IChairVarManager {
    ~IChairVarManager() = default;

    //! Register a CVar to the ChairVarManager, requires the VF_DUMPTOCHAIR flag to be set. The value will be restored across restarts.
    //! \param cvar The CVar to register
    //! \param modName The name of the mod that registered the CVar
    virtual void RegisterCVar(ICVar* cvar, const std::string& modName) = 0;

    //! Remove a CVar from the ChairVarManager, this variable will no longer be saved and will be reset to its default value on restart.
    //! \param cvar The CVar to remove
    virtual void UnregisterCVar(ICVar* cvar) = 0;

    //! Remove a CVar from the ChairVarManager, this variable will no longer be saved and will be reset to its default value on restart.
    //! \param name The name of the CVar to remove
    virtual void UnregisterCVar(const std::string& name) = 0;

    //! Called when the game is initialized, loads the config file.
    virtual void InitSystem() = 0;

    //! Called when the game is shutting down, saves the config file.
    virtual void ShutdownGame() = 0;

    //! Called every frame, saves the config file if the save interval has been reached.
    virtual void UpdateSystem() = 0;

};
