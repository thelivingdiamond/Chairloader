//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECTMANAGER_H
#define CHAIRLOADER_PROJECTMANAGER_H

#include "pch.h"
#include "Project.h"

//! PROJECT MANAGER
// this class will keep track of projects, and will be able to create new ones, and load existing ones
// should store previous projects in a file, and load them on startup

class ProjectManager {
public:
    ProjectManager();
    ~ProjectManager();

    void Init();
    void Update();

private:
    fs::path ProjectDirectory;
    std::vector<fs::path> PreviousProjects;
};


#endif //CHAIRLOADER_PROJECTMANAGER_H
