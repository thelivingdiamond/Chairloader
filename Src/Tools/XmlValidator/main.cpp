#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/program_options.hpp>
#include <taskflow/algorithm/for_each.hpp>
#include <taskflow/taskflow.hpp>
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/PreyFilePatcher.h>
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
    int skipped = 0;
};

struct ExecutorOutput
{
    ValidationStats stats;
    std::map<fs::path, XmlValidator::Result> results;
    std::map<fs::path, std::string> exceptionList;
    std::set<fs::path> missingPolicyList;
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
            ("xml-dir", po::value<std::string>()->required(), "path to the XML file directory")
            ("mode", po::value<std::string>()->required(), "validation mode: prey, mergingBase, mod")
            ("patch", "apply patches prior to validation");

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


        XmlValidator::EMode validationMode;

        if (vm["mode"].as<std::string>() == "prey")
            validationMode = XmlValidator::EMode::Prey;
        else if (vm["mode"].as<std::string>() == "mergingBase")
            validationMode = XmlValidator::EMode::MergingBase;
        else if (vm["mode"].as<std::string>() == "mod")
            validationMode = XmlValidator::EMode::Mod;
        else
            throw std::runtime_error("Invalid --mode");

        bool applyPatches = vm.count("patch") != 0;

        // Load type library
        fs::path typeLibPath = fs::u8path(vm["type-lib"].as<std::string>());
        XmlTypeLibrary typeLib;
        typeLib.LoadTypesFromFile(typeLibPath);

        // Load merging library
        fs::path mergingLibraryPath = fs::u8path(vm["merging-lib"].as<std::string>());
        fmt::println("Merging library: {}", mergingLibraryPath.u8string());
        MergingLibrary3 mergingLibrary(&typeLib);
        mergingLibrary.LoadFromPath(mergingLibraryPath);

        // Find all XML files
        fs::path xmlDir = fs::u8path(vm["xml-dir"].as<std::string>());
        std::vector<fs::path> xmlFileList;
        xmlFileList.reserve(5000);
        fmt::println("Collecting XML file list...");

        for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(xmlDir))
        {
            if (dirEnt.is_directory())
                continue;

            fs::path xmlFullPath = dirEnt.path();

            if (!boost::algorithm::iequals(xmlFullPath.extension().u8string(), ".xml"))
                continue;

            xmlFileList.push_back(xmlFullPath.lexically_relative(xmlDir));
        }

        fmt::println("Processing {} files", xmlFileList.size());

        // Process XMLs
        tf::Executor executor;
        tf::Taskflow taskflow;
        std::vector<ExecutorOutput> executorOutputs(executor.num_workers());

        auto fnProcessXmlFile = [validationMode, &xmlFileList, &xmlDir, &executorOutputs, &executor, &mergingLibrary, &typeLib, applyPatches](size_t fileIdx) {
            const fs::path& xmlRelPath = xmlFileList[fileIdx];
            fs::path xmlFullPath = xmlDir / xmlRelPath;
            ExecutorOutput& output = executorOutputs[executor.this_worker_id()];

            output.stats.total++;

            try
            {
                pugi::xml_document xmlDoc = XmlUtils::LoadDocument(xmlFullPath);
                const FileMergingPolicy3* filePolicy = mergingLibrary.FindPolicyForFile(xmlRelPath);

                if (!filePolicy)
                {
                    output.missingPolicyList.insert(xmlRelPath);
                    output.stats.missing++;
                    return;
                }

                if (filePolicy->GetMethod() == FileMergingPolicy3::EMethod::Localization)
                {
                    // Can't validate localization files
                    output.stats.skipped++;
                    return;
                }

                output.stats.checked++;

                if (applyPatches)
                {
                    XmlErrorStack errorStack("FILE");
                    PreyFilePatcher::PatchDocument(xmlFullPath, xmlDoc, *filePolicy, errorStack);
                }

                XmlValidator::Context context;
                context.mode = applyPatches ? XmlValidator::EMode::MergingBase : validationMode;
                context.pTypeLib = &typeLib;

                XmlValidator::Result result = XmlValidator::ValidateDocument(
                    context,
                    xmlDoc,
                    *filePolicy);

                if (!result)
                    output.stats.failed++;
                else
                    output.stats.valid++;

                output.results.emplace(xmlRelPath, std::move(result));
            }
            catch (const std::exception& e)
            {
                output.exceptionList.emplace(xmlRelPath, e.what());
                output.stats.failed++;
            }
        };

        taskflow.for_each_index((size_t)0, xmlFileList.size(), (size_t)1, fnProcessXmlFile, tf::DynamicPartitioner(64));
        executor.run(taskflow).wait();

        // Record processing time here so printing doesn't count
        auto endTime = std::chrono::steady_clock::now();

        // Combine results
        ExecutorOutput combinedOutput;

        for (const ExecutorOutput& i : executorOutputs)
        {
            combinedOutput.stats.total += i.stats.total;
            combinedOutput.stats.checked += i.stats.checked;
            combinedOutput.stats.valid += i.stats.valid;
            combinedOutput.stats.failed += i.stats.failed;
            combinedOutput.stats.missing += i.stats.missing;
            combinedOutput.stats.skipped += i.stats.skipped;

            for (auto& [k, v] : i.results)
            {
                combinedOutput.results.emplace(k, std::move(v));
            }

            for (auto& [k, v] : i.exceptionList)
            {
                combinedOutput.exceptionList.emplace(k, std::move(v));
            }

            for (auto& k : i.missingPolicyList)
            {
                combinedOutput.missingPolicyList.emplace(k);
            }
        }

        // Print results
        for (const auto& [xmlRelPath, result] : combinedOutput.results)
        {
            if (result)
                continue;

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
        }

        // Print exceptions
        if (!combinedOutput.exceptionList.empty())
        {
            constexpr size_t MAX_PRINT = 5;
            size_t i = 0;
            fmt::println(LINES);
            fmt::println("The following files failed with exception:");

            for (const auto& [xmlRelPath, msg] : combinedOutput.exceptionList)
            {
                if (i >= MAX_PRINT)
                {
                    fmt::println("    and {} more", combinedOutput.exceptionList.size() - MAX_PRINT);
                    break;
                }

                fmt::println("    {}) {}: {}", i + 1, xmlRelPath.u8string(), msg);
                i++;
            }
        }

        // Print missing
        if (!combinedOutput.missingPolicyList.empty())
        {
            constexpr size_t MAX_PRINT = 5;
            size_t i = 0;
            fmt::println(LINES);
            fmt::println("The following files are missing the merging policy:");

            for (const fs::path& xmlRelPath : combinedOutput.missingPolicyList)
            {
                if (i >= MAX_PRINT)
                {
                    fmt::println("    and {} more", combinedOutput.missingPolicyList.size() - MAX_PRINT);
                    break;
                }

                fmt::println("    {}) {}", i + 1, xmlRelPath.u8string());
                i++;
            }
        }

        fmt::println(LINES);
        fmt::println("Total: {:>5} | Checked: {:>5} | Valid: {:>5} | Failed: {:>5} | Missing: {:>5} | Skipped: {:>5}",
            combinedOutput.stats.total, combinedOutput.stats.checked, combinedOutput.stats.valid,
            combinedOutput.stats.failed, combinedOutput.stats.missing, combinedOutput.stats.skipped);

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
