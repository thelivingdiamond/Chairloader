//
// Created by theli on 10/28/2022.
//

#include "ProjectManager.h"
#include "ConfigManager.h"

static ProjectManager* s_pProjectManager = nullptr;

ProjectManager::ProjectManager() {
    s_pProjectManager = this;

    auto projectsNode = ConfigManager::Get()->getConfigNode().child("Projects");
    if (!projectsNode) return;
    for (auto projectNode : projectsNode) {
        fs::path path = projectNode.attribute("Path").as_string();
        if (!fs::exists(path)) {
            projectsNode.remove_child(projectNode);
        }
    }
    for (auto projectNode : projectsNode) {
        fs::path path = projectNode.attribute("Path").as_string();
        if (!path.empty()) {
            m_PreviousProjects.push_back(path);
        }
    }
    ConfigManager::Get()->SaveToXML();
}

ProjectManager *ProjectManager::Get() {
    return s_pProjectManager;
}

void ProjectManager::LoadProject(const fs::path& path)
{
    CreateOrLoadProject(path, true);
}

void ProjectManager::CreateProject(const fs::path& path)
{
    CreateOrLoadProject(path, false);
}

void ProjectManager::addPreviousProject(const fs::path &path) {
    fs::path absPath = absolute(path);
    if(!ConfigManager::Get()) return;
    //check if previous project already exists, if so delete it and add it to the beginning
    for(auto &project : m_PreviousProjects){
        if(project == absPath){
            m_PreviousProjects.erase(std::remove(m_PreviousProjects.begin(), m_PreviousProjects.end(), project), m_PreviousProjects.end());
            break;
        }
    }
    //add the new project to the beginning
    m_PreviousProjects.insert(m_PreviousProjects.begin(), absPath);
    savePreviousProjects();
}

void ProjectManager::savePreviousProjects() {
    if(!ConfigManager::Get()) return;
    auto projectsNode = ConfigManager::Get()->getConfigNode().child("Projects");
    if(!projectsNode) return;
    projectsNode.remove_children();
    for(auto &project : m_PreviousProjects){
        auto projectNode = projectsNode.append_child("Project");
        projectNode.append_attribute("Path") = project.string().c_str();
    }
    ConfigManager::Get()->SaveToXML();
}

void ProjectManager::ValidatePathOrThrow(const fs::path& path)
{
    if (!fs::exists(path))
        throw std::runtime_error("Project path doesn't exist");
    if (!fs::is_directory(path))
        throw std::runtime_error("Project path isn't a directory");
}

void ProjectManager::CreateOrLoadProject(const fs::path& path, bool loadExisting)
{
    if (m_pProject)
        throw std::logic_error("Only one project may be loaded");
    addPreviousProject(path);
    ValidatePathOrThrow(path);

    if (loadExisting)
    {
        if (!fs::exists(path / Project::PROJECT_FILE_NAME))
            throw std::runtime_error(fmt::format("Project file {} doesn't exist", Project::PROJECT_FILE_NAME));
    }

    m_pProject = std::make_unique<Project>(path, loadExisting);
}
