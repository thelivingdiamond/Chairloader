import 'package:chairmanager_flutter_v2/dialogs/deploy/DeployDialog.dart';
import 'package:chairmanager_flutter_v2/dialogs/uninstallation/UninstallationDialogController.dart';
import 'package:get/get.dart';
import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';

class UninstallationDialog extends StatelessWidget {
  const UninstallationDialog({super.key});

  @override
  Widget build(BuildContext context) {
    return Dialog.fullscreen(
      child: Container(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          children: [
            Center(
              child: Text(
                "Uninstallation",
                style: Theme.of(context).textTheme.titleLarge,
              ),
            ),
            const SizedBox(height: 16.0),
            Center(
              child: Text(
                "Are you sure you want to uninstall Chairloader?",
                style: Theme.of(context).textTheme.bodyLarge,
              ),
            ),
            const SizedBox(height: 16.0),
            GetBuilder<UninstallationDialogController>(
              init: UninstallationDialogController(),
              builder: (controller) => Column(
                children: [
                  CheckboxListTile(
                    title: const Text("Remove mod folder"),
                    value: controller.removeModFolder,
                    onChanged: (v) => controller.setRemoveModFolder(v ?? false),
                  ),
                  const SizedBox(height: 16.0),
                  if(controller.success != null)
                    ...[
                      if (controller.success == true)
                        ...[
                          Center(
                            child: Text(
                              "Uninstallation successful",
                              style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.green,
                              ),
                            ),
                          ),
                        ]
                      else if (controller.success == false)
                        ...[
                          Center(
                            child: Text(
                              "Uninstallation failed",
                              style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.red,
                              ),
                            ),
                          ),
                          if (controller.errorMessage != null)
                            Center(
                              child: Text(
                                controller.errorMessage!,
                                style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.red,
                                ),
                              ),
                            ),
                        ],
                      if(controller.dllPatchRestored == true)
                        ...[
                          const SizedBox(height: 16.0),
                          Center(
                            child: Text(
                              "Prey DLL restored Successfull",
                              style: Theme.of(context).textTheme.bodyLarge?.copyWith(color: Colors.green,
                              ),
                            ),
                          ),
                        ]
                      else if(controller.dllPatchRestored == false)
                        ...[
                          const SizedBox(height: 16.0),
                          Center(
                            child: Text(
                              "Prey DLL restore failed, if you are using the Epic Games launcher this is normal. Otherwise please verify game files in your game launcher to complete the uninstallation.",
                              style: Theme.of(context).textTheme.bodyLarge,
                            ),
                          ),
                        ],
                      const SizedBox(height: 16.0),
                      Center(
                        child: ElevatedButton(
                          onPressed: () {
                            context.pop();
                          },
                          child: const Text("Close"),
                        ),
                      ),
                    ],
                  const SizedBox(height: 16.0),
                  if (controller.busy)
                    const Center(child: CircularProgressIndicator())
                  else if (controller.success == null)
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                      children: [
                        ElevatedButton(
                          onPressed: () {
                            context.pop();
                          },
                          child: const Text("Cancel"),
                        ),
                        ElevatedButton(
                          onPressed: controller.uninstallChairloader,
                          child: const Text("Uninstall"),
                        ),
                      ],
                    ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
