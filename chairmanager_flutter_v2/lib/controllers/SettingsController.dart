import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/PreyVersion.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:shared_preferences/shared_preferences.dart';

class SettingsController extends GetxController with TalkerMixin {
  var darkMode = true.obs;
  Rx<ThemeColor> themeColor = ThemeColor.Indigo.obs;
  Rx<DynamicSchemeVariant> schemeVariant = DynamicSchemeVariant.fidelity.obs;

  Future<void> load() async {
    SharedPreferences prefs = await SharedPreferences.getInstance();
    darkMode.value = prefs.getBool("darkMode") ?? false;
    final themeColorName = prefs.getString("themeColor") ?? "Blue";
    themeColor.value = ThemeColor.values.firstWhere((color) => color.name == themeColorName);
    final schemeVariantName = prefs.getString("schemeVariant") ?? "tonalSpot";
    schemeVariant.value = DynamicSchemeVariant.values.firstWhere((variant) => variant.name == schemeVariantName);
    update();
  }

  void toggleDarkMode() {
    darkMode.value = !darkMode.value;
    SharedPreferences.getInstance().then((prefs) {
      prefs.setBool("darkMode", darkMode.value);
    });
    update();
  }

  void setThemeColor(ThemeColor color) {
    themeColor.value = color;
    SharedPreferences.getInstance().then((prefs) {
      prefs.setString("themeColor", color.name);
    });
    update();
  }

  void setSchemeVariant(DynamicSchemeVariant variant) {
    schemeVariant.value = variant;
    SharedPreferences.getInstance().then((prefs) {
      prefs.setString("schemeVariant", variant.name);
    });
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