import 'package:chairmanager_flutter_v2/controllers/DeployController.dart';
import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:get/get.dart';

class DeployDialogController extends GetxController {
  DeployDialogController();

  DeployArguments args = DeployArguments();


  void setForceLevelsRepack(bool value) {
    args.forceLevelsRepack = value;
    update();
  }

  void setForceLocalizationRepack(bool value) {
    args.forceLocalizationRepack = value;
    update();
  }

  void setForceMainPatchRepack(bool value) {
    args.forceMainPatchRepack = value;
    update();
  }

  void setPackOnlyVanillaFiles(bool value) {
    args.packOnlyVanillaFiles = value;
    update();
  }

  void launchDeployDialog() {
    Get.back();
    Get.dialog(const DeployDialog());
  }

  void cancel() {
    Get.back();
  }
}