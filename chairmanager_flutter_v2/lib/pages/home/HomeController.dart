import 'dart:math';

import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:flutter/cupertino.dart';
import 'package:get/get.dart';

class HomeController extends GetxController {
  Mod? selectedMod;

  void selectMod(Mod? mod) {
    selectedMod = mod;
    update();
  }
}