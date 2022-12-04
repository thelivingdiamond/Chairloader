//
// Created by theli on 10/28/2022.
//

#ifndef CHAIRLOADER_PROJECTMANAGER_H
#define CHAIRLOADER_PROJECTMANAGER_H
#include "Project.h"

//! PROJECT MANAGER
//! this class will keep track of projects, and will be able to create new ones, and load existing ones
//! should store previous projects in a file, and load them on startup
//! Only supports one project loaded at a time (we can load only one instance of the game).
//! Can't unload projects as that requires runtime engine reload.
class ProjectManager {
public:
    ProjectManager();
    ~ProjectManager() = default;

    //! @returns the singleton instance.
    static ProjectManager* Get();

    //! @returns the currently loaded project.
    static Project* GetProject() { return Get()->m_pProject.get(); }

    //! Loads an existing project.
    //! @param  path    Path to the directory
    void LoadProject(const fs::path& path);

    //! Creates a new project.
    //! @param  path    Path to the directory
    void CreateProject(const fs::path& path);

    std::vector<fs::path>& getPreviousProjects() { return m_PreviousProjects; }
    void addPreviousProject(const fs::path& path);
    void savePreviousProjects();

private:
    std::vector<fs::path> m_PreviousProjects;
    std::unique_ptr<Project> m_pProject;

    //! Validates whether the path to project dir is valid.
    void ValidatePathOrThrow(const fs::path& path);

    void CreateOrLoadProject(const fs::path& path, bool loadExisting);
};


#endif //CHAIRLOADER_PROJECTMANAGER_H
