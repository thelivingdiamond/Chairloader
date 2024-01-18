#pragma once

class ChairMod;

//! Manages all enabled Chairloader mods.
class ModManager : NoCopy
{
public:
    ModManager();
    ~ModManager();

    //! Adds a new mod.
    void AddMod(std::unique_ptr<ChairMod>&& pMod);

private:
    std::vector<std::unique_ptr<ChairMod>> m_Mods;
};
