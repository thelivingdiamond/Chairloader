#pragma once
#include <Prey/ArkEntityArchetypeLibrary.h>
#include <Chairloader/IChairloaderGui.h>
#include <Chairloader/ILogManager.h>
#include <ConsoleColorParser.h>


class LogManager;

class OverlayLogManager{
public:
    OverlayLogManager(std::shared_ptr<LogManager> pLogManager);
    ~OverlayLogManager();
    // show persistent transparent log overlay
    void draw();
    void setMessageTimeoutInterval(float milliseconds);
private:
    uint64_t MessageTimeoutTime = 10000;
    std::shared_ptr<LogManager> m_pLogManager;

    class OverlayParser : public ConsoleColorParser
    {
    protected:
        void PrintText(const char* text, size_t size, int color) override;
        void NewLine() override;
    };
    OverlayParser m_Parser;
};
