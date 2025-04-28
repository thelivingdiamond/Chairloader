import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:get/get.dart';


class UninstallationDialogController extends GetxController {
  bool busy = false;

  bool removeModFolder = false;
  bool? dllPatchRestored;

  String? errorMessage;
  bool? success;

  void setRemoveModFolder(bool value) {
    removeModFolder = value;
    update();
  }

  final PathController pathController = Get.find();

  Future<void> uninstallChairloader() async {
    try {
      busy = true;
      update();
      await removeBinaries();
      await removePatchFile();
      await deleteModFolder();
      await restoreBackupDll();
      success = true;
    } catch(e) {
      errorMessage = e.toString();
      success = false;
    } finally {
      busy = false;
      update();
    }
  }

  Future<void> removeBinaries() async {
    for(var binary in pathController.requiredChairloaderBinaries) {
      await File("${pathController.binaryPath}\\$binary").delete();
    }
  }

  Future<void> removePatchFile() async {
    for(var patch in pathController.chairloaderDeployedPaks) {
      await File("${pathController.precachePath}\\$patch").delete();
    }
  }

  Future<void> deleteModFolder() async {
    if(removeModFolder) {
      try{
        await Directory(pathController.modDirPath).delete(recursive: true);
      } catch(e) {
        if (!(e is FileSystemException && e.osError?.errorCode == 2)) {
          rethrow;
        }
      }
    }
  }

  Future<void> restoreBackupDll() async {
    if(await File(pathController.preyDllBackupPath).exists()) {
      await File(pathController.preyDllPath).delete();
      await File(pathController.preyDllBackupPath).rename(pathController.preyDllPath);
    }
  }


}