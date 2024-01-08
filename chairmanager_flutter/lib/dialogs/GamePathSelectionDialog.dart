import 'dart:io';

import 'package:bitsdojo_window/bitsdojo_window.dart';
import 'package:chairmanager_flutter/dialogs/DialogPageView.dart';
import 'package:chairmanager_flutter/log/log.dart';
import 'package:chairmanager_flutter/states/PathController.dart';
import 'package:chairmanager_flutter/states/SettingsController.dart';
import 'package:chairmanager_flutter/widgets/WindowsBar.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:get/get.dart';
import 'package:file_picker/file_picker.dart';
import 'package:window_manager/window_manager.dart';

import '../states/ThemeController.dart';
import 'DialogPage.dart';


class GamePathSelectionDialogController extends GetxController{
  var pageController = PageController(initialPage: 0).obs;

  var gamePath = "".obs;
  var gameVersion = PreyVersion.Unknown.obs;
  var errorReason = "".obs;
  var isGamePathValid = false.obs;

  var selectedExePath = "".obs;


  bool validateExePath(){
    errorReason.value = "";
    //"C:\Program Files (x86)\Steam\steamapps\common\Prey\Binaries\Danielle\x64\Release\Prey.exe"
    // check if it's empty
    if(selectedExePath.value.isEmpty){
      errorReason.value = "Executable File Path is empty";
      return false;
    }
    if(!File(selectedExePath.value).existsSync()){
      errorReason.value = "Executable File does not exist";
      return false;
    }
    // check if it ends with prey.exe
    if(!selectedExePath.value.endsWith("Prey.exe")){
      errorReason.value = "Executable File is not Prey.exe";
      return false;
    }

    gamePath.value = exePathToGamePath(selectedExePath.value);

    return validateGamePath();
  }

  bool validateGamePath() {
    PathController pathController = Get.find();
    // check if it's empty
    if(selectedExePath.value.isEmpty){
      errorReason.value = "Game Path is empty";
      return false;
    }
    if(!Directory(gamePath.value).existsSync()){
      errorReason.value = "Game Path does not exist";
      return false;
    }

    gameVersion.value = pathController.deduceGameVersionSync(gamePath.value);
    if(gameVersion.value == PreyVersion.Unknown){
      errorReason.value = "Game Version is unknown";
      return false;
    }

    //TODO: check vital files exist
    for(var file in pathController.requiredGameFiles){
      if(!File("$gamePath\\$file").existsSync()){
        errorReason.value = "Game is missing required file: $file";
        return false;
      }
    }

    for (var directory in pathController.requiredGameDirectories) {
      if (!Directory("$gamePath\\$directory").existsSync()) {
        errorReason.value = "Game is missing required directory: $directory";
        return false;
      }
    }

    return true;
  }

  String exePathToGamePath(String exePath){
    File exeFile = File(exePath);
    //Binaries\Danielle\x64\Release\Prey.exe
    var parentDir = exeFile.parent.parent.parent.parent.parent;
    return parentDir.path;
  }
}



class GamePathSelectionDialog extends StatelessWidget {
  GamePathSelectionDialog({super.key}){
    final args = Get.arguments;
    if(args != null){
      if(args["hasCancelButton"] != null){
        cancelEnabled = args["hasCancelButton"] ?? true;
      }
    }
  }

  late final bool cancelEnabled;

  @override
  Widget build(BuildContext context) {
    final controller = Get.put(GamePathSelectionDialogController());
    final titleStyle = FluentTheme.of(context).typography.title!;
    final subtitleStyle = FluentTheme.of(context).typography.subtitle!;
    final bodyStyle = FluentTheme.of(context).typography.body!;
    final bodyLargeStyle = FluentTheme.of(context).typography.bodyLarge!;
    final settingsController = Get.find<SettingsController>();
    return DialogPageView(pages: [
      DialogPage(
        showButtons: cancelEnabled,
        cancelEnabled: true,
        backEnabled: false,
        nextEnabled: false,
        child: Expanded(
          child: ListView(
            children: [
              const SizedBox(height: 16.0,),
              Center(
                child: Obx((){
                  if(!controller.isGamePathValid.value){
                    return Text("Please select the game executable for prey", style: titleStyle, textAlign: TextAlign.center,);
                  } else {
                    return Container(
                      padding: const EdgeInsets.all(8.0),
                      decoration: BoxDecoration(
                        borderRadius: BorderRadius.circular(4.0),
                        color: material.Colors.green,
                      ),
                      // color: material.Colors.green,
                      child: Text("Valid Prey Path Found", style: titleStyle, textAlign: TextAlign.center,),
                    );
                  }
                }),
              ),
              Center(
                child: Obx( () => controller.isGamePathValid.value ? const SizedBox():
                Text("It's located in Binaries\\Danielle\\...\\Release\\Prey.exe in your game folder.", style: subtitleStyle, textAlign: TextAlign.center,)),
              ),
              const SizedBox(height: 16.0,),
              // Obx( () => Text("Selected Value: ${controller.selectedExePath.value}")),
              Center(child: Obx( () => Text("Game Path: ${controller.gamePath.value}", style:bodyLargeStyle))),
              Center(child: Obx( () => Text("Game Version: ${getPreyVersionName(controller.gameVersion.value)}", style:bodyLargeStyle))),
              Center(child: Obx( () => controller.errorReason.value.isEmpty ? const SizedBox() : Text("Error: ${controller.errorReason.value}", style: TextStyle(color: Colors.red, fontSize: 20),))),
              const SizedBox(height: 16.0,),
              Center(
                child: Obx( () => controller.isGamePathValid.value ?
                FilledButton(child:  Text("Close", style:FluentTheme.of(context).typography.bodyLarge), onPressed: () {Get.back();}) :
                FilledButton(child:  Text("Select Game Executable", style:FluentTheme.of(context).typography.bodyLarge), onPressed: () async {
                  final result = await FilePicker.platform.pickFiles(type: FileType.custom, allowedExtensions: ['exe'], allowMultiple: false, dialogTitle: "Select Prey Executable", lockParentWindow: true);
                  if(result != null){
                    controller.selectedExePath.value = result.files.single.path ?? "";
                    controller.isGamePathValid.value = controller.validateExePath();
                    if(controller.isGamePathValid.value){
                      settingsController.preyPath.value = controller.gamePath.value;
                      settingsController.preyVersion.value = controller.gameVersion.value;
                    }
                  }
                },)),
              ),
            ],
          ),
        ),
      )
    ],
    );
  }

}