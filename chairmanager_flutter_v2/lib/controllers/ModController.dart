import 'dart:io';
import 'package:get/get.dart';
import 'package:xml/xml.dart' as xml;

import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:chairmanager_flutter_v2/models/ModConfig.dart';

class ModController extends GetxController with TalkerMixin{
  RxList<Mod> mods = <Mod>[].obs;

  void reorderMods(int oldIndex, int newIndex) {
    if (oldIndex < newIndex) {
      newIndex -= 1;
    }
    final Mod item = mods.removeAt(oldIndex);
    mods.insert(newIndex, item);
    _reserializeLoadOrder();
    configDirty = true;
    update();
  }

  void enableMod(Mod mod, bool? enabled) {
    mod.enabled = enabled ?? false;
    configDirty = true;
    update();
  }

  void enableAllMods(bool enabled) {
    for (var mod in mods) {
      mod.enabled = enabled;
    }
    configDirty = true;
    update();
  }

  void _reserializeLoadOrder() {
    for (int i = 0; i < mods.length; i++) {
      mods[i].loadOrder = i + 1;
    }
  }

  bool configDirty = false;

  Future<void> detectMods() async {
    // get the load order and enabled status of each mod from the config file
    // detect mods from the registered mods folder (including ones we don't know about yet)
    // detect mods from the legacy mods folder (including ones we don't know about yet)
    // for each mod, if it is in the list of mods, update the load order and enabled status
    // for each mod, if it is not in the list of mods, add it to the list of mods at the end and disable it
    mods.clear();
    var configModList = await getConfigModList();
    var registeredMods = await detectRegisteredMods(configModList);
    var legacyMods = await detectLegacyMods(configModList);
    mods.addAll(registeredMods);
    mods.addAll(legacyMods);
    sortMods();
    for (var mod in mods) {
      try{
        if(!mod.isLegacy) {
          mod.config = await loadConfig(mod.modName);
        }
      } catch(e) {
        talker.error("Failed to load config for ${mod.modName}", e, StackTrace.current);
      }
    }
    configDirty = false;
    update();
  }

  void sortMods() {
    mods.sort((a, b) => a.loadOrder.compareTo(b.loadOrder));
    _reserializeLoadOrder();
    update();
  }

  List<Mod> get modsWithConfig {
    return mods.where((element) => element.config != null && element.config!.config.isNotEmpty).toList();
  }

  Future<void> saveModListToConfig() async {
    PathController pathController = Get.find();
    var configPath = "${pathController.modConfigPath}\\Chairloader.xml";
    var configFile = File(configPath);
    if(! await configFile.exists()) {
      talker.error("Chairloader.xml does not exist, something is very wrong");
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
      configDirty = false;
      update();
    }
  }

  Future<List<(String, int, bool)>> getConfigModList() async {
    List<(String, int, bool)> loadOrderEnabledList = [];

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
            loadOrderEnabledList.add((modName, int.parse(loadOrder), enabled == "true"));
          }
        }
      }
    }

    return loadOrderEnabledList;
  }

  Future<List<Mod>> detectRegisteredMods(List<(String, int, bool)> priorConfig) async {
    List<Mod> detectedMods = [];
    PathController pathController = Get.find();
    try {
      var directoryList = await Directory(pathController.modDirPath)
          .list()
          .toList();
      // now we go through each directory and check if it has a ModInfo.xml
      for (var fileSystemEntity in directoryList) {
        if (fileSystemEntity is Directory) {
          var mod = await readModInfo(fileSystemEntity.path);
          if (mod == null) {
            talker.verbose("Failed to read mod info for ${fileSystemEntity.path}");
            continue;
          }
          var priorMod = priorConfig.firstWhereOrNull((element) => element.$1 == mod.modName);
          if(priorMod != null) {
            mod.loadOrder = priorMod.$2;
            mod.enabled = priorMod.$3;
          }
          talker.verbose("Loaded mod ${mod.modName}");
          detectedMods.add(mod);
        }
      }
    } catch (e) {
      talker.error("Failed to detect mods", e, StackTrace.current);
      // logger.e(e);
    }
    return detectedMods;
  }

  Future<List<Mod>> detectLegacyMods(List<(String, int, bool)> priorConfig) async {
    List<Mod> detectedMods = [];
    PathController pathController = Get.find();
    try {
      var directoryList = await Directory(pathController.modLegacyDirPath)
          .list()
          .toList();
      // now we go through each directory and since it's legacy, there is no ModInfo.xml
      for (var fileSystemEntity in directoryList) {
        if (fileSystemEntity is Directory) {
          var mod = Mod.legacy(fileSystemEntity.path);
          var priorMod = priorConfig.firstWhereOrNull((element) => element.$1 == mod.modName);
          if(priorMod != null) {
            mod.loadOrder = priorMod.$2;
            mod.enabled = priorMod.$3;
          }
          talker.verbose("Found legacy mod ${fileSystemEntity.path}");
          detectedMods.add(mod);
        }
      }
    } catch (e) {
      talker.error("Failed to detect legacy mods", e, StackTrace.current);
      // logger.e(e);
    }
    return detectedMods;
  }

  Future<Mod?> readModInfo(String path) async {
    var modInfoFile = File("$path\\ModInfo.xml");
    if (await modInfoFile.exists()) {
      // we found a modinfo.xml, so we can add it to the list
      var modInfo = modInfoFile.readAsStringSync();
      var modInfoXml = xml.XmlDocument.parse(modInfo);
      var modName = modInfoXml
          .findAllElements("Mod")
          .firstOrNull
          ?.getAttribute("modName");
      if (modName == null) {
        talker.warning("ModInfo.xml for $path is missing a ModName tag");
        return Mod.empty();
      }
      var mod = Mod.fromModInfo(modInfoXml);
      return mod;
    }
    return null;
  }

  Future<void> saveConfigs() async {
    for (var mod in mods) {
      if(mod.config != null) {
        if(mod.config!.dirty) {
          await saveConfig(mod.config!);
          mod.config!.dirty = false;
        }
      }
    }
  }

  void markConfigAsDirty(Mod mod) {
    if(mod.config != null) {
      mod.config!.dirty = true;
    }
    update();
  }

  Future<ModConfig> loadConfig(String modName) async {
    PathController pathController = Get.find();
    var configFile = File("${pathController.modConfigPath}/$modName.xml");
    var defaultConfigFile = File("${pathController.modDirPath}/$modName/${modName}_default.xml");
    if (!await configFile.exists()) {
      if(!await defaultConfigFile.exists()){
        throw Exception("Default config file for $modName does not exist");
      }
      await defaultConfigFile.copy(configFile.path);
      talker.verbose("Copied default config for $modName");
    }
    // then load the config file
    var configString = await configFile.readAsString();
    var configDocument = xml.XmlDocument.parse(configString);
    var configElement = configDocument.rootElement;
    // then for each child of the root element, create a ConfigEntry from it
    var modConfig = ModConfig.fromXml(configElement, configPath: configFile.path, modDirPath: pathController.modDirPath, modName: modName);
    talker.verbose("Loaded config for $modName");
    return modConfig;
  }

  Future<void> saveConfig(ModConfig config) async {
    PathController pathController = Get.find();
    var configFile = File("${pathController.modConfigPath}/${config.modName}.xml");
    // if the config file doesn't exist, create it from the default config file
    // create a new xml document
    var configDocument = xml.XmlDocument([
      xml.XmlProcessing('xml', 'version="1.0" encoding="utf-8"'),
      config.toXml()
    ]);
    // then save the config file
    await configFile.writeAsString(configDocument.toXmlString(pretty: true, indent: "  "), mode:FileMode.writeOnly);
    talker.verbose("Saved config for ${config.modName}");
  }


}