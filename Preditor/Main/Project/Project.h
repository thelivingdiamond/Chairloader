//
// Created by theli on 10/28/2022.
//
#pragma once
#include <Preditor/Main/IProject.h>

namespace Main
{

// this class will be used to store all the data for a project
// should contain a path to the project, and a list of all the files in the project
class Project : public IProject
{
public:
    //! @param  path            Path to the directory
    Project(const fs::path& path);

    //! Saves the project data to disk.
    void SaveProject();

    // IProject
    virtual const std::string& GetName() override { return m_ProjectName; }
    virtual const fs::path& GetDirectory() override { return m_ProjectPath; }
    virtual const fs::path& GetProjectFilePath() override { return m_ProjectFilePath; }

private:
    //! Path to runtime-generated data. Can be removed, must not be checked into version control.
    static constexpr char RUNTIME_PATH[] = "Runtime";

    fs::path m_ProjectPath;
    fs::path m_ProjectFilePath;

    std::string m_ProjectName; //!< Name of the directory

    //! Constructs paths from m_ProjectPath. Creates directories.
    void ConstructPaths();

    //! Loads project data from disk.
    void LoadProject();
};

} // namespace Main
