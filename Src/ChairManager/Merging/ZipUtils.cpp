//
// Created by theli on 4/3/2023.
//

#include "ZipUtils.h"
#include <libzippp.h>

void ZipUtils::ExtractFolder(const fs::path& zipPath, const fs::path& outPath)
{
    libzippp::ZipArchive archive(zipPath.u8string());
    archive.open(libzippp::ZipArchive::ReadOnly);
    if (!fs::exists(outPath))
        fs::create_directories(outPath);
    for (auto& entry : archive.getEntries())
    {
        if (entry.isDirectory())
        {
            fs::create_directories(outPath.u8string() + "/" + entry.getName());
            continue;
        }
        else if (entry.isFile())
        {
            fs::path entryName = entry.getName();
            fs::path entryPath = outPath / entryName;
            if (!fs::exists(entryPath.parent_path()))
                fs::create_directories(entryPath.parent_path());
            std::ofstream outFile(entryPath, std::ios::binary);
            outFile.write(entry.readAsText().c_str(), entry.getSize());
            outFile.close();
        }
    }
}

void ZipUtils::CompressFolder(const fs::path& folderPath, const fs::path& outPath, bool removeDuplicateRootFolder)
{
    libzippp::ZipArchive archive(outPath.u8string());
    if (fs::exists(outPath))
        fs::remove(outPath);
    archive.open(libzippp::ZipArchive::New);
    if (!archive.isOpen())
        throw std::runtime_error("Could not open archive");
    for (const auto& entry : fs::recursive_directory_iterator(folderPath))
    {
        if (entry.is_regular_file())
        {
            std::string entryPath = entry.path().u8string();
            std::string localPath = entry.path().lexically_relative(folderPath.parent_path()).u8string();
            std::replace(localPath.begin(), localPath.end(), '\\', '/');
            if (removeDuplicateRootFolder)
            {
                localPath = localPath.substr(localPath.find_first_of('/') + 1);
            }
            // replace all \ with /
            //            printf("Adding %s as %s\n\n", entryPath.c_str(), localPath.c_str());
            archive.addFile(localPath, entryPath);
        }
    }
    archive.close();
}
