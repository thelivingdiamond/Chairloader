#include <Manager/GamePath.h>
#include <Manager/PreditorFiles.h>
#include <WinShell/WinShell.h>
#include <Wizard/ProgressWizardStage.h>
#include <Wizard/WizardManager.h>
#include <Wizard/WizardStage.h>
#include <Prey/CryCore/Platform/WindowsUtils.h>
#include "ChairWizards/NewInstallWizard.h"
#include "ChairManager.h"
#include "GameVersion.h"
#include "PreyFilesPatchTask.h"

namespace
{

void ShowPatchWarning(bool isFinal)
{
    ImGui::TextColored(ImColor(255, 255, 0), isFinal ? "Final Warning: " : "Warning: ");
    ImGui::TextWrapped("Patching the game will turn your version of the game into an Epic Games Store version. "
        "Steam/GOG achievements will continue to work. Xbox Game Pass/MS Store achievements will be disabled.");
}

class GamePathStage : public WizardStage
{
public:
    GamePathStage(WizardManager* pMgr) : WizardStage("Game Path")
    {
        m_pMgr = pMgr;
        SetGamePath(ChairManager::Get().GetGamePath());
    }

    void SetGamePath(const fs::path& path)
    {
        fs::path exePath = !path.empty() ? path / ChairManager::Get().GetGamePathUtil().GetGameExePath() : path;
        exePath = exePath.lexically_normal();
        std::string pathStr = exePath.u8string();
        snprintf(m_PathInput, sizeof(m_PathInput), "%s", pathStr.c_str());
        ValidatePath();
    }

    virtual void ShowContent() override
    {
        ImGui::Text(R"(Select path to Prey.exe.)");
        ImGui::PushItemWidth(500);
        if (ImGui::InputText("##path", m_PathInput, sizeof(m_PathInput), 0))
            ValidatePath();
        ImGui::PopItemWidth();
        ImGui::SameLine();

        if (ImGui::Button("Browse..."))
        {
            WinShell::DialogOptions opts;
            opts.title = "Choose the Prey Executable...";
            opts.fileTypes.push_back({ "Prey executable (Prey.exe)", "Prey.exe" });
            WinShell::ImShowFileOpenDialog("GamePathDialog", opts);
        }

        WinShell::DialogResult dialogResult;

        if (WinShell::ImUpdateFileOpenDialog("GamePathDialog", &dialogResult))
        {
            if (dialogResult.isOk)
            {
                std::string filePathName = dialogResult.filePath.u8string();
                snprintf(m_PathInput, sizeof(m_PathInput), "%s", filePathName.c_str());
                ValidatePath();
            }
        }

        if (!m_ValidationError.empty())
            ImGui::TextColored(ImColor(255, 0, 0), "%s", m_ValidationError.c_str());

        if (m_IsValid)
        {
            ImGui::NewLine();
            ImGui::Text("Game path: %s", m_GamePath.GetGamePath().u8string().c_str());
            ImGui::Text("Platform: %s", m_GamePath.GetGamePlatformString());
        }
    }

    virtual bool CanContinue() override { return m_IsValid; }

    virtual bool CanReturn() override { return false; }

    virtual bool TryContinue() override
    {
        ChairManager::Get().SetGamePathFromWizard(m_Path);

        // Once path is set, need to restart the wizard.
        // This will refresh all steps that depend on path
        m_pMgr->Reset();
        return true;
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        std::promise<bool> promise;
        promise.set_value(m_IsValid);
        return promise.get_future();
    }

private:
    WizardManager* m_pMgr = nullptr;
    bool m_IsValid = false;
    char m_PathInput[260] = {};
    std::string m_ValidationError;
    fs::path m_Path;
    GamePath m_GamePath;

    void ValidatePath()
    {
        m_IsValid = false;
        m_ValidationError.clear();
        m_Path.clear();

        fs::path exePath = fs::u8path(m_PathInput);
        if (exePath.empty())
            return;

        if (GamePath::ValidateGamePath(exePath))
        {
            // Allow the input of game path instead of exe path
            m_IsValid = m_GamePath.TrySetGamePath(exePath, &m_ValidationError);
            m_Path = exePath;
            return;
        }

        m_IsValid = GamePath::ValidateExePath(exePath, &m_ValidationError);

        if (m_IsValid)
        {
            m_Path = GamePath::ExePathToGamePath(exePath);
            m_IsValid = m_GamePath.TrySetGamePath(m_Path, &m_ValidationError);
        }
    }
};

class WelcomeStage : public WizardStage
{
public:
    WelcomeStage() : WizardStage("Welcome")
    {
    }

    virtual void ShowContent() override
    {
        if (VersionCheck::getInstalledChairloaderVersion().valid() &&
            VersionCheck::getPackagedChairloaderVersion() > VersionCheck::getInstalledChairloaderVersion())
        {
            ImGui::TextWrapped("Current Installed Version: %s", VersionCheck::getInstalledChairloaderVersion().String().c_str());
            ImGui::TextWrapped("Available Version: %s", VersionCheck::getPackagedChairloaderVersion().String().c_str());
            ImGui::NewLine();
            ImGui::TextWrapped("Chairloader has been updated to a new version. The latest version will now be installed.");
            ImGui::NewLine();
        }
        else
        {
            ImGui::TextWrapped("Before using the Mod Manager, the game needs to be modified to add support "
                "for code mods and game scripts must be extracted.");
            ImGui::NewLine();
            ImGui::TextWrapped("It will be done automatically in the following steps.");
            ImGui::NewLine();

            ImGui::Text("\t1) Check if your version of the game is supported");
            ImGui::Text("\t2) Patch the game DLL file for Chairloader, if necessary");
            ImGui::Text("\t3) Install Chairloader files");
            ImGui::Text("\t4) Extract script files from the installed game");
            ImGui::NewLine();

            ShowPatchWarning(false);
        }
    }
};

class VersionCheckStage : public WizardStage
{
public:
    VersionCheckStage(GameVersion* pGameVersion) : WizardStage("Version Check")
    {
        m_pGameVersion = pGameVersion;
    }

    virtual void Reset() override
    {
        m_pGameVersion->CheckAgain();
    }

    virtual void ShowContent() override
    {
        ImGui::TextWrapped("Currently Chairloader only works with one specific version of Prey.");
        ImGui::TextWrapped("Other versions must be converted into that version.");
        ImGui::NewLine();

        m_pGameVersion->Update();
        GameVersion::Result result = m_pGameVersion->ShowInstalledVersion(false);

        if (result == GameVersion::Result::Error)
        {
            ImGui::Text("Error: %s", m_pGameVersion->GetErrorText().c_str());
        }
    }

    virtual bool CanContinue() override
    {
        return m_pGameVersion->GetResult() == GameVersion::Result::Supported ||
            m_pGameVersion->GetResult() == GameVersion::Result::Patchable;;
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        return std::async(std::launch::async, [=]()
        {
            // Not thread safe but whatever
            while (m_pGameVersion->GetResult() == GameVersion::Result::Loading)
                std::this_thread::sleep_for(std::chrono::milliseconds(50));

            if (isInitial)
            {
                return m_pGameVersion->GetResult() == GameVersion::Result::Supported;
            }
            else
            {
                return m_pGameVersion->GetResult() == GameVersion::Result::Supported ||
                    m_pGameVersion->GetResult() == GameVersion::Result::Patchable;
            }
        });
    }

private:
    GameVersion* m_pGameVersion = nullptr;
};

class VerifyFilesWarningStage : public WizardStage
{
public:
    VerifyFilesWarningStage() : WizardStage("Verify Game Files")
    {
    }

    virtual void ShowContent() override
    {
        ImGui::TextColored(ImColor(255, 255, 0), "Important!");
        ImGui::Text("If you ever installed any mods or an older version of Chairloader, "
            "please, ");
        ImGui::TextColored(ImColor(247, 115, 7), "verify game files ");
        ImGui::SameLine(0, 0);
        ImGui::Text("in Steam/GOG/EGS. Chairloader requires original game files");
        ImGui::Text("to install mods correctly.");
        ImGui::NewLine();
    }
};

class ConfirmStage : public WizardStage
{
public:
    ConfirmStage(GameVersion* pGameVersion) : WizardStage("Confirm")
    {
        m_pGameVersion = pGameVersion;
    }

    virtual void ShowContent() override
    {
        ImGui::TextWrapped("Chairloader is ready to be installed.");
        ImGui::NewLine();

        if (m_pGameVersion->GetResult() == GameVersion::Result::Patchable)
        {
            ShowPatchWarning(true);
            ImGui::NewLine();
        }

        ImGui::Text("This is your ");
        ImGui::SameLine(0, 0);
        ImGui::TextColored(ImColor(247, 115, 7), "last chance");
        ImGui::SameLine(0, 0);
        ImGui::Text(" to cancel the installation.");
        ImGui::Text("Do you wish to proceed?");
    }

private:
    GameVersion* m_pGameVersion = nullptr;
};

class PatchDllStage : public ProgressWizardStage
{
public:
    PatchDllStage(GameVersion* pGameVersion) : ProgressWizardStage("Patch DLL")
    {
        m_pGameVersion = pGameVersion;
    }

    virtual bool TryContinue() override
    {
        // Refresh the DLL state
        m_pGameVersion->CheckAgain();
        return true;
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        return std::async(std::launch::async, [=]()
        {
            // Not thread safe but whatever
            while (m_pGameVersion->GetResult() == GameVersion::Result::Loading)
                std::this_thread::sleep_for(std::chrono::milliseconds(50));

            return m_pGameVersion->GetResult() == GameVersion::Result::Supported;
        });
    }

protected:
    virtual void StartTask() override
    {
        if (m_pGameVersion->GetResult() == GameVersion::Result::Supported)
        {
            Task_LogMessage("Patching is not needed");
            std::promise<void> promise;
            promise.set_value();
            m_TaskFuture = promise.get_future();
        }
        else
        {
            m_TaskFuture = PatchDllAsync();
        }

        SetTaskFutureRef(m_TaskFuture);
    }

    virtual void OnTaskFinished() override
    {
        m_TaskFuture.get();
    }

private:
    GameVersion* m_pGameVersion = nullptr;
    std::future<void> m_TaskFuture;

    std::future<void> PatchDllAsync()
    {
        return std::async(std::launch::async, [=]()
        {
            Task_LogMessage("Patching the game DLL...");
            m_pGameVersion->PatchTheGame();
            Task_LogMessage("Finished patching");
        });
    }
};

class ExtractFilesStage : public ProgressWizardStage
{
public:
    ExtractFilesStage() : ProgressWizardStage("Extract Files")
    {
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        return std::async(std::launch::async, [=]()
        {
            // Extraction data must exist
            fs::path path = fs::current_path() / "PreyFiles" / PREDITOR_FILES_EXTRACTED;
            return fs::exists(path);
        });
    }

protected:
    virtual void StartTask() override
    {
        m_TaskFuture = ExtractAsync();
        SetTaskFutureRef(m_TaskFuture);
    }

    virtual void OnTaskFinished() override
    {
        m_TaskFuture.get();
    }

private:
    GameVersion* m_pGameVersion = nullptr;
    std::future<void> m_TaskFuture;

    std::future<void> ExtractAsync()
    {
        return std::async(std::launch::async, [=]()
        {
            fs::path outPath = fs::absolute("PreyFiles");
            Task_LogMessage(fmt::format("Output path: {}", outPath.u8string()));

            // Remove old files
            fs::remove_all(outPath);

            // Create directory
            fs::create_directories(outPath);

            // Launch Preditor in extract mode
            STARTUPINFOW startupInfo = { sizeof(STARTUPINFOW) };
            PROCESS_INFORMATION processInfo = {};
            fs::path gamePath = ChairManager::Get().GetGamePathUtil().GetGamePath();
            std::string cmdLine = fmt::format("Preditor.exe --extract --game-path \"{}\" --output-path \"{}\"", gamePath.u8string(), outPath.u8string());
            std::wstring wideCmdLine;
            Unicode::Convert(wideCmdLine, cmdLine);

            bool result = CreateProcessW(
                nullptr, // lpApplicationName
                wideCmdLine.data(), // lpCommandLine
                nullptr, // lpProcessAttributes
                nullptr, // lpThreadAttributes
                false, // bInheritHandles
                0, // dwCreationFlags
                nullptr, // lpEnvironment
                nullptr, // lpCurrentDirectory
                &startupInfo, // lpStartupInfo
                &processInfo // lpProcessInformation
            );

            if (!result)
            {
                Task_LogMessage(fmt::format("Last Windows error: {}", WindowsErrorToString(GetLastError())));
                throw std::runtime_error("CreateProcessW failed");
            }

            WaitForSingleObject(processInfo.hProcess, INFINITE);

            DWORD exitCode = -1;
            if (!GetExitCodeProcess(processInfo.hProcess, &exitCode))
                throw std::runtime_error("GetExitCodeProcess failed");

            Task_LogMessage(fmt::format("Exit code: {}", exitCode));

            if (exitCode != 0)
                throw std::runtime_error(fmt::format("Preditor failed with code {}", exitCode));

            CloseHandle(processInfo.hProcess);
            CloseHandle(processInfo.hThread);

            if (!fs::exists(outPath / PREDITOR_FILES_EXTRACTED))
                throw std::runtime_error(fmt::format("{} was not found. Extraction failed.", PREDITOR_FILES_EXTRACTED));
        });
    }
};

class PatchFilesStage : public ProgressWizardStage
{
public:
    PatchFilesStage() : ProgressWizardStage("Patch Files")
    {
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        return std::async(std::launch::async, [=]()
        {
            return !PreyFilesPatchTask::IsPatchingRequired();
        });
    }

protected:
    virtual void StartTask() override
    {
        m_TaskFuture = PatchAsync();
        SetTaskFutureRef(m_TaskFuture);
    }

    virtual void OnTaskFinished() override
    {
        try
        {
            m_TaskFuture.get();
        }
        catch (const std::exception& e)
        {
            Task_LogMessage(e.what());
            throw std::runtime_error("Patching has failed. Validate game files and reinstall Chairloader.");
        }
    }

private:
    std::future<void> m_TaskFuture;

    std::future<void> PatchAsync()
    {
        return std::async(std::launch::async, [=]()
        {
            PreyFilesPatchTask task;
            task.logCallback = [this](std::string_view msg) { Task_LogMessage(msg); };
            task.progressCallback = [this](std::string_view msg, float progress)
            {
                Task_UpdateProgressSubtext(msg);
                Task_UpdateProgressBar(progress);
            };

            task.RunTask();
        });
    }
};

class InstallChairStage : public ProgressWizardStage
{
public:
    InstallChairStage() : ProgressWizardStage("Install Chairloader")
    {
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        return std::async(std::launch::async, [=]()
        {
            GamePath& gamePath = ChairManager::Get().GetGamePathUtil();

            for (const char* fileName : gamePath.GetRequiredChairloaderBinaries())
            {
                fs::path chairFilePath = fs::current_path() / gamePath.GetChairloaderBinSrcPath() / fileName;
                fs::path installedFilePath = gamePath.GetGamePath() / gamePath.GetGameBinDir() / fileName;

                if (!fs::exists(chairFilePath) || !fs::exists(installedFilePath))
                    return false;

                // Compare version
                SemanticVersion chairFileVersion = VersionCheck::getBinaryVersion(chairFilePath);
                SemanticVersion installedFileVersion = VersionCheck::getBinaryVersion(installedFilePath);

                if (chairFileVersion != installedFileVersion)
                    return false;
            }

            return true;
        });
    }

protected:
    virtual void StartTask() override
    {
        m_TaskFuture = InstallAsync();
        SetTaskFutureRef(m_TaskFuture);
    }

    virtual void OnTaskFinished() override
    {
        m_TaskFuture.get();
    }

private:
    std::future<void> m_TaskFuture;

    std::future<void> InstallAsync()
    {
        return std::async(std::launch::async, [=]()
        {
            GamePath& gamePath = ChairManager::Get().GetGamePathUtil();

            for (const char* fileName : gamePath.GetRequiredChairloaderBinaries())
            {
                fs::path chairFilePath = fs::current_path() / gamePath.GetChairloaderBinSrcPath() / fileName;
                fs::path installedFilePath = gamePath.GetGamePath() / gamePath.GetGameBinDir() / fileName;

                if (!fs::exists(chairFilePath))
                    throw std::runtime_error(fmt::format("Chairloader file '{}' not found. Reinstall Chairloader."));

                if (fs::exists(installedFilePath))
                {
                    // Compare versions
                    SemanticVersion chairFileVersion = VersionCheck::getBinaryVersion(chairFilePath);
                    SemanticVersion installedFileVersion = VersionCheck::getBinaryVersion(installedFilePath);

                    if (chairFileVersion == installedFileVersion)
                    {
                        Task_LogMessage(fmt::format("{}: version {} == {}", fileName, chairFileVersion.String(), installedFileVersion.String()));
                        continue;
                    }
                    else
                    {
                        Task_LogMessage(fmt::format("{}: version {} != {}", fileName, chairFileVersion.String(), installedFileVersion.String()));
                    }
                }

                // Replace the file
                Task_LogMessage(fmt::format("{}: installing", fileName));
                fs::copy(chairFilePath, installedFilePath, fs::copy_options::overwrite_existing);
            }
        });
    }
};

class DeployFilesStage : public ProgressWizardStage
{
public:
    DeployFilesStage() : ProgressWizardStage("Deploy Files")
    {
    }

    virtual std::future<bool> CheckFinishedConditionAsync(bool isInitial) override
    {
        // Always succeed.
        // If all previous steps are already finished during initialization, nothing will be done
        // If at least one step is not, deploy will happen
        std::promise<bool> promise;
        promise.set_value(true);
        return promise.get_future();
    }

protected:
    virtual void StartTask() override
    {
        m_TaskFuture = PatchAsync();
        SetTaskFutureRef(m_TaskFuture);
    }

    virtual void OnTaskFinished() override
    {
        try
        {
            m_TaskFuture.get();
        }
        catch (const std::exception& e)
        {
            Task_LogMessage(e.what());
            throw std::runtime_error("Deploy failed. Check ChairManager.log for details.");
        }
    }

private:
    std::future<void> m_TaskFuture;

    std::future<void> PatchAsync()
    {
        return std::async(std::launch::async, [=]()
        {
            auto fnLogCallback = [this](std::string_view msg) { Task_LogMessage(msg); };
            std::string deployErrorMessage;
            bool success = ChairManager::Get().DeployForInstallWizard(fnLogCallback, deployErrorMessage);

            if (!success)
                throw std::runtime_error("Deploy failed.\n" + deployErrorMessage);
        });
    }
};

class FinishStage : public WizardStage
{
public:
    FinishStage() : WizardStage("Finish")
    {
    }

    virtual void ShowContent() override
    {
        ImGui::TextWrapped("Chairloader has been successfully intalled");
    }
};

} // namespace

NewInstallWizard::NewInstallWizard(ILogger* pLogger)
{
    m_pLogger = pLogger;
    m_pGameVersion = std::make_unique<GameVersion>();

    m_pWizMgr = std::make_unique<WizardManager>(pLogger);
    m_pWizMgr->SetInitialCheckText("Validating Chairloader installation\n\nPlease, wait...");

    m_pGamePathStage = std::make_unique<GamePathStage>(m_pWizMgr.get());
    m_pWizMgr->AddStage(m_pGamePathStage.get());

    m_pWelcomeStage = std::make_unique<WelcomeStage>();
    m_pWelcomeStage->AddDependency(m_pGamePathStage.get());
    m_pWizMgr->AddStage(m_pWelcomeStage.get());

    m_pVersionCheckStage = std::make_unique<VersionCheckStage>(m_pGameVersion.get());
    m_pVersionCheckStage->AddDependency(m_pGamePathStage.get());
    m_pWizMgr->AddStage(m_pVersionCheckStage.get());

    m_pVerifyFilesWarningStage = std::make_unique<VerifyFilesWarningStage>();
    m_pVerifyFilesWarningStage->AddDependency(m_pGamePathStage.get());
    m_pWizMgr->AddStage(m_pVerifyFilesWarningStage.get());

    m_pConfirmStage = std::make_unique<ConfirmStage>(m_pGameVersion.get());
    m_pConfirmStage->AddDependency(m_pGamePathStage.get());
    m_pWizMgr->AddStage(m_pConfirmStage.get());

    m_pPatchDllStage = std::make_unique<PatchDllStage>(m_pGameVersion.get());
    m_pPatchDllStage->AddDependency(m_pVersionCheckStage.get());
    m_pWizMgr->AddStage(m_pPatchDllStage.get());

    m_pExtractFilesStage = std::make_unique<ExtractFilesStage>();
    m_pExtractFilesStage->AddDependency(m_pPatchDllStage.get());
    m_pWizMgr->AddStage(m_pExtractFilesStage.get());

    m_pPatchFilesStage = std::make_unique<PatchFilesStage>();
    m_pPatchFilesStage->AddDependency(m_pExtractFilesStage.get());
    m_pWizMgr->AddStage(m_pPatchFilesStage.get());

    m_pInstallChairStage = std::make_unique<InstallChairStage>();
    m_pInstallChairStage->AddDependency(m_pPatchFilesStage.get());
    m_pWizMgr->AddStage(m_pInstallChairStage.get());

    m_pDeployStage = std::make_unique<DeployFilesStage>();
    m_pDeployStage->AddDependency(m_pPatchFilesStage.get());
    m_pDeployStage->AddDependency(m_pInstallChairStage.get());
    m_pWizMgr->AddStage(m_pDeployStage.get());

    m_pFinishStage = std::make_unique<FinishStage>();
    m_pWizMgr->AddStage(m_pFinishStage.get());
}

NewInstallWizard::~NewInstallWizard()
{
}

void NewInstallWizard::Update()
{
    m_pGameVersion->Update();

    ImGuiWindowFlags windowFlags =
        ImGuiWindowFlags_NoSavedSettings |
        ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize;

    ImVec2 windowSize = { 800, 500 };
    windowSize = { windowSize.x * ChairManager::Get().GetDPIScale(), windowSize.y * ChairManager::Get().GetDPIScale() };
    ImGui::SetNextWindowSize(windowSize);

    if (ImGui::Begin("Chairloader Install Wizard", nullptr, windowFlags))
    {
        m_pWizMgr->ShowContent();
    }

    ImGui::End();
}

bool NewInstallWizard::IsFinished()
{
    // DeployStage is the last one. If it's done, all is done.
    return m_pWizMgr->IsDone() || m_pWizMgr->IsStageDone(m_pDeployStage.get());
}

bool NewInstallWizard::IsCancelled()
{
    return m_pWizMgr->IsCancelled();
}
