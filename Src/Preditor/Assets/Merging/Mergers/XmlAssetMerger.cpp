#include <ChairMerger/MergingPolicy3.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/XmlMerger3.h>
#include <ChairMerger/XmlValidator.h>
#include <ChairMerger/XmlFinalizer3.h>
#include <ChairMerger/WildcardResolver.h>
#include "Merging/Mergers/XmlAssetMerger.h"
#include "Merging/Sources/AssetMergeSource.h"
#include "Merging/AssetMergeSystem.h"

constexpr char SERIALIZE_XML[] = "serialize.xml";

static void PrintValidationResult(std::string_view relPath, std::string_view subtext, const XmlValidator::Result& result)
{
    constexpr char LINES[] = "============================================================";
    CryError(LINES);
    CryError("= XML VALIDATION ERROR: {}", subtext);
    CryError("= {}", relPath);
    CryError(LINES);

    for (auto& error : result.errors)
    {
        // Path
        std::string path;
        for (auto it = error.path.crbegin(); it != error.path.crend(); ++it)
        {
            path += "> ";
            path += *it;
            path += " ";
        }

        // Attribute
        if (!error.attributeName.empty())
            path += fmt::format("| (attr = {})", error.attributeName);

        CryLog("{}", path);

        // Message
        CryLog("    {}", error.message);
    }
}

Assets::XmlAssetMerger::XmlAssetMerger(AssetMergeSystem* pSys)
    : AssetMerger(pSys)
{
}

Assets::XmlAssetMerger::~XmlAssetMerger()
{
}

void Assets::XmlAssetMerger::DoMerge(const std::vector<InputFile>& inputFiles)
{
    const FileMergingPolicy3* pPolicy = m_pSys->GetMergingLibrary().FindPolicyForFile(GetRelPath());
    CRY_ASSERT_MESSAGE(pPolicy, "XmlAssetMerger may only be used with registered files");

    fs::path originalDocPath = gPreditor->pConfig->GetPreyFiles() / fs::u8path(GetRelPath());

    if (pPolicy->GetMethod() == FileMergingPolicy3::EMethod::Replace)
    {
        // Keep the last file, ignore the rest
        pugi::xml_document lastXml;

        if (!inputFiles.empty())
            lastXml = ReadFile(*inputFiles.rbegin());
        else
            lastXml = ReadFile(originalDocPath);

        SaveFinalXml(lastXml, *pPolicy);
        return;
    }

    if (pPolicy->GetMethod() == FileMergingPolicy3::EMethod::ReadOnly)
    {
        // Don't merge the file
        CryWarning("[XmlAssetMerger] Not merging read-only file {}", GetRelPath());
        return;
    }

    if (pPolicy->GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
    {
        // Excel spreadsheets are parsed in full
        m_ParseFlags = XmlMerger3::EXCEL_PARSE_OPTIONS;
    }

    pugi::xml_document baseDoc; //!< The XML into which changes are being merged into

    size_t inputFileIdx = 0;

    if (fs::exists(originalDocPath))
    {
        // Prey file is the base
        baseDoc = ReadFile(originalDocPath);
    }
    else
    {
        CRY_ASSERT(!inputFiles.empty());

        // First file is the base
        baseDoc = ReadFile(*inputFiles.begin());

        // Since it's already "merged", skip it
        inputFileIdx = 1;
    }

    // Merge mod files
    for (; inputFileIdx < inputFiles.size(); inputFileIdx++)
    {
        const InputFile& inputFile = inputFiles[inputFileIdx];
        pugi::xml_document modDoc = ReadFile(inputFile);

        XmlMergerContext context;
        context.modName = inputFile.pSource->GetSourceName();
        context.pTypeLib = &m_pSys->GetTypeLibrary();

        if (pPolicy->GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
        {
            XmlMerger3::MergeExcelDocument(context, baseDoc, modDoc, *pPolicy);
        }
        else
        {
            // Validate mod node
            {
                XmlValidator::Context valCtx;
                valCtx.mode = XmlValidator::EMode::Mod;
                valCtx.pTypeLib = &m_pSys->GetTypeLibrary();

                XmlValidator::Result result = XmlValidator::ValidateDocument(valCtx, modDoc, *pPolicy);

                if (!result)
                {
                    PrintValidationResult(GetRelPath(), fmt::format("in mod {}", inputFile.pSource->GetSourceName()), result);
                    throw std::runtime_error("Mod file validation error");
                }
            }

            XmlMerger3::MergeDocument(context, baseDoc, modDoc, *pPolicy);

            // Validate base after merging
            {
                XmlValidator::Context valCtx;
                valCtx.mode = XmlValidator::EMode::MergingBase;
                valCtx.pTypeLib = &m_pSys->GetTypeLibrary();

                XmlValidator::Result result = XmlValidator::ValidateDocument(valCtx, baseDoc, *pPolicy);

                if (!result)
                {
                    PrintValidationResult(GetRelPath(), fmt::format("after merging mod {}", inputFile.pSource->GetSourceName()), result);
                    throw std::runtime_error("Base file validation error after merging");
                }
            }
        }
    }

    SaveFinalXml(baseDoc, *pPolicy);
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

void Assets::XmlAssetMerger::SaveFinalXml(pugi::xml_document& doc, const FileMergingPolicy3& policy)
{
    constexpr char INDENT[] = "    ";
    constexpr unsigned FLAGS = pugi::format_indent | pugi::format_indent_attributes;

    if (policy.GetMethod() != FileMergingPolicy3::EMethod::Excel2003)
    {
        // Finalize
        XmlFinalizerContext context;
        XmlFinalizer3::FinalizeDocument(context, doc, policy);

        if (!context.serializeEntityIds.empty())
        {
            // Generate serialize.xml
            // Safe to do this because it's read-only in the policy.
            fs::path serPath = GetOutputFilePath().parent_path() / SERIALIZE_XML;
            pugi::xml_document serDoc = XmlFinalizer3::GenerateEntitySerialize(context.serializeEntityIds);

            if (!serDoc.save_file(serPath.c_str(), INDENT, FLAGS))
            {
                throw std::runtime_error(fmt::format("doc.save_file failed for {}", serPath.u8string()));
            }
        }

        // Validate after finalization
        {
            XmlValidator::Context valCtx;
            valCtx.mode = XmlValidator::EMode::Prey;
            valCtx.pTypeLib = &m_pSys->GetTypeLibrary();

            XmlValidator::Result result = XmlValidator::ValidateDocument(valCtx, doc, policy);

            if (!result)
            {
                PrintValidationResult(GetRelPath(), "in final file", result);
                throw std::runtime_error("Final validation error");
            }
        }
    }

    if (!doc.save_file(GetOutputFilePath().c_str(), INDENT, FLAGS))
    {
        throw std::runtime_error(fmt::format("doc.save_file failed for {}", GetRelPath()));
    }
}
