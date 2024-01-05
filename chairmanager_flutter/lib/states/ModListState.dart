import 'dart:async';
import 'dart:io';

import 'package:fluent_ui/fluent_ui.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:get/get.dart';
import 'package:xml/xml.dart' as xml;


import '../data/Mod.dart';
import './PathController.dart';

class ModListController extends GetxController {
  RxList<Mod> mods = <Mod>[].obs;
  var selectedMod = Mod.empty().obs;

  ModListController();
  var dirty = false.obs;
  var timerStart = false.obs;
  bool ignoreDirty = false;

  Timer _saveTimer = Timer(Duration(seconds: 5), () {});

  @override
  void onInit() {
    super.onInit();
    detectMods();
    ever(mods, (_) {
      if(ignoreDirty) return;
      dirty.value = true;
      timerStart.value = true;
    });
    // create a timer such that 5 seconds after the last change to dirty, we save the mod list, but if a change happens before then, we reset the timer
    ever(timerStart, (_) {
      if(!timerStart.value) return;
      timerStart.value = false;
      _saveTimer.cancel();
      _saveTimer = Timer(Duration(seconds: 5), () {
        saveModListToConfig();
      });
    });
  }

  void selectMod(Mod mod) {
    selectedMod.value = mod;
  }

  bool isModSelected(Mod mod) {
    return selectedMod.value == mod;
  }

  void addMod(Mod mod) {
    mods.add(mod);
  }

  void removeMod(Mod mod) {
    mods.remove(mod);
  }

  void clear() {
    mods.clear();
  }

  void sort() {
    // sort by load order
    var tempList = mods.toList();
    tempList.sort((a, b) => a.loadOrder.compareTo(b.loadOrder));
    mods.clear();
    mods.addAll(tempList);
  }

  void serializeLoadOrder() {
    for (var element in mods) {
      element.loadOrder = mods.indexOf(element);
    }
  }

  void setModLoadOrderAbove(Mod mod, Mod above) {
    if (mod == above) return;
    mods.remove(mod);
    mods.insert(mods.indexOf(above), mod);
    serializeLoadOrder();
  }

  void setModLoadOrderBelow(Mod mod, Mod below) {
    if (mod == below) return;
    mods.remove(mod);
    mods.insert(mods.indexOf(below) + 1, mod);
    serializeLoadOrder();
  }

  void setModLoadOrder(Mod mod, int index) {
    if (mods.indexOf(mod) == index) return;
    mods.remove(mod);
    mods.insert(index, mod);
    serializeLoadOrder();
  }

  Mod getMod(String modName) {
    for (var element in mods) {
      if (element.modName == modName) {
        return element;
      }
    }
    return Mod.empty();
  }

  Mod getModByIndex(int index) {
    return mods[index];
  }

  void moveModUp(Mod mod) {
    if (mod.loadOrder == 0) return;
    setModLoadOrderAbove(mod, getModByIndex(mod.loadOrder - 1));
  }

  void moveModDown(Mod mod) {
    if (mod.loadOrder == mods.length - 1) return;
    setModLoadOrderBelow(mod, getModByIndex(mod.loadOrder + 1));
  }

  void enableMod(Mod mod, bool enabled) {
    mod.enabled.value = enabled;
    if (ignoreDirty) return;
    dirty.value = true;
    timerStart.value = true;
  }

  void enableAllMods(bool enabled) {
    for (var mod in mods) {
      mod.enabled.value = enabled;
    }
    if (ignoreDirty) return;
    dirty.value = true;
    timerStart.value = true;
  }

  void toggleAllMods() {
    // if any mod is enabled, disable all mods
    // if all mods are disabled, enable all mods
    var anyEnabled = false;
    for (var mod in mods) {
      if(mod.enabled.value) {
        anyEnabled = true;
        break;
      }
    }
    if(anyEnabled) {
      enableAllMods(false);
    } else {
      enableAllMods(true);
    }
  }

  Future<void> loadModListFromConfig() async {
    PathController pathController = Get.find();
    var configPath = "${pathController.modConfigPath}\\Chairloader.xml";
    var configFile = File(configPath);
    if(await configFile.exists()) {
      var config = await configFile.readAsString();
      var configXml = xml.XmlDocument.parse(config);
      var modList = configXml.findAllElements("ModList").firstOrNull;
      if(modList != null) {
        for (var mod in modList.childElements) {
          var modName = mod.findAllElements("modName").firstOrNull?.innerText;
          var enabled = mod.findAllElements("enabled").firstOrNull?.innerText;
          var loadOrder = mod.findAllElements("loadOrder").firstOrNull?.innerText;
          if(modName != null && enabled != null && loadOrder != null) {
            var mod = getMod(modName);
            if(!mod.isEmpty()) {
              mod.enabled.value = enabled == "true";
              mod.loadOrder = int.parse(loadOrder);
            }
          }
        }
      }
    }
  }

  Future<void> saveModListToConfig() async {
    PathController pathController = Get.find();
    var configPath = "${pathController.modConfigPath}\\Chairloader.xml";
    var configFile = File(configPath);
    if(! await configFile.exists()) {
      logger.e("Chairloader.xml does not exist, something is very wrong");
      return;
    }
    // read the file into an xml document
    var config = await configFile.readAsString();
    var configXml = xml.XmlDocument.parse(config);
    // find the modlist element
    var modList = configXml.findAllElements("ModList").firstOrNull;
    if(modList != null) {
      // clear the modlist element
      modList.children.clear();
      // add each mod to the modlist element
      for (var mod in mods) {
        modList.children.add(mod.toXml());
      }
      // write the xml document back to the file
      await configFile.writeAsString(configXml.toXmlString(pretty: true));
    }
    dirty.value = false;
  }

  void detectMods() async {
    _saveTimer.cancel();
    ignoreDirty = true;
    mods.clear();
    await detectRegisteredMods();
    await detectLegacyMods();
    await loadModListFromConfig();
    sort();
    serializeLoadOrder();
    dirty.value = false;
    ignoreDirty = false;
  }

  Future<void> detectRegisteredMods() async {
    PathController pathController = Get.find();
    var directoryList = await Directory(pathController.modDirPath)
        .list()
        .toList();
    // now we go through each directory and check if it has a ModInfo.xml
    for (var fileSystemEntity in directoryList) {
      if (fileSystemEntity is Directory) {
        var mod = ReadModInfo(fileSystemEntity.path);
        if(mod == null) {
          // logger.w("Failed to read mod info for ${fileSystemEntity.path}");
          continue;
        }
        logger.v("Found mod ${mod.modName}");
        mods.add(mod);
      }
    }
  }


  Mod? ReadModInfo(String path) {
    var modInfoFile = File("${path}\\ModInfo.xml");
    if (modInfoFile.existsSync()) {
      // we found a modinfo.xml, so we can add it to the list
      var modInfo = modInfoFile.readAsStringSync();
      var modInfoXml = xml.XmlDocument.parse(modInfo);
      var modName = modInfoXml
          .findAllElements("Mod")
          .firstOrNull
          ?.getAttribute("modName");
      var modVersion = modInfoXml
          .findAllElements("Mod")
          .firstOrNull
          ?.getAttribute("version");
      var modAuthor = modInfoXml
          .findAllElements("Mod")
          .firstOrNull
          ?.getAttribute("author");
      var displayName = modInfoXml
          .findAllElements("Mod")
          .firstOrNull
          ?.getAttribute("displayName");
      var dllName = modInfoXml
          .findAllElements("Mod")
          .firstOrNull
          ?.getAttribute("dllName");
      if (modName == null) {
        logger.w("ModInfo.xml for ${path} is missing a ModName tag");
        return Mod.empty();
      }
      var mod = Mod(
        modName: modName,
        version: modVersion ?? "",
        author: modAuthor ?? "",
        displayName: displayName ?? "",
        dllName: dllName ?? "",
        // TODO: read the enabled state from Chairloader.xml when that's implemented
        enabled: true.obs,
        // TODO: read the load order from Chairloader.xml when that's implemented
        loadOrder: -1,
        isLegacy: false,
      );
      return mod;
    }
    return null;
  }


  Future<void> detectLegacyMods() async {
    PathController pathController = Get.find();
    var directoryList = await Directory(pathController.modLegacyDirPath).list().toList();
    // now we go through each directory and since it's legacy, there is no ModInfo.xml
    for (var fileSystemEntity in directoryList) {
      if (fileSystemEntity is Directory) {
        var mod = Mod(
          modName: fileSystemEntity.path.split("\\").last,
          version: "",
          author: "",
          displayName: "",
          dllName: "",
          loadOrder: -1,
          // TODO: read the enabled state from Chairloader.xml when that's implemented
          enabled: true.obs,
          // TODO: read the load order for legacy mods from somewhere when we do that eventually
          isLegacy: true,
        );
        logger.v("Found legacy mod ${fileSystemEntity.path}");
        mods.add(mod);
      }
    }
  }
}