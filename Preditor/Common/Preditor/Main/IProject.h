#pragma once

struct IProject
{
    //! Name of the project file.
    static constexpr char PROJECT_FILE_NAME[] = ".preditor_project";

    virtual ~IProject() {}

    //! @returns the name of the project.
    virtual const std::string& GetName() = 0;

    //! @returns the directory where the project file is.
    virtual const fs::path& GetDirectory() = 0;

    //! @returns path to the project file.
    virtual const fs::path& GetProjectFilePath() = 0;
};
