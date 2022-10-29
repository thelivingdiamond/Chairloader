//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECTSELECTSTAGE_H
#define CHAIRLOADER_PROJECTSELECTSTAGE_H

#include "pch.h"
#include "App/AppStage.h"

class ProjectSelectStage: private AppStage {
public:
    void Update() override;
    void ShowUI(bool * bOpen) override;
    void Start() override;
};


#endif //CHAIRLOADER_PROJECTSELECTSTAGE_H
