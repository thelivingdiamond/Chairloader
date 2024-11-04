class ChairMergerParams {
  ChairMergerParams({required this.mergerFiles, required this.preyFiles, required this.outputRoot, required this.gamePath, required this.mods, required this.settings});

  final String mergerFiles;
  final String preyFiles;
  final String outputRoot;
  final String gamePath;
  final List<ChairMergerMod> mods;
  final ChairMergerSettings settings;

}


class ChairMergerSettings {
  ChairMergerSettings({required this.forceLevelsRepack, required this.forceLocalizationRepack, required this.forceMainPatchRepack, required this.forceVanillaPack});

  final bool forceLevelsRepack;
  final bool forceLocalizationRepack;
  final bool forceMainPatchRepack;
  final bool forceVanillaPack;
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
  final String configPath;
}