//
// Created by theli on 3/26/2023.
//

#include <regex>
#include "ChairMerger.h"
#include "ChairManager.h"
#include <gtest/gtest.h>
#include <boost/algorithm/string.hpp>
#include "XMLMerger2.h"
#include "ZipUtils.h"
#include "HashUtils.h"
#include <LuaUtils.h>

// resolve static variable m_RandomGenerator
std::mt19937 ChairMerger::m_RandomGenerator;

void ChairMerger::PreMerge() {
    SetDeployPhase(DeployPhase::PreMerge);
    // make sure mod configs are loaded
    // clear out the output directory
    SetDeployStep(DeployStep::RemovingOldOutput);
    try{
        fs::remove_all(m_OutputPath);
        fs::create_directories(m_OutputPath);
    } catch (fs::filesystem_error& e){
        ChairManager::Get().overlayLog(severityLevel::error, "Failed to clear output directory: %s", std::string(e.what()));
        SetDeployFailed("Failed to clear output directory: " + std::string(e.what()));
        return;
    }
    // Copy over the chairloader patch files
    SetDeployStep(DeployStep::CopyingBaseFiles);
    CopyChairloaderPatchFiles();
    if(m_bDeployFailed)
        return;
    // load the patch file checksums
    SetDeployStep(DeployStep::LoadingPatchChecksums);
    LoadPatchFileChecksums();
}

void ChairMerger::Merge() {
    if(m_bForceVanillaPack)
        return;
    // merge the legacy mods
    SetDeployPhase(DeployPhase::Merge);
    SetDeployStep(DeployStep::MergingLegacyMods);
    for(auto& legacyMod : ChairManager::Get().GetLegacyMods()){
        ProcessLegacyMod(legacyMod);
        m_MergeThreadPool->wait();
        ChairManager::Get().log(severityLevel::trace, "Finished merging legacy mod: %s", legacyMod);
    }

    if(m_bDeployFailed)
        return;

    // merge the registered mods
    SetDeployStep(DeployStep::MergingMods);
    for(auto& mod : ChairManager::Get().GetMods()){
        if(mod.enabled) {
            ProcessMod(std::make_shared<Mod>(mod));
            m_MergeThreadPool->wait();
            ChairManager::Get().log(severityLevel::trace, "Finished merging mod: %s", mod.modName);
        }
    }
}

void ChairMerger::PostMerge() {
    SetDeployPhase(DeployPhase::PostMerge);
    // Post merge tasks

    // Pack and Copy the level files
    SetDeployStep(DeployStep::PackingLevelPatches);
    PackLevelFiles();
    if(m_bDeployFailed)
        return;
    SetDeployStep(DeployStep::PackingLocalizationPatches);
    PackLocalizationFiles();
    if(m_bDeployFailed)
        return;
    SetDeployStep(DeployStep::PackingMainPatch);
    PackMainPatch();
    if(m_bDeployFailed)
        return;
    SetDeployStep(DeployStep::CleaningUp);
}
//! Function to resolve all attribute wildcards in an xml document
void ChairMerger::ResolveFileWildcards(pugi::xml_node docNode, std::string modName) {

    auto configVariables = ChairManager::Get().GetConfigManager()->getModSpaceBooleanVariables(modName);
    // start the recursive descent on the root node
    auto configNode = ChairManager::Get().GetConfigManager()->getModConfig(modName).configNode;

    // create a new lua state
    lua_State* L = luaL_newstate();
    // load the lua libraries
    luaL_openlibs(L);

    luabridge::getGlobalNamespace(L).addFunction("IsModEnabled", &ChairMerger::IsModEnabled);

    // add random function
    luabridge::getGlobalNamespace(L).addFunction("Random", &ChairMerger::Random);

    // add random Float function
    luabridge::getGlobalNamespace(L).addFunction("RandomFloat", &ChairMerger::RandomFloat);

    // add the config variables to the lua state
    for(auto& mod :ChairManager::Get().GetMods()){
        auto config = ChairManager::Get().GetConfigManager()->getModConfig(mod.modName);
        LuaUtils::AddXmlNodeAsVariables(L, config.configNode, mod.modName);
    }
    //TODO: add local mod config variables in a way to ignore g.modName

    LuaUtils::AddXmlNodeAsVariables(L, configNode, modName, false);

    ResolveAttributeWildcards(docNode, modName, L);

    // close the lua state
    lua_close(L);

}

//! Recursive function to descend an xml node tree and find all attribute wildcards
void ChairMerger::ResolveAttributeWildcards(pugi::xml_node node, std::string modName, void *L_) {
    auto L = (lua_State*)L_;
    // iterate over all attributes
    for (auto &attribute : node.attributes()) {
        auto wildcard = std::make_shared<AttributeWildcard>();
        wildcard->attribute = attribute;
        wildcard->mod_name = modName;
        if(GetAttributeWildcardValue(wildcard, L))
            attribute.set_value(wildcard->match_value.c_str());

    }

    // iterate over all child nodes
    for (auto &childNode : node.children()) {
        // recursively descend the tree
        ResolveAttributeWildcards(childNode, modName, L);
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
bool ChairMerger::GetAttributeWildcardValue(std::shared_ptr<AttributeWildcard> wildcard, void *L_) {
    auto L = (lua_State*)L_;
    if(std::string(wildcard->attribute.value()).find("{{") != std::string::npos && std::string(wildcard->attribute.value()).find("}}") != std::string::npos) {
        // Regex to determine if the attribute value is a wildcard
        std::regex re(R"(\{\{(.*)\}\})");
        std::smatch match;
        std::string value = wildcard->attribute.value();
        if(std::regex_search(value, match, re)) {
            if(match.ready()) {
                std::string wildcardName;
                wildcardName = match[1].str();

                // setup the lua buffer
                luaL_Buffer b;
                luaL_buffinit(L, &b);
                luaL_addstring(&b,LuaUtils::GetExpressionCodeString(wildcardName).c_str());
                luaL_addstring(&b, LuaUtils::SandboxString.c_str());
                luaL_pushresult(&b);
                int code = luaL_dostring(L, lua_tostring(L, -1));
                bool success = LuaUtils::report_errors(L, code);
                std::string result;
                if(success){
                    lua_getglobal(L, "result");
                    if (luabridge::isInstance<bool>(L, -1)) {
                        result = luabridge::Stack<bool>::get(L, -1) ? "true" : "false";
                        wildcard->match_value = result;
                        wildcard->has_match_value = true;
                    } else if (luabridge::isInstance<float>(L, -1)) {
                        result = std::to_string(luabridge::Stack<float>::get(L, -1));
                        wildcard->match_value = result;
                        wildcard->has_match_value = true;
                    } else if (luabridge::isInstance<int>(L, -1)) {
                        result = std::to_string(luabridge::Stack<int>::get(L, -1));
                        wildcard->match_value = result;
                        wildcard->has_match_value = true;
                    } else if (luabridge::isInstance<std::string>(L, -1)) {
                        result = luabridge::Stack<std::string>::get(L, -1);
                        wildcard->match_value = result;
                        wildcard->has_match_value = true;
                    }  else if (luabridge::isInstance<unsigned int>(L, -1)) {
                        result = std::to_string(luabridge::Stack<unsigned int>::get(L, -1));
                        wildcard->match_value = result;
                        wildcard->has_match_value = true;
                    } else {
                        ChairManager::Get().log(severityLevel::error, "Error evaluating lua expression: %s", wildcardName.c_str());
                    }

                }
                else{
                    ChairManager::Get().log(severityLevel::error, "Error evaluating lua expression: %s", wildcardName.c_str());
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

void ChairMerger::CopyModDataFiles(fs::path sourcePath) {
    m_MergeThreadPool->enqueue([sourcePath] {
        RecursiveFileCopyBlacklist(sourcePath, m_OutputPath, {".xml"});
    });
}

void ChairMerger::RecursiveFileCopyBlacklist(fs::path source, fs::path destination, std::vector<std::string> exclusions) {
    if(fs::exists(source) && fs::is_directory(source)) {
        for(auto &file : fs::directory_iterator(source)) {
            if(fs::is_directory(file)) {
                RecursiveFileCopyBlacklist(file.path(), destination / file.path().filename(), exclusions);
            } else {
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

    if(!fs::exists(m_PrecacheFilesPath)){
        fs::create_directories(m_PrecacheFilesPath);
    }

    if(!fs::exists(m_OutputPath)){
        fs::create_directory(m_OutputPath);
    }
    unsigned int numThreads = std::thread::hardware_concurrency();
    m_MergeThreadPool = std::make_unique<ThreadPool>(numThreads);
    m_MergingPolicyDoc = std::make_unique<pugi::xml_document>();

    auto result = m_MergingPolicyDoc->load_file("MergingLibrary.xml");
    if(!result) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load MergingLibrary.xml");
    }

    m_RandomGenerator = std::mt19937(std::random_device()());
}

void ChairMerger::ProcessMod(std::shared_ptr<Mod> mod) {
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Processing mod %s", mod->modName.c_str());

    fs::path dataPath = m_ModPath / mod->modName / "Data";

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(dataPath);

    // Merge all XML files from the mod's Data folder
    RecursiveMergeXMLFiles(dataPath, mod->modName, false);
}

void ChairMerger::ProcessLegacyMod(std::string modName) {
    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Processing legacy mod %s", modName.c_str());

    fs::path dataPath = m_ModPath / "Legacy" / modName ;

    // Copy all files from the mod's Data folder to the output folder
    CopyModDataFiles(dataPath);

    // Merge all XML files from the mod's Data folder
    RecursiveMergeXMLFiles(dataPath, modName, true);
}


void ChairMerger::RecursiveMergeXMLFiles(const fs::path &source, std::string modName, bool isLegacy) {
    if(fs::exists(source) && fs::is_directory(source)) {
        for(auto &file : fs::directory_iterator(source)) {
            if(fs::is_directory(file)) {
                RecursiveMergeXMLFiles(file.path(), modName, isLegacy);
            } else {
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
    auto policy = GetFileMergingPolicy(relativePath, modName);

    // now we have the relative path to the file, we can use this to find the original file, and the base file in the output directory
    fs::path originalFile = m_PreyFilePath / relativePath;
    fs::path baseFile = m_OutputPath / relativePath;

    pugi::xml_document baseDoc, modDoc, originalDoc;
    auto parseTags = pugi::parse_default;
    if(policy.policy == MergingPolicy::identification_policy::match_spreadsheet){
        parseTags = pugi::parse_full;
    }

    pugi::xml_parse_result baseResult = baseDoc.load_file(baseFile.wstring().c_str(), parseTags);
    pugi::xml_parse_result modResult = modDoc.load_file(file.wstring().c_str(), parseTags);
    pugi::xml_parse_result originalResult = originalDoc.load_file(originalFile.wstring().c_str(), parseTags);

    if(!modResult) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not load mod file %s", file.u8string().c_str());
        return;
    }
    // resolve attribute wildcards on non legacy files
    if(!isLegacy)
        ResolveFileWildcards(modDoc.first_child(), modName);

    if(!originalResult){
        // this is a new file, we have to just copy it over, even if base exists
        fs::create_directories(baseFile.parent_path());
        fs::copy_file(file, baseFile, fs::copy_options::overwrite_existing);
        return;
    }

    //if we have an original result, we can actually do some merging
    if(policy.policy == MergingPolicy::identification_policy::overwrite || policy.policy == MergingPolicy::identification_policy::unknown){
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

void ChairMerger::CopyChairloaderPatchFiles() {
    if(fs::exists(m_ChairloaderPatchPath)){
        try {
            fs::copy(m_ChairloaderPatchPath, m_OutputPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        } catch (fs::filesystem_error &e) {
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy chairloader patch files: %s", e.what());
        }
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
        ChairManager::Get().overlayLog(severityLevel::error, "ChairMerger: Could not load patch checksums file");
        return;
    }
    auto root = doc.first_child();
    for(auto &child : root.children()){
        std::string path = child.attribute("path").value();
        std::string hash = child.attribute("hash").value();
        std::string type = child.attribute("type").value();
        if(type == "level"){
            m_LevelFileChecksums[path] = SHA256::fromString(hash);
        } else if (type == "localization"){
            m_LocalizationFileChecksums[path] = SHA256::fromString(hash);
        } else {
            ChairManager::Get().log(severityLevel::error, "ChairMerger: Invalid patch checksum type %s", type);
        }
    }
}



void ChairMerger::PackLevelFiles() {
    try {
        fs::remove_all(m_LevelOutputPath);
        fs::create_directories(m_LevelOutputPath);
    } catch (fs::filesystem_error &e) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not clear level output directory");
        SetDeployFailed("Could not clear level output directory");
        return;
    }
    if(CheckLevelPacksChanged()){
        std::atomic<bool> bFailure = false;
        SerializeLevelPacks();
        ChairManager::Get().log(severityLevel::debug, "ChairMerger: Level files have changed, repacking");
        // level files have changed, repack the level files, we just need to check which ones are changed
        for(auto& changedPack: m_ChangedLevelPacks){
            // this is a relative path to the level pack, we need to remove the filename so we can find the level directory
            const auto levelPath = changedPack.parent_path();
            const auto deployedHash = m_DeployedLevelFileChecksums[changedPack];
            const bool forcePack = m_bForceLevelPack;
            m_MergeThreadPool->enqueue([levelPath, deployedHash, forcePack, &bFailure]{
                try {
                    // create the level directory in the level output path
                    fs::create_directories(m_LevelOutputPath / levelPath);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not create level directory %s", (m_LevelOutputPath / levelPath).string());
                    bFailure = true;
                    return;
                }
                try {
                    // copy over the level directory to the level output path
                    fs::copy(m_PreyFilePath / "Levels" / levelPath, m_LevelOutputPath / levelPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy original level directory %s", (m_PreyFilePath / "Levels" / levelPath).string());
                    bFailure = true;
                    return;
                }
                try {
                    // then copy over the output that we merged or copied into
                    fs::copy(m_OutputPath / "Levels" / levelPath, m_LevelOutputPath / levelPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Could not copy level output directory %s, no mod modified this level.", (m_OutputPath / "Levels" / levelPath).string());
                }
                // now check if we need to continue to pack the level directory
                auto levelPakHashPath = m_LevelOutputPath / levelPath / "level";
                auto levelOutputChecksum = HashUtils::HashDirectory(levelPakHashPath);
                if(levelOutputChecksum == deployedHash && !forcePack){
                    // the level directory has not changed, we can skip packing it
                    ChairManager::Get().log(severityLevel::info, "ChairMerger: Level %s is up to date, skipping", levelPath.filename().u8string());
                    try {
                        // remove the "level" folder from the level output path
                        fs::remove_all(m_LevelOutputPath / levelPath / "level");
                        // remove the folder from the output path
                        fs::remove_all(m_OutputPath / "Levels" / levelPath);
                    } catch (fs::filesystem_error &e) {
                        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove level directory %s", (m_LevelOutputPath / levelPath / "level").string());
                    }
                    return;
                }
                try {
                    // then we must pack the level directory
                    ZipUtils::CompressFolder(m_LevelOutputPath / levelPath / "level", m_LevelOutputPath / levelPath / "level.pak", true);
                } catch (std::exception &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not pack level directory %s", (m_LevelOutputPath / levelPath / "level").string());
                    bFailure = true;
                }
                try {
                    // remove the "level" folder from the level output path
                    fs::remove_all(m_LevelOutputPath / levelPath / "level");
                    // remove the folder from the output path
                    fs::remove_all(m_OutputPath / "Levels" / levelPath);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove level directory %s", (m_LevelOutputPath / levelPath / "level").string());
                }
                try {
                    // copy the output folder to the game files folder
                    fs::copy(m_LevelOutputPath / levelPath, m_LevelFilesPath / levelPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy merged level pack %s", (m_LevelOutputPath / levelPath).string());
                    bFailure = true;
                    return;
                }
                ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished merging level pack %s", levelPath.string());
            });
        }
        m_MergeThreadPool->wait();
        if(bFailure){
            SetDeployFailed("Error merging level packs");
            return;
        }
        ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished merging all level packs");
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
    if(CheckLocalizationPacksChanged()){
        std::atomic<bool> bFailure = false;
        ChairManager::Get().log(severityLevel::debug, "ChairMerger: Localization files have changed, repacking");
        // localization files have changed, repack the localization files, we just need to check which ones are changed
        for(auto& changedPack: m_ChangedLocalizationPacks){
            // this is a relative path to the localization pack, we need to remove the filename so we can find the localization directory
            const auto localizationPath = changedPack.parent_path();
            const auto deployedLocalizationChecksum = m_DeployedLocalizationFileChecksums[changedPack];
            const bool forcePack = m_bForceLocalizationPack;
            m_MergeThreadPool->enqueue([localizationPath, changedPack, deployedLocalizationChecksum, forcePack, &bFailure]{
                // patch file path is XXXX_patch.pak
                // non-patch path is XXXX, so the filename needs to be changed and the extension removed
                fs::path patchFilePath = localizationPath / changedPack.filename();
                fs::path originalDirectoryPath = localizationPath / changedPack.filename().replace_extension("");
                // if the originalDirectoryPath has _patch, remove it
                if(originalDirectoryPath.filename().wstring().find(L"_patch") != std::string::npos){
                    originalDirectoryPath = originalDirectoryPath.parent_path() / originalDirectoryPath.filename().replace_extension("").string().substr(0, originalDirectoryPath.filename().string().find("_patch"));
                }
                try {
                    // create the localization directory in the localization output path
                    fs::create_directories(m_LocalizationOutputPath / localizationPath);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not create localization output directory %s", (m_LocalizationOutputPath / localizationPath).string());
                    bFailure = true;
                    return;
                }
                try {
                    // copy over the vanilla localization patch files to the localization output path
                    fs::copy(m_PreyFilePath / "Localization" / originalDirectoryPath, m_LocalizationOutputPath / originalDirectoryPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy original localization patch %s", (m_PreyFilePath / "Localization" / originalDirectoryPath).string());
                    bFailure = true;
                    return;
                }
                try {
                    // then copy over the output that we merged or copied into
                    fs::copy(m_OutputPath / "localization" / originalDirectoryPath, m_LocalizationOutputPath / originalDirectoryPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::debug, "ChairMerger: Could not copy localization output directory %s, no mod modified this pack.", (m_OutputPath / "localization" / originalDirectoryPath).string());
                }
                // now check if we need to continue to pack the level directory
                auto levelOutputChecksum = HashUtils::HashDirectory(m_LocalizationOutputPath / originalDirectoryPath);
                if(levelOutputChecksum == deployedLocalizationChecksum && !forcePack){
                    ChairManager::Get().log(severityLevel::info, "ChairMerger: Localization pack %s up to date, skipping", originalDirectoryPath.string());
                    try {
                        // remove the original folder from the localization output path
                        fs::remove_all(m_LocalizationOutputPath / localizationPath / originalDirectoryPath);
                        // remove the folder from the output path
                        fs::remove_all(m_OutputPath / "Localization" / localizationPath / originalDirectoryPath);
                    } catch (fs::filesystem_error &e) {
                        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove localization directory %s", (m_LocalizationOutputPath / localizationPath / "localization").string());
                    }
                    return;
                }
                try {
                    // then we must pack the localization directory
                    ZipUtils::CompressFolder(m_LocalizationOutputPath / localizationPath / originalDirectoryPath, m_LocalizationOutputPath / localizationPath / patchFilePath, true);
                } catch (std::exception &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not pack localization directory %s", (m_LocalizationOutputPath / localizationPath / "localization").string());
                    bFailure = true;
                }
                try {
                    // remove the original folder from the localization output path
                    fs::remove_all(m_LocalizationOutputPath / localizationPath / originalDirectoryPath);
                    // remove the folder from the output path
                    fs::remove_all(m_OutputPath / "Localization" / localizationPath / originalDirectoryPath);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove localization directory %s", (m_LocalizationOutputPath / localizationPath / "localization").string());
                }
                try {
                    // copy the output folder to the game files folder
                    // because this is localization we need to replace the patch_ files with the new ones
                    fs::copy(m_LocalizationOutputPath / localizationPath / patchFilePath, m_LocalizationFilesPath / localizationPath / patchFilePath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
                } catch (fs::filesystem_error &e) {
                    ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not copy merged localization pack %s", (m_LocalizationOutputPath / localizationPath).string());
                    bFailure = true;
                }
            });
        }
        m_MergeThreadPool->wait();
        ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished merging localization packs");
    }
}

void ChairMerger::PackMainPatch() {
    // at this point level and localization packs are packed and their files moved. We can now pack what is left in the output path
    auto deployedFileHash = HashUtils::HashUncompressedFile(m_PrecacheFilesPath / "patch_chairloader.pak");
    auto outputFileHash = HashUtils::HashDirectory(m_OutputPath);
    if(deployedFileHash == outputFileHash){
        ChairManager::Get().log(severityLevel::info, "ChairMerger: Main patch is up to date, skipping");
        return;
    }
    try {
        fs::remove(m_PrecacheFilesPath / "patch_chairloader.pak");
    } catch (fs::filesystem_error &e) {
        ChairManager::Get().log(severityLevel::error, "ChairMerger: Could not remove old patch file: %s", e.what());
        SetDeployFailed("Could not remove old patch file: " + std::string(e.what()));
        return;
    }
    ZipUtils::CompressFolder(m_OutputPath, m_PrecacheFilesPath / "patch_chairloader.pak", true);
    ChairManager::Get().log(severityLevel::trace, "ChairMerger: Finished packing main patch");
}

bool ChairMerger::CheckLevelPacksChanged() {
    m_ChangedLevelPacks.clear();
    for(auto& levelPack : m_LevelFileChecksums){
        m_MergeThreadPool->enqueue([levelPack, this](){
            auto existingFile = m_LevelFilesPath / levelPack.first;
            bool exists = fs::exists(existingFile);
            auto checksum = HashUtils::HashUncompressedFile(existingFile);
            m_DeployedLevelFileChecksums[levelPack.first] = checksum;
            if (checksum != levelPack.second || !fs::exists(existingFile) || m_bForceLevelPack) {
                AddChangedLevelPack(levelPack.first);
                ChairManager::Get().log(severityLevel::trace, "ChairMerger: Level pack %s has changed", levelPack.first.string());
            } else if (fs::exists(m_OutputPath / "Levels" / levelPack.first.parent_path())) {
                AddChangedLevelPack(levelPack.first);
            }
//            }
        });
    }
    m_MergeThreadPool->wait();
    return !m_ChangedLevelPacks.empty();
}

bool ChairMerger::CheckLocalizationPacksChanged() {
    m_ChangedLocalizationPacks.clear();
    for(auto& localizationPack : m_LocalizationFileChecksums){
        auto existingFile = m_LocalizationFilesPath / localizationPack.first;
        auto checksum = HashUtils::HashUncompressedFile(existingFile);
        m_DeployedLocalizationFileChecksums[localizationPack.first] = checksum;
//        auto checksum = SHA256::Digest();
//        if(false) {
        if (checksum != localizationPack.second || !fs::exists(existingFile) || m_bForceLocalizationPack) {
            AddChangedLocalizationPack(localizationPack.first);
            ChairManager::Get().log(severityLevel::debug, "ChairMerger: Localization pack %s has changed", localizationPack.first.string());
        } else if (fs::exists(m_OutputPath / "Localization" / localizationPack.first.parent_path())) {
            AddChangedLocalizationPack(localizationPack.first);
        }
//        }
    }
    return !m_ChangedLocalizationPacks.empty();
    
}

bool ChairMerger::PackFolder7ZipDeprecated(fs::path folder, fs::path output) {
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

void ChairMerger::AddChangedLevelPack(fs::path pack) {
    std::lock_guard<std::mutex> lock(m_ChangedLevelPacksMutex);
    m_ChangedLevelPacks.emplace_back(pack);
}

void ChairMerger::AddChangedLocalizationPack(fs::path pack) {
    std::lock_guard<std::mutex> lock(m_ChangedLocalizationPacksMutex);
    m_ChangedLocalizationPacks.emplace_back(pack);
}

void ChairMerger::AsyncDeploy() {
    ClearDeployFailed();
    auto now = std::chrono::high_resolution_clock::now();
    PreMerge();
    if(m_bDeployFailed)
        return;
    Merge();
    if(m_bDeployFailed)
        return;
    PostMerge();
    if(m_bDeployFailed)
        return;
    SetDeployPhase(DeployPhase::Done);
    SetDeployStep(DeployStep::Done);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - now);
    if(!m_bDeployFailed){
        ChairManager::Get().log(severityLevel::info, "ChairMerger: Finished merging in %.1f seconds", elapsed.count() / 1000.0f);
    }
    else {
        ChairManager::Get().log(severityLevel::info, "ChairMerger: Merge failed, %d seconds", elapsed.count() / 1000.0f);
    }
}

std::future<void> ChairMerger::LaunchAsyncDeploy() {
    return std::async(std::launch::async, &ChairMerger::AsyncDeploy, this);
}

void ChairMerger::SerializeLevelPacks() {
    for(auto& levelPack : m_ChangedLevelPacks){
        auto levelFolderPath = m_OutputPath / "Levels" / levelPack.parent_path() / "level";
        XMLMerger2::SerializeLevelEntityIDs(levelFolderPath);
    }
}

std::string ChairMerger::GetDeployPhaseString(DeployPhase phase) {
    return m_DeployPhaseStrings.at(phase);
}

std::string ChairMerger::GetDeployStepString(DeployStep step) {
    return m_DeployStepStrings.at(step);
}

std::string ChairMerger::GetDeployFailedMessage() {
    std::lock_guard<std::mutex> lock(m_DeployStateMutex);
    return m_DeployError;
}

bool ChairMerger::IsModEnabled(std::string modName) {
    return ChairManager::Get().IsModEnabled(modName);
}

int ChairMerger::Random(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(m_RandomGenerator);
}

float ChairMerger::RandomFloat(float min, float max) {
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(m_RandomGenerator);
}