#pragma once

enum class logLevel {
    normal = 0,
    warning = 1,
    error = 2,
};

struct logMessage {
    std::string message;
    std::string modName;
    uint64_t time;
    logLevel level;

    logMessage(){

    }

    logMessage(const std::string &message, const std::string &modName, logLevel level) : message(message),
                                                                                         modName(modName),
                                                                                         level(level) {
        time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }

    bool empty() {
        return message.empty();
    }
};

struct IChairloaderGui
{
    virtual ~IChairloaderGui() {}

    //! @returns whether the GUI is currently enabled and being drawn to the screen.
    virtual bool IsEnabled() = 0;
    virtual void SetEnabled(bool state) = 0;

//    virtual void overlayLog(std::string modName, const char* format, ...) = 0;
//    virtual void overlaywarning(std::string modName, const char* format, ...) = 0;
//    virtual void overlayError(std::string modName, const char* format, ...) = 0;

//	virtual void logItem(std::string msg, const std::string modName, logLevel level = logLevel::normal, bool displayToScreen = true) = 0;
//	virtual void logItem(logMessage message, bool displayToScreen = true) = 0;
};
