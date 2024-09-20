#pragma once
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/Export.h>
#include <Manager/LogEntry.h>

class MergingPolicy3;
class FileMergingPolicy3;

class CHAIRMERGER_EXPORT LegacyModConverter
{
public:
    struct LogEntry
    {
        severityLevel level;
        std::string message;
        std::vector<std::string> stackTrace;
    };

    //! @returns List of log entries.
    const std::list<LogEntry>& GetLogs() const { return m_Logs; }

    //! Converts a legacy mod node.
    void ConvertNode(
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

private:
    std::list<LogEntry> m_Logs;

    void AddLog(severityLevel level, std::string_view message, const XmlErrorStack& errorStack);

    void ConvertAttributes(
        const pugi::xml_node& preyNode,
        const pugi::xml_node& legacyModNode,
        pugi::xml_node outNode,
        const MergingPolicy3& policy,
        const XmlErrorStack& errorStack);
};
