#include <execution>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <Manager/ILogger.h>
#include "PreyFilesPatchProgressDialog.h"

PreyFilesPatchProgressDialog::PreyFilesPatchProgressDialog(ILogger* pLogger)
{
    m_pLogger = pLogger;
}

PreyFilesPatchProgressDialog::~PreyFilesPatchProgressDialog()
{
}

void PreyFilesPatchProgressDialog::Start()
{
    fs::path preyFilesPath = fs::absolute("PreyFiles");
    fs::path mergingLibPath= fs::absolute("MergingLibrary");
    fs::path xmlTypesPath = fs::absolute("XmlTypeLibrary.xml");
    m_pLogger->Log(severityLevel::info, "Starting XML patching");

    m_Future = std::async(std::launch::async, [this, preyFilesPath, mergingLibPath, xmlTypesPath]()
    {
        auto fnCallback = [this](const std::string& msg)
        {
            auto lock = m_ProgressText.GetScopedLock();
            m_ProgressText.GetData() = msg;
        };

        fnCallback("Loading XML type library");
        XmlTypeLibrary xmlTypeLib;
        xmlTypeLib.LoadTypesFromFile(xmlTypesPath);

        fnCallback("Loading merging library");
        MergingLibrary3 mergingLib(&xmlTypeLib);
        mergingLib.LoadFromPath(mergingLibPath);

        PreyFilePatcher::PatchDirectory(
            preyFilesPath,
            mergingLib,
            &xmlTypeLib,
            fnCallback);
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
