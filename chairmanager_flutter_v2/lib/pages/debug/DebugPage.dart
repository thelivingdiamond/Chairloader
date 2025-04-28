import 'package:chairmanager_flutter_v2/controllers/PathController.dart';
import 'package:chairmanager_flutter_v2/dialogs/GamePathSelection/gamePathSelectionDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/installation/InstallationDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/uninstallation/UninstallationDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/modInstallation/ModInstallationDialog.dart';
import 'package:file_picker/file_picker.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';

class DebugPage extends StatelessWidget {
  const DebugPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Card(
      child: ListView(
        padding: const EdgeInsets.all(16.0),
        children: [
          Center(child: Text("Debug Page", style: Theme.of(context).textTheme.titleLarge,)),
          const SizedBox(height: 16.0,),
          Center(
            child: FilledButton(
                onPressed: () async {
                  await showDialog(context: context, builder: (context) => const GamePathSelectionDialog(), useSafeArea: false, barrierDismissible: false);
                  // Get.dialog(const GamePathSelectionDialog(), barrierDismissible: false);
                },
                child: const Text("Open Game Path Selection Dialog")
            ),
          ),
          const SizedBox(height: 16.0,),
          Center(
            child: FilledButton(
                onPressed: () async {
                  await showDialog(context: context, builder: (context) => const InstallationDialog(), useSafeArea: false, barrierDismissible: false);
                },
                child: const Text("Open Installation Dialog")
            ),
          ),
          const SizedBox(height: 16.0,),
          Center(
            child: FilledButton(
                onPressed: () async {
                  await showDialog(context: context, builder: (context) => const UninstallationDialog(), useSafeArea: false, barrierDismissible: false);
                },
                child: const Text("Open Uninstallation Dialog")
            ),
          ),
          const SizedBox(height: 16.0,),
          Center(
            child: FilledButton(
                onPressed: () async {
                  await showDialog(context: context, builder: (context) => const ModInstallationDialog(), useSafeArea: false, barrierDismissible: false);
                  // Get.dialog(const ModInstallationDialog(), barrierDismissible: false);
                },
                child: const Text("Open Mod Installation Dialog")
            ),
          ),
          Center(
            child: FilledButton(
                onPressed: () {
                  context.go("/SplashScreen", extra: true);
                },
                child: const Text("Go to Splash Screen")
            ),
          ),
          GetBuilder<PathController>(builder: (controller) =>
              Column(
                children: [
                  TextFormField(
                              controller: TextEditingController(text: controller.dataPath.value),
                              onChanged: (value) {
                  controller.setDataPath(value);
                              },
                            ),
                  ElevatedButton(
                      onPressed: () async {
                        var result = await FilePicker.platform.getDirectoryPath();
                        if(result != null){
                          controller.setDataPath(result);
                        }
                      },
                      child: const Text("Pick Data Path")
                  ),
                ],
              )),

        ],
      ),
    );
  }
}
