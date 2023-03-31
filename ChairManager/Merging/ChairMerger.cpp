//
// Created by theli on 3/26/2023.
//

#include <regex>
#include "ChairMerger.h"
#include "ChairManager.h"
#include <gtest/gtest.h>
#include <boost/algorithm/string.hpp>
#include "XMLMerger2.h"



void ChairMerger::PreMerge() {
    // make sure mod configs are loaded
    // clear out the output directory
    try{
        fs::remove_all(m_OutputPath);
        fs::create_directories(m_OutputPath);
    } catch (fs::filesystem_error& e){
        ChairManager::Get().log(severityLevel::error, "ChairMerger", "Failed to clear output directory: " + std::string(e.what()));
        ChairManager::Get().SetDeployFailed();
        return;
    }
    for(auto& mod : ChairManager::Get().GetMods()){
        if(mod.enabled && mod.hasLevelXML){
            m_LevelFilesChanged = true;
        }
    }

    // Copy over the chairloader patch files
    CopyChairloaderPatchFiles();
    LoadPatchFileChecksums();
}

void ChairMerger::Merge() {
    // merge the legacy mods
    for(auto& legacyMod : ChairManager::Get().GetLegacyMods()){
        ProcessLegacyMod(legacyMod);
        m_MergeThreadPool->wait();
    }

    // merge the registered mods
    for(auto& mod : ChairManager::Get().GetMods()){
        ProcessMod(std::make_shared<Mod>(mod));
        m_MergeThreadPool->wait();
    }
}

void ChairMerger::PostMerge() {
    // Level Entity ID Serialization
    // Pack level files
    // pack patch_chairloader.pak
    // copy patches to game directories
}
//! Function to resolve all attribute wildcards in an xml document
void ChairMerger::ResolveFileWildcards(pugi::xml_node docNode,  std::shared_ptr<Mod> mod) {
    // start the recursive descent on the root node
    ResolveAttributeWildcards(docNode, mod->modName);

}

//! Recursive function to descend an xml node tree and find all attribute wildcards
void ChairMerger::ResolveAttributeWildcards(pugi::xml_node node, std::string modName) {
    // iterate over all attributes
    for (auto &attribute : node.attributes()) {
        auto wildcard = std::make_shared<AttributeWildcard>();
        wildcard->attribute = attribute;
        wildcard->mod_name = modName;
        if(GetAttributeWildcardValue(wildcard))
            attribute.set_value(wildcard->match_value.c_str());

    }

    // iterate over all child nodes
    for (auto &childNode : node.children()) {
        // recursively descend the tree
        ResolveAttributeWildcards(childNode, modName);
    }
}


/*! Attribute Wildcards
<X Param="{{ configValue }}" /> <!-- Current mod's config -->
<X Param="{{ $.modAuthor.modName.configValue }}"/> <!-- Reference a different mod. modAuthor.modName is actually "modName" from ModInfo.xml. $ indicates that we are looking in the global space -->
<X ch:apply_if="$.modAuthor.modName.modEnabled" /> <!-- Check if different mod is installed and enabled. Allows for some basic interop between XML mods -->
<X ch:apply_if="{{ configValue }}"/> <!-- apply if some other config value -->
<X ch:remove /> <!-- Remove this node from the XML -->
 <X ch:patch_mode/> <!-- Patch mode: will overwrite all attributes present in the mod node w/out any vanilla checking. -->
 */
bool ChairMerger::GetAttributeWildcardValue(std::shared_ptr<AttributeWildcard> wildcard) {
    if(std::string(wildcard->attribute.value()).find("{{") != std::string::npos && std::string(wildcard->attribute.value()).find("}}") != std::string::npos) {
        // Regex to determine if the attribute value is a wildcard
        std::regex re(R"(\{\{(.*)\}\})");
        std::smatch match;
        std::string value = wildcard->attribute.value();

        if(std::regex_search(value, match, re)) {
            if(match.ready()) {
                auto wildcardName = match[1].str();
                // remove spaces from wildcardName
                wildcardName.erase(std::remove_if(wildcardName.begin(), wildcardName.end(), isspace), wildcardName.end());

                if(wildcardName[0] == '$') { // Global indicator token
                    // this means we will be looking for global values from other mods, wildcard name will be $.modname.parameterName
                    std::regex localMatch = std::regex(R"(\$.(.*).(.*))");
                    std::smatch localMatchResult;
                    if(std::regex_search(wildcardName, localMatchResult, localMatch)) {
                        if(localMatchResult.ready()) {
                            std::string modName = localMatchResult[1].str();
                            std::string parameter = localMatchResult[2].str();
                            ChairManager::Get().log(severityLevel::debug, "Found local match: %s, %s", modName.c_str(), parameter.c_str());
                            if(parameter == "modEnabled"){
                                wildcard->match_value = ChairManager::Get().IsModEnabled(modName) ? "true" : "false";
                            } else {
                                auto modConfig = ChairManager::Get().GetConfigManager()->getModConfig(modName);
                                wildcard->match_value = modConfig.getConfigValue(parameter);
                                wildcard->has_match_value = true;
                                if(wildcard->match_value.empty()) {
                                    ChairManager::Get().log(severityLevel::error, "XMLMerger: could not find config value %s in mod %s", parameter.c_str(), modName.c_str());
                                }
                            }
                        }
                    }
                } else {
                    // this means we will be looking for values from the current mod
                    wildcard->match_value = ChairManager::Get().GetConfigManager()->getModConfig(wildcard->mod_name).getConfigValue(wildcardName);
                    if(!wildcard->match_value.empty()) {
                        wildcard->has_match_value = true;
                    } else {
                        ChairManager::Get().log(severityLevel::error, "XMLMerger: could not find config value %s in mod %s", wildcardName.c_str(), wildcard->mod_name.c_str());
                    }
                }
            }
        } else {
            ChairManager::Get().log(severityLevel::warning, "Could not find wildcard value in %s", wildcard->attribute.value());
            wildcard->type = AttributeWildcard::wildcard_type::none;
        }
    } else {
        wildcard->type = AttributeWildcard::wildcard_type::none;
    }
    return wildcard->has_match_value;
}

void ChairMerger::CopyModDataFiles(fs::path sourcePath, std::string modName) {

    m_MergeThreadPool->enqueue([sourcePath, modName] {
        RecursiveFileCopyExclusiveFilter(sourcePath, m_OutputPath, {".xml"}, modName);
    });
}

void ChairMerger::RecursiveFileCopyExclusiveFilter(fs::path source, fs::path destination, std::vector<std::string> exclusions, std::string modName) {
    if(fs::exists(source) && fs::is_directory(source)) {
        for(auto &file : fs::directory_iterator(source)) {
            if(fs::is_directory(file)) {
                RecursiveFileCopyExclusiveFilter(file.path(), destination / file.path().filename(), exclusions, modName);
            } else {
                IsLevelFile(file.path(), modName);
                bool shouldCopy = true;
                for(auto &exclusion : exclusions) {
                    if(file.path().extension() == exclusion) {
                        shouldCopy = false;
                        break;
                    }
                }
                if(shouldCopy) {
                    auto destinationPath = destination / file.path().filename();
                    fs::create_directories(destinationPath.parent_path());
                    fs::copy_file(file.path(), destinationPath, fs::copy_options::overwrite_existing);
                }
            }
        }
    }
}

ChairMerger::ChairMerger() {
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Initializing ChairMerger");
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: ChairMerger Initialized");

    m_ModPath = ChairManager::Get().GetGamePath() / "Mods";
    m_LevelFilesPath = ChairManager::Get().GetGamePath() / "GameSDK" / "Levels";
    m_LocalizationFilesPath = ChairManager::Get().GetGamePath() / "Localization";
    m_PrecacheFilesPath = ChairManager::Get().GetGamePath() / "GameSDK" / "Precache";

    if(!fs::exists(m_OutputPath)){
        fs::create_directory(m_OutputPath);
    }
    m_LevelFilesChanged = false;
    m_LocalizationFilesChanged = false;
    m_MergeThreadPool = std::make_unique<ThreadPool>(std::thread::hardware_concurrency());
    m_MergingPolicyDoc = std::make_unique<pugi::xml_document>();

    auto result = m_MergingPolicyDoc->load_file("MergingLibrary.xml");
    if(!result) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load MergingLibrary.xml");
    }
}

void ChairMerger::ProcessMod(std::shared_ptr<Mod> mod) {
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Processing mod %s", mod->modName.c_str());

    fs::path dataPath = m_ModPath / mod->modName / "Data";

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(dataPath, mod->modName);

    // Merge all XML files from the mod's Data folder
    RecursiveMergeXMLFiles(dataPath, mod->modName, false);
}

void ChairMerger::ProcessLegacyMod(std::string modName) {
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Processing legacy mod %s", modName.c_str());

    fs::path dataPath = m_ModPath / "Legacy" / modName ;

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(dataPath, modName);

    // Merge all XML files from the mod's Data folder
    RecursiveMergeXMLFiles(dataPath, modName, true);
}


void ChairMerger::RecursiveMergeXMLFiles(const fs::path &source, std::string modName, bool isLegacy) {
    if(fs::exists(source) && fs::is_directory(source)) {
        for(auto &file : fs::directory_iterator(source)) {
            if(fs::is_directory(file)) {
                RecursiveMergeXMLFiles(file.path(), modName, isLegacy);
            } else {
                IsLevelFile(file.path(), modName);
                if(file.path().extension() == ".xml") {
                    // Toss the file into the thread pool
                    m_MergeThreadPool->enqueue([this, file, modName,isLegacy] {
                        ProcessXMLFile(file, modName, isLegacy);
                    });
                }
            }
        }
    }
}

void ChairMerger::ProcessXMLFile(const fs::path &file, std::string modName, bool isLegacy) {
    fs::path relativePath;
    if(isLegacy){
        relativePath = file.lexically_relative(m_ModPath / "Legacy" / modName);
    } else {
        relativePath = file.lexically_relative(m_ModPath / modName / "Data");
    }

    // now we have the relative path to the file, we can use this to find the original file, and the base file in the output directory
    fs::path originalFile = m_PreyFilePath / relativePath;
    fs::path baseFile = m_OutputPath / relativePath;

    pugi::xml_document baseDoc, modDoc, originalDoc;
    pugi::xml_parse_result baseResult = baseDoc.load_file(baseFile.wstring().c_str());
    pugi::xml_parse_result modResult = modDoc.load_file(file.wstring().c_str());
    pugi::xml_parse_result originalResult = originalDoc.load_file(originalFile.wstring().c_str());

    if(!modResult) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load mod file %s", file.u8string().c_str());
        return;
    }
    // resolve attribute wildcards on non legacy files
    if(!isLegacy)
        ResolveAttributeWildcards(modDoc.first_child(), modName);

    if(!originalResult){
        // this is a new file, we have to just copy it over, even if base exists
        fs::copy_file(file, baseFile, fs::copy_options::overwrite_existing);
        return;
    }

    //if we have an original result, we can actually do some merging
    auto policy = GetFileMergingPolicy(relativePath, modName);
    if(policy.policy == MergingPolicy::identification_policy::overwrite) {
        fs::copy_file(file, baseFile, fs::copy_options::overwrite_existing);
        return;
    }

    if(!baseResult){
        // this is a file that hasn't been merged before, we should copy the original over
        if(!fs::exists(baseFile.parent_path()))
            fs::create_directories(baseFile.parent_path());
        fs::copy_file(originalFile, baseFile, fs::copy_options::overwrite_existing);
        baseResult = baseDoc.load_file(baseFile.wstring().c_str());
        if(!baseResult){
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load base file %s", baseFile.u8string().c_str());
            return;
        }
    }

    XMLMerger2::MergeXMLDocument(baseDoc, modDoc, originalDoc, policy);

    baseDoc.save_file(baseFile.wstring().c_str());

    // we are done

}

pugi::xml_node noCaseChild(pugi::xml_node& node, std::string name) {
    for(auto &child : node.children()){
        if(boost::iequals(child.name(), name)){
            return child;
        }
    }
    return {};
}

MergingPolicy ChairMerger::GetFileMergingPolicy(const fs::path &file, std::string modName) {
    MergingPolicy policy;
    auto root = m_MergingPolicyDoc->child("root");
    policy = MergingPolicy(root.child("mergingPolicy"), file, modName);
    auto currentNode = root;
    fs::path currentPath;
    for (auto &directory : file){
        if(!fs::exists(m_PreyFilePath / currentPath / directory)){
            break;
        }
        currentPath /= directory;
        currentNode = noCaseChild(currentNode, directory.u8string());
        if(!currentNode){
            continue;
        } else {
            if(currentNode.child("mergingPolicy")){
                policy = MergingPolicy(currentNode.child("mergingPolicy"), file, modName);
            }
        }
    }
    if  (currentPath != file){
        // File is not in the library, so it must be novel
        ChairManager::Get().log(severityLevel::error, "XMLMerger: File %s not found in merging library", file.u8string());
        policy.policy = MergingPolicy::identification_policy::unknown;
        policy.attributeMatches.clear();
        policy.nodeStructure = pugi::xml_node();
    }
    return policy;
}

bool ChairMerger::IsLevelFile(const fs::path &modFile, std::string modName) {
    // look for /Levels/ in the path
    auto registeredPath = modFile.lexically_relative(m_ModPath / modName / "Data");
    auto legacyPath = modFile.lexically_relative(m_ModPath / "Legacy" / modName);
    // Levels should be the first directory in the path, that's the only one we should check
    // get the first directory in the path
    auto firstDir = registeredPath.begin();
    if(firstDir != registeredPath.end() && *firstDir == "Levels"){
        // this is a level file, we need to add it to the level list
        m_LevelFilesChanged = true;
        return true;
    }
    firstDir = legacyPath.begin();
    if(firstDir != legacyPath.end() && *firstDir == "Levels"){
        // this is a level file, we need to add it to the level list
        m_LevelFilesChanged = true;
        return true;
    }
    return false;
}

bool ChairMerger::IsLocalizationFile(const fs::path &modFile, std::string modName) {
    // look for /Localization/ in the path
    auto registeredPath = modFile.lexically_relative(m_ModPath / modName / "Data");
    auto legacyPath = modFile.lexically_relative(m_ModPath / "Legacy" / modName);
    // Localization should be the first directory in the path, that's the only one we should check
    // get the first directory in the path
    auto firstDir = registeredPath.begin();
    if(firstDir != registeredPath.end() && *firstDir == "Localization"){
        // this is a localization file, we need to add it to the localization list
        m_LocalizationFilesChanged = true;
        return true;
    }
    firstDir = legacyPath.begin();
    if(firstDir != legacyPath.end() && *firstDir == "Localization"){
        // this is a localization file, we need to add it to the localization list
        m_LocalizationFilesChanged = true;
        return true;
    }
    return false;
}

void ChairMerger::CopyChairloaderPatchFiles() {
    if(fs::exists(m_ChairloaderPatchPath)){
        fs::copy(m_ChairloaderPatchPath, m_OutputPath, fs::copy_options::recursive |  fs::copy_options::overwrite_existing);
    }
}

void ChairMerger::SetDeployStep(DeployStep step) {
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_DeployStep = step;
}

void ChairMerger::SetDeployPhase(DeployPhase phase) {
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_DeployPhase = phase;
}

void ChairMerger::SetDeployFailed(std::string error) {
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_bDeployFailed = true;
    m_DeployError = error;
}

void ChairMerger::ClearDeployFailed() {
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    m_bDeployFailed = false;
    m_DeployError.clear();
}

DeployStep ChairMerger::GetDeployStep() {
    return m_DeployStep;
}

DeployPhase ChairMerger::GetDeployPhase() {
    return m_DeployPhase;
}

bool ChairMerger::DeployFailed() {
    return m_bDeployFailed;
}

std::string ChairMerger::GetFailedDeployMessage() {
    return m_DeployError;
}

void ChairMerger::LoadPatchFileChecksums() {
    m_LevelFileChecksums.clear();
    m_LocalizationFileChecksums.clear();
    pugi::xml_document doc;

    auto result = doc.load_file("patchChecksums.xml");
    if(!result){
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load patch checksums file");
        return;
    }
    auto root = doc.first_child();
    for(auto &child : root.children()){
        std::string path = child.attribute("path").value();
        std::string hash = child.attribute("hash").value();
        std::string type = child.attribute("type").value();
        if(type == "level"){
            m_LevelFileChecksums.emplace_back(path, path, hash);
        } else if (type == "localization"){
            m_LocalizationFileChecksums.emplace_back(path, path, hash);
        } else {
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Invalid patch checksum type %s", type);
        }
    }
}

bool ChairMerger::isFileChanged(FileChecksum file) {
    for(auto& levelChecksum : m_LevelFileChecksums){
        if(levelChecksum.path == file.path){
            if(levelChecksum.checksum == file.checksum){
                return false;
            }
        }
    }
    for(auto& localizationChecksum : m_LocalizationFileChecksums){
        if(localizationChecksum.path == file.path){
            if(localizationChecksum.checksum == file.checksum){
                return false;
            }
        }
    }
    return true;
}



void ChairMerger::PackLevelFiles() {
    try {
        fs::remove_all(m_LevelOutputPath);
        fs::create_directories(m_LevelOutputPath);
    } catch (fs::filesystem_error &e) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not clear level output directory");
        return;
    }
    if(CheckLevelPacksChanged() || m_LevelFilesChanged){
        ChairManager::Get().log(severityLevel::debug, "ChairMerger: Level files have changed, repacking");
        // level files have changed, repack the level files, we just need to check which ones are changed
        for(auto& changedPack: m_ChangedLevelPacks){
            // this is a relative path to the level pack, we need to remove the filename so we can find the level directory
            auto levelPath = changedPack.parent_path();
            m_MergeThreadPool->enqueue([levelPath]{
                try {
                    // create the level directory in the level output path
                    fs::create_directories(m_LevelOutputPath / levelPath);
                    // copy over the level directory to the level output path
                    fs::copy(m_PreyFilePath / "Levels" / levelPath, m_LevelOutputPath / levelPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    // then copy over the output that we merged or copied into
                    fs::copy(m_OutputPath / "Levels" / levelPath, m_LevelOutputPath / levelPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    // then we must pack the level directory
                    PackFolder(m_LevelOutputPath / levelPath / "level", m_LevelOutputPath / levelPath / "level.pak");
                    // remove the "level" folder from the level output path
                    fs::remove_all(m_LevelOutputPath / levelPath / "level");
                    // remove the folder from the output path
                    fs::remove_all(m_OutputPath / "Levels" / levelPath);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Error merging level pack %s: %s", levelPath.string(), e.what());
                }
            });
        }
        m_MergeThreadPool->wait();
    }
}

void ChairMerger::PackLocalizationFiles() {
    try{
        fs::remove_all(m_LocalizationOutputPath);
        fs::create_directories(m_LocalizationOutputPath);
    } catch (fs::filesystem_error &e) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not clear localization output directory");
        return;
    }
    if(CheckLocalizationPacksChanged() || m_LocalizationFilesChanged){
        ChairManager::Get().log(severityLevel::debug, "ChairMerger: Localization files have changed, repacking");
        // localization files have changed, repack the localization files, we just need to check which ones are changed
        for(auto& changedPack: m_ChangedLocalizationPacks){
            // this is a relative path to the localization pack, we need to remove the filename so we can find the localization directory
            auto localizationPath = changedPack.parent_path();
            m_MergeThreadPool->enqueue([localizationPath]{
                try {
                    // create the localization directory in the localization output path
                    fs::create_directories(m_LocalizationOutputPath / localizationPath);
                    // copy over the localization directory to the localization output path
                    fs::copy(m_PreyFilePath / "Localization" / localizationPath, m_LocalizationOutputPath / localizationPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    // then copy over the output that we merged or copied into
                    fs::copy(m_OutputPath / "Localization" / localizationPath, m_LocalizationOutputPath / localizationPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                    // then we must pack the localization directory
                    PackFolder(m_LocalizationOutputPath / localizationPath / "localization", m_LocalizationOutputPath / localizationPath / "localization.pak");
                    // remove the "localization" folder from the localization output path
                    fs::remove_all(m_LocalizationOutputPath / localizationPath / "localization");
                    // remove the folder from the output path
                    fs::remove_all(m_OutputPath / "Localization" / localizationPath);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Error merging localization pack %s: %s", localizationPath.string(), e.what());
                }
            });
        }
        m_MergeThreadPool->wait();
    }
}

void ChairMerger::PackMainPatch() {

}

bool ChairMerger::CheckLevelPacksChanged() {
    m_ChangedLevelPacks.clear();
    for(auto& levelPack : m_LevelFileChecksums){
        auto existingFile = m_LevelFilesPath / levelPack.relativePath;
        auto checksum = FileChecksum(existingFile, levelPack.relativePath);
        if(checksum.checksum != levelPack.checksum){
            m_ChangedLevelPacks.emplace_back(levelPack.relativePath);
        } else if(fs::exists(m_OutputPath / "Levels" / levelPack.relativePath.parent_path())){
            m_ChangedLevelPacks.emplace_back(levelPack.relativePath);
        }
    }
    return !m_ChangedLevelPacks.empty();
}

bool ChairMerger::CheckLocalizationPacksChanged() {
    m_ChangedLocalizationPacks.clear();
    for(auto& localizationPack : m_LocalizationFileChecksums){
        auto existingFile = m_LocalizationFilesPath / localizationPack.relativePath;
        auto checksum = FileChecksum(existingFile, localizationPack.relativePath);
        if(checksum.checksum != localizationPack.checksum){
            m_ChangedLocalizationPacks.emplace_back(localizationPack.relativePath);
        } else if(fs::exists(m_OutputPath / "Localization" / localizationPack.relativePath.parent_path())){
            m_ChangedLocalizationPacks.emplace_back(localizationPack.relativePath);
        }
    }
}

bool ChairMerger::PackFolder(fs::path folder, fs::path output) {
    STARTUPINFOW ChairloaderStartupInfo = {sizeof(ChairloaderStartupInfo)};
    PROCESS_INFORMATION ChairloaderProcessInfo;
    fs::path commandRaw = L"7za.exe a " + output.wstring() + L" -tzip " + folder.wstring() + L"\\*";
    std::wstring command = commandRaw.wstring();
    command.resize(commandRaw.wstring().size() + 1000);
    if(CreateProcessW(nullptr, command.data(), nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &ChairloaderStartupInfo, &ChairloaderProcessInfo)){
        WaitForSingleObject(ChairloaderProcessInfo.hProcess, INFINITE);
        CloseHandle(ChairloaderProcessInfo.hProcess);
        CloseHandle(ChairloaderProcessInfo.hThread);
        return true;
    } else {
        return false;
    }
}



