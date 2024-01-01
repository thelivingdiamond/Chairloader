#pragma once
#include <App/AppStage.h>

//! Name of the project history file.
static constexpr char PROJECT_HISTORY_FILE_PATH[] = "Preditor/ProjectHistory.xml";

class ProjectCreateStage : public AppStage
{
public:
    virtual void Start() override;
    virtual void ShowUI(bool* bOpen) override;

private:
    std::string m_ModName;
    std::string m_DisplayName;
    std::string m_Author;
    bool m_HasDll = false;
    std::string m_DllName;
    
    std::string m_ProjectPath;
    bool m_CreateModFolder = true;

    bool m_IsAllValid = false;
    std::string m_ValidationErrors;
    std::string m_Warnings;

    bool m_IsCreateError = false;
    std::string m_CreateError;

    //! Checks if all values are valid.
    bool Validate();

    //! Creates the project.
    void CreateProject();

    void CreateProjectFile(const fs::path& projPath);
    void CopyDefaultFiles(const fs::path& projPath);
    void SaveModInfo(const fs::path& projPath);

    void ShowInputs();
    void ShowCreateError();
};
