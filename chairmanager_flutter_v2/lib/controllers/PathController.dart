import 'dart:io';

import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/PreyVersion.dart';
import 'package:chairmanager_flutter_v2/storage/StorageMixin.dart';
import 'package:get/get.dart';

const String _STEAM_GAME_BIN_DIR = "Binaries\\Danielle\\x64\\Release";
const String _STEAM_GAME_EXE_PATH = "Binaries\\Danielle\\x64\\Release\\Prey.exe";
const String _STEAM_GAME_DLL_PATH = "Binaries\\Danielle\\x64\\Release\\PreyDll.dll";
const String _STEAM_GAME_DLL_PDB_PATH = "Binaries\\Danielle\\x64\\Release\\PreyDll.pdb";
const String _STEAM_GAME_DLL_BACKUP_PATH = "Binaries\\Danielle\\x64\\Release\\PreyDll.dll.chairloader_backup";

const String _EPIC_GAME_BIN_DIR = "Binaries\\Danielle\\x64-Epic\\Release";
const String _EPIC_GAME_EXE_PATH = "Binaries\\Danielle\\x64-Epic\\Release\\Prey.exe";
const String _EPIC_GAME_DLL_PATH = "Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.dll";
const String _EPIC_GAME_DLL_PDB_PATH = "Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.pdb";
const String _EPIC_GAME_DLL_BACKUP_PATH = "Binaries\\Danielle\\x64-Epic\\Release\\PreyDll.dll.chairloader_backup";

const String _GOG_GAME_BIN_DIR = "Binaries\\Danielle\\x64\\Release";
const String _GOG_GAME_EXE_PATH = "Binaries\\Danielle\\x64\\Release\\Prey.exe";
const String _GOG_GAME_DLL_PATH = "Binaries\\Danielle\\x64\\Release\\PreyDll.dll";
const String _GOG_GAME_DLL_PDB_PATH = "Binaries\\Danielle\\x64\\Release\\PreyDll.pdb";
const String _GOG_GAME_DLL_BACKUP_PATH = "Binaries\\Danielle\\x64\\Release\\PreyDll.dll.chairloader_backup";

const String _MICRO_GAME_BIN_DIR = "Binaries\\Danielle\\Gaming.Desktop.x64\\Release";
const String _MICRO_GAME_EXE_PATH = "Binaries\\Danielle\\Gaming.Desktop.x64\\Release\\Prey.exe";
const String _MICRO_GAME_DLL_PATH = "Binaries\\Danielle\\Gaming.Desktop.x64\\Release\\PreyDll.dll";
const String _MICRO_GAME_DLL_PDB_PATH = "Binaries\\Danielle\\Gaming.Desktop.x64\\Release\\PreyDll.pdb";
const String _MICRO_GAME_DLL_BACKUP_PATH = "Binaries\\Danielle\\Gaming.Desktop.x64\\Release\\PreyDll.dll.chairloader_backup";

const String _CHAIRLOADER_BIN_SRC_PATH_STR = "Release";

class PathController extends GetxController  with TalkerMixin, StorageMixin {
  var preyPath = "".obs;
  var preyVersion = PreyVersion.Steam.obs;

  var dataPath = "".obs;

  final String chairloaderDllName = "Chairloader.dll";

  final String chairmergerExeName = "ChairMerger.Runner.exe";

  final String dllPatcherExeName = "DllPatcher.exe";

  final String preditorExeName = "Preditor.exe";

  final List<String> requiredChairloaderBinaries = [
    "Chairloader.dll",
    "mswsock.dll"
  ];

  final List requiredChairloaderDirectories = [
    "Mods",
    "Mods\\Legacy",
    "Mods\\config",
  ];

  final List requiredGameDirectories = [
    "Engine",
    "GameSDK",
  ];

  final List requiredGameFiles = [];


  Future<void> init() async {
    preyPath.value = await storage.getOrInit<String>("preyPath", "");
    final versionString = await storage.getOrInit<String>("preyVersion", "Steam");
    preyVersion.value = PreyVersion.values.firstWhere((e) => e.name == versionString, orElse: () => PreyVersion.Steam);
    dataPath.value = await storage.getOrInit<String>("dataPath", ".\\Data"); // probably just for debugging/testing where the data path is not in the correct location
    update();
  }

  void setPreyPath(String path) {
    preyPath.value = path;
    storage.set("preyPath", path);
    update();
  }

  void setPreyVersion(PreyVersion version) {
    preyVersion.value = version;
    storage.set("preyVersion", version.name);
    update();
  }

  void setDataPath(String path) {
    dataPath.value = path;
    storage.set("dataPath", path);
    update();
  }


  String get binaryPath {
    switch (preyVersion.value) {
      case PreyVersion.Steam:
        return "${preyPath.value}\\$_STEAM_GAME_BIN_DIR";
      case PreyVersion.GOG:
        return "${preyPath.value}\\$_GOG_GAME_BIN_DIR";
      case PreyVersion.Epic:
        return "${preyPath.value}\\$_EPIC_GAME_BIN_DIR";
      case PreyVersion.MicrosoftStore:
        return "${preyPath.value}\\$_MICRO_GAME_BIN_DIR";
      default:
        return "";
    }
  }

  String get preyExePath {
    switch (preyVersion.value) {
      case PreyVersion.Steam:
        return "${preyPath.value}\\$_STEAM_GAME_EXE_PATH";
      case PreyVersion.GOG:
        return "${preyPath.value}\\$_GOG_GAME_EXE_PATH";
      case PreyVersion.Epic:
        return "${preyPath.value}\\$_EPIC_GAME_EXE_PATH";
      case PreyVersion.MicrosoftStore:
        return "${preyPath.value}\\$_MICRO_GAME_EXE_PATH";
      default:
        return "";
    }
  }

  String get preyDllPath {
    switch (preyVersion.value) {
      case PreyVersion.Steam:
        return "${preyPath.value}\\$_STEAM_GAME_DLL_PATH";
      case PreyVersion.GOG:
        return "${preyPath.value}\\$_GOG_GAME_DLL_PATH";
      case PreyVersion.Epic:
        return "${preyPath.value}\\$_EPIC_GAME_DLL_PATH";
      case PreyVersion.MicrosoftStore:
        return "${preyPath.value}\\$_MICRO_GAME_DLL_PATH";
      default:
        return "";
    }
  }

  String get preyDllPdbPath {
    switch (preyVersion.value) {
      case PreyVersion.Steam:
        return "${preyPath.value}\\$_STEAM_GAME_DLL_PDB_PATH";
      case PreyVersion.GOG:
        return "${preyPath.value}\\$_GOG_GAME_DLL_PDB_PATH";
      case PreyVersion.Epic:
        return "${preyPath.value}\\$_EPIC_GAME_DLL_PDB_PATH";
      case PreyVersion.MicrosoftStore:
        return "${preyPath.value}\\$_MICRO_GAME_DLL_PDB_PATH";
      default:
        return "";
    }
  }

  String get preyDllBackupPath {
    switch (preyVersion.value) {
      case PreyVersion.Steam:
        return "${preyPath.value}\\$_STEAM_GAME_DLL_BACKUP_PATH";
      case PreyVersion.GOG:
        return "${preyPath.value}\\$_GOG_GAME_DLL_BACKUP_PATH";
      case PreyVersion.Epic:
        return "${preyPath.value}\\$_EPIC_GAME_DLL_BACKUP_PATH";
      case PreyVersion.MicrosoftStore:
        return "${preyPath.value}\\$_MICRO_GAME_DLL_BACKUP_PATH";
      default:
        return "";
    }
  }

  // non version dependent game paths
  // TODO: this will need to change with mooncrash support

  String get levelsDirPath {
    return "${preyPath.value}\\GameSDK\\Levels\\Campaign";
  }

// non version dependent paths (for chairloader)
  String get modDirPath {
    return "${preyPath.value}\\Mods";
  }

  String get modLegacyDirPath {
    return "${preyPath.value}\\Mods\\Legacy";
  }

  String get modConfigPath {
    return "${preyPath.value}\\Mods\\config";
  }

  String get chairloaderInstallFilePath{
    return Directory("$dataPath\\$_CHAIRLOADER_BIN_SRC_PATH_STR").absolute.path;
  }

  String get chairloaderPatchPath{
    return Directory("$dataPath\\ChairloaderPatch").absolute.path;
  }

  Future<(bool, String?, String?)> validateGamePath(String? path) async {
    bool valid = false;
    String? error;

    if(path == null){
      return (false, "Game Path is empty", null);
    }

    (valid, error) = await validateExePath(path);
    if (!valid) {
      return (false, error, null);
    }


    // now get the game path from the selected path
    var gamePath = exePathToGamePath(path);

    if (gamePath == null) {
      return (false, "Game Path could not be found in the selected path", null);
    }

    (valid, error) = await validateGameFiles(gamePath);
    if (!valid) {
      return (false, error, null);
    }


    return (true, null, gamePath);
  }

  Future<PreyVersion> deduceGameVersion(String path) async {
    if (await File('$path\\$_STEAM_GAME_EXE_PATH').exists()){
      return PreyVersion.Steam;
    } else if (await File('$path\\$_GOG_GAME_EXE_PATH').exists()){
      return PreyVersion.GOG;
    } else if (await File('$path\\$_EPIC_GAME_EXE_PATH').exists()){
      return PreyVersion.Epic;
    } else if (await File('$path\\$_MICRO_GAME_EXE_PATH').exists()){
      return PreyVersion.MicrosoftStore;
    } else {
      return PreyVersion.Unknown;
    }
  }

  String get chairMergerExePath {
    return Directory("$dataPath\\$chairmergerExeName").absolute.path;
  }

  String get dllPatcherExePath {
    return Directory("$dataPath\\$dllPatcherExeName").absolute.path;
  }

  String get dllVersionsXmlPath {
    return Directory("$dataPath\\Versions\\Versions.xml").absolute.path;
  }

  String get preditorExePath {
    return Directory("$dataPath\\$preditorExeName").absolute.path;
  }

  String get runtimeDataPath {
    // this one is always relative to the current working directory
    return Directory("Config").absolute.path;
  }

  String get logsPath {
    return Directory("$runtimeDataPath\\Logs").absolute.path;
  }

  String get preyFilesPath {
    return Directory("$dataPath\\PreyFiles").absolute.path;
  }

  String getModDataPath(String modName, bool isLegacy) {
    return isLegacy ? "$modLegacyDirPath\\$modName" : "$modDirPath\\$modName\\Data";
  }

  String getModConfigPath(String modName, bool isLegacy) {
    return isLegacy ? "" : "$modConfigPath\\$modName.xml";
  }

  Future<(bool, String?)> validateExePath(String path) async{
    //"C:\Program Files (x86)\Steam\steamapps\common\Prey\Binaries\Danielle\x64\Release\Prey.exe"
    // check if it's empty
    if(path.isEmpty){
      return (false, "Executable File Path is empty");
    }

    if(! await File(path).exists()){
      return (false, "Executable File does not exist");
    }
    // check if it ends with prey.exe
    if(!path.endsWith("Prey.exe")){
      return (false, "Executable File is not Prey.exe");
    }

    return (true, null);
  }

  Future<(bool, String?)> validateGameFiles(String path) async {
    // check if it's empty
    if(path.isEmpty){
      return (false, "Game Path is empty");
    }
    if(! await Directory(path).exists()){
      return (false, "Game Path does not exist");
    }

    var gameVersion = await deduceGameVersion(path);
    if(gameVersion == PreyVersion.Unknown){
      return (false, "Game Version is unknown");
    }

    //TODO: check vital files exist
    for(var file in requiredGameFiles){
      if(! await File("$path\\$file").exists()){
        return (false, "Path is missing required file: $file");
      }
    }

    for (var directory in requiredGameDirectories) {
      if (! await Directory("$path\\$directory").exists()) {
        return (false, "Path is missing required directory: $directory");
      }
    }

    return (true, null);
  }

  String? exePathToGamePath(String exePath){
    File exeFile = File(exePath);
    //Binaries\Danielle\x64\Release\Prey.exe
    // well, I guess this works
    var parentDir = exeFile.parent.parent.parent.parent.parent;
    return parentDir.path;
  }

}