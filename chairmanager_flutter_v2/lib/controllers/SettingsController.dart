import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/storage/StorageMixin.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class SettingsController extends GetxController with TalkerMixin, StorageMixin {
  var darkMode = true.obs;
  Rx<ThemeColor> themeColor = ThemeColor.Indigo.obs;
  Rx<DynamicSchemeVariant> schemeVariant = DynamicSchemeVariant.fidelity.obs;

  Future<void> load() async {
    darkMode.value = await storage.getOrInit<bool>("darkMode", true);

    final themeColorName = await storage.getOrInit<String>("themeColor", "Indigo");
    themeColor.value = ThemeColor.values.firstWhere((color) => color.name == themeColorName);

    final schemeVariantName = await storage.getOrInit<String>("schemeVariant", "fidelity");
    schemeVariant.value = DynamicSchemeVariant.values.firstWhere((variant) => variant.name == schemeVariantName);

    update();
  }

  void toggleDarkMode() {
    darkMode.value = !darkMode.value;
    storage.set("darkMode", darkMode.value);
    update();
  }

  void setThemeColor(ThemeColor color) {
    themeColor.value = color;
    storage.set("themeColor", color.name);
    update();
  }

  void setSchemeVariant(DynamicSchemeVariant variant) {
    schemeVariant.value = variant;
    storage.set("schemeVariant", variant.name);
    update();
  }

  @override
  void onClose() {
    super.onClose();
  }
}

enum ThemeColor {
  Red("Red", Colors.red),
  Pink("Pink", Colors.pink),
  Purple("Purple", Colors.purple),
  DeepPurple("Deep Purple", Colors.deepPurple),
  Indigo("Indigo", Colors.indigo),
  Blue("Blue", Colors.blue),
  LightBlue("Light Blue", Colors.lightBlue),
  Cyan("Cyan", Colors.cyan),
  Teal("Teal", Colors.teal),
  Green("Green", Colors.green),
  LightGreen("Light Green", Colors.lightGreen),
  Lime("Lime", Colors.lime),
  Yellow("Yellow", Colors.yellow),
  Amber("Amber", Colors.amber),
  Orange("Orange", Colors.orange),
  DeepOrange("Deep Orange", Colors.deepOrange),
  Brown("Brown", Colors.brown),
  BlueGrey("Blue Grey", Colors.blueGrey);

  const ThemeColor(this.name, this.color);
  final String name;
  final Color color;
}