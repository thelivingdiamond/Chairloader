#pragma once

namespace Main
{

//! Keeps all known file formats and file viewers.
class FileFormats
{
public:
    //! @returns the singleton instance.
    static FileFormats& Get();

    FileFormats();
    ~FileFormats();

    //! @param  fileName    Name of the file with extension (if any).
    //! @returns the icon for a file.
    const char* GetFileIcon(std::string_view fileName);

    //! Opens the specified file in HEX-viewer.
    void OpenHexViewer(const std::string& path);

private:
    using IconHandler = std::function<const char* (std::string_view fileName)>;

    const char* m_DefaultFileIcon = nullptr;
    std::vector<IconHandler> m_IconHandlers;
    std::map<std::string, const char*, std::less<>> m_ExtToIcon;
};

} // namespace Main
