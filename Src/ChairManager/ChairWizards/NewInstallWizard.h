#pragma once
#include <Manager/ILogger.h>

class GameVersion;
class WizardStage;
class WizardManager;

class NewInstallWizard
{
public:
    NewInstallWizard(ILogger* pLogger);
    ~NewInstallWizard();

    void Update();
    bool IsFinished();

private:
    ILogger* m_pLogger = nullptr;
    std::unique_ptr<GameVersion> m_pGameVersion;

    std::unique_ptr<WizardManager> m_pWizMgr;
    std::unique_ptr<WizardStage> m_pGamePathStage;
    std::unique_ptr<WizardStage> m_pWelcomeStage;
    std::unique_ptr<WizardStage> m_pVersionCheckStage;
    std::unique_ptr<WizardStage> m_pVerifyFilesWarningStage;
    std::unique_ptr<WizardStage> m_pConfirmStage;
    std::unique_ptr<WizardStage> m_pPatchDllStage;
    std::unique_ptr<WizardStage> m_pExtractFilesStage;
    std::unique_ptr<WizardStage> m_pPatchFilesStage;
    std::unique_ptr<WizardStage> m_pInstallChairStage;
    std::unique_ptr<WizardStage> m_pDeployStage;
    std::unique_ptr<WizardStage> m_pFinishStage;
};
