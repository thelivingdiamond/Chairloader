#include <execution>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <Manager/ILogger.h>
#include "PreyFilesPatchProgressDialog.h"
#include "PreyFilesPatchTask.h"

PreyFilesPatchProgressDialog::PreyFilesPatchProgressDialog(ILogger* pLogger)
{
    m_pLogger = pLogger;
}

PreyFilesPatchProgressDialog::~PreyFilesPatchProgressDialog()
{
}

void PreyFilesPatchProgressDialog::Start()
{
    m_pLogger->Log(severityLevel::info, "Starting XML patching");

    m_Future = std::async(std::launch::async, [this]()
    {
        PreyFilesPatchTask task;
        task.logCallback = [](std::string_view msg) {};
        task.progressCallback = [this](std::string_view fileName, float progress)
        {
            auto lock = m_ProgressText.GetScopedLock();
            m_ProgressText.GetData() = fileName;
        };

        task.RunTask();
    });
}

bool PreyFilesPatchProgressDialog::ShowUI()
{
    if (m_Future.valid() && IsFutureReady(m_Future))
    {
        try
        {
            m_Future.get();
            m_pLogger->Log(severityLevel::info, "XML patching succeded");
            return false;
        }
        catch (const std::exception& e)
        {
            m_ErrorText = e.what();
            m_pLogger->Log(severityLevel::error, "XML patching failed: %s", e.what());
        }
    }

    if (!m_ErrorText.empty())
    {
        ImGui::TextWrapped("Error:\n%s", m_ErrorText.c_str());
        
        if (ImGui::Button("Close"))
            return false;
        else
            return true;
    }
    
    auto lock = m_ProgressText.GetScopedLock();
    ImGui::Text("Processing...");
    ImGui::Text("%s", m_ProgressText.GetData().c_str());
    return true;
}
