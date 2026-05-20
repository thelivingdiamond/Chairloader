import 'package:chairmanager_flutter_v2/controllers/ModController.dart';
import 'package:chairmanager_flutter_v2/logger/TalkerMixin.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class ConfigController extends GetxController with GetSingleTickerProviderStateMixin, TalkerMixin {
  late TabController tabController;

  bool get anyConfigDirty => Get.find<ModController>().modsWithConfig.any((mod) => mod.config!.dirty);


  @override
  void onInit() {
    super.onInit();



    ModController modController = Get.find();
    tabController = TabController(length: modController.modsWithConfig.length, vsync: this);
    tabController.addListener(() {
      update();
    });
  }

  @override
  void onClose() {
    tabController.dispose();
    super.onClose();
  }

  void markConfigAsDirty(Mod mod) {
    ModController modController = Get.find();
    modController.markConfigAsDirty(mod);
    update();
  }

  Future<void> saveAll() async {
    ModController modController = Get.find();
    await modController.saveConfigs();
    update();
  }

}