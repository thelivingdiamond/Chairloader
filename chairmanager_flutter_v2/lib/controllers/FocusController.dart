import 'package:chairmanager_flutter_v2/logger/LogMixin.dart';
import 'package:get/get.dart';
import 'package:window_manager/window_manager.dart';

class FocusController extends GetxController with WindowListener, LogMixin {
  var hasFocus = true.obs;

  @override
  void onInit() {
    super.onInit();
    windowManager.addListener(this);
  }

  @override
  void onClose() {
    windowManager.removeListener(this);
    super.onClose();
  }

  @override
  void onWindowFocus() {
    hasFocus.value = true;
    update();
  }


  @override
  void onWindowBlur() {
    hasFocus.value = false;
    update();
  }
}