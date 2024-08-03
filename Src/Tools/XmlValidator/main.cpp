#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/program_options.hpp>
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/XmlValidator.h>

namespace po = boost::program_options;

struct ValidationStats
{
    int total = 0;
    int checked = 0;
    int valid = 0;
    int failed = 0;
    int missing = 0;
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
            ("xml-dir", po::value<std::string>()->required(), "path to the XML file directory");

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
        auto startTime = std::chrono::steady_clock::now();

        // Load type library
        fs::path typeLibPath = fs::u8path(vm["type-lib"].as<std::string>());
        XmlTypeLibrary typeLib;
        typeLib.LoadTypesFromFile(typeLibPath);

        // Load merging library
        fs::path mergingLibraryPath = fs::u8path(vm["merging-lib"].as<std::string>());
        fmt::println("Merging library: {}", mergingLibraryPath.u8string());
        MergingLibrary3 mergingLibrary(&typeLib);
        mergingLibrary.LoadFromPath(mergingLibraryPath);

        // Process XMLs
        fs::path xmlDir = fs::u8path(vm["xml-dir"].as<std::string>());
        
        ValidationStats stats;
        std::vector<fs::path> missingPolicyList;

        for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(xmlDir))
        {
            if (dirEnt.is_directory())
                continue;

            fs::path xmlFullPath = dirEnt.path();

            if (!boost::algorithm::iequals(xmlFullPath.extension().u8string(), ".xml"))
                continue;

            fs::path xmlRelPath = xmlFullPath.lexically_relative(xmlDir);
            stats.total++;

            try
            {
                pugi::xml_document xmlDoc = XmlUtils::LoadDocument(xmlFullPath);
                const FileMergingPolicy3* filePolicy = mergingLibrary.FindPolicyForFile(xmlRelPath);

                if (!filePolicy)
                {
                    missingPolicyList.push_back(xmlRelPath);
                    stats.missing++;
                    continue;
                }

                stats.checked++;

                XmlValidator::Context context;
                context.nodeType = XmlValidator::ENodeType::MergingBase;
                context.pTypeLib = &typeLib;

                XmlValidator::Result result = XmlValidator::ValidateDocument(
                    context,
                    xmlDoc,
                    *filePolicy);

                if (!result)
                {
                    fmt::println(LINES);
                    fmt::println("- VALIDATION FAILURE: {}", xmlRelPath.u8string());
                    fmt::println(LINES);

                    for (auto& error : result.errors)
                    {
                        // Path
                        for (auto it = error.path.crbegin(); it != error.path.crend(); ++it)
                        {
                            fmt::print("> {} ", *it);
                        }

                        // Attribute
                        if (!error.attributeName.empty())
                            fmt::print("| (attr = {})", error.attributeName);

                        fmt::println("");

                        // Message
                        fmt::println("    {}", error.message);
                    }

                    stats.failed++;
                }
                else
                {
                    stats.valid++;
                }
            }
            catch (const std::exception& e)
            {
                fmt::println("Error while processing {}: {}", xmlRelPath.u8string(), e.what());
                stats.failed++;
            }
        }

        // Show results
        if (!missingPolicyList.empty())
        {
            constexpr size_t MAX_PRINT = 5;
            fmt::println(LINES);
            fmt::println("The following files are missing the merging policy:");

            for (size_t i = 0; i < missingPolicyList.size() && i < MAX_PRINT; i++)
            {
                fmt::println("    {}) {}", i + 1, missingPolicyList[i].u8string());
            }

            if (missingPolicyList.size() > MAX_PRINT)
                fmt::println("    and {} more", missingPolicyList.size() - MAX_PRINT);
        }

        fmt::println(LINES);
        fmt::println("Total: {:>5} | Checked: {:>5} | Valid: {:>5} | Failed: {:>5} | Missing: {:>5}",
            stats.total, stats.checked, stats.valid, stats.failed, stats.missing);

        auto endTime = std::chrono::steady_clock::now();
        auto timeElapsed = endTime - startTime;
        fmt::println("Time elapsed: {:.3f} s", std::chrono::duration_cast<std::chrono::milliseconds>(timeElapsed).count() / 1000.0);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 2;
}
