#pragma once
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/Export.h>
#include <Manager/LogEntry.h>

class MergingPolicy3;
class FileMergingPolicy3;

class CHAIRMERGER_EXPORT LegacyModConverter
{
public:
    enum class EPakType
    {
        None,
        GameData, //!< Goes into GameSDK or Precache.
        Level, //! Goes into a level folder.
        Localization, //!< Goes into a localization folder
    };

    struct LogEntry
    {
        severityLevel level;
        std::string message;
        std::vector<std::string> stackTrace;
    };

    struct ModInfo
    {
        //! Type of the mod pak.
        EPakType pakType = EPakType::None;

        //! Relative path in the output (converted) folder.
        //! Will include level name or localization folder.
        fs::path outputRelativePath;
    };

    //! Analizes a mod folder.
    static ModInfo AnalyzeFolder(const std::string& pakName, const fs::path& modDir);

    //! @returns List of log entries.
    const std::list<LogEntry>& GetLogs() const { return m_Logs; }

    //! Patches a document to fix modder's mistakes (and removes legacy stuff no longer in the game).
    void PrePatchDocument(
        const fs::path& relPath,
        pugi::xml_document& legacyModDoc,
        const FileMergingPolicy3& policy);

    //! Patches a converted document.
    void PostPatchDocument(
        const fs::path& relPath,
        pugi::xml_document& modDoc,
        const FileMergingPolicy3& policy);

    //! Converts a legacy mod node.
    bool ConvertNode(
        const pugi::xml_node& preyNode,
        const pugi::xml_node& legacyModNode,
        pugi::xml_node outNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

    //! Converts a legacy mod document.
    //! @returns Whether the output document contains any changes.
    bool ConvertDocument(
        const pugi::xml_document& preyDoc,
        const pugi::xml_document& legacyModDoc,
        pugi::xml_document& outDoc,
        const FileMergingPolicy3& policy);

    //! Converts an Excel document.
    //! @returns Whether the output document contains any changes.
    bool ConvertExcelDocument(
        const pugi::xml_document& preyDoc,
        const pugi::xml_document& legacyModDoc,
        pugi::xml_document& outDoc,
        const FileMergingPolicy3& policy);

private:
    std::list<LogEntry> m_Logs;

    void AddLog(severityLevel level, std::string_view message, const XmlErrorStack& errorStack);

    bool ConvertAttributes(
        const pugi::xml_node& preyNode,
        const pugi::xml_node& legacyModNode,
        pugi::xml_node outNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

    bool ConvertText(
        const pugi::xml_node& preyNode,
        const pugi::xml_node& legacyModNode,
        pugi::xml_node outNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

    bool ConvertDict(
        const pugi::xml_node& preyNode,
        const pugi::xml_node& legacyModNode,
        pugi::xml_node outNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

    //! Looks for items with duplicate keys and removes them.
    void RemoveDuplicateKeys(
        pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);

    //! Applies fixes to new nodes.
    void FixUpNewNode(
        pugi::xml_node& node,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);
};
