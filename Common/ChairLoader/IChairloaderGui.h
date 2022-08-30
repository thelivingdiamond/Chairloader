#pragma once

enum class logLevel {
    normal = 0,
    warning = 1,
    error = 2,
};

struct logMessage {
    std::string message;
    std::string modName;
    time_t time;
    logLevel level;

    bool empty() {
        return message.empty();
    }
};

struct IChairloaderGui {
     virtual void overlayLog(std::string modName, const char* format, ...) = 0;
     virtual void overlaywarning(std::string modName, const char* format, ...) = 0;
     virtual void overlayError(std::string modName, const char* format, ...) = 0;

	virtual void logItem(std::string msg, const std::string modName, logLevel level = logLevel::normal, bool displayToScreen = true) = 0;
	virtual void logItem(logMessage message, bool displayToScreen = true) = 0;
};
