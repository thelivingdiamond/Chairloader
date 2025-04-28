import 'dart:math';

import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployOptionsDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/launch/LaunchOptionsDialog.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class HomeController extends GetxController {
  Mod? selectedMod;

  void selectMod(Mod? mod) {
    selectedMod = mod;
    update();
  }

  Future<void> openDeployDialog(BuildContext context) async {
    await showDialog(context: context, builder: (context) => const DeployOptionsDialog(), barrierDismissible: false);
    // var result = await Get.dialog(const DeployOptionsDialog());
  }

  Future<void> openLaunchOptionsDialog(BuildContext context) async {
    await showDialog(context: context, builder: (context) => const LaunchOptionsDialog(), barrierDismissible: false);
    // var result = await Get.dialog(const LaunchOptionsDialog());
  }

  Future<void> refreshMods() async{
    ModController controller = Get.find();
    selectedMod = null;
    await controller.detectMods();
    update();
  }

  Future<void> openSelectedModFolder() async {
    if(selectedMod == null) return;
    ModController controller = Get.find();
    await controller.openModFolder(selectedMod!);
  }

  Future<void> openSelectedModConfig() async {
    if(selectedMod == null) return;
    ModController controller = Get.find();
    await controller.openModConfig(selectedMod!);
  }
}