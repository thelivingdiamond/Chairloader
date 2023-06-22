#include <WindowManager/WindowManager.h>
#include <Manager/IconsMaterialDesign.h>
#include "UI/FileViewers/FileFormats.h"
#include "UI/FileViewers/HexViewer.h"

namespace
{

Main::FileFormats g_FileFormats;

const char* DdsIconHandler(std::string_view fileName)
{
    if (fileName.size() >= 6 &&
        fileName[fileName.size() - 1] >= '0' &&
        fileName[fileName.size() - 1] <= '9')
    {
        std::string_view suff = ".dds.";
        if (fileName.substr(fileName.size() - 1 - suff.size(), suff.size()) == suff)
        {
            return ICON_MD_IMAGE;
        }
    }

    return nullptr;
}

} // namespace

Main::FileFormats& Main::FileFormats::Get()
{
    return g_FileFormats;
}

Main::FileFormats::FileFormats()
{
    m_DefaultFileIcon = ICON_MD_DESCRIPTION;

    // Archives
    m_ExtToIcon["zip"] = ICON_MD_FOLDER_ZIP;
    m_ExtToIcon["pak"] = ICON_MD_FOLDER_ZIP;

    // Code
    m_ExtToIcon["xml"] = ICON_MD_CODE;
    m_ExtToIcon["lua"] = ICON_MD_CODE;
    m_ExtToIcon["mtl"] = ICON_MD_CODE; // Material XML

    // Flash/Scaleform
    m_ExtToIcon["swf"] = ICON_MD_GRID_VIEW;
    m_ExtToIcon["gfx"] = ICON_MD_GRID_VIEW;

    // Images
    m_ExtToIcon["dds"] = ICON_MD_IMAGE;
    m_ExtToIcon["png"] = ICON_MD_IMAGE;
    m_ExtToIcon["tif"] = ICON_MD_IMAGE;

    // Models
    m_ExtToIcon["cgf"] = ICON_MD_VIEW_IN_AR;

    m_IconHandlers.push_back(&DdsIconHandler);
}

Main::FileFormats::~FileFormats()
{
}

const char* Main::FileFormats::GetFileIcon(std::string_view fileName)
{
    // Find an extension
    size_t dot = fileName.rfind('.');

    if (dot != std::string::npos)
    {
        std::string_view ext = fileName.substr(dot + 1);
        auto it = m_ExtToIcon.find(ext);

        if (it != m_ExtToIcon.end())
            return it->second;
    }

    // Check handlers
    for (auto& i : m_IconHandlers)
    {
        const char* result = i(fileName);
        if (result)
            return result;
    }

    return m_DefaultFileIcon;
}

void Main::FileFormats::OpenHexViewer(const std::string& path)
{
    try
    {
        WindowManager::Get().Create<HexViewer>(path);
    }
    catch (const std::exception& e)
    {
        CryError("Failed to open {}:\n{}", path, e.what());
    }
}
