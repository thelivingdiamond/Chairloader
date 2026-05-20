import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/modUninstallation/ModUninstallationController.dart';
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:go_router/go_router.dart';

class ModUninstallationDialog extends StatelessWidget {
  const ModUninstallationDialog({super.key, required this.selectedMod});

  final Mod selectedMod;

  @override
  Widget build(BuildContext context) {
    return GetBuilder<ModUninstallationController>(
      init: ModUninstallationController(selectedMod),
      builder: (controller) => Dialog(
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              RichText(
                textAlign: TextAlign.center,
                  text: TextSpan(
                      text: "Are you sure you want to uninstall this mod?\n",
                    style: Theme.of(context).textTheme.bodyLarge,
                    children: [
                      TextSpan(
                          text: '${controller.selectedMod.displayName.isNotEmpty ? controller.selectedMod.displayName : controller.selectedMod.modName}\n',
                        style: const TextStyle(fontWeight: FontWeight.bold),
                      ),
                      if(controller.selectedMod.version != null || controller.selectedMod.author.isNotEmpty)
                      TextSpan(
                          text: '${controller.selectedMod.version != null ? controller.selectedMod.version.toString() : ''} ${controller.selectedMod.author}',
                      ),
                    ]
                  )
              ),
              const SizedBox(height: 8.0,),
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                mainAxisSize: MainAxisSize.min,
                children: [
                  Checkbox(
                    value: controller.deleteConfigFiles,
                    onChanged: (value) => controller.setDeleteConfigFiles(value ?? false),
                  ),
                  const Text("Delete configuration files")
                ],
              ),
              const SizedBox(height: 16.0,),
              Row(
                mainAxisSize: MainAxisSize.min,
                mainAxisAlignment: MainAxisAlignment.center,
                children:[
                  FilledButton.tonal(
                      onPressed: () => context.pop(),
                      child: const Text("Cancel")
                  ),
                  const SizedBox(width: 16.0,),
                  FilledButton(
                      onPressed: () async {
                        await controller.uninstallMod();
                        if(context.mounted){
                          context.pop();
                        }
                      },
                      child: const Text("Confirm")
                  )
                ]
              ),
            ],
          ),
        ),
      ),
    );
  }
}
