//
// Created by theli on 10/28/2022.
//

#include "ProjectManager.h"
#include "ConfigManager.h"

static ProjectManager* s_pProjectManager = nullptr;

void ProjectManager::Update() {


}

void ProjectManager::Init() {
    if(!ConfigManager::Get()) return;
    auto projectsNode = ConfigManager::Get()->getConfigNode().child("Projects");
    if(!projectsNode) return;
    for(auto projectNode: projectsNode){
        fs::path path = projectNode.attribute("Path").as_string();
        if(!fs::exists(path)){
            projectsNode.remove_child(projectNode);
        }
    }
    for(auto projectNode : projectsNode){
        fs::path path = projectNode.attribute("Path").as_string();
        if(!path.empty()){
            m_PreviousProjects.push_back(path);
        }
    }
    ConfigManager::Get()->SaveToXML();
}

ProjectManager::ProjectManager() {
    s_pProjectManager = this;
}

ProjectManager *ProjectManager::Get() {
    return s_pProjectManager;
}

void ProjectManager::addPreviousProject(const fs::path &path) {
    if(!ConfigManager::Get()) return;
    //check if previous project already exists, if so delete it and add it to the beginning
    for(auto &project : m_PreviousProjects){
        if(project == path){
            m_PreviousProjects.erase(std::remove(m_PreviousProjects.begin(), m_PreviousProjects.end(), project), m_PreviousProjects.end());
            break;
        }
    }
    //add the new project to the beginning
    m_PreviousProjects.insert(m_PreviousProjects.begin(), path);
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

void ProjectManager::setProjectDirectory(const fs::path &path) {
    m_ProjectDirectory = path;
    addPreviousProject(path);
}
