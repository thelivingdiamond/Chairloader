//
// Created by theli on 11/3/2024.
//

#include <iostream>
#include <pugixml.hpp>
#include "ChairMerger/CApi.h"
#include "boost/json.hpp"

#include <Prey/CryCore/Platform/platform_impl.inl>

// TODO 2024-05-04: Remove this
struct ChairloaderGlobalEnvironment* gCL;


//void (*pfnLogCallback)(int verbosity, const char* msg, size_t msgLen);

static std::string logLevelToString(logLevel level) {
    switch(level) {
        case logLevel::normal:
            return "info";
        case logLevel::warning:
            return "warning";
        case logLevel::error:
            return "error";
        default:
            return "unknown";
    }
}

static void LogCallback(int verbosity, const char* msg, size_t msgLen) {
    std::string_view msgView(msg, msgLen);
    logLevel level = static_cast<logLevel>(verbosity);
    // print it out like [info] : message
    std::cout << "[" << logLevelToString(level) << "] : " << msgView << std::endl;
}


int main() {
    // read in a json string from stdin, which we will parse into a list of ChairMergerMods
    // example json format:
    /*
     * {
     *   "mergerFiles": "path/to/mergerFiles",
     *   "preyFiles": "path/to/preyFiles",
     *   "outputRoot": "path/to/outputRoot",
     *   "gamePath": "path/to/gamePath",
     *    "mods": [
     *      {
     *        "dataPath": "path/to/data",
     *        "configPath": "path/to/config",
     *        "modName": "modName",
     *        "type": 0
     *      }
     *    ],
     *    "settings": {
     *      "forceLevelPack": false,
     *      "forceLocalizationPack": false,
     *      "forceMainPatchPack": false,
     *      "forceVanillaPack": false,
     *    }
     * }
     * */

    ChairMergerParams params;
    std::vector<ChairMergerMod> mods;
    ChairMergerSettings settings;

    params.pfnLogCallback = LogCallback;

    std::cout << "awaiting json parameters..." << std::endl;

    boost::json::value json;
    std::cin >> json;

    params.mergerFiles = json.at("mergerFiles").as_string().c_str();
    params.preyFiles = json.at("preyFiles").as_string().c_str();
    params.outputRoot = json.at("outputRoot").as_string().c_str();
    params.gamePath = json.at("gamePath").as_string().c_str();

    if(json.as_object().contains("mods")) {
        for(auto& item : json.at("mods").as_array()) {
            ChairMergerMod mod{};
            mod.dataPath = item.at("dataPath").as_string().c_str();
            mod.configPath = item.at("configPath").as_string().c_str();
            mod.modName = item.at("modName").as_string().c_str();
            mod.type = boost::json::value_to<int>(item.at("type"));
            mods.push_back(mod);
        }
    }
    params.mods = mods.data();
    params.modCount = mods.size();

    if(json.as_object().contains("settings")) {
        auto settingsJson = json.at("settings").as_object();
        settings.m_bForceLevelPack = settingsJson.at("forceLevelPack").as_bool();
        settings.m_bForceLocalizationPack = settingsJson.at("forceLocalizationPack").as_bool();
        settings.m_bForceMainPatchPack = settingsJson.at("forceMainPatchPack").as_bool();
        settings.m_bForceVanillaPack = settingsJson.at("forceVanillaPack").as_bool();
    }

    bool success = ChairMerger_RunMerging(&params);
    if(!success) {
        std::cout << "Failed to run ChairMerger" << std::endl;
        return 1;
    }

    std::cout << "Successfully ran ChairMerger" << std::endl;
    return 0;
}