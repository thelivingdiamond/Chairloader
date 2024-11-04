import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:get/get.dart';
import 'package:shared_preferences/shared_preferences.dart';

class LaunchController extends GetxController with TalkerMixin {
  LaunchArguments args = LaunchArguments();

  late SharedPreferences prefs;
  PathController pathController = Get.find();

  Process? gameProcess;
  RxBool isRunning = false.obs;

  void setLoadChairloader(bool value) {
    args.loadChairloader = value;
    prefs.setBool("loadChairloader", value);
    update();
  }

  void setLoadTrainers(bool value) {
    args.loadTrainers = value;
    prefs.setBool("loadTrainers", value);
    update();
  }

  void setLoadEditor(bool value) {
    args.loadEditor = value;
    prefs.setBool("loadEditor", value);
    update();
  }

  void setDevMode(bool value) {
    args.devMode = value;
    prefs.setBool("devMode", value);
    update();
  }

  void setNoRandom(bool value) {
    args.noRandom = value;
    prefs.setBool("noRandom", value);
    update();
  }

  void setCustomOptions(String value) {
    args.customOptions = value;
    prefs.setString("customOptions", value);
    update();
  }

  Future<void> init() async {
    // load the settings
    prefs = await SharedPreferences.getInstance();
    args.loadChairloader = prefs.getBool("loadChairloader") ?? true;
    args.loadTrainers = prefs.getBool("loadTrainers") ?? false;
    args.loadEditor = prefs.getBool("loadEditor") ?? false;
    args.devMode = prefs.getBool("devMode") ?? false;
    args.noRandom = prefs.getBool("noRandom") ?? false;
    args.customOptions = prefs.getString("customOptions") ?? "";
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

  void cancel() {
    Get.back();
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