#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/program_options.hpp>
#include <taskflow/algorithm/for_each.hpp>
#include <taskflow/taskflow.hpp>
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/LegacyModConverter.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>
#include <ChairMerger/XmlMerger3.h>
#include <SHA256/SHA256.h>

namespace po = boost::program_options;

struct ConvertionStats
{
    int total = 0;
    int failed = 0;
    int copied = 0;
    int converted = 0;
    int unchanged = 0;
};

// TODO 2024-05-04: Remove this
struct ChairloaderGlobalEnvironment* gCL;

static constexpr char LINES[] = "----------------------------------------------------------------------";

SHA256::Digest HashFile(const fs::path& path)
{
    std::ifstream file;
    file.exceptions(std::ios::failbit | std::ios::badbit);
    file.open(path, std::ios::binary);
    file.seekg(0, std::ios::end);
    uint64_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    std::vector<char> buf(16384);
    SHA256 hash;

    for (uint64_t i = 0; i < size; i += (uint64_t)buf.size())
    {
        size_t read = (size_t)std::min((uint64_t)buf.size(), size - i);
        file.read(buf.data(), read);
        hash.update((uint8_t*)buf.data(), read);
    }

    return hash.digest();
}

int main(int argc, char** argv)
{
    po::options_description desc("Validates that XML files match the merging policy");
    po::variables_map vm;

    try
    {
        desc.add_options()
            ("help", "produce help message")
            ("type-lib", po::value<std::string>()->required(), "path to the type library")
            ("merging-lib", po::value<std::string>()->required(), "path to the merging library")
            ("prey-files-dir", po::value<std::string>()->required(), "path to Prey files directory")
            ("legacy-mod-dir", po::value<std::string>()->required(), "path to the legacy mod directory")
            ("out-dir", po::value<std::string>()->required(), "path to the output directory");

        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            return 1;
        }

        po::notify(vm);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        std::cout << desc << "\n";
        return 1;
    }

    try
    {
        // Load type library
        fs::path typeLibPath = fs::u8path(vm["type-lib"].as<std::string>());
        XmlTypeLibrary typeLib;
        typeLib.LoadTypesFromFile(typeLibPath);

        // Load merging library
        fs::path mergingLibraryPath = fs::u8path(vm["merging-lib"].as<std::string>());
        fmt::println("Merging library: {}", mergingLibraryPath.u8string());
        MergingLibrary3 mergingLibrary(&typeLib);
        mergingLibrary.LoadFromPath(mergingLibraryPath);

        // Convert files
        fs::path preyFilesDir = fs::u8path(vm["prey-files-dir"].as<std::string>());
        fs::path legacyModDir = fs::u8path(vm["legacy-mod-dir"].as<std::string>());
        fs::path outDir = fs::u8path(vm["out-dir"].as<std::string>());
        ConvertionStats stats;

        // Analyze the folder
        LegacyModConverter::ModInfo legacyModInfo = LegacyModConverter::AnalyzeFolder(legacyModDir.filename().u8string(), legacyModDir);
        fmt::println("Output relative path: {}", legacyModInfo.outputRelativePath.generic_u8string());
        fmt::println("{}", LINES);

        for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(legacyModDir))
        {
            if (dirEnt.is_directory())
                continue;

            stats.total++;
            fs::path legacyFilePath = dirEnt.path();
            fs::path relPath = legacyModInfo.outputRelativePath / legacyFilePath.lexically_relative(legacyModDir);

            try
            {
                fs::path preyFilePath = preyFilesDir / relPath;
                fs::path outFilePath = outDir / relPath;

                fs::create_directories(outFilePath.parent_path());

                bool preyFileExists = fs::exists(preyFilePath);
                const FileMergingPolicy3* pPolicy = mergingLibrary.FindPolicyForFile(relPath);

                if (!preyFileExists || !pPolicy ||
                    (pPolicy->GetMethod() != FileMergingPolicy3::EMethod::Merge && pPolicy->GetMethod() != FileMergingPolicy3::EMethod::Excel2003))
                {
                    // No policy for this file. Copy it instead.
                    // Can happen if non-XML file or new file.

                    if (preyFileExists)
                    {
                        // Hash the files
                        SHA256::Digest preyHash = HashFile(preyFilePath);
                        SHA256::Digest legacyHash = HashFile(legacyFilePath);

                        if (preyHash == legacyHash)
                        {
                            // File not changed
                            stats.unchanged++;
                            fmt::println("Unchanged (bin): {}", relPath.generic_u8string());
                            continue;
                        }
                    }

                    fmt::println("Copying (bin): {}", relPath.generic_u8string());
                    fs::copy_file(legacyFilePath, outFilePath, fs::copy_options::overwrite_existing);
                    stats.copied++;
                    continue;
                }

                unsigned parseOptions =
                    pPolicy->GetMethod() == FileMergingPolicy3::EMethod::Excel2003
                    ? XmlMerger3::EXCEL_PARSE_OPTIONS
                    : pugi::parse_default;

                pugi::xml_document legacyDoc = XmlUtils::LoadDocument(legacyFilePath, parseOptions);
                pugi::xml_document preyDoc = XmlUtils::LoadDocument(preyFilePath, parseOptions);
                pugi::xml_document outDoc;

                LegacyModConverter converter;
                bool foundChanges = false;

                if (pPolicy->GetMethod() == FileMergingPolicy3::EMethod::Merge)
                {
                    // Patch the files
                    {
                        XmlErrorStack errorStack("LegacyMod");
                        PreyFilePatcher::PatchDocument(legacyFilePath, fs::path(), legacyDoc, *pPolicy, errorStack);
                    }
                    {
                        XmlErrorStack errorStack("Prey");
                        PreyFilePatcher::PatchDocument(preyFilePath, fs::path(), preyDoc, *pPolicy, errorStack);
                    }

                    converter.PatchDocument(relPath, legacyDoc, *pPolicy);
                    foundChanges = converter.ConvertDocument(preyDoc, legacyDoc, outDoc, *pPolicy);
                }
                else if (pPolicy->GetMethod() == FileMergingPolicy3::EMethod::Excel2003)
                {
                    foundChanges = converter.ConvertExcelDocument(preyDoc, legacyDoc, outDoc, *pPolicy);
                }

                // Print the log
                const std::list<LegacyModConverter::LogEntry>& logs = converter.GetLogs();
                bool foundErrors = false;

                for (auto& i : logs)
                {
                    fmt::println("{}: {}", relPath.generic_u8string(), i.message);
                    fmt::println("Stack trace:");

                    for (const std::string& j : i.stackTrace)
                    {
                        fmt::println("- {}", j);
                    }

                    if (i.level == severityLevel::error)
                        foundErrors = true;
                }

                // Check for errors
                if (foundErrors)
                {
                    fmt::println("Failed to convert {}", relPath.generic_u8string());
                    stats.failed++;
                    continue;
                }
                
                // Save the file if need to
                if (foundChanges)
                {
                    // Save the converted file
                    fs::create_directories(outFilePath.parent_path());

                    if (!outDoc.save_file(outFilePath.c_str(), "    ", pugi::format_default | pugi::format_indent_attributes, pugi::encoding_utf8))
                    {
                        throw std::runtime_error("Failed to save the file");
                    }

                    stats.converted++;
                    fmt::println("Converted: {}", relPath.generic_u8string());
                }
                else
                {
                    // File not changed
                    stats.unchanged++;
                    fmt::println("Unchanged (xml): {}", relPath.generic_u8string());
                }
            }
            catch (const std::exception& e)
            {
                fmt::println("Failed to convert {}", relPath.generic_u8string());
                fmt::println("{}", e.what());
                stats.failed++;
            }
        }

        fmt::println("{}", LINES);
        fmt::println("Total: {:>5} | Copied: {:>5} | Converted: {:>5} | Failed: {:>5} | Unchanged: {:>5}",
            stats.total, stats.copied, stats.converted, stats.failed, stats.unchanged);

        return stats.failed > 0 ? 1 : 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 2;
}
