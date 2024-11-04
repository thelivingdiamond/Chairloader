import 'dart:async';
import 'dart:convert';
import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/ChairMerger.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

import 'ModController.dart';

class DeployController extends GetxController with TalkerMixin {
  DeployController();

  ChairMergerSettings chairMergerSettings = ChairMergerSettings();

  List<String> mergerOutput = [];

  bool mergingFinished = false;

  void setForceLevelsRepack(bool value) {
    chairMergerSettings.forceLevelPack = value;
    update();
  }

  void setForceLocalizationRepack(bool value) {
    chairMergerSettings.forceLocalizationPack = value;
    update();
  }

  void setForceMainPatchRepack(bool value) {
    chairMergerSettings.forceMainPatchPack = value;
    update();
  }

  void setForceVanillaPack(bool value) {
    chairMergerSettings.forceVanillaPack = value;
    update();
  }

  Future<void> startDeployDialog() async {
    Get.dialog(
      const DeployDialog(),
      barrierDismissible: false,
      barrierColor: Colors.black.withOpacity(0.1),
    );
    await deploy();
  }

  Future<void> deploy() async {
    mergerOutput.clear();
    mergingFinished = false;
    update();

    ModController modController = Get.find();
    PathController pathController = Get.find();
    List<ChairMergerMod> mods = modController.mods.where((m) => m.enabled).map(
      (mod) => ChairMergerMod(
        type: mod.isLegacy ? ChairMergerModType.legacy.value : ChairMergerModType.native.value,
        modName: mod.modName,
        //TODO: don't pass mods in where the mod data path doesn't exist
        dataPath: pathController.getModDataPath(mod.modName, mod.isLegacy),
        configPath: mod.config != null ? pathController.getModConfigPath(mod.modName, mod.isLegacy) : null,
      ),
    ).toList();

    ChairMergerParams params = ChairMergerParams(
      settings: chairMergerSettings,
      gamePath: pathController.preyPath.value,
      mergerFiles: pathController.dataPath.value,
      outputRoot: pathController.runtimeDataPath,
      preyFiles: pathController.preyFilesPath,
      mods: mods,
    );

    // now we run the chairmerger
    var process = await Process.start(pathController.chairMergerExePath, []);
    process.stdout.transform(utf8.decoder).listen((event) {
      mergerOutput.addAll(event.split("\n"));
      update();
    });
    process.stderr.transform(utf8.decoder).listen((event) {
      mergerOutput.addAll(event.split("\n"));
      update();
    });

    final json = jsonEncode(params);
    talker.verbose(json);
    process.stdin.writeln(json);
    var exitCode = await process.exitCode;
    if(exitCode == 0){
      talker.info("ChairMerger completed successfully");
    } else {
      talker.error("ChairMerger failed with exit code $exitCode");
    }
    mergingFinished = true;
    update();
  }
}