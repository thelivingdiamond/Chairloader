#pragma once
#include <boost/format.hpp>
#include <Manager/LogEntry.h>

//! Interface for basic ChairManager functionality.
//! Used by ChairManager modules that are shared with Preditor.
struct IChairManager
{
    virtual ~IChairManager() {}

    //! @returns path to the config directory (Mods/config).
    virtual fs::path GetConfigPath() = 0;

    //! @returns path to the mod directory. Throws if mod doesn't exist.
    virtual fs::path GetModPath(const std::string& modName) = 0;

    //! @returns the list of names of installed mods.
    virtual std::vector<std::string> GetModNames() = 0;

    //! @returns the mod display name or empty string if not found.
    virtual std::string GetModDisplayName(const std::string& modName) = 0;

    //! @returns whether the mod is enabled.
    virtual bool IsModEnabled(const std::string& modName) = 0;

    //! Prints a string to the log.
    //! Fatal logs will additionally throw an exception.
    virtual void LogString(severityLevel level, std::string_view str) = 0;

    //! Logs a formatted string to the log.
    //! Fatal logs will additionally throw an exception.
    template<typename... Args>
    inline void Log(severityLevel level, const char* format, const Args&...args)
    {
        auto message = boost::str((boost::format(format) % ... % args));
        LogString(level, message);
    }
};
