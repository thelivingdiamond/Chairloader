#pragma once

class ChairMod;

class ModComponent : NoCopy
{
public:
    //! Constructs the component for a mod.
    ModComponent(ChairMod* pMod);
    virtual ~ModComponent();

    //! @returns the component's mod.
    ChairMod* GetMod() const { return m_pMod; }

private:
    ChairMod* m_pMod = nullptr;
};
