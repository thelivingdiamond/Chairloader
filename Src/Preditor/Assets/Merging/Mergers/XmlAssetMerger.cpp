#include <ChairMerger/MergingPolicy.h>
#include <ChairMerger/XMLMerger2.h>
#include <ChairMerger/WildcardResolver.h>
#include "Merging/Mergers/XmlAssetMerger.h"
#include "Merging/Sources/AssetMergeSource.h"
#include "Merging/AssetMergeSystem.h"

Assets::XmlAssetMerger::XmlAssetMerger(AssetMergeSystem* pSys)
{
    m_pSys = pSys;
}

Assets::XmlAssetMerger::~XmlAssetMerger()
{
}

void Assets::XmlAssetMerger::DoMerge(const std::vector<InputFile>& inputFiles)
{
    MergingPolicy policy = m_pSys->FindMergingPolicy(GetRelPath());

    if (policy.policy == MergingPolicy::identification_policy::match_spreadsheet)
    {
        // Excel spreadsheets are parsed in full
        m_ParseFlags = pugi::parse_full;
    }

    if (policy.policy == MergingPolicy::identification_policy::overwrite ||
        policy.policy == MergingPolicy::identification_policy::unknown)
    {
        // Keep the last file, ignore the rest
        pugi::xml_document lastXml = ReadFile(*inputFiles.rbegin());
        SaveXml(lastXml);
        return;
    }

    pugi::xml_document baseDoc; //!< The XML into which changes are being merged into
    pugi::xml_document originalDoc; //!< The original XML from Prey

    fs::path originalDocPath = gPreditor->pConfig->GetPreyFiles() / fs::u8path(GetRelPath());
    size_t inputFileIdx = 0;

    if (fs::exists(originalDocPath))
    {
        // Prey file is the base
        originalDoc = ReadFile(originalDocPath);
        baseDoc = ReadFile(originalDocPath);
    }
    else
    {
        // First file is the base
        baseDoc = ReadFile(*inputFiles.rbegin());

        // Since it's already "merged", skip it
        inputFileIdx = 1;
    }

    // Merge mod files
    for (; inputFileIdx < inputFiles.size(); inputFileIdx++)
    {
        const InputFile& inputFile = inputFiles[inputFileIdx];
        pugi::xml_document modDoc = ReadFile(inputFile);
        XMLMerger2::MergeXMLDocument(baseDoc, modDoc, originalDoc, policy);
    }

    SaveXml(baseDoc);
}

pugi::xml_document Assets::XmlAssetMerger::ReadFile(const fs::path& file)
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(file.c_str(), m_ParseFlags);

    if (!result)
    {
        throw std::runtime_error(fmt::format(
            "Failed to parse XML file.\n"
            "Offset: {}; {}\n"
            "{}",
            result.offset, result.description(), file.u8string()));
    }

    return doc;
}

pugi::xml_document Assets::XmlAssetMerger::ReadFile(const InputFile& file)
{
    pugi::xml_document doc = ReadFile(file.fullPath);
    ResolveWildcards(doc, file.pSource);
    return doc;
}

void Assets::XmlAssetMerger::ResolveWildcards(pugi::xml_document& doc, AssetMergeSource* pSource)
{
    WildcardResolver* wr = pSource->GetWildcardResolver();
    if (wr)
        wr->ResolveDocumentWildcards(doc);
}

void Assets::XmlAssetMerger::SaveXml(const pugi::xml_document& doc)
{
    constexpr char INDENT[] = "    ";
    constexpr unsigned FLAGS = pugi::format_indent | pugi::format_indent_attributes;

    if (!doc.save_file(GetOutputFilePath().c_str(), INDENT, FLAGS))
    {
        throw std::runtime_error(fmt::format("doc.save_file failed for {}", GetRelPath()));
    }
}
