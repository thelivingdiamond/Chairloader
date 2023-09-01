#include <WinShell/WinShell.h>
#include <Manager/ModInfo.h>
#include <Preditor/Main/IProject.h>
#include "ProjectCreateStage.h"
#include "ProjectSelectStage.h"
#include "ProjectHistory.h"

static const ImVec2 WINDOW_SIZE = ImVec2(800, 0);
static constexpr ImGuiWindowFlags WINDOW_FLAGS =
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoDocking |
    ImGuiWindowFlags_NoBringToFrontOnFocus;
static constexpr char WINDOW_TITLE[] = "Create Project...";

static constexpr char GIT_IGNORE_NAME[] = ".gitignore";
static constexpr char ORIG_GIT_IGNORE_PATH[] = "Preditor/Project.gitignore";

static constexpr char DEFAULT_MOD_VERSION[] = "0.1.0";

void ProjectCreateStage::Start()
{
    Validate();
}

void ProjectCreateStage::ShowUI(bool* bOpen)
{
    ImGui::SetNextWindowSize(WINDOW_SIZE);

    if (ImGui::Begin(WINDOW_TITLE, bOpen, WINDOW_FLAGS))
    {
        if (m_IsCreateError)
            ShowCreateError();
        else
            ShowInputs();
    }

    ImGui::End();
}

bool ProjectCreateStage::Validate()
{
    std::string errBuf;
    m_IsAllValid = true;
    m_ValidationErrors.clear();
    m_Warnings.clear();

    if (m_ModName.empty())
        m_ValidationErrors += "Mod Name must be set\n";
    else if (!Manager::ModInfo::ValidateModName(m_ModName, &errBuf))
        m_ValidationErrors += errBuf + "\n";

    if (m_DisplayName.empty())
        m_ValidationErrors += "Display Name must be set\n";

    if (m_Author.empty())
        m_ValidationErrors += "Author Name must be set\n";

    if (m_HasDll && m_DllName.empty())
        m_ValidationErrors += "DLL Name must be set\n";

    if (m_ProjectPath.empty())
    {
        m_ValidationErrors += "Project Location must be set\n";
    }
    else
    {
        fs::path path = fs::u8path(m_ProjectPath);
        
        if (!path.is_absolute())
        {
            m_ValidationErrors += "Project Location must be absolute\n";
        }
        else if (m_CreateModFolder)
        {
            if (!fs::exists(path))
                m_ValidationErrors += "Project Location does not exist\n";
            else if (!fs::is_directory(path))
                m_ValidationErrors += "Project Location must be a directory\n";
        }

        fs::path projectPath = path;
        if (m_CreateModFolder)
            projectPath /= fs::u8path(m_ModName);

        if (fs::exists(projectPath))
        {
            if (fs::is_directory(projectPath))
                m_Warnings += "Project Location already exists. Files may be overwritten.\n";
            else
                m_ValidationErrors += "Project Location must be a directory\n";
        }
    }

    if (m_DisplayName.empty())
        m_ValidationErrors += "Display Name must be set\n";

    if (m_DisplayName.empty())
        m_ValidationErrors += "Display Name must be set\n";

    m_IsAllValid = m_ValidationErrors.empty();
    return m_IsAllValid;
}

void ProjectCreateStage::CreateProject()
{
    try
    {
        fs::path projPath = fs::u8path(m_ProjectPath);

        if (m_CreateModFolder)
            projPath /= fs::u8path(m_ModName);

        // Create the directory for the project
        fs::create_directory(projPath);

        CreateProjectFile(projPath);
        CopyDefaultFiles(projPath);
        SaveModInfo(projPath);

        ProjectHistory::AddToHistory(projPath);
        SetStageFinished(std::make_unique<ProjectSelectStage>());
    }
    catch (const std::exception& e)
    {
        m_IsCreateError = true;
        m_CreateError = e.what();
    }
}

void ProjectCreateStage::CreateProjectFile(const fs::path& projPath)
{
    fs::path filePath = projPath / IProject::PROJECT_FILE_NAME;
    pugi::xml_document doc;
    if (!doc.save_file(filePath.c_str()))
        throw std::runtime_error("Failed to create project file.");
}

void ProjectCreateStage::CopyDefaultFiles(const fs::path& projPath)
{
    // .gitignore
    fs::copy_file(
        gPreditor->pConfig->GetPreditorRoot() / ORIG_GIT_IGNORE_PATH,
        projPath / GIT_IGNORE_NAME,
        fs::copy_options::overwrite_existing);
}

void ProjectCreateStage::SaveModInfo(const fs::path& projPath)
{
    // Create ModInfo
    Manager::ModInfo modInfo;
    modInfo.modName = m_ModName;
    modInfo.displayName = m_DisplayName;
    modInfo.version = DEFAULT_MOD_VERSION;
    modInfo.author = m_Author;
    modInfo.hasXML = true;

    if (m_HasDll)
        modInfo.dllName = m_DllName;

    // Save XML
    pugi::xml_document doc;
    pugi::xml_node node = doc.append_child(Manager::ModInfo::XML_NODE_NAME);
    modInfo.SaveXml(node);
    
    bool saveSuccess = doc.save_file(
        (projPath / Manager::ModInfo::XML_FILE_NAME).c_str(),
        "    ",
        pugi::format_indent | pugi::format_indent_attributes);

    if (!saveSuccess)
        throw std::runtime_error(fmt::format("Failed to create {}.", Manager::ModInfo::XML_FILE_NAME));
}

void ProjectCreateStage::ShowInputs()
{
    bool changed = false;

    changed |= ImGui::InputText("Mod Name", &m_ModName);
    ImGui::TextDisabled("e.g. \"TheChair.ExampleMod\"");

    changed |= ImGui::InputText("Display Name", &m_DisplayName);
    ImGui::TextDisabled("e.g. \"Example Mod\"");

    changed |= ImGui::InputText("Author", &m_Author);
    ImGui::TextDisabled("e.g. \"The Chair\"");

    changed |= ImGui::Checkbox("Has a DLL", &m_HasDll);

    if (m_HasDll)
    {
        changed |= ImGui::InputText("DLL Name", &m_DllName);
        ImGui::TextDisabled("e.g. \"ExampleMod.dll\"");
    }

    changed |= ImGui::InputText("Project Location", &m_ProjectPath);
    ImGui::SameLine();
    if (ImGui::Button(ICON_MD_MORE_HORIZ "##Browse")) {
        WinShell::DialogOptions opts;
        opts.title = "Select Project Directory...";
        opts.flags |= WinShell::FL_PICK_FOLDERS;
        WinShell::ImShowFileOpenDialog("ProjectCreateStage::m_ProjectPath", opts);
    }

    changed |= ImGui::Checkbox("Create Project Folder", &m_CreateModFolder);

    WinShell::DialogResult dialogResult;

    if (WinShell::ImUpdateFileOpenDialog("ProjectCreateStage::m_ProjectPath", &dialogResult))
    {
        if (dialogResult.isOk)
        {
            m_ProjectPath = dialogResult.filePath.u8string();
            changed = true;
        }
    }

    if (changed)
        Validate();

    if (ImGui::Button("< Back"))
        SetStageFinished(std::make_unique<ProjectSelectStage>());

    ImGui::SameLine();
    ImGui::BeginDisabled(!m_IsAllValid);

    if (ImGui::Button("Create >"))
        CreateProject();

    ImGui::EndDisabled();

    if (!m_ValidationErrors.empty())
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", m_ValidationErrors.c_str());

    if (!m_Warnings.empty())
        ImGui::TextColored(ImVec4(1, 1, 0, 1), "%s", m_Warnings.c_str());
}

void ProjectCreateStage::ShowCreateError()
{
    ImGui::TextColored(ImVec4(1, 0, 0, 1), "Failed to create project:");
    ImGui::TextWrapped("%s", m_CreateError.c_str());

    if (ImGui::Button("< Back"))
        m_IsCreateError = false;
}
