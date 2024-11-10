import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:get/get.dart';

class ChairloaderFileInstallController extends GetxController {

  final PathController pathController = Get.find();

  Future<void> installChairloaderFiles() async {
    // copy the files from the Release folder to the game directory
    for(var file in pathController.requiredChairloaderBinaries){
      final source = File("${pathController.chairloaderInstallFilePath}/$file");
      final destination = File("${pathController.binaryPath}/$file");
      await source.copy(destination.path);
    }

    for(var directory in pathController.requiredChairloaderDirectories){
      final dir = Directory("${pathController.preyPath}/$directory");
      if(!await dir.exists()){
        await dir.create();
      }
    }

    // now copy the default config file if it doesn't exist
    final configPath = "${pathController.modConfigPath}/Chairloader.xml";
    if(!await File(configPath).exists()){
      await File("${pathController.dataPath}/chairloader_default.xml").copy(configPath);
    }
  }

}