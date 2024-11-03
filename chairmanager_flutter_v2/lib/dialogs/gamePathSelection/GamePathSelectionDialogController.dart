import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/models/PreyVersion.dart';
import 'package:flutter/cupertino.dart';
import 'package:get/get.dart';

class GamePathSelectionDialogController extends GetxController {
  String? gamePath;
  bool gamePathValid = false;
  String? gamePathError = "";
  PreyVersion? gameVersion;

  TextEditingController gamePathController = TextEditingController();
  final PathController pathController = Get.find();


  void setGamePath(String? path) {
    gamePath = path;
    gamePathController.text = path ?? "";
    update();
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

  Future<void> trySetGamePath(String? exePath) async {
    String? error;
    String? newGamePath;
    bool valid = false;

    gameVersion = null;
    gamePathError = null;
    gamePathValid = false;
    gamePath = null;


    (valid, error, newGamePath) = await validateGamePath(exePath);
    setGamePath(newGamePath);

    if (valid) {
      gamePathValid = true;
      gamePathError = null;
      gameVersion = await pathController.deduceGameVersion(newGamePath!);
    } else {
      gamePathValid = false;
      gamePathError = error;
    }
    update();
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

    var gameVersion = await pathController.deduceGameVersion(path);
    if(gameVersion == PreyVersion.Unknown){
      return (false, "Game Version is unknown");
    }

    //TODO: check vital files exist
    for(var file in pathController.requiredGameFiles){
      if(! await File("$path\\$file").exists()){
        return (false, "Path is missing required file: $file");
      }
    }

    for (var directory in pathController.requiredGameDirectories) {
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

  void finish() {
    pathController.setPreyPath(gamePath!);
    pathController.setPreyVersion(gameVersion!);
    Get.back(result: gamePath);
  }

}