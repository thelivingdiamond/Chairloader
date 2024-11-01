import 'package:chairmanager_flutter_v2/logger/LogMixin.dart';
import 'package:chairmanager_flutter_v2/models/PreyVersion.dart';
import 'package:get/get.dart';
import 'package:shared_preferences/shared_preferences.dart';

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

class PathController extends GetxController  with LogMixin {
  var preyPath = "".obs;
  var preyVersion = PreyVersion.Steam.obs;


  Future<void> load() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    preyPath.value = prefs.getString("preyPath") ?? "";
    preyVersion.value = PreyVersion.values.firstWhereOrNull((version) => version.toString() == prefs.getString("preyVersion")) ?? PreyVersion.Steam;
    update();
  }

  void setPreyPath(String path) {
    preyPath.value = path;
    SharedPreferences.getInstance().then((prefs) {
      prefs.setString("preyPath", path);
    });
    update();
  }

  void setPreyVersion(PreyVersion version) {
    preyVersion.value = version;
    SharedPreferences.getInstance().then((prefs) {
      prefs.setString("preyVersion", version.toString());
    });
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
}