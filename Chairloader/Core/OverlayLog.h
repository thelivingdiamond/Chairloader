#pragma once
#include <Prey/ArkEntityArchetypeLibrary.h>
#include <ChairLoader/IChairloaderGui.h>
#include <Chairloader/ILogManager.h>
#include <ConsoleColorParser.h>


class OverlayLogManager{
public:
    OverlayLogManager();
    ~OverlayLogManager();
    // show persistent transparent log overlay
    void draw();
    void setMessageTimeoutInterval(float milliseconds);
private:
    uint64_t MessageTimeoutTime = 10000;

    class OverlayParser : public ConsoleColorParser
    {
    protected:
        void PrintText(const char* text, size_t size, int color) override;
        void NewLine() override;
    };
    OverlayParser m_Parser;
};