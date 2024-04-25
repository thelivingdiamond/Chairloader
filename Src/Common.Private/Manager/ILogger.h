#pragma once
#include <boost/format.hpp>
#include <Manager/LogEntry.h>

struct ILogger
{
    virtual ~ILogger() {}

    //! Prints a string to the log.
    //! Fatal logs will additionally throw an exception.
    virtual void LogString(severityLevel level, std::string_view str) = 0;

    //! Prints a string to the log and displays it in the overlay.
    //! Fatal logs will additionally throw an exception.
    virtual void OverlayLogString(severityLevel level, std::string_view str) = 0;

    //! Logs a formatted string to the log.
    //! Fatal logs will additionally throw an exception.
    template<typename... Args>
    inline void Log(severityLevel level, const char* format, const Args&...args)
    {
        auto message = boost::str((boost::format(format) % ... % args));
        LogString(level, message);
    }

    //! Prints a string to the log and displays it in the overlay.
    //! Fatal logs will additionally throw an exception.
    template<typename... Args>
    inline void OverlayLog(severityLevel level, const char* format, const Args&...args)
    {
        auto message = boost::str((boost::format(format) % ... % args));
        OverlayLogString(level, message);
    }
};