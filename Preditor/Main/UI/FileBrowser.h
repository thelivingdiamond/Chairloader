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

    struct ListItem
    {
        //! Path to the file.
        std::string fullPath;

        //! File name
        std::string fileName;

        //! File name with icon.
        std::string listName;

        //! Is this a directory.
        bool isDirectory = false;

        //! Text color.
        ImVec4 textColor;
    };

    //! Path to the root directory.
    std::vector<std::string> m_RootPath;

    //! Path to the current directory, relative to root.
    std::vector<std::string> m_Path;

    //! Files in the current directory.
    std::vector<ListItem> m_CurFiles;

    //! A refresh is currently pending.
    bool m_PendingRefresh = false;

    //! Whether currently editing the path in text format
    bool m_IsEditingPath = false;
    std::string m_PathEditBuf;

    //! Refreshes current directory contents.
    void RefreshCurDirInternal();

    //! Opens the specified file/directory.
    void OpenFile(ListItem& file);

    void ShowTopRow();
    void ShowDirTree();
    void ShowFileList();
};

} // namespace Main
