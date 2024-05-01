#pragma once

//! Methods for manipulating a history file.
//! It keeps a list of strings, sorted from most recent.
class FileHistory
{
public:
    //! Reads the history file.
    //! @param  historyFile     The history XML file.
    //! @returns a list of file paths.
    static std::vector<std::string> ReadHistory(const fs::path& historyFile);

    //! Adds a path to the history.
    //! @param  historyFile     The history XML file.
    //! @param  path            Path to a add to history.
    static void AddToHistory(const fs::path& historyFile, const std::string& path);
};
