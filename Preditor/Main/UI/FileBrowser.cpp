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

std::string StringToLower(const std::string& s)
{
    std::string l = s;

    for (char& c : l)
    {
        if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
    }

    return l;
}

} // namespace

Main::FileBrowser::FileBrowser()
{
    SetTitle("File Browser");
    SetRootPath("");
    RefreshCurDir();

    // Disable scroll. Child windows will handle that.
    SetFlags(ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
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

void Main::FileBrowser::SetRootPath(const std::string& pathStr)
{
    // Path will be split by slashes automatically
    fs::path path = fs::u8path(pathStr);
    path = path.lexically_normal();
    m_RootPath.clear();

    for (const fs::path& i : path)
    {
        // C:\Test -> 'C:', '\', 'Test'
        // Skip the slash
        if (!i.empty() && i != "\\")
            m_RootPath.push_back(i.u8string());
    }

    m_TreeRoot.fullPath = PathListToString(m_RootPath);
    RefreshCurDir();
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
            if (!i.empty() && i != ".." && i != "\\")
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
        fileItem.type = FileType::GoUp;
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
            fileItem.type = (c_file.attrib & _A_SUBDIR) ? FileType::Directory : FileType::File;

            std::string icon = ICON_MD_QUESTION_MARK;

            if (fileItem.type == FileType::Directory)
            {
                fileItem.textColor = COLOR_DIR;
                icon = ICON_MD_FOLDER;
            }
            else
            {
                fileItem.textColor = COLOR_FILE;
                icon = ICON_MD_DESCRIPTION;
            }

            fileItem.listName = icon + c_file.name;
        } while (gEnv->pCryPak->FindNext(hFile, &c_file) == 0);
    }

    // Sort files
    auto fnSortPred = [](ListItem& lhs, const ListItem& rhs)
    {
        // By type (directories go first)
        if (lhs.type < rhs.type)
            return true;
        if (lhs.type > rhs.type)
            return false;

        // Alpha-numerically
        return lhs.fileName < rhs.fileName;
    };

    std::sort(m_CurFiles.begin(), m_CurFiles.end(), fnSortPred);

    // Refresh the tree
    {
        TreeItem* curTreeItem = &m_TreeRoot;
        bool isFound = true;
        m_CurPathIdx++;

        // Iterate over path to find its tree item
        for (int i = 0; i < m_Path.size(); i++)
        {
            std::string lowerPathItem = StringToLower(m_Path[i]);
            auto it = curTreeItem->children.find(lowerPathItem);

            if (it == curTreeItem->children.end())
            {
                // Refresh and retry
                RefreshTreeItem(*curTreeItem);
                it = curTreeItem->children.find(lowerPathItem);
            }

            if (it == curTreeItem->children.end())
            {
                // Dir not found
                isFound = false;
                auto pathSpan = boost::span(m_Path);
                CryError("[FileBrowser] Directory not found: {}", PathListToString(pathSpan.first(i + 1)));
                break;
            }

            curTreeItem = &it->second;
            curTreeItem->lastPathIdx = m_CurPathIdx;
        }

        if (isFound)
            RefreshTreeItem(*curTreeItem);
    }

    m_PendingRefresh = false;
    m_PendingTreeOpen = true;
}

void Main::FileBrowser::RefreshTreeItem(TreeItem& item, bool refreshImmediateChildren)
{
    intptr_t hFile = 0;
    _finddata_t c_file;
    unsigned refreshIdx = m_NextTreeRefreshIdx++;

    if ((hFile = gEnv->pCryPak->FindFirst((item.fullPath + "*.*").c_str(), &c_file)) != -1L)
    {
        do
        {
            // Skip files
            if (!(c_file.attrib & _A_SUBDIR))
                continue;

            // Skip current directory
            if (!strcmp(c_file.name, "."))
                continue;

            // Skip "go up"
            if (!strcmp(c_file.name, ".."))
                continue;

            std::string lowerName = StringToLower(c_file.name);

            TreeItem& treeItem = item.children[lowerName];
            treeItem.parent = &item != &m_TreeRoot ? &item : nullptr;
            treeItem.fileName = c_file.name;
            treeItem.fullPath = item.fullPath + treeItem.fileName + "/";
            treeItem.refreshIdx = refreshIdx;

            if (refreshImmediateChildren)
                RefreshTreeItem(treeItem, false);
        }
        while (gEnv->pCryPak->FindNext(hFile, &c_file) == 0);
    }

    // Remove old items
    for (auto it = item.children.begin(); it != item.children.end();)
    {
        if (it->second.refreshIdx != refreshIdx)
        {
            it = item.children.erase(it);
        }
        else
        {
            ++it;
        }
    }

    item.isLoaded = true;
}

void Main::FileBrowser::OpenFile(ListItem& file)
{
    if (file.type == FileType::Directory || file.type == FileType::GoUp)
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
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, { 0.0f, 0.0f });
    ShowTreeItem(m_TreeRoot);
    ImGui::PopStyleVar();
    m_PendingTreeOpen = false;
}

void Main::FileBrowser::ShowTreeItem(TreeItem& item)
{
    for (auto& i : item.children)
    {
        int flags = ImGuiTreeNodeFlags_SpanAvailWidth |
            ImGuiTreeNodeFlags_OpenOnDoubleClick |
            ImGuiTreeNodeFlags_OpenOnArrow;

        if (i.second.isLoaded && i.second.children.empty())
            flags |= ImGuiTreeNodeFlags_Leaf;

        if (i.second.lastPathIdx == m_CurPathIdx)
        {
            flags |= ImGuiTreeNodeFlags_Selected;

            if (m_PendingTreeOpen)
                ImGui::SetNextItemOpen(true);
        }

        bool isItemOpen = ImGui::TreeNodeEx(i.second.fileName.c_str(), flags);

        if (ImGui::IsItemClicked() && !ImGui::IsItemToggledOpen())
        {
            std::string path = i.second.GetLocalPath();
            SetCurrentPath(path);
        }

        if (isItemOpen)
        {
            if (ImGui::IsItemToggledOpen())
                RefreshTreeItem(i.second);

            ShowTreeItem(i.second);
            ImGui::TreePop();
        }
    }
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
