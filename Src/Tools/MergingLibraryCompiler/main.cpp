#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <Prey/CryCore/Platform/platform_impl.inl>
#include <Chairloader/Private/XmlUtils.h>

namespace po = boost::program_options;

// TODO 2024-05-04: Remove this
struct ChairloaderGlobalEnvironment* gCL;

static constexpr char LINES[] = "----------------------------------------------------------------------";

static constexpr char XS_SCHEMA[] = "xs:schema";

int main(int argc, char** argv)
{
    po::options_description desc("Compiler merging library into a single XML for easier distribution");
    po::variables_map vm;

    try
    {
        desc.add_options()
            ("help", "produce help message")
            ("dir", po::value<std::string>()->required(), "path to the merging library directory")
            ("out-file", po::value<std::string>()->required(), "path to the output file");

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
        fs::path mergingLibraryDir = vm["dir"].as<std::string>();
        fs::path outFilePath = vm["out-file"].as<std::string>();

        pugi::xml_document outXml;
        pugi::xml_node outRoot = outXml.append_child("MergingLibrary");
        outRoot.append_child(pugi::node_comment).set_value(" WARNING! This file is generated automatically! ");
        outRoot.append_child(pugi::node_comment).set_value(" If you want to modify it: ");
        outRoot.append_child(pugi::node_comment).set_value("   1) Download Data/MergingLibrary folder from Chairloader GitHub ");
        outRoot.append_child(pugi::node_comment).set_value("   2) Place it next to this file ");
        outRoot.append_child(pugi::node_comment).set_value(" Folder always takes priority and will be used instead of the file ");
        outRoot.append_child(pugi::node_comment).set_value(" ");

        std::time_t currentTime = std::time(nullptr);
        std::tm* now = std::gmtime(&currentTime);
        outRoot.append_child(pugi::node_comment).set_value(fmt::format(
            " Generated at {:04}-{:02}-{:02} {:02}:{:02}:{:02} UTC ",
            now->tm_year + 1900,
            now->tm_mon + 1,
            now->tm_mday,
            now->tm_hour,
            now->tm_min,
            now->tm_sec
        ).c_str());

        for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(mergingLibraryDir))
        {
            if (dirEnt.is_directory())
                continue;

            fs::path fullPath = dirEnt.path();
            fs::path relPath = fullPath.lexically_relative(mergingLibraryDir);
            pugi::xml_document doc = XmlUtils::LoadDocument(fullPath);
            pugi::xml_node docRoot = doc.first_child();
            docRoot.remove_attribute("xmlns");
            docRoot.remove_attribute("xmlns:xsi");
            docRoot.remove_attribute("xsi:schemaLocation");
            docRoot.prepend_attribute("relPath").set_value(relPath.generic_u8string().c_str());
            outRoot.append_copy(docRoot);
        }

        if (!outXml.save_file(outFilePath.c_str(), "  "))
            throw std::runtime_error(fmt::format("Failed to save {}", outFilePath.u8string()));

        return 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 2;
}
