#pragma once

//! Methods for manipulating the project history file.
class ProjectHistory
{
public:
    //! Name of the file.
    static constexpr char FILE_PATH[] = "Preditor/ProjectHistory.xml";

    //! Reads the history file.
    //! @returns a list of project directory paths.
    static std::vector<fs::path> ReadHistory();

    //! Adds a path to the history.
    //! @param  path    Path to a project directory.
    static void AddToHistory(const fs::path& path);
};
