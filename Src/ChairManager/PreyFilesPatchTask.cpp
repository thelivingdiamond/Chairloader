#include <Chairloader/Private/XmlUtils.h>
#include <ChairMerger/MergingLibrary3.h>
#include <ChairMerger/XmlTypeLibrary.h>
#include <ChairMerger/PreyFilePatcher.h>
#include <Manager/PreditorFiles.h>
#include "PreyFilesPatchTask.h"

//! This must be incremented when merging policy updates or PreyFilePatcher is changed.
constexpr int FILE_PATCH_VERSION = 1;

bool PreyFilesPatchTask::IsPatchingRequired()
{
    fs::path path = fs::current_path() / "PreyFiles" / PREDITOR_FILES_EXTRACTED;
    pugi::xml_document doc;

    if (!doc.load_file(path.c_str()))
        return true;

    int patchVersion = doc.first_child().attribute("patchVersion").as_int();
    return patchVersion != FILE_PATCH_VERSION;
}

void PreyFilesPatchTask::RunTask()
{
    progressCallback("Preparing...", 0.0f);

    fs::path preyFilesPath = fs::absolute("PreyFiles");
    fs::path mergingLibPath = fs::absolute("MergingLibrary");
    fs::path xmlTypesPath = fs::absolute("XmlTypeLibrary.xml");

    // Load type library
    logCallback(fmt::format("Loading XML types: {}", xmlTypesPath.u8string()));
    XmlTypeLibrary typeLib;
    typeLib.LoadTypesFromFile(xmlTypesPath);

    // Load merging library
    fs::path mergingLibDir = fs::current_path() / "MergingLibrary";
    fs::path mergingLibFile = fs::current_path() / "MergingLibrary.xml";
    MergingLibrary3 mergingLibrary(&typeLib);

    if (fs::exists(mergingLibDir))
    {
        // Use directory if it exists. It contains the source files.
        logCallback("Using merging library from directory");
        mergingLibrary.LoadFromDir(mergingLibDir);
    }
    else if (fs::exists(mergingLibFile))
    {
        // Use file instead. It contains the combined contents of source dir.
        mergingLibrary.LoadFromFile(mergingLibFile);
    }
    else
    {
        throw std::runtime_error("Merging library missing");
    }

    // Load patch metadata
    pugi::xml_document patchDoc;

    if (!patchDoc.load_file((preyFilesPath / PREDITOR_FILES_EXTRACTED).c_str()))
    {
        patchDoc.reset();
        patchDoc.append_child("FileMetadata");
    }

    pugi::xml_attribute patchVersionAttr = XmlUtils::GetOrAddAttribute(patchDoc.first_child(), "patchVersion");

    // Find all XML files
    size_t totalXmlCount = 0;
    logCallback("Counting XML files...");

    for (const fs::directory_entry& dirEnt : fs::recursive_directory_iterator(preyFilesPath))
    {
        if (dirEnt.is_directory())
            continue;

        totalXmlCount++;
    }

    logCallback(fmt::format("Found {} files", totalXmlCount));

    fs::path xsdBasePath;

#ifdef DEBUG_BUILD
    // TODO 2024-09-03: Ugly hack. If running Chairloader from source, use local XSDs
    if (fs::exists(fs::current_path() / "../Xsd/Chairloader/MetaType.xsd"))
        xsdBasePath = fs::current_path() / "../Xsd";
#endif

    size_t processedXmls = 0;

    auto fnCallback = [&](const std::string& fileName)
    {
        processedXmls++;
        progressCallback(fileName, (float)processedXmls / (float)totalXmlCount);
    };

    PreyFilePatcher::PatchDirectory(
        preyFilesPath,
        xsdBasePath,
        mergingLibrary,
        &typeLib,
        fnCallback);

    // Update patch version
    patchVersionAttr.set_value(FILE_PATCH_VERSION);

    if (!patchDoc.save_file((preyFilesPath / PREDITOR_FILES_EXTRACTED).c_str()))
        throw std::runtime_error(fmt::format("Failed to save {}", PREDITOR_FILES_EXTRACTED));
}
