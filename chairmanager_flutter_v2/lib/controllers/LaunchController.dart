import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/storage/StorageMixin.dart';
import 'package:get/get.dart';

class LaunchController extends GetxController with TalkerMixin, StorageMixin {
  LaunchArguments args = LaunchArguments();

  PathController pathController = Get.find();

  Process? gameProcess;
  RxBool isRunning = false.obs;

  Future<void> init() async {
    // load the settings
    args.loadChairloader = await storage.getOrInit<bool>("loadChairloader", true);
    args.loadTrainers = await storage.getOrInit<bool>("loadTrainers", false);
    args.loadEditor = await storage.getOrInit<bool>("loadEditor", false);
    args.devMode = await storage.getOrInit<bool>("devMode", false);
    args.noRandom = await storage.getOrInit<bool>("noRandom", false);
    args.customOptions = await storage.getOrInit<String>("customOptions", "");
  }

  void setLoadChairloader(bool value) {
    args.loadChairloader = value;
    storage.set("loadChairloader", value);
    update();
  }

  void setLoadTrainers(bool value) {
    args.loadTrainers = value;
    storage.set("loadTrainers", value);
    update();
  }

  void setLoadEditor(bool value) {
    args.loadEditor = value;
    storage.set("loadEditor", value);
    update();
  }

  void setDevMode(bool value) {
    args.devMode = value;
    storage.set("devMode", value);
    update();
  }

  void setNoRandom(bool value) {
    args.noRandom = value;
    storage.set("noRandom", value);
    update();
  }

  void setCustomOptions(String value) {
    args.customOptions = value;
    storage.set("customOptions", value);
    update();
  }



  Future<void> launchGame() async {
   // get the path to the executable
   final path = pathController.preyExePath;
   final argsArray = args.argsArray;
    // launch the game
    gameProcess = await Process.start(path, argsArray);
    isRunning.value = true;
    update();
    await gameProcess!.exitCode;
    isRunning.value = false;
    update();
  }


  Future<void> stopGame() async {
    if(gameProcess != null){
      gameProcess!.kill();
      isRunning.value = false;
      update();
    }
  }
}


class LaunchArguments {
  bool loadChairloader = true;
  bool loadTrainers = false;
  bool loadEditor = false;
  bool devMode = false;
  bool noRandom = false;
  String customOptions = "";


  List<String> get argsArray {
    List<String> result = [];
    if(!loadChairloader){
      result.add("-nochair");
    }
    if(loadEditor){
      result.add("-editor");
    }
    if(devMode){
      result.add("-devmode");
    }
    if(noRandom){
      result.add("-norandom");
    }
    if(loadTrainers){
      result.add("-trainer");
    }
    // add the custom options split by space
    result.addAll(customOptions.split(" "));
    return result;
  }
}