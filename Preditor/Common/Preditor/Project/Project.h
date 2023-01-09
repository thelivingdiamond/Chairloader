//
// Created by theli on 10/28/2022.
//
#pragma once

// this class will be used to store all the data for a project
// should contain a path to the project, and a list of all the files in the project
class Project
{
public:
    //! Name of the project file.
    static constexpr char PROJECT_FILE_NAME[] = ".preditor_project";

    //! @param  path            Path to the directory
    //! @param  loadExisting    Load existing project instead of creating a new one.
    Project(const fs::path& path, bool loadExisting);

    //! Saves the project data to disk.
    void SaveProject();

    //! @returns the project name.
    const std::string& GetName() { return m_ProjectName; }

    //! @returns path to the project directory.
    const fs::path& GetPath() { return m_ProjectPath; }

    //! @returns the path to the directory with runtime files.
    const fs::path& GetRuntimePath() { return m_ProjectRuntimePath; }

private:
    //! Path to runtime-generated data. Can be removed, must not be checked into version control.
    static constexpr char RUNTIME_PATH[] = "Runtime";
    
    fs::path m_ProjectPath;
    fs::path m_ProjectFilePath;
    fs::path m_ProjectRuntimePath;

    std::string m_ProjectName; //!< Name of the directory

    //! Constructs paths from m_ProjectPath. Creates directories.
    void ConstructPaths();

    //! Loads project data from disk.
    void LoadProject();
};
