import 'dart:math';

import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployOptionsDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/launch/LaunchOptionsDialog.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:flutter/cupertino.dart';
import 'package:get/get.dart';

class HomeController extends GetxController {
  Mod? selectedMod;

  void selectMod(Mod? mod) {
    selectedMod = mod;
    update();
  }

  Future<void> openDeployDialog() async {
    var result = await Get.dialog(const DeployOptionsDialog());
  }

  Future<void> openLaunchOptionsDialog() async {
    var result = await Get.dialog(const LaunchOptionsDialog());
  }

  Future<void> refreshMods() async{
    ModController controller = Get.find();
    selectedMod = null;
    await controller.detectMods();
    update();
  }
}