import 'package:get/get.dart';

class DeployController extends GetxController {
  DeployController();

}

class DeployArguments {
  DeployArguments();

  bool forceLevelsRepack = false;
  bool forceLocalizationRepack = false;
  bool forceMainPatchRepack = false;
  bool packOnlyVanillaFiles = false;
}