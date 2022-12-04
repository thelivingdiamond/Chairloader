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
    ~ProjectManager() = default;

    void Init();
    void Update();

    static ProjectManager* Get();
    std::vector<fs::path>& getPreviousProjects() { return m_PreviousProjects; }
    void setProjectDirectory(const fs::path& path);
    fs::path getProjectDirectory() { return m_ProjectDirectory; }
    void addPreviousProject(const fs::path& path);
    void savePreviousProjects();
private:
    fs::path m_ProjectDirectory;
    std::vector<fs::path> m_PreviousProjects;
};


#endif //CHAIRLOADER_PROJECTMANAGER_H
