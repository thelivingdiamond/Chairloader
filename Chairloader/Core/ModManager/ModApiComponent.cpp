#include "ModManager/ModApiComponent.h"

ModApiComponent::ModApiComponent(ChairMod* pMod, IChairloaderMod* pApi)
    : ModComponent(pMod)
{
    m_pApi = pApi;
}
