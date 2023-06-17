#pragma once
#include "App/AppStage.h"

class MainStage : public AppStage
{
public:
    void Update() override;
    void ShowUI(bool* bOpen) override;
};
