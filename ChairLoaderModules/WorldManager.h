//
// Created by theli on 7/31/2022.
//
#include "ChairLoader/ChairloaderEnv.h"
struct pathEntry{
    uint64_t ID;
    std::string Name;
    std::string FlashID;
    uint64_t LocationA, LocationB;
};

struct airlockEntry{
    uint64_t ID;
    uint64_t Location;
    bool StartsLocked = true, StartsHidden = false;
};

struct locationInfo{
    uint64_t ID = 0;
    std::string Name;
    std::string Label;
    std::string LevelName = "";
    int StationMapIndex = 0;
    uint64_t Tip = 0;
    std::string ScreenshotPath = "";
    std::string RichPresence = "";
    int Cooldown = 0;
};

struct keycardEntry {
    uint64_t ID = 0;
    std::string Name, Label;
    uint64_t Location = 0;
};

struct keycodeEntry {
    uint64_t ID = 0;
    std::string Name, Label;
    uint64_t Location = 0;
    std::string Code;
};
struct characterInfo {
    uint64_t ID = 0;
    std::string Name, Label, JobTitle;
    uint64_t Group = 0;
    std::string VitalSigns;
    bool IsAlive, HasTrackingChip;
    uint64_t Voice = 0, Location = 0;
    std::string Password, Notes;
    bool IsPlaced;
    std::string Portrait;
};

class WorldManager {
public:
    WorldManager(ChairloaderGlobalEnvironment* env);
    void Draw();
    std::map<uint64_t, pathEntry> ArkStationPaths;
    std::map<uint64_t, airlockEntry> ArkStationAirlocks;
    std::map<uint64_t, locationInfo> ArkLocations;
    std::map<uint64_t, keycardEntry> ArkKeycards;
    std::map<uint64_t, keycodeEntry> ArkKeycodes;
    std::map<uint64_t, characterInfo> ArkCharacters;
    void Update();

    std::string GetModuleName();
private:
    std::map<std::string, uint64_t> ArkKeycardNames;
    std::map<std::string, uint64_t> ArkCharacterNames;
    XmlNodeRef stationAccessLibrary, locationLibrary, keycardLibrary, keycodeLibrary, characterLibrary;
    bool showLevelManagerWindow = false,
    showKeycardManagerWindow = false,
    showStationAccessManagerWindow = false,
    showKeycodeManagerWindow = false,
    showPasswordManagerWindow = false,
    showCharacterManagerWindow = false;
    ChairloaderGlobalEnvironment* gCLEnv;
    const std::string ModuleName = "WorldManager";

    void DrawLevelManagerWindow();
    void DrawKeycardManagerWindow();
    void DrawStationAccessManagerWindow();
    void DrawKeycodeManagerWindow();
    void DrawPasswordManagerWindow();
    void DrawCharacterManagerWindow();

    void loadStationAccessLibrary();
    void loadLocationLibrary();
    void loadKeycardLibrary();
    void loadKeycodeLibrary();
    void loadCharacterLibrary();

    void sortKeycardDisplayList();
    void sortCharacterDisplayList();

    void DrawMenuBar();

};
