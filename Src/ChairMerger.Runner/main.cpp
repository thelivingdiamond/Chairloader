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

static std::string logLevelToString(int level) {
    switch(level) {
        case 0:
            return "trace";
        case 1:
            return "debug";
        case 2:
            return "info";
        case 3:
            return "warning";
        case 4:
            return "error";
        case 5:
            return "fatal";
        default:
            return "unknown";
    }
}

static void LogCallback(int verbosity, const char* msg, size_t msgLen) {
    std::string_view msgView(msg, msgLen);
    // print it out like [info] : message
    std::cout << "[" << logLevelToString(verbosity) << "] : " << msgView << std::endl;
}

static void Log(int verbosity, const std::string msg) {
    LogCallback(verbosity, msg.c_str(), msg.size());
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

    Log(2, "Awaiting json parameters...");

    boost::json::value json;
    std::cin >> json;

    if(json == nullptr) {
        Log(5, "Failed to read json parameters");
        return 1;
    }

    Log(2, "Received json parameters");

    params.mergerFiles = json.at("mergerFiles").as_string().c_str();
    params.preyFiles = json.at("preyFiles").as_string().c_str();
    params.outputRoot = json.at("outputRoot").as_string().c_str();
    params.gamePath = json.at("gamePath").as_string().c_str();

    if(json.as_object().contains("mods")) {
        for(auto& item : json.at("mods").as_array()) {
            ChairMergerMod mod{};
            mod.dataPath = item.at("dataPath").as_string().c_str();
            if(item.as_object().contains("configPath")){
                mod.configPath = item.at("configPath").as_string().c_str();
            } else {
                mod.configPath = nullptr;
            }
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

    params.settings = settings;

    Log(2, "Beginning Merging");
    try {
        bool success = ChairMerger_RunMerging(&params);
        if(!success) {
            Log(5, "ChairMerger failed to run successfully");
            return 1;
        }

        Log(2, "ChairMerger ran successfully");
        return 0;
    } catch (std::exception& e) {
        Log(5, "ChairMerger failed to run successfully" + std::string(e.what()));
        return 1;
    }
}

