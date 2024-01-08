import 'dart:io';

import 'package:chairmanager_flutter/dialogs/DialogController.dart';
import 'package:chairmanager_flutter/dialogs/DialogPageView.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:get/get.dart';
import 'package:window_manager/window_manager.dart';

import '../states/ThemeController.dart';
import '../widgets/WindowsBar.dart';
import 'DialogPage.dart';

class ChairloaderUpdateDialogController extends GetxController{

  var testEnabled = false.obs;

  @override
  void onInit() {
    super.onInit();
  }
}


class ChairloaderUpdateDialog extends StatelessWidget{
  const ChairloaderUpdateDialog({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final controller = Get.put(ChairloaderUpdateDialogController());
    final titleStyle = FluentTheme.of(context).typography.title!;
    final subtitleStyle = FluentTheme.of(context).typography.subtitle!;
    final bodyStyle = FluentTheme.of(context).typography.body!;
    final bodyLargeStyle = FluentTheme.of(context).typography.bodyLarge!;
    return DialogPageView(title: "Chairloader Update", pages: [
      DialogPage(
        // welcome page
          child: Expanded(
              child: ListView(
                children: [
                  Text("Welcome to the Chairloader update wizard.", style: titleStyle, textAlign: TextAlign.center,),
                  Text("There is a new version available, and this will download and install the new update.", style: subtitleStyle, textAlign: TextAlign.center),
                ],
              )
          )
      ),
      DialogPage(
          cancelEnabled: true,
          // nextEnabled: controller.testEnabled.value,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("Chairloader is ready to be updated.\n\n", style: titleStyle, textAlign: TextAlign.center,),

                    Text("This will remove the config files, mod files, and any other files stored in the Mods/ folder in the game directory."
                        "\nOnly choose if you are certain you will never use Chairloader again.", style: bodyLargeStyle, textAlign: TextAlign.center,),
                    Center(
                        child: Checkbox(
                          checked: true,
                          onChanged: (value) {},
                          content: Text("Delete the Mods/ folder", style: bodyLargeStyle, textAlign: TextAlign.center,),
                        )
                    ),
                    Text("\n\nDo you wish to proceed?", style: bodyLargeStyle, textAlign: TextAlign.center,),
                  ]
              )
          )
      ),
      Obx(()=> DialogPage(
          showButtons: false,
          nextEnabled: controller.testEnabled.value || true,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("TODO: Chairloader is being updated...", style: titleStyle, textAlign: TextAlign.center,),
                    Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: FutureBuilder(future: Future.delayed(const Duration(seconds: 5), () => Get.find<DialogPageViewController>().nextPage()), builder: (context, snapshot) => snapshot.connectionState == ConnectionState.done ? Text("Done!", style: bodyLargeStyle, textAlign: TextAlign.center,) : const Row(mainAxisAlignment: MainAxisAlignment.center, children: [ProgressRing(),],),),
                    ),
                  ]
              )
          )
      ),
      ),
      DialogPage(
          showButtons: false,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("Chairloader has been updated. ChairManager will now close and reopen.", style: titleStyle, textAlign: TextAlign.center,),
                    Padding(
                      padding: const EdgeInsets.all(18.0),
                      child: Center(
                          child: FilledButton(
                            onPressed: () {
                              exit(0);
                            },
                            child: Text("Finish", style: subtitleStyle),
                          )
                      ),
                    )
                  ]
              )
          )
      ),
    ]);
  }

}