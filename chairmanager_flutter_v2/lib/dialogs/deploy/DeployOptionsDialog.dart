import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialogController.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';

class DeployOptionsDialog extends StatelessWidget {
  const DeployOptionsDialog({super.key});

  @override
  Widget build(BuildContext context) {
    return GetBuilder<DeployDialogController>(
      init: DeployDialogController(),
      builder: (controller) {
        return Dialog(
          child: Container(
            padding: const EdgeInsets.all(16.0),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                Text("Deploy Options", style: Theme.of(context).textTheme.titleLarge,),
                const SizedBox(height: 16.0,),
                Column(
                  mainAxisSize: MainAxisSize.min,
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Checkbox(value: controller.args.forceLevelsRepack, onChanged: (value) {
                          controller.setForceLevelsRepack(value ?? false);
                        }),
                        Text("Force Levels Repack", style: Theme.of(context).textTheme.bodyLarge,),
                      ],
                    ),
                    Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Checkbox(value: controller.args.forceLocalizationRepack, onChanged: (value) {
                          controller.setForceLocalizationRepack(value ?? false);
                        }),
                        Text("Force Localization Repack", style: Theme.of(context).textTheme.bodyLarge,),
                      ],
                    ),
                    Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Checkbox(value: controller.args.forceMainPatchRepack, onChanged: (value) {
                          controller.setForceMainPatchRepack(value ?? false);
                        }),
                        Text("Force Main Patch Repack", style: Theme.of(context).textTheme.bodyLarge,),
                      ],
                    ),
                    Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Checkbox(value: controller.args.packOnlyVanillaFiles, onChanged: (value) {
                          controller.setPackOnlyVanillaFiles(value ?? false);
                        }),
                        Text("Pack only vanilla files (no mods)", style: Theme.of(context).textTheme.bodyLarge,),
                      ],
                    ),
                  ],
                ),
                const SizedBox(height: 16.0,),
                Row(
                  mainAxisSize: MainAxisSize.min,
                  children: [
                    FilledButton.tonal(
                      onPressed: () => controller.cancel(),
                      child: const Text("Cancel"),
                    ),
                    const SizedBox(width: 8.0,),
                    FilledButton(
                      onPressed: () => controller.launchDeployDialog(),
                      child: const Text("Deploy"),
                    ),
                  ],
                )
              ],
            )
          )
        );
      }
    );
  }
}
