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

        for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(legacyModDir))
        {
            if (dirEnt.is_directory())
                continue;

            stats.total++;
            fs::path legacyFilePath = dirEnt.path();
            fs::path relPath = legacyFilePath.lexically_relative(legacyModDir);

            try
            {
                fs::path preyFilePath = preyFilesDir / relPath;
                fs::path outFilePath = outDir / relPath;

                if (!fs::exists(preyFilePath))
                {
                    // This is a new file. Just copy it.
                    fmt::println("Copying: {}", relPath.generic_u8string());
                    stats.copied++;
                    continue;
                }

                const FileMergingPolicy3* pPolicy = mergingLibrary.FindPolicyForFile(relPath);

                if (!pPolicy)
                {
                    // No policy for this file. This is not supposed to happen.
                    throw std::runtime_error("Policy not found for file");
                }

                pugi::xml_document legacyDoc = XmlUtils::LoadDocument(legacyFilePath);
                pugi::xml_document preyDoc = XmlUtils::LoadDocument(preyFilePath);
                pugi::xml_document outDoc;

                // Patch the files
                {
                    XmlErrorStack errorStack("LegacyMod");
                    PreyFilePatcher::PatchDocument(legacyFilePath, fs::path(), legacyDoc, *pPolicy, errorStack);
                }
                {
                    XmlErrorStack errorStack("Prey");
                    PreyFilePatcher::PatchDocument(preyFilePath, fs::path(), preyDoc, *pPolicy, errorStack);
                }

                LegacyModConverter converter;
                
                if (converter.ConvertDocument(preyDoc, legacyDoc, outDoc, *pPolicy))
                {
                    // TODO 2024-09-22: Check for errors in the log
                    // TODO 2024-09-22: Also print the log
                    // TODO 2024-09-22: Add stats to the merging process

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
                    fmt::println("Unchanged: {}", relPath.generic_u8string());
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
