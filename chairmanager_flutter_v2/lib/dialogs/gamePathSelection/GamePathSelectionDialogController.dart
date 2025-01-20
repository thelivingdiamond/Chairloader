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

  Future<void> trySetGamePath(String? exePath) async {
    String? error;
    String? newGamePath;
    bool valid = false;

    gameVersion = null;
    gamePathError = null;
    gamePathValid = false;
    gamePath = null;


    (valid, error, newGamePath) = await pathController.validateGamePath(exePath);
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

  void finish() {
    pathController.setPreyPath(gamePath!);
    pathController.setPreyVersion(gameVersion!);
  }

}
