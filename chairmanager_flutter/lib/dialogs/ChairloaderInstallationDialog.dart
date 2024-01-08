import 'package:chairmanager_flutter/dialogs/DialogController.dart';
import 'package:chairmanager_flutter/dialogs/DialogPageView.dart';
import 'package:fluent_ui/fluent_ui.dart';
import 'package:flutter/material.dart' as material;
import 'package:get/get.dart';
import 'package:window_manager/window_manager.dart';

import '../states/ThemeController.dart';
import '../widgets/WindowsBar.dart';
import 'DialogPage.dart';

class ChairloaderInstallationDialogController extends GetxController{

  var testEnabled = false.obs;

  @override
  void onInit() {
    super.onInit();
  }
}


class ChairloaderInstallationDialog extends StatelessWidget{
  const ChairloaderInstallationDialog({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    final controller = Get.put(ChairloaderInstallationDialogController());
    final titleStyle = FluentTheme.of(context).typography.title!;
    final subtitleStyle = FluentTheme.of(context).typography.subtitle!;
    final bodyStyle = FluentTheme.of(context).typography.body!;
    final bodyLargeStyle = FluentTheme.of(context).typography.bodyLarge!;
    return DialogPageView(title: "Chairloader Installation", pages: [
      DialogPage(
        // welcome page
          child: Expanded(
              child: ListView(
                children: [
                  Text("Welcome to the Chairloader installation wizard.", style: titleStyle, textAlign: TextAlign.center,),
                  Text("This wizard will guide you through the installation of Chairloader.", style: subtitleStyle, textAlign: TextAlign.center),
                  Text("\nBefore using the Mod Manager the game must be modified to add support for advanced modding features. \nIt will be done in the following steps:\n", style: subtitleStyle, textAlign: TextAlign.center,),
                  Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text("1. Check if your version of the game is supported", style:bodyLargeStyle, textAlign: TextAlign.center),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text("2. Patch the game DLL file to a supported version if needed", style:bodyLargeStyle, textAlign: TextAlign.center),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text("3. Install Chairloader files and create Mod directory", style:bodyLargeStyle, textAlign: TextAlign.center),
                  ),
                  Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text("4. Extract files from the game assets", style:bodyLargeStyle, textAlign: TextAlign.center),
                  ),
                ],
              )
          )
      ),
      // version check page
      Obx(() => DialogPage(
          nextEnabled: controller.testEnabled.value,
          cancelEnabled: false,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("Currently Chairloader only works with one specific version of Prey, all other versions must be patched to be the correct version.", style: bodyLargeStyle, textAlign: TextAlign.center,),
                    Text("TODO: add version check", style: bodyLargeStyle, textAlign: TextAlign.center,),
                    Checkbox(checked: controller.testEnabled.value, onChanged: (value) => controller.testEnabled.value = value!,content: Text("AAAAAAA"),),
                  ]
              )
          )
      )),
      Obx(
            ()=> DialogPage(
            cancelEnabled: false,
            nextEnabled: !controller.testEnabled.value,
            child: Expanded(
                child: ListView(
                    children: [
                      Container(
                          color: FluentTheme.of(context).accentColor,
                          child: Text("Important!", style: titleStyle, textAlign: TextAlign.center,)
                      ),
                      Text("If you ever installed any mods or an older version of Chairloader, "
                          "please,", style: bodyLargeStyle, textAlign: TextAlign.center,),
                      Text("verify game files", style: bodyLargeStyle.copyWith(fontWeight: FontWeight.bold), textAlign: TextAlign.center,),
                      Text("in Steam/GOG/EGS. Chairloader requires original game files to install mods correctly. \nTODO: If you are updating Chairloader this message will not appear.", style: bodyLargeStyle, textAlign: TextAlign.center,),
                      Checkbox(checked: controller.testEnabled.value, onChanged: (value) => controller.testEnabled.value = value!,content: Text("AAAAAAA"),),
                    ]
                )
            )
        ),
      ),
      DialogPage(
          cancelEnabled: true,
          // nextEnabled: controller.testEnabled.value,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("Chairloader is ready to be installed.", style: titleStyle, textAlign: TextAlign.center,),

                    if(true)
                      ...[
                        Text("Warning:", style: bodyLargeStyle.copyWith(fontWeight: FontWeight.bold,color: Colors.orange), textAlign: TextAlign.center,),
                        Text("The game will be patched. This will turn your version into the Epic Games Store version. Steam/GOG achievements will continue to work. Xbox Game Pass/MS Store achievements will be disabled.", style: bodyLargeStyle, textAlign: TextAlign.center,),
                      ],

                    Text("\nThis is your last chance to cancel the installation.", style: bodyLargeStyle, textAlign: TextAlign.center,),
                    Text("Do you wish to proceed?", style: bodyLargeStyle, textAlign: TextAlign.center,),
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
                    Text("TODO: Chairloader is installing...", style: titleStyle, textAlign: TextAlign.center,),
                    Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: FutureBuilder(future: Future.delayed(const Duration(seconds: 5), () => Get.find<DialogPageViewController>().nextPage()), builder: (context, snapshot) => snapshot.connectionState == ConnectionState.done ? Text("Done!", style: bodyLargeStyle, textAlign: TextAlign.center,) : const Row(mainAxisAlignment: MainAxisAlignment.center, children: [ProgressRing(),],),),
                    ),
                  ]
              )
          )
      ),
      ),
      Obx(()=> DialogPage(
          showButtons: false,
          nextEnabled: controller.testEnabled.value || true,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("TODO: Extracting game files...", style: titleStyle, textAlign: TextAlign.center,),
                    Text("TODO: Please monitor the Preditor window. ", style: titleStyle, textAlign: TextAlign.center,),
                    Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: FutureBuilder(future: Future.delayed(const Duration(seconds: 5), () => Get.find<DialogPageViewController>().nextPage()), builder: (context, snapshot) => snapshot.connectionState == ConnectionState.done ? Text("Done!", style: bodyLargeStyle, textAlign: TextAlign.center,) : const Row(mainAxisAlignment: MainAxisAlignment.center, children: [ProgressRing(),],),),
                    ),
                  ]
              )
          )
      ),
      ),
      Obx(()=> DialogPage(
          showButtons: false,
          nextEnabled: controller.testEnabled.value || true,
          child: Expanded(
              child: ListView(
                  children: [
                    Text("TODO: Deploying chairloader files...", style: titleStyle, textAlign: TextAlign.center,),
                    Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: FutureBuilder(
                        future: Future.delayed(const Duration(seconds: 5), () => Get.find<DialogPageViewController>().nextPage()),
                        builder: (context, snapshot) => snapshot.connectionState == ConnectionState.done ? Text("Done!", style: bodyLargeStyle, textAlign: TextAlign.center,) :
                        const Row(mainAxisAlignment: MainAxisAlignment.center, children: [ProgressRing(),],),),
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
                    Text("Installation has been completed.", style: titleStyle, textAlign: TextAlign.center,),
                    Padding(
                      padding: const EdgeInsets.all(18.0),
                      child: Center(
                          child: FilledButton(
                            onPressed: () {
                              Get.back();
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