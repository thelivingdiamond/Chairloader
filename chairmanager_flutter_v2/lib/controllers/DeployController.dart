import 'dart:async';
import 'dart:convert';
import 'dart:io';

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/ChairMerger.dart';
import 'package:chairmanager_flutter_v2/models/GenericLogMessage.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:talker_flutter/talker_flutter.dart';

import 'ModController.dart';

class DeployController extends GetxController with TalkerMixin {
  DeployController();

  ChairMergerSettings chairMergerSettings = ChairMergerSettings();

  List<GenericLogMessage> mergerOutput = [];
  StreamController<GenericLogMessage> mergerOutputController = StreamController<GenericLogMessage>.broadcast();

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

  Future<void> startDeployDialog(BuildContext context) async {
    showDialog(context: context, builder: (context) => const DeployDialog(), barrierDismissible: false);
    await deploy();
  }

  Future<void> deploy() async {
    mergerOutput.clear();
    mergingFinished = false;
    update();

    ModController modController = Get.find();
    PathController pathController = Get.find();
    List<ChairMergerMod> mods = [];
    mods.addAll(modController.mods.where((m) => m.enabled && Directory(pathController.getModDataPath(m.modName, m.isLegacy)).existsSync()).map(
      (mod) => ChairMergerMod(
        type: mod.isLegacy ? ChairMergerModType.legacy.value : ChairMergerModType.native.value,
        modName: mod.modName,
        dataPath: pathController.getModDataPath(mod.modName, mod.isLegacy),
        configPath: mod.config != null ? pathController.getModConfigPath(mod.modName, mod.isLegacy) : null,
      ),
    ));
    mods.add(ChairMergerMod(
        type: ChairMergerModType.folder.value,
        modName: 'Chairloader',
        dataPath: pathController.chairloaderPatchPath,
        configPath: null)
    );

    ChairMergerParams params = ChairMergerParams(
      settings: chairMergerSettings,
      gamePath: pathController.preyPath.value,
      mergerFiles: pathController.dataPath.value,
      outputRoot: pathController.runtimeDataPath,
      preyFiles: pathController.preyFilesPath,
      mods: mods,
    );

    // now we run the chairmerger
    var process = await Process.start(pathController.chairMergerExePath, [], workingDirectory: pathController.dataPath.value);
    process.stdout.transform(utf8.decoder).listen((event) {
      final messages = parseOutput(event);
      for(var message in messages){
        talker.log(message.message, logLevel: message.level);
        mergerOutputController.add(message);
      }
      mergerOutput.addAll(parseOutput(event));
      update();
    });
    process.stderr.transform(utf8.decoder).listen((event) {
      final messages = parseOutput(event);
      for(var message in messages){
        talker.log(message.message, logLevel: message.level);
        mergerOutputController.add(message);
      }
      update();
    });
    final json = jsonEncode(params);
    // we do this to ensure that the merger is ready to receive the json
    var firstMessage = await mergerOutputController.stream.first;
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

  Iterable<GenericLogMessage> parseOutput(String output) {
    return output.split("\n").where((element) => element.isNotEmpty).map((e) {
      if(e.startsWith("[trace] : ")){
        return GenericLogMessage(e.substring("[trace] : ".length), LogLevel.verbose);
      } else if(e.startsWith("[debug] : ")){
        return GenericLogMessage(e.substring("[debug] : ".length), LogLevel.debug);
      } else if(e.startsWith("[info] : ")){
        return GenericLogMessage(e.substring("[info] : ".length), LogLevel.info);
      } else if(e.startsWith("[warning]")){
        return GenericLogMessage(e.substring("[warning] : ".length), LogLevel.warning);
      } else if(e.startsWith("[error]")){
        return GenericLogMessage(e.substring("[error] : ".length), LogLevel.error);
      } else if(e.startsWith("[fatal]")){
        return GenericLogMessage(e.substring("[fatal] : ".length), LogLevel.critical);
      } else {
        return GenericLogMessage(e, LogLevel.info);
      }
    });
  }
}

