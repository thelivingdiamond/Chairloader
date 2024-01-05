import 'package:fluent_ui/fluent_ui.dart';
import 'package:get/get.dart';



class ConfigController extends GetxController {
  var tabIndex = 0.obs;
  var tabScrollPosController = ScrollPosController().obs;
  var narrowSpacing = false.obs;
  // create a map btwn index and modName observable
  RxMap<int, String> indexToModName = <int,String>{}.obs;

  String getCurrentModName(){
    return indexToModName[tabIndex.value] ?? "";
  }
}