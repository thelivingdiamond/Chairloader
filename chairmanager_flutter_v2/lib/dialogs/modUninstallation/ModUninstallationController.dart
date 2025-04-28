import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:flutter/cupertino.dart';
import 'package:get/get.dart';

class ModUninstallationController extends GetxController {
  ModUninstallationController(this.selectedMod);
  final Mod selectedMod;

  PathController pathController = Get.find();
  ModController modController = Get.find();


  bool deleteConfigFiles = false;


  void setDeleteConfigFiles(bool value) {
    deleteConfigFiles = value;
    update();
  }

  Future<void> uninstallMod() async {
    late String modPath;
    if(selectedMod.isLegacy){
      modPath = '${pathController.modLegacyDirPath}\\${selectedMod.modName}\\';
    } else {
      modPath = '${pathController.modDirPath}\\${selectedMod.modName}\\';
    }
    final modDir = Directory(modPath);
    if(await modDir.exists()){
      await modDir.delete(recursive: true);
    }

    if(deleteConfigFiles){
      final configFile = File('${pathController.modConfigPath}\\${selectedMod.modName}.xml');
      if(await configFile.exists()){
        await configFile.delete();
      }
    }
    await modController.detectMods();
  }
}