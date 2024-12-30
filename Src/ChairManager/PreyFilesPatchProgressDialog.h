#pragma once
#include <Manager/SynchronizedData.h>

struct ILogger;

class PreyFilesPatchProgressDialog : NoCopy
{
public:
    PreyFilesPatchProgressDialog(ILogger* pLogger);
    ~PreyFilesPatchProgressDialog();

    void Start();
    bool ShowUI();

private:
    ILogger* m_pLogger = nullptr;
    SynchronizedData<std::string> m_ProgressText;
    std::string m_ErrorText;
    std::future<void> m_Future;
};