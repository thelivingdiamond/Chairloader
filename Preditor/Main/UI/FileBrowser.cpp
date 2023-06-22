#include <boost/core/span.hpp>
#include <Prey/CrySystem/File/ICryPak.h>
#include <Manager/IconsMaterialDesign.h>
#include "FileBrowser.h"

namespace
{

const ImVec4 COLOR_FILE = ImColor(128, 128, 128);
const ImVec4 COLOR_DIR = ImColor(255, 255, 255);

void AppendPathList(std::string& s, boost::span<std::string> list)
{
    for (const std::string& i : list)
    {
        CRY_ASSERT_MESSAGE(i.find_first_of("/\\") == std::string::npos, "Path components may not contain slashes");
        s += i;
        s += '/';
    }
}

std::string PathListToString(boost::span<std::string> list)
{
    std::string s;
    AppendPathList(s, list);
    return s;
}

} // namespace

Main::FileBrowser::FileBrowser()
{
    SetTitle("File Browser");
    SetPersistentID("FileBrowser");

    RefreshCurDir();
}

Main::FileBrowser::~FileBrowser()
{

}

std::string Main::FileBrowser::GetCurrentFullPath()
{
    std::string s;
    AppendPathList(s, m_RootPath);
    AppendPathList(s, m_Path);
    return s;
}

void Main::FileBrowser::SetCurrentPath(const std::string& pathStr)
{
    // Path will be split by slashes automatically
    fs::path path = fs::u8path(pathStr);
    path = path.lexically_normal();
    m_Path.clear();

    if (path != ".")
    {
        for (const fs::path& i : path)
        {
            if (!i.empty())
                m_Path.push_back(i.u8string());
        }
    }

    RefreshCurDir();
}

void Main::FileBrowser::RefreshCurDir()
{
    m_PendingRefresh = true;
}

void Main::FileBrowser::ShowContents()
{
    if (m_PendingRefresh)
        RefreshCurDirInternal();

    ShowTopRow();

    ImGuiTableFlags flags = ImGuiTableFlags_SizingFixedFit |
        ImGuiTableFlags_Resizable |
        ImGuiTableFlags_BordersOuter |
        ImGuiTableFlags_BordersV |
        ImGuiTableFlags_ContextMenuInBody;
    
    if (ImGui::BeginTable("contentTable", 2, flags))
    {
        ImGui::TableSetupColumn("Tree", ImGuiTableColumnFlags_WidthFixed, TREE_WIDTH * ImGui::GetFontSize());
        ImGui::TableSetupColumn("List", ImGuiTableColumnFlags_WidthStretch);

        ImGui::TableNextRow();

        ImGui::TableSetColumnIndex(0);
        ImGui::BeginChild("Tree");
        ShowDirTree();
        ImGui::EndChild();

        ImGui::TableSetColumnIndex(1);
        ImGui::BeginChild("List");
        ShowFileList();
        ImGui::EndChild();

        ImGui::EndTable();
    }
}

void Main::FileBrowser::RefreshCurDirInternal()
{
    std::string dirPath = GetCurrentFullPath();
    m_CurFiles.clear();

    // Add "go up" if not root
    if (!m_Path.empty())
    {
        ListItem& fileItem = m_CurFiles.emplace_back();
        fileItem.fileName = "..";
        fileItem.fullPath = dirPath + fileItem.fileName;
        fileItem.isDirectory = true;
        fileItem.textColor = COLOR_DIR;
        fileItem.listName = ICON_MD_ARROW_UPWARD + fileItem.fileName;
    }

    intptr_t hFile = 0;
    _finddata_t c_file;

    if ((hFile = gEnv->pCryPak->FindFirst((dirPath + "*.*").c_str(), &c_file)) != -1L)
    {
        do
        {
            // Skip current directory
            if (!strcmp(c_file.name, "."))
                continue;

            // Skip "go up"
            if (!strcmp(c_file.name, ".."))
                continue;

            ListItem& fileItem = m_CurFiles.emplace_back();
            fileItem.fileName = c_file.name;
            fileItem.fullPath = dirPath + c_file.name;
            fileItem.isDirectory = c_file.attrib & _A_SUBDIR;
            fileItem.textColor = fileItem.isDirectory ? COLOR_DIR : COLOR_FILE;

            std::string icon = ICON_MD_QUESTION_MARK;

            if (fileItem.isDirectory)
            {
                if (!strcmp(c_file.name, ".."))
                    icon = ICON_MD_ARROW_UPWARD;
                else
                    icon = ICON_MD_FOLDER;
            }
            else
            {
                icon = ICON_MD_DESCRIPTION;
            }

            fileItem.listName = icon + c_file.name;
        } while (gEnv->pCryPak->FindNext(hFile, &c_file) == 0);
    }

    // Sort files
    auto fnSortPred = [](ListItem& lhs, const ListItem& rhs)
    {
        // Directories go first
        if (lhs.isDirectory && !rhs.isDirectory)
            return true;
        if (!lhs.isDirectory && rhs.isDirectory)
            return false;

        // Alpha-numerically
        return lhs.fileName < rhs.fileName;
    };

    std::sort(m_CurFiles.begin(), m_CurFiles.end(), fnSortPred);

    m_PendingRefresh = false;
}

void Main::FileBrowser::OpenFile(ListItem& file)
{
    if (file.isDirectory)
    {
        SetCurrentPath(PathListToString(m_Path) + file.fileName);
    }
    else
    {
        // TODO 2023-06-22
    }
}

void Main::FileBrowser::ShowTopRow()
{
    if (ImGui::Button("Refresh"))
        RefreshCurDir();
}

void Main::FileBrowser::ShowDirTree()
{
}

void Main::FileBrowser::ShowFileList()
{
    // Path
    if (m_IsEditingPath)
    {
        if (ImGui::Button(ICON_MD_CANCEL))
        {
            m_IsEditingPath = false;
        }

        ImGui::SameLine();

        int flags = ImGuiInputTextFlags_AutoSelectAll
            | ImGuiInputTextFlags_EnterReturnsTrue;
        bool isPathChanged = ImGui::InputText("##Path", &m_PathEditBuf, flags);
        isPathChanged |= ImGui::IsItemDeactivated();

        if (isPathChanged)
        {
            SetCurrentPath(m_PathEditBuf);
            m_PathEditBuf.clear();
            m_IsEditingPath = false;
        }
    }
    else
    {
        if (ImGui::Button(ICON_MD_EDIT))
        {
            m_IsEditingPath = true;
            m_PathEditBuf = PathListToString(m_Path);
        }

        ImGui::SameLine();

        if (ImGui::Button("(root)"))
            SetCurrentPath("");
        ImGui::SameLine();

        for (int i = 0; i < m_Path.size(); i++)
        {
            ImGui::Text(">");
            ImGui::SameLine();
            ImGui::PushID(i);

            if (ImGui::Button(m_Path[i].c_str()))
            {
                auto path = boost::span(m_Path).first(i + 1);
                SetCurrentPath(PathListToString(path));
            }

            ImGui::PopID();
            ImGui::SameLine();
        }

        ImGui::NewLine();
    }

    // List
    for (ListItem& i : m_CurFiles)
    {
        ImGui::PushStyleColor(ImGuiCol_Text, i.textColor);
        
        if (ImGui::Selectable(i.listName.c_str()))
            OpenFile(i);
        
        ImGui::PopStyleColor();
    }
}
