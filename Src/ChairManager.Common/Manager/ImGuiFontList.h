#pragma once

class ImGuiFontList
{
public:
    struct ILogger
    {
        virtual ~ILogger() {}
        virtual void Log(std::string_view str) = 0;
        virtual void LogWarning(std::string_view str) = 0;
        virtual void LogError(std::string_view str) = 0;
    };

    //! Loads an XML file.
    void LoadFile(const fs::path& path, const fs::path& rootPath, ILogger* pLog, float dpiScale = 1.0f);

    //! Loads the <FontList> XML node.
    void LoadXml(pugi::xml_node node, const fs::path& rootPath, ILogger* pLog, float dpiScale = 1.0f);

    //! @returns font or nullptr.
    ImFont* FindFont(std::string_view name);

private:
    //! Maps font name to ImGui font.
    std::map<std::string, ImFont*, std::less<>> m_FontMap;

    //! Buffer for font ranges (they must live for as long as fonts do).
    std::vector<std::vector<ImWchar>> m_RangeBuf;
};
