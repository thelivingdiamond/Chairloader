//
// Created by theli on 1/14/2023.
//

#ifndef CHAIRLOADER_LOGENTRY_H
#define CHAIRLOADER_LOGENTRY_H
#include <chrono>
#include <boost/format.hpp>

//TODO: rework logging system to be CryLog() compatible
enum class severityLevel{
    trace,
    debug,
    info,
    warning,
    error,
    fatal
};

class LogEntry{
public:
    LogEntry(const std::string &messageIn, severityLevel levelIn): message(messageIn), level(levelIn){
        tm timeStruct{};
        timeNow = time(nullptr);
        localtime_s(&timeStruct,&timeNow);
        timeStamp = boost::str((boost::format("%i:%i:%i") % timeStruct.tm_hour % timeStruct.tm_min % timeStruct.tm_sec));
        fadeTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    }
    std::string message;
    severityLevel level;
    std::string timeStamp;
    time_t timeNow;
    uint64_t fadeTime;
};

#endif //CHAIRLOADER_LOGENTRY_H
