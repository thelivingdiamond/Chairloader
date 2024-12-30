#pragma once

class PreyFilesPatchTask
{
public:
    std::function<void(std::string_view msg)> logCallback;
    std::function<void(std::string_view msg, float progress)> progressCallback;

    static bool IsPatchingRequired();
    void RunTask();
};