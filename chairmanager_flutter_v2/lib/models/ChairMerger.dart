class ChairMergerParams {
  ChairMergerParams({required this.mergerFiles, required this.preyFiles, required this.outputRoot, required this.gamePath, required this.mods, required this.settings});

  final String mergerFiles;
  final String preyFiles;
  final String outputRoot;
  final String gamePath;
  final List<ChairMergerMod> mods;
  final ChairMergerSettings settings;

  Map<String, dynamic> toJson() {
    return {
      "mergerFiles": mergerFiles,
      "preyFiles": preyFiles,
      "outputRoot": outputRoot,
      "gamePath": gamePath,
      "mods": mods.map((e) => e.toJson()).toList(),
      "settings": settings.toJson(),
    };
  }
}


class ChairMergerSettings {
  ChairMergerSettings();

  bool forceLevelPack = false;
  bool forceLocalizationPack = false;
  bool forceMainPatchPack = false;
  bool forceVanillaPack = false;

  Map<String, dynamic> toJson() {
    return {
      "forceLevelPack": forceLevelPack,
      "forceLocalizationPack": forceLocalizationPack,
      "forceMainPatchPack": forceMainPatchPack,
      "forceVanillaPack": forceVanillaPack,
    };
  }
}

enum ChairMergerModType {
  none(value: 0),
  folder(value: 1), // unused currently
  native(value: 2),
  legacy(value: 3),;

  const ChairMergerModType({required this.value});
  final int value;
}

class ChairMergerMod {
  ChairMergerMod({required this.type, required this.modName, required this.dataPath, required this.configPath});

  final int type;
  final String modName;
  final String dataPath;
  final String? configPath;

  Map<String, dynamic> toJson() {
    Map<String, dynamic> map = {};
    map["type"] = type;
    map["modName"] = modName;
    map["dataPath"] = dataPath;
    if(configPath != null){
      map["configPath"] = configPath;
    }
    return map;
  }
}