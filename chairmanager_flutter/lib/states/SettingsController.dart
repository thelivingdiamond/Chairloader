import 'dart:convert';
import 'dart:io';

import 'package:chairmanager_flutter/log/log.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:get/get.dart';
import 'package:get_storage/get_storage.dart';

const settingsFilePath = "ChairManagerConfig.json";

enum PreyVersion {
  Steam,
  GOG,
  Epic,
  MicrosoftStore,
  Unknown,
}

String getPreyVersionName(PreyVersion version) {
  switch (version) {
    case PreyVersion.Steam:
      return "Steam";
    case PreyVersion.GOG:
      return "GOG";
    case PreyVersion.Epic:
      return "Epic";
    case PreyVersion.MicrosoftStore:
      return "MicrosoftStore";
    default:
      return "Unknown";
  }
}

// add a way to convert string to prey version
PreyVersion toPreyVersion(String versionString) {
  switch (versionString) {
    case "Steam":
      return PreyVersion.Steam;
    case "GOG":
      return PreyVersion.GOG;
    case "Epic":
      return PreyVersion.Epic;
    case "MicrosoftStore":
      return PreyVersion.MicrosoftStore;
    default:
      return PreyVersion.Unknown;
  }
}

class SettingsController extends GetxController {
  SettingsController();

  var preyPath = "".obs;
  var preyVersion = PreyVersion.Steam.obs;
  //TODO:

  @override
  void onInit() {
    super.onInit();
    var storage = GetStorage("ChairManagerConfig");
  //   add listener to preyPath
    ever(preyPath, (value) async {
      await storage.write("preyPath", value);
    });
    ever(preyVersion, (value) async {
      await storage.write("preyVersion", getPreyVersionName(value));
    });
    // load the values from storage
    preyPath.value = storage.read("preyPath") ?? "";
    final versionString = storage.read("preyVersion") ?? "Steam";
    print("preyVersion from storage: $versionString");
    preyVersion.value = toPreyVersion(versionString);
  }
}