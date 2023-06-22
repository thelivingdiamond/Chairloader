#pragma once
#include <WindowManager/ManagedWindow.h>

namespace Main
{

class FileBrowser : public ManagedWindow
{
public:
    FileBrowser();
    ~FileBrowser();

    //! @returns full path to the current directory. Will have a trailing slash unless empty.
    std::string GetCurrentFullPath();

    //! Sets the current path relative to the root.
    void SetCurrentPath(const std::string &pathStr);

    //! Refreshes current directory contents next update.
    void RefreshCurDir();

protected:
    // ManagedWindow
    virtual void ShowContents() override;

private:
    static constexpr float TREE_WIDTH = 20;

    enum class FileType
    {
        None,
        GoUp,
        Directory,
        File,
    };

    struct ListItem
    {
        //! Path to the file.
        std::string fullPath;

        //! File name
        std::string fileName;

        //! File name with icon.
        std::string listName;

        //! File type
        FileType type = FileType::None;

        //! Text color.
        ImVec4 textColor;
    };

    struct TreeItem
    {
        //! Parent item.
        TreeItem* parent = nullptr;

        //! Path to the directory.
        std::string fullPath;

        //! Name of the directory.
        std::string fileName;

        //! Map of lower-case names to child items.
        std::map<std::string, TreeItem> children;

        //! Whether the contents were loaded.
        bool isLoaded = false;

        //! Index of the path that contains this item.
        unsigned lastPathIdx = 0;

        //! Index when the item was last refreshed.
        unsigned refreshIdx = 0;

        //! Traverses up to the tree root and gets the path.
        std::string GetLocalPath()
        {
            std::string parentPath = parent ? (parent->GetLocalPath() + "/") : "";
            return parentPath + fileName;
        }
    };

    //! Path to the root directory.
    std::vector<std::string> m_RootPath;

    //! Path to the current directory, relative to root.
    std::vector<std::string> m_Path;

    //! Files in the current directory.
    std::vector<ListItem> m_CurFiles;

    //! Root tree node.
    TreeItem m_TreeRoot;

    //! Incremented every time path is changed.
    unsigned m_CurPathIdx = 1;

    //! Incremented on every tree item that is updated.
    //! Used to remove old items.
    unsigned m_NextTreeRefreshIdx = 1;

    //! A refresh is currently pending.
    bool m_PendingRefresh = false;

    //! If true, the tree items for current path will be forced open.
    bool m_PendingTreeOpen = false;

    //! Whether currently editing the path in text format
    bool m_IsEditingPath = false;
    std::string m_PathEditBuf;

    //! Refreshes current directory contents.
    void RefreshCurDirInternal();

    //! Refreshes the contents of the tree item.
    //! @param  refreshImmediateChildren    Children of the item will be refreshed non-recursively.
    void RefreshTreeItem(TreeItem& item, bool refreshImmediateChildren = true);

    //! Opens the specified file/directory.
    void OpenFile(ListItem& file);

    void ShowTopRow();
    void ShowDirTree();
    void ShowTreeItem(TreeItem& item);
    void ShowFileList();
};

} // namespace Main
