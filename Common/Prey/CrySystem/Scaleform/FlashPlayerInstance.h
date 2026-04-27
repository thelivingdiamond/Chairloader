//
// Created by theli on 4/22/2026.
//

#ifndef CHAIRLOADER_FLASHPLAYERINSTANCE_H
#define CHAIRLOADER_FLASHPLAYERINSTANCE_H
#include "IFlashPlayer.h"

#endif //CHAIRLOADER_FLASHPLAYERINSTANCE_H



class CFlashPlayer : public IFlashPlayer, public IFlashPlayer_RenderProxy
{
public:
    virtual void AddRef();
    virtual void Release();
};
