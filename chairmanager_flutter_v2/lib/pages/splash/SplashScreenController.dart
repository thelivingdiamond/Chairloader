import 'package:get/get.dart';

class SplashScreenController extends GetxController {
  SplashScreenController();

  void goHome() {
    Get.offNamed('/');
  }
}