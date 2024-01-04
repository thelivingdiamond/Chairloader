import 'package:fluent_ui/fluent_ui.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:get/get.dart';
import 'dart:io';

import './SettingsController.dart';

// this serves as a utility class that generates paths for important files
// and folders

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


class PathController extends GetxController {
  //TODO: see if we need any of these
  String get binaryPath {
    final settingsController = Get.find<SettingsController>();
    switch (settingsController.preyVersion.value) {
      case PreyVersion.Steam:
        return "${settingsController.preyPath.value}\\$_STEAM_GAME_BIN_DIR";
      case PreyVersion.GOG:
        return "${settingsController.preyPath.value}\\$_GOG_GAME_BIN_DIR";
      case PreyVersion.Epic:
        return "${settingsController.preyPath.value}\\$_EPIC_GAME_BIN_DIR";
      case PreyVersion.MicrosoftStore:
        return "${settingsController.preyPath.value}\\$_MICRO_GAME_BIN_DIR";
      default:
        return "";
    }
  }
  
 String get preyExePath {
    final settingsController = Get.find<SettingsController>();
    switch (settingsController.preyVersion.value) {
      case PreyVersion.Steam:
        return "${settingsController.preyPath.value}\\$_STEAM_GAME_EXE_PATH";
      case PreyVersion.GOG:
        return "${settingsController.preyPath.value}\\$_GOG_GAME_EXE_PATH";
      case PreyVersion.Epic:
        return "${settingsController.preyPath.value}\\$_EPIC_GAME_EXE_PATH";
      case PreyVersion.MicrosoftStore:
        return "${settingsController.preyPath.value}\\$_MICRO_GAME_EXE_PATH";
      default:
        return "";
    }
  }

  String get preyDllPath {
    final settingsController = Get.find<SettingsController>();
    switch (settingsController.preyVersion.value) {
      case PreyVersion.Steam:
        return "${settingsController.preyPath.value}\\$_STEAM_GAME_DLL_PATH";
      case PreyVersion.GOG:
        return "${settingsController.preyPath.value}\\$_GOG_GAME_DLL_PATH";
      case PreyVersion.Epic:
        return "${settingsController.preyPath.value}\\$_EPIC_GAME_DLL_PATH";
      case PreyVersion.MicrosoftStore:
        return "${settingsController.preyPath.value}\\$_MICRO_GAME_DLL_PATH";
      default:
        return "";
    }
  }

  String get preyDllPdbPath {
    final settingsController = Get.find<SettingsController>();
    switch (settingsController.preyVersion.value) {
      case PreyVersion.Steam:
        return "${settingsController.preyPath.value}\\$_STEAM_GAME_DLL_PDB_PATH";
      case PreyVersion.GOG:
        return "${settingsController.preyPath.value}\\$_GOG_GAME_DLL_PDB_PATH";
      case PreyVersion.Epic:
        return "${settingsController.preyPath.value}\\$_EPIC_GAME_DLL_PDB_PATH";
      case PreyVersion.MicrosoftStore:
        return "${settingsController.preyPath.value}\\$_MICRO_GAME_DLL_PDB_PATH";
      default:
        return "";
    }
  }

  String get preyDllBackupPath {
    final settingsController = Get.find<SettingsController>();
    switch (settingsController.preyVersion.value) {
      case PreyVersion.Steam:
        return "${settingsController.preyPath.value}\\$_STEAM_GAME_DLL_BACKUP_PATH";
      case PreyVersion.GOG:
        return "${settingsController.preyPath.value}\\$_GOG_GAME_DLL_BACKUP_PATH";
      case PreyVersion.Epic:
        return "${settingsController.preyPath.value}\\$_EPIC_GAME_DLL_BACKUP_PATH";
      case PreyVersion.MicrosoftStore:
        return "${settingsController.preyPath.value}\\$_MICRO_GAME_DLL_BACKUP_PATH";
      default:
        return "";
    }
  }

  // non version dependent game paths
  // TODO: this will need to change with mooncrash support

  String get levelsDirPath {
    final settingsController = Get.find<SettingsController>();
    return "${settingsController.preyPath.value}\\GameSDK\\Levels\\Campaign";
  }

// non version dependent paths (for chairloader)
  String get modDirPath {
    final settingsController = Get.find<SettingsController>();
    return "${settingsController.preyPath.value}\\Mods";
  }

  String get modLegacyDirPath {
    final settingsController = Get.find<SettingsController>();
    return "${settingsController.preyPath.value}\\Mods\\Legacy";
  }

  String get modConfigPath {
    final settingsController = Get.find<SettingsController>();
    return "${settingsController.preyPath.value}\\Mods\\config";
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

}