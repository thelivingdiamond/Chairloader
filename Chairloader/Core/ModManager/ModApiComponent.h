#pragma once
#include "ModManager/ModComponent.h"

struct IChairloaderMod;

class ModApiComponent : public ModComponent
{
public:
    ModApiComponent(ChairMod* pMod, IChairloaderMod* pApi);

    //! @returns the Mod API.
    IChairloaderMod* GetApi() const { return m_pApi; }

private:
    IChairloaderMod* m_pApi = nullptr;
};
