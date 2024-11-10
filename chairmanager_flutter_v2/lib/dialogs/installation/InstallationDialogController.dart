import 'package:chairmanager_flutter_v2/controllers/ChairloaderFileInstallController.dart';
import 'package:chairmanager_flutter_v2/controllers/DeployController.dart';
import 'package:chairmanager_flutter_v2/controllers/DllPatcherController.dart';
import 'package:chairmanager_flutter_v2/controllers/ExtractionController.dart';
import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/models/PreyVersion.dart';
import 'package:get/get.dart';
import 'package:flutter/material.dart';

enum InstallationStep {
  welcome,
  selectGamePath,
  gameVersionCheck,
  confirm,
  installing,
}

enum InstallationProgress{
  patchGame,
  extractFiles,
  installChairloaderFiles,
  deployChairloaderFiles,
  finish,
}

class InstallationDialogController extends GetxController {

  int currentPage = 0;
  final int pageCount;
  bool installationInProgress = false;
  InstallationProgress currentProgress = InstallationProgress.patchGame;
  bool isError = false;
  String errorMessage = "";

  // game path Selection
  String? gamePath;
  bool gamePathValid = false;
  String? gamePathError = "";
  PreyVersion? gameVersion;
  bool gamePathOperationInProgress = false;

  InstallationDialogController({required this.pageCount});
  TextEditingController gamePathController = TextEditingController();
  final PathController pathController = Get.find();
  final DllPatcherController dllPatcherController = Get.find();
  final ExtractionController extractionController = Get.find();
  final DeployController deployController = Get.find();
  final ChairloaderFileInstallController chairloaderFileInstallController = Get.find();

  void nextPage() {
    currentPage++;
    if(currentPage == InstallationStep.installing.index){
      installChairloader();
    }
    update();
  }

  VoidCallback? get nextPageFunction {
    if(currentPage >= pageCount - 1){
      return null;
    }
    if(currentPage == InstallationStep.selectGamePath.index && !gamePathValid){
      return null;
    }

    if(currentPage == InstallationStep.gameVersionCheck.index &&
        dllPatcherController.currentDllVersion == null
    || dllPatcherController.currentDllVersion?.isOutdated == true){
      return null;
    }

    if(currentPage == InstallationStep.installing.index){
      return null;
    }

    return nextPage;
  }

  void previousPage() {
    currentPage--;
    update();
  }

  VoidCallback? get previousPageFunction {
    if(currentPage <= 0){
      return null;
    }

    if(currentPage == InstallationStep.gameVersionCheck.index &&
        dllPatcherController.currentDllVersion == null
        || dllPatcherController.currentDllVersion?.isOutdated == true){
      return null;
    }

    if(currentPage == InstallationStep.installing.index){
      return null;
    }

    return previousPage;
  }

  void setCurrentPage(int index){
    currentPage = index;
    update();
  }



  Future<void> setGamePath(String? path) async {
    gamePath = path;
    gamePathController.text = path ?? "";
    if(path != null){
      pathController.setPreyPath(path);
      await dllPatcherController.verifyCurrentDll();
    }
    update();
  }

  Future<void> trySetGamePath(String? exePath) async {
    gamePathOperationInProgress = true;
    update();
    String? error;
    String? newGamePath;
    bool valid = false;

    gameVersion = null;
    gamePathError = null;
    gamePathValid = false;
    gamePath = null;


    (valid, error, newGamePath) = await pathController.validateGamePath(exePath);
    await setGamePath(newGamePath);

    if (valid) {
      gamePathValid = true;
      gamePathError = null;
      gameVersion = await pathController.deduceGameVersion(newGamePath!);
    } else {
      gamePathValid = false;
      gamePathError = error;
    }
    gamePathOperationInProgress = false;
    update();
  }

  Future<void> installChairloader() async {
    try {
      currentProgress = InstallationProgress.patchGame;
      installationInProgress = true;
      update();
      if (dllPatcherController.currentDllVersion?.isSupported != true) {
        await dllPatcherController.patchGame();
        if (!dllPatcherController.patcherSuccess.value) {
          isError = true;
          errorMessage = "Failed to patch game";
          update();
          return;
        }
        await Future.delayed(const Duration(seconds: 1));
      }
      currentProgress = InstallationProgress.extractFiles;
      update();
      if (await extractionController.extractionNeeded()) {
        await extractionController.extractGameFiles();
        if (!extractionController.extractionSuccess) {
          isError = true;
          errorMessage = "Failed to extract game files";
          update();
          return;
        }
      }
      currentProgress = InstallationProgress.installChairloaderFiles;
      update();

      await chairloaderFileInstallController.installChairloaderFiles();
      currentProgress = InstallationProgress.deployChairloaderFiles;
      update();

      await deployController.deploy();
      currentProgress = InstallationProgress.finish;
      update();
    } catch (e) {
      isError = true;
      errorMessage = "An error occurred during installation: $e";
      update();
      return;
    }

  }

}